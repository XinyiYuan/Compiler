#include "semanticAnalysis.h"

void IRListener::enterCompUnit(CACTParser::CompUnitContext * ctx) { 
    //recover
    symbol_table.add_funcname("print_int", CLS_VOID, 1, 0);
    symbol_table.add_funcname("print_bool", CLS_VOID, 1, 0);
    symbol_table.add_funcname("print_float", CLS_VOID, 1, 0);
    symbol_table.add_funcname("print_double", CLS_VOID, 1, 0);
    symbol_table.add_funcname("get_int", CLS_INT, 0, 0);
    symbol_table.add_funcname("get_float", CLS_FLOAT, 0, 0);
    symbol_table.add_funcname("get_double", CLS_DOUBLE, 0, 0);
}
void IRListener::exitCompUnit(CACTParser::CompUnitContext * ctx) {
    if(this->symbol_table.lookup_func("main") == nullptr){
      std::cout<<"line"<<std::to_string(ctx->getStart()->getLine())<<":"<<std::endl;
      throw std::runtime_error("\nDid't define a main function!\n");
    }
    // //debug
    // ircode_gen.print_IRC();
    // //debug

}

void IRListener::enterBlock(CACTParser::BlockContext * ctx){
    int line = ctx->getStart()->getLine();
    symbol_table.add_block(line);
}
void IRListener::exitBlock(CACTParser::BlockContext * ctx){
    symbol_table.pop_block();
    // printf("@line%3d:\n",ctx->getStart()->getLine());
    // symbol_table.print();
}
void IRListener::exitConstDecl(CACTParser::ConstDeclContext * ctx)
{
}
void IRListener::enterConstDecl(CACTParser::ConstDeclContext * ctx)
{
    std::string name;
    std::string cls_string;
    std::string value_string;
    int type = TYPE_CONST;
    int init_type = TYPE_CONST;
    int length = 0;
    unsigned long long value=0;
    //std::cout << "const variable define: " << std::endl;
    for(const auto & const_def : ctx->constDef())
    {
        if(const_def->Ident() == nullptr)
            return;
        name = const_def->Ident()->getText().c_str();
        cls_string = ctx->bType()->getText().c_str();
        //检查常量类型是否为常量数组
        if(const_def -> arraySymbol() != nullptr){
            type = TYPE_CONST_ARRAY;
            std::string length_str = const_def -> arraySymbol()->IntConst()->getText();
            length = std::stoi(length_str, 0, getIntStringBase(length_str));
        }
        //检查初始化类型是否为常量数组
        if(const_def -> constInitVal()->constInitArray()!=nullptr)
            init_type = TYPE_CONST_ARRAY;
        else if(const_def -> constInitVal()->constExp() != nullptr)
            value_string = const_def ->constInitVal()-> constExp()->getText();

           //检查初始化类型与常量类型是否匹配
        if(type != init_type){
            std::cout<<"line"<<std::to_string(ctx->getStart()->getLine())<<":"<<std::endl;
            throw std::runtime_error("\nUnmatched initial value!\n");
        }
        int cls = symbol_table.StringToInt(cls_string);
        int def_line = ctx->getStart()->getLine();
        std::string format_value;

        if(type == TYPE_CONST_ARRAY){
            value = length;
            format_value = std::to_string(length);
        }
        else if(cls == CLS_INT){
            int ival = std::stoi(value_string, 0, getIntStringBase(value_string));
            value = *(unsigned long long *)&ival;
            format_value = std::to_string(ival);
        }
        else if(cls == CLS_BOOL){
            int bval = (value_string == "true") ? 1:0;
            value = *(unsigned long long *)&bval;
            format_value = std::to_string(bval);
        }
        else if(cls == CLS_DOUBLE){
            double dval = std::stod(value_string);
            value = *(unsigned long long *)&dval;
            format_value = std::to_string(dval);
        }
        else{
            float fval = std::stof(value_string.substr(0, value_string.length() - 1));
            value =  *(unsigned long long *)&fval;
            format_value = std::to_string(fval);
        }
        symbol_table.add_symbol(name,cls,type,value,def_line);        
        auto info = symbol_table.lookup_symbol(name);
        if(!info->global){
            if(info->type == TYPE_ARRAY || info->type == TYPE_CONST_ARRAY){
                ircode_gen.add_IRC(name,OP_ARR_DECL,format_value,"NULL",cls);
            }else{
                ircode_gen.add_IRC("t2",OP_LI,format_value,"NULL",cls);
                ircode_gen.add_IRC("t2",OP_STORE,symbol_table.locate_stack_offset(info),"NULL",cls);
            }

        }else{
            if(info->type == TYPE_ARRAY || info->type == TYPE_CONST_ARRAY){
                ircode_gen.add_IRC(name,OP_G_ARR_DECL,format_value,"const",cls);
            }else{
                ircode_gen.add_IRC(name,OP_G_ASSIGN,format_value,"const",cls);
            }
        }
    }
    
}

