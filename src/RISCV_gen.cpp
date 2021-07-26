#include "semanticAnalysis.h"

void IRListener::RISCV_gen(std::string input_file_name){
    std::string name;
    name = ".file   \"" + input_file_name + ".cact\"";
    riscv_codes.push_back(name);
    riscv_codes.push_back(".option nopic");
    riscv_codes.push_back(".attribute arch, \"rv64i2p0_m2p0_a2p0_f2p0_d2p0_c2p0\"");
    //RV64GC
    riscv_codes.push_back(".attribute unaligned_access, 0");
    riscv_codes.push_back(".attribute stack_align, 16");

    //text section
    riscv_codes.push_back("");
    riscv_codes.push_back(".text");

    rodata.push_back(".section .rodata");
    for(auto ir_code:ircode_gen.IR_codes){
        switch(ir_code.opcode){
            case FUNC_BEGIN:
                FUNC_BEGIN_method(&ir_code);
                break;
            case FUNC_END:
                FUNC_END_method(&ir_code);
                break;
            case OP_LI:
                LI_method(&ir_code);
                break;
            case OP_LOAD:
                LOAD_method(&ir_code);
                break;
            case OP_STORE:
                STORE_method(&ir_code);
                break;
            case OP_CALL: 
                CALL_method(&ir_code);
                break;
            case OP_MOVE:
                MOVE_method(&ir_code);
                break;
            case OP_ADD:
                ADD_method(&ir_code);
                break;
            case OP_SUB:
                SUB_method(&ir_code);
                break;
            case OP_MUL:
                MUL_method(&ir_code);
                break;
            case OP_DIV:
                DIV_method(&ir_code);
                break;
            case OP_MOD:
                MOD_method(&ir_code);
                break;
            case OP_LABEL:
                LABEL_method(&ir_code);
                break;
            case OP_LT:
                LT_method(&ir_code);
                break;
            case OP_LE:
                LE_method(&ir_code);
                break;
            case OP_GT:
                GT_method(&ir_code);
                break;
            case OP_GE:
                GE_method(&ir_code);
                break;
            case OP_EQ:
                EQ_method(&ir_code);
                break;
            case OP_NE:
                NE_method(&ir_code);
                break;
            case OP_AND:
                AND_method(&ir_code);
                break;
            case OP_OR:
                OR_method(&ir_code);
                break;
            case OP_BEQZ:
                BEQZ_method(&ir_code);
                break;
            case OP_GOTO:
                GOTO_method(&ir_code);
                break;
            case OP_G_ASSIGN:
                G_ASSIGN_method(&ir_code);
                break;
            case OP_G_ARR_DECL:
                G_ARR_DECL_method(&ir_code);
                break;
            case OP_G_ARR_ASSIGN:
                G_ARR_ASSIGN_method(&ir_code);
                break;
            case OP_ARR_ASSIGN:
                ARR_ASSIGN_method(&ir_code);
                break;
            case OP_LOAD_ARR:
                LOAD_ARR_method(&ir_code);
                break;
            default:
                //riscv_codes.push_back("ERROR!"+std::to_string(ir_code.opcode));
                break;
        }
        std::ofstream out("./out/" + input_file_name + ".s", std::ios::out|std::ios::trunc);
        for (auto &ins : riscv_codes)
        {
            if (ins.find(':') == -1)
            {
                out << '\t';
            }
            out << ins << std::endl;
        }
        for (auto &ins : rodata)
        {
            if (ins.find(':') == -1)
            {
                out << '\t';
            }
            out << ins << std::endl;

        }
        out.close();
    }
}

