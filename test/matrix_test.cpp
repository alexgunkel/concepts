#include "matrix.h"

#include "gtest/gtest.h"

TEST(MatrixTest, testIntegers) {
  Matrix<int, 2, 2> m1{{{{1, 1}, {1, 0}}}};

  auto m = m1;
  for (int i = 0; i < 30; ++i) {
    auto sum = m.get(0, 1) + m.get(0, 0);
    m = m * m1;
    ASSERT_EQ(m.get(0, 0), sum);
  }
}

TEST(MatrixTest, testBooleans) {
  Matrix<bool, 2, 2, std::logical_and<bool>, std::logical_or<bool>> m1{
      {{{true, false}, {true, true}}}};

  auto m2 = m1 * m1;
}

TEST(MatrixTest, testNesting) {
  typedef Matrix<int, 2, 2, add<int>, multiply<int>> inner_t;
  inner_t inner1 = {{{{1, 2}, {5, 6}}}};
  inner_t inner2 = {{{{1, 2}, {5, 6}}}};
  inner_t inner3 = {{{{1, 2}, {5, 6}}}};
  inner_t inner4 = {{{{1, 2}, {5, 6}}}};

  Matrix<inner_t, 2, 2, add<inner_t>, multiply<inner_t>> outer = {{{{inner1, inner2}, {inner3, inner4}}}};
}

TEST(MatrixTest, sonstiges) {
  Matrix<int, 1, 2> m1 {{{{1}, {2}}}};
  Matrix<int, 2, 2> m2 {{{{1, 2}, {3, 4}}}};

  std::cout << m1 << std::endl;
  std::cout << m2 << std::endl;
  std::cout << (m2 * m1) << std::endl;
}
