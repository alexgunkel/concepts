
#ifndef C__20_REGULARITY_H
#define C__20_REGULARITY_H
#include <concepts>

template <typename T>
concept DefaultConstructable = requires(T a) {
  T{};
};

template <class T>
constexpr bool isDefaultConstructable() {
  return false;
}

template <DefaultConstructable T>
constexpr bool isDefaultConstructable() {
  return true;
}

template <typename T>
concept CopyConstructable = requires(T a) {
  T(a);
};

template <typename T, typename F>
concept SemiGroupConcept = requires (T a, T b) {
  {F{}(a, b)} -> std::same_as<T>;
};

template <CopyConstructable T>
constexpr bool isCopyConstructable() {
  return true;
}

template <class T>
constexpr bool isCopyConstructable() {
  return false;
}

#endif  // C__20_REGULARITY_H
