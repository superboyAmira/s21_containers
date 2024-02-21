#include <gtest/gtest.h>

#include <list>

#include "s21_list.h"

using namespace s21;

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

TEST(Constructors, init) {
  std::list<int> std_list;
  s21::List<int> s21_list;

  ASSERT_EQ(std_list.size(), s21_list.size());
}

TEST(Constructors, init_size) {
  std::list<int> std_list(5);
  s21::List<int> s21_list(5);

  ASSERT_EQ(std_list.size(), s21_list.size());
}

TEST(Constructors, init_values) {
  std::list<int> std_list{1, 2, 3, 4, 5, 6};
  s21::List<int> s21_list{1, 2, 3, 4, 5, 6};
  auto it = std_list.begin();

  ASSERT_EQ(std_list.size(), s21_list.size());
  for (auto v : s21_list) {
    ASSERT_EQ(v, *it);
    ++it;
  }
}

TEST(Constructors, copy) {
  std::list<int> std_list(5);
  std::list<int> std_list_copy(std_list);
  s21::List<int> s21_list(5);
  s21::List<int> s21_list_copy(s21_list);

  ASSERT_EQ(std_list.size(), s21_list.size());
}

TEST(Constructors, copy_2) {
  s21::List<int> s21_list = {1, 2, 3};
  std::list<int> std_list = {1, 2, 3};
  s21::List<int> s21_copy(s21_list);
  std::list<int> std_copy(std_list);
  auto it = std_list.begin();

  ASSERT_EQ(std_list.size(), s21_list.size());
  for (auto v : s21_list) {
    ASSERT_EQ(v, *it);
    ++it;
  }
}

TEST(Operators, copy) {
  s21::List<int> s21_list = {1, 2, 3};
  std::list<int> std_list = {1, 2, 3};
  s21::List<int> s21_copy;
  s21_copy = s21_list;
  std::list<int> std_copy;
  std_copy = std_list;
  EXPECT_EQ(s21_copy.front(), std_copy.front());
  EXPECT_EQ(s21_copy.back(), std_copy.back());
}

TEST(Operators, move) {
  s21::List<int> s21_list = {1, 2, 3};
  std::list<int> std_list = {1, 2, 3};
  s21::List<int> s21_copy(std::move(s21_list));
  std::list<int> std_copy(std::move(std_list));
  EXPECT_EQ(s21_copy.front(), std_copy.front());
  EXPECT_EQ(s21_copy.back(), std_copy.back());
  EXPECT_EQ(s21_list.empty(), std_list.empty());
}

TEST(Methods, push_front) {
  s21::List<int> s21_list;
  std::list<int> std_list;
  s21_list.push_front(1);
  std_list.push_front(1);
  EXPECT_EQ(s21_list.front(), std_list.front());
  EXPECT_EQ(s21_list.back(), std_list.back());
  s21_list.push_front(2);
  std_list.push_front(2);
  EXPECT_EQ(s21_list.front(), std_list.front());
  EXPECT_EQ(s21_list.back(), std_list.back());
  s21_list.push_front(3);
  std_list.push_front(3);
  EXPECT_EQ(s21_list.front(), std_list.front());
  EXPECT_EQ(s21_list.back(), std_list.back());
}

TEST(Methods, push_back) {
  s21::List<int> s21_list;
  std::list<int> std_list;
  s21_list.push_back(1);
  std_list.push_back(1);
  EXPECT_EQ(s21_list.front(), std_list.front());
  EXPECT_EQ(s21_list.back(), std_list.back());
  s21_list.push_back(2);
  std_list.push_back(2);
  EXPECT_EQ(s21_list.front(), std_list.front());
  EXPECT_EQ(s21_list.back(), std_list.back());
  s21_list.push_back(3);
  std_list.push_back(3);
  EXPECT_EQ(s21_list.front(), std_list.front());
  EXPECT_EQ(s21_list.back(), std_list.back());
}

TEST(Methods, pop_front) {
  s21::List<int> s21_list;
  std::list<int> std_list;
  s21_list.push_back(1);
  std_list.push_back(1);
  EXPECT_EQ(s21_list.front(), std_list.front());
  EXPECT_EQ(s21_list.back(), std_list.back());
  s21_list.push_back(2);
  std_list.push_back(2);
  EXPECT_EQ(s21_list.front(), std_list.front());
  EXPECT_EQ(s21_list.back(), std_list.back());
  s21_list.push_back(3);
  std_list.push_back(3);
  EXPECT_EQ(s21_list.front(), std_list.front());
  EXPECT_EQ(s21_list.back(), std_list.back());
  s21_list.pop_front();
  std_list.pop_front();
  EXPECT_EQ(s21_list.front(), std_list.front());
  EXPECT_EQ(s21_list.back(), std_list.back());
}

