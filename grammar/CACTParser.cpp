
    #include <vector>
    #include <string>


// Generated from ./grammar/CACT.g4 by ANTLR 4.8


#include "CACTListener.h"

#include "CACTParser.h"


using namespace antlrcpp;
using namespace antlr4;

CACTParser::CACTParser(TokenStream *input) : Parser(input) {
  _interpreter = new atn::ParserATNSimulator(this, _atn, _decisionToDFA, _sharedContextCache);
}

CACTParser::~CACTParser() {
  delete _interpreter;
}

std::string CACTParser::getGrammarFileName() const {
  return "CACT.g4";
}

const std::vector<std::string>& CACTParser::getRuleNames() const {
  return _ruleNames;
}

dfa::Vocabulary& CACTParser::getVocabulary() const {
  return _vocabulary;
}


//----------------- CompUnitContext ------------------------------------------------------------------

CACTParser::CompUnitContext::CompUnitContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CACTParser::CompUnitContext::EOF() {
  return getToken(CACTParser::EOF, 0);
}

CACTParser::TransUnitContext* CACTParser::CompUnitContext::transUnit() {
  return getRuleContext<CACTParser::TransUnitContext>(0);
}


size_t CACTParser::CompUnitContext::getRuleIndex() const {
  return CACTParser::RuleCompUnit;
}

void CACTParser::CompUnitContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCompUnit(this);
}

void CACTParser::CompUnitContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCompUnit(this);
}

CACTParser::CompUnitContext* CACTParser::compUnit() {
  CompUnitContext *_localctx = _tracker.createInstance<CompUnitContext>(_ctx, getState());
  enterRule(_localctx, 0, CACTParser::RuleCompUnit);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(73);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << CACTParser::T__0)
      | (1ULL << CACTParser::T__3)
      | (1ULL << CACTParser::T__4)
      | (1ULL << CACTParser::T__5)
      | (1ULL << CACTParser::T__6)
      | (1ULL << CACTParser::T__14))) != 0)) {
      setState(72);
      transUnit();
    }
    setState(75);
    match(CACTParser::EOF);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TransUnitContext ------------------------------------------------------------------

CACTParser::TransUnitContext::TransUnitContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<CACTParser::DeclContext *> CACTParser::TransUnitContext::decl() {
  return getRuleContexts<CACTParser::DeclContext>();
}

CACTParser::DeclContext* CACTParser::TransUnitContext::decl(size_t i) {
  return getRuleContext<CACTParser::DeclContext>(i);
}

std::vector<CACTParser::FuncDefContext *> CACTParser::TransUnitContext::funcDef() {
  return getRuleContexts<CACTParser::FuncDefContext>();
}

CACTParser::FuncDefContext* CACTParser::TransUnitContext::funcDef(size_t i) {
  return getRuleContext<CACTParser::FuncDefContext>(i);
}


size_t CACTParser::TransUnitContext::getRuleIndex() const {
  return CACTParser::RuleTransUnit;
}

void CACTParser::TransUnitContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTransUnit(this);
}

void CACTParser::TransUnitContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTransUnit(this);
}

CACTParser::TransUnitContext* CACTParser::transUnit() {
  TransUnitContext *_localctx = _tracker.createInstance<TransUnitContext>(_ctx, getState());
  enterRule(_localctx, 2, CACTParser::RuleTransUnit);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(79); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(79);
      _errHandler->sync(this);
      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 1, _ctx)) {
      case 1: {
        setState(77);
        decl();
        break;
      }

      case 2: {
        setState(78);
        funcDef();
        break;
      }

      }
      setState(81); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << CACTParser::T__0)
      | (1ULL << CACTParser::T__3)
      | (1ULL << CACTParser::T__4)
      | (1ULL << CACTParser::T__5)
      | (1ULL << CACTParser::T__6)
      | (1ULL << CACTParser::T__14))) != 0));
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DeclContext ------------------------------------------------------------------

CACTParser::DeclContext::DeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CACTParser::ConstDeclContext* CACTParser::DeclContext::constDecl() {
  return getRuleContext<CACTParser::ConstDeclContext>(0);
}

CACTParser::VarDeclContext* CACTParser::DeclContext::varDecl() {
  return getRuleContext<CACTParser::VarDeclContext>(0);
}


size_t CACTParser::DeclContext::getRuleIndex() const {
  return CACTParser::RuleDecl;
}

void CACTParser::DeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDecl(this);
}

void CACTParser::DeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDecl(this);
}

CACTParser::DeclContext* CACTParser::decl() {
  DeclContext *_localctx = _tracker.createInstance<DeclContext>(_ctx, getState());
  enterRule(_localctx, 4, CACTParser::RuleDecl);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(85);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case CACTParser::T__0: {
        enterOuterAlt(_localctx, 1);
        setState(83);
        constDecl();
        break;
      }

      case CACTParser::T__3:
      case CACTParser::T__4:
      case CACTParser::T__5:
      case CACTParser::T__6: {
        enterOuterAlt(_localctx, 2);
        setState(84);
        varDecl();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ConstDeclContext ------------------------------------------------------------------

CACTParser::ConstDeclContext::ConstDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CACTParser::BTypeContext* CACTParser::ConstDeclContext::bType() {
  return getRuleContext<CACTParser::BTypeContext>(0);
}

std::vector<CACTParser::ConstDefContext *> CACTParser::ConstDeclContext::constDef() {
  return getRuleContexts<CACTParser::ConstDefContext>();
}

CACTParser::ConstDefContext* CACTParser::ConstDeclContext::constDef(size_t i) {
  return getRuleContext<CACTParser::ConstDefContext>(i);
}


size_t CACTParser::ConstDeclContext::getRuleIndex() const {
  return CACTParser::RuleConstDecl;
}

void CACTParser::ConstDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterConstDecl(this);
}

void CACTParser::ConstDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitConstDecl(this);
}

CACTParser::ConstDeclContext* CACTParser::constDecl() {
  ConstDeclContext *_localctx = _tracker.createInstance<ConstDeclContext>(_ctx, getState());
  enterRule(_localctx, 6, CACTParser::RuleConstDecl);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(87);
    match(CACTParser::T__0);
    setState(88);
    bType();
    setState(89);
    constDef();
    setState(94);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == CACTParser::T__1) {
      setState(90);
      match(CACTParser::T__1);
      setState(91);
      constDef();
      setState(96);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(97);
    match(CACTParser::T__2);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BTypeContext ------------------------------------------------------------------

CACTParser::BTypeContext::BTypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t CACTParser::BTypeContext::getRuleIndex() const {
  return CACTParser::RuleBType;
}

void CACTParser::BTypeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBType(this);
}

void CACTParser::BTypeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBType(this);
}

CACTParser::BTypeContext* CACTParser::bType() {
  BTypeContext *_localctx = _tracker.createInstance<BTypeContext>(_ctx, getState());
  enterRule(_localctx, 8, CACTParser::RuleBType);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(99);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << CACTParser::T__3)
      | (1ULL << CACTParser::T__4)
      | (1ULL << CACTParser::T__5)
      | (1ULL << CACTParser::T__6))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ArraySymbolContext ------------------------------------------------------------------

CACTParser::ArraySymbolContext::ArraySymbolContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CACTParser::ArraySymbolContext::IntConst() {
  return getToken(CACTParser::IntConst, 0);
}


size_t CACTParser::ArraySymbolContext::getRuleIndex() const {
  return CACTParser::RuleArraySymbol;
}

void CACTParser::ArraySymbolContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterArraySymbol(this);
}

void CACTParser::ArraySymbolContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitArraySymbol(this);
}

CACTParser::ArraySymbolContext* CACTParser::arraySymbol() {
  ArraySymbolContext *_localctx = _tracker.createInstance<ArraySymbolContext>(_ctx, getState());
  enterRule(_localctx, 10, CACTParser::RuleArraySymbol);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(101);
    match(CACTParser::T__7);
    setState(103);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == CACTParser::IntConst) {
      setState(102);
      match(CACTParser::IntConst);
    }
    setState(105);
    match(CACTParser::T__8);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ConstDefContext ------------------------------------------------------------------

CACTParser::ConstDefContext::ConstDefContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CACTParser::ConstDefContext::Ident() {
  return getToken(CACTParser::Ident, 0);
}

CACTParser::ConstInitValContext* CACTParser::ConstDefContext::constInitVal() {
  return getRuleContext<CACTParser::ConstInitValContext>(0);
}

CACTParser::ArraySymbolContext* CACTParser::ConstDefContext::arraySymbol() {
  return getRuleContext<CACTParser::ArraySymbolContext>(0);
}


size_t CACTParser::ConstDefContext::getRuleIndex() const {
  return CACTParser::RuleConstDef;
}

void CACTParser::ConstDefContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterConstDef(this);
}

void CACTParser::ConstDefContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitConstDef(this);
}

CACTParser::ConstDefContext* CACTParser::constDef() {
  ConstDefContext *_localctx = _tracker.createInstance<ConstDefContext>(_ctx, getState());
  enterRule(_localctx, 12, CACTParser::RuleConstDef);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(107);
    match(CACTParser::Ident);
    setState(109);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == CACTParser::T__7) {
      setState(108);
      arraySymbol();
    }
    setState(111);
    match(CACTParser::T__9);
    setState(112);
    constInitVal();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ConstInitValContext ------------------------------------------------------------------

CACTParser::ConstInitValContext::ConstInitValContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CACTParser::ConstExpContext* CACTParser::ConstInitValContext::constExp() {
  return getRuleContext<CACTParser::ConstExpContext>(0);
}

CACTParser::ConstInitArrayContext* CACTParser::ConstInitValContext::constInitArray() {
  return getRuleContext<CACTParser::ConstInitArrayContext>(0);
}


size_t CACTParser::ConstInitValContext::getRuleIndex() const {
  return CACTParser::RuleConstInitVal;
}

void CACTParser::ConstInitValContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterConstInitVal(this);
}

void CACTParser::ConstInitValContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitConstInitVal(this);
}

CACTParser::ConstInitValContext* CACTParser::constInitVal() {
  ConstInitValContext *_localctx = _tracker.createInstance<ConstInitValContext>(_ctx, getState());
  enterRule(_localctx, 14, CACTParser::RuleConstInitVal);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(117);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case CACTParser::BoolConst:
      case CACTParser::IntConst:
      case CACTParser::FloatConst:
      case CACTParser::DoubleConst: {
        enterOuterAlt(_localctx, 1);
        setState(114);
        constExp();
        break;
      }

      case CACTParser::T__10: {
        enterOuterAlt(_localctx, 2);
        setState(115);
        match(CACTParser::T__10);
        setState(116);
        constInitArray();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ConstInitArrayContext ------------------------------------------------------------------

CACTParser::ConstInitArrayContext::ConstInitArrayContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<CACTParser::ConstExpContext *> CACTParser::ConstInitArrayContext::constExp() {
  return getRuleContexts<CACTParser::ConstExpContext>();
}

CACTParser::ConstExpContext* CACTParser::ConstInitArrayContext::constExp(size_t i) {
  return getRuleContext<CACTParser::ConstExpContext>(i);
}


size_t CACTParser::ConstInitArrayContext::getRuleIndex() const {
  return CACTParser::RuleConstInitArray;
}

void CACTParser::ConstInitArrayContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterConstInitArray(this);
}

void CACTParser::ConstInitArrayContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitConstInitArray(this);
}

CACTParser::ConstInitArrayContext* CACTParser::constInitArray() {
  ConstInitArrayContext *_localctx = _tracker.createInstance<ConstInitArrayContext>(_ctx, getState());
  enterRule(_localctx, 16, CACTParser::RuleConstInitArray);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(127);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << CACTParser::BoolConst)
      | (1ULL << CACTParser::IntConst)
      | (1ULL << CACTParser::FloatConst)
      | (1ULL << CACTParser::DoubleConst))) != 0)) {
      setState(119);
      constExp();
      setState(124);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == CACTParser::T__1) {
        setState(120);
        match(CACTParser::T__1);
        setState(121);
        constExp();
        setState(126);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
    }
    setState(129);
    match(CACTParser::T__11);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- VarDeclContext ------------------------------------------------------------------

