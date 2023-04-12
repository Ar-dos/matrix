#include "s21_matrix_oop.h"

#include <cmath>
#include <exception>
#include <iostream>

S21Matrix::S21Matrix() : rows_(3), cols_(3) { Allocate(); }

S21Matrix::S21Matrix(int rows, int cols) : rows_(rows), cols_(cols) {
  Allocate();
}

S21Matrix::S21Matrix(const S21Matrix &other) {
  if (*this == other && this->matrix_ == other.matrix_) return;
  this->~S21Matrix();
  rows_ = other.rows_;
  cols_ = other.cols_;
  Allocate();
  for (int i = 0; i < rows_; i++)
    for (int j = 0; j < cols_; j++) matrix_[i][j] = other.matrix_[i][j];
}
S21Matrix::S21Matrix(S21Matrix &&other) {
  rows_ = other.rows_;
  cols_ = other.cols_;
  matrix_ = other.matrix_;
  other.matrix_ = nullptr;
  other.rows_ = 0;
  other.cols_ = 0;
}
S21Matrix::~S21Matrix() { Clear(); }

int S21Matrix::GetCols() { return cols_; }

int S21Matrix::GetRows() { return rows_; }

void S21Matrix::SetCols(int cols) {
  if (cols < 1) throw std::exception();
  double **temp;
  temp = new double *[rows_];
  for (int i = 0; i < rows_; i++) temp[i] = new double[cols];
  int newcols = (cols > cols_) ? cols_ : cols;
  for (int i = 0; i < rows_; i++)
    for (int j = 0; j < newcols; j++) temp[i][j] = matrix_[i][j];
  if (cols > cols_)
    for (int i = 0; i < rows_; i++)
      for (int j = newcols; j < cols; j++) temp[i][j] = 0;
  Clear();
  matrix_ = temp;
  cols_ = cols;
}

void S21Matrix::SetRows(int rows) {
  if (rows < 1) throw std::exception();
  double **temp;
  temp = new double *[rows];
  for (int i = 0; i < rows; i++) temp[i] = new double[cols_];
  int newrows = (rows > rows_) ? rows_ : rows;
  for (int i = 0; i < newrows; i++)
    for (int j = 0; j < cols_; j++) temp[i][j] = matrix_[i][j];
  if (rows > rows_)
    for (int i = newrows; i < rows; i++)
      for (int j = 0; j < cols_; j++) temp[i][j] = 0;
  Clear();
  matrix_ = temp;
  rows_ = rows;
}

bool S21Matrix::eq_matrix(const S21Matrix &other) {
  bool res = 1;
  if (cols_ != other.cols_ || rows_ != other.rows_) {
    res = 0;
  } else {
    for (int i = 0; i < rows_; i++)
      for (int j = 0; j < cols_; j++)
        if (!(fabs(matrix_[i][j] - other.matrix_[i][j]) < 0.0000001)) res = 0;
  }
  return res;
}

void S21Matrix::sum_matrix(const S21Matrix &other) {
  if (cols_ == other.cols_ && rows_ == other.rows_) {
    for (int i = 0; i < rows_; i++)
      for (int j = 0; j < cols_; j++) matrix_[i][j] += other.matrix_[i][j];
  } else {
    throw std::exception();
  }
}

void S21Matrix::sub_matrix(const S21Matrix &other) {
  if (cols_ == other.cols_ && rows_ == other.rows_) {
    for (int i = 0; i < rows_; i++)
      for (int j = 0; j < cols_; j++) matrix_[i][j] -= other.matrix_[i][j];
  } else {
    throw std::exception();
  }
}

void S21Matrix::mul_number(const double num) {
  for (int i = 0; i < rows_; i++)
    for (int j = 0; j < cols_; j++) matrix_[i][j] *= num;
}

void S21Matrix::mul_matrix(const S21Matrix &other) {
  if (cols_ != other.rows_) throw std::exception();
  S21Matrix res = S21Matrix(rows_, other.cols_);
  for (int i = 0; i < res.rows_; i++)
    for (int j = 0; j < res.cols_; j++)
      for (int x = 0; x < other.rows_; x++)
        res.Set_matrix(res(i, j) + (matrix_[i][x] * other.matrix_[x][j]), i, j);
  Clear();
  *this = res;
}

S21Matrix S21Matrix::transpose() {
  S21Matrix res = S21Matrix(cols_, rows_);
  for (int i = 0; i < rows_; i++)
    for (int j = 0; j < cols_; j++) res.matrix_[j][i] = matrix_[i][j];
  return res;
}

void S21Matrix::Allocate() {
  if (rows_ < 1 || cols_ < 1) throw std::exception();
  matrix_ = new double *[rows_];
  for (int i = 0; i < rows_; i++) matrix_[i] = new double[cols_]{0};
}