void IRListener::exitVarDecl(CACTParser::VarDeclContext * ctx)
{
    //std::string class_str =  ctx->bType()->getText();
  
}
void IRListener::enterVarDecl(CACTParser::VarDeclContext * ctx)
{
#ifdef DEBUG
    std::cout << "variable define: " << std::endl;
    for(const auto & var_def : ctx->varDef())
    {
        if(var_def->Ident()==NULL)
            break;
        std::cout << "\tname: " << var_def->Ident()->getText().c_str() \
                << " type: " << ctx->bType()->getText().c_str() << std::endl;
    }
#endif 

    std::string name;
    std::string cls_string;
    std::string init_cls_string;
    std::string value_string;
    int type = TYPE_VAR;
    int init_type = TYPE_VAR;
    int length=0;
    int inited=0;
    unsigned long long value=0;
    //std::cout << "variable define: " << std::endl;
    for(const auto & var_def : ctx->varDef())
    {
        if(var_def->Ident()==NULL)
            return;
        name = var_def->Ident()->getText().c_str();
        cls_string = ctx->bType()->getText().c_str();
        //检查变量是否为数组
        if(var_def -> arraySymbol() != nullptr){
            type = TYPE_ARRAY;
            std::string length_str = var_def -> arraySymbol()->IntConst()->getText();
            length = std::stoi(length_str, 0, getIntStringBase(length_str));
        }
            //如果有初始化
        if(var_def -> constInitVal()){
            inited = 1;
            //检查初始化类型是否为数组
            if(var_def -> constInitVal()->constInitArray()!=nullptr)
                init_type = TYPE_ARRAY;
            //记录初始化类型
            else if(var_def -> constInitVal()->constExp() != nullptr){
                value_string = var_def ->constInitVal()-> constExp()->getText();
                if(var_def -> constInitVal()->constExp()->BoolConst()!=nullptr)
                    init_cls_string = "bool";   
                else if(var_def -> constInitVal()->constExp()->number()->IntConst()!=nullptr)
                    init_cls_string = "int";
                else if(var_def -> constInitVal()->constExp()->number()->DoubleConst()!=nullptr)
                    init_cls_string = "double";
                else if(var_def -> constInitVal()->constExp()->number()->FloatConst()!=nullptr)
                    init_cls_string = "float";
            }
            //如果变量类型与初始化类型不匹配
            if(cls_string != init_cls_string && var_def -> constInitVal()->constExp() != nullptr){
                std::cout<<"line"<<std::to_string(ctx->getStart()->getLine())<<":"<<std::endl;
                throw std::runtime_error("\nUnmatched initial value!\n");
            }
            if(type != init_type){
                std::cout<<"line"<<std::to_string(ctx->getStart()->getLine())<<":"<<std::endl;
                throw std::runtime_error("\nUnmatched initial value!\n");
            }
        }     

        int cls = symbol_table.StringToInt(cls_string);
        int def_line = ctx->getStart()->getLine();
        //std::cout<<value_string<<"\n"<<std::endl;
        std::string format_value = "0";
        if(type != TYPE_ARRAY && inited){
            if(cls == CLS_INT){
                int ival = std::stoi(value_string, 0, getIntStringBase(value_string));
                value = *(unsigned long long *)&ival;
                format_value = std::to_string(ival);
            }
            else if(cls == CLS_BOOL){
                int bval = (value_string == "true") ? 1:0;
                value = *(unsigned long long *)&bval;
                format_value = std::to_string(bval);
            }
            else if(cls == CLS_DOUBLE){
                double dval = std::stod(value_string);
                value = *(unsigned long long *)&dval;
                format_value = std::to_string(dval);

            }
            else{
                float fval = std::stof(value_string.substr(0, value_string.length() - 1));
                value =  *(unsigned long long *)&fval;
                format_value = std::to_string(fval);
            }
        }else{
            value = length;
            format_value = std::to_string(length);
        }
        symbol_table.add_symbol(name,cls,type,value,def_line);
        auto info = symbol_table.lookup_symbol(name);
        std::string init = (inited)?"inited":"uninited";
        if(!info->global){
            if(info->type == TYPE_ARRAY || info->type == TYPE_CONST_ARRAY){
                ircode_gen.add_IRC(name,OP_ARR_DECL,format_value,"NULL",cls);
            }else{
                ircode_gen.add_IRC("t2",OP_LI,format_value,"NULL",cls);
                ircode_gen.add_IRC("t2",OP_STORE,symbol_table.locate_stack_offset(info),"NULL",cls);
            }

        }else{
            if(info->type == TYPE_ARRAY || info->type == TYPE_CONST_ARRAY){
                ircode_gen.add_IRC(name,OP_G_ARR_DECL,format_value,init,cls);
            }else{
                ircode_gen.add_IRC(name,OP_G_ASSIGN,format_value,init,cls);
            }
        }
    } 
}
void IRListener::enterConstInitArray(CACTParser::ConstInitArrayContext * ctx){
    std::string value_string;
    std::string format_value;
    int idx = 0;
    auto info = symbol_table.lookup_symbol(symbol_table.data_name);
    int cls = info->cls;
    int array_len = info->value;
    std::string array_start_addr = symbol_table.locate_stack_offset(info);
    if(symbol_table.cur_func_name == "nullptr"){//global
        for(const auto &p:ctx->constExp()){
            value_string = p->getText();
            if(cls == CLS_INT){
                int ival = std::stoi(value_string, 0, getIntStringBase(value_string));
                format_value = std::to_string(ival);
            }
            else if(cls == CLS_BOOL){
                int bval = (value_string == "true") ? 1:0;
                format_value = std::to_string(bval);
            }
            else if(cls == CLS_DOUBLE){
                double dval = std::stod(value_string);
                format_value = std::to_string(dval);

            }
            else{
                float fval = std::stof(value_string.substr(0, value_string.length() - 1));
                format_value = std::to_string(fval);
            }
            ircode_gen.add_IRC(info->name,OP_G_ARR_ASSIGN,std::to_string(idx),format_value,cls);
            idx++;
        }
        while (idx < array_len)
        {
            ircode_gen.add_IRC(info->name, OP_G_ARR_ASSIGN, std::to_string(idx),"0",cls);
            idx++;
        }
    }else{//local
        for(const auto &p:ctx->constExp()){
            value_string = p->getText();
            if(cls == CLS_INT){
                int ival = std::stoi(value_string, 0, getIntStringBase(value_string));
                format_value = std::to_string(ival);
            }
            else if(cls == CLS_BOOL){
                int bval = (value_string == "true") ? 1:0;
                format_value = std::to_string(bval);
            }
            else if(cls == CLS_DOUBLE){
                double dval = std::stod(value_string);
                format_value = std::to_string(dval);

            }
            else{
                float fval = std::stof(value_string.substr(0, value_string.length() - 1));
                format_value = std::to_string(fval);
            }
            ircode_gen.add_IRC("t2", OP_LI, format_value, "NULL", cls);
            ircode_gen.add_IRC("t3", OP_LI, std::to_string(idx), "NULL", CLS_INT);
            ircode_gen.add_IRC("t2",OP_ARR_ASSIGN,array_start_addr,"t3",cls);
            idx++;
        }
    }
    
}
void IRListener::exitConstInitArray(CACTParser::ConstInitArrayContext * ctx){}
void IRListener::enterFuncDef(CACTParser::FuncDefContext * ctx){
    std::string name = ctx->Ident()->getText().c_str();
    std::string type_string = ctx->funcType()->getText();
    int cls = symbol_table.StringToInt(type_string);
    int params = 0;
    if(ctx->funcFParams()!=nullptr)
      params = ctx->funcFParams()->funcFParam().size();
    int def_line = ctx->getStart()->getLine();
    //检查main函数是否符合规范
    if(name == "main"){
        if(params != 0){
            std::cout<<"line"<<std::to_string(ctx->getStart()->getLine())<<":"<<std::endl;
            throw std::runtime_error("Too many args in main function!\n");
        }
        if(cls != CLS_INT){
            std::cout<<"line"<<std::to_string(ctx->getStart()->getLine())<<":"<<std::endl;
            throw std::runtime_error("Unmatched return type of main function!\n");
        }
    }
    //添加函数及形参到符号表
    symbol_table.add_func(name,cls,params,def_line);
    symbol_table.cur_func_name = name;
    ircode_gen.add_IRC(name,FUNC_BEGIN,"NULL","NULL",cls);
    int param_cnt = 0;
    if(params != 0){
        for(auto & local_param: ctx->funcFParams()->funcFParam()){
            std::string name = local_param->Ident()->getText();
            std::string cls_string = local_param->bType()->getText();
            int type;
            if(local_param->arraySymbol())
                type = TYPE_ARRAY;
            else
                type = TYPE_VAR;
            int value = 0;
            int cls = symbol_table.StringToInt(cls_string);
            symbol_table.add_symbol(name,cls,type,value,def_line);
            //ircode_gen.add_IRC("t2", OP::MOV, "a" + std::to_string(param_cnt), VOID, cls);
            auto info = symbol_table.lookup_symbol(name);
            std::string dest = symbol_table.locate_stack_offset(info);
            ircode_gen.add_IRC("a" + std::to_string(param_cnt), OP_STORE, dest, "NULL", cls);
        }
    }
    

 }