void IRListener::FUNC_BEGIN_method(IRcode * ir_code){
    std::string func_name = ir_code->result;
    auto func_info = symbol_table.lookup_func(func_name);
    
    riscv_codes.push_back(".text");
    riscv_codes.push_back(".align   1");
    riscv_codes.push_back(".globl   " + func_name);
    riscv_codes.push_back(".type    " + func_name + ", @function");
    riscv_codes.push_back(func_name + ":");

    int size = func_info->frame_len;
    riscv_codes.push_back("#frame size:" + std::to_string(size));
    riscv_codes.push_back("addi    sp,sp,-" + std::to_string(size));
    riscv_codes.push_back("sd      ra," + std::to_string(size - 8) + "(sp)");
    riscv_codes.push_back("sd      s0," + std::to_string(size - 16) + "(sp)");
    riscv_codes.push_back("addi    s0,sp," + std::to_string(size));

}

void IRListener::FUNC_END_method(IRcode * ir_code){
    std::string func_name = ir_code->result;
    auto func_info = symbol_table.lookup_func(func_name);
    int size = func_info->frame_len;
    riscv_codes.push_back("ld      ra," + std::to_string(size - 8) + "(sp)");
    riscv_codes.push_back("ld      s0," + std::to_string(size - 16) + "(sp)");
    riscv_codes.push_back("addi    sp,sp," + std::to_string(size));
    riscv_codes.push_back("jr ra");
    riscv_codes.push_back(".size   "+func_name+",.-"+func_name);
    
}
void IRListener::CALL_method(IRcode * ir_code){
    riscv_codes.push_back("call     " + ir_code->result);
    riscv_codes.push_back("nop");
}
void IRListener::LABEL_method(IRcode *ir_code){
    riscv_codes.push_back(ir_code->result+":");
}

void IRListener::BEQZ_method(IRcode *ir_code){
    riscv_codes.push_back("beqz   " + ir_code->arg1 + "," + ir_code->result);
}

void IRListener::GOTO_method(IRcode *ir_code){
    riscv_codes.push_back("j      " + ir_code->result);
}

void IRListener::STORE_method(IRcode * ir_code){
    if (ir_code->cls == CLS_INT || ir_code->cls == CLS_BOOL)
    {
        riscv_codes.push_back("sw   " + ir_code->result + ", " + ir_code->arg1);
    }
    else if (ir_code->cls == CLS_FLOAT)
    {
        riscv_codes.push_back("fsw   f" + ir_code->result + ", " + ir_code->arg1);
    }
    else if (ir_code->cls == CLS_DOUBLE)
    {
        riscv_codes.push_back("fsd   f" + ir_code->result + ", " + ir_code->arg1);
    }
}
void IRListener::LOAD_method(IRcode * ir_code){
    auto name = ir_code->arg1;
    auto postfix = name.substr(name.size() - 2, 2);
    if (postfix == ".G") //global
    {
        name.pop_back();
        name.pop_back();
        riscv_codes.push_back("lui   " + ir_code->result + ",%hi(" + name + ")");
        if (ir_code->cls == CLS_INT || ir_code->cls == CLS_BOOL)
        {
            riscv_codes.push_back("lw   " + ir_code->result + ",%lo(" + name + ")(" + ir_code->result + ")");
        }
        else if (ir_code->cls == CLS_FLOAT)
        {
            riscv_codes.push_back("flw   f" + ir_code->result + ",%lo(" + name + ")(" + ir_code->result + ")");
        }
        else
        {
            riscv_codes.push_back("fld   f" + ir_code->result + ",%lo(" + name + ")(" + ir_code->result + ")");
        }
        return;
    }
    if (ir_code->cls == CLS_INT || ir_code->cls == CLS_BOOL)
    {
        riscv_codes.push_back("lw   " + ir_code->result + ", " + ir_code->arg1);
    }
    else if (ir_code->cls == CLS_FLOAT)
    {
        riscv_codes.push_back("flw   f" + ir_code->result + ", " + ir_code->arg1);
    }
    else if (ir_code->cls == CLS_DOUBLE)
    {
        riscv_codes.push_back("fld   f" + ir_code->result + ", " + ir_code->arg1);
    }
}
void IRListener::MOVE_method(IRcode * ir_code){
    if (ir_code->cls == CLS_INT || ir_code->cls == CLS_BOOL)
    {
        riscv_codes.push_back("mv   " + ir_code->result + "," + ir_code->arg1);
    }
    else if (ir_code->cls == CLS_FLOAT)
    {
        riscv_codes.push_back("fmv.s   f" + ir_code->result + ",f" + ir_code->arg1);
    }
    else if (ir_code->cls == CLS_DOUBLE)
    {
        riscv_codes.push_back("fmv.d   f" + ir_code->result + ",f" + ir_code->arg1);
    }
}

