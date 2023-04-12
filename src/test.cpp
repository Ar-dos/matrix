#include <gtest/gtest.h>

#include <iostream>

#include "s21_matrix_oop.h"

TEST(test_group, S21Matrix_1) {
  S21Matrix a = S21Matrix();
  ASSERT_EQ(a.GetCols(), 3);
  ASSERT_EQ(a.GetRows(), 3);
  for (int i = 0; i < a.GetRows(); i++)
    for (int j = 0; j < a.GetCols(); j++) ASSERT_EQ(a(i, j), 0);
  ASSERT_THROW(a.Set_matrix(69, 4, 8), std::exception);
  ASSERT_THROW(a(4, 6), std::exception);
}

TEST(test_group, S21Matrix_2) {
  S21Matrix a = S21Matrix(1, 6);
  a.Set_matrix(1, 0, 5);
  ASSERT_EQ(a.GetCols(), 6);
  ASSERT_EQ(a.GetRows(), 1);
  ASSERT_EQ(a(0, 5), 1);
}

TEST(test_group, S21Matrix_3) {
  ASSERT_THROW(S21Matrix a = S21Matrix(0, 6), std::exception);
}

TEST(test_group, s21_eq_test) {
  S21Matrix a = S21Matrix(3, 3);
  S21Matrix b = S21Matrix(3, 3);
  S21Matrix c = S21Matrix(3, 3);
  S21Matrix d = S21Matrix(1, 3);
  ASSERT_TRUE(a.eq_matrix(b));
  ASSERT_TRUE(b.eq_matrix(a));
  ASSERT_FALSE(c.eq_matrix(d));
  ASSERT_FALSE(d.eq_matrix(c));
  ASSERT_TRUE(a == b);
  ASSERT_TRUE(b == a);
  ASSERT_FALSE(c == d);
  ASSERT_FALSE(d == c);
  a.Set_matrix(6.6666666, 0, 0);
  b.Set_matrix(6.6666666, 0, 0);
  a.Set_matrix(-1.1111111, 1, 0);
  b.Set_matrix(-1.1111111, 1, 0);
  a.Set_matrix(-3.4343434, 2, 0);
  b.Set_matrix(-3.4343434, 2, 0);
  a.Set_matrix(-6.6666666, 0, 1);
  b.Set_matrix(-6.6666666, 0, 1);
  a.Set_matrix(-1.1111111, 1, 1);
  b.Set_matrix(-1.1111111, 1, 1);
  a.Set_matrix(0.0000000, 2, 1);
  b.Set_matrix(0.0000000, 2, 1);
  a.Set_matrix(42.4242424, 0, 2);
  b.Set_matrix(42.4242424, 0, 2);
  a.Set_matrix(-69.6969696, 1, 2);
  b.Set_matrix(-69.6969696, 1, 2);
  a.Set_matrix(2.28228228, 2, 2);
  b.Set_matrix(2.28228220, 2, 2);
  c.Set_matrix(6.666666, 0, 0);
  c.Set_matrix(-1.111111, 1, 0);
  c.Set_matrix(-3.434343, 2, 0);
  c.Set_matrix(-6.666666, 0, 1);
  c.Set_matrix(-1.111111, 1, 1);
  c.Set_matrix(0.000000, 2, 1);
  c.Set_matrix(42.424242, 0, 2);
  c.Set_matrix(-69.696969, 1, 2);
  c.Set_matrix(2.28228220, 2, 2);

  ASSERT_TRUE(a.eq_matrix(b));
  ASSERT_FALSE(c.eq_matrix(d));
  ASSERT_FALSE(d.eq_matrix(c));
  ASSERT_TRUE(a == b);
  ASSERT_FALSE(c == d);
  ASSERT_FALSE(d == c);
}