void IRListener::exitFuncDef(CACTParser::FuncDefContext * ctx){ 
    //remove base block即形参
    symbol_table.pop_block();
    // //debug
    // printf("@func:%5s[%3d]\n",
    //   symbol_table.cur_func_name.c_str(),
    //   symbol_table.lookup_func(symbol_table.cur_func_name)->frame_len
    // );
    // symbol_table.print();
    // symbol_table.print_allsymbol();
    // //debug
    symbol_table.cur_func_name = "nullptr"; 
}
void IRListener::enterExp(CACTParser::ExpContext * ctx){
}
void IRListener::exitExp(CACTParser::ExpContext * ctx){
    if (ctx->addExp())
    {
        ctx->cls = ctx->addExp()->cls;
        ctx->tmp = ctx->addExp()->tmp;
        ctx->type = ctx->addExp()->type;
        ctx->elementwise = ctx->addExp()->elementwise;
    }else{
        ctx->cls = CLS_BOOL;
        ctx->elementwise = false;
    }
}

void IRListener::enterAddExp(CACTParser::AddExpContext * ctx){
}
void IRListener::exitAddExp(CACTParser::AddExpContext * ctx){
    ctx->tmp = ctx->mulExp()->tmp;
    ctx->cls = ctx->mulExp()->cls;
    ctx->type = ctx->mulExp()->type;
    ctx->elementwise = ctx->mulExp()->elementwise;
    int cls = ctx->mulExp()->cls;
    if (ctx->addExp())
     //case: addexp -> addexp (+/-) mulexp
    {
        if (ctx->addExp()->cls != cls){ //类型检查
            std::cout<<"line"<<std::to_string(ctx->getStart()->getLine())<<":"<<std::endl;
            throw std::runtime_error("Cannot cast type!");
        }
        if(ctx->addExp()->elementwise || ctx->mulExp()->elementwise){
            auto *add1 = symbol_table.lookup_symbol(ctx->addExp()->tmp);
            auto *add2 = symbol_table.lookup_symbol(ctx->mulExp()->tmp);
            if(ctx->addExp()->elementwise != ctx->mulExp()->elementwise || add1 == nullptr || add2 == nullptr || add1->value != add2->value){
                std::cout<<"line"<<std::to_string(ctx->getStart()->getLine())<<":"<<std::endl;
                throw std::runtime_error("Unmatched array add length!\n");
            }
            auto tmp = ircode_gen.gen_temp_array(ctx->getStart()->getLine(), add1->cls, add1->value, symbol_table);
            auto tmp_info = symbol_table.lookup_symbol(tmp);
            auto add1_addr = symbol_table.locate_stack_offset(add1);
            auto add2_addr = symbol_table.locate_stack_offset(add2);
            auto tmp_addr = symbol_table.locate_stack_offset(tmp_info);
            int cls = add1->cls;
            int op;
            if (ctx->op->getType() == CACTLexer::ADD) //+
                op = OP_ADD; 
            else
                op = OP_SUB;
            for (int i = 0; i < add1->value; i++)
            {
                ircode_gen.add_IRC("t4", OP_LI, std::to_string(i), "NULL", CLS_INT);
                ircode_gen.add_IRC("t1", OP_LOAD_ARR, add1_addr, "t4", cls);
                ircode_gen.add_IRC("t2", OP_LOAD_ARR, add2_addr, "t4", cls);
                ircode_gen.add_IRC("t3", op, "t1", "t2", cls); //+
                ircode_gen.add_IRC("t3", OP_ARR_ASSIGN, tmp_addr, "t4", cls);
            }
            
            ctx->elementwise = true;
            ctx->tmp = tmp;
        }else{
            std::string tmp = ircode_gen.gen_temp(ctx->getStart()->getLine(), cls , symbol_table);
            auto info = symbol_table.lookup_symbol(tmp);
            std::string addr = symbol_table.locate_stack_offset(info);
            ctx->tmp = tmp;
            auto var1 = symbol_table.lookup_symbol(ctx->addExp()->tmp);
            auto var2 = symbol_table.lookup_symbol(ctx->mulExp()->tmp);
            int op;
            if (ctx->op->getType() == CACTLexer::ADD)
                op = OP_ADD;
            else
                op = OP_SUB;
            ircode_gen.add_IRC("t0", OP_LOAD, symbol_table.locate_stack_offset(var1), "NULL", cls);
            ircode_gen.add_IRC("t1", OP_LOAD, symbol_table.locate_stack_offset(var2), "NULL", cls);
            ircode_gen.add_IRC("t2", op, "t0", "t1", cls);//op +/-
            ircode_gen.add_IRC("t2", OP_STORE, addr, "NULL", cls);
        }
    }else{
        ctx->tmp = ctx->mulExp()->tmp;
    }
}
void IRListener::enterMulExp(CACTParser::MulExpContext * ctx){
}
void IRListener::exitMulExp(CACTParser::MulExpContext * ctx){
    int cls = ctx->unaryExp()->cls;
    ctx->cls = ctx->unaryExp()->cls;
    ctx->type = ctx->unaryExp()->type;
    ctx->elementwise = ctx->unaryExp()->elementwise;
    ctx->tmp = ctx->unaryExp()->tmp;
    if (!ctx->mulExp()) // case: mulexp ->unaryexp
    {
        if (ctx->cls == CLS_VOID) //only void funcall return void here
            ctx->tmp = "NULL"; //just give a name here
        ctx->tmp = ctx->unaryExp()->tmp;
    }
    else //case: mulexp -> mulexp (* /) unaryexp
    {
        if (ctx->mulExp()->cls != cls){ //类型检查
            std::cout<<"line"<<std::to_string(ctx->getStart()->getLine())<<":"<<std::endl;
            throw std::runtime_error("Cannot cast type!\n");
        }
        if(ctx->unaryExp()->elementwise || ctx->mulExp()->elementwise){
            auto *add1 = symbol_table.lookup_symbol(ctx->unaryExp()->tmp);
            auto *add2 = symbol_table.lookup_symbol(ctx->mulExp()->tmp);
            if(ctx->unaryExp()->elementwise != ctx->mulExp()->elementwise || add1 == nullptr || add2 == nullptr || add1->value != add2->value){
                std::cout<<"line"<<std::to_string(ctx->getStart()->getLine())<<":"<<std::endl;
                throw std::runtime_error("Unmatched array add length!\n");
            }
        }else{
            std::string tmp = ircode_gen.gen_temp(ctx->getStart()->getLine(), cls , symbol_table);
            auto info = symbol_table.lookup_symbol(tmp);
            std::string addr = symbol_table.locate_stack_offset(info);
            ctx->tmp = tmp;
            auto var1 = symbol_table.lookup_symbol(ctx->mulExp()->tmp);
            auto var2 = symbol_table.lookup_symbol(ctx->unaryExp()->tmp);

            int op;
            if (ctx->op->getType() == CACTLexer::MUL)
                op = OP_MUL;
            else if(ctx->op->getType() == CACTLexer::DIV)
                op = OP_DIV;
            else
                op = OP_MOD;
            ircode_gen.add_IRC("t0", OP_LOAD, symbol_table.locate_stack_offset(var1), "NULL", cls);
            ircode_gen.add_IRC("t1", OP_LOAD, symbol_table.locate_stack_offset(var2), "NULL", cls);
            ircode_gen.add_IRC("t2", op, "t0", "t1", cls);//op * \/\ %
            ircode_gen.add_IRC("t2", OP_STORE, addr, "NULL", cls);
        }
    }
}