void IRListener::ADD_method(IRcode * ir_code){
    if (ir_code->cls == CLS_INT || ir_code->cls == CLS_BOOL)
    {
        riscv_codes.push_back("addw   " + ir_code->result + "," + ir_code->arg1+","+ir_code->arg2);
    }
    else if (ir_code->cls == CLS_FLOAT)
    {
        riscv_codes.push_back("fadd.s   f" + ir_code->result + ",f" + ir_code->arg1+",f"+ir_code->arg2);
    }
    else if (ir_code->cls == CLS_DOUBLE)
    {
        riscv_codes.push_back("fadd.d   f" + ir_code->result + ",f" + ir_code->arg1+",f"+ir_code->arg2);
    }
}

void IRListener::SUB_method(IRcode * ir_code){
    if (ir_code->cls == CLS_INT || ir_code->cls == CLS_BOOL)
    {
        riscv_codes.push_back("subw   " + ir_code->result + "," + ir_code->arg1+","+ir_code->arg2);
    }
    else if (ir_code->cls == CLS_FLOAT)
    {
        riscv_codes.push_back("fsub.s   f" + ir_code->result + ",f" + ir_code->arg1+",f"+ir_code->arg2);
    }
    else if (ir_code->cls == CLS_DOUBLE)
    {
        riscv_codes.push_back("fsub.d   f" + ir_code->result + ",f" + ir_code->arg1+",f"+ir_code->arg2);
    }
}
void IRListener::MUL_method(IRcode * ir_code){
    if (ir_code->cls == CLS_INT || ir_code->cls == CLS_BOOL)
    {
        riscv_codes.push_back("mulw   " + ir_code->result + "," + ir_code->arg1+","+ir_code->arg2);
    }
    else if (ir_code->cls == CLS_FLOAT)
    {
        riscv_codes.push_back("fmul.s   f" + ir_code->result + ",f" + ir_code->arg1+",f"+ir_code->arg2);
    }
    else if (ir_code->cls == CLS_DOUBLE)
    {
        riscv_codes.push_back("fmul.d   f" + ir_code->result + ",f" + ir_code->arg1+",f"+ir_code->arg2);
    }
}
void IRListener::DIV_method(IRcode * ir_code){
    if (ir_code->cls == CLS_INT || ir_code->cls == CLS_BOOL)
    {
        riscv_codes.push_back("divw   " + ir_code->result + "," + ir_code->arg1+","+ir_code->arg2);
    }
    else if (ir_code->cls == CLS_FLOAT)
    {
        riscv_codes.push_back("fdiv.s   f" + ir_code->result + ",f" + ir_code->arg1+",f"+ir_code->arg2);
    }
    else if (ir_code->cls == CLS_DOUBLE)
    {
        riscv_codes.push_back("fdiv.d   f" + ir_code->result + ",f" + ir_code->arg1+",f"+ir_code->arg2);
    }
}
void IRListener::MOD_method(IRcode * ir_code){
    if (ir_code->cls == CLS_INT || ir_code->cls == CLS_BOOL)
    {
        riscv_codes.push_back("rem   " + ir_code->result + "," + ir_code->arg1+","+ir_code->arg2);
    }
    
}
void IRListener::LI_method(IRcode * ir_code){
    if (ir_code->cls == CLS_INT || ir_code->cls == CLS_BOOL)
    {
        riscv_codes.push_back("li   " + ir_code->result + ", " + ir_code->arg1);
    }
    else if (ir_code->cls == CLS_FLOAT)
    {
        riscv_codes.push_back("lui  a5,%hi(.LC" + std::to_string(float_tmp_cnt) + ")");
        riscv_codes.push_back("flw  f" + ir_code->result + ",%lo(.LC" + std::to_string(float_tmp_cnt) + ")(a5)");
        float fval = std::stof(ir_code->arg1);
        int decimal_fval = *(int *)&fval;

        rodata.push_back(".align  2");
        rodata.push_back(".LC" + std::to_string(float_tmp_cnt) + ":");
        rodata.push_back(".word    " + std::to_string(decimal_fval));
        float_tmp_cnt++;
    }
    else //double
    {
        riscv_codes.push_back("lui  a5,%hi(.LC" + std::to_string(float_tmp_cnt) + ")");
        riscv_codes.push_back("fld  f" + ir_code->result + ",%lo(.LC" + std::to_string(float_tmp_cnt) + ")(a5)");
        double dval = std::stod(ir_code->arg1);
        long decimal_dval = *(long *)&dval;
        int hi = decimal_dval >> 32;
        int lo = decimal_dval & 0x00000000ffffffff;

        rodata.push_back(".align  3");
        rodata.push_back(".LC" + std::to_string(float_tmp_cnt) + ":");
        rodata.push_back(".word    " + std::to_string(lo));
        rodata.push_back(".word    " + std::to_string(hi));
        float_tmp_cnt++;
    }
}
// compare method
void IRListener::LT_method(IRcode *ir_code){
    if (ir_code->cls == CLS_INT || ir_code->cls == CLS_BOOL)
    {
        riscv_codes.push_back("slt   " + ir_code->result + "," + ir_code->arg1+","+ir_code->arg2);
    }
    else if (ir_code->cls == CLS_FLOAT)
    {
        riscv_codes.push_back("flt.s   " + ir_code->result + ",f" + ir_code->arg1+",f"+ir_code->arg2);
    }
    else if (ir_code->cls == CLS_DOUBLE)
    {
        riscv_codes.push_back("flt.d   " + ir_code->result + ",f" + ir_code->arg1+",f"+ir_code->arg2);
    }
}
void IRListener::GE_method(IRcode *ir_code){
    if (ir_code->cls == CLS_INT || ir_code->cls == CLS_BOOL)
    {
        riscv_codes.push_back("slt   " + ir_code->result + "," + ir_code->arg1+","+ir_code->arg2);
        riscv_codes.push_back("not   " + ir_code->result + "," + ir_code->result);
        riscv_codes.push_back("andi   " + ir_code->result + "," + ir_code->result+",1");   
    }
    else if (ir_code->cls == CLS_FLOAT)
    {
        riscv_codes.push_back("flt.s   " + ir_code->result + ",f" + ir_code->arg1+",f"+ir_code->arg2);
        riscv_codes.push_back("not     " + ir_code->result + "," + ir_code->result);
        riscv_codes.push_back("andi    " + ir_code->result + "," + ir_code->result+",1");
    }
    else if (ir_code->cls == CLS_DOUBLE)
    {
        riscv_codes.push_back("flt.d   " + ir_code->result + ",f" + ir_code->arg1+",f"+ir_code->arg2);
        riscv_codes.push_back("not     " + ir_code->result + "," + ir_code->result);
        riscv_codes.push_back("andi    " + ir_code->result + "," + ir_code->result+",1");
    }
}