CACTParser::VarDeclContext::VarDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CACTParser::BTypeContext* CACTParser::VarDeclContext::bType() {
  return getRuleContext<CACTParser::BTypeContext>(0);
}

std::vector<CACTParser::VarDefContext *> CACTParser::VarDeclContext::varDef() {
  return getRuleContexts<CACTParser::VarDefContext>();
}

CACTParser::VarDefContext* CACTParser::VarDeclContext::varDef(size_t i) {
  return getRuleContext<CACTParser::VarDefContext>(i);
}


size_t CACTParser::VarDeclContext::getRuleIndex() const {
  return CACTParser::RuleVarDecl;
}

void CACTParser::VarDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVarDecl(this);
}

void CACTParser::VarDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVarDecl(this);
}

CACTParser::VarDeclContext* CACTParser::varDecl() {
  VarDeclContext *_localctx = _tracker.createInstance<VarDeclContext>(_ctx, getState());
  enterRule(_localctx, 18, CACTParser::RuleVarDecl);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(131);
    bType();
    setState(132);
    varDef();
    setState(137);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == CACTParser::T__1) {
      setState(133);
      match(CACTParser::T__1);
      setState(134);
      varDef();
      setState(139);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(140);
    match(CACTParser::T__2);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- VarDefContext ------------------------------------------------------------------

CACTParser::VarDefContext::VarDefContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CACTParser::VarDefContext::Ident() {
  return getToken(CACTParser::Ident, 0);
}

CACTParser::ArraySymbolContext* CACTParser::VarDefContext::arraySymbol() {
  return getRuleContext<CACTParser::ArraySymbolContext>(0);
}

CACTParser::ConstInitValContext* CACTParser::VarDefContext::constInitVal() {
  return getRuleContext<CACTParser::ConstInitValContext>(0);
}


size_t CACTParser::VarDefContext::getRuleIndex() const {
  return CACTParser::RuleVarDef;
}

void CACTParser::VarDefContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVarDef(this);
}

void CACTParser::VarDefContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVarDef(this);
}

CACTParser::VarDefContext* CACTParser::varDef() {
  VarDefContext *_localctx = _tracker.createInstance<VarDefContext>(_ctx, getState());
  enterRule(_localctx, 20, CACTParser::RuleVarDef);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(152);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 13, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(142);
      match(CACTParser::Ident);
      setState(144);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == CACTParser::T__7) {
        setState(143);
        arraySymbol();
      }
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(146);
      match(CACTParser::Ident);
      setState(148);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == CACTParser::T__7) {
        setState(147);
        arraySymbol();
      }
      setState(150);
      match(CACTParser::T__9);
      setState(151);
      constInitVal();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FuncDefContext ------------------------------------------------------------------

CACTParser::FuncDefContext::FuncDefContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CACTParser::FuncTypeContext* CACTParser::FuncDefContext::funcType() {
  return getRuleContext<CACTParser::FuncTypeContext>(0);
}

tree::TerminalNode* CACTParser::FuncDefContext::Ident() {
  return getToken(CACTParser::Ident, 0);
}

CACTParser::BlockContext* CACTParser::FuncDefContext::block() {
  return getRuleContext<CACTParser::BlockContext>(0);
}

CACTParser::FuncFParamsContext* CACTParser::FuncDefContext::funcFParams() {
  return getRuleContext<CACTParser::FuncFParamsContext>(0);
}


size_t CACTParser::FuncDefContext::getRuleIndex() const {
  return CACTParser::RuleFuncDef;
}

void CACTParser::FuncDefContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFuncDef(this);
}

void CACTParser::FuncDefContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFuncDef(this);
}

CACTParser::FuncDefContext* CACTParser::funcDef() {
  FuncDefContext *_localctx = _tracker.createInstance<FuncDefContext>(_ctx, getState());
  enterRule(_localctx, 22, CACTParser::RuleFuncDef);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(154);
    funcType();
    setState(155);
    match(CACTParser::Ident);
    setState(156);
    match(CACTParser::T__12);
    setState(158);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << CACTParser::T__3)
      | (1ULL << CACTParser::T__4)
      | (1ULL << CACTParser::T__5)
      | (1ULL << CACTParser::T__6))) != 0)) {
      setState(157);
      funcFParams();
    }
    setState(160);
    match(CACTParser::T__13);
    setState(161);
    block();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FuncTypeContext ------------------------------------------------------------------

CACTParser::FuncTypeContext::FuncTypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t CACTParser::FuncTypeContext::getRuleIndex() const {
  return CACTParser::RuleFuncType;
}

void CACTParser::FuncTypeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFuncType(this);
}

void CACTParser::FuncTypeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFuncType(this);
}

CACTParser::FuncTypeContext* CACTParser::funcType() {
  FuncTypeContext *_localctx = _tracker.createInstance<FuncTypeContext>(_ctx, getState());
  enterRule(_localctx, 24, CACTParser::RuleFuncType);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(163);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << CACTParser::T__3)
      | (1ULL << CACTParser::T__4)
      | (1ULL << CACTParser::T__5)
      | (1ULL << CACTParser::T__6)
      | (1ULL << CACTParser::T__14))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FuncFParamsContext ------------------------------------------------------------------

CACTParser::FuncFParamsContext::FuncFParamsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<CACTParser::FuncFParamContext *> CACTParser::FuncFParamsContext::funcFParam() {
  return getRuleContexts<CACTParser::FuncFParamContext>();
}

CACTParser::FuncFParamContext* CACTParser::FuncFParamsContext::funcFParam(size_t i) {
  return getRuleContext<CACTParser::FuncFParamContext>(i);
}


size_t CACTParser::FuncFParamsContext::getRuleIndex() const {
  return CACTParser::RuleFuncFParams;
}

void CACTParser::FuncFParamsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFuncFParams(this);
}

void CACTParser::FuncFParamsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFuncFParams(this);
}

CACTParser::FuncFParamsContext* CACTParser::funcFParams() {
  FuncFParamsContext *_localctx = _tracker.createInstance<FuncFParamsContext>(_ctx, getState());
  enterRule(_localctx, 26, CACTParser::RuleFuncFParams);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(165);
    funcFParam();
    setState(170);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == CACTParser::T__1) {
      setState(166);
      match(CACTParser::T__1);
      setState(167);
      funcFParam();
      setState(172);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FuncFParamContext ------------------------------------------------------------------

CACTParser::FuncFParamContext::FuncFParamContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CACTParser::BTypeContext* CACTParser::FuncFParamContext::bType() {
  return getRuleContext<CACTParser::BTypeContext>(0);
}

tree::TerminalNode* CACTParser::FuncFParamContext::Ident() {
  return getToken(CACTParser::Ident, 0);
}

CACTParser::ArraySymbolContext* CACTParser::FuncFParamContext::arraySymbol() {
  return getRuleContext<CACTParser::ArraySymbolContext>(0);
}


size_t CACTParser::FuncFParamContext::getRuleIndex() const {
  return CACTParser::RuleFuncFParam;
}

void CACTParser::FuncFParamContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFuncFParam(this);
}

void CACTParser::FuncFParamContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFuncFParam(this);
}

CACTParser::FuncFParamContext* CACTParser::funcFParam() {
  FuncFParamContext *_localctx = _tracker.createInstance<FuncFParamContext>(_ctx, getState());
  enterRule(_localctx, 28, CACTParser::RuleFuncFParam);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(173);
    bType();
    setState(174);
    match(CACTParser::Ident);
    setState(176);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == CACTParser::T__7) {
      setState(175);
      arraySymbol();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BlockContext ------------------------------------------------------------------

CACTParser::BlockContext::BlockContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<CACTParser::BlockItemContext *> CACTParser::BlockContext::blockItem() {
  return getRuleContexts<CACTParser::BlockItemContext>();
}

CACTParser::BlockItemContext* CACTParser::BlockContext::blockItem(size_t i) {
  return getRuleContext<CACTParser::BlockItemContext>(i);
}


size_t CACTParser::BlockContext::getRuleIndex() const {
  return CACTParser::RuleBlock;
}

void CACTParser::BlockContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBlock(this);
}

void CACTParser::BlockContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBlock(this);
}

CACTParser::BlockContext* CACTParser::block() {
  BlockContext *_localctx = _tracker.createInstance<BlockContext>(_ctx, getState());
  enterRule(_localctx, 30, CACTParser::RuleBlock);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(178);
    match(CACTParser::T__10);
    setState(182);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << CACTParser::T__0)
      | (1ULL << CACTParser::T__2)
      | (1ULL << CACTParser::T__3)
      | (1ULL << CACTParser::T__4)
      | (1ULL << CACTParser::T__5)
      | (1ULL << CACTParser::T__6)
      | (1ULL << CACTParser::T__10)
      | (1ULL << CACTParser::T__12)
      | (1ULL << CACTParser::T__15)
      | (1ULL << CACTParser::T__16)
      | (1ULL << CACTParser::T__17)
      | (1ULL << CACTParser::BoolConst)
      | (1ULL << CACTParser::Ident)
      | (1ULL << CACTParser::ADD)
      | (1ULL << CACTParser::SUB)
      | (1ULL << CACTParser::NOT)
      | (1ULL << CACTParser::IntConst)
      | (1ULL << CACTParser::FloatConst)
      | (1ULL << CACTParser::DoubleConst))) != 0)) {
      setState(179);
      blockItem();
      setState(184);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(185);
    match(CACTParser::T__11);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BlockItemContext ------------------------------------------------------------------

CACTParser::BlockItemContext::BlockItemContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CACTParser::DeclContext* CACTParser::BlockItemContext::decl() {
  return getRuleContext<CACTParser::DeclContext>(0);
}

CACTParser::StmtContext* CACTParser::BlockItemContext::stmt() {
  return getRuleContext<CACTParser::StmtContext>(0);
}


size_t CACTParser::BlockItemContext::getRuleIndex() const {
  return CACTParser::RuleBlockItem;
}

void CACTParser::BlockItemContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBlockItem(this);
}

void CACTParser::BlockItemContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBlockItem(this);
}

CACTParser::BlockItemContext* CACTParser::blockItem() {
  BlockItemContext *_localctx = _tracker.createInstance<BlockItemContext>(_ctx, getState());
  enterRule(_localctx, 32, CACTParser::RuleBlockItem);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(189);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case CACTParser::T__0:
      case CACTParser::T__3:
      case CACTParser::T__4:
      case CACTParser::T__5:
      case CACTParser::T__6: {
        enterOuterAlt(_localctx, 1);
        setState(187);
        decl();
        break;
      }

      case CACTParser::T__2:
      case CACTParser::T__10:
      case CACTParser::T__12:
      case CACTParser::T__15:
      case CACTParser::T__16:
      case CACTParser::T__17:
      case CACTParser::BoolConst:
      case CACTParser::Ident:
      case CACTParser::ADD:
      case CACTParser::SUB:
      case CACTParser::NOT:
      case CACTParser::IntConst:
      case CACTParser::FloatConst:
      case CACTParser::DoubleConst: {
        enterOuterAlt(_localctx, 2);
        setState(188);
        stmt();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StmtContext ------------------------------------------------------------------

CACTParser::StmtContext::StmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t CACTParser::StmtContext::getRuleIndex() const {
  return CACTParser::RuleStmt;
}

void CACTParser::StmtContext::copyFrom(StmtContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- ExprStmtContext ------------------------------------------------------------------

CACTParser::ExpContext* CACTParser::ExprStmtContext::exp() {
  return getRuleContext<CACTParser::ExpContext>(0);
}

CACTParser::ExprStmtContext::ExprStmtContext(StmtContext *ctx) { copyFrom(ctx); }

void CACTParser::ExprStmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExprStmt(this);
}
void CACTParser::ExprStmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExprStmt(this);
}
//----------------- WhileStmtContext ------------------------------------------------------------------

CACTParser::WhileCondContext* CACTParser::WhileStmtContext::whileCond() {
  return getRuleContext<CACTParser::WhileCondContext>(0);
}

CACTParser::StmtContext* CACTParser::WhileStmtContext::stmt() {
  return getRuleContext<CACTParser::StmtContext>(0);
}

CACTParser::WhileStmtContext::WhileStmtContext(StmtContext *ctx) { copyFrom(ctx); }

void CACTParser::WhileStmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterWhileStmt(this);
}
void CACTParser::WhileStmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitWhileStmt(this);
}
//----------------- IfStmtContext ------------------------------------------------------------------