void IRListener::enterUnaryExp(CACTParser::UnaryExpContext * ctx){

}
void IRListener::exitUnaryExp(CACTParser::UnaryExpContext * ctx){
    if(ctx->primaryExp()){//case:unaryExp -> primaryExp
        ctx->cls = ctx->primaryExp()->cls;
        ctx->tmp = ctx->primaryExp()->tmp;
        ctx->type = ctx->primaryExp()->type;
        ctx->elementwise = ctx->primaryExp()->elementwise;
    }else if(ctx->Ident()){//case:unaryExp -> Ident '(' funcRParams? ')'
        auto * func = symbol_table.lookup_func(ctx->Ident()->getText());
        ctx->elementwise = false;
        if(func == nullptr){
            std::cout<<"line"<<std::to_string(ctx->getStart()->getLine())<<":"<<std::endl;
            throw std::runtime_error("Undefined function call!");
        }
        ctx->cls = func->cls;
        int params = 0;
        if(ctx->funcRParams())
            params = ctx->funcRParams()->exp().size();
        if(func -> params == 0 && ctx->funcRParams() || func->params != 0 && func->params != params){
            std::cout<<"line"<<std::to_string(ctx->getStart()->getLine())<<":"<<std::endl;
            throw std::runtime_error("Too many or too little args!\n");
        }
        if(ctx->funcRParams()){
            int param_cnt = 0;
            for(auto &param:ctx->funcRParams()->exp()){
                auto temp_info = symbol_table.lookup_symbol(param->tmp);
                auto dest = symbol_table.locate_stack_offset(temp_info);
                ircode_gen.add_IRC("a" + std::to_string(param_cnt), OP_LOAD, dest, "NULL", temp_info->cls);
                //not consider too large parameter number
                param_cnt++;
            }
        }
        ircode_gen.add_IRC(func->name, OP_CALL, "NULL", "NULL", func->cls);
        ctx->tmp = ctx->Ident()->getText();
        ctx->type = TYPE_CONST;
        if (func->cls != CLS_VOID)
        {
            std::string tmp = ircode_gen.gen_temp(ctx->getStart()->getLine(), func->cls, symbol_table);
            auto ret_info = symbol_table.lookup_symbol(tmp);
            std::string addr = symbol_table.locate_stack_offset(ret_info);
            ircode_gen.add_IRC("t2", OP_MOVE, "a0", "NULL", ret_info->cls);
            ircode_gen.add_IRC("t2", OP_STORE, addr, "NULL", ret_info->cls);
            ctx->cls = func->cls;
            ctx->tmp = tmp;
        }
    }else{//case:unaryExp ->unaryOp unaryExp
        std::string op = ctx->unaryOp()->getText();
        if(op == "!" && ctx->unaryExp()->cls != CLS_BOOL){
            std::cout<<"line"<<std::to_string(ctx->getStart()->getLine())<<":"<<std::endl;
            throw std::runtime_error("Unmatched type of not operation!\n");
        }
        ctx->cls = ctx->unaryExp()->cls;
        ctx->tmp = ctx->unaryExp()->tmp;
        ctx->type = ctx->unaryExp()->type;
        ctx->elementwise = false;
    }
}

