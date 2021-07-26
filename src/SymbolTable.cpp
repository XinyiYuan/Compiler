#include "SymbolTable.h"


VarInfo *SymbolTable::lookup_symbol(const std::string &name){
  int count = this->block_stack.size();
  int i;
  BlockTable * block;
  for(i=count;i>1;i--){
    block = block_stack[i-1];
    if(block->symbol_table.count(name)>0){
      assert(block->symbol_table.count(name)==1);
      return &block->symbol_table[name];
    }
  }
  if (this->global_table.count(name) == 1) // exists
		return &this->global_table[name];
	else
		return nullptr;
}

FuncInfo *SymbolTable::lookup_func(const std::string &func_name)
{
	if (this->func_table.count(func_name) == 1) // exists
		return &this->func_table[func_name];
	else
		return nullptr;
}

void SymbolTable::add_symbol(std::string name, int cls, int type, int value, int def_line){
  int count = this->block_stack.size();
  VarInfo tmp;
  tmp.name = name;
  tmp.cls = cls;
  tmp.type = type;
  tmp.value = value;
  tmp.def_line = def_line;
  tmp.global = 0;
  tmp.len = cls2len[tmp.cls];
  
  if(this->cur_func_name == "nullptr"){//global
    if(this->global_table.count(name) == 0){
      tmp.global = 1;
      tmp.offset = global_offset;
      tmp.absOffset = global_offset;
      global_offset += tmp.len;
			this->global_table.insert(std::pair<std::string, VarInfo>(name, tmp));
      this->data_name = name;
    }
		else
			throw std::runtime_error("\nMultiple definition!\n");
  }else{//
    //计算offsete & absolute offset
    tmp.offset = block_stack[count - 1]->len;
    tmp.absOffset = calculateAbsOffset(tmp);
    //更新block的len
    if(tmp.type == TYPE_ARRAY||tmp.type == TYPE_CONST_ARRAY){
      block_stack[count - 1]->len += tmp.len * tmp.value;
    }else
      block_stack[count - 1]->len += tmp.len;

    BlockTable *top = this->block_stack[count - 1];
    FuncInfo *func = lookup_func(this->cur_func_name);
    if(top->symbol_table.count(name) == 0 && func->base_block.symbol_table.count(name) == 0){
      top->symbol_table.insert(std::pair<std::string, VarInfo>(name, tmp));
      this->data_name = name;
    }
    else
      throw std::runtime_error("\nMultiple definition!\n");
  }
}
void SymbolTable::add_func(std::string name, int cls, int params, int def_line){
  FuncInfo tmp;
  tmp.name = name;
  tmp.cls = cls;
  tmp.params = params;
  tmp.def_line = def_line;
  tmp.frame_len = 0;
  
  if(this->func_table.count(name) == 0){
    this->func_table.insert(std::pair<std::string,FuncInfo>(name,tmp));
    block_stack.push_back(&func_table[name].base_block);
    block_record.push_back(&func_table[name].base_block);
  }else
    throw std::runtime_error("\nMultiple definition!\n");
}

void SymbolTable::add_block(int line){
  BlockTable *block = new BlockTable;
  int count = this->block_stack.size();
  block->offset = block_stack[count - 1]->len;
	block->line = line;
  block_record.push_back(block);
  block_stack.push_back(block);
}

void SymbolTable::add_funcname(std::string name, int cls, int params, int def_line){
  FuncInfo tmp;
  tmp.name = name;
  tmp.cls = cls;
  tmp.params = params;
  tmp.def_line = def_line;
  tmp.frame_len = 0;
  
  if(this->func_table.count(name) == 0){
    this->func_table.insert(std::pair<std::string,FuncInfo>(name,tmp));
  }else
    throw std::runtime_error("\nMultiple definition!\n");
}


void SymbolTable::pop_block(){
  int count;
  count = this->block_stack.size();
  //根据longest更新自己的len，从栈中弹出
  int child_len = block_stack[count - 1]->longest_child_len;
  block_stack[count - 1]->len += child_len; 
  child_len = block_stack[count - 1]->len;
  block_stack.pop_back();
  //新的栈顶是父节点
  count = this->block_stack.size();
  if(count>1){//（nullptr*1）如果也是block，更新longest
    if(block_stack[count - 1]->longest_child_len < child_len)
      block_stack[count - 1]->longest_child_len = child_len;
  }else if(count==1){//否则，更新函数cur_func_name的frame_len
    auto *func = lookup_func(cur_func_name);
    assert(func!=nullptr);
    //16 bytes for old ra/s0, 16 aligned 
    func->frame_len = child_len + 16;
    int no_padding = func->frame_len%16;
    if(no_padding!=0)
      func->frame_len += 16-no_padding;
  }else{
    printf("pop_block, count<1");
  }
}

int SymbolTable::StringToInt(std::string rt_type){
  int rt_type_int;
    if (rt_type == "int")
    {
        rt_type_int = CLS_INT;
    }
    else if (rt_type == "float")
    {
        rt_type_int = CLS_FLOAT;
    }
    else if (rt_type == "double")
    {
        rt_type_int = CLS_DOUBLE;
    }
    else if (rt_type == "bool")
    {
        rt_type_int = CLS_BOOL;
    }
    else if (rt_type == "void")
    {
        rt_type_int = CLS_VOID;
    }
    else
    {
        rt_type_int = -1;
        std::cout<< rt_type << std::endl;
    }
    return rt_type_int;
}


