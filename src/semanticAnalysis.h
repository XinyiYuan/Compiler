#pragma

#include "antlr4-runtime.h"
#include "../grammar/CACTBaseListener.h"
#include "SymbolTable.h"
#include "IRcode.h"
#include "CACTLexer.h"

typedef int status_t;
enum{
    ok,warning,critical,error
};

namespace antlr4{
    class VerboseErrorListener : public BaseErrorListener{
    public:
        
        status_t level;
        VerboseErrorListener(){
            level = ok;
        }

        void syntaxError(Recognizer *recognizer, Token * offendingSymbol, size_t line, size_t charPositionInLine,
          const std::string &msg, std::exception_ptr e){
            level = error;
            std::vector<std::string> stack = ((antlr4::Parser *)recognizer)->getRuleInvocationStack();
            std::reverse(stack.begin(),stack.end());
            std::cout << "rule stack: [";
            for(int i=0;i<stack.size();i++)
                std::cout << stack[i] << ", ";
            std::cout << "]" << std::endl;
            std::cout << "line: " << line << ":" << charPositionInLine << " at " << offendingSymbol->getText() << std::endl;
        }
    };
};

class IRListener : public CACTBaseListener
{
private:
    /* data */
    SymbolTable symbol_table;
    IR ircode_gen;
    int float_tmp_cnt = 0;//LCx
    std::vector<std::string> riscv_codes;
    std::vector<std::string> rodata;

public:
    
    IRListener(/* args */){}
    ~IRListener(){}


    void enterCompUnit(CACTParser::CompUnitContext * /*ctx*/) override;
    void exitCompUnit(CACTParser::CompUnitContext * /*ctx*/) override;

    void enterDecl(CACTParser::DeclContext * /*ctx*/) override { }
    void exitDecl(CACTParser::DeclContext * /*ctx*/) override { }

    void enterConstDecl(CACTParser::ConstDeclContext * /*ctx*/) override;
    void exitConstDecl(CACTParser::ConstDeclContext * /*ctx*/) override;

    void enterBType(CACTParser::BTypeContext * /*ctx*/) override { }
    void exitBType(CACTParser::BTypeContext * /*ctx*/) override { }

    void enterConstDef(CACTParser::ConstDefContext * /*ctx*/) override { }
    void exitConstDef(CACTParser::ConstDefContext * /*ctx*/) override { }

    void enterConstInitVal(CACTParser::ConstInitValContext * /*ctx*/) override { }
    void exitConstInitVal(CACTParser::ConstInitValContext * /*ctx*/) override { }
    void enterConstInitArray(CACTParser::ConstInitArrayContext * /*ctx*/) override;
    void exitConstInitArray(CACTParser::ConstInitArrayContext * /*ctx*/) override;

    void enterVarDecl(CACTParser::VarDeclContext * /*ctx*/) override;
    void exitVarDecl(CACTParser::VarDeclContext * /*ctx*/) override;

    void enterVarDef(CACTParser::VarDefContext * /*ctx*/) override { }
    void exitVarDef(CACTParser::VarDefContext * /*ctx*/) override { }
    
    void enterFuncDef(CACTParser::FuncDefContext * /*ctx*/) override;
    void exitFuncDef(CACTParser::FuncDefContext * /*ctx*/) override;

    void enterFuncType(CACTParser::FuncTypeContext * /*ctx*/) override { }
    void exitFuncType(CACTParser::FuncTypeContext * /*ctx*/) override { }

    void enterFuncFParams(CACTParser::FuncFParamsContext * /*ctx*/) override { }
    void exitFuncFParams(CACTParser::FuncFParamsContext * /*ctx*/) override { }

    void enterFuncFParam(CACTParser::FuncFParamContext * /*ctx*/) override { }
    void exitFuncFParam(CACTParser::FuncFParamContext * /*ctx*/) override { }
    void enterExp(CACTParser::ExpContext * /*ctx*/) override;
    void exitExp(CACTParser::ExpContext * /*ctx*/) override;
    
    void enterAddExp(CACTParser::AddExpContext * /*ctx*/) override;
    void exitAddExp(CACTParser::AddExpContext * /*ctx*/) override;
    
    void enterMulExp(CACTParser::MulExpContext * /*ctx*/) override;
    void exitMulExp(CACTParser::MulExpContext * /*ctx*/) override;
    
    void enterUnaryExp(CACTParser::UnaryExpContext * /*ctx*/) override;
    void exitUnaryExp(CACTParser::UnaryExpContext * /*ctx*/) override;
    