TEST(test_group, s21_sum_sub_test) {
  S21Matrix a = S21Matrix(3, 3);
  S21Matrix b = S21Matrix(3, 3);
  S21Matrix c = S21Matrix(3, 3);
  S21Matrix d = S21Matrix(2, 2);
  a.Set_matrix(1, 0, 0);
  a.Set_matrix(0, 1, 0);
  a.Set_matrix(0, 2, 0);
  a.Set_matrix(2, 0, 1);
  a.Set_matrix(4, 1, 1);
  a.Set_matrix(0, 2, 1);
  a.Set_matrix(3, 0, 2);
  a.Set_matrix(5, 1, 2);
  a.Set_matrix(6, 2, 2);

  b.Set_matrix(1, 0, 0);
  b.Set_matrix(2, 1, 0);
  b.Set_matrix(3, 2, 0);
  b.Set_matrix(0, 0, 1);
  b.Set_matrix(0, 1, 1);
  b.Set_matrix(4, 2, 1);
  b.Set_matrix(0, 0, 2);
  b.Set_matrix(0, 1, 2);
  b.Set_matrix(1, 2, 2);

  c.Set_matrix(2, 0, 0);
  c.Set_matrix(2, 1, 0);
  c.Set_matrix(3, 2, 0);
  c.Set_matrix(2, 0, 1);
  c.Set_matrix(4, 1, 1);
  c.Set_matrix(4, 2, 1);
  c.Set_matrix(3, 0, 2);
  c.Set_matrix(5, 1, 2);
  c.Set_matrix(7, 2, 2);

  S21Matrix e = a;
  e.sum_matrix(b);
  ASSERT_TRUE(e.eq_matrix(c));
  e.sub_matrix(b);
  ASSERT_TRUE(e.eq_matrix(a));
  ASSERT_THROW(a.sum_matrix(d), std::exception);
  ASSERT_THROW(a.sub_matrix(d), std::exception);
}

TEST(test_group, s21_sum_sub_test_op) {
  S21Matrix a = S21Matrix(3, 3);
  S21Matrix b = S21Matrix(3, 3);
  S21Matrix c = S21Matrix(3, 3);
  S21Matrix d = S21Matrix(2, 2);
  a.Set_matrix(1, 0, 0);
  a.Set_matrix(0, 1, 0);
  a.Set_matrix(0, 2, 0);
  a.Set_matrix(2, 0, 1);
  a.Set_matrix(4, 1, 1);
  a.Set_matrix(0, 2, 1);
  a.Set_matrix(3, 0, 2);
  a.Set_matrix(5, 1, 2);
  a.Set_matrix(6, 2, 2);

  b.Set_matrix(1, 0, 0);
  b.Set_matrix(2, 1, 0);
  b.Set_matrix(3, 2, 0);
  b.Set_matrix(0, 0, 1);
  b.Set_matrix(0, 1, 1);
  b.Set_matrix(4, 2, 1);
  b.Set_matrix(0, 0, 2);
  b.Set_matrix(0, 1, 2);
  b.Set_matrix(1, 2, 2);

  c.Set_matrix(2, 0, 0);
  c.Set_matrix(2, 1, 0);
  c.Set_matrix(3, 2, 0);
  c.Set_matrix(2, 0, 1);
  c.Set_matrix(4, 1, 1);
  c.Set_matrix(4, 2, 1);
  c.Set_matrix(3, 0, 2);
  c.Set_matrix(5, 1, 2);
  c.Set_matrix(7, 2, 2);

  S21Matrix e = a + b;
  ASSERT_TRUE(e.eq_matrix(c));
  e = e - b;
  ASSERT_TRUE(e.eq_matrix(a));
  ASSERT_THROW(a - d, std::exception);
  ASSERT_THROW(a + d, std::exception);
}

