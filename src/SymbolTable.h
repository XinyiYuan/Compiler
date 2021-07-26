#ifndef SYMTABLE_H
#define SYMTABLE_H
#include "headers.h"
enum
{
	CLS_INT,
	CLS_DOUBLE,
	CLS_FLOAT,
	CLS_BOOL,
	CLS_VOID
};
const int cls2len[5] = {
	4,//CLS_INT,
	8,//CLS_DOUBLE,
	4,//CLS_FLOAT,
	4,//CLS_BOOL,
	0//CLS_VOID
};
enum
{
	TYPE_CONST,
	TYPE_VAR,
	TYPE_ARRAY,
	TYPE_CONST_ARRAY
};




struct VarInfo {
  std::string name;
	int cls;		// class: int double float bool void
	int type;		// type: constvar var constarray array 
  int def_line;	// def position
  unsigned long long value;
  int global = 0;// 是否为全局变量
  int offset = -1024; //相对于所在block，应当为正
  int absOffset = -1024; //相对于所在函数fp。abs'=4,len=4-->访问fp-16-4-4=-24(s0)-->abs=-24
  int len;
  void print(){
    if(global)
      printf("G [%3d]",offset);
    else
      printf("- [%3d]",absOffset);
		std::string cls_str =(cls==0)? "int":\
						(cls==1)?	"double":\
						(cls==2)?	"float":\
						(cls==3)?	"bool":\
						(cls==4)?	"void":"";
		std::string type_str =(type==0)? "const":\
						(type==1)?	"var":\
						(type==2)?	"array":\
						(type==3)?	"ca":"";

    printf("%10s:%12s","name",name.c_str());    
	  printf("%10s:%6s", "cls",cls_str.c_str());
    printf("%10s:%5s", "type",type_str.c_str()); 
    printf("%10s:%2d", "def_line",def_line);
    printf("%10s:%2d", "offset",offset);
    printf("\n");
  }
};

struct BlockTable{
  int line; // start position
  std::map<std::string,VarInfo> symbol_table;
  int offset = 0; //相对于父block的偏移
  int len = 0; //在frame中占有的大小
  int longest_child_len = 0; 
  void print(){
    for(auto p:symbol_table)
      p.second.print();
  }
};

struct FuncInfo{
  std::string name;
  int cls; //return type
  int params; //number of paramters
  int def_line; //def position
  BlockTable base_block;
  int frame_len;
  void print(){
		std::string cls_str =(cls==0)? "int":\
						(cls==1)?	"double":\
						(cls==2)?	"float":\
						(cls==3)?	"bool":\
						(cls==4)?	"void":"";
    printf("[%3d]",frame_len);    
    printf("%12s:%12s","name",name.c_str());    
	  printf("%10s:%6s", "cls",cls_str.c_str());
    printf("%10s:%2d", "params",params); 
    printf("%10s:%2d", "def_line",def_line);
    printf("\n---base block---\n");
    base_block.print();
    printf("----------------");
    printf("\n");
  }
};



class SymbolTable
{
public:
  std::map<std::string,VarInfo> global_table;
  int global_offset = 0;
  std::map<std::string,FuncInfo> func_table;
  std::vector<BlockTable *> block_stack;
  std::vector<BlockTable *> block_record;
  std::string cur_func_name = "nullptr";
  std::string data_name = "nullptr";//the name of current-handling or recent-declareed data
public:
  SymbolTable(){
    block_record.push_back(nullptr);
    block_stack.push_back(nullptr);
  }
  VarInfo *lookup_symbol(const std::string &name);
  FuncInfo *lookup_func(const std::string &func_name);
  void add_symbol(std::string name, int cls, int type, int value, int def_line);
	void add_func(std::string name, int cls, int params, int def_line);
  void add_funcname(std::string name, int cls, int params, int def_line);
	
  void add_block(int line);
  void pop_block();
  int StringToInt(std::string rt_type);
  int calculateAbsOffset(VarInfo &tmp){
    //逐个block计算positive offset
    int count = this->block_stack.size();
    int pOffset = 0;
    for(int i=1;i<count;i++)
      pOffset += block_stack[i]->len;
    //计算absOffset
    return -16-pOffset-tmp.len;
  }
  void print(){
    printf("global_table\n");
    for(auto p:global_table)
      p.second.print();
    printf("func_table\n");
    for(auto p:func_table)
      p.second.print();
    printf("block_stack\n");
    int i=0;
    for(auto p:block_stack){
      printf("#%2d[%2d]\n",i,p==nullptr?0:p->len);i++;
      if(p!=nullptr)
        p->print();
      else
        printf("nullptr\n");
    }
  }
  void print_allsymbol(){
    int i = 0;
    for(auto p:block_record){
      printf("#%2d[%2d]\n",i,p==nullptr?0:p->len);i++;
      if(p!=nullptr)
        p->print();
      else
        printf("nullptr\n");
    }
  }
  std::string locate_stack_offset(VarInfo *info){
    if(!info->global){
      std::string stack_offset = std::to_string(info->absOffset)+"(s0)";
      return stack_offset;
    }else{
      return info->name+".G";
    }
  }

};

#endif