#ifndef IRCODE_H
#define IRCODE_H
#include "headers.h"
#include "SymbolTable.h"

struct IRcode{
  std::string result;
  int opcode;
  std::string arg1;
  std::string arg2;
  int cls;
};

enum allowed_opcode {
  //e.g. [result="r",opcode"...",arg1="a1",arg2="a2",cls=INT]
  //--> r = a1 ... a2, and all are int
  OP_ADD,
  OP_SUB,
  OP_MUL,
  OP_DIV,
  OP_MOD,
  OP_AND,
  OP_OR,
  OP_NOT,
  OP_GT,
  OP_GE,
  OP_LT,
  OP_LE,
  OP_EQ,
  OP_NE,
  //e.g. [result="reg",opcode="LOAD",arg1="20",arg2="regAddr",cls=INT]
  //--> reg = 20(regAddr), and reg is int
  OP_LOAD,
  //e.g. [result="reg",opcode="STORE",arg1="20",arg2="regAddr",cls=INT]
  //--> 20(regAddr) = reg, and reg is int
  OP_STORE,
  OP_MOVE,
  //e.g. [result="reg",opcode="LI",arg1="20",arg2="",cls=INT]
  //--> reg = 20, and reg is int
  OP_LI,

  OP_G_ASSIGN,//assign for global var
  //e.g. [result="arr",opcode"G-ARR-ASSIGN",arg1="2",arg2="10",cls=INT]
  //--> arr[2] = 10, and arr is array of int
  OP_G_ARR_ASSIGN,//assign for global array 
  //e.g. [result="arr",opcode"G-ARR-ASSIGN",arg1="2",arg2="10",cls=INT]
  //--> arr[2] = 10, and arr is array of int
  OP_G_ARR_DECL,
  OP_ARR_DECL,
  OP_ARR_ASSIGN,
  OP_LOAD_ARR,

  //e.g. [result="name",opcode="GOTO",arg1="",arg2="",cls=0]
  //--> goto name
  OP_GOTO,
  OP_LABEL,
  OP_CALL,
  OP_RET,
  OP_PARAM,
  OP_BEQZ,

  FUNC_BEGIN,
  FUNC_END
};

class IR{
public:
  std::vector<IRcode> IR_codes;
  int tmp_var_cnt;
  int label_cnt;
  std::string tmp_var_head = "_tmp_var";
  std::string label_head = "__lable";
  std::vector<std::string> b_false_list;
  std::vector<std::string> b_true_list;


  IR(){
      tmp_var_cnt = 0;
      label_cnt = 0;
  }

  void add_IRC(std::string result,int opcode,std::string arg1,std::string arg2,int cls);
  void print_IRC();
  std::string get_label(){
      return label_head+std::to_string(++label_cnt);
  }
  std::string gen_temp(int line, int cls, SymbolTable& );
  std::string gen_temp_array(int line, int cls,int length, SymbolTable& );

};

#endif