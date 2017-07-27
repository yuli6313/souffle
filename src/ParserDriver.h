/*
 * Souffle - A Datalog Compiler
 * Copyright (c) 2015, Oracle and/or its affiliates. All rights reserved
 * Licensed under the Universal Permissive License v 1.0 as shown at:
 * - https://opensource.org/licenses/UPL
 * - <souffle root>/licenses/SOUFFLE-UPL.txt
 */

/************************************************************************
 *
 * @file ParserDriver.h
 *
 * Defines the parser driver.
 *
 ***********************************************************************/
#pragma once

#include "parser.hh"

#include <memory>

#define YY_DECL yy::parser::symbol_type yylex(ParserDriver& driver, yyscan_t yyscanner)
YY_DECL;

namespace souffle {

class AstTranslationUnit;
class ErrorReport;
class AstRelation;
class AstType;
class AstProgram;
class SymbolTable;

typedef void* yyscan_t;

struct scanner_data {
    AstSrcLocation yylloc;

    /* Stack of parsed files */
    const char* yyfilename;
};

class ParserDriver {
public:
    ParserDriver();
    virtual ~ParserDriver();

    std::unique_ptr<AstTranslationUnit> translationUnit;

    void addRelation(std::unique_ptr<AstRelation> r);
    void addIODirective(std::unique_ptr<AstIODirective> d);
    void addIODirectiveChain(std::unique_ptr<AstIODirective> d);
    void addType(std::unique_ptr<AstType> type);
    void addClause(std::unique_ptr<AstClause> c);
    void addComponent(std::unique_ptr<AstComponent> c);
    void addInstantiation(std::unique_ptr<AstComponentInit> ci);
    void addPragma(std::unique_ptr<AstPragma> p);

    souffle::SymbolTable& getSymbolTable();

    bool trace_scanning;

    std::unique_ptr<AstTranslationUnit> parse(const std::string& f, FILE* in, bool nowarn = false);
    std::unique_ptr<AstTranslationUnit> parse(const std::string& code, bool nowarn = false);
    static std::unique_ptr<AstTranslationUnit> parseTranslationUnit(
            const std::string& f, FILE* in, bool nowarn = false);
    static std::unique_ptr<AstTranslationUnit> parseTranslationUnit(
            const std::string& code, bool nowarn = false);

    bool trace_parsing;

    void error(const AstSrcLocation& loc, const std::string& msg);
    void error(const std::string& msg);
};

}  // end of namespace souffle