void IRListener::enterPrimaryExp(CACTParser::PrimaryExpContext * ctx){}
void IRListener::exitPrimaryExp(CACTParser::PrimaryExpContext * ctx){
    if(ctx->exp()){
        ctx->cls = ctx->exp()->cls;
        ctx->tmp = ctx->exp()->tmp;
        ctx->type = ctx->exp()->type;
        ctx->elementwise = ctx->exp()->elementwise;
    }else if(ctx->lVal()){
        ctx->cls = ctx->lVal()->cls;
        ctx->tmp = ctx->lVal()->tmp;
        ctx->type = ctx->lVal()->type;
        ctx->elementwise = ctx->lVal()->elementwise;
    }else{//case:primaryExp->number
        ctx->cls = ctx->number()->cls;
        ctx->type = TYPE_CONST;
        ctx->elementwise = false;
        ////added lab3
        int cls = ctx->cls;
        std::string value_string = ctx->getText();
        std::string format_value;
        if(cls == CLS_INT){
            int ival = std::stoi(value_string, 0, getIntStringBase(value_string));
            format_value = std::to_string(ival);
        }
        else if(cls == CLS_BOOL){
            int bval = (value_string == "true") ? 1:0;
            format_value = std::to_string(bval);
        }
        else if(cls == CLS_DOUBLE){
            double dval = std::stod(value_string);
            format_value = std::to_string(dval);
        }
        else{
            float fval = std::stof(value_string.substr(0, value_string.length() - 1));
            format_value = std::to_string(fval);
        }
        std::string tmp = ircode_gen.gen_temp(ctx->getStart()->getLine(), cls, symbol_table);
        ctx->tmp = tmp;
        auto info = symbol_table.lookup_symbol(tmp);
        std::string addr = symbol_table.locate_stack_offset(info);
        ircode_gen.add_IRC("t2", OP_LI, format_value, "NULL", ctx->cls);
        ircode_gen.add_IRC("t2", OP_STORE, symbol_table.locate_stack_offset(info), "NULL", ctx->cls);
        ////added lab3

    }
}

void IRListener::enterNumber(CACTParser::NumberContext * ctx){}
void IRListener::exitNumber(CACTParser::NumberContext * ctx){
    if(ctx->IntConst())
        ctx->cls = CLS_INT;
    else if(ctx->DoubleConst())
        ctx->cls = CLS_DOUBLE;
    else //FloatConst
        ctx->cls = CLS_FLOAT;

}

void IRListener::enterLVal(CACTParser::LValContext * ctx){}
void IRListener::exitLVal(CACTParser::LValContext * ctx){
    auto *symbol = symbol_table.lookup_symbol(ctx->Ident()->getText());
    if(symbol == nullptr){
        std::cout<<"line"<<std::to_string(ctx->getStart()->getLine())<<":"<<std::endl;
        throw std::runtime_error("Undefined variable!\n");
    }
        
    ctx->cls = symbol->cls;
    if(symbol->type == TYPE_ARRAY || symbol->type == TYPE_CONST_ARRAY){
        if(!ctx->exp()){
            ctx->elementwise = true;
            ctx->type = symbol->type;
            ctx->tmp = symbol->name;
        }else{
            ctx->elementwise = false;
            ctx->type = symbol->type;
            // if(ctx->exp()->type != TYPE_CONST && ctx->exp()->type != TYPE_VAR){
            //     std::cout<<"line"<<std::to_string(ctx->getStart()->getLine())<<":"<<std::endl;
            //     throw std::runtime_error("Illegal array index!\n");
            // }
            VarInfo *array = symbol_table.lookup_symbol(ctx->Ident()->getText());
            ctx->cls = array->cls;
            auto idx = ctx->exp()->tmp;
            auto index_info = symbol_table.lookup_symbol(idx);
            auto index_addr = symbol_table.locate_stack_offset(index_info);
            if (index_info->cls != CLS_INT)
                throw std::runtime_error("invalid index at line: " + std::to_string(ctx->getStart()->getLine()));
            std::string arrayelem = ircode_gen.gen_temp(ctx->getStart()->getLine(), ctx->cls, symbol_table);
            //arrayelem=A[b[1]];
            auto array_name = ctx->Ident()->getText();
            auto array_info = symbol_table.lookup_symbol(array_name);
            auto array_addr = symbol_table.locate_stack_offset(array_info);
            auto arrayelem_info = symbol_table.lookup_symbol(arrayelem);
            auto arrayelem_addr = symbol_table.locate_stack_offset(arrayelem_info);
            ircode_gen.add_IRC("t1", OP_LOAD, index_addr, "NULL", CLS_INT);
            ircode_gen.add_IRC("t2", OP_LOAD_ARR, array_addr, "t1", array->cls);
            ircode_gen.add_IRC("t2", OP_STORE, arrayelem_addr, "NULL", array->cls);
            ctx->tmp = arrayelem;
        }
    }else{
        ctx->elementwise = false;
        ctx->tmp = symbol->name;
    }
    ctx->type = symbol->type;
}

