#include "IRcode.h"

void IR::add_IRC(std::string result,int opcode,std::string arg1,std::string arg2,int cls){
	IRcode tmp;
	tmp.result = result;
	tmp.opcode = opcode;
	tmp.arg1 = arg1;
	tmp.arg2 = arg2;
	tmp.cls = cls;
	this->IR_codes.push_back(tmp);
}
void IR::print_IRC(){
	for(auto p : IR_codes) {
		std::cout << std::right;
		std::string cls =
						(p.cls==0)? "int":\
						(p.cls==1)?	"double":\
						(p.cls==2)?	"float":\
						(p.cls==3)?	"bool":"";
		std::string opcode_str =
						(p.opcode==OP_LOAD)? "OP_LOAD":\
						(p.opcode==OP_STORE)? "OP_STORE":\
						(p.opcode==OP_MOVE)? "OP_MOVE":\
						(p.opcode==OP_LI)? "OP_LI":\
						(p.opcode==OP_G_ASSIGN)? "OP_G_ASSIGN":\
						(p.opcode==OP_G_ARR_ASSIGN)? "OP_G_ARR_ASSIGN":\
						(p.opcode==OP_G_ARR_DECL)? "OP_G_ARR_DECL":\
						(p.opcode==OP_GOTO)? "OP_GOTO":\
						(p.opcode==OP_LABEL)? "OP_LABEL":\
						(p.opcode==OP_CALL)? "OP_CALL":\
						(p.opcode==OP_RET)? "OP_RET":\
						(p.opcode==OP_PARAM)? "OP_PARAM":\
						(p.opcode==FUNC_BEGIN)? "FUNC_BEGIN":\
						(p.opcode==FUNC_END)? "FUNC_END":\
						(p.opcode==OP_ARR_ASSIGN)?"ARR_ASSIGN":\
						(p.opcode==OP_LOAD_ARR)?"LOAD_ARR":\
						(p.opcode==OP_ARR_DECL)?"ARR_DECL":\
						(p.opcode==OP_BEQZ)?"BEQZ":\
						(p.opcode==OP_GOTO)?"GOTO":\
						(p.opcode==OP_ADD)?"ADD":\
						(p.opcode==OP_LT)?"LT":\
						"";
			
		std::cout << std::setw(10) << opcode_str << "  " << std::setw(14) << p.result << "  " 
			<< std::setw(14) << p.arg1 << "  " << std::setw(14) << p.arg2 << "  "
			<< std::setw(7) << p.cls << std::endl;
	}
}

std::string IR::gen_temp(int line, int cls, SymbolTable& symbol_table) {
    assert(cls == CLS_INT || cls == CLS_DOUBLE || cls == CLS_FLOAT || cls == CLS_BOOL);
    auto name = tmp_var_head + std::to_string(++tmp_var_cnt);
    symbol_table.add_symbol(name, cls, TYPE_VAR, 0, line);
	return name;
}
std::string IR::gen_temp_array(int line, int cls,int length, SymbolTable& symbol_table){
	auto name = tmp_var_head + std::to_string(++tmp_var_cnt);
    symbol_table.add_symbol(name, cls, TYPE_ARRAY, length, line);
	return name;
}

