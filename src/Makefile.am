# Souffle - A Datalog Compiler
# Copyright (c) 2013, Oracle and/or its affiliates. All rights reserved.
# Licensed under the Universal Permissive License v 1.0 as shown at:
# - https://opensource.org/licenses/UPL
# - <souffle root>/licenses/SOUFFLE-UPL.txt

SUFFIXES = .cpp .h .yy .ll .cc .hh .h

bin_PROGRAMS = souffle souffle-profile

nodist_souffle_profile_SOURCES = $(BUILT_SOURCES)

souffle_profile_sources = \
        ProfileDatabase.h                         \
        json11.h                                  \
        profile/Cell.h                            \
        profile/CellInterface.h                   \
        profile/Cli.h                             \
        profile/DataComparator.h                  \
        profile/Iteration.h                       \
        profile/OutputProcessor.h                 \
        profile/ProgramRun.h                      \
        profile/Reader.h                          \
        profile/Relation.h                        \
        profile/Row.h                             \
        profile/Rule.h                            \
        profile/StringUtils.h                     \
        profile/Table.h                           \
        profile/Tui.h                             \
        profile/UserInputReader.h                 \
        profile/htmlCssChartist.h                 \
        profile/htmlJsChartistMin.h               \
        profile/htmlJsMain.h                      \
        profile/htmlJsUtil.h                      \
        profile/htmlCssStyle.h                    \
        profile/htmlJsChartistPlugin.h            \
        profile/htmlJsTableSort.h                 \
        profile/htmlMain.h                        \
        profile/HtmlGenerator.h

souffle_swig_sources = \
        swig/SwigInterface.h                      \
        swig/SwigInterface.cpp                    \
        swig/SwigInterface.i

DIR := ${CURDIR}

# ... which should no go to distribution
nodist_souffle_SOURCES = $(BUILT_SOURCES)

if LIBZ
libz_sources = gzfstream.h
endif

if SQLITE
sqlite_sources = ReadStreamSQLite.h WriteStreamSQLite.h
endif


souffle_sources = \
        AstAbstract.h                             \
        AstAnalysis.h                             \
        AuxArityAnalysis.cpp  AuxArityAnalysis.h  \
        AstArgument.h                             \
        AstAttribute.h                            \
        AstClause.h                               \
        AstComponent.h                            \
        AstComponentChecker.cpp                   \
        AstComponentChecker.h                     \
        AstConstraintAnalysis.h                   \
        AstFunctorDeclaration.h                   \
        AstGroundAnalysis.cpp AstGroundAnalysis.h \
        AstIO.h                                   \
        AstIOTypeAnalysis.cpp AstIOTypeAnalysis.h \
        AstLiteral.h                              \
        AstNode.h                                 \
        AstParserUtils.cpp    AstParserUtils.h    \
        AstPragma.cpp         AstPragma.h         \
        AstProgram.h                              \
        AstProfileUse.cpp     AstProfileUse.h     \
        AstRelation.h                             \
        AstRelationIdentifier.h                   \
        AstSemanticChecker.cpp                    \
        AstSemanticChecker.h                      \
        AstTransformer.cpp    AstTransformer.h    \
        AstTransforms.cpp     AstTransforms.h     \
        AstTranslationUnit.h  ErrorReport.h       \
        AstTranslator.cpp     AstTranslator.h     \
        AstType.h                                 \
        AstTypeAnalysis.cpp   AstTypeAnalysis.h   \
        AstTypeEnvironmentAnalysis.cpp            \
        AstTypeEnvironmentAnalysis.h              \
        AstUtils.cpp          AstUtils.h          \
        AstVisitor.h                              \
        BinaryConstraintOps.h                     \
        ComponentModel.cpp    ComponentModel.h    \
        Constraints.h                             \
        DebugReport.cpp       DebugReport.h       \
        EventProcessor.h                          \
        FunctorOps.h                              \
        Global.cpp            Global.h            \
        GraphUtils.h                              \
        IODirectives.h                            \
        IOSystem.h                                \
        RamIndexAnalysis.cpp  RamIndexAnalysis.h  \
        InlineRelationsTransformer.cpp            \
        LogStatement.h                            \
        InterpreterIndex.h            InterpreterIndex.cpp	\
        InterpreterRelation.h         InterpreterRelation.cpp     \
        MagicSet.cpp          MagicSet.h          \
        MinimiseProgramTransformer.cpp            \
        ParserDriver.cpp      ParserDriver.h      \
        PrecedenceGraph.cpp   PrecedenceGraph.h   \
        ProfileEvent.h                            \
        ProvenanceTransformer.cpp                 \
        RamAnalysis.h                             \
        InterpreterContext.h                      \
        InterpreterEngine.cpp InterpreterEngine.h \
        InterpreterGenerator.h                    \
        InterpreterIndex.h                        \
        InterpreterNode.h		          \
        InterpreterProgInterface.h                \
        InterpreterPreamble.h			  \
        RecordTable.h                             \
        RamComplexityAnalysis.cpp  RamComplexityAnalysis.h  \
        RamLevelAnalysis.cpp  RamLevelAnalysis.h  \
        RamCondition.h                            \
        RamNode.h                                 \
        RamOperation.h                            \
        RamProgram.h                              \
        RamRelation.h                             \
        RamStatement.h                            \
        RamTransformer.cpp    RamTransformer.h    \
        RamTransforms.cpp     RamTransforms.h     \
        RamTranslationUnit.h                      \
        RamTypes.h                                \
        RamExpression.h                           \
        RamUtils.h                                \
        RamVisitor.h                              \
        ReadStream.h                              \
        ReadStreamCSV.h                           \
        RelationRepresentation.h                  \
        ReorderLiteralsTransformer.cpp            \
        ResolveAliasesTransformer.cpp             \
        SignalHandler.h                           \
        SrcLocation.cpp    SrcLocation.h          \
        Synthesiser.cpp       Synthesiser.h       \
        SynthesiserRelation.cpp                   \
        SynthesiserRelation.h                     \
        TypeSystem.cpp        TypeSystem.h        \
        WriteStream.h                             \
        WriteStreamCSV.h                          \
        parser.cc             parser.hh           \
        scanner.cc            stack.hh            \
        $(sqlite_sources)                         \
        $(libz_sources)                           \
        $(souffle_profile_sources)

