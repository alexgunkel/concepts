
#ifndef C__20_ALGEBRAIC_CONCEPTS_H
#define C__20_ALGEBRAIC_CONCEPTS_H

#include <concepts>
#include <functional>

template <typename T>
requires requires(T &a, T &b) {
  { a + b }
  ->std::same_as<T>;
}
struct add {
  constexpr T operator()(const T &left, const T &right) const {
    return left + right;
  }
};

template <typename T>
requires requires(T &a, T &b) {
  { a * b }
  ->std::same_as<T>;
}
struct multiply {
  constexpr T operator()(const T &left, const T &right) const {
    return left * right;
  }
};

template <typename T, typename F>
concept Magma = std::regular<T> &&requires(T a, T b) {
  { F()(a, b) }
  ->std::same_as<T>;
};

template <typename T, typename F>
constexpr bool is_associative = true;

template <typename T, typename F>
constexpr bool is_commutative = true;

template <typename T, typename F>
concept SemiGroup = Magma<T, F> &&is_associative<T, F>;

template <typename T, typename F>
concept CommutativeSemiGroup = SemiGroup<T, F> &&is_commutative<T, F>;

template <typename T, typename F>
concept Monoid = SemiGroup<T, F>;

template <typename T, typename Addition, typename Multiplication>
concept SemiRing = SemiGroup<T, Addition> &&SemiGroup<T, Multiplication>;

template <typename R, typename Addition, typename Multiplication>
constexpr bool isSemiRing = SemiRing<R, Addition, Multiplication>;

#endif  // C__20_ALGEBRAIC_CONCEPTS_H
