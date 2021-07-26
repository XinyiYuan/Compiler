
    #include <vector>
    #include <string>


// Generated from ./grammar/CACT.g4 by ANTLR 4.8

#pragma once


#include "antlr4-runtime.h"




class  CACTLexer : public antlr4::Lexer {
public:
  enum {
    T__0 = 1, T__1 = 2, T__2 = 3, T__3 = 4, T__4 = 5, T__5 = 6, T__6 = 7, 
    T__7 = 8, T__8 = 9, T__9 = 10, T__10 = 11, T__11 = 12, T__12 = 13, T__13 = 14, 
    T__14 = 15, T__15 = 16, T__16 = 17, T__17 = 18, T__18 = 19, BoolConst = 20, 
    Ident = 21, ADD = 22, SUB = 23, MUL = 24, DIV = 25, MOD = 26, NOT = 27, 
    NE = 28, EQ = 29, GT = 30, LT = 31, GE = 32, LE = 33, AND = 34, OR = 35, 
    IntConst = 36, NewLine = 37, WhiteSpace = 38, BlockComment = 39, LineComment = 40, 
    FloatConst = 41, DoubleConst = 42, DecimalFloatConst = 43, FracConst = 44, 
    ExpPart = 45, DigitSeq = 46
  };

  CACTLexer(antlr4::CharStream *input);
  ~CACTLexer();

  virtual std::string getGrammarFileName() const override;
  virtual const std::vector<std::string>& getRuleNames() const override;

  virtual const std::vector<std::string>& getChannelNames() const override;
  virtual const std::vector<std::string>& getModeNames() const override;
  virtual const std::vector<std::string>& getTokenNames() const override; // deprecated, use vocabulary instead
  virtual antlr4::dfa::Vocabulary& getVocabulary() const override;

  virtual const std::vector<uint16_t> getSerializedATN() const override;
  virtual const antlr4::atn::ATN& getATN() const override;

private:
  static std::vector<antlr4::dfa::DFA> _decisionToDFA;
  static antlr4::atn::PredictionContextCache _sharedContextCache;
  static std::vector<std::string> _ruleNames;
  static std::vector<std::string> _tokenNames;
  static std::vector<std::string> _channelNames;
  static std::vector<std::string> _modeNames;

  static std::vector<std::string> _literalNames;
  static std::vector<std::string> _symbolicNames;
  static antlr4::dfa::Vocabulary _vocabulary;
  static antlr4::atn::ATN _atn;
  static std::vector<uint16_t> _serializedATN;


  // Individual action functions triggered by action() above.

  // Individual semantic predicate functions triggered by sempred() above.

  struct Initializer {
    Initializer();
  };
  static Initializer _init;
};