TEST(Methods, pop_back) {
  s21::List<int> s21_list;
  std::list<int> std_list;
  s21_list.push_back(1);
  std_list.push_back(1);
  EXPECT_EQ(s21_list.front(), std_list.front());
  EXPECT_EQ(s21_list.back(), std_list.back());
  s21_list.push_back(2);
  std_list.push_back(2);
  EXPECT_EQ(s21_list.front(), std_list.front());
  EXPECT_EQ(s21_list.back(), std_list.back());
  s21_list.push_back(3);
  std_list.push_back(3);
  EXPECT_EQ(s21_list.front(), std_list.front());
  EXPECT_EQ(s21_list.back(), std_list.back());
  s21_list.pop_back();
  std_list.pop_back();
  EXPECT_EQ(s21_list.front(), std_list.front());
  EXPECT_EQ(s21_list.back(), std_list.back());
}

// при создании анологичного std`шного листа почему то
// malloc(): corrupted top size
TEST(Iterators, variative_front_increment) {
  s21::List<int> s21_list = {1, 2, 3};
  s21::List<int>::iterator s21_it = s21_list.begin();
  EXPECT_EQ(*s21_it, 1);
  ++s21_it;
  EXPECT_EQ(*s21_it, 2);
  --s21_it;
  EXPECT_EQ(*s21_it, 1);
}

TEST(Iterators, variative_back_increment) {
  s21::List<int> s21_list = {1, 2, 3};
  s21::List<int>::iterator s21_it = s21_list.end();
  s21_it++;
  EXPECT_EQ(*s21_it, 1);
  s21_it--;
  s21_it--;
  EXPECT_EQ(*s21_it, 3);
}

TEST(Methods, insert) {
  s21::List<int> s21_list;
  std::list<int> std_list;
  s21::List<int>::iterator s21_it;
  s21_it = s21_list.begin();
  std::list<int>::iterator std_it;
  std_it = std_list.begin();
  s21_list.insert(s21_it, 5);
  std_list.insert(std_it, 5);
  EXPECT_EQ(s21_list.front(), std_list.front());
  EXPECT_EQ(s21_list.back(), std_list.back());
  s21_list.insert(s21_it, 7);
  std_list.insert(std_it, 7);
  s21_list.insert(s21_it, 9);
  std_list.insert(std_it, 9);
  EXPECT_EQ(s21_list.front(), std_list.front());
  EXPECT_EQ(s21_list.back(), std_list.back());
}

TEST(Methods, erase) {
  s21::List<int> s21_list = {1, 2, 3, 4, 5};
  std::list<int> std_list = {1, 2, 3, 4, 5};
  s21_list.erase(s21_list.begin());
  std_list.erase(std_list.begin());
  EXPECT_EQ(s21_list.front(), std_list.front());
  EXPECT_EQ(s21_list.back(), std_list.back());
  s21::List<int>::iterator s21_it;
  s21_it = s21_list.begin();
  ++s21_it;
  std::list<int>::iterator std_it;
  std_it = std_list.begin();
  ++std_it;
  EXPECT_EQ(s21_list.front(), std_list.front());
  EXPECT_EQ(s21_list.back(), std_list.back());
}

TEST(Methods, splice) {
  s21::List<int> s21_list_first = {1};
  s21::List<int> s21_list_second = {2, 3, 4, 5};
  std::list<int> std_list_first = {1};
  std::list<int> std_list_second = {2, 3, 4, 5};
  s21::List<int>::iterator s21_it = s21_list_first.begin();
  std::list<int>::iterator std_it = std_list_first.begin();
  s21_list_first.splice(s21_it, s21_list_second);
  std_list_first.splice(std_it, std_list_second);
  EXPECT_EQ(s21_list_first.front(), std_list_first.front());
  EXPECT_EQ(s21_list_first.back(), std_list_first.back());
}

TEST(Methods, merge) {
  s21::List<int> s21_list_first = {1};
  s21::List<int> s21_list_second = {2, 3, 4, 5};
  std::list<int> std_list_first = {1};
  std::list<int> std_list_second = {2, 3, 4, 5};
  s21_list_first.merge(s21_list_second);
  std_list_first.merge(std_list_second);
  EXPECT_EQ(s21_list_first.front(), std_list_first.front());
  EXPECT_EQ(s21_list_first.back(), std_list_first.back());
  EXPECT_EQ(s21_list_second.empty(), std_list_second.empty());
}

TEST(Methods, reverse) {
  s21::List<int> s21_list = {1, 2, 3, 4, 5};
  std::list<int> std_list = {1, 2, 3, 4, 5};
  s21_list.reverse();
  std_list.reverse();
  EXPECT_EQ(s21_list.front(), std_list.front());
  EXPECT_EQ(s21_list.back(), std_list.back());
}

TEST(Methods, unique) {
  s21::List<int> s21_list = {1, 2, 2, 3, 3};
  std::list<int> std_list = {1, 2, 2, 3, 3};
  s21_list.unique();
  std_list.unique();
  auto s21_pos = s21_list.begin();
  auto std_pos = std_list.begin();
  for (; s21_pos != s21_list.end(); ++s21_pos, ++std_pos)
    EXPECT_EQ(*s21_pos, *std_pos);
}