void IRListener::GT_method(IRcode *ir_code){
    if (ir_code->cls == CLS_INT || ir_code->cls == CLS_BOOL)
    {
        riscv_codes.push_back("slt   " + ir_code->result + "," + ir_code->arg2 +","+ir_code->arg1);
    }
    else if (ir_code->cls == CLS_FLOAT)
    {
        riscv_codes.push_back("flt.s   " + ir_code->result + ",f" + ir_code->arg2+",f"+ir_code->arg1);
    }
    else if (ir_code->cls == CLS_DOUBLE)
    {
        riscv_codes.push_back("flt.d   " + ir_code->result + ",f" + ir_code->arg2+",f"+ir_code->arg1);
    }
}

void IRListener::LE_method(IRcode *ir_code){
    if (ir_code->cls == CLS_INT || ir_code->cls == CLS_BOOL)
    {
        riscv_codes.push_back("slt   " + ir_code->result + "," + ir_code->arg2+","+ir_code->arg1);
        riscv_codes.push_back("not   " + ir_code->result + "," + ir_code->result);
        riscv_codes.push_back("andi   " + ir_code->result + "," + ir_code->result+",1");   
    }
    else if (ir_code->cls == CLS_FLOAT)
    {
        riscv_codes.push_back("flt.s   " + ir_code->result + ",f" + ir_code->arg2+",f"+ir_code->arg1);
        riscv_codes.push_back("not   " + ir_code->result + "," + ir_code->result);
        riscv_codes.push_back("andi   " + ir_code->result + "," + ir_code->result+",1");   
    }
    else if (ir_code->cls == CLS_DOUBLE)
    {
        riscv_codes.push_back("flt.d   " + ir_code->result + ",f" + ir_code->arg2+",f"+ir_code->arg1);
        riscv_codes.push_back("not   " + ir_code->result + "," + ir_code->result);
        riscv_codes.push_back("andi   " + ir_code->result + "," + ir_code->result+",1");   
    }
}