# -- build souffle as a library so it can be reused in testing
noinst_LTLIBRARIES = libsouffle.la
libsouffle_la_SOURCES  = $(souffle_sources)
libsouffle_la_CXXFLAGS = $(souffle_CPPFLAGS) $(FFI_CFLAGS)
libsouffle_la_LDFLAGS = --static --dlopen --pic -ldl -lffi

souffle_SOURCES = main.cpp
souffle_LDADD = libsouffle.la

souffle_profile_SOURCES = souffle_prof.cpp
souffle_profile_CXXFLAGS = $(souffle_CPPFLAGS) -DMAKEDIR='"$(DIR)"'

dist_bin_SCRIPTS = souffle-compile souffle-config

EXTRA_DIST = parser.yy scanner.ll  test/test.h

soufflepublicdir = $(includedir)/souffle

soufflepublic_HEADERS = \
        CompiledOptions.h                         \
        BinaryConstraintOps.h                     \
        Brie.h                                    \
        BTree.h                                   \
        CompiledIndexUtils.h                      \
        CompiledSouffle.h                         \
        CompiledTuple.h                           \
        EventProcessor.h                          \
        Explain.h                                 \
        ExplainProvenance.h                       \
        ExplainProvenanceImpl.h                   \
        ExplainTree.h                             \
        EquivalenceRelation.h                     \
        IODirectives.h                            \
        IOSystem.h                                \
        IterUtils.h                               \
        LambdaBTree.h                             \
        Logger.h                                  \
        ParallelUtils.h                           \
        PiggyList.h                               \
        ProfileDatabase.h                         \
        ProfileEvent.h                            \
        RamTypes.h                                \
        ReadStream.h                              \
        ReadStreamCSV.h                           \
        RecordTable.h                             \
        SignalHandler.h                           \
        SouffleInterface.h                        \
        SymbolTable.h                             \
        Table.h                                   \
        UnionFind.h                               \
        Util.h                                    \
        WriteStream.h                             \
        WriteStreamCSV.h                          \
        json11.h                                  \
        $(libz_sources)                           \
        $(sqlite_sources)