    void enterPrimaryExp(CACTParser::PrimaryExpContext * /*ctx*/) override;
    void exitPrimaryExp(CACTParser::PrimaryExpContext * /*ctx*/) override;
    
    void enterAssignStmt(CACTParser::AssignStmtContext * /*ctx*/) override;
    void exitAssignStmt(CACTParser::AssignStmtContext * /*ctx*/) override;

    void enterNumber(CACTParser::NumberContext * /*ctx*/) override;
    void exitNumber(CACTParser::NumberContext * /*ctx*/) override;
    void enterLVal(CACTParser::LValContext * /*ctx*/) override;
    void exitLVal(CACTParser::LValContext * /*ctx*/) override;

    void enterBlock(CACTParser::BlockContext * /*ctx*/) override;
    void exitBlock(CACTParser::BlockContext * /*ctx*/) override;
    
    void enterWhileStmt(CACTParser::WhileStmtContext * /*ctx*/) override;
    void exitWhileStmt(CACTParser::WhileStmtContext * /*ctx*/) override;
    void enterIfStmt(CACTParser::IfStmtContext * /*ctx*/) override;
    void exitIfStmt(CACTParser::IfStmtContext * /*ctx*/) override;
    void enterIfElseStmt(CACTParser::IfElseStmtContext * /*ctx*/) override;
    void exitIfElseStmt(CACTParser::IfElseStmtContext * /*ctx*/) override;
    void enterElseStmt(CACTParser::ElseStmtContext * /*ctx*/) override;
    void exitElseStmt(CACTParser::ElseStmtContext * /*ctx*/) override;
    
    void enterReturnStmt(CACTParser::ReturnStmtContext * /*ctx*/) override;
    void exitReturnStmt(CACTParser::ReturnStmtContext * /*ctx*/) override;
    
    void enterRelExp(CACTParser::RelExpContext * /*ctx*/) override;
    void exitRelExp(CACTParser::RelExpContext * /*ctx*/) override;

    void enterEqExp(CACTParser::EqExpContext * /*ctx*/) override;
    void exitEqExp(CACTParser::EqExpContext * /*ctx*/) override;

    void enterLAndExp(CACTParser::LAndExpContext * /*ctx*/) override;
    void exitLAndExp(CACTParser::LAndExpContext * /*ctx*/) override;

    void enterLOrExp(CACTParser::LOrExpContext * /*ctx*/) override;
    void exitLOrExp(CACTParser::LOrExpContext * /*ctx*/) override;
    
    void enterCond(CACTParser::CondContext * /*ctx*/) override;
    void exitCond(CACTParser::CondContext * /*ctx*/) override;
    void enterIfCond(CACTParser::IfCondContext * /*ctx*/) override;
    void exitIfCond(CACTParser::IfCondContext * /*ctx*/) override;
    void enterWhileCond(CACTParser::WhileCondContext * /*ctx*/) override;
    void exitWhileCond(CACTParser::WhileCondContext * /*ctx*/) override;

    void enterEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
    void exitEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
    void visitTerminal(antlr4::tree::TerminalNode * /*node*/) override { }
    void visitErrorNode(antlr4::tree::ErrorNode * /*node*/) override { }


    void RISCV_gen(std::string input_file_name);

    void FUNC_BEGIN_method(IRcode * ir_code);
    void FUNC_END_method(IRcode * ir_code);
    void CALL_method(IRcode * ir_code);
    void STORE_method(IRcode * ir_code);
    void LOAD_method(IRcode * ir_code);
    void LI_method(IRcode * ir_code);
    void MOVE_method(IRcode * ir_code);
    void ADD_method(IRcode * ir_code);
    void SUB_method(IRcode * ir_code);
    void MUL_method(IRcode *ir_code);
    void DIV_method(IRcode *ir_code);
    void MOD_method(IRcode *ir_code);
    void LABEL_method(IRcode *ir_code);
    void LT_method(IRcode *ir_code);
    void LE_method(IRcode *ir_code);
    void GT_method(IRcode *ir_code);
    void GE_method(IRcode *ir_code);
    void EQ_method(IRcode *ir_code);
    void NE_method(IRcode *ir_code);
    void AND_method(IRcode *ir_code);
    void OR_method(IRcode *ir_code);
    void BEQZ_method(IRcode *ir_code);
    void GOTO_method(IRcode *ir_code);
    void G_ASSIGN_method(IRcode *ir_code);
    void G_ARR_ASSIGN_method(IRcode *ir_code);
    void G_ARR_DECL_method(IRcode *ir_code);
    void ARR_ASSIGN_method(IRcode *ir_code);
    void LOAD_ARR_method(IRcode *ir_code);


};