void IRListener::EQ_method(IRcode *ir_code){
    if (ir_code->cls == CLS_INT || ir_code->cls == CLS_BOOL)
    {
        riscv_codes.push_back("subw   " + ir_code->result + "," + ir_code->arg1+","+ir_code->arg2);
        riscv_codes.push_back("sltu   " + ir_code->result + ",zero,"+ir_code->result);
        riscv_codes.push_back("not   " + ir_code->result + "," + ir_code->result);
        riscv_codes.push_back("andi   " + ir_code->result + "," + ir_code->result+",1");
    }
    else if (ir_code->cls == CLS_FLOAT)
    {
        riscv_codes.push_back("feq.s   " + ir_code->result + ",f" + ir_code->arg1+",f"+ir_code->arg2);
        
    }
    else if (ir_code->cls == CLS_DOUBLE)
    {
        riscv_codes.push_back("feq.d   " + ir_code->result + ",f" + ir_code->arg1+",f"+ir_code->arg2);
    }
}
void IRListener::NE_method(IRcode *ir_code){
    if (ir_code->cls == CLS_INT || ir_code->cls == CLS_BOOL)
    {
        riscv_codes.push_back("subw     " + ir_code->result + "," + ir_code->arg1+","+ir_code->arg2);
        riscv_codes.push_back("sltu   " + ir_code->result + ",zero,"+ir_code->result);
        
    }
    else if (ir_code->cls == CLS_FLOAT)
    {
        riscv_codes.push_back("feq.s   " + ir_code->result + ",f" + ir_code->arg1+",f"+ir_code->arg2);
        riscv_codes.push_back("not   " + ir_code->result + "," + ir_code->result);
        riscv_codes.push_back("andi   " + ir_code->result + "," + ir_code->result+",1");
    }
    else if (ir_code->cls == CLS_DOUBLE)
    {
        riscv_codes.push_back("feq.d   " + ir_code->result + ",f" + ir_code->arg1+",f"+ir_code->arg2);
        riscv_codes.push_back("not   " + ir_code->result + "," + ir_code->result);
        riscv_codes.push_back("andi   " + ir_code->result + "," + ir_code->result+",1");
    }
}
void IRListener::AND_method(IRcode *ir_code){
    if (ir_code->cls == CLS_INT || ir_code->cls == CLS_BOOL)
    {
        riscv_codes.push_back("and   " + ir_code->result + "," + ir_code->arg1+","+ir_code->arg2);
    }
}
void IRListener::OR_method(IRcode *ir_code){
    if (ir_code->cls == CLS_INT || ir_code->cls == CLS_BOOL)
    {
        riscv_codes.push_back("or   " + ir_code->result + "," + ir_code->arg1+","+ir_code->arg2);
    }
}