void IRListener::enterAssignStmt(CACTParser::AssignStmtContext * ctx){}
void IRListener::exitAssignStmt(CACTParser::AssignStmtContext * ctx){
    std::string name = ctx->lVal()->Ident()->getText();
    auto *var = symbol_table.lookup_symbol(name);
    if(var == nullptr){
        std::cout<<"line"<<std::to_string(ctx->getStart()->getLine())<<":"<<std::endl;
        throw std::runtime_error("Undefined variable\n");
    }
    int var_type = var->type;
    if(var_type == TYPE_CONST || var_type == TYPE_CONST_ARRAY){
        std::cout<<"line"<<std::to_string(ctx->getStart()->getLine())<<":"<<std::endl;
        throw std::runtime_error("\nIllegal assignment to constant\n");
    }
    int rval_cls = ctx->exp()->cls;
    if(var->cls != rval_cls){
        std::cout<<"line"<<std::to_string(ctx->getStart()->getLine())<<":"<<std::endl;
        throw std::runtime_error("\nIllegal assignment between unmatched type\n");
    }
    if(var->type != TYPE_ARRAY && ctx->exp()->elementwise){
        std::cout<<"line"<<std::to_string(ctx->getStart()->getLine())<<":"<<std::endl;
        throw std::runtime_error("\nIllegal assignment between unmatched type\n");
    }else if(ctx->exp()->elementwise){
        auto *array1= symbol_table.lookup_symbol(ctx->exp()->tmp);
        if(array1->value != var->value){
            std::cout<<"line"<<std::to_string(ctx->getStart()->getLine())<<":"<<std::endl;
            throw std::runtime_error("\nIllegal elementwise assignment because of unmatched length\n");
        }
    }
    auto rvar_info = symbol_table.lookup_symbol(ctx->exp()->tmp);

    if(var->type == TYPE_ARRAY && ctx->exp()->elementwise){ // arr = exp
        auto lvar_addr = symbol_table.locate_stack_offset(var);
        auto rvar_addr = symbol_table.locate_stack_offset(rvar_info);
        for (int i = 0; i < var->value; i++)
        {
            ircode_gen.add_IRC("t3", OP_LI, std::to_string(i), "NULL", CLS_INT);
            ircode_gen.add_IRC("t2", OP_LOAD_ARR, rvar_addr, "t3", var->cls);
            ircode_gen.add_IRC("t2", OP_ARR_ASSIGN, lvar_addr, "t3", var->cls);
        }
    }else if(var->type == TYPE_ARRAY && !ctx->exp()->elementwise){ //arr[idx] = exp
        std::string index = ctx->lVal()->exp()->tmp;
        std::string array_addr = symbol_table.locate_stack_offset(var);
        auto index_info = symbol_table.lookup_symbol(index);
        auto index_addr = symbol_table.locate_stack_offset(index_info);
        ircode_gen.add_IRC("t2", OP_LOAD, symbol_table.locate_stack_offset(rvar_info), "NULL", CLS_INT);
        ircode_gen.add_IRC("t4", OP_LOAD, index_addr, "NULL", CLS_INT);
        ircode_gen.add_IRC("t2", OP_ARR_ASSIGN, array_addr, "t4", var->cls);
    }
    else{ // var = exp
        ircode_gen.add_IRC("t2", OP_LOAD, symbol_table.locate_stack_offset(rvar_info), "NULL", var->cls);
        ircode_gen.add_IRC("t2", OP_STORE, symbol_table.locate_stack_offset(var), "NULL", var->cls);
    }

}