TEST(test_group, s21_sum_sub_test_op_op) {
  S21Matrix a = S21Matrix(3, 3);
  S21Matrix b = S21Matrix(3, 3);
  S21Matrix c = S21Matrix(3, 3);
  S21Matrix d = S21Matrix(2, 2);
  a.Set_matrix(1, 0, 0);
  a.Set_matrix(0, 1, 0);
  a.Set_matrix(0, 2, 0);
  a.Set_matrix(2, 0, 1);
  a.Set_matrix(4, 1, 1);
  a.Set_matrix(0, 2, 1);
  a.Set_matrix(3, 0, 2);
  a.Set_matrix(5, 1, 2);
  a.Set_matrix(6, 2, 2);

  b.Set_matrix(1, 0, 0);
  b.Set_matrix(2, 1, 0);
  b.Set_matrix(3, 2, 0);
  b.Set_matrix(0, 0, 1);
  b.Set_matrix(0, 1, 1);
  b.Set_matrix(4, 2, 1);
  b.Set_matrix(0, 0, 2);
  b.Set_matrix(0, 1, 2);
  b.Set_matrix(1, 2, 2);

  c.Set_matrix(2, 0, 0);
  c.Set_matrix(2, 1, 0);
  c.Set_matrix(3, 2, 0);
  c.Set_matrix(2, 0, 1);
  c.Set_matrix(4, 1, 1);
  c.Set_matrix(4, 2, 1);
  c.Set_matrix(3, 0, 2);
  c.Set_matrix(5, 1, 2);
  c.Set_matrix(7, 2, 2);

  S21Matrix e = a;
  a += b;
  ASSERT_TRUE(a.eq_matrix(c));
  a -= b;
  ASSERT_TRUE(a.eq_matrix(a));
  ASSERT_THROW(a += d, std::exception);
  ASSERT_THROW(a -= d, std::exception);
}

TEST(test_group, s21_mult_test) {
  S21Matrix a = S21Matrix(3, 2);
  S21Matrix b = S21Matrix(2, 3);
  S21Matrix c = S21Matrix(3, 3);
  S21Matrix d = S21Matrix(1, 1);

  d.Set_matrix(1, 0, 0);

  a.Set_matrix(1, 0, 0);
  a.Set_matrix(2, 1, 0);
  a.Set_matrix(3, 2, 0);
  a.Set_matrix(4, 0, 1);
  a.Set_matrix(5, 1, 1);
  a.Set_matrix(6, 2, 1);

  b.Set_matrix(1, 0, 0);
  b.Set_matrix(2, 1, 0);
  b.Set_matrix(-1, 0, 1);
  b.Set_matrix(3, 1, 1);
  b.Set_matrix(1, 0, 2);
  b.Set_matrix(4, 1, 2);

  c.Set_matrix(9, 0, 0);
  c.Set_matrix(12, 1, 0);
  c.Set_matrix(15, 2, 0);
  c.Set_matrix(11, 0, 1);
  c.Set_matrix(13, 1, 1);
  c.Set_matrix(15, 2, 1);
  c.Set_matrix(17, 0, 2);
  c.Set_matrix(22, 1, 2);
  c.Set_matrix(27, 2, 2);

  a.mul_matrix(b);
  ASSERT_TRUE(a.eq_matrix(c));
  ASSERT_THROW(a.mul_matrix(d), std::exception);
}

TEST(test_group, s21_mult_test_op) {
  S21Matrix a = S21Matrix(3, 2);
  S21Matrix b = S21Matrix(2, 3);
  S21Matrix c = S21Matrix(3, 3);
  S21Matrix d = S21Matrix(1, 1);

  d.Set_matrix(1, 0, 0);

  a.Set_matrix(1, 0, 0);
  a.Set_matrix(2, 1, 0);
  a.Set_matrix(3, 2, 0);
  a.Set_matrix(4, 0, 1);
  a.Set_matrix(5, 1, 1);
  a.Set_matrix(6, 2, 1);

  b.Set_matrix(1, 0, 0);
  b.Set_matrix(2, 1, 0);
  b.Set_matrix(-1, 0, 1);
  b.Set_matrix(3, 1, 1);
  b.Set_matrix(1, 0, 2);
  b.Set_matrix(4, 1, 2);

  c.Set_matrix(9, 0, 0);
  c.Set_matrix(12, 1, 0);
  c.Set_matrix(15, 2, 0);
  c.Set_matrix(11, 0, 1);
  c.Set_matrix(13, 1, 1);
  c.Set_matrix(15, 2, 1);
  c.Set_matrix(17, 0, 2);
  c.Set_matrix(22, 1, 2);
  c.Set_matrix(27, 2, 2);

  a = a * b;
  ASSERT_TRUE(a.eq_matrix(c));
  ASSERT_THROW(a * d, std::exception);
}