void IRListener::G_ASSIGN_method(IRcode *ir_code){
    auto name = ir_code->result;
    auto cls = ir_code->cls;
    std::string section = (ir_code->arg2 == "const") ? ".section     .srodata,\"a\"" 
                : (ir_code->arg2 == "uninited") ? ".bss" 
                : ".section     .sdata,\"aw\"";
    std::string align = (ir_code->cls == CLS_DOUBLE) ? ".align   3" : ".align  2";
    int size = (cls == CLS_DOUBLE) ? 8 : 4;

    riscv_codes.push_back(".globl   " + name);
    riscv_codes.push_back(section);
    riscv_codes.push_back(align);
    riscv_codes.push_back(".type    " + name + ", @object");
    riscv_codes.push_back(".size    " + name + ", " + std::to_string(size));
    riscv_codes.push_back(name + ":");
    if (ir_code->arg2 == "uninited")
    {
        riscv_codes.push_back(".zero    " + std::to_string(size));
    }
    else
    {
        if (cls == CLS_INT || cls == CLS_BOOL)
        {
            riscv_codes.push_back(".word    " + ir_code->arg1);
        }
        else if (cls == CLS_FLOAT)
        {
            //如何float转10进制的IEEE 754表示
            auto floatvalue = std::stof(ir_code->arg1);
            int decimal_fval = *(int *)&floatvalue;
            riscv_codes.push_back(".word    " + std::to_string(decimal_fval));
        }
        else //double
        {
            auto dvalue = std::stod(ir_code->arg1);
            long decimal_dval = *(long *)&dvalue;
            int hi = (decimal_dval >> 32);
            int lo = decimal_dval & (long)0x00000000ffffffff;
            riscv_codes.push_back(".word    " + std::to_string(lo));
            riscv_codes.push_back(".word    " + std::to_string(hi));
        }
    }
}
void IRListener::G_ARR_ASSIGN_method(IRcode *ir_code){
    auto cls = ir_code->cls;
    if (cls == CLS_INT || cls == CLS_BOOL)
    {
        riscv_codes.push_back(".word    " + ir_code->arg2);
    }
    else if (cls == CLS_FLOAT)
    {
        //如何float转10进制的IEEE 754表示
        auto floatvalue = std::stof(ir_code->arg2);
        int decimal_fval = *(int *)&floatvalue;
        riscv_codes.push_back(".word    " + std::to_string(decimal_fval));
    }
    else //double
    {
        auto dvalue = std::stod(ir_code->arg2);
        long decimal_dval = *(long *)&dvalue;
        int hi = (decimal_dval >> 32);
        int lo = decimal_dval & (long)0x00000000ffffffff;
        riscv_codes.push_back(".word    " + std::to_string(lo));
        riscv_codes.push_back(".word    " + std::to_string(hi));
    }

}
void IRListener::G_ARR_DECL_method(IRcode *ir_code){
    auto name = ir_code->result;
    auto cls = ir_code->cls;
    int length = std::stoi(ir_code->arg1);
    std::string section = (ir_code->arg2 == "const") ? ".section     .srodata,\"a\"" 
                        : (ir_code->arg2 == "uninited") ? ".bss" 
                        : (cls == CLS_DOUBLE || cls == CLS_FLOAT) ? ".section     .sdata,\"aw\"" 
                        : ".data";
    std::string align = ".align   3";
    int size = (cls == CLS_DOUBLE) ? 8 * length : 4 * length;

    riscv_codes.push_back(".globl   " + name);
    riscv_codes.push_back(section);
    riscv_codes.push_back(align);
    riscv_codes.push_back(".type    " + name + ", @object");
    riscv_codes.push_back(".size    " + name + ", " + std::to_string(size));
    riscv_codes.push_back(name + ":");
    if (ir_code->arg2 == "uninited")
    {
        riscv_codes.push_back(".zero    " + std::to_string(size));
    }
}
void IRListener::ARR_ASSIGN_method(IRcode *ir_code){
    int cls = ir_code->cls;
    auto name = ir_code->arg1;
    auto postfix = name.substr(name.size() - 2, 2);
    int size = (cls == CLS_DOUBLE)? 3:2;
    if (postfix == ".G") //global
    {
        name.pop_back();
        name.pop_back();
        riscv_codes.push_back("mv   t5," + ir_code->arg2);
        riscv_codes.push_back("slliw    t5,t5,"+std::to_string(size));
        riscv_codes.push_back("lui  s2,%hi(" + name + ")");
        riscv_codes.push_back("addi s2,s2,%lo(" + name + ")"); //base
        riscv_codes.push_back("add s3,s2,t5");                 //base+offset
        if (cls == CLS_INT || cls == CLS_BOOL)
        {
            riscv_codes.push_back("sw   " + ir_code->result + ",0(s3)");
        }
        else if (cls == CLS_FLOAT)
        {
            riscv_codes.push_back("fsw   f" + ir_code->result + ",0(s3)");
        }
        else
        {
            riscv_codes.push_back("fsd   f" + ir_code->result + ",0(s3)");
        }
    }else
    {
        riscv_codes.push_back("mv   t5," + ir_code->arg2);
        riscv_codes.push_back("slliw    t5,t5,"+std::to_string(size));
        riscv_codes.push_back("sub  s2,s0,t5");
        std::string old;
        if (cls == CLS_INT || cls == CLS_BOOL)
        {
            old = "sw     " + ir_code->result + "," + ir_code->arg1;      
        }
        else if (cls == CLS_FLOAT)
        {
            old = "fsw     f" + ir_code->result + "," + ir_code->arg1;
        }
        else if (cls == CLS_DOUBLE)
        {
            old = "fsd     f" + ir_code->result + "," + ir_code->arg1;
        }
        std::string new_str = old.substr(0,old.size() - 2);
        riscv_codes.push_back(new_str+"2)");
    }
}

