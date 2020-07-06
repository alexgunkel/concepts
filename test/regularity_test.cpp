#include "regularity.h"

#include "gtest/gtest.h"

class Irregular {
    int i;
public:
    //Irregular() = delete;
    Irregular(const int &v): i{v} {};
    Irregular(const Irregular &) = delete;
    //Irregular(const Irregular &&) = delete;
    Irregular &operator=(const Irregular &) = default;
};

TEST(Regularity, testDefaultConstructable) {
    ASSERT_TRUE(isDefaultConstructable<int>());
    ASSERT_FALSE(isDefaultConstructable<Irregular>());
}

TEST(Regularity, testCopyConstructable) {
    ASSERT_TRUE(isCopyConstructable<int>());
    ASSERT_FALSE(isCopyConstructable<Irregular>());
}

template <typename T, typename F = std::plus<T> >
requires SemiGroupConcept<T, F>
T add(const T &a, const T &b) {
  return F()(a, b);
}

TEST(ConceptTest, testSemiGroup) {
  int a{3};
  int b{5};

  auto c = add(a, b);
  ASSERT_EQ(8, c);
}