TEST(test_group, s21_mult_test_op_op) {
  S21Matrix a = S21Matrix(3, 2);
  S21Matrix b = S21Matrix(2, 3);
  S21Matrix c = S21Matrix(3, 3);
  S21Matrix d = S21Matrix(1, 1);

  d.Set_matrix(1, 0, 0);

  a.Set_matrix(1, 0, 0);
  a.Set_matrix(2, 1, 0);
  a.Set_matrix(3, 2, 0);
  a.Set_matrix(4, 0, 1);
  a.Set_matrix(5, 1, 1);
  a.Set_matrix(6, 2, 1);

  b.Set_matrix(1, 0, 0);
  b.Set_matrix(2, 1, 0);
  b.Set_matrix(-1, 0, 1);
  b.Set_matrix(3, 1, 1);
  b.Set_matrix(1, 0, 2);
  b.Set_matrix(4, 1, 2);

  c.Set_matrix(9, 0, 0);
  c.Set_matrix(12, 1, 0);
  c.Set_matrix(15, 2, 0);
  c.Set_matrix(11, 0, 1);
  c.Set_matrix(13, 1, 1);
  c.Set_matrix(15, 2, 1);
  c.Set_matrix(17, 0, 2);
  c.Set_matrix(22, 1, 2);
  c.Set_matrix(27, 2, 2);

  a *= b;
  ASSERT_TRUE(a.eq_matrix(c));
  ASSERT_THROW(a *= d, std::exception);
}

TEST(test_group, s21_transpose_test) {
  S21Matrix a = S21Matrix(3, 2);
  S21Matrix res = S21Matrix(2, 3);

  a.Set_matrix(1, 0, 0);
  a.Set_matrix(2, 1, 0);
  a.Set_matrix(3, 2, 0);
  a.Set_matrix(4, 0, 1);
  a.Set_matrix(5, 1, 1);
  a.Set_matrix(6, 2, 1);

  res.Set_matrix(1, 0, 0);
  res.Set_matrix(2, 0, 1);
  res.Set_matrix(3, 0, 2);
  res.Set_matrix(4, 1, 0);
  res.Set_matrix(5, 1, 1);
  res.Set_matrix(6, 1, 2);

  S21Matrix b = a.transpose();
  ASSERT_TRUE(b.eq_matrix(res));
}

TEST(test_group, s21_calc_complements_test) {
  S21Matrix a = S21Matrix(3, 3);
  S21Matrix res = S21Matrix(3, 3);
  S21Matrix c = S21Matrix(3, 2);
  S21Matrix d = S21Matrix(1, 1);

  a.Set_matrix(1, 0, 0);
  a.Set_matrix(2, 1, 0);
  a.Set_matrix(3, 2, 0);
  a.Set_matrix(0, 0, 1);
  a.Set_matrix(4, 1, 1);
  a.Set_matrix(2, 2, 1);
  a.Set_matrix(5, 0, 2);
  a.Set_matrix(2, 1, 2);
  a.Set_matrix(1, 2, 2);

  c.Set_matrix(1, 0, 0);
  c.Set_matrix(2, 1, 0);
  c.Set_matrix(3, 2, 0);
  c.Set_matrix(0, 0, 1);
  c.Set_matrix(4, 1, 1);
  c.Set_matrix(2, 2, 1);

  d.Set_matrix(1, 0, 0);

  res.Set_matrix(0, 0, 0);
  res.Set_matrix(10, 1, 0);
  res.Set_matrix(-20, 2, 0);
  res.Set_matrix(4, 0, 1);
  res.Set_matrix(-14, 1, 1);
  res.Set_matrix(8, 2, 1);
  res.Set_matrix(-8, 0, 2);
  res.Set_matrix(-2, 1, 2);
  res.Set_matrix(4, 2, 2);

  S21Matrix b = a.calc_complements();
  ASSERT_TRUE(b.eq_matrix(res));
  ASSERT_TRUE(d.eq_matrix(d.calc_complements()));
  ASSERT_THROW(c.determinant(), std::exception);
  ASSERT_THROW(c.calc_complements(), std::exception);
}

