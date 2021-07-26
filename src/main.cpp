#include <iostream>

#include "antlr4-runtime.h"
#include "../grammar/CACTLexer.h"
#include "../grammar/CACTParser.h"
#include "../grammar/CACTBaseListener.h"

#include "semanticAnalysis.h"
//#define MOREINFO 1
using namespace antlr4;

int main(int argc, const char* argv[]) {
    std::ifstream stream;
    stream.open(argv[1]);
    std::string name1 = argv[1];
    int pos1 = name1.find_last_of('/');
    std::string name2 = name1.substr(pos1 + 1);
    int pos2 = name2.find('.');
    std::string input_file_name = name2.substr(0,pos2);
    //std::cout << input_file_name << std::endl;
    ANTLRInputStream input(stream);
    CACTLexer lexer(&input);
    CommonTokenStream tokens(&lexer);
    CACTParser parser(&tokens);
/*#ifdef DEBUG
    parser.removeErrorListeners();
    VerboseErrorListener * ErrListenerInst = new VerboseErrorListener();
    parser.addErrorListener(ErrListenerInst);
#endif*/
    tree::ParseTree *tree = parser.compUnit();
    if (parser.getNumberOfSyntaxErrors() > 0 || lexer.getNumberOfSyntaxErrors() > 0)
	  {
		    std::cout << "Syntax error in this .cact file : Compilation failed !" << std::endl;
		    return -1;
	  }
    tree::ParseTreeWalker walker;
    IRListener listener;
    try {
        walker.walk(&listener, tree);
    }
    catch(const std::exception& e) {
        std::cerr << e.what() << '\n';
		    std::cout << "Semantic error in this .cact file : Compilation failed !" << std::endl;
		    return -1;
    }

    listener.RISCV_gen(input_file_name);
    return 0;
}