souffleprofiledir = $(soufflepublicdir)/profile

souffleprofile_HEADERS = $(souffle_profile_sources)

souffleswigdir = $(soufflepublicdir)/swig

souffleswig_HEADERS = $(souffle_swig_sources)

# files to clean
CLEANFILES = $(BUILT_SOURCES)  parser.cc scanner.cc parser.hh stack.hh

# run Bison
$(builddir)/parser.hh: $(srcdir)/parser.yy
	$(BISON) -Wall -Werror -Wno-error=deprecated -Wno-error=other -v -d -o parser.cc $(srcdir)/parser.yy

# and FLEX
$(builddir)/scanner.cc: $(srcdir)/scanner.ll
	$(FLEX) -o scanner.cc $(srcdir)/scanner.ll

# driver depends on the generated header
$(builddir)/parser.cc $(builddir)/stack.hh $(builddir)/scanner.cc \
    $(builddir)/main.cpp $(builddir)/ParserDriver.cpp: $(builddir)/parser.hh

########## Unit Tests

AM_COLOR_TESTS=always

# -------------------------

# init check programs
check_PROGRAMS =

# profile utilities test
check_PROGRAMS += test/profile_util_test
test_profile_util_test_CXXFLAGS = $(souffle_CPPFLAGS) -I @abs_top_srcdir@/src/test
test_profile_util_test_SOURCES = test/profile_util_test.cpp
test_profile_util_test_LDADD = libsouffle.la

# utils test
check_PROGRAMS += test/util_test
test_util_test_CXXFLAGS = $(souffle_CPPFLAGS) -I @abs_top_srcdir@/src/test
test_util_test_SOURCES = test/util_test.cpp
test_util_test_LDADD = libsouffle.la

# matching test
check_PROGRAMS += test/matching_test
test_matching_test_CXXFLAGS = $(souffle_CPPFLAGS) -I @abs_top_srcdir@/src/test
test_matching_test_SOURCES = test/matching_test.cpp
test_matching_test_LDADD = libsouffle.la

# table test
check_PROGRAMS += test/table_test
test_table_test_CXXFLAGS = $(souffle_CPPFLAGS) -I @abs_top_srcdir@/src/test
test_table_test_SOURCES = test/table_test.cpp
test_table_test_LDADD = libsouffle.la

# b-tree set test
check_PROGRAMS += test/btree_set_test
test_btree_set_test_CXXFLAGS = $(souffle_CPPFLAGS) -I @abs_top_srcdir@/src/test
test_btree_set_test_SOURCES = test/btree_set_test.cpp
test_btree_set_test_LDADD = libsouffle.la

# b-tree multi-set test
check_PROGRAMS += test/btree_multiset_test
test_btree_multiset_test_CXXFLAGS = $(souffle_CPPFLAGS) -I @abs_top_srcdir@/src/test
test_btree_multiset_test_SOURCES = test/btree_multiset_test.cpp
test_btree_multiset_test_LDADD = libsouffle.la

# binary relation tests
check_PROGRAMS += test/binary_relation_test
test_binary_relation_test_CXXFLAGS = $(souffle_CPPFLAGS) -I @abs_top_srcdir@/src/test
test_binary_relation_test_SOURCES = test/binary_relation_test.cpp
test_binary_relation_test_LDADD = libsouffle.la

# pnappa's good ol fashioned data structure tests (auxilliary structures to binrel, and potentially useful outside)
check_PROGRAMS += test/eqrel_datastructure_test
test_eqrel_datastructure_test_CXXFLAGS = $(souffle_CPPFLAGS) -I @abs_top_srcdir@/src/test
test_eqrel_datastructure_test_SOURCES = test/eqrel_datastructure_test.cpp
test_eqrel_datastructure_test_LDADD = libsouffle.la

# compiled ram tuple test
check_PROGRAMS += test/compiled_tuple_test
test_compiled_tuple_test_CXXFLAGS = $(souffle_CPPFLAGS) -I @abs_top_srcdir@/src/test
test_compiled_tuple_test_SOURCES = test/compiled_tuple_test.cpp
test_compiled_tuple_test_LDADD = libsouffle.la