TEST(Methods, sort) {
  s21::List<int> s21_list = {2, 4, 1, 3, 5};
  std::list<int> std_list = {2, 4, 1, 3, 5};
  s21_list.sort();
  std_list.sort();
  auto s21_pos = s21_list.begin();
  auto std_pos = std_list.begin();
  for (; s21_pos != s21_list.end(); ++s21_pos, ++std_pos)
    EXPECT_EQ(*s21_pos, *std_pos);
}

TEST(Methods, PushPopBack) {
  s21::List<int> s21_list;
  std::list<int> std_list;
  s21_list.push_back(1);
  std_list.push_back(1);
  ASSERT_EQ(std_list.back(), s21_list.back());
  s21_list.pop_back();
  std_list.pop_back();
  ASSERT_EQ(std_list.size(), s21_list.size());
}

TEST(Methods, PushPopFront) {
  s21::List<int> s21_list;
  std::list<int> std_list;
  s21_list.push_front(1);
  std_list.push_front(1);
  ASSERT_EQ(std_list.front(), s21_list.front());
  s21_list.pop_front();
  std_list.pop_front();
  ASSERT_EQ(std_list.size(), s21_list.size());
}

TEST(Methods, Clear) {
  s21::List<int> s21_list = {1, 2, 3};
  std::list<int> std_list = {1, 2, 3};
  s21_list.clear();
  std_list.clear();
  ASSERT_EQ(std_list.size(), s21_list.size());
}

TEST(Methods, Insert) {
  s21::List<int> s21_list = {1, 3};
  std::list<int> std_list = {1, 3};
  auto it_s21 = s21_list.begin();
  ++it_s21;
  auto it_std = std_list.begin();
  ++it_std;
  s21_list.insert(it_s21, 2);
  std_list.insert(it_std, 2);
  ASSERT_EQ(std_list.size(), s21_list.size());
  ASSERT_EQ(*it_std, *it_s21);
}

TEST(Methods, SizeAfterOperations) {
  s21::List<int> s21_list = {1, 2, 3, 4, 5};
  std::list<int> std_list = {1, 2, 3, 4, 5};
  s21_list.insert(++s21_list.begin(), 0);
  std_list.insert(++std_list.begin(), 0);
  s21_list.erase(--s21_list.end());
  std_list.erase(--std_list.end());
  ASSERT_EQ(std_list.size(), s21_list.size());
}

TEST(Methods, Swap) {
  s21::List<int> list1 = {1, 2, 3};
  s21::List<int> list2 = {4, 5, 6};
  std::list<int> std_list1 = {1, 2, 3};
  std::list<int> std_list2 = {4, 5, 6};

  list1.swap(list2);
  std_list1.swap(std_list2);

  ASSERT_EQ(list1.front(), std_list1.front());
  ASSERT_EQ(list2.front(), std_list2.front());
}

TEST(Bonus, insert_many) {
  std::list<int> std_list = {1, 3, 5};
  s21::List<int> s21_list = {1, 3, 5};
  auto s21_pos = s21_list.begin();
  auto std_pos = std_list.begin();
  s21_list.insert_many(s21_pos, 7, 9, 0);
  std_list.insert(std_pos, {7, 9, 0});

  for (; s21_pos != s21_list.end(); ++s21_pos, ++std_pos)
    ASSERT_EQ(*s21_pos, *std_pos);
}

TEST(Bonus, insert_many_front) {
  std::list<int> std_list = {1, 3, 5};
  s21::List<int> s21_list = {1, 3, 5};
  auto s21_pos = s21_list.begin();
  auto std_pos = std_list.begin();
  s21_list.insert_many_front(7, 9, 0);
  std_list.insert(std_pos, {7, 9, 0});

  for (; s21_pos != s21_list.end(); ++s21_pos, ++std_pos)
    ASSERT_EQ(*s21_pos, *std_pos);
}

TEST(Bonus, insert_many_back) {
  std::list<int> std_list = {1, 3, 5, 12};
  s21::List<int> s21_list = {1, 3, 5, 12};
  auto s21_pos = s21_list.end();
  auto std_pos = std_list.end();
  s21_list.insert_many_back(7, 9, 11);
  std_list.insert(std_pos, {7, 9, 11});
  --s21_pos;
  --std_pos;

  for (; s21_pos != s21_list.begin(); --s21_pos, --std_pos)
    ASSERT_EQ(*s21_pos, *std_pos);
}

TEST(EdgeCases, EmptyContainer) {
  s21::List<int> s21_list;
  ASSERT_TRUE(s21_list.empty());
}

TEST(EdgeCases, InsertEraseEmpty) {
  s21::List<int> s21_list;
  s21_list.push_front(1);
  ASSERT_EQ(s21_list.size(), 1);
  s21_list.pop_front();
  ASSERT_TRUE(s21_list.empty());
}

TEST(EdgeCases, CopyEmptyContainer) {
  s21::List<int> original;
  s21::List<int> copy = original;
  ASSERT_TRUE(copy.empty());
}