void IRListener::enterRelExp(CACTParser::RelExpContext * ctx){}
void IRListener::exitRelExp(CACTParser::RelExpContext * ctx){
    if(ctx->BoolConst()){
        ctx->cls = CLS_BOOL;
        ////added lab3
        std::string value_string = ctx->getText();
        std::string format_value;
        int bval = (value_string == "true") ? 1:0;
        format_value = std::to_string(bval);
        std::string tmp = ircode_gen.gen_temp(ctx->getStart()->getLine(), ctx->cls, symbol_table);
        ctx->tmp = tmp;
        auto info = symbol_table.lookup_symbol(tmp);
        std::string addr = symbol_table.locate_stack_offset(info);
        ircode_gen.add_IRC("t2", OP_LI, format_value, "NULL", ctx->cls);
        ircode_gen.add_IRC("t2", OP_STORE, symbol_table.locate_stack_offset(info), "NULL", ctx->cls);
        ////added lab3
    }
    else if(ctx->relExp()){
        ctx->cls = CLS_BOOL;
        if(ctx->addExp()->elementwise){
            std::cout<<"line"<<std::to_string(ctx->getStart()->getLine())<<":"<<std::endl;
            throw std::runtime_error("\nIllegal elementwise assignment because of unmatched operation\n");
        }
        std::string tmp = ircode_gen.gen_temp(ctx->getStart()->getLine(), ctx->cls , symbol_table);
        auto info = symbol_table.lookup_symbol(tmp);
        std::string addr = symbol_table.locate_stack_offset(info);
        ctx->tmp = tmp;
        auto var1 = symbol_table.lookup_symbol(ctx->relExp()->tmp);
        auto var2 = symbol_table.lookup_symbol(ctx->addExp()->tmp);

        int op;
        if (ctx->op->getType() == CACTLexer::GT) //>
        {
            op = OP_GT;
        }
        else if (ctx->op->getType() == CACTLexer::GE) //>=
        {
            op = OP_GE;
        }
        else if (ctx->op->getType() == CACTLexer::LE) //<=
        {
            op = OP_LE;
        }
        else if (ctx->op->getType() == CACTLexer::LT) //<
        {
            op = OP_LT;
        }
        ircode_gen.add_IRC("t0", OP_LOAD, symbol_table.locate_stack_offset(var1), "NULL", var1->cls);
        ircode_gen.add_IRC("t1", OP_LOAD, symbol_table.locate_stack_offset(var2), "NULL", var2->cls);
        ircode_gen.add_IRC("t2", op, "t0", "t1", var1->cls);
        ircode_gen.add_IRC("t2", OP_STORE, addr, "NULL", CLS_BOOL);
    }else{
        ctx->cls = ctx->addExp()->cls;
        if(ctx->addExp()->elementwise){
            std::cout<<"line"<<std::to_string(ctx->getStart()->getLine())<<":"<<std::endl;
            throw std::runtime_error("\nIllegal elementwise assignment because of unmatched operation\n");
        }
        ctx->tmp = ctx->addExp()->tmp;
    }
}

void IRListener::enterEqExp(CACTParser::EqExpContext * ctx){}
void IRListener::exitEqExp(CACTParser::EqExpContext * ctx){
    if(ctx->eqExp()){
        ctx->cls = CLS_BOOL;
        std::string tmp = ircode_gen.gen_temp(ctx->getStart()->getLine(), ctx->cls , symbol_table);
        auto info = symbol_table.lookup_symbol(tmp);
        std::string addr = symbol_table.locate_stack_offset(info);
        ctx->tmp = tmp;
        auto var1 = symbol_table.lookup_symbol(ctx->eqExp()->tmp);
        auto var2 = symbol_table.lookup_symbol(ctx->relExp()->tmp);

        int op;
        if (ctx->op->getType() == CACTLexer::EQ) //>
        {
            op = OP_EQ;
        }
        else if (ctx->op->getType() == CACTLexer::NE) //>=
        {
            op = OP_NE;
        }
        
        ircode_gen.add_IRC("t0", OP_LOAD, symbol_table.locate_stack_offset(var1), "NULL", var1->cls);
        ircode_gen.add_IRC("t1", OP_LOAD, symbol_table.locate_stack_offset(var2), "NULL", var2->cls);
        ircode_gen.add_IRC("t2", op, "t0", "t1", var1->cls);
        ircode_gen.add_IRC("t2", OP_STORE, addr, "NULL", CLS_BOOL);
    }
    else{
        ctx->tmp = ctx->relExp()->tmp;
        ctx->cls = ctx->relExp()->cls;
    }
}

void IRListener::enterLAndExp(CACTParser::LAndExpContext * ctx){}
void IRListener::exitLAndExp(CACTParser::LAndExpContext * ctx){
    if(ctx->lAndExp()){
        ctx->cls = CLS_BOOL;
        std::string tmp = ircode_gen.gen_temp(ctx->getStart()->getLine(), ctx->cls , symbol_table);
        auto info = symbol_table.lookup_symbol(tmp);
        std::string addr = symbol_table.locate_stack_offset(info);
        ctx->tmp = tmp;
        auto var1 = symbol_table.lookup_symbol(ctx->lAndExp()->tmp);
        auto var2 = symbol_table.lookup_symbol(ctx->eqExp()->tmp);

        int op = OP_AND;
        
        ircode_gen.add_IRC("t0", OP_LOAD, symbol_table.locate_stack_offset(var1), "NULL", var1->cls);
        ircode_gen.add_IRC("t1", OP_LOAD, symbol_table.locate_stack_offset(var2), "NULL", var2->cls);
        ircode_gen.add_IRC("t2", op, "t0", "t1", var1->cls);
        ircode_gen.add_IRC("t2", OP_STORE, addr, "NULL", CLS_BOOL);
    }
    else{
        ctx->cls = ctx->eqExp()->cls;
        ctx->tmp = ctx->eqExp()->tmp;
    }
}

void IRListener::enterLOrExp(CACTParser::LOrExpContext * ctx){}
void IRListener::exitLOrExp(CACTParser::LOrExpContext * ctx){
    if(ctx->lOrExp()){
        ctx->cls = CLS_BOOL;
        std::string tmp = ircode_gen.gen_temp(ctx->getStart()->getLine(), ctx->cls , symbol_table);
        auto info = symbol_table.lookup_symbol(tmp);
        std::string addr = symbol_table.locate_stack_offset(info);
        ctx->tmp = tmp;
        auto var1 = symbol_table.lookup_symbol(ctx->lOrExp()->tmp);
        auto var2 = symbol_table.lookup_symbol(ctx->lAndExp()->tmp);

        int op = OP_OR;
        
        ircode_gen.add_IRC("t0", OP_LOAD, symbol_table.locate_stack_offset(var1), "NULL", var1->cls);
        ircode_gen.add_IRC("t1", OP_LOAD, symbol_table.locate_stack_offset(var2), "NULL", var2->cls);
        ircode_gen.add_IRC("t2", op, "t0", "t1", var1->cls);
        ircode_gen.add_IRC("t2", OP_STORE, addr, "NULL", CLS_BOOL);
    }
    else{
        ctx->cls = ctx->lAndExp()->cls;
        ctx->tmp = ctx->lAndExp()->tmp;
    }
}
    
