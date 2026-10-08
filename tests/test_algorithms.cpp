// Copyright 2026 Lebedev Vladislav

#include <gtest/gtest.h>
#include "../lib_algorithms/algorithms.h"
#include "../lib_stack_on_mass/StackOnMass.h"


#define EPSILON 0.000001

TEST(TestEasyExampleLib, can_div) {
  // Arrange
  int x = 10;
  int y = 2;

  // Act & Assert
  ASSERT_NO_THROW(division(x, y));
}

TEST(TestEasyExampleLib, can_div_correctly) {
    // Arrange
    int x = 6;
    int y = 2;

    // Act
    int actual_result = division(x, y);

    // Assert
    int expected_result = 3;
    EXPECT_EQ(expected_result, actual_result);
}

TEST(TestEasyExampleLib, can_div_correctly_with_remainder) {
    // Arrange
    int x = 5;
    int y = 4;

    // Act
    float actual_result = division(x, y);

    // Assert
    float expected_result = 1.25;
    EXPECT_NEAR(expected_result, actual_result, EPSILON);
}

TEST(TestEasyExampleLib, throw_when_try_div_by_zero) {
  // Arrange
  int x = 10;
  int y = 0;

  // Act & Assert
  ASSERT_ANY_THROW(division(x, y));
}


TEST(StackOnMassTest, Initialization) {
    StackOnMass<int> stack(5);
    EXPECT_EQ(stack.get_size(), 5);
    EXPECT_EQ(stack.get_top(), -1);
    EXPECT_TRUE(stack.is_empty());
    EXPECT_FALSE(stack.is_full());
}

TEST(StackOnMassTest, PushElements) {
    StackOnMass<int> stack(3);
    stack.push(10);
    EXPECT_EQ(stack.get_top(), 0);
    EXPECT_EQ(stack.top(), 10);

    stack.push(20);
    EXPECT_EQ(stack.get_top(), 1);
    EXPECT_EQ(stack.top(), 20);
    EXPECT_FALSE(stack.is_empty());
}

TEST(StackOnMassTest, PopElements) {
    StackOnMass<int> stack(3);
    stack.push(10);
    stack.push(20);

    EXPECT_EQ(stack.pop(), 20);
    EXPECT_EQ(stack.top(), 10);
    EXPECT_EQ(stack.pop(), 10);
    EXPECT_TRUE(stack.is_empty());
}

TEST(StackOnMassTest, CopyConstructor) {
    StackOnMass<int> stack1(3);
    stack1.push(42);

    StackOnMass<int> stack2(stack1);
    EXPECT_EQ(stack2.get_size(), 3);
    EXPECT_EQ(stack2.top(), 42);

    stack2.pop();
    EXPECT_TRUE(stack2.is_empty());
    EXPECT_FALSE(stack1.is_empty());
}

TEST(StackOnMassTest, ThrowOnPushToFull) {
    StackOnMass<int> stack(2);
    stack.push(1);
    stack.push(2);

    EXPECT_TRUE(stack.is_full());
    EXPECT_THROW(stack.push(3), std::out_of_range);

    try {
        stack.push(3);
    }
    catch (const std::out_of_range& e) {
        EXPECT_STREQ(e.what(), "StackOnMass::push(): stack is full");
    }
}

TEST(StackOnMassTest, ThrowOnPopFromEmpty) {
    StackOnMass<int> stack(5);
    EXPECT_THROW(stack.pop(), std::out_of_range);

    try {
        stack.pop();
    }
    catch (const std::out_of_range& e) {
        EXPECT_STREQ(e.what(), "StackOnMass::pop(): stack is empty");
    }
}

TEST(StackOnMassTest, ThrowOnTopFromEmpty) {
    StackOnMass<int> stack(5);
    EXPECT_THROW(stack.top(), std::out_of_range);

    try {
        stack.top();
    }
    catch (const std::out_of_range& e) {
        EXPECT_STREQ(e.what(), "StackOnMass::top(): stack is empty");
    }
}