void S21Matrix::Clear() {
  if (matrix_ != nullptr) {
    for (int i = 0; i < rows_; i++) delete[] matrix_[i];
    delete[] matrix_;
    matrix_ = nullptr;
  }
}

S21Matrix S21Matrix::calc_complements() {
  if (cols_ != rows_) throw std::exception();
  S21Matrix res = S21Matrix(cols_, rows_);
  if (cols_ < 2) {
    res.matrix_[0][0] = 1;
  } else {
    for (int i = 0; i < rows_; i++)
      for (int j = 0; j < cols_; j++) {
        S21Matrix temp = Exclude(i, j);
        res.matrix_[i][j] = temp.determinant() * pow(-1, i + j);
      }
  }
  return res;
}

double S21Matrix::determinant() {
  if (cols_ != rows_) throw std::exception();
  double res = 0;
  if (cols_ == 1) {
    res = matrix_[0][0];
  } else if (cols_ == 2) {
    res = matrix_[0][0] * matrix_[1][1] - matrix_[1][0] * matrix_[0][1];
  } else if (cols_ > 2) {
    for (int i = 0, k = 1; i < rows_; i++, k = -k) {
      S21Matrix temp = Exclude(i, 0);
      res = res + k * matrix_[i][0] * temp.determinant();
    }
  }
  return res;
}

S21Matrix S21Matrix::inverse_matrix() {
  double d = determinant();
  if (d == 0 || d == NAN || cols_ != rows_) throw std::exception();
  S21Matrix res = calc_complements();
  S21Matrix ress = res.transpose();
  ress *= (1 / d);
  return ress;
}

S21Matrix S21Matrix::operator+(const S21Matrix &o) {
  if (cols_ != o.cols_ || rows_ != o.rows_) throw std::exception();
  S21Matrix res = *this;
  res.sum_matrix(o);
  return res;
}

S21Matrix S21Matrix::operator-(const S21Matrix &o) {
  if (cols_ != o.cols_ || rows_ != o.rows_) throw std::exception();
  S21Matrix res = *this;
  res.sub_matrix(o);
  return res;
}
S21Matrix S21Matrix::operator*(const S21Matrix &o) {
  if (cols_ != o.rows_) throw std::exception();
  S21Matrix res = *this;
  res.mul_matrix(o);
  return res;
}

bool S21Matrix::operator==(const S21Matrix &o) { return eq_matrix(o); }

S21Matrix &S21Matrix::operator=(const S21Matrix &o) {
  Clear();
  rows_ = o.rows_;
  cols_ = o.cols_;
  Allocate();
  for (int i = 0; i < rows_; i++)
    for (int j = 0; j < cols_; j++) matrix_[i][j] = o.matrix_[i][j];
  return *this;
}
S21Matrix &S21Matrix::operator+=(const S21Matrix &o) {
  if (cols_ != o.cols_ || rows_ != o.rows_) throw std::exception();
  sum_matrix(o);
  return *this;
}
S21Matrix &S21Matrix::operator-=(const S21Matrix &o) {
  if (cols_ != o.cols_ || rows_ != o.rows_) throw std::exception();
  sub_matrix(o);
  return *this;
}
S21Matrix &S21Matrix::operator*=(const S21Matrix &o) {
  if (cols_ != o.rows_) throw std::exception();
  mul_matrix(o);
  return *this;
}

S21Matrix &S21Matrix::operator*=(double d) {
  mul_number(d);
  return *this;
}

double S21Matrix::operator()(int i, int j) {
  if (i >= rows_ || j >= cols_ || i < 0 || j < 0) throw std::exception();
  return matrix_[i][j];
}

double S21Matrix::operator()(int i, int j) const {
  if (i >= rows_ || j >= cols_ || i < 0 || j < 0) throw std::exception();
  return matrix_[i][j];
}

S21Matrix S21Matrix::Exclude(int i, int j) {
  S21Matrix res = S21Matrix(rows_ - 1, cols_ - 1);
  for (int x = 0, ki = 0; x < rows_ - 1; x++) {
    if (x == i) ki = 1;
    for (int y = 0, kj = 0; y < cols_ - 1; y++) {
      if (y == j) kj = 1;
      res.matrix_[x][y] = matrix_[x + ki][y + kj];
    }
  }
  return res;
}

void S21Matrix::Set_matrix(double value, int i, int j) {
  if (i >= rows_ || j >= cols_ || i < 0 || j < 0) throw std::exception();
  matrix_[i][j] = value;
}

void S21Matrix::Print() {
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) std::cout << matrix_[i][j] << " ";
    std::cout << std::endl;
  }
}

S21Matrix operator*(double d, S21Matrix &o) {
  S21Matrix res = o;
  res.mul_number(d);
  return res;
}

S21Matrix operator*(S21Matrix &o, double d) {
  S21Matrix res = o;
  res.mul_number(d);
  return res;
}