void IRListener::enterCond(CACTParser::CondContext * ctx){
}
void IRListener::exitCond(CACTParser::CondContext * ctx){
    if(ctx->lOrExp()->cls != CLS_BOOL){
        std::cout<<"line"<<std::to_string(ctx->getStart()->getLine())<<":"<<std::endl;
        throw std::runtime_error("Unmatched type of while-condition!\n");
    }
    ctx->tmp = ctx->lOrExp()->tmp;

}
void IRListener::enterIfCond(CACTParser::IfCondContext * ctx){

}
void IRListener::exitIfCond(CACTParser::IfCondContext * ctx){
    ctx->tmp = ctx->cond()->tmp;
    std::string label = ircode_gen.b_false_list.back();
    auto info = symbol_table.lookup_symbol(ctx->tmp);
    auto addr = symbol_table.locate_stack_offset(info);
    ircode_gen.add_IRC("t2", OP_LOAD, addr, "NULL", CLS_BOOL);
    ircode_gen.add_IRC(label, OP_BEQZ, "t2", "NULL", CLS_VOID); 
}
void IRListener::enterIfStmt(CACTParser::IfStmtContext * ctx){
    std::string b_false = ircode_gen.get_label();
    ircode_gen.b_false_list.push_back(b_false);
    // S.code = cond.code||label(cond.true)||stmt.code||label(cond.false)

}
void IRListener::exitIfStmt(CACTParser::IfStmtContext * ctx){
    std::string label = ircode_gen.b_false_list.back();
    ircode_gen.b_false_list.pop_back();
    ircode_gen.add_IRC(label, OP_LABEL, "NULL", "NULL", CLS_VOID);
}
void IRListener::enterIfElseStmt(CACTParser::IfElseStmtContext * ctx){
    std::string b_false = ircode_gen.get_label();
    std::string b_true = ircode_gen.get_label();
    ircode_gen.b_false_list.push_back(b_false);
    ircode_gen.b_true_list.push_back(b_true);//order : b_false stmt_end

}
void IRListener::exitIfElseStmt(CACTParser::IfElseStmtContext * ctx){
    std::string label = ircode_gen.b_true_list.back();
    ircode_gen.b_true_list.pop_back();
    ircode_gen.add_IRC(label, OP_LABEL, "NULL", "NULL", CLS_VOID);
}

void IRListener::enterElseStmt(CACTParser::ElseStmtContext * ctx){
    // S.code = cond.code||stmt.code||goto cond.false||label(cond.false)||stmt.code||label(cond.true)
    // cond.code include jump inst
    std::string label = ircode_gen.b_true_list.back();
    ircode_gen.add_IRC(label, OP_GOTO, "NULL", "NULL", CLS_VOID);
    label = ircode_gen.b_false_list.back();
    ircode_gen.b_false_list.pop_back();
    ircode_gen.add_IRC(label, OP_LABEL, "NULL", "NULL", CLS_VOID);
}
void IRListener::exitElseStmt(CACTParser::ElseStmtContext * ctx){}

void IRListener::enterWhileCond(CACTParser::WhileCondContext * ctx){}
void IRListener::exitWhileCond(CACTParser::WhileCondContext * ctx){
    ctx->tmp = ctx->cond()->tmp;
    std::string label = ircode_gen.b_false_list.back();
    auto info = symbol_table.lookup_symbol(ctx->tmp);
    auto addr = symbol_table.locate_stack_offset(info);
    ircode_gen.add_IRC("t2", OP_LOAD, addr, "NULL", CLS_BOOL);
    ircode_gen.add_IRC(label, OP_BEQZ, "t2", "NULL", CLS_VOID);
}
void IRListener::enterWhileStmt(CACTParser::WhileStmtContext * ctx){
    std::string b_false = ircode_gen.get_label();
    std::string b_true = ircode_gen.get_label();
    ircode_gen.b_false_list.push_back(b_false);
    ircode_gen.b_true_list.push_back(b_true);//order : b_false stmt_end
    ircode_gen.add_IRC(b_true, OP_LABEL, "NULL", "NULL", CLS_VOID);

}
void IRListener::exitWhileStmt(CACTParser::WhileStmtContext * ctx){
    std::string label = ircode_gen.b_true_list.back();
    ircode_gen.add_IRC(label, OP_GOTO, "NULL", "NULL", CLS_VOID);
    label = ircode_gen.b_false_list.back();
    ircode_gen.b_false_list.pop_back();
    ircode_gen.add_IRC(label, OP_LABEL, "NULL", "NULL", CLS_VOID);
}

void IRListener::enterReturnStmt(CACTParser::ReturnStmtContext * ctx){}
void IRListener::exitReturnStmt(CACTParser::ReturnStmtContext * ctx){
    auto *func = symbol_table.lookup_func(symbol_table.cur_func_name);
    

    if(func->cls == CLS_VOID){
        if(ctx->exp()){
            std::cout<<"line"<<std::to_string(ctx->getStart()->getLine())<<":"<<std::endl;
            throw std::runtime_error("Unmatched return type!\n");
        }
    }else{
        if(ctx->exp() == nullptr || func->cls != ctx->exp()->cls){
            std::cout<<"line"<<std::to_string(ctx->getStart()->getLine())<<":"<<std::endl;
            throw std::runtime_error("Unmatched return type!\n");        
        }
        
        //non-zero ret
        std::string tmp = ctx->exp()->tmp;
        VarInfo *ret = symbol_table.lookup_symbol(tmp);
        std::string dest = symbol_table.locate_stack_offset(ret);
        ircode_gen.add_IRC("a0",OP_LOAD,dest,"NULL",func->cls);
        //ircode_gen.add_IRC("a0",OP_LI,"0","NULL",func->cls);
        //need more consideration, number may not be zero
        
    }
    ircode_gen.add_IRC(func->name,FUNC_END,"NULL","NULL",func->cls);
}