# compiled ram index utils test
check_PROGRAMS += test/compiled_index_utils_test
test_compiled_index_utils_test_CXXFLAGS = $(souffle_CPPFLAGS) -I @abs_top_srcdir@/src/test
test_compiled_index_utils_test_SOURCES = test/compiled_index_utils_test.cpp
test_compiled_index_utils_test_LDADD = libsouffle.la

# interpreter relation test
check_PROGRAMS += test/interpreter_relation_test
test_interpreter_relation_test_CXXFLAGS = $(souffle_bin_CPPFLAGS) -I @abs_top_srcdir@/src/test
test_interpreter_relation_test_SOURCES = test/interpreter_relation_test.cpp
test_interpreter_relation_test_LDADD = libsouffle.la

# type system test
check_PROGRAMS += test/type_system_test
test_type_system_test_CXXFLAGS = $(souffle_CPPFLAGS) -I @abs_top_srcdir@/src/test
test_type_system_test_SOURCES = test/type_system_test.cpp
test_type_system_test_LDADD = libsouffle.la

# constraints test
check_PROGRAMS += test/constraints_test
test_constraints_test_CXXFLAGS = $(souffle_CPPFLAGS) -I @abs_top_srcdir@/src/test
test_constraints_test_SOURCES = test/constraints_test.cpp
test_constraints_test_LDADD = libsouffle.la

# ast print test
check_PROGRAMS += test/ast_print_test
test_ast_print_test_CXXFLAGS = $(souffle_CPPFLAGS) -I @abs_top_srcdir@/src/test
test_ast_print_test_SOURCES = test/ast_print_test.cpp
test_ast_print_test_LDADD = libsouffle.la

# ast program test
check_PROGRAMS += test/ast_program_test
test_ast_program_test_CXXFLAGS = $(souffle_CPPFLAGS) -I @abs_top_srcdir@/src/test
test_ast_program_test_SOURCES = test/ast_program_test.cpp
test_ast_program_test_LDADD = libsouffle.la

# ast utils test
check_PROGRAMS += test/ast_utils_test
test_ast_utils_test_CXXFLAGS = $(souffle_CPPFLAGS) -I @abs_top_srcdir@/src/test
test_ast_utils_test_SOURCES = test/ast_utils_test.cpp
test_ast_utils_test_LDADD = libsouffle.la

# ast parser utils test
check_PROGRAMS += test/ast_parser_utils_test
test_ast_parser_utils_test_CXXFLAGS = $(souffle_CPPFLAGS) -I @abs_top_srcdir@/src/test
test_ast_parser_utils_test_SOURCES = test/ast_parser_utils_test.cpp
test_ast_parser_utils_test_LDADD = libsouffle.la

# symbol table
check_PROGRAMS += test/symbol_table_test
test_symbol_table_test_CXXFLAGS = $(souffle_bin_CPPFLAGS) -I @abs_top_srcdir@/src/test -DBUILDDIR='"@abs_top_builddir@/src/"'
test_symbol_table_test_SOURCES = test/symbol_table_test.cpp
test_symbol_table_test_LDADD = libsouffle.la

# graph utils
check_PROGRAMS += test/graph_utils_test
test_graph_utils_test_CXXFLAGS = $(souffle_bin_CPPFLAGS) -I @abs_top_srcdir@/src/test -DBUILDDIR='"@abs_top_builddir@/src/"'
test_graph_utils_test_SOURCES = test/graph_utils_test.cpp
test_graph_utils_test_LDADD = libsouffle.la

# trie implementation
check_PROGRAMS += test/brie_test
test_brie_test_CXXFLAGS = $(souffle_bin_CPPFLAGS) -I @abs_top_srcdir@/src/test -DBUILDDIR='"@abs_top_builddir@/src/"'
test_brie_test_SOURCES = test/brie_test.cpp
test_brie_test_LDADD = libsouffle.la

# parallel utils implementation
check_PROGRAMS += test/parallel_utils_test
test_parallel_utils_test_CXXFLAGS = $(souffle_bin_CPPFLAGS) -I @abs_top_srcdir@/src/test -DBUILDDIR='"@abs_top_builddir@/src/"'
test_parallel_utils_test_SOURCES = test/parallel_utils_test.cpp
test_parallel_utils_test_LDADD = libsouffle.la