CACTParser::IfCondContext* CACTParser::IfStmtContext::ifCond() {
  return getRuleContext<CACTParser::IfCondContext>(0);
}

CACTParser::StmtContext* CACTParser::IfStmtContext::stmt() {
  return getRuleContext<CACTParser::StmtContext>(0);
}

CACTParser::IfStmtContext::IfStmtContext(StmtContext *ctx) { copyFrom(ctx); }

void CACTParser::IfStmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIfStmt(this);
}
void CACTParser::IfStmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIfStmt(this);
}
//----------------- BlockStmtContext ------------------------------------------------------------------

CACTParser::BlockContext* CACTParser::BlockStmtContext::block() {
  return getRuleContext<CACTParser::BlockContext>(0);
}

CACTParser::BlockStmtContext::BlockStmtContext(StmtContext *ctx) { copyFrom(ctx); }

void CACTParser::BlockStmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBlockStmt(this);
}
void CACTParser::BlockStmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBlockStmt(this);
}
//----------------- IfElseStmtContext ------------------------------------------------------------------

CACTParser::IfCondContext* CACTParser::IfElseStmtContext::ifCond() {
  return getRuleContext<CACTParser::IfCondContext>(0);
}

CACTParser::StmtContext* CACTParser::IfElseStmtContext::stmt() {
  return getRuleContext<CACTParser::StmtContext>(0);
}

CACTParser::ElseStmtContext* CACTParser::IfElseStmtContext::elseStmt() {
  return getRuleContext<CACTParser::ElseStmtContext>(0);
}

CACTParser::IfElseStmtContext::IfElseStmtContext(StmtContext *ctx) { copyFrom(ctx); }

void CACTParser::IfElseStmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIfElseStmt(this);
}
void CACTParser::IfElseStmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIfElseStmt(this);
}
//----------------- AssignStmtContext ------------------------------------------------------------------

CACTParser::LValContext* CACTParser::AssignStmtContext::lVal() {
  return getRuleContext<CACTParser::LValContext>(0);
}

CACTParser::ExpContext* CACTParser::AssignStmtContext::exp() {
  return getRuleContext<CACTParser::ExpContext>(0);
}

CACTParser::AssignStmtContext::AssignStmtContext(StmtContext *ctx) { copyFrom(ctx); }

void CACTParser::AssignStmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAssignStmt(this);
}
void CACTParser::AssignStmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAssignStmt(this);
}
//----------------- ReturnStmtContext ------------------------------------------------------------------

CACTParser::ExpContext* CACTParser::ReturnStmtContext::exp() {
  return getRuleContext<CACTParser::ExpContext>(0);
}

CACTParser::ReturnStmtContext::ReturnStmtContext(StmtContext *ctx) { copyFrom(ctx); }

void CACTParser::ReturnStmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterReturnStmt(this);
}
void CACTParser::ReturnStmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitReturnStmt(this);
}
CACTParser::StmtContext* CACTParser::stmt() {
  StmtContext *_localctx = _tracker.createInstance<StmtContext>(_ctx, getState());
  enterRule(_localctx, 34, CACTParser::RuleStmt);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(225);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 21, _ctx)) {
    case 1: {
      _localctx = dynamic_cast<StmtContext *>(_tracker.createInstance<CACTParser::AssignStmtContext>(_localctx));
      enterOuterAlt(_localctx, 1);
      setState(191);
      lVal();
      setState(192);
      match(CACTParser::T__9);
      setState(193);
      exp();
      setState(194);
      match(CACTParser::T__2);
      break;
    }

    case 2: {
      _localctx = dynamic_cast<StmtContext *>(_tracker.createInstance<CACTParser::ExprStmtContext>(_localctx));
      enterOuterAlt(_localctx, 2);
      setState(197);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << CACTParser::T__12)
        | (1ULL << CACTParser::BoolConst)
        | (1ULL << CACTParser::Ident)
        | (1ULL << CACTParser::ADD)
        | (1ULL << CACTParser::SUB)
        | (1ULL << CACTParser::NOT)
        | (1ULL << CACTParser::IntConst)
        | (1ULL << CACTParser::FloatConst)
        | (1ULL << CACTParser::DoubleConst))) != 0)) {
        setState(196);
        exp();
      }
      setState(199);
      match(CACTParser::T__2);
      break;
    }

    case 3: {
      _localctx = dynamic_cast<StmtContext *>(_tracker.createInstance<CACTParser::BlockStmtContext>(_localctx));
      enterOuterAlt(_localctx, 3);
      setState(200);
      block();
      break;
    }

    case 4: {
      _localctx = dynamic_cast<StmtContext *>(_tracker.createInstance<CACTParser::IfElseStmtContext>(_localctx));
      enterOuterAlt(_localctx, 4);
      setState(201);
      match(CACTParser::T__15);
      setState(202);
      match(CACTParser::T__12);
      setState(203);
      ifCond();
      setState(204);
      match(CACTParser::T__13);
      setState(205);
      stmt();
      setState(206);
      elseStmt();
      break;
    }

    case 5: {
      _localctx = dynamic_cast<StmtContext *>(_tracker.createInstance<CACTParser::IfStmtContext>(_localctx));
      enterOuterAlt(_localctx, 5);
      setState(208);
      match(CACTParser::T__15);
      setState(209);
      match(CACTParser::T__12);
      setState(210);
      ifCond();
      setState(211);
      match(CACTParser::T__13);
      setState(212);
      stmt();
      break;
    }

    case 6: {
      _localctx = dynamic_cast<StmtContext *>(_tracker.createInstance<CACTParser::WhileStmtContext>(_localctx));
      enterOuterAlt(_localctx, 6);
      setState(214);
      match(CACTParser::T__16);
      setState(215);
      match(CACTParser::T__12);
      setState(216);
      whileCond();
      setState(217);
      match(CACTParser::T__13);
      setState(218);
      stmt();
      break;
    }

    case 7: {
      _localctx = dynamic_cast<StmtContext *>(_tracker.createInstance<CACTParser::ReturnStmtContext>(_localctx));
      enterOuterAlt(_localctx, 7);
      setState(220);
      match(CACTParser::T__17);
      setState(222);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << CACTParser::T__12)
        | (1ULL << CACTParser::BoolConst)
        | (1ULL << CACTParser::Ident)
        | (1ULL << CACTParser::ADD)
        | (1ULL << CACTParser::SUB)
        | (1ULL << CACTParser::NOT)
        | (1ULL << CACTParser::IntConst)
        | (1ULL << CACTParser::FloatConst)
        | (1ULL << CACTParser::DoubleConst))) != 0)) {
        setState(221);
        exp();
      }
      setState(224);
      match(CACTParser::T__2);
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ElseStmtContext ------------------------------------------------------------------

CACTParser::ElseStmtContext::ElseStmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CACTParser::StmtContext* CACTParser::ElseStmtContext::stmt() {
  return getRuleContext<CACTParser::StmtContext>(0);
}


size_t CACTParser::ElseStmtContext::getRuleIndex() const {
  return CACTParser::RuleElseStmt;
}

void CACTParser::ElseStmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterElseStmt(this);
}

void CACTParser::ElseStmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitElseStmt(this);
}

CACTParser::ElseStmtContext* CACTParser::elseStmt() {
  ElseStmtContext *_localctx = _tracker.createInstance<ElseStmtContext>(_ctx, getState());
  enterRule(_localctx, 36, CACTParser::RuleElseStmt);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(227);
    match(CACTParser::T__18);
    setState(228);
    stmt();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExpContext ------------------------------------------------------------------

CACTParser::ExpContext::ExpContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CACTParser::AddExpContext* CACTParser::ExpContext::addExp() {
  return getRuleContext<CACTParser::AddExpContext>(0);
}

tree::TerminalNode* CACTParser::ExpContext::BoolConst() {
  return getToken(CACTParser::BoolConst, 0);
}


size_t CACTParser::ExpContext::getRuleIndex() const {
  return CACTParser::RuleExp;
}

void CACTParser::ExpContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExp(this);
}

void CACTParser::ExpContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExp(this);
}

CACTParser::ExpContext* CACTParser::exp() {
  ExpContext *_localctx = _tracker.createInstance<ExpContext>(_ctx, getState());
  enterRule(_localctx, 38, CACTParser::RuleExp);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(232);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case CACTParser::T__12:
      case CACTParser::Ident:
      case CACTParser::ADD:
      case CACTParser::SUB:
      case CACTParser::NOT:
      case CACTParser::IntConst:
      case CACTParser::FloatConst:
      case CACTParser::DoubleConst: {
        enterOuterAlt(_localctx, 1);
        setState(230);
        addExp(0);
        break;
      }

      case CACTParser::BoolConst: {
        enterOuterAlt(_localctx, 2);
        setState(231);
        match(CACTParser::BoolConst);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CondContext ------------------------------------------------------------------

CACTParser::CondContext::CondContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CACTParser::LOrExpContext* CACTParser::CondContext::lOrExp() {
  return getRuleContext<CACTParser::LOrExpContext>(0);
}


size_t CACTParser::CondContext::getRuleIndex() const {
  return CACTParser::RuleCond;
}

void CACTParser::CondContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCond(this);
}

void CACTParser::CondContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCond(this);
}

CACTParser::CondContext* CACTParser::cond() {
  CondContext *_localctx = _tracker.createInstance<CondContext>(_ctx, getState());
  enterRule(_localctx, 40, CACTParser::RuleCond);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(234);
    lOrExp(0);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- IfCondContext ------------------------------------------------------------------

CACTParser::IfCondContext::IfCondContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CACTParser::CondContext* CACTParser::IfCondContext::cond() {
  return getRuleContext<CACTParser::CondContext>(0);
}


size_t CACTParser::IfCondContext::getRuleIndex() const {
  return CACTParser::RuleIfCond;
}

void CACTParser::IfCondContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIfCond(this);
}

void CACTParser::IfCondContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIfCond(this);
}

CACTParser::IfCondContext* CACTParser::ifCond() {
  IfCondContext *_localctx = _tracker.createInstance<IfCondContext>(_ctx, getState());
  enterRule(_localctx, 42, CACTParser::RuleIfCond);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(236);
    cond();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- WhileCondContext ------------------------------------------------------------------

CACTParser::WhileCondContext::WhileCondContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CACTParser::CondContext* CACTParser::WhileCondContext::cond() {
  return getRuleContext<CACTParser::CondContext>(0);
}


size_t CACTParser::WhileCondContext::getRuleIndex() const {
  return CACTParser::RuleWhileCond;
}

void CACTParser::WhileCondContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterWhileCond(this);
}

void CACTParser::WhileCondContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitWhileCond(this);
}

CACTParser::WhileCondContext* CACTParser::whileCond() {
  WhileCondContext *_localctx = _tracker.createInstance<WhileCondContext>(_ctx, getState());
  enterRule(_localctx, 44, CACTParser::RuleWhileCond);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(238);
    cond();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- LValContext ------------------------------------------------------------------

CACTParser::LValContext::LValContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CACTParser::LValContext::Ident() {
  return getToken(CACTParser::Ident, 0);
}

CACTParser::ExpContext* CACTParser::LValContext::exp() {
  return getRuleContext<CACTParser::ExpContext>(0);
}


size_t CACTParser::LValContext::getRuleIndex() const {
  return CACTParser::RuleLVal;
}

void CACTParser::LValContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLVal(this);
}

void CACTParser::LValContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLVal(this);
}

CACTParser::LValContext* CACTParser::lVal() {
  LValContext *_localctx = _tracker.createInstance<LValContext>(_ctx, getState());
  enterRule(_localctx, 46, CACTParser::RuleLVal);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(240);
    match(CACTParser::Ident);
    setState(245);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 23, _ctx)) {
    case 1: {
      setState(241);
      match(CACTParser::T__7);
      setState(242);
      exp();
      setState(243);
      match(CACTParser::T__8);
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- PrimaryExpContext ------------------------------------------------------------------

CACTParser::PrimaryExpContext::PrimaryExpContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CACTParser::ExpContext* CACTParser::PrimaryExpContext::exp() {
  return getRuleContext<CACTParser::ExpContext>(0);
}

CACTParser::LValContext* CACTParser::PrimaryExpContext::lVal() {
  return getRuleContext<CACTParser::LValContext>(0);
}

CACTParser::NumberContext* CACTParser::PrimaryExpContext::number() {
  return getRuleContext<CACTParser::NumberContext>(0);
}


size_t CACTParser::PrimaryExpContext::getRuleIndex() const {
  return CACTParser::RulePrimaryExp;
}

void CACTParser::PrimaryExpContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPrimaryExp(this);
}

void CACTParser::PrimaryExpContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPrimaryExp(this);
}

