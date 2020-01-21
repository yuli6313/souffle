/*
 * Souffle - A Datalog Compiler
 * Copyright (c) 2019, The Souffle Developers. All rights reserved
 * Licensed under the Universal Permissive License v 1.0 as shown at:
 * - https://opensource.org/licenses/UPL
 * - <souffle root>/licenses/SOUFFLE-UPL.txt
 */

/************************************************************************
 *
 * @file ram_expression_equal_clone_test.cpp
 *
 * Tests equal and clone function of RamExpression classes.
 *
 ***********************************************************************/

#include "RamExpression.h"

#include "test.h"

namespace souffle {

namespace test {

TEST(RamIntrinsicOperator, CloneAndEquals) {
    // ADD(number(1), number(2))
    std::vector<std::unique_ptr<RamExpression>> a_args;
    a_args.emplace_back(new RamNumber(1));
    a_args.emplace_back(new RamNumber(2));
    RamIntrinsicOperator a(FunctorOp::ADD, std::move(a_args));

    std::vector<std::unique_ptr<RamExpression>> b_args;
    b_args.emplace_back(new RamNumber(1));
    b_args.emplace_back(new RamNumber(2));
    RamIntrinsicOperator b(FunctorOp::ADD, std::move(b_args));
    EXPECT_EQ(a, b);
    EXPECT_NE(&a, &b);

    RamIntrinsicOperator* c = a.clone();
    EXPECT_EQ(a, *c);
    EXPECT_NE(&a, c);
    delete c;

    // NEG(number(1))
    std::vector<std::unique_ptr<RamExpression>> d_args;
    d_args.emplace_back(new RamNumber(1));
    RamIntrinsicOperator d(FunctorOp::NEG, std::move(d_args));

    std::vector<std::unique_ptr<RamExpression>> e_args;
    e_args.emplace_back(new RamNumber(1));
    RamIntrinsicOperator e(FunctorOp::NEG, std::move(e_args));
    EXPECT_EQ(d, e);
    EXPECT_NE(&d, &e);

    RamIntrinsicOperator* f = d.clone();
    EXPECT_EQ(d, *f);
    EXPECT_NE(&d, f);
    delete f;
}

TEST(RamUserDefinedOperator, CloneAndEquals) {
    // define binary functor NE check if two RamExpressions are not equal
    // NE(number(1), number(10))
    std::vector<std::unique_ptr<RamExpression>> a_args;
    a_args.emplace_back(new RamNumber(1));
    a_args.emplace_back(new RamNumber(10));
    RamUserDefinedOperator a("NE", "Binary", std::move(a_args));

    std::vector<std::unique_ptr<RamExpression>> b_args;
    b_args.emplace_back(new RamNumber(1));
    b_args.emplace_back(new RamNumber(10));
    RamUserDefinedOperator b("NE", "Binary", std::move(b_args));
    EXPECT_EQ(a, b);
    EXPECT_NE(&a, &b);

    RamUserDefinedOperator* c = a.clone();
    EXPECT_EQ(a, *c);
    EXPECT_NE(&a, c);
    delete c;
}

TEST(RamTupleElement, CloneAndEquals) {
    // t0.1
    RamTupleElement a(0, 1);
    RamTupleElement b(0, 1);
    EXPECT_EQ(a, b);
    EXPECT_NE(&a, &b);

    RamTupleElement* c = a.clone();
    EXPECT_EQ(a, *c);
    EXPECT_NE(&a, c);
    delete c;
}

TEST(RamNumber, CloneAndEquals) {
    // number(5)
    RamNumber a(5);
    RamNumber b(5);
    EXPECT_EQ(a, b);
    EXPECT_NE(&a, &b);

    RamNumber* c = a.clone();
    EXPECT_EQ(a, *c);
    EXPECT_NE(&a, c);
    delete c;
}

TEST(RamAutoIncrement, CloneAndEquals) {
    RamAutoIncrement a;
    RamAutoIncrement b;
    EXPECT_EQ(a, b);
    EXPECT_NE(&a, &b);

    RamAutoIncrement* c = a.clone();
    EXPECT_EQ(a, *c);
    EXPECT_NE(&a, c);
    delete c;
}

TEST(RamUndefValue, CloneAndEquals) {
    RamUndefValue a;
    RamUndefValue b;
    EXPECT_EQ(a, b);
    EXPECT_NE(&a, &b);

    RamUndefValue* c = a.clone();
    EXPECT_EQ(a, *c);
    EXPECT_NE(&a, c);
    delete c;
}

TEST(RamPackRecord, CloneAndEquals) {
    // {number{10), number(5), ⊥, ⊥}
    std::vector<std::unique_ptr<RamExpression>> a_args;
    a_args.emplace_back(new RamNumber(10));
    a_args.emplace_back(new RamNumber(5));
    a_args.emplace_back(new RamUndefValue);
    a_args.emplace_back(new RamUndefValue);
    RamPackRecord a(std::move(a_args));

    std::vector<std::unique_ptr<RamExpression>> b_args;
    b_args.emplace_back(new RamNumber(10));
    b_args.emplace_back(new RamNumber(5));
    b_args.emplace_back(new RamUndefValue);
    b_args.emplace_back(new RamUndefValue);
    RamPackRecord b(std::move(b_args));

    EXPECT_EQ(a, b);
    EXPECT_NE(&a, &b);

    RamPackRecord* c = a.clone();
    EXPECT_EQ(a, *c);
    EXPECT_NE(&a, c);
    delete c;

    // {⊥, {argument(1), number(0)}, t1.3}
    std::vector<std::unique_ptr<RamExpression>> d_args;
    d_args.emplace_back(new RamUndefValue);
    std::vector<std::unique_ptr<RamExpression>> d_record;
    d_record.emplace_back(new RamSubroutineArgument(1));
    d_record.emplace_back(new RamNumber(5));
    d_args.emplace_back(new RamPackRecord(std::move(d_record)));
    d_args.emplace_back(new RamTupleElement(1, 3));
    RamPackRecord d(std::move(d_args));

    std::vector<std::unique_ptr<RamExpression>> e_args;
    e_args.emplace_back(new RamUndefValue);
    std::vector<std::unique_ptr<RamExpression>> e_record;
    e_record.emplace_back(new RamSubroutineArgument(1));
    e_record.emplace_back(new RamNumber(5));
    e_args.emplace_back(new RamPackRecord(std::move(e_record)));
    e_args.emplace_back(new RamTupleElement(1, 3));
    RamPackRecord e(std::move(e_args));

    EXPECT_EQ(d, e);
    EXPECT_NE(&d, &e);

    RamPackRecord* f = d.clone();
    EXPECT_EQ(d, *f);
    EXPECT_NE(&d, f);
    delete f;
}

TEST(RamSubrountineArgument, CloneAndEquals) {
    RamSubroutineArgument a(2);
    RamSubroutineArgument b(2);
    EXPECT_EQ(a, b);
    EXPECT_NE(&a, &b);

    RamSubroutineArgument* c = a.clone();
    EXPECT_EQ(a, *c);
    EXPECT_NE(&a, c);
    delete c;
}
}  // end namespace test
}  // end namespace souffle