TEST(test_group, s21_calc_inverse_test) {
  S21Matrix a = S21Matrix(3, 3);
  S21Matrix res = S21Matrix(3, 3);
  S21Matrix c = S21Matrix(1, 1);

  a.Set_matrix(2, 0, 0);
  a.Set_matrix(5, 1, 0);
  a.Set_matrix(7, 2, 0);
  a.Set_matrix(6, 0, 1);
  a.Set_matrix(3, 1, 1);
  a.Set_matrix(4, 2, 1);
  a.Set_matrix(5, 0, 2);
  a.Set_matrix(-2, 1, 2);
  a.Set_matrix(-3, 2, 2);

  c.Set_matrix(0, 0, 0);

  res.Set_matrix(1, 0, 0);
  res.Set_matrix(-1, 1, 0);
  res.Set_matrix(1, 2, 0);
  res.Set_matrix(-38, 0, 1);
  res.Set_matrix(41, 1, 1);
  res.Set_matrix(-34, 2, 1);
  res.Set_matrix(27, 0, 2);
  res.Set_matrix(-29, 1, 2);
  res.Set_matrix(24, 2, 2);

  S21Matrix b = a.inverse_matrix();
  ASSERT_TRUE(b.eq_matrix(res));
  ASSERT_THROW(c.inverse_matrix(), std::exception);
}

TEST(test_group, s21_set_cols_test) {
  S21Matrix a = S21Matrix(3, 3);
  S21Matrix b = S21Matrix(3, 2);
  S21Matrix c = S21Matrix(3, 3);

  a.Set_matrix(2, 0, 0);
  a.Set_matrix(5, 1, 0);
  a.Set_matrix(7, 2, 0);
  a.Set_matrix(6, 0, 1);
  a.Set_matrix(3, 1, 1);
  a.Set_matrix(4, 2, 1);
  a.Set_matrix(5, 0, 2);
  a.Set_matrix(-2, 1, 2);
  a.Set_matrix(-3, 2, 2);

  b.Set_matrix(2, 0, 0);
  b.Set_matrix(5, 1, 0);
  b.Set_matrix(7, 2, 0);
  b.Set_matrix(6, 0, 1);
  b.Set_matrix(3, 1, 1);
  b.Set_matrix(4, 2, 1);

  c.Set_matrix(2, 0, 0);
  c.Set_matrix(5, 1, 0);
  c.Set_matrix(7, 2, 0);
  c.Set_matrix(6, 0, 1);
  c.Set_matrix(3, 1, 1);
  c.Set_matrix(4, 2, 1);
  c.Set_matrix(0, 0, 2);
  c.Set_matrix(0, 1, 2);
  c.Set_matrix(0, 2, 2);

  a.SetCols(2);

  ASSERT_TRUE(a.eq_matrix(b));

  a.SetCols(3);
  ASSERT_THROW(a.SetCols(-1), std::exception);
  ASSERT_TRUE(a.eq_matrix(c));
}

