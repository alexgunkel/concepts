
#ifndef C__20_MATRIX_H
#define C__20_MATRIX_H
#include <array>
#include <ostream>

#include "algebraic_concepts.h"

template <typename T, int X, int Y, typename Addition = add<T>,
          typename Multiplication = multiply<T>>
requires SemiRing<T, Addition, Multiplication>
    &&Monoid<T, Addition> class Matrix {
  typedef std::array<std::array<T, X>, Y> storage;
  typedef Matrix<T, X, Y, Addition, Multiplication> self_t;
  storage _m;

 public:
  Matrix(const storage &i) : _m{i} {};
  constexpr Matrix() {
    std::fill(_m.begin(), _m.end(), std::array<T, X>{T{}});
  };

  template <int OX, int OY>
  requires(std::equal_to{}(X, OY)) Matrix<T, OX, Y, Addition, Multiplication>
  operator*(const Matrix<T, OX, OY, Addition, Multiplication> &other) const {
    std::array<std::array<T, OX>, Y> res;
    for (int i = 0; i < Y; ++i) {
      for (int j = 0; j < OX; ++j) {
        res[i][j] = T{};
        for (int k = 0; k < X; ++k) {
          res[i][j] = Addition{}(
              res[i][j], Multiplication{}(this->get(k, i), other.get(j, k)));
        }
      }
    }

    return Matrix<T, OX, Y, Addition, Multiplication>{res};
  }

  self_t operator+(const self_t &other) const {
    storage result;
    for (int i = 0; i < X; ++i) {
      for (int j = 0; j < Y; ++j) {
        result[j][i] = Addition{}(_m[j][i], other._m[j][i]);
      }
    }

    return self_t{result};
  }

  T get(int x, int y) const { return _m[y][x]; }
  bool operator==(const Matrix &rhs) const { return _m == rhs._m; }
  bool operator!=(const Matrix &rhs) const { return !(rhs == *this); }

  friend std::ostream &operator<<(std::ostream &os, const Matrix &matrix) {
    os << " < ";
    for (const auto &line : matrix._m) {
      os << " < ";
      for (const auto &sg : line) {
        os << sg << ", ";
      }
      os << " > ";
    }
    os << " > ";

    return os;
  }
};

#endif  // C__20_MATRIX_H