CACTParser::PrimaryExpContext* CACTParser::primaryExp() {
  PrimaryExpContext *_localctx = _tracker.createInstance<PrimaryExpContext>(_ctx, getState());
  enterRule(_localctx, 48, CACTParser::RulePrimaryExp);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(253);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case CACTParser::T__12: {
        enterOuterAlt(_localctx, 1);
        setState(247);
        match(CACTParser::T__12);
        setState(248);
        exp();
        setState(249);
        match(CACTParser::T__13);
        break;
      }

      case CACTParser::Ident: {
        enterOuterAlt(_localctx, 2);
        setState(251);
        lVal();
        break;
      }

      case CACTParser::IntConst:
      case CACTParser::FloatConst:
      case CACTParser::DoubleConst: {
        enterOuterAlt(_localctx, 3);
        setState(252);
        number();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- NumberContext ------------------------------------------------------------------

CACTParser::NumberContext::NumberContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CACTParser::NumberContext::IntConst() {
  return getToken(CACTParser::IntConst, 0);
}

tree::TerminalNode* CACTParser::NumberContext::DoubleConst() {
  return getToken(CACTParser::DoubleConst, 0);
}

tree::TerminalNode* CACTParser::NumberContext::FloatConst() {
  return getToken(CACTParser::FloatConst, 0);
}


size_t CACTParser::NumberContext::getRuleIndex() const {
  return CACTParser::RuleNumber;
}

void CACTParser::NumberContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNumber(this);
}

void CACTParser::NumberContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNumber(this);
}

CACTParser::NumberContext* CACTParser::number() {
  NumberContext *_localctx = _tracker.createInstance<NumberContext>(_ctx, getState());
  enterRule(_localctx, 50, CACTParser::RuleNumber);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(255);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << CACTParser::IntConst)
      | (1ULL << CACTParser::FloatConst)
      | (1ULL << CACTParser::DoubleConst))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- UnaryExpContext ------------------------------------------------------------------

CACTParser::UnaryExpContext::UnaryExpContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CACTParser::PrimaryExpContext* CACTParser::UnaryExpContext::primaryExp() {
  return getRuleContext<CACTParser::PrimaryExpContext>(0);
}

tree::TerminalNode* CACTParser::UnaryExpContext::Ident() {
  return getToken(CACTParser::Ident, 0);
}

CACTParser::FuncRParamsContext* CACTParser::UnaryExpContext::funcRParams() {
  return getRuleContext<CACTParser::FuncRParamsContext>(0);
}

CACTParser::UnaryOpContext* CACTParser::UnaryExpContext::unaryOp() {
  return getRuleContext<CACTParser::UnaryOpContext>(0);
}

CACTParser::UnaryExpContext* CACTParser::UnaryExpContext::unaryExp() {
  return getRuleContext<CACTParser::UnaryExpContext>(0);
}


size_t CACTParser::UnaryExpContext::getRuleIndex() const {
  return CACTParser::RuleUnaryExp;
}

void CACTParser::UnaryExpContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterUnaryExp(this);
}

void CACTParser::UnaryExpContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitUnaryExp(this);
}

CACTParser::UnaryExpContext* CACTParser::unaryExp() {
  UnaryExpContext *_localctx = _tracker.createInstance<UnaryExpContext>(_ctx, getState());
  enterRule(_localctx, 52, CACTParser::RuleUnaryExp);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(267);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 26, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(257);
      primaryExp();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(258);
      match(CACTParser::Ident);
      setState(259);
      match(CACTParser::T__12);
      setState(261);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << CACTParser::T__12)
        | (1ULL << CACTParser::BoolConst)
        | (1ULL << CACTParser::Ident)
        | (1ULL << CACTParser::ADD)
        | (1ULL << CACTParser::SUB)
        | (1ULL << CACTParser::NOT)
        | (1ULL << CACTParser::IntConst)
        | (1ULL << CACTParser::FloatConst)
        | (1ULL << CACTParser::DoubleConst))) != 0)) {
        setState(260);
        funcRParams();
      }
      setState(263);
      match(CACTParser::T__13);
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(264);
      unaryOp();
      setState(265);
      unaryExp();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- UnaryOpContext ------------------------------------------------------------------

CACTParser::UnaryOpContext::UnaryOpContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CACTParser::UnaryOpContext::ADD() {
  return getToken(CACTParser::ADD, 0);
}

tree::TerminalNode* CACTParser::UnaryOpContext::SUB() {
  return getToken(CACTParser::SUB, 0);
}

tree::TerminalNode* CACTParser::UnaryOpContext::NOT() {
  return getToken(CACTParser::NOT, 0);
}


size_t CACTParser::UnaryOpContext::getRuleIndex() const {
  return CACTParser::RuleUnaryOp;
}

void CACTParser::UnaryOpContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterUnaryOp(this);
}

void CACTParser::UnaryOpContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitUnaryOp(this);
}

CACTParser::UnaryOpContext* CACTParser::unaryOp() {
  UnaryOpContext *_localctx = _tracker.createInstance<UnaryOpContext>(_ctx, getState());
  enterRule(_localctx, 54, CACTParser::RuleUnaryOp);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(269);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << CACTParser::ADD)
      | (1ULL << CACTParser::SUB)
      | (1ULL << CACTParser::NOT))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FuncRParamsContext ------------------------------------------------------------------

CACTParser::FuncRParamsContext::FuncRParamsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<CACTParser::ExpContext *> CACTParser::FuncRParamsContext::exp() {
  return getRuleContexts<CACTParser::ExpContext>();
}

CACTParser::ExpContext* CACTParser::FuncRParamsContext::exp(size_t i) {
  return getRuleContext<CACTParser::ExpContext>(i);
}


size_t CACTParser::FuncRParamsContext::getRuleIndex() const {
  return CACTParser::RuleFuncRParams;
}

void CACTParser::FuncRParamsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFuncRParams(this);
}

void CACTParser::FuncRParamsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFuncRParams(this);
}

CACTParser::FuncRParamsContext* CACTParser::funcRParams() {
  FuncRParamsContext *_localctx = _tracker.createInstance<FuncRParamsContext>(_ctx, getState());
  enterRule(_localctx, 56, CACTParser::RuleFuncRParams);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(271);
    exp();
    setState(276);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == CACTParser::T__1) {
      setState(272);
      match(CACTParser::T__1);
      setState(273);
      exp();
      setState(278);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- MulExpContext ------------------------------------------------------------------

CACTParser::MulExpContext::MulExpContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CACTParser::UnaryExpContext* CACTParser::MulExpContext::unaryExp() {
  return getRuleContext<CACTParser::UnaryExpContext>(0);
}

CACTParser::MulExpContext* CACTParser::MulExpContext::mulExp() {
  return getRuleContext<CACTParser::MulExpContext>(0);
}

tree::TerminalNode* CACTParser::MulExpContext::MUL() {
  return getToken(CACTParser::MUL, 0);
}

tree::TerminalNode* CACTParser::MulExpContext::DIV() {
  return getToken(CACTParser::DIV, 0);
}

tree::TerminalNode* CACTParser::MulExpContext::MOD() {
  return getToken(CACTParser::MOD, 0);
}


size_t CACTParser::MulExpContext::getRuleIndex() const {
  return CACTParser::RuleMulExp;
}

void CACTParser::MulExpContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMulExp(this);
}

void CACTParser::MulExpContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMulExp(this);
}


CACTParser::MulExpContext* CACTParser::mulExp() {
   return mulExp(0);
}

CACTParser::MulExpContext* CACTParser::mulExp(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  CACTParser::MulExpContext *_localctx = _tracker.createInstance<MulExpContext>(_ctx, parentState);
  CACTParser::MulExpContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 58;
  enterRecursionRule(_localctx, 58, CACTParser::RuleMulExp, precedence);

    size_t _la = 0;

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(280);
    unaryExp();
    _ctx->stop = _input->LT(-1);
    setState(287);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 28, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<MulExpContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleMulExp);
        setState(282);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(283);
        dynamic_cast<MulExpContext *>(_localctx)->op = _input->LT(1);
        _la = _input->LA(1);
        if (!((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & ((1ULL << CACTParser::MUL)
          | (1ULL << CACTParser::DIV)
          | (1ULL << CACTParser::MOD))) != 0))) {
          dynamic_cast<MulExpContext *>(_localctx)->op = _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(284);
        unaryExp(); 
      }
      setState(289);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 28, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- AddExpContext ------------------------------------------------------------------

CACTParser::AddExpContext::AddExpContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CACTParser::MulExpContext* CACTParser::AddExpContext::mulExp() {
  return getRuleContext<CACTParser::MulExpContext>(0);
}

CACTParser::AddExpContext* CACTParser::AddExpContext::addExp() {
  return getRuleContext<CACTParser::AddExpContext>(0);
}

tree::TerminalNode* CACTParser::AddExpContext::ADD() {
  return getToken(CACTParser::ADD, 0);
}

tree::TerminalNode* CACTParser::AddExpContext::SUB() {
  return getToken(CACTParser::SUB, 0);
}


size_t CACTParser::AddExpContext::getRuleIndex() const {
  return CACTParser::RuleAddExp;
}

void CACTParser::AddExpContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAddExp(this);
}

void CACTParser::AddExpContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAddExp(this);
}


CACTParser::AddExpContext* CACTParser::addExp() {
   return addExp(0);
}

CACTParser::AddExpContext* CACTParser::addExp(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  CACTParser::AddExpContext *_localctx = _tracker.createInstance<AddExpContext>(_ctx, parentState);
  CACTParser::AddExpContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 60;
  enterRecursionRule(_localctx, 60, CACTParser::RuleAddExp, precedence);

    size_t _la = 0;

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(291);
    mulExp(0);
    _ctx->stop = _input->LT(-1);
    setState(298);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 29, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<AddExpContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleAddExp);
        setState(293);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(294);
        dynamic_cast<AddExpContext *>(_localctx)->op = _input->LT(1);
        _la = _input->LA(1);
        if (!(_la == CACTParser::ADD

        || _la == CACTParser::SUB)) {
          dynamic_cast<AddExpContext *>(_localctx)->op = _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(295);
        mulExp(0); 
      }
      setState(300);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 29, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- RelExpContext ------------------------------------------------------------------

CACTParser::RelExpContext::RelExpContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CACTParser::AddExpContext* CACTParser::RelExpContext::addExp() {
  return getRuleContext<CACTParser::AddExpContext>(0);
}

tree::TerminalNode* CACTParser::RelExpContext::BoolConst() {
  return getToken(CACTParser::BoolConst, 0);
}

CACTParser::RelExpContext* CACTParser::RelExpContext::relExp() {
  return getRuleContext<CACTParser::RelExpContext>(0);
}

tree::TerminalNode* CACTParser::RelExpContext::GT() {
  return getToken(CACTParser::GT, 0);
}

tree::TerminalNode* CACTParser::RelExpContext::LT() {
  return getToken(CACTParser::LT, 0);
}

tree::TerminalNode* CACTParser::RelExpContext::LE() {
  return getToken(CACTParser::LE, 0);
}

tree::TerminalNode* CACTParser::RelExpContext::GE() {
  return getToken(CACTParser::GE, 0);
}


size_t CACTParser::RelExpContext::getRuleIndex() const {
  return CACTParser::RuleRelExp;
}

void CACTParser::RelExpContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterRelExp(this);
}

void CACTParser::RelExpContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitRelExp(this);
}


CACTParser::RelExpContext* CACTParser::relExp() {
   return relExp(0);
}