TEST(test_group, s21_set_rows_test) {
  S21Matrix a = S21Matrix(3, 3);
  S21Matrix b = S21Matrix(2, 3);
  S21Matrix c = S21Matrix(3, 3);

  a.Set_matrix(2, 0, 0);
  a.Set_matrix(5, 1, 0);
  a.Set_matrix(7, 2, 0);
  a.Set_matrix(6, 0, 1);
  a.Set_matrix(3, 1, 1);
  a.Set_matrix(4, 2, 1);
  a.Set_matrix(5, 0, 2);
  a.Set_matrix(-2, 1, 2);
  a.Set_matrix(-3, 2, 2);

  b.Set_matrix(2, 0, 0);
  b.Set_matrix(5, 1, 0);

  b.Set_matrix(6, 0, 1);
  b.Set_matrix(3, 1, 1);

  b.Set_matrix(5, 0, 2);
  b.Set_matrix(-2, 1, 2);

  c.Set_matrix(2, 0, 0);
  c.Set_matrix(5, 1, 0);
  c.Set_matrix(0, 2, 0);
  c.Set_matrix(6, 0, 1);
  c.Set_matrix(3, 1, 1);
  c.Set_matrix(0, 2, 1);
  c.Set_matrix(5, 0, 2);
  c.Set_matrix(-2, 1, 2);
  c.Set_matrix(0, 2, 2);

  a.SetRows(2);

  ASSERT_TRUE(a.eq_matrix(b));

  a.SetRows(3);
  ASSERT_THROW(a.SetRows(-1), std::exception);
  ASSERT_TRUE(a.eq_matrix(c));
}

TEST(test_group, s21_move_test) {
  S21Matrix a = S21Matrix(3, 3);

  a.Set_matrix(2, 0, 0);
  a.Set_matrix(5, 1, 0);
  a.Set_matrix(7, 2, 0);
  a.Set_matrix(6, 0, 1);
  a.Set_matrix(3, 1, 1);
  a.Set_matrix(4, 2, 1);
  a.Set_matrix(5, 0, 2);
  a.Set_matrix(-2, 1, 2);
  a.Set_matrix(-3, 2, 2);

  S21Matrix b = a;

  S21Matrix c = std::move(a);

  ASSERT_TRUE(b.eq_matrix(c));
}

TEST(test_group, s21_const_test) {
  const S21Matrix a = S21Matrix(3, 3);

  ASSERT_DOUBLE_EQ(a(1, 0), 0);
  ASSERT_DOUBLE_EQ(a(2, 0), 0);
  ASSERT_DOUBLE_EQ(a(0, 1), 0);
  ASSERT_DOUBLE_EQ(a(1, 1), 0);
  ASSERT_DOUBLE_EQ(a(2, 1), 0);
  ASSERT_DOUBLE_EQ(a(0, 2), 0);
  ASSERT_DOUBLE_EQ(a(1, 2), 0);
  ASSERT_DOUBLE_EQ(a(2, 2), 0);
  ASSERT_THROW(a(0, 6), std::exception);
}

TEST(test_group, s21_mulnum_test) {
  S21Matrix a = S21Matrix(3, 3);

  a.Set_matrix(2, 0, 0);
  a.Set_matrix(5, 1, 0);
  a.Set_matrix(7, 2, 0);
  a.Set_matrix(6, 0, 1);
  a.Set_matrix(3, 1, 1);
  a.Set_matrix(4, 2, 1);
  a.Set_matrix(5, 0, 2);
  a.Set_matrix(-2, 1, 2);
  a.Set_matrix(-3, 2, 2);

  S21Matrix e = S21Matrix(3, 3);

  e.Set_matrix(4, 0, 0);
  e.Set_matrix(10, 1, 0);
  e.Set_matrix(14, 2, 0);
  e.Set_matrix(12, 0, 1);
  e.Set_matrix(6, 1, 1);
  e.Set_matrix(8, 2, 1);
  e.Set_matrix(10, 0, 2);
  e.Set_matrix(-4, 1, 2);
  e.Set_matrix(-6, 2, 2);

  double d = 2.0;

  S21Matrix b = a * d;
  S21Matrix c = d * a;

  ASSERT_TRUE(b.eq_matrix(e));
  ASSERT_TRUE(c.eq_matrix(e));
  ASSERT_TRUE(b.eq_matrix(c));
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
