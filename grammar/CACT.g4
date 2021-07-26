/*****
    locals & return for rules
*****/
grammar CACT;

// The language generated
options {
    language = Cpp;
}

@header {
    #include <vector>
    #include <string>
}

/********** Parser **********/

compUnit
    : transUnit? EOF
    ;

transUnit
    : ( decl | funcDef )+
    ;

decl
    : constDecl
    | varDecl
    ;

constDecl
    : 'const' bType constDef (',' constDef)* ';'
    ;

bType
    : 'int'
    | 'bool'
    | 'float'
    | 'double'
    ;
arraySymbol
    : '[' (IntConst)? ']'
    ;
constDef
    : Ident (arraySymbol)? '=' constInitVal
    ;

constInitVal
    locals[
        int basic_or_array_and_type
    ]
    : constExp
    | '{' constInitArray
    ;
constInitArray
    : (constExp (',' constExp)*)? '}'
    ;
varDecl
    : bType varDef (',' varDef)* ';'
    ;

varDef
    : Ident (arraySymbol)?
    | Ident (arraySymbol)? '=' constInitVal
    ;

funcDef
    : funcType Ident '(' funcFParams? ')' block
    ;

funcType
    : 'void' | 'int' | 'float' | 'double' | 'bool'
    ;

funcFParams
    : funcFParam (',' funcFParam)*
    ;

funcFParam
    : bType Ident (arraySymbol)?
    ;

block
    : '{' blockItem* '}'
    ;

blockItem
    : decl | stmt
    ;

stmt
    : lVal '=' exp ';'                              # assignStmt
    | exp? ';'                                      # exprStmt
    | block                                         # blockStmt
    | 'if' '(' ifCond ')' stmt elseStmt                  # ifElseStmt
    | 'if' '(' ifCond ')' stmt                      # ifStmt
    | 'while' '(' whileCond ')' stmt                     # whileStmt
    | 'return' exp? ';'                             # returnStmt
    ;
elseStmt: 'else' stmt ;
exp locals[
    std::string tmp,
    int cls,
    int type,
    bool elementwise
    ]
    : addExp | BoolConst
    ;

cond locals[
    std::string tmp
    ]
    : lOrExp
    ;
ifCond locals[
    std::string tmp
    ]
    : cond
    ;
whileCond locals[
    std::string tmp
    ]
    : cond
    ;
lVal locals[
    std::string tmp,
    int cls,
    int type,
    bool elementwise
    ]
    : Ident ('[' exp ']')? //used to be exp, changed to constExp
    ;

primaryExp locals[
    std::string tmp,
    int cls,
    int type,
    bool elementwise
    ]
    : '(' exp ')'
    | lVal
    | number
    ;

number
    locals[
        int basic_or_array_and_type,
        std::string tmp,
        int cls
    ]
    : IntConst
    | DoubleConst
    | FloatConst
    ;

unaryExp locals[
    std::string tmp,
    int cls,
    int type,
    bool elementwise
    ]
    : primaryExp
    | Ident '(' funcRParams? ')'
    | unaryOp unaryExp
    ;

unaryOp
    : '+'|'-'|'!'
    ;

funcRParams
    : exp (',' exp)*
    ;

mulExp locals[
    std::string tmp,
    int cls,
    int type,
    bool elementwise
    ]
    : unaryExp 
    | mulExp op=(MUL | DIV | MOD) unaryExp
    ;

addExp locals[
    std::string tmp,
    int cls,
    int type,
    bool elementwise
    ]
    : mulExp
    | addExp op=(ADD | SUB) mulExp
    ;

relExp locals[
    std::string tmp,
	int cls
	]
    : addExp
    | relExp op=(GT | LT | LE | GE) addExp
    | BoolConst
    ;

eqExp locals[
    std::string tmp,
	int cls
	]
    : relExp
    | eqExp op=(EQ | NE) relExp
    ;

lAndExp locals[
    std::string tmp,
	int cls
	]
    : eqExp
    | lAndExp op=AND eqExp
    ;

lOrExp locals[
    std::string tmp,
	int cls
	]
    : lAndExp
    | lOrExp op=OR lAndExp
    ;

constExp
    locals[
        int basic_or_array_and_type,
    ]
    : number            //#constExpNumber
    | BoolConst         //#constExpBoolConst
    ;

/********** Lexer **********/
BoolConst : 'true' | 'false';

Ident
    : IdentNondigit [a-zA-Z_0-9]*
    ;
ADD: '+';
SUB: '-';
MUL: '*';
DIV: '/';
MOD: '%';   

NOT: '!';

NE: '!=';
EQ:'==';
GT:'>';
LT:'<';
GE:'>=';
LE:'<=';

AND: '&&';
OR: '||';
fragment
IdentNondigit
    : [a-zA-Z_]
    ;

fragment
Digit
    : [0-9]
    ;

IntConst
    : DecimalConst 
    | OctalConst
    | HexadecimalConst
    ;

fragment
DecimalConst
    : '0'
    | NonzeroDigit Digit*
    ;

fragment
OctalConst
    : '0' OctalDigit+
    ;

fragment
HexadecimalConst
    : HexadecimalPrefix HexadecimalDigit+
    ;

fragment
NonzeroDigit
    : [1-9]
    ;

fragment
OctalDigit
    : [0-7]
    ;

fragment
HexadecimalPrefix
    : '0x'
    | '0X'
    ;

fragment
HexadecimalDigit
    : [0-9a-fA-F]
    ;

NewLine
    : ('\r' '\n'? | '\n') 
      -> skip
    ;

WhiteSpace
    : [ \t]+ 
      -> skip
    ;

BlockComment
    : '/*' .*? '*/'
      -> skip
    ;

LineComment
    : '//' ~[\r\n]*
      -> skip
    ;

//support decimal only
FloatConst
    : DecimalFloatConst ('f' | 'F')
    ;

//support decimal only
DoubleConst
    : DecimalFloatConst
    ;

DecimalFloatConst
    : FracConst ExpPart?
    | DigitSeq ExpPart
    ;

FracConst
    : DigitSeq? '.' DigitSeq
    | '.' DigitSeq
    ;

ExpPart
    : 'e' ('+' | '-')? DigitSeq
    | 'E' ('+' | '-')? DigitSeq
    ;

DigitSeq
    : Digit+
    ;