CACTParser::RelExpContext* CACTParser::relExp(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  CACTParser::RelExpContext *_localctx = _tracker.createInstance<RelExpContext>(_ctx, parentState);
  CACTParser::RelExpContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 62;
  enterRecursionRule(_localctx, 62, CACTParser::RuleRelExp, precedence);

    size_t _la = 0;

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(304);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case CACTParser::T__12:
      case CACTParser::Ident:
      case CACTParser::ADD:
      case CACTParser::SUB:
      case CACTParser::NOT:
      case CACTParser::IntConst:
      case CACTParser::FloatConst:
      case CACTParser::DoubleConst: {
        setState(302);
        addExp(0);
        break;
      }

      case CACTParser::BoolConst: {
        setState(303);
        match(CACTParser::BoolConst);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    _ctx->stop = _input->LT(-1);
    setState(311);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 31, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<RelExpContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleRelExp);
        setState(306);

        if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
        setState(307);
        dynamic_cast<RelExpContext *>(_localctx)->op = _input->LT(1);
        _la = _input->LA(1);
        if (!((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & ((1ULL << CACTParser::GT)
          | (1ULL << CACTParser::LT)
          | (1ULL << CACTParser::GE)
          | (1ULL << CACTParser::LE))) != 0))) {
          dynamic_cast<RelExpContext *>(_localctx)->op = _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(308);
        addExp(0); 
      }
      setState(313);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 31, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- EqExpContext ------------------------------------------------------------------

CACTParser::EqExpContext::EqExpContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CACTParser::RelExpContext* CACTParser::EqExpContext::relExp() {
  return getRuleContext<CACTParser::RelExpContext>(0);
}

CACTParser::EqExpContext* CACTParser::EqExpContext::eqExp() {
  return getRuleContext<CACTParser::EqExpContext>(0);
}

tree::TerminalNode* CACTParser::EqExpContext::EQ() {
  return getToken(CACTParser::EQ, 0);
}

tree::TerminalNode* CACTParser::EqExpContext::NE() {
  return getToken(CACTParser::NE, 0);
}


size_t CACTParser::EqExpContext::getRuleIndex() const {
  return CACTParser::RuleEqExp;
}

void CACTParser::EqExpContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterEqExp(this);
}

void CACTParser::EqExpContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitEqExp(this);
}


CACTParser::EqExpContext* CACTParser::eqExp() {
   return eqExp(0);
}

CACTParser::EqExpContext* CACTParser::eqExp(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  CACTParser::EqExpContext *_localctx = _tracker.createInstance<EqExpContext>(_ctx, parentState);
  CACTParser::EqExpContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 64;
  enterRecursionRule(_localctx, 64, CACTParser::RuleEqExp, precedence);

    size_t _la = 0;

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(315);
    relExp(0);
    _ctx->stop = _input->LT(-1);
    setState(322);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 32, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<EqExpContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleEqExp);
        setState(317);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(318);
        dynamic_cast<EqExpContext *>(_localctx)->op = _input->LT(1);
        _la = _input->LA(1);
        if (!(_la == CACTParser::NE

        || _la == CACTParser::EQ)) {
          dynamic_cast<EqExpContext *>(_localctx)->op = _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(319);
        relExp(0); 
      }
      setState(324);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 32, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- LAndExpContext ------------------------------------------------------------------

CACTParser::LAndExpContext::LAndExpContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CACTParser::EqExpContext* CACTParser::LAndExpContext::eqExp() {
  return getRuleContext<CACTParser::EqExpContext>(0);
}

CACTParser::LAndExpContext* CACTParser::LAndExpContext::lAndExp() {
  return getRuleContext<CACTParser::LAndExpContext>(0);
}

tree::TerminalNode* CACTParser::LAndExpContext::AND() {
  return getToken(CACTParser::AND, 0);
}


size_t CACTParser::LAndExpContext::getRuleIndex() const {
  return CACTParser::RuleLAndExp;
}

void CACTParser::LAndExpContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLAndExp(this);
}

void CACTParser::LAndExpContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLAndExp(this);
}


CACTParser::LAndExpContext* CACTParser::lAndExp() {
   return lAndExp(0);
}

CACTParser::LAndExpContext* CACTParser::lAndExp(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  CACTParser::LAndExpContext *_localctx = _tracker.createInstance<LAndExpContext>(_ctx, parentState);
  CACTParser::LAndExpContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 66;
  enterRecursionRule(_localctx, 66, CACTParser::RuleLAndExp, precedence);

    

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(326);
    eqExp(0);
    _ctx->stop = _input->LT(-1);
    setState(333);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 33, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<LAndExpContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleLAndExp);
        setState(328);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(329);
        dynamic_cast<LAndExpContext *>(_localctx)->op = match(CACTParser::AND);
        setState(330);
        eqExp(0); 
      }
      setState(335);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 33, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- LOrExpContext ------------------------------------------------------------------

CACTParser::LOrExpContext::LOrExpContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CACTParser::LAndExpContext* CACTParser::LOrExpContext::lAndExp() {
  return getRuleContext<CACTParser::LAndExpContext>(0);
}

CACTParser::LOrExpContext* CACTParser::LOrExpContext::lOrExp() {
  return getRuleContext<CACTParser::LOrExpContext>(0);
}

tree::TerminalNode* CACTParser::LOrExpContext::OR() {
  return getToken(CACTParser::OR, 0);
}


size_t CACTParser::LOrExpContext::getRuleIndex() const {
  return CACTParser::RuleLOrExp;
}

void CACTParser::LOrExpContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLOrExp(this);
}

void CACTParser::LOrExpContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLOrExp(this);
}


CACTParser::LOrExpContext* CACTParser::lOrExp() {
   return lOrExp(0);
}

CACTParser::LOrExpContext* CACTParser::lOrExp(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  CACTParser::LOrExpContext *_localctx = _tracker.createInstance<LOrExpContext>(_ctx, parentState);
  CACTParser::LOrExpContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 68;
  enterRecursionRule(_localctx, 68, CACTParser::RuleLOrExp, precedence);

    

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(337);
    lAndExp(0);
    _ctx->stop = _input->LT(-1);
    setState(344);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 34, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<LOrExpContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleLOrExp);
        setState(339);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(340);
        dynamic_cast<LOrExpContext *>(_localctx)->op = match(CACTParser::OR);
        setState(341);
        lAndExp(0); 
      }
      setState(346);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 34, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- ConstExpContext ------------------------------------------------------------------

CACTParser::ConstExpContext::ConstExpContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CACTParser::NumberContext* CACTParser::ConstExpContext::number() {
  return getRuleContext<CACTParser::NumberContext>(0);
}

tree::TerminalNode* CACTParser::ConstExpContext::BoolConst() {
  return getToken(CACTParser::BoolConst, 0);
}


size_t CACTParser::ConstExpContext::getRuleIndex() const {
  return CACTParser::RuleConstExp;
}

void CACTParser::ConstExpContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterConstExp(this);
}

void CACTParser::ConstExpContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitConstExp(this);
}