void IRListener::LOAD_ARR_method(IRcode *ir_code)
{
    int cls = ir_code->cls;
    auto name = ir_code->arg1;
    auto postfix = name.substr(name.size() - 2, 2);
    int size = (cls == CLS_DOUBLE)?3:2;
    if (postfix == ".G") //global
    {
        name.pop_back();
        name.pop_back();
        riscv_codes.push_back("mv   t5," + ir_code->arg2);
        riscv_codes.push_back("slliw    t5,t5,"+std::to_string(size));
        riscv_codes.push_back("lui  s2,%hi(" + name + ")");
        riscv_codes.push_back("addi s2,s2,%lo(" + name + ")"); //base
        riscv_codes.push_back("add s3,s2,t5");                 //base+offset
        if (cls == CLS_INT || cls == CLS_BOOL)
        {
            riscv_codes.push_back("lw   " + ir_code->result + ",0(s3)");
        }
        else if (cls == CLS_FLOAT)
        {
            riscv_codes.push_back("flw   f" + ir_code->result + ",0(s3)");
        }
        else
        {
            riscv_codes.push_back("fld   f" + ir_code->result + ",0(s3)");
        }
    }
    else
    {   
        riscv_codes.push_back("mv   t5," + ir_code->arg2);
        riscv_codes.push_back("slliw    t5,t5,"+std::to_string(size));
        riscv_codes.push_back("sub  s2,s0,t5");
        std::string old1;
        if (cls == CLS_INT || cls == CLS_BOOL)
        {
            old1 = "lw     " + ir_code->result + "," + ir_code->arg1;
        }
        else if (cls == CLS_FLOAT)
        {
            old1 = "flw     f" + ir_code->result + "," + ir_code->arg1;
        }
        else
        {
            old1 = "fld     f" + ir_code->result + "," + ir_code->arg1;
        }
        std::string new_str = old1.substr(0,old1.size() - 2);
        riscv_codes.push_back(new_str+"2)");
    }
}
