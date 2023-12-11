#include <gtest/gtest.h>

#include "../square_matrix.h"

TEST(SquareMatrixTest, AddMatrices) {
    Math::SquareMatrix<int> first(2, 2);
    first.setValue(0, 0, 1);
    first.setValue(0, 1, 2);
    first.setValue(1, 0, 3);
    first.setValue(1, 1, 4);

    Math::SquareMatrix<int> second(2, 2);
    second.setValue(0, 0, 5);
    second.setValue(0, 1, 6);
    second.setValue(1, 0, 7);
    second.setValue(1, 1, 8);

    Math::SquareMatrix<int> expected(2, 2);
    expected.setValue(0, 0, 6);
    expected.setValue(0, 1, 8);
    expected.setValue(1, 0, 10);
    expected.setValue(1, 1, 12);

    Math::SquareMatrix<int> result = first + second;

    EXPECT_EQ(result, expected);
}


TEST(SquareMatrixTest, MultiplyMatrices) {
    Math::SquareMatrix<int> first(2, 2);
    first.setValue(0, 0, 1);
    first.setValue(0, 1, 2);
    first.setValue(1, 0, 3);
    first.setValue(1, 1, 4);

    Math::SquareMatrix<int> second(2, 2);
    second.setValue(0, 0, 5);
    second.setValue(0, 1, 6);
    second.setValue(1, 0, 7);
    second.setValue(1, 1, 8);

    Math::SquareMatrix<int> expected(2, 2);
    expected.setValue(0, 0, 19);
    expected.setValue(0, 1, 22);
    expected.setValue(1, 0, 43);
    expected.setValue(1, 1, 50);

    Math::SquareMatrix<int> result = Math::multiply(first, second);

    EXPECT_EQ(result, expected);
}