# interpreter relation test
check_PROGRAMS += test/ram_condition_equal_clone_test
test_ram_condition_equal_clone_test_CXXFLAGS = $(souffle_bin_CPPFLAGS) -I @abs_top_srcdir@/src/test -DBUILDDIR='"@abs_top_builddir@/src/"'
test_ram_condition_equal_clone_test_SOURCES = test/ram_condition_equal_clone_test.cpp
test_ram_condition_equal_clone_test_LDADD = libsouffle.la

check_PROGRAMS += test/ram_statement_equal_clone_test
test_ram_statement_equal_clone_test_CXXFLAGS = $(souffle_bin_CPPFLAGS) -I @abs_top_srcdir@/src/test -DBUILDDIR='"@abs_top_builddir@/src/"'
test_ram_statement_equal_clone_test_SOURCES = test/ram_statement_equal_clone_test.cpp
test_ram_statement_equal_clone_test_LDADD = libsouffle.la

check_PROGRAMS += test/ram_expression_equal_clone_test
test_ram_expression_equal_clone_test_CXXFLAGS = $(souffle_bin_CPPFLAGS) -I @abs_top_srcdir@/src/test -DBUILDDIR='"@abs_top_builddir@/src/"'
test_ram_expression_equal_clone_test_SOURCES = test/ram_expression_equal_clone_test.cpp
test_ram_expression_equal_clone_test_LDADD = libsouffle.la

check_PROGRAMS += test/ram_operation_equal_clone_test
test_ram_operation_equal_clone_test_CXXFLAGS = $(souffle_bin_CPPFLAGS) -I @abs_top_srcdir@/src/test -DBUILDDIR='"@abs_top_builddir@/src/"'
test_ram_operation_equal_clone_test_SOURCES = test/ram_operation_equal_clone_test.cpp
test_ram_operation_equal_clone_test_LDADD = libsouffle.la

check_PROGRAMS += test/ram_relation_equal_clone_test
test_ram_relation_equal_clone_test_CXXFLAGS = $(souffle_bin_CPPFLAGS) -I @abs_top_srcdir@/src/test -DBUILDDIR='"@abs_top_builddir@/src/"'
test_ram_relation_equal_clone_test_SOURCES = test/ram_relation_equal_clone_test.cpp
test_ram_relation_equal_clone_test_LDADD = libsouffle.la

# relation test
check_PROGRAMS += test/ram_relation_test
test_ram_relation_test_CXXFLAGS = $(souffle_bin_CPPFLAGS) -I @abs_top_srcdir@/src/test -DBUILDDIR='"@abs_top_builddir@/src/"'
test_ram_relation_test_SOURCES = test/ram_relation_test.cpp
test_ram_relation_test_LDADD = libsouffle.la

# arithmetic test
check_PROGRAMS += test/ram_arithmetic_test
test_ram_arithmetic_test_CXXFLAGS = $(souffle_bin_CPPFLAGS) -I @abs_top_srcdir@/src/test -DBUILDDIR='"@abs_top_builddir@/src/"'
test_ram_arithmetic_test_SOURCES = test/ram_arithmetic_test.cpp
test_ram_arithmetic_test_LDADD = libsouffle.la

check_PROGRAMS += test/ram_type_conversion_test
test_ram_type_conversion_test_CXXFLAGS = $(souffle_bin_CPPFLAGS) -I @abs_top_srcdir@/src/test -DBUILDDIR='"@abs_top_builddir@/src/"'
test_ram_type_conversion_test_SOURCES = test/ram_type_conversion_test.cpp
test_ram_type_conversion_test_LDADD = libsouffle.la

check_PROGRAMS += test/record_table_test
test_record_table_test_CXXFLAGS = $(souffle_bin_CPPFLAGS) -I @abs_top_srcdir@/src/test -DBUILDDIR='"@abs_top_builddir@/src/"'
test_record_table_test_SOURCES = test/record_table_test.cpp
test_record_table_test_LDADD = libsouffle.la

# make all check-programs tests
TESTS = $(check_PROGRAMS)
