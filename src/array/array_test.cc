#include <gtest/gtest.h>

#include <array>

#include "s21_array.h"

using namespace s21;

TEST(Array_Constructors, init) {
  std::array<int, 1> std_array;
  s21::Array<int, 1> s21_array;

  ASSERT_EQ(std_array.size(), s21_array.size());
}

TEST(Array_Constructors, default) {
  s21::Array<int, 10> a1;

  ASSERT_NO_THROW(a1[0]);
}

TEST(Array_Constructors, init_list) {
  s21::Array<int, 10> a1{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  std::array<int, 10> a2{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

  for (size_t i = 0; i != a1.max_size(); i++) ASSERT_EQ(a1[i], a2[i]);
}

TEST(Array_Constructors, copy) {
  s21::Array<int, 10> a1{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  s21::Array<int, 10> a2(a1);
  std::array<int, 10> a3{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  std::array<int, 10> a4(a3);

  for (size_t i = 0; i != a1.max_size(); i++) ASSERT_EQ(a2[i], a4[i]);
}

TEST(Array_Constructors, move) {
  s21::Array<int, 10> a1{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  s21::Array<int, 10> a2(std::move(a1));
  std::array<int, 10> a3{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  std::array<int, 10> a4(std::move(a3));

  for (size_t i = 0; i != a1.max_size(); i++) {
    ASSERT_EQ(a1[i], a3[i]);
    ASSERT_EQ(a2[i], a4[i]);
  }
}

TEST(Array_Methods, begin) {
  s21::Array<int, 10> a1{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  std::array<int, 10> a2{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

  ASSERT_EQ(*a1.begin(), *a2.begin());
}

TEST(Array_Methods, end) {
  s21::Array<int, 10> a1{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  std::array<int, 10> a2{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

  s21::Array<int, 10>::iterator it = a1.end();
  --it;
  std::array<int, 10>::iterator std_it = a2.end();
  --std_it;

  ASSERT_EQ(*it, *std_it);
}

TEST(Array_Methods, data) {
  s21::Array<int, 10> a1{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  std::array<int, 10> a2{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

  ASSERT_EQ(*a1.data(), *a2.data());
}

TEST(Array_Methods, at) {
  s21::Array<int, 10> a1{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  std::array<int, 10> a2{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

  ASSERT_EQ(a1.at(2), a2.at(2));
}

TEST(Array_Methods, at_out_of_range) {
  s21::Array<int, 10> a1{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  std::array<int, 10> a2{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

  ASSERT_THROW(a1.at(20), std::out_of_range);
  ASSERT_THROW(a2.at(20), std::out_of_range);
}

TEST(Array_Methods, front) {
  s21::Array<int, 10> a1{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  std::array<int, 10> a2{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

  ASSERT_EQ(a1.front(), a2.front());
}

TEST(Array_Methods, back) {
  s21::Array<int, 10> a1{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  std::array<int, 10> a2{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

  ASSERT_EQ(a1.back(), a2.back());
}

TEST(Array_Methods, empty_true) {
  s21::Array<int, 10> a1;
  std::array<int, 10> a2;

  ASSERT_EQ(a1.empty(), a2.empty());
}

TEST(Array_Methods, empty_false) {
  s21::Array<int, 10> a1{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  std::array<int, 10> a2{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

  ASSERT_EQ(a1.empty(), a2.empty());
}

TEST(Array_Methods, size) {
  s21::Array<int, 10> a1{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  std::array<int, 10> a2{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

  ASSERT_EQ(a1.size(), a2.size());
}

TEST(Array_Methods, size_zero) {
  s21::Array<int, 0> a1;
  std::array<int, 0> a2;

  ASSERT_EQ(a1.size(), a2.size());
}

TEST(Array_Methods, max_size) {
  s21::Array<int, 10> a1{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  std::array<int, 10> a2{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

  ASSERT_EQ(a1.max_size(), a2.max_size());
}

TEST(Array_Methods, max_size_zero) {
  s21::Array<int, 0> a1;
  std::array<int, 0> a2;

  ASSERT_EQ(a1.max_size(), a2.max_size());
}

TEST(Array_Methods, swap) {
  s21::Array<int, 10> a1{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  s21::Array<int, 10> a2{1, 1, 1, 1, 1, 1, 1, 1, 1, 1};

  std::array<int, 10> a3{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  std::array<int, 10> a4{1, 1, 1, 1, 1, 1, 1, 1, 1, 1};

  a1.swap(a2);
  a3.swap(a4);
  for (size_t i = 0; i != a1.max_size(); i++) {
    ASSERT_EQ(a1[i], a3[i]);
    ASSERT_EQ(a2[i], a4[i]);
  }
}

TEST(Array_Methods, fill) {
  s21::Array<int, 10> a1;
  std::array<int, 10> a2;

  a1.fill(1);
  a2.fill(1);
  for (size_t i = 0; i != a1.max_size(); i++) ASSERT_EQ(a1[i], a2[i]);
}

TEST(Array_Operators, copy) {
  s21::Array<int, 10> a1{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  s21::Array<int, 10> a2{1, 1, 1, 1, 1, 1, 1, 1, 1, 1};

  std::array<int, 10> a3{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  std::array<int, 10> a4{1, 1, 1, 1, 1, 1, 1, 1, 1, 1};

  a1 = a2;
  a3 = a4;
  for (size_t i = 0; i != a1.max_size(); i++) ASSERT_EQ(a1[i], a3[i]);
}

TEST(Array_Operators, move) {
  s21::Array<int, 10> a1{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  s21::Array<int, 10> a2{1, 1, 1, 1, 1, 1, 1, 1, 1, 1};

  std::array<int, 10> a3{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  std::array<int, 10> a4{1, 1, 1, 1, 1, 1, 1, 1, 1, 1};

  a1 = std::move(a2);
  a3 = std::move(a4);
  for (size_t i = 0; i != a1.max_size(); i++) ASSERT_EQ(a1[i], a3[i]);
}

TEST(Array_Operators, brackets) {
  const s21::Array<int, 10> a1{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  const std::array<int, 10> a2{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

  ASSERT_EQ(a1[1], a2[1]);
}

TEST(Array_Operators, brackets_out_of_range) {
  const s21::Array<int, 10> a1{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

  ASSERT_THROW(a1[111], std::out_of_range);
}

TEST(Array_Operators, brackets_overwriting) {
  s21::Array<int, 10> a1{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  std::array<int, 10> a2{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

  a1[1] = 11;
  a2[1] = 11;
  ASSERT_EQ(a1[1], a2[1]);
}