CACTParser::ConstExpContext* CACTParser::constExp() {
  ConstExpContext *_localctx = _tracker.createInstance<ConstExpContext>(_ctx, getState());
  enterRule(_localctx, 70, CACTParser::RuleConstExp);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(349);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case CACTParser::IntConst:
      case CACTParser::FloatConst:
      case CACTParser::DoubleConst: {
        enterOuterAlt(_localctx, 1);
        setState(347);
        number();
        break;
      }

      case CACTParser::BoolConst: {
        enterOuterAlt(_localctx, 2);
        setState(348);
        match(CACTParser::BoolConst);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

bool CACTParser::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
    case 29: return mulExpSempred(dynamic_cast<MulExpContext *>(context), predicateIndex);
    case 30: return addExpSempred(dynamic_cast<AddExpContext *>(context), predicateIndex);
    case 31: return relExpSempred(dynamic_cast<RelExpContext *>(context), predicateIndex);
    case 32: return eqExpSempred(dynamic_cast<EqExpContext *>(context), predicateIndex);
    case 33: return lAndExpSempred(dynamic_cast<LAndExpContext *>(context), predicateIndex);
    case 34: return lOrExpSempred(dynamic_cast<LOrExpContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool CACTParser::mulExpSempred(MulExpContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool CACTParser::addExpSempred(AddExpContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 1: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool CACTParser::relExpSempred(RelExpContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 2: return precpred(_ctx, 2);

  default:
    break;
  }
  return true;
}

bool CACTParser::eqExpSempred(EqExpContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 3: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool CACTParser::lAndExpSempred(LAndExpContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 4: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool CACTParser::lOrExpSempred(LOrExpContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 5: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

// Static vars and initialization.
std::vector<dfa::DFA> CACTParser::_decisionToDFA;
atn::PredictionContextCache CACTParser::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN CACTParser::_atn;
std::vector<uint16_t> CACTParser::_serializedATN;

std::vector<std::string> CACTParser::_ruleNames = {
  "compUnit", "transUnit", "decl", "constDecl", "bType", "arraySymbol", 
  "constDef", "constInitVal", "constInitArray", "varDecl", "varDef", "funcDef", 
  "funcType", "funcFParams", "funcFParam", "block", "blockItem", "stmt", 
  "elseStmt", "exp", "cond", "ifCond", "whileCond", "lVal", "primaryExp", 
  "number", "unaryExp", "unaryOp", "funcRParams", "mulExp", "addExp", "relExp", 
  "eqExp", "lAndExp", "lOrExp", "constExp"
};

std::vector<std::string> CACTParser::_literalNames = {
  "", "'const'", "','", "';'", "'int'", "'bool'", "'float'", "'double'", 
  "'['", "']'", "'='", "'{'", "'}'", "'('", "')'", "'void'", "'if'", "'while'", 
  "'return'", "'else'", "", "", "'+'", "'-'", "'*'", "'/'", "'%'", "'!'", 
  "'!='", "'=='", "'>'", "'<'", "'>='", "'<='", "'&&'", "'||'"
};

std::vector<std::string> CACTParser::_symbolicNames = {
  "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 
  "", "", "BoolConst", "Ident", "ADD", "SUB", "MUL", "DIV", "MOD", "NOT", 
  "NE", "EQ", "GT", "LT", "GE", "LE", "AND", "OR", "IntConst", "NewLine", 
  "WhiteSpace", "BlockComment", "LineComment", "FloatConst", "DoubleConst", 
  "DecimalFloatConst", "FracConst", "ExpPart", "DigitSeq"
};

dfa::Vocabulary CACTParser::_vocabulary(_literalNames, _symbolicNames);

std::vector<std::string> CACTParser::_tokenNames;

CACTParser::Initializer::Initializer() {
	for (size_t i = 0; i < _symbolicNames.size(); ++i) {
		std::string name = _vocabulary.getLiteralName(i);
		if (name.empty()) {
			name = _vocabulary.getSymbolicName(i);
		}

		if (name.empty()) {
			_tokenNames.push_back("<INVALID>");
		} else {
      _tokenNames.push_back(name);
    }
	}

  _serializedATN = {
    0x3, 0x608b, 0xa72a, 0x8133, 0xb9ed, 0x417c, 0x3be7, 0x7786, 0x5964, 
    0x3, 0x30, 0x162, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 
    0x9, 0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 0x7, 
    0x4, 0x8, 0x9, 0x8, 0x4, 0x9, 0x9, 0x9, 0x4, 0xa, 0x9, 0xa, 0x4, 0xb, 
    0x9, 0xb, 0x4, 0xc, 0x9, 0xc, 0x4, 0xd, 0x9, 0xd, 0x4, 0xe, 0x9, 0xe, 
    0x4, 0xf, 0x9, 0xf, 0x4, 0x10, 0x9, 0x10, 0x4, 0x11, 0x9, 0x11, 0x4, 
    0x12, 0x9, 0x12, 0x4, 0x13, 0x9, 0x13, 0x4, 0x14, 0x9, 0x14, 0x4, 0x15, 
    0x9, 0x15, 0x4, 0x16, 0x9, 0x16, 0x4, 0x17, 0x9, 0x17, 0x4, 0x18, 0x9, 
    0x18, 0x4, 0x19, 0x9, 0x19, 0x4, 0x1a, 0x9, 0x1a, 0x4, 0x1b, 0x9, 0x1b, 
    0x4, 0x1c, 0x9, 0x1c, 0x4, 0x1d, 0x9, 0x1d, 0x4, 0x1e, 0x9, 0x1e, 0x4, 
    0x1f, 0x9, 0x1f, 0x4, 0x20, 0x9, 0x20, 0x4, 0x21, 0x9, 0x21, 0x4, 0x22, 
    0x9, 0x22, 0x4, 0x23, 0x9, 0x23, 0x4, 0x24, 0x9, 0x24, 0x4, 0x25, 0x9, 
    0x25, 0x3, 0x2, 0x5, 0x2, 0x4c, 0xa, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x3, 
    0x3, 0x3, 0x6, 0x3, 0x52, 0xa, 0x3, 0xd, 0x3, 0xe, 0x3, 0x53, 0x3, 0x4, 
    0x3, 0x4, 0x5, 0x4, 0x58, 0xa, 0x4, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 
    0x5, 0x3, 0x5, 0x7, 0x5, 0x5f, 0xa, 0x5, 0xc, 0x5, 0xe, 0x5, 0x62, 0xb, 
    0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x6, 0x3, 0x6, 0x3, 0x7, 0x3, 0x7, 0x5, 
    0x7, 0x6a, 0xa, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x8, 0x3, 0x8, 0x5, 0x8, 
    0x70, 0xa, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x9, 0x3, 0x9, 0x3, 
    0x9, 0x5, 0x9, 0x78, 0xa, 0x9, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x7, 0xa, 
    0x7d, 0xa, 0xa, 0xc, 0xa, 0xe, 0xa, 0x80, 0xb, 0xa, 0x5, 0xa, 0x82, 
    0xa, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 
    0x7, 0xb, 0x8a, 0xa, 0xb, 0xc, 0xb, 0xe, 0xb, 0x8d, 0xb, 0xb, 0x3, 0xb, 
    0x3, 0xb, 0x3, 0xc, 0x3, 0xc, 0x5, 0xc, 0x93, 0xa, 0xc, 0x3, 0xc, 0x3, 
    0xc, 0x5, 0xc, 0x97, 0xa, 0xc, 0x3, 0xc, 0x3, 0xc, 0x5, 0xc, 0x9b, 0xa, 
    0xc, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x5, 0xd, 0xa1, 0xa, 0xd, 
    0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xe, 0x3, 0xe, 0x3, 0xf, 0x3, 0xf, 
    0x3, 0xf, 0x7, 0xf, 0xab, 0xa, 0xf, 0xc, 0xf, 0xe, 0xf, 0xae, 0xb, 0xf, 
    0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x5, 0x10, 0xb3, 0xa, 0x10, 0x3, 0x11, 
    0x3, 0x11, 0x7, 0x11, 0xb7, 0xa, 0x11, 0xc, 0x11, 0xe, 0x11, 0xba, 0xb, 
    0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x12, 0x3, 0x12, 0x5, 0x12, 0xc0, 0xa, 
    0x12, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 
    0x5, 0x13, 0xc8, 0xa, 0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 
    0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 
    0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 
    0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x5, 
    0x13, 0xe1, 0xa, 0x13, 0x3, 0x13, 0x5, 0x13, 0xe4, 0xa, 0x13, 0x3, 0x14, 
    0x3, 0x14, 0x3, 0x14, 0x3, 0x15, 0x3, 0x15, 0x5, 0x15, 0xeb, 0xa, 0x15, 
    0x3, 0x16, 0x3, 0x16, 0x3, 0x17, 0x3, 0x17, 0x3, 0x18, 0x3, 0x18, 0x3, 
    0x19, 0x3, 0x19, 0x3, 0x19, 0x3, 0x19, 0x3, 0x19, 0x5, 0x19, 0xf8, 0xa, 
    0x19, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 
    0x5, 0x1a, 0x100, 0xa, 0x1a, 0x3, 0x1b, 0x3, 0x1b, 0x3, 0x1c, 0x3, 0x1c, 
    0x3, 0x1c, 0x3, 0x1c, 0x5, 0x1c, 0x108, 0xa, 0x1c, 0x3, 0x1c, 0x3, 0x1c, 
    0x3, 0x1c, 0x3, 0x1c, 0x5, 0x1c, 0x10e, 0xa, 0x1c, 0x3, 0x1d, 0x3, 0x1d, 
    0x3, 0x1e, 0x3, 0x1e, 0x3, 0x1e, 0x7, 0x1e, 0x115, 0xa, 0x1e, 0xc, 0x1e, 
    0xe, 0x1e, 0x118, 0xb, 0x1e, 0x3, 0x1f, 0x3, 0x1f, 0x3, 0x1f, 0x3, 0x1f, 
    0x3, 0x1f, 0x3, 0x1f, 0x7, 0x1f, 0x120, 0xa, 0x1f, 0xc, 0x1f, 0xe, 0x1f, 
    0x123, 0xb, 0x1f, 0x3, 0x20, 0x3, 0x20, 0x3, 0x20, 0x3, 0x20, 0x3, 0x20, 
    0x3, 0x20, 0x7, 0x20, 0x12b, 0xa, 0x20, 0xc, 0x20, 0xe, 0x20, 0x12e, 
    0xb, 0x20, 0x3, 0x21, 0x3, 0x21, 0x3, 0x21, 0x5, 0x21, 0x133, 0xa, 0x21, 
    0x3, 0x21, 0x3, 0x21, 0x3, 0x21, 0x7, 0x21, 0x138, 0xa, 0x21, 0xc, 0x21, 
    0xe, 0x21, 0x13b, 0xb, 0x21, 0x3, 0x22, 0x3, 0x22, 0x3, 0x22, 0x3, 0x22, 
    0x3, 0x22, 0x3, 0x22, 0x7, 0x22, 0x143, 0xa, 0x22, 0xc, 0x22, 0xe, 0x22, 
    0x146, 0xb, 0x22, 0x3, 0x23, 0x3, 0x23, 0x3, 0x23, 0x3, 0x23, 0x3, 0x23, 
    0x3, 0x23, 0x7, 0x23, 0x14e, 0xa, 0x23, 0xc, 0x23, 0xe, 0x23, 0x151, 
    0xb, 0x23, 0x3, 0x24, 0x3, 0x24, 0x3, 0x24, 0x3, 0x24, 0x3, 0x24, 0x3, 
    0x24, 0x7, 0x24, 0x159, 0xa, 0x24, 0xc, 0x24, 0xe, 0x24, 0x15c, 0xb, 
    0x24, 0x3, 0x25, 0x3, 0x25, 0x5, 0x25, 0x160, 0xa, 0x25, 0x3, 0x25, 
    0x2, 0x8, 0x3c, 0x3e, 0x40, 0x42, 0x44, 0x46, 0x26, 0x2, 0x4, 0x6, 0x8, 
    0xa, 0xc, 0xe, 0x10, 0x12, 0x14, 0x16, 0x18, 0x1a, 0x1c, 0x1e, 0x20, 
    0x22, 0x24, 0x26, 0x28, 0x2a, 0x2c, 0x2e, 0x30, 0x32, 0x34, 0x36, 0x38, 
    0x3a, 0x3c, 0x3e, 0x40, 0x42, 0x44, 0x46, 0x48, 0x2, 0xa, 0x3, 0x2, 
    0x6, 0x9, 0x4, 0x2, 0x6, 0x9, 0x11, 0x11, 0x4, 0x2, 0x26, 0x26, 0x2b, 
    0x2c, 0x4, 0x2, 0x18, 0x19, 0x1d, 0x1d, 0x3, 0x2, 0x1a, 0x1c, 0x3, 0x2, 
    0x18, 0x19, 0x3, 0x2, 0x20, 0x23, 0x3, 0x2, 0x1e, 0x1f, 0x2, 0x168, 
    0x2, 0x4b, 0x3, 0x2, 0x2, 0x2, 0x4, 0x51, 0x3, 0x2, 0x2, 0x2, 0x6, 0x57, 
    0x3, 0x2, 0x2, 0x2, 0x8, 0x59, 0x3, 0x2, 0x2, 0x2, 0xa, 0x65, 0x3, 0x2, 
    0x2, 0x2, 0xc, 0x67, 0x3, 0x2, 0x2, 0x2, 0xe, 0x6d, 0x3, 0x2, 0x2, 0x2, 
    0x10, 0x77, 0x3, 0x2, 0x2, 0x2, 0x12, 0x81, 0x3, 0x2, 0x2, 0x2, 0x14, 
    0x85, 0x3, 0x2, 0x2, 0x2, 0x16, 0x9a, 0x3, 0x2, 0x2, 0x2, 0x18, 0x9c, 
    0x3, 0x2, 0x2, 0x2, 0x1a, 0xa5, 0x3, 0x2, 0x2, 0x2, 0x1c, 0xa7, 0x3, 
    0x2, 0x2, 0x2, 0x1e, 0xaf, 0x3, 0x2, 0x2, 0x2, 0x20, 0xb4, 0x3, 0x2, 
    0x2, 0x2, 0x22, 0xbf, 0x3, 0x2, 0x2, 0x2, 0x24, 0xe3, 0x3, 0x2, 0x2, 
    0x2, 0x26, 0xe5, 0x3, 0x2, 0x2, 0x2, 0x28, 0xea, 0x3, 0x2, 0x2, 0x2, 
    0x2a, 0xec, 0x3, 0x2, 0x2, 0x2, 0x2c, 0xee, 0x3, 0x2, 0x2, 0x2, 0x2e, 
    0xf0, 0x3, 0x2, 0x2, 0x2, 0x30, 0xf2, 0x3, 0x2, 0x2, 0x2, 0x32, 0xff, 
    0x3, 0x2, 0x2, 0x2, 0x34, 0x101, 0x3, 0x2, 0x2, 0x2, 0x36, 0x10d, 0x3, 
    0x2, 0x2, 0x2, 0x38, 0x10f, 0x3, 0x2, 0x2, 0x2, 0x3a, 0x111, 0x3, 0x2, 
    0x2, 0x2, 0x3c, 0x119, 0x3, 0x2, 0x2, 0x2, 0x3e, 0x124, 0x3, 0x2, 0x2, 
    0x2, 0x40, 0x132, 0x3, 0x2, 0x2, 0x2, 0x42, 0x13c, 0x3, 0x2, 0x2, 0x2, 
    0x44, 0x147, 0x3, 0x2, 0x2, 0x2, 0x46, 0x152, 0x3, 0x2, 0x2, 0x2, 0x48, 
    0x15f, 0x3, 0x2, 0x2, 0x2, 0x4a, 0x4c, 0x5, 0x4, 0x3, 0x2, 0x4b, 0x4a, 
    0x3, 0x2, 0x2, 0x2, 0x4b, 0x4c, 0x3, 0x2, 0x2, 0x2, 0x4c, 0x4d, 0x3, 
    0x2, 0x2, 0x2, 0x4d, 0x4e, 0x7, 0x2, 0x2, 0x3, 0x4e, 0x3, 0x3, 0x2, 
    0x2, 0x2, 0x4f, 0x52, 0x5, 0x6, 0x4, 0x2, 0x50, 0x52, 0x5, 0x18, 0xd, 
    0x2, 0x51, 0x4f, 0x3, 0x2, 0x2, 0x2, 0x51, 0x50, 0x3, 0x2, 0x2, 0x2, 
    0x52, 0x53, 0x3, 0x2, 0x2, 0x2, 0x53, 0x51, 0x3, 0x2, 0x2, 0x2, 0x53, 
    0x54, 0x3, 0x2, 0x2, 0x2, 0x54, 0x5, 0x3, 0x2, 0x2, 0x2, 0x55, 0x58, 
    0x5, 0x8, 0x5, 0x2, 0x56, 0x58, 0x5, 0x14, 0xb, 0x2, 0x57, 0x55, 0x3, 
    0x2, 0x2, 0x2, 0x57, 0x56, 0x3, 0x2, 0x2, 0x2, 0x58, 0x7, 0x3, 0x2, 
    0x2, 0x2, 0x59, 0x5a, 0x7, 0x3, 0x2, 0x2, 0x5a, 0x5b, 0x5, 0xa, 0x6, 
    0x2, 0x5b, 0x60, 0x5, 0xe, 0x8, 0x2, 0x5c, 0x5d, 0x7, 0x4, 0x2, 0x2, 
    0x5d, 0x5f, 0x5, 0xe, 0x8, 0x2, 0x5e, 0x5c, 0x3, 0x2, 0x2, 0x2, 0x5f, 
    0x62, 0x3, 0x2, 0x2, 0x2, 0x60, 0x5e, 0x3, 0x2, 0x2, 0x2, 0x60, 0x61, 
    0x3, 0x2, 0x2, 0x2, 0x61, 0x63, 0x3, 0x2, 0x2, 0x2, 0x62, 0x60, 0x3, 
    0x2, 0x2, 0x2, 0x63, 0x64, 0x7, 0x5, 0x2, 0x2, 0x64, 0x9, 0x3, 0x2, 
    0x2, 0x2, 0x65, 0x66, 0x9, 0x2, 0x2, 0x2, 0x66, 0xb, 0x3, 0x2, 0x2, 
    0x2, 0x67, 0x69, 0x7, 0xa, 0x2, 0x2, 0x68, 0x6a, 0x7, 0x26, 0x2, 0x2, 
    0x69, 0x68, 0x3, 0x2, 0x2, 0x2, 0x69, 0x6a, 0x3, 0x2, 0x2, 0x2, 0x6a, 
    0x6b, 0x3, 0x2, 0x2, 0x2, 0x6b, 0x6c, 0x7, 0xb, 0x2, 0x2, 0x6c, 0xd, 
    0x3, 0x2, 0x2, 0x2, 0x6d, 0x6f, 0x7, 0x17, 0x2, 0x2, 0x6e, 0x70, 0x5, 
    0xc, 0x7, 0x2, 0x6f, 0x6e, 0x3, 0x2, 0x2, 0x2, 0x6f, 0x70, 0x3, 0x2, 
    0x2, 0x2, 0x70, 0x71, 0x3, 0x2, 0x2, 0x2, 0x71, 0x72, 0x7, 0xc, 0x2, 
    0x2, 0x72, 0x73, 0x5, 0x10, 0x9, 0x2, 0x73, 0xf, 0x3, 0x2, 0x2, 0x2, 
    0x74, 0x78, 0x5, 0x48, 0x25, 0x2, 0x75, 0x76, 0x7, 0xd, 0x2, 0x2, 0x76, 
    0x78, 0x5, 0x12, 0xa, 0x2, 0x77, 0x74, 0x3, 0x2, 0x2, 0x2, 0x77, 0x75, 
    0x3, 0x2, 0x2, 0x2, 0x78, 0x11, 0x3, 0x2, 0x2, 0x2, 0x79, 0x7e, 0x5, 
    0x48, 0x25, 0x2, 0x7a, 0x7b, 0x7, 0x4, 0x2, 0x2, 0x7b, 0x7d, 0x5, 0x48, 
    0x25, 0x2, 0x7c, 0x7a, 0x3, 0x2, 0x2, 0x2, 0x7d, 0x80, 0x3, 0x2, 0x2, 
    0x2, 0x7e, 0x7c, 0x3, 0x2, 0x2, 0x2, 0x7e, 0x7f, 0x3, 0x2, 0x2, 0x2, 
    0x7f, 0x82, 0x3, 0x2, 0x2, 0x2, 0x80, 0x7e, 0x3, 0x2, 0x2, 0x2, 0x81, 
    0x79, 0x3, 0x2, 0x2, 0x2, 0x81, 0x82, 0x3, 0x2, 0x2, 0x2, 0x82, 0x83, 
    0x3, 0x2, 0x2, 0x2, 0x83, 0x84, 0x7, 0xe, 0x2, 0x2, 0x84, 0x13, 0x3, 
    0x2, 0x2, 0x2, 0x85, 0x86, 0x5, 0xa, 0x6, 0x2, 0x86, 0x8b, 0x5, 0x16, 
    0xc, 0x2, 0x87, 0x88, 0x7, 0x4, 0x2, 0x2, 0x88, 0x8a, 0x5, 0x16, 0xc, 
    0x2, 0x89, 0x87, 0x3, 0x2, 0x2, 0x2, 0x8a, 0x8d, 0x3, 0x2, 0x2, 0x2, 
    0x8b, 0x89, 0x3, 0x2, 0x2, 0x2, 0x8b, 0x8c, 0x3, 0x2, 0x2, 0x2, 0x8c, 
    0x8e, 0x3, 0x2, 0x2, 0x2, 0x8d, 0x8b, 0x3, 0x2, 0x2, 0x2, 0x8e, 0x8f, 
    0x7, 0x5, 0x2, 0x2, 0x8f, 0x15, 0x3, 0x2, 0x2, 0x2, 0x90, 0x92, 0x7, 
    0x17, 0x2, 0x2, 0x91, 0x93, 0x5, 0xc, 0x7, 0x2, 0x92, 0x91, 0x3, 0x2, 
    0x2, 0x2, 0x92, 0x93, 0x3, 0x2, 0x2, 0x2, 0x93, 0x9b, 0x3, 0x2, 0x2, 
    0x2, 0x94, 0x96, 0x7, 0x17, 0x2, 0x2, 0x95, 0x97, 0x5, 0xc, 0x7, 0x2, 
    0x96, 0x95, 0x3, 0x2, 0x2, 0x2, 0x96, 0x97, 0x3, 0x2, 0x2, 0x2, 0x97, 
    0x98, 0x3, 0x2, 0x2, 0x2, 0x98, 0x99, 0x7, 0xc, 0x2, 0x2, 0x99, 0x9b, 
    0x5, 0x10, 0x9, 0x2, 0x9a, 0x90, 0x3, 0x2, 0x2, 0x2, 0x9a, 0x94, 0x3, 
    0x2, 0x2, 0x2, 0x9b, 0x17, 0x3, 0x2, 0x2, 0x2, 0x9c, 0x9d, 0x5, 0x1a, 
    0xe, 0x2, 0x9d, 0x9e, 0x7, 0x17, 0x2, 0x2, 0x9e, 0xa0, 0x7, 0xf, 0x2, 
    0x2, 0x9f, 0xa1, 0x5, 0x1c, 0xf, 0x2, 0xa0, 0x9f, 0x3, 0x2, 0x2, 0x2, 
    0xa0, 0xa1, 0x3, 0x2, 0x2, 0x2, 0xa1, 0xa2, 0x3, 0x2, 0x2, 0x2, 0xa2, 
    0xa3, 0x7, 0x10, 0x2, 0x2, 0xa3, 0xa4, 0x5, 0x20, 0x11, 0x2, 0xa4, 0x19, 
    0x3, 0x2, 0x2, 0x2, 0xa5, 0xa6, 0x9, 0x3, 0x2, 0x2, 0xa6, 0x1b, 0x3, 
    0x2, 0x2, 0x2, 0xa7, 0xac, 0x5, 0x1e, 0x10, 0x2, 0xa8, 0xa9, 0x7, 0x4, 
    0x2, 0x2, 0xa9, 0xab, 0x5, 0x1e, 0x10, 0x2, 0xaa, 0xa8, 0x3, 0x2, 0x2, 
    0x2, 0xab, 0xae, 0x3, 0x2, 0x2, 0x2, 0xac, 0xaa, 0x3, 0x2, 0x2, 0x2, 
    0xac, 0xad, 0x3, 0x2, 0x2, 0x2, 0xad, 0x1d, 0x3, 0x2, 0x2, 0x2, 0xae, 
    0xac, 0x3, 0x2, 0x2, 0x2, 0xaf, 0xb0, 0x5, 0xa, 0x6, 0x2, 0xb0, 0xb2, 
    0x7, 0x17, 0x2, 0x2, 0xb1, 0xb3, 0x5, 0xc, 0x7, 0x2, 0xb2, 0xb1, 0x3, 
    0x2, 0x2, 0x2, 0xb2, 0xb3, 0x3, 0x2, 0x2, 0x2, 0xb3, 0x1f, 0x3, 0x2, 
    0x2, 0x2, 0xb4, 0xb8, 0x7, 0xd, 0x2, 0x2, 0xb5, 0xb7, 0x5, 0x22, 0x12, 
    0x2, 0xb6, 0xb5, 0x3, 0x2, 0x2, 0x2, 0xb7, 0xba, 0x3, 0x2, 0x2, 0x2, 
    0xb8, 0xb6, 0x3, 0x2, 0x2, 0x2, 0xb8, 0xb9, 0x3, 0x2, 0x2, 0x2, 0xb9, 
    0xbb, 0x3, 0x2, 0x2, 0x2, 0xba, 0xb8, 0x3, 0x2, 0x2, 0x2, 0xbb, 0xbc, 
    0x7, 0xe, 0x2, 0x2, 0xbc, 0x21, 0x3, 0x2, 0x2, 0x2, 0xbd, 0xc0, 0x5, 
    0x6, 0x4, 0x2, 0xbe, 0xc0, 0x5, 0x24, 0x13, 0x2, 0xbf, 0xbd, 0x3, 0x2, 
    0x2, 0x2, 0xbf, 0xbe, 0x3, 0x2, 0x2, 0x2, 0xc0, 0x23, 0x3, 0x2, 0x2, 
    0x2, 0xc1, 0xc2, 0x5, 0x30, 0x19, 0x2, 0xc2, 0xc3, 0x7, 0xc, 0x2, 0x2, 
    0xc3, 0xc4, 0x5, 0x28, 0x15, 0x2, 0xc4, 0xc5, 0x7, 0x5, 0x2, 0x2, 0xc5, 
    0xe4, 0x3, 0x2, 0x2, 0x2, 0xc6, 0xc8, 0x5, 0x28, 0x15, 0x2, 0xc7, 0xc6, 
    0x3, 0x2, 0x2, 0x2, 0xc7, 0xc8, 0x3, 0x2, 0x2, 0x2, 0xc8, 0xc9, 0x3, 
    0x2, 0x2, 0x2, 0xc9, 0xe4, 0x7, 0x5, 0x2, 0x2, 0xca, 0xe4, 0x5, 0x20, 
    0x11, 0x2, 0xcb, 0xcc, 0x7, 0x12, 0x2, 0x2, 0xcc, 0xcd, 0x7, 0xf, 0x2, 
    0x2, 0xcd, 0xce, 0x5, 0x2c, 0x17, 0x2, 0xce, 0xcf, 0x7, 0x10, 0x2, 0x2, 
    0xcf, 0xd0, 0x5, 0x24, 0x13, 0x2, 0xd0, 0xd1, 0x5, 0x26, 0x14, 0x2, 
    0xd1, 0xe4, 0x3, 0x2, 0x2, 0x2, 0xd2, 0xd3, 0x7, 0x12, 0x2, 0x2, 0xd3, 
    0xd4, 0x7, 0xf, 0x2, 0x2, 0xd4, 0xd5, 0x5, 0x2c, 0x17, 0x2, 0xd5, 0xd6, 
    0x7, 0x10, 0x2, 0x2, 0xd6, 0xd7, 0x5, 0x24, 0x13, 0x2, 0xd7, 0xe4, 0x3, 
    0x2, 0x2, 0x2, 0xd8, 0xd9, 0x7, 0x13, 0x2, 0x2, 0xd9, 0xda, 0x7, 0xf, 
    0x2, 0x2, 0xda, 0xdb, 0x5, 0x2e, 0x18, 0x2, 0xdb, 0xdc, 0x7, 0x10, 0x2, 
    0x2, 0xdc, 0xdd, 0x5, 0x24, 0x13, 0x2, 0xdd, 0xe4, 0x3, 0x2, 0x2, 0x2, 
    0xde, 0xe0, 0x7, 0x14, 0x2, 0x2, 0xdf, 0xe1, 0x5, 0x28, 0x15, 0x2, 0xe0, 
    0xdf, 0x3, 0x2, 0x2, 0x2, 0xe0, 0xe1, 0x3, 0x2, 0x2, 0x2, 0xe1, 0xe2, 
    0x3, 0x2, 0x2, 0x2, 0xe2, 0xe4, 0x7, 0x5, 0x2, 0x2, 0xe3, 0xc1, 0x3, 
    0x2, 0x2, 0x2, 0xe3, 0xc7, 0x3, 0x2, 0x2, 0x2, 0xe3, 0xca, 0x3, 0x2, 
    0x2, 0x2, 0xe3, 0xcb, 0x3, 0x2, 0x2, 0x2, 0xe3, 0xd2, 0x3, 0x2, 0x2, 
    0x2, 0xe3, 0xd8, 0x3, 0x2, 0x2, 0x2, 0xe3, 0xde, 0x3, 0x2, 0x2, 0x2, 
    0xe4, 0x25, 0x3, 0x2, 0x2, 0x2, 0xe5, 0xe6, 0x7, 0x15, 0x2, 0x2, 0xe6, 
    0xe7, 0x5, 0x24, 0x13, 0x2, 0xe7, 0x27, 0x3, 0x2, 0x2, 0x2, 0xe8, 0xeb, 
    0x5, 0x3e, 0x20, 0x2, 0xe9, 0xeb, 0x7, 0x16, 0x2, 0x2, 0xea, 0xe8, 0x3, 
    0x2, 0x2, 0x2, 0xea, 0xe9, 0x3, 0x2, 0x2, 0x2, 0xeb, 0x29, 0x3, 0x2, 
    0x2, 0x2, 0xec, 0xed, 0x5, 0x46, 0x24, 0x2, 0xed, 0x2b, 0x3, 0x2, 0x2, 
    0x2, 0xee, 0xef, 0x5, 0x2a, 0x16, 0x2, 0xef, 0x2d, 0x3, 0x2, 0x2, 0x2, 
    0xf0, 0xf1, 0x5, 0x2a, 0x16, 0x2, 0xf1, 0x2f, 0x3, 0x2, 0x2, 0x2, 0xf2, 
    0xf7, 0x7, 0x17, 0x2, 0x2, 0xf3, 0xf4, 0x7, 0xa, 0x2, 0x2, 0xf4, 0xf5, 
    0x5, 0x28, 0x15, 0x2, 0xf5, 0xf6, 0x7, 0xb, 0x2, 0x2, 0xf6, 0xf8, 0x3, 
    0x2, 0x2, 0x2, 0xf7, 0xf3, 0x3, 0x2, 0x2, 0x2, 0xf7, 0xf8, 0x3, 0x2, 
    0x2, 0x2, 0xf8, 0x31, 0x3, 0x2, 0x2, 0x2, 0xf9, 0xfa, 0x7, 0xf, 0x2, 
    0x2, 0xfa, 0xfb, 0x5, 0x28, 0x15, 0x2, 0xfb, 0xfc, 0x7, 0x10, 0x2, 0x2, 
    0xfc, 0x100, 0x3, 0x2, 0x2, 0x2, 0xfd, 0x100, 0x5, 0x30, 0x19, 0x2, 
    0xfe, 0x100, 0x5, 0x34, 0x1b, 0x2, 0xff, 0xf9, 0x3, 0x2, 0x2, 0x2, 0xff, 
    0xfd, 0x3, 0x2, 0x2, 0x2, 0xff, 0xfe, 0x3, 0x2, 0x2, 0x2, 0x100, 0x33, 
    0x3, 0x2, 0x2, 0x2, 0x101, 0x102, 0x9, 0x4, 0x2, 0x2, 0x102, 0x35, 0x3, 
    0x2, 0x2, 0x2, 0x103, 0x10e, 0x5, 0x32, 0x1a, 0x2, 0x104, 0x105, 0x7, 
    0x17, 0x2, 0x2, 0x105, 0x107, 0x7, 0xf, 0x2, 0x2, 0x106, 0x108, 0x5, 
    0x3a, 0x1e, 0x2, 0x107, 0x106, 0x3, 0x2, 0x2, 0x2, 0x107, 0x108, 0x3, 
    0x2, 0x2, 0x2, 0x108, 0x109, 0x3, 0x2, 0x2, 0x2, 0x109, 0x10e, 0x7, 
    0x10, 0x2, 0x2, 0x10a, 0x10b, 0x5, 0x38, 0x1d, 0x2, 0x10b, 0x10c, 0x5, 
    0x36, 0x1c, 0x2, 0x10c, 0x10e, 0x3, 0x2, 0x2, 0x2, 0x10d, 0x103, 0x3, 
    0x2, 0x2, 0x2, 0x10d, 0x104, 0x3, 0x2, 0x2, 0x2, 0x10d, 0x10a, 0x3, 
    0x2, 0x2, 0x2, 0x10e, 0x37, 0x3, 0x2, 0x2, 0x2, 0x10f, 0x110, 0x9, 0x5, 
    0x2, 0x2, 0x110, 0x39, 0x3, 0x2, 0x2, 0x2, 0x111, 0x116, 0x5, 0x28, 
    0x15, 0x2, 0x112, 0x113, 0x7, 0x4, 0x2, 0x2, 0x113, 0x115, 0x5, 0x28, 
    0x15, 0x2, 0x114, 0x112, 0x3, 0x2, 0x2, 0x2, 0x115, 0x118, 0x3, 0x2, 
    0x2, 0x2, 0x116, 0x114, 0x3, 0x2, 0x2, 0x2, 0x116, 0x117, 0x3, 0x2, 
    0x2, 0x2, 0x117, 0x3b, 0x3, 0x2, 0x2, 0x2, 0x118, 0x116, 0x3, 0x2, 0x2, 
    0x2, 0x119, 0x11a, 0x8, 0x1f, 0x1, 0x2, 0x11a, 0x11b, 0x5, 0x36, 0x1c, 
    0x2, 0x11b, 0x121, 0x3, 0x2, 0x2, 0x2, 0x11c, 0x11d, 0xc, 0x3, 0x2, 
    0x2, 0x11d, 0x11e, 0x9, 0x6, 0x2, 0x2, 0x11e, 0x120, 0x5, 0x36, 0x1c, 
    0x2, 0x11f, 0x11c, 0x3, 0x2, 0x2, 0x2, 0x120, 0x123, 0x3, 0x2, 0x2, 
    0x2, 0x121, 0x11f, 0x3, 0x2, 0x2, 0x2, 0x121, 0x122, 0x3, 0x2, 0x2, 
    0x2, 0x122, 0x3d, 0x3, 0x2, 0x2, 0x2, 0x123, 0x121, 0x3, 0x2, 0x2, 0x2, 
    0x124, 0x125, 0x8, 0x20, 0x1, 0x2, 0x125, 0x126, 0x5, 0x3c, 0x1f, 0x2, 
    0x126, 0x12c, 0x3, 0x2, 0x2, 0x2, 0x127, 0x128, 0xc, 0x3, 0x2, 0x2, 
    0x128, 0x129, 0x9, 0x7, 0x2, 0x2, 0x129, 0x12b, 0x5, 0x3c, 0x1f, 0x2, 
    0x12a, 0x127, 0x3, 0x2, 0x2, 0x2, 0x12b, 0x12e, 0x3, 0x2, 0x2, 0x2, 
    0x12c, 0x12a, 0x3, 0x2, 0x2, 0x2, 0x12c, 0x12d, 0x3, 0x2, 0x2, 0x2, 
    0x12d, 0x3f, 0x3, 0x2, 0x2, 0x2, 0x12e, 0x12c, 0x3, 0x2, 0x2, 0x2, 0x12f, 
    0x130, 0x8, 0x21, 0x1, 0x2, 0x130, 0x133, 0x5, 0x3e, 0x20, 0x2, 0x131, 
    0x133, 0x7, 0x16, 0x2, 0x2, 0x132, 0x12f, 0x3, 0x2, 0x2, 0x2, 0x132, 
    0x131, 0x3, 0x2, 0x2, 0x2, 0x133, 0x139, 0x3, 0x2, 0x2, 0x2, 0x134, 
    0x135, 0xc, 0x4, 0x2, 0x2, 0x135, 0x136, 0x9, 0x8, 0x2, 0x2, 0x136, 
    0x138, 0x5, 0x3e, 0x20, 0x2, 0x137, 0x134, 0x3, 0x2, 0x2, 0x2, 0x138, 
    0x13b, 0x3, 0x2, 0x2, 0x2, 0x139, 0x137, 0x3, 0x2, 0x2, 0x2, 0x139, 
    0x13a, 0x3, 0x2, 0x2, 0x2, 0x13a, 0x41, 0x3, 0x2, 0x2, 0x2, 0x13b, 0x139, 
    0x3, 0x2, 0x2, 0x2, 0x13c, 0x13d, 0x8, 0x22, 0x1, 0x2, 0x13d, 0x13e, 
    0x5, 0x40, 0x21, 0x2, 0x13e, 0x144, 0x3, 0x2, 0x2, 0x2, 0x13f, 0x140, 
    0xc, 0x3, 0x2, 0x2, 0x140, 0x141, 0x9, 0x9, 0x2, 0x2, 0x141, 0x143, 
    0x5, 0x40, 0x21, 0x2, 0x142, 0x13f, 0x3, 0x2, 0x2, 0x2, 0x143, 0x146, 
    0x3, 0x2, 0x2, 0x2, 0x144, 0x142, 0x3, 0x2, 0x2, 0x2, 0x144, 0x145, 
    0x3, 0x2, 0x2, 0x2, 0x145, 0x43, 0x3, 0x2, 0x2, 0x2, 0x146, 0x144, 0x3, 
    0x2, 0x2, 0x2, 0x147, 0x148, 0x8, 0x23, 0x1, 0x2, 0x148, 0x149, 0x5, 
    0x42, 0x22, 0x2, 0x149, 0x14f, 0x3, 0x2, 0x2, 0x2, 0x14a, 0x14b, 0xc, 
    0x3, 0x2, 0x2, 0x14b, 0x14c, 0x7, 0x24, 0x2, 0x2, 0x14c, 0x14e, 0x5, 
    0x42, 0x22, 0x2, 0x14d, 0x14a, 0x3, 0x2, 0x2, 0x2, 0x14e, 0x151, 0x3, 
    0x2, 0x2, 0x2, 0x14f, 0x14d, 0x3, 0x2, 0x2, 0x2, 0x14f, 0x150, 0x3, 
    0x2, 0x2, 0x2, 0x150, 0x45, 0x3, 0x2, 0x2, 0x2, 0x151, 0x14f, 0x3, 0x2, 
    0x2, 0x2, 0x152, 0x153, 0x8, 0x24, 0x1, 0x2, 0x153, 0x154, 0x5, 0x44, 
    0x23, 0x2, 0x154, 0x15a, 0x3, 0x2, 0x2, 0x2, 0x155, 0x156, 0xc, 0x3, 
    0x2, 0x2, 0x156, 0x157, 0x7, 0x25, 0x2, 0x2, 0x157, 0x159, 0x5, 0x44, 
    0x23, 0x2, 0x158, 0x155, 0x3, 0x2, 0x2, 0x2, 0x159, 0x15c, 0x3, 0x2, 
    0x2, 0x2, 0x15a, 0x158, 0x3, 0x2, 0x2, 0x2, 0x15a, 0x15b, 0x3, 0x2, 
    0x2, 0x2, 0x15b, 0x47, 0x3, 0x2, 0x2, 0x2, 0x15c, 0x15a, 0x3, 0x2, 0x2, 
    0x2, 0x15d, 0x160, 0x5, 0x34, 0x1b, 0x2, 0x15e, 0x160, 0x7, 0x16, 0x2, 
    0x2, 0x15f, 0x15d, 0x3, 0x2, 0x2, 0x2, 0x15f, 0x15e, 0x3, 0x2, 0x2, 
    0x2, 0x160, 0x49, 0x3, 0x2, 0x2, 0x2, 0x26, 0x4b, 0x51, 0x53, 0x57, 
    0x60, 0x69, 0x6f, 0x77, 0x7e, 0x81, 0x8b, 0x92, 0x96, 0x9a, 0xa0, 0xac, 
    0xb2, 0xb8, 0xbf, 0xc7, 0xe0, 0xe3, 0xea, 0xf7, 0xff, 0x107, 0x10d, 
    0x116, 0x121, 0x12c, 0x132, 0x139, 0x144, 0x14f, 0x15a, 0x15f, 
  };

  atn::ATNDeserializer deserializer;
  _atn = deserializer.deserialize(_serializedATN);

  size_t count = _atn.getNumberOfDecisions();
  _decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    _decisionToDFA.emplace_back(_atn.getDecisionState(i), i);
  }
}

CACTParser::Initializer CACTParser::_init;
