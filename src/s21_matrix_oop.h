#ifndef SRC_S21_MATRIX_OOP_H_
#define SRC_S21_MATRIX_OOP_H_
class S21Matrix {
 private:
  int rows_ = 0, cols_ = 0;
  double **matrix_ = nullptr;

  S21Matrix Exclude(int i, int j);
  void Allocate();
  void Clear();

 public:
  S21Matrix();
  S21Matrix(int rows, int cols);
  S21Matrix(const S21Matrix &other);
  S21Matrix(S21Matrix &&other);
  ~S21Matrix();

  int GetCols();
  int GetRows();
  void SetCols(int cols);
  void SetRows(int rows);

  bool eq_matrix(const S21Matrix &other);
  void sum_matrix(const S21Matrix &other);
  void sub_matrix(const S21Matrix &other);
  void mul_number(const double num);
  void mul_matrix(const S21Matrix &other);
  S21Matrix transpose();
  S21Matrix calc_complements();
  double determinant();
  S21Matrix inverse_matrix();

  S21Matrix operator+(const S21Matrix &o);
  S21Matrix operator-(const S21Matrix &o);
  S21Matrix operator*(const S21Matrix &o);
  friend S21Matrix operator*(double, S21Matrix &);
  friend S21Matrix operator*(S21Matrix &, double);
  bool operator==(const S21Matrix &o);
  S21Matrix &operator=(const S21Matrix &o);
  S21Matrix &operator+=(const S21Matrix &o);
  S21Matrix &operator-=(const S21Matrix &o);
  S21Matrix &operator*=(const S21Matrix &o);
  S21Matrix &operator*=(double d);
  double operator()(int i, int j);
  double operator()(int i, int j) const;

  void Set_matrix(double value, int i, int j);
  void Print();
};

#endif  // SRC_S21_MATRIX_OOP_H_
