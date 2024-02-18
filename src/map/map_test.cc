#include <gtest/gtest.h>

#include <map>
#include <string>

#include "../s21_containers.h"

TEST(TestMapMapСonstructor, DefaultConstructor) {
  s21::map<int, int> m;
  std::map<int, int> m2;
  ASSERT_EQ(m.size(), m2.size());
}

TEST(TestMapСonstructor, InitializerListConstructor) {
  s21::map<int, int> m{{1, 100}, {-3, 100}, {6, 100}, {4, 50}};
  std::map<int, int> m2{{1, 100}, {-3, 100}, {6, 100}, {4, 50}};
  ASSERT_EQ(m[1], m2[1]);
  ASSERT_EQ(m[-3], m2[-3]);
  ASSERT_EQ(m[6], m2[6]);
  ASSERT_EQ(m[4], m2[4]);
}

TEST(TestMapСonstructor, InitializerListConstructorSecond) {
  s21::map<int, int> m{{1, 10}, {-3, 20}, {6, 30},  {4, 40},
                       {3, 50}, {-1, 60}, {-10, 70}};
  std::map<int, int> m2{{1, 10}, {-3, 20}, {6, 30},  {4, 40},
                        {3, 50}, {-1, 60}, {-10, 70}};
  ASSERT_EQ(m[1], m2[1]);
  ASSERT_EQ(m[-3], m2[-3]);
  ASSERT_EQ(m[6], m2[6]);
  ASSERT_EQ(m[4], m2[4]);
  ASSERT_EQ(m[3], m2[3]);
  ASSERT_EQ(m[-10], m2[-10]);
  ASSERT_EQ(m[3], m2[3]);
  ASSERT_EQ(m[-1], m2[-1]);
}

TEST(TestMapСonstructor, InitializerListConstructorThird) {
  s21::map<std::string, int> m{{"this", 1}, {"sentence", 2}, {"is", 3},
                               {"not", 4},  {"a", 5},        {"word", 6}};
  std::map<std::string, int> m2{{"this", 1}, {"sentence", 2}, {"is", 3},
                                {"not", 4},  {"a", 5},        {"word", 6}};
  ASSERT_EQ(m["this"], m2["this"]);
  ASSERT_EQ(m["sentence"], m2["sentence"]);
  ASSERT_EQ(m["is"], m2["is"]);
  ASSERT_EQ(m["not"], m2["not"]);
  ASSERT_EQ(m["a"], m2["a"]);
  ASSERT_EQ(m["word"], m2["word"]);
}

TEST(TestMapСonstructor, CopyConstructor) {
  s21::map<int, int> m{{1, 10}, {-3, 100}, {6, 100}, {4, 50}};
  s21::map<int, int> m3(m);
  std::map<int, int> m2{{1, 10}, {-3, 100}, {6, 100}, {4, 50}};
  std::map<int, int> m4(m2);
  ASSERT_EQ(m3[1], m4[1]);
  ASSERT_EQ(m3[-3], m4[-3]);
  ASSERT_EQ(m3[6], m4[6]);
  ASSERT_EQ(m3[4], m4[4]);
}

TEST(TestMapСonstructor, CopyConstructorSecond) {
  s21::map<int, int> m{{1, 10}, {-3, 20}, {6, 30},  {4, 40},
                       {3, 50}, {-1, 60}, {-10, 70}};
  std::map<int, int> m2{{1, 10}, {-3, 20}, {6, 30},  {4, 40},
                        {3, 50}, {-1, 60}, {-10, 70}};
  s21::map<int, int> m3(m);
  std::map<int, int> m4(m2);
  ASSERT_EQ(m3[1], m4[1]);
  ASSERT_EQ(m3[-3], m4[-3]);
  ASSERT_EQ(m3[6], m4[6]);
  ASSERT_EQ(m3[4], m4[4]);
  ASSERT_EQ(m3[3], m4[3]);
  ASSERT_EQ(m3[-10], m4[-10]);
  ASSERT_EQ(m3[3], m4[3]);
  ASSERT_EQ(m3[-1], m4[-1]);
}

TEST(TestMapСonstructor, CopyConstructorThird) {
  s21::map<std::string, int> m{{"this", 1}, {"sentence", 2}, {"is", 3},
                               {"not", 4},  {"a", 5},        {"word", 6}};
  std::map<std::string, int> m2{{"this", 1}, {"sentence", 2}, {"is", 3},
                                {"not", 4},  {"a", 5},        {"word", 6}};
  s21::map<std::string, int> m3(m);
  std::map<std::string, int> m4(m2);
  ASSERT_EQ(m3["this"], m4["this"]);
  ASSERT_EQ(m3["sentence"], m4["sentence"]);
  ASSERT_EQ(m3["is"], m4["is"]);
  ASSERT_EQ(m3["not"], m4["not"]);
  ASSERT_EQ(m3["a"], m4["a"]);
  ASSERT_EQ(m3["word"], m4["word"]);
}

TEST(TestMapСonstructor, MoveConstructor) {
  s21::map<int, int> m{{1, 10}, {-3, 100}, {6, 100}, {4, 50}};
  s21::map<int, int> m3(std::move(m));
  std::map<int, int> m2{{1, 10}, {-3, 100}, {6, 100}, {4, 50}};
  std::map<int, int> m4(std::move(m2));
  ASSERT_EQ(m3[1], m4[1]);
  ASSERT_EQ(m3[-3], m4[-3]);
  ASSERT_EQ(m3[6], m4[6]);
  ASSERT_EQ(m3[4], m4[4]);
}

TEST(TestMapСonstructor, MoveConstructorSecond) {
  s21::map<int, int> m{{1, 10}, {-3, 20}, {6, 30},  {4, 40},
                       {3, 50}, {-1, 60}, {-10, 70}};
  std::map<int, int> m2{{1, 10}, {-3, 20}, {6, 30},  {4, 40},
                        {3, 50}, {-1, 60}, {-10, 70}};
  s21::map<int, int> m3(std::move(m));
  std::map<int, int> m4(std::move(m2));
  ASSERT_EQ(m3[1], m4[1]);
  ASSERT_EQ(m3[-3], m4[-3]);
  ASSERT_EQ(m3[6], m4[6]);
  ASSERT_EQ(m3[4], m4[4]);
  ASSERT_EQ(m3[3], m4[3]);
  ASSERT_EQ(m3[-10], m4[-10]);
  ASSERT_EQ(m3[3], m4[3]);
  ASSERT_EQ(m3[-1], m4[-1]);
}

TEST(TestMapСonstructor, MoveConstructorThird) {
  s21::map<std::string, int> m{{"this", 1}, {"sentence", 2}, {"is", 3},
                               {"not", 4},  {"a", 5},        {"word", 6}};
  std::map<std::string, int> m2{{"this", 1}, {"sentence", 2}, {"is", 3},
                                {"not", 4},  {"a", 5},        {"word", 6}};
  s21::map<std::string, int> m3(std::move(m));
  std::map<std::string, int> m4(std::move(m2));
  ASSERT_EQ(m3["this"], m4["this"]);
  ASSERT_EQ(m3["sentence"], m4["sentence"]);
  ASSERT_EQ(m3["is"], m4["is"]);
  ASSERT_EQ(m3["not"], m4["not"]);
  ASSERT_EQ(m3["a"], m4["a"]);
  ASSERT_EQ(m3["word"], m4["word"]);
}

TEST(TestMapOperator, OperatorFirst) {
  s21::map<int, int> m{{1, 10}, {-3, 100}, {6, 100}, {4, 50}};
  s21::map<int, int> m3 = m;
  std::map<int, int> m2{{1, 10}, {-3, 100}, {6, 100}, {4, 50}};
  std::map<int, int> m4 = m2;
  ASSERT_EQ(m3[1], m4[1]);
  ASSERT_EQ(m3[-3], m4[-3]);
  ASSERT_EQ(m3[6], m4[6]);
  ASSERT_EQ(m3[4], m4[4]);
}

TEST(TestMapOperator, OperatorSecond) {
  s21::map<std::string, int> m{{"this", 1}, {"sentence", 2}, {"is", 3},
                               {"not", 4},  {"a", 5},        {"word", 6}};
  std::map<std::string, int> m2{{"this", 1}, {"sentence", 2}, {"is", 3},
                                {"not", 4},  {"a", 5},        {"word", 6}};
  s21::map<std::string, int> m3 = m;
  std::map<std::string, int> m4 = m2;
  ASSERT_EQ(m3["this"], m4["this"]);
  ASSERT_EQ(m3["sentence"], m4["sentence"]);
  ASSERT_EQ(m3["is"], m4["is"]);
  ASSERT_EQ(m3["not"], m4["not"]);
  ASSERT_EQ(m3["a"], m4["a"]);
  ASSERT_EQ(m3["word"], m4["word"]);
}

TEST(TestMapOperator, OperatorThird) {
  s21::map<int, int> m{{1, 10}, {-3, 100}, {6, 100}, {4, 50}};
  s21::map<int, int> m3 = std::move(m);
  std::map<int, int> m2{{1, 10}, {-3, 100}, {6, 100}, {4, 50}};
  std::map<int, int> m4 = std::move(m2);
  ASSERT_EQ(m3[1], m4[1]);
  ASSERT_EQ(m3[-3], m4[-3]);
  ASSERT_EQ(m3[6], m4[6]);
  ASSERT_EQ(m3[4], m4[4]);
}

TEST(TestMapOperator, OperatorFourth) {
  s21::map<std::string, int> m{{"this", 1}, {"sentence", 2}, {"is", 3},
                               {"not", 4},  {"a", 5},        {"word", 6}};
  std::map<std::string, int> m2{{"this", 1}, {"sentence", 2}, {"is", 3},
                                {"not", 4},  {"a", 5},        {"word", 6}};
  s21::map<std::string, int> m3 = std::move(m);
  std::map<std::string, int> m4 = std::move(m2);
  ASSERT_EQ(m3["this"], m4["this"]);
  ASSERT_EQ(m3["sentence"], m4["sentence"]);
  ASSERT_EQ(m3["is"], m4["is"]);
  ASSERT_EQ(m3["not"], m4["not"]);
  ASSERT_EQ(m3["a"], m4["a"]);
  ASSERT_EQ(m3["word"], m4["word"]);
}

TEST(TestMapSize, SizeFirst) {
  s21::map<int, int> m{{1, 100}, {-3, 100}, {6, 100}, {4, 50}};
  std::map<int, int> m2{{1, 100}, {-3, 100}, {6, 100}, {4, 50}};
  ASSERT_EQ(m.size(), m2.size());
}

TEST(TestMapSize, SizeSecond) {
  s21::map<int, int> m;
  std::map<int, int> m2;
  ASSERT_EQ(m.size(), m2.size());
}

TEST(TestMapMaxSize, MaxSizeFirst) {
  s21::map<int, int> m{{1, 100}, {-3, 100}, {6, 100}};
  std::map<int, int> m2{{1, 100}, {-3, 100}, {6, 100}};
  //   ASSERT_EQ(m.max_size(), m2.max_size());
}

TEST(TestMapMaxSize, MaxSizeSecond) {
  s21::map<int, int> m;
  std::map<int, int> m2;
  //   ASSERT_EQ(m.max_size(), m2.max_size());
}

TEST(TestMapMaxSize, MaxSizeThird) {
  s21::map<char, int> m{{'t', 1}, {'s', 2}, {'i', 3},
                        {'n', 4}, {'a', 5}, {'w', 6}};
  std::map<char, int> m2{{'t', 1}, {'s', 2}, {'i', 3},
                         {'n', 4}, {'a', 5}, {'w', 6}};
  //   ASSERT_EQ(m.max_size(), m2.max_size());
}

TEST(TestMapClear, ClearFirst) {
  s21::map<int, int> m{{1, 100}, {-3, 100}, {6, 100}, {4, 50}};
  std::map<int, int> m2{{1, 100}, {-3, 100}, {6, 100}, {4, 50}};
  m.clear();
  m2.clear();
  ASSERT_EQ(m.size(), m2.size());
}

TEST(TestMapClear, ClearSecond) {
  s21::map<int, int> m{{1, 100}, {-3, 100}, {6, 100}, {4, 50}, {-12, 45}};
  std::map<int, int> m2{{1, 100}, {-3, 100}, {6, 100}, {4, 50}, {-12, 45}};
  m.clear();
  m2.clear();
  ASSERT_EQ(m.size(), m2.size());
}

TEST(TestMapClear, ClearThird) {
  s21::map<int, int> m;
  std::map<int, int> m2;
  m.clear();
  m2.clear();
  ASSERT_EQ(m.size(), m2.size());
}

TEST(TestMapEmpty, EmptyFirst) {
  s21::map<int, int> m{{1, 100}, {-3, 100}, {6, 100}, {4, 50}};
  std::map<int, int> m2{{1, 100}, {-3, 100}, {6, 100}, {4, 50}};
  ASSERT_EQ(m.empty(), m2.empty());
}

TEST(TestMapEmpty, EmptySecond) {
  s21::map<int, int> m;
  std::map<int, int> m2;
  ASSERT_EQ(m.empty(), m2.empty());
}

TEST(TestMapContains, ContainsFirst) {
  s21::map<int, int> m{{1, 100}, {-3, 100}, {6, 100}, {4, 50}};
  ASSERT_EQ(m.contains(1), true);
  ASSERT_EQ(m.contains(-3), true);
  ASSERT_EQ(m.contains(6), true);
  ASSERT_EQ(m.contains(4), true);
}

TEST(TestMapContains, ContainsSecond) {
  s21::map<int, int> m;
  ASSERT_EQ(m.contains(10), false);
  ASSERT_EQ(m.contains(-8), false);
}

TEST(TestMapIterator, IteratorFirst) {
  s21::map<int, int> m{{1, 100}, {-3, 100}, {6, 100}, {4, 50}};
  std::map<int, int> m2{{1, 100}, {-3, 100}, {6, 100}, {4, 50}};
  auto it = m.begin();
  auto i = m2.begin();
  ASSERT_EQ((*it).first, (*i).first);
  ASSERT_EQ((*it).second, (*i).second);
}

TEST(TestMapIterator, IteratorSecond) {
  s21::map<int, int> m{{1, 100}, {-3, 100}, {6, 100}, {4, 50}};
  std::map<int, int> m2{{1, 100}, {-3, 100}, {6, 100}, {4, 50}};
  auto it = m.begin();
  auto i = m2.begin();
  it++;
  i++;
  ASSERT_EQ((*it).first, (*i).first);
  ASSERT_EQ((*it).second, (*i).second);
}

TEST(TestMapIterator, IteratorThird) {
  s21::map<int, int> m{{1, 100}, {-3, 100}, {6, 100}, {4, 50}};
  std::map<int, int> m2{{1, 100}, {-3, 100}, {6, 100}, {4, 50}};
  auto it = m.end();
  auto i = m2.end();
  --it;
  --i;
  ASSERT_EQ((*it).first, (*i).first);
  ASSERT_EQ((*it).second, (*i).second);
}

TEST(TestMapIterator, IteratorFourth) {
  s21::map<int, int> m = {{20, 4}};
  auto it = m.begin();
  it++;
}

TEST(TestMapIterator, IteratorFifth) {
  s21::map<std::string, int> m{{"this", 1}, {"sentence", 2}, {"is", 3},
                               {"not", 4},  {"a", 5},        {"word", 6}};
  std::map<std::string, int> m2{{"this", 1}, {"sentence", 2}, {"is", 3},
                                {"not", 4},  {"a", 5},        {"word", 6}};
  auto it = m.end();
  auto i = m2.end();
  --it;
  --it;
  --it;
  --i;
  --i;
  --i;
  ASSERT_EQ((*it).first, (*i).first);
  ASSERT_EQ((*it).second, (*i).second);
}

TEST(TestMapIterator, IteratorSixth) {
  s21::map<int, int> m = {{20, 4}, {10, 3}, {4, 3},  {2, 2},  {5, 2},  {16, 3},
                          {3, 1},  {14, 2}, {17, 2}, {12, 2}, {15, 2}, {11, 1},
                          {19, 1}, {25, 3}, {23, 2}, {30, 2}};
  std::map<int, int> m2 = {{20, 4}, {10, 3}, {4, 3},  {2, 2},  {5, 2},  {16, 3},
                           {3, 1},  {14, 2}, {17, 2}, {12, 2}, {15, 2}, {11, 1},
                           {19, 1}, {25, 3}, {23, 2}, {30, 2}};
  auto it = m.begin();
  auto i = m2.begin();
  ASSERT_EQ((*it).first, (*i).first);
  ASSERT_EQ((*it).second, (*i).second);
  it++;
  i++;
  ASSERT_EQ((*it).first, (*i).first);
  ASSERT_EQ((*it).second, (*i).second);
  it++;
  i++;
  ASSERT_EQ((*it).first, (*i).first);
  ASSERT_EQ((*it).second, (*i).second);
  it++;
  i++;
  ASSERT_EQ((*it).first, (*i).first);
  ASSERT_EQ((*it).second, (*i).second);
  it++;
  i++;
  ASSERT_EQ((*it).first, (*i).first);
  ASSERT_EQ((*it).second, (*i).second);
  it++;
  i++;
  ASSERT_EQ((*it).first, (*i).first);
  ASSERT_EQ((*it).second, (*i).second);
  it++;
  i++;
  ASSERT_EQ((*it).first, (*i).first);
  ASSERT_EQ((*it).second, (*i).second);
  it++;
  i++;
  ASSERT_EQ((*it).first, (*i).first);
  ASSERT_EQ((*it).second, (*i).second);
  it++;
  i++;
  ASSERT_EQ((*it).first, (*i).first);
  ASSERT_EQ((*it).second, (*i).second);
  it++;
  i++;
  ASSERT_EQ((*it).first, (*i).first);
  ASSERT_EQ((*it).second, (*i).second);
  it++;
  i++;
  ASSERT_EQ((*it).first, (*i).first);
  ASSERT_EQ((*it).second, (*i).second);
  it++;
  i++;
  ASSERT_EQ((*it).first, (*i).first);
  ASSERT_EQ((*it).second, (*i).second);
}

TEST(TestMapIterator, IteratorSeventh) {
  s21::map<int, int> m = {{20, 4}, {10, 3}, {4, 3},  {2, 2},  {5, 2},  {16, 3},
                          {3, 1},  {14, 2}, {17, 2}, {12, 2}, {15, 2}, {11, 1},
                          {19, 1}, {25, 3}, {23, 2}, {30, 2}};
  std::map<int, int> m2 = {{20, 4}, {10, 3}, {4, 3},  {2, 2},  {5, 2},  {16, 3},
                           {3, 1},  {14, 2}, {17, 2}, {12, 2}, {15, 2}, {11, 1},
                           {19, 1}, {25, 3}, {23, 2}, {30, 2}};
  auto it = m.end();
  auto i = m2.end();
  it--;
  i--;
  ASSERT_EQ((*it).first, (*i).first);
  ASSERT_EQ((*it).second, (*i).second);
  it--;
  i--;
  ASSERT_EQ((*it).first, (*i).first);
  ASSERT_EQ((*it).second, (*i).second);
  it--;
  i--;
  ASSERT_EQ((*it).first, (*i).first);
  ASSERT_EQ((*it).second, (*i).second);
  it--;
  i--;
  ASSERT_EQ((*it).first, (*i).first);
  ASSERT_EQ((*it).second, (*i).second);
  it--;
  i--;
  ASSERT_EQ((*it).first, (*i).first);
  ASSERT_EQ((*it).second, (*i).second);
  it--;
  i--;
  ASSERT_EQ((*it).first, (*i).first);
  ASSERT_EQ((*it).second, (*i).second);
  it--;
  i--;
  ASSERT_EQ((*it).first, (*i).first);
  ASSERT_EQ((*it).second, (*i).second);
  it--;
  i--;
  ASSERT_EQ((*it).first, (*i).first);
  ASSERT_EQ((*it).second, (*i).second);
  it--;
  i--;
  ASSERT_EQ((*it).first, (*i).first);
  ASSERT_EQ((*it).second, (*i).second);
  it--;
  i--;
  ASSERT_EQ((*it).first, (*i).first);
  ASSERT_EQ((*it).second, (*i).second);
  it--;
  i--;
  ASSERT_EQ((*it).first, (*i).first);
  ASSERT_EQ((*it).second, (*i).second);
}

TEST(TestMapConstIterator, ConstIteratorFirst) {
  s21::map<int, int> m{{1, 100}, {-3, 100}, {6, 100}, {4, 50}};
  std::map<int, int> m2{{1, 100}, {-3, 100}, {6, 100}, {4, 50}};
  auto it = m.cbegin();
  auto i = m2.cbegin();
  ASSERT_EQ((*it).first, (*i).first);
  ASSERT_EQ((*it).second, (*i).second);
}

TEST(TestMapConstIterator, ConstIteratorSecond) {
  s21::map<int, int> m{{1, 100}, {-3, 100}, {6, 100}, {4, 50}};
  std::map<int, int> m2{{1, 100}, {-3, 100}, {6, 100}, {4, 50}};
  auto it = m.cbegin();
  auto i = m2.cbegin();
  it++;
  i++;
  ASSERT_EQ((*it).first, (*i).first);
  ASSERT_EQ((*it).second, (*i).second);
}

TEST(TestMapIteratorConst, IteratorThird) {
  s21::map<int, int> m{{1, 100}, {-3, 100}, {6, 100}, {4, 50}};
  std::map<int, int> m2{{1, 100}, {-3, 100}, {6, 100}, {4, 50}};
  auto it = m.cend();
  auto i = m2.cend();
  --it;
  --i;
  ASSERT_EQ((*it).first, (*i).first);
  ASSERT_EQ((*it).second, (*i).second);
}

TEST(TestMapIteratorConst, IteratorConstFifth) {
  s21::map<std::string, int> m{{"this", 1}, {"sentence", 2}, {"is", 3},
                               {"not", 4},  {"a", 5},        {"word", 6}};
  std::map<std::string, int> m2{{"this", 1}, {"sentence", 2}, {"is", 3},
                                {"not", 4},  {"a", 5},        {"word", 6}};
  auto it = m.cend();
  auto i = m2.cend();
  --it;
  --it;
  --it;
  --i;
  --i;
  --i;
  ASSERT_EQ((*it).first, (*i).first);
  ASSERT_EQ((*it).second, (*i).second);
}

TEST(TestMapConstIterator, IteratorConstSixth) {
  s21::map<int, int> m = {{20, 4}, {10, 3}, {4, 3},  {2, 2},  {5, 2},  {16, 3},
                          {3, 1},  {14, 2}, {17, 2}, {12, 2}, {15, 2}, {11, 1},
                          {19, 1}, {25, 3}, {23, 2}, {30, 2}};
  std::map<int, int> m2 = {{20, 4}, {10, 3}, {4, 3},  {2, 2},  {5, 2},  {16, 3},
                           {3, 1},  {14, 2}, {17, 2}, {12, 2}, {15, 2}, {11, 1},
                           {19, 1}, {25, 3}, {23, 2}, {30, 2}};
  auto it = m.cbegin();
  auto i = m2.cbegin();
  ASSERT_EQ((*it).first, (*i).first);
  ASSERT_EQ((*it).second, (*i).second);
  it++;
  i++;
  ASSERT_EQ((*it).first, (*i).first);
  ASSERT_EQ((*it).second, (*i).second);
  it++;
  i++;
  ASSERT_EQ((*it).first, (*i).first);
  ASSERT_EQ((*it).second, (*i).second);
  it++;
  i++;
  ASSERT_EQ((*it).first, (*i).first);
  ASSERT_EQ((*it).second, (*i).second);
  it++;
  i++;
  ASSERT_EQ((*it).first, (*i).first);
  ASSERT_EQ((*it).second, (*i).second);
  it++;
  i++;
  ASSERT_EQ((*it).first, (*i).first);
  ASSERT_EQ((*it).second, (*i).second);
  it++;
  i++;
  ASSERT_EQ((*it).first, (*i).first);
  ASSERT_EQ((*it).second, (*i).second);
  it++;
  i++;
  ASSERT_EQ((*it).first, (*i).first);
  ASSERT_EQ((*it).second, (*i).second);
  it++;
  i++;
  ASSERT_EQ((*it).first, (*i).first);
  ASSERT_EQ((*it).second, (*i).second);
  it++;
  i++;
  ASSERT_EQ((*it).first, (*i).first);
  ASSERT_EQ((*it).second, (*i).second);
  it++;
  i++;
  ASSERT_EQ((*it).first, (*i).first);
  ASSERT_EQ((*it).second, (*i).second);
  it++;
  i++;
  ASSERT_EQ((*it).first, (*i).first);
  ASSERT_EQ((*it).second, (*i).second);
}

TEST(TestMapConstIterator, IteratorConstSeventh) {
  s21::map<int, int> m = {{20, 4}, {10, 3}, {4, 3},  {2, 2},  {5, 2},  {16, 3},
                          {3, 1},  {14, 2}, {17, 2}, {12, 2}, {15, 2}, {11, 1},
                          {19, 1}, {25, 3}, {23, 2}, {30, 2}};
  std::map<int, int> m2 = {{20, 4}, {10, 3}, {4, 3},  {2, 2},  {5, 2},  {16, 3},
                           {3, 1},  {14, 2}, {17, 2}, {12, 2}, {15, 2}, {11, 1},
                           {19, 1}, {25, 3}, {23, 2}, {30, 2}};
  auto it = m.cend();
  auto i = m2.cend();
  it--;
  i--;
  ASSERT_EQ((*it).first, (*i).first);
  ASSERT_EQ((*it).second, (*i).second);
  it--;
  i--;
  ASSERT_EQ((*it).first, (*i).first);
  ASSERT_EQ((*it).second, (*i).second);
  it--;
  i--;
  ASSERT_EQ((*it).first, (*i).first);
  ASSERT_EQ((*it).second, (*i).second);
  it--;
  i--;
  ASSERT_EQ((*it).first, (*i).first);
  ASSERT_EQ((*it).second, (*i).second);
  it--;
  i--;
  ASSERT_EQ((*it).first, (*i).first);
  ASSERT_EQ((*it).second, (*i).second);
  it--;
  i--;
  ASSERT_EQ((*it).first, (*i).first);
  ASSERT_EQ((*it).second, (*i).second);
  it--;
  i--;
  ASSERT_EQ((*it).first, (*i).first);
  ASSERT_EQ((*it).second, (*i).second);
  it--;
  i--;
  ASSERT_EQ((*it).first, (*i).first);
  ASSERT_EQ((*it).second, (*i).second);
  it--;
  i--;
  ASSERT_EQ((*it).first, (*i).first);
  ASSERT_EQ((*it).second, (*i).second);
  it--;
  i--;
  ASSERT_EQ((*it).first, (*i).first);
  ASSERT_EQ((*it).second, (*i).second);
  it--;
  i--;
  ASSERT_EQ((*it).first, (*i).first);
  ASSERT_EQ((*it).second, (*i).second);
}

TEST(TestMapIterator, IteratorOperatorFirst) {
  s21::map<int, int> m{{1, 100}, {-3, 100}, {6, 100}, {4, 50}};
  std::map<int, int> m2{{1, 100}, {-3, 100}, {6, 100}, {4, 50}};
  auto it = m.begin();
  auto it2 = m.begin();
  auto i = m2.begin();
  auto i2 = m2.begin();
  bool result1 = ((*it).first == (*it2).first);
  bool result2 = (i->first == i2->first);
  ASSERT_EQ(result1, result2);
}

TEST(TestMapIterator, IteratorOperatorSecond) {
  s21::map<int, int> m{{1, 100}, {-3, 100}, {6, 100}, {4, 50}};
  std::map<int, int> m2{{1, 100}, {-3, 100}, {6, 100}, {4, 50}};
  auto it = m.begin();
  it++;
  auto it2 = m.begin();
  auto i = m2.begin();
  i++;
  auto i2 = m2.begin();
  bool result1 = ((*it).first == (*it2).first);
  bool result2 = (i->first == i2->first);
  ASSERT_EQ(result1, result2);
}

TEST(TestMapIterator, IteratorOperatorThird) {
  s21::map<int, int> m{{1, 100}, {-3, 100}, {6, 100}, {4, 50}};
  std::map<int, int> m2{{1, 100}, {-3, 100}, {6, 100}, {4, 50}};
  auto it = m.begin();
  auto it2 = m.begin();
  auto i = m2.begin();
  auto i2 = m2.begin();
  bool result1 = ((*it).first != (*it2).first);
  bool result2 = (i->first != i2->first);
  ASSERT_EQ(result1, result2);
}

TEST(TestMapIterator, IteratorOperatorFourth) {
  s21::map<int, int> m{{1, 100}, {-3, 100}, {6, 100}, {4, 50}};
  std::map<int, int> m2{{1, 100}, {-3, 100}, {6, 100}, {4, 50}};
  auto it = m.begin();
  it++;
  auto it2 = m.begin();
  auto i = m2.begin();
  i++;
  auto i2 = m2.begin();
  bool result1 = ((*it).first != (*it2).first);
  bool result2 = (i->first != i2->first);
  ASSERT_EQ(result1, result2);
}

TEST(TestMapIterator, IteratorOperatorFifth) {
  s21::map<int, int> m{{1, 100}, {-3, 100}, {6, 100}, {4, 50}};
  std::map<int, int> m2{{1, 100}, {-3, 100}, {6, 100}, {4, 50}};
  auto it = m.begin();
  it++;
  auto it2 = m.begin();
  auto i = m2.begin();
  i++;
  auto i2 = m2.begin();
  bool result1 = ((*it).first != (*it2).first);
  bool result2 = (i->first != i2->first);
  ASSERT_EQ(result1, result2);
}

TEST(TestMapIterator, IteratorOperatorSixth) {
  s21::map<int, int> m{{5, 40}, {-33, 12}};
  std::map<int, int> m2{{1, 100}, {-3, 100}, {6, 100}, {4, 50}};
  auto it = m.begin();
  it++;
  auto i = m2.begin();
  i++;
  bool result1 = ((*it).first != (*i).first);
  ASSERT_EQ(result1, true);
}

TEST(TestMapIterator, IteratorOperatorSeventh) {
  s21::map<int, int> m{{5, 40}, {-33, 12}};
  std::map<int, int> m2{{1, 100}, {-3, 100}, {6, 100}, {4, 50}};
  auto it = m.begin();
  auto i = m2.begin();
  bool result1 = ((*it).first == (*i).first);
  ASSERT_EQ(result1, false);
}

TEST(TestMapIterator, IteratorOperatorEighth) {
  s21::map<int, int> m{{5, 40}, {-33, 12}};
  std::map<int, int> m2{{1, 100}, {-3, 100}, {6, 100}, {4, 50}};
  auto it = m.begin();
  it++;
  auto i = m2.begin();
  i++;
  bool result1 = ((*it).first != (*i).first);
  ASSERT_EQ(result1, true);
}

TEST(TestMapIterator, IteratorOperatorNinth) {
  s21::map<int, int> m = {{1, 100}, {-3, 100}, {6, 100}, {4, 50}};
  std::map<int, int> m2 = {{5, 40}, {-33, 12}};
  auto it = m.begin();
  auto i = m2.begin();
  bool result1 = ((*it).first == (*i).first);
  ASSERT_EQ(result1, false);
}

TEST(TestMapConstIterator, ConstIteratorOperatorFirst) {
  s21::map<int, int> m{{1, 100}, {-3, 100}, {6, 100}, {4, 50}};
  std::map<int, int> m2{{1, 100}, {-3, 100}, {6, 100}, {4, 50}};
  auto it = m.cbegin();
  auto it2 = m.cbegin();
  auto i = m2.cbegin();
  auto i2 = m2.cbegin();
  bool result1 = ((*it).first == (*it2).first);
  bool result2 = (i->first == i2->first);
  ASSERT_EQ(result1, result2);
}

TEST(TestMapConstIterator, IteratorConstOperatorSecond) {
  s21::map<int, int> m{{1, 100}, {-3, 100}, {6, 100}, {4, 50}};
  std::map<int, int> m2{{1, 100}, {-3, 100}, {6, 100}, {4, 50}};
  auto it = m.cbegin();
  it++;
  auto it2 = m.cbegin();
  auto i = m2.cbegin();
  i++;
  auto i2 = m2.cbegin();
  bool result1 = ((*it).first == (*it2).first);
  bool result2 = (i->first == i2->first);
  ASSERT_EQ(result1, result2);
}

TEST(TestMapConstIterator, IteratorConstOperatorThird) {
  s21::map<int, int> m{{1, 100}, {-3, 100}, {6, 100}, {4, 50}};
  std::map<int, int> m2{{1, 100}, {-3, 100}, {6, 100}, {4, 50}};
  auto it = m.cbegin();
  auto it2 = m.cbegin();
  auto i = m2.cbegin();
  auto i2 = m2.cbegin();
  bool result1 = ((*it).first != (*it2).first);
  bool result2 = (i->first != i2->first);
  ASSERT_EQ(result1, result2);
}

TEST(TestMapConstIterator, IteratorConstOperatorFourth) {
  s21::map<int, int> m{{1, 100}, {-3, 100}, {6, 100}, {4, 50}};
  std::map<int, int> m2{{1, 100}, {-3, 100}, {6, 100}, {4, 50}};
  auto it = m.cbegin();
  it++;
  auto it2 = m.cbegin();
  auto i = m2.cbegin();
  i++;
  auto i2 = m2.cbegin();
  bool result1 = ((*it).first != (*it2).first);
  bool result2 = (i->first != i2->first);
  ASSERT_EQ(result1, result2);
}

TEST(TestMapConstIterator, IteratorConstOperatorSixth) {
  s21::map<int, int> m{{5, 40}, {-33, 12}};
  std::map<int, int> m2{{1, 100}, {-3, 100}, {6, 100}, {4, 50}};
  auto it = m.cbegin();
  it++;
  auto i = m2.cbegin();
  i++;
  bool result1 = ((*it).first != (*i).first);
  ASSERT_EQ(result1, true);
}

TEST(TestMapConstIterator, IteratorConstOperatorSeventh) {
  s21::map<int, int> m{{5, 40}, {-33, 12}};
  std::map<int, int> m2{{1, 100}, {-3, 100}, {6, 100}, {4, 50}};
  auto it = m.cbegin();
  auto i = m2.cbegin();
  bool result1 = ((*it).first == (*i).first);
  ASSERT_EQ(result1, false);
}

TEST(TestMapConstIterator, IteratorConstOperatorEighth) {
  s21::map<int, int> m{{5, 40}, {-33, 12}};
  std::map<int, int> m2{{1, 100}, {-3, 100}, {6, 100}, {4, 50}};
  auto it = m.cbegin();
  it++;
  auto i = m2.cbegin();
  i++;
  bool result1 = ((*it).first != (*i).first);
  ASSERT_EQ(result1, true);
}

TEST(TestMapConstIterator, IteratorConstOperatorNinth) {
  s21::map<int, int> m = {{1, 100}, {-3, 100}, {6, 100}, {4, 50}};
  std::map<int, int> m2 = {{5, 40}, {-33, 12}};
  auto it = m.cbegin();
  auto i = m2.cbegin();
  bool result1 = ((*it).first == (*i).first);
  ASSERT_EQ(result1, false);
}

TEST(TestMapSwap, SwapFirst) {
  s21::map<int, int> m{{1, 100}, {-3, 100}, {6, 100}, {4, 50}};
  std::map<int, int> m2{{1, 100}, {-3, 100}, {6, 100}, {4, 50}};
  s21::map<int, int> m3{{2, 40}, {-4, 23}};
  std::map<int, int> m4{{2, 40}, {-4, 23}};
  m.swap(m3);
  auto i = m.begin();
  auto it = m3.begin();
  auto i2 = m.end();
  i2--;
  auto it2 = m3.end();
  it2--;
  m2.swap(m4);
  auto ite = m2.begin();
  auto iter = m4.begin();
  auto ite2 = m2.end();
  ite2--;
  auto iter2 = m4.end();
  iter2--;
  ASSERT_EQ((*i).first, ite->first);
  ASSERT_EQ((*it).first, iter->first);
  ASSERT_EQ((*i2).first, ite2->first);
  ASSERT_EQ((*it2).first, iter2->first);
}

TEST(TestMapSwap, SwapSecond) {
  s21::map<int, int> m{{2, 40}, {-4, 23}};
  std::map<int, int> m2{{2, 40}, {-4, 23}};
  s21::map<int, int> m3{{1, 100}, {-3, 100}, {6, 100}, {4, 50}};
  std::map<int, int> m4{{1, 100}, {-3, 100}, {6, 100}, {4, 50}};
  m.swap(m3);
  auto i = m.begin();
  auto it = m3.begin();
  auto i2 = m.end();
  i2--;
  auto it2 = m3.end();
  it2--;
  m2.swap(m4);
  auto ite = m2.begin();
  auto iter = m4.begin();
  auto ite2 = m2.end();
  ite2--;
  auto iter2 = m4.end();
  iter2--;
  ASSERT_EQ((*i).first, ite->first);
  ASSERT_EQ((*it).first, iter->first);
  ASSERT_EQ((*i2).first, ite2->first);
  ASSERT_EQ((*it2).first, iter2->first);
}

TEST(TestMapSwap, SwapThird) {
  s21::map<int, int> m{{2, 40}, {-4, 23}, {6, 7}, {10, -6}};
  std::map<int, int> m2{{2, 40}, {-4, 23}, {6, 7}, {10, -6}};
  s21::map<int, int> m3{{1, 100}, {-3, 100}, {6, 100}, {4, 50}};
  std::map<int, int> m4{{1, 100}, {-3, 100}, {6, 100}, {4, 50}};
  m.swap(m3);
  auto i = m.begin();
  auto it = m3.begin();
  auto i2 = m.end();
  i2--;
  auto it2 = m3.end();
  it2--;
  m2.swap(m4);
  auto ite = m2.begin();
  auto iter = m4.begin();
  auto ite2 = m2.end();
  ite2--;
  auto iter2 = m4.end();
  iter2--;
  ASSERT_EQ((*i).first, ite->first);
  ASSERT_EQ((*it).first, iter->first);
  ASSERT_EQ((*i2).first, ite2->first);
  ASSERT_EQ((*it2).first, iter2->first);
}

TEST(TestMapInsert, InsertFirst) {
  s21::map<int, int> m;
  std::pair<int, int> value = {1, 2};
  m.insert(value);
  value = {3, 4};
  m.insert(value);
  value = {5, 6};
  m.insert(value);
  value = {2, 3};
  m.insert(value);
  value = {-1, -9};
  m.insert(value);
  value = {-4, -9};
  m.insert(value);
  ASSERT_EQ(m[3], 4);
  ASSERT_EQ(m[5], 6);
  ASSERT_EQ(m[2], 3);
  ASSERT_EQ(m[-1], -9);
  ASSERT_EQ(m[-4], -9);
  ASSERT_EQ(m.size(), 6u);
}

TEST(TestMapInsert, InsertSecond) {
  s21::map<int, int> m = {{-5, 100}};
  std::pair<int, int> value = {1, 2};
  m.insert(value);
  value = {3, 4};
  m.insert(value);
  value = {5, 6};
  m.insert(value);
  value = {2, 3};
  m.insert(value);
  value = {-1, -9};
  m.insert(value);
  value = {-4, -9};
  m.insert(value);
  ASSERT_EQ(m[-5], 100);
  ASSERT_EQ(m[1], 2);
  ASSERT_EQ(m[3], 4);
  ASSERT_EQ(m[5], 6);
  ASSERT_EQ(m[2], 3);
  ASSERT_EQ(m[-1], -9);
  ASSERT_EQ(m[-4], -9);
  ASSERT_EQ(m.size(), 7u);
}

TEST(TestMapInsert, InsertFifth) {
  s21::map<int, int> m;
  std::pair<int, int> value = {1, 2};
  m.insert(value);
  value = {3, 4};
  m.insert(value);
  value = {5, 6};
  m.insert(value);
  value = {2, 3};
  m.insert(value);
  value = {-1, -9};
  m.insert(value);
  value = {-4, -9};
  m.insert(value);
  ASSERT_EQ(m[1], 2);
  ASSERT_EQ(m[3], 4);
  ASSERT_EQ(m[5], 6);
  ASSERT_EQ(m[2], 3);
  ASSERT_EQ(m[-1], -9);
  ASSERT_EQ(m[-4], -9);
  ASSERT_EQ(m.size(), 6u);
}

TEST(TestMapInsert, InsertThird) {
  s21::map<int, int> m;
  std::pair<int, int> value = {1, 2};
  auto it = m.insert(value);
  std::map<int, int> m2;
  auto i = m2.insert(value);
  ASSERT_EQ(i.first->first, (*it.first).first);
  ASSERT_EQ(i.second, it.second);
}

TEST(TestMapInsert, InsertFourth) {
  s21::map<int, int> m;
  //   m.insert(1, 2);
  //   m.insert(3, 4);
  //   m.insert(5, 6);
  //   m.insert(2, 3);
  //   m.insert(-1, -9);
  //   m.insert(-4, -9);
  m.insert(std::make_pair<int, int>(1, 2));
  m.insert(std::make_pair<int, int>(3, 4));
  m.insert(std::make_pair<int, int>(5, 6));
  m.insert(std::make_pair<int, int>(2, 3));
  m.insert(std::make_pair<int, int>(-1, -9));
  m.insert(std::make_pair<int, int>(-4, -9));

  ASSERT_EQ(m[3], 4);
  ASSERT_EQ(m[5], 6);
  ASSERT_EQ(m[2], 3);
  ASSERT_EQ(m[-1], -9);
  ASSERT_EQ(m[-4], -9);
  ASSERT_EQ(m.size(), 6u);
}

TEST(TestMapInsert, InsertSixth) {
  s21::map<int, int> m;
  auto it = m.insert(std::make_pair<int, int>(1, 2));
  ASSERT_EQ(1, (*it.first).first);
  ASSERT_EQ(2, (*it.first).second);
  ASSERT_EQ(true, it.second);
}

TEST(TestMapInsert, InsertSeventh) {
  s21::map<int, int> m;
  auto it = m.insert(std::make_pair<int, int>(20, 4));
  ASSERT_EQ(20, (*it.first).first);
  ASSERT_EQ(4, (*it.first).second);
  ASSERT_EQ(true, it.second);
  it = m.insert(std::make_pair<int, int>(10, 3));
  ASSERT_EQ(10, (*it.first).first);
  ASSERT_EQ(3, (*it.first).second);
  ASSERT_EQ(true, it.second);
  it = m.insert(std::make_pair<int, int>(4, 3));
  ASSERT_EQ(4, (*it.first).first);
  ASSERT_EQ(3, (*it.first).second);
  ASSERT_EQ(true, it.second);
  it = m.insert(std::make_pair<int, int>(2, 2));
  ASSERT_EQ(2, (*it.first).first);
  ASSERT_EQ(2, (*it.first).second);
  ASSERT_EQ(true, it.second);
  it = m.insert(std::make_pair<int, int>(5, 2));
  ASSERT_EQ(5, (*it.first).first);
  ASSERT_EQ(2, (*it.first).second);
  ASSERT_EQ(true, it.second);
  it = m.insert(std::make_pair<int, int>(16, 3));
  ASSERT_EQ(16, (*it.first).first);
  ASSERT_EQ(3, (*it.first).second);
  ASSERT_EQ(true, it.second);
  it = m.insert(std::make_pair<int, int>(3, 1));
  ASSERT_EQ(3, (*it.first).first);
  ASSERT_EQ(1, (*it.first).second);
  ASSERT_EQ(true, it.second);
  it = m.insert(std::make_pair<int, int>(14, 2));
  ASSERT_EQ(14, (*it.first).first);
  ASSERT_EQ(2, (*it.first).second);
  ASSERT_EQ(true, it.second);
  it = m.insert(std::make_pair<int, int>(17, 2));
  ASSERT_EQ(17, (*it.first).first);
  ASSERT_EQ(2, (*it.first).second);
  ASSERT_EQ(true, it.second);
  it = m.insert(std::make_pair<int, int>(12, 2));
  ASSERT_EQ(12, (*it.first).first);
  ASSERT_EQ(2, (*it.first).second);
  ASSERT_EQ(true, it.second);
  it = m.insert(std::make_pair<int, int>(15, 2));
  ASSERT_EQ(15, (*it.first).first);
  ASSERT_EQ(2, (*it.first).second);
  ASSERT_EQ(true, it.second);
  it = m.insert(std::make_pair<int, int>(11, 1));
  ASSERT_EQ(11, (*it.first).first);
  ASSERT_EQ(1, (*it.first).second);
  ASSERT_EQ(true, it.second);
  it = m.insert(std::make_pair(19, 1));
  ASSERT_EQ(19, (*it.first).first);
  ASSERT_EQ(1, (*it.first).second);
  ASSERT_EQ(true, it.second);
  it = m.insert(std::make_pair(25, 3));
  ASSERT_EQ(25, (*it.first).first);
  ASSERT_EQ(3, (*it.first).second);
  ASSERT_EQ(true, it.second);
  it = m.insert(std::make_pair(23, 2));
  ASSERT_EQ(23, (*it.first).first);
  ASSERT_EQ(2, (*it.first).second);
  ASSERT_EQ(true, it.second);
  it = m.insert(std::make_pair(30, 2));
  ASSERT_EQ(30, (*it.first).first);
  ASSERT_EQ(2, (*it.first).second);
  ASSERT_EQ(true, it.second);
  it = m.insert(std::make_pair(1, 4));
  ASSERT_EQ(1, (*it.first).first);
  ASSERT_EQ(4, (*it.first).second);
  ASSERT_EQ(true, it.second);
}

TEST(TestMapInsert, InsertEighth) {
  s21::map<std::string, char> m{{"sentence", 'b'}, {"not", 'd'}, {"word", 'e'}};
  m.insert(std::make_pair<std::string, char>("this", 'a'));
  m.insert({"is", 'c'});
  m.insert({"a", 'f'});
  ASSERT_EQ(m["this"], 'a');
  ASSERT_EQ(m["is"], 'c');
  ASSERT_EQ(m["a"], 'f');
  ASSERT_EQ(m["sentence"], 'b');
  ASSERT_EQ(m["not"], 'd');
  ASSERT_EQ(m["word"], 'e');
  ASSERT_EQ(m.size(), 6u);
}

// TEST(TestMapInsertOrAssign, InsertOrAssignFirst) {
//   s21::map<int, int> m;
//   m.insert_or_assign(1, 2);
//   m.insert_or_assign(3, 4);
//   m.insert_or_assign(5, 6);
//   m.insert_or_assign(2, 3);
//   m.insert_or_assign(-1, -9);
//   m.insert_or_assign(-4, -9);
//   ASSERT_EQ(m[1], 2);
//   ASSERT_EQ(m[3], 4);
//   ASSERT_EQ(m[5], 6);
//   ASSERT_EQ(m[2], 3);
//   ASSERT_EQ(m[-1], -9);
//   ASSERT_EQ(m[-4], -9);
//   ASSERT_EQ(m.size(), 6u);
// }

// TEST(TestMapInsertOrAssign, InsertOrAssignSecond) {
//   s21::map<int, int> m = {{-5, 100}};
//   m.insert_or_assign(1, 2);
//   m.insert_or_assign(3, 4);
//   m.insert_or_assign(5, 6);
//   m.insert_or_assign(2, 3);
//   m.insert_or_assign(-1, -9);
//   m.insert_or_assign(-4, -9);
//   ASSERT_EQ(m[-5], 100);
//   ASSERT_EQ(m[1], 2);
//   ASSERT_EQ(m[3], 4);
//   ASSERT_EQ(m[5], 6);
//   ASSERT_EQ(m[2], 3);
//   ASSERT_EQ(m[-1], -9);
//   ASSERT_EQ(m[-4], -9);
//   ASSERT_EQ(m.size(), 7u);
// }

// TEST(TestMapInsertOrAssign, InsertOrAssignThird) {
//   s21::map<int, int> m = {{-5, 100}};
//   auto iter = m.insert_or_assign(-5, 100);
//   std::map<int, int> m2 = {{-5, 100}};
//   auto it = m2.insert_or_assign(-5, 100);
//   ASSERT_EQ(iter.second, it.second);
//   ASSERT_EQ(it.first->first, (*iter.first).first);
//   ASSERT_EQ(m.size(), 1u);
// }

// TEST(TestMapInsertOrAssign, InsertOrAssignFourth) {
//   s21::map<int, int> m = {{20, 4}, {10, 3}, {2, 2},  {5, 2},  {16, 3},
//                                  {14, 2}, {17, 2}, {12, 2}, {15, 2}, {11, 1},
//                                  {19, 1}, {25, 3}, {23, 2}, {30, 2}};
//   m.insert_or_assign(1, 2);
//   m.insert_or_assign(3, 4);
//   m.insert_or_assign(-1, -9);
//   m.insert_or_assign(-4, -9);
//   ASSERT_EQ(m.size(), 18u);
//   ASSERT_EQ(m[20], 4);
//   ASSERT_EQ(m[10], 3);
//   ASSERT_EQ(m[2], 2);
//   ASSERT_EQ(m[5], 2);
//   ASSERT_EQ(m[16], 3);
//   ASSERT_EQ(m[14], 2);
//   ASSERT_EQ(m[17], 2);
//   ASSERT_EQ(m[12], 2);
//   ASSERT_EQ(m[15], 2);
//   ASSERT_EQ(m[11], 1);
//   ASSERT_EQ(m[19], 1);
//   ASSERT_EQ(m[25], 3);
//   ASSERT_EQ(m[23], 2);
//   ASSERT_EQ(m[30], 2);
//   ASSERT_EQ(m[1], 2);
//   ASSERT_EQ(m[3], 4);
//   ASSERT_EQ(m[-1], -9);
//   ASSERT_EQ(m[-4], -9);
// }

// TEST(TestMapInsertOrAssign, InsertOrAssignFifth) {
//   s21::map<int, int> m = {{20, 4}, {10, 3}, {2, 2},  {5, 2},  {16, 3},
//                                  {14, 2}, {17, 2}, {12, 2}, {15, 2}, {11, 1},
//                                  {19, 1}, {25, 3}, {23, 2}, {30, 2}};
//   auto iter = m.insert_or_assign(20, 4);
//   std::map<int, int> m2 = {{20, 4}, {10, 3}, {2, 2},  {5, 2},  {16, 3},
//                            {14, 2}, {17, 2}, {12, 2}, {15, 2}, {11, 1},
//                            {19, 1}, {25, 3}, {23, 2}, {30, 2}};
//   auto it = m2.insert_or_assign(20, 4);
//   ASSERT_EQ(m.size(), 14u);
//   ASSERT_EQ(m[20], 4);
//   ASSERT_EQ(m[10], 3);
//   ASSERT_EQ(m[2], 2);
//   ASSERT_EQ(m[5], 2);
//   ASSERT_EQ(m[16], 3);
//   ASSERT_EQ(m[14], 2);
//   ASSERT_EQ(m[17], 2);
//   ASSERT_EQ(m[12], 2);
//   ASSERT_EQ(m[15], 2);
//   ASSERT_EQ(m[11], 1);
//   ASSERT_EQ(m[19], 1);
//   ASSERT_EQ(m[25], 3);
//   ASSERT_EQ(m[23], 2);
//   ASSERT_EQ(m[30], 2);
//   ASSERT_EQ(iter.second, it.second);
//   ASSERT_EQ(it.first->first, (*iter.first).first);
// }

TEST(TestMapOperatorBracket, OperatorBracketFirst) {
  s21::map<int, int> m = {{-5, 100}};
  ASSERT_EQ(m[-5], 100);
}

TEST(TestMapOperatorBracket, OperatorBracketSecond) {
  s21::map<int, char> m = {{-5, 'a'}};
  ASSERT_EQ(m[-5], 'a');
}

TEST(TestMapOperatorAt, OperatorAt) {
  s21::map<int, int> m = {{-5, 100}};
  EXPECT_ANY_THROW(m.at(1));
}

TEST(TestMapOperatorAt, OperatorAtSecond) {
  s21::map<int, int> m = {{-5, 100}};
  ASSERT_EQ(m.at(-5), 100);
}

TEST(TestMapMerge, MergeFirst) {
  s21::map<int, int> m = {{-5, 100}};
  s21::map<int, int> m2 = {{1, 10}, {-3, 20}, {6, 30},  {4, 40},
                           {3, 50}, {-1, 60}, {-10, 70}};
  m.merge(m2);
  ASSERT_EQ(m.size(), 8u);
  ASSERT_EQ(m[-5], 100);
  ASSERT_EQ(m[1], 10);
  ASSERT_EQ(m[-3], 20);
  ASSERT_EQ(m[6], 30);
  ASSERT_EQ(m[4], 40);
  ASSERT_EQ(m[3], 50);
  ASSERT_EQ(m[-1], 60);
  ASSERT_EQ(m[-10], 70);
}

TEST(TestMapMerge, MergeSecond) {
  s21::map<int, int> m = {{1, 10}, {-3, 20}, {6, 30},  {4, 40},
                          {3, 50}, {-1, 60}, {-10, 70}};
  s21::map<int, int> m2 = {{-5, 100}};
  m.merge(m2);
  ASSERT_EQ(m.size(), 8u);
  ASSERT_EQ(m[-5], 100);
  ASSERT_EQ(m[1], 10);
  ASSERT_EQ(m[-3], 20);
  ASSERT_EQ(m[6], 30);
  ASSERT_EQ(m[4], 40);
  ASSERT_EQ(m[3], 50);
  ASSERT_EQ(m[-1], 60);
  ASSERT_EQ(m[-10], 70);
}

TEST(TestMapMerge, MergeThird) {
  s21::map<int, int> m = {{1, 10}, {-3, 20}, {6, 30},  {4, 40},
                          {3, 50}, {-1, 60}, {-10, 70}};
  s21::map<int, int> m2 = {{20, 4}, {10, 3}, {2, 2},  {5, 2},  {16, 3},
                           {14, 2}, {17, 2}, {12, 2}, {15, 2}, {11, 1},
                           {19, 1}, {25, 3}, {23, 2}, {30, 2}};
  m.merge(m2);
  ASSERT_EQ(m.size(), 21u);
  ASSERT_EQ(m[1], 10);
  ASSERT_EQ(m[-3], 20);
  ASSERT_EQ(m[6], 30);
  ASSERT_EQ(m[4], 40);
  ASSERT_EQ(m[3], 50);
  ASSERT_EQ(m[-1], 60);
  ASSERT_EQ(m[-10], 70);
  ASSERT_EQ(m[20], 4);
  ASSERT_EQ(m[10], 3);
  ASSERT_EQ(m[2], 2);
  ASSERT_EQ(m[5], 2);
  ASSERT_EQ(m[16], 3);
  ASSERT_EQ(m[14], 2);
  ASSERT_EQ(m[17], 2);
  ASSERT_EQ(m[12], 2);
  ASSERT_EQ(m[15], 2);
  ASSERT_EQ(m[11], 1);
  ASSERT_EQ(m[19], 1);
  ASSERT_EQ(m[25], 3);
  ASSERT_EQ(m[23], 2);
  ASSERT_EQ(m[30], 2);
}

TEST(TestMapErase, EraseFirst) {
  s21::map<int, int> m = {{1, 10}, {-3, 20}, {6, 30},  {4, 40},
                          {3, 50}, {-1, 60}, {-10, 70}};
  auto it = m.begin();
  m.erase(it);
  ASSERT_EQ(m.size(), 6u);
  ASSERT_EQ(m[1], 10);
  ASSERT_EQ(m[-1], 60);
  ASSERT_EQ(m[6], 30);
  ASSERT_EQ(m[4], 40);
  ASSERT_EQ(m[3], 50);
}

TEST(TestMapErase, EraseSecond) {
  s21::map<int, int> m = {{1, 10}};
  auto it = m.begin();
  m.erase(it);
  ASSERT_EQ(m.size(), 0u);
}

TEST(TestMapErase, EraseThird) {
  s21::map<int, int> m = {{100, 10}, {90, 20}, {10, 30}, {150, 40}, {50, 50}};
  auto it = m.begin();
  m.erase(it);
  ASSERT_EQ(m.size(), 4u);
  ASSERT_EQ(m[100], 10);
  ASSERT_EQ(m[90], 20);
  ASSERT_EQ(m[150], 40);
  ASSERT_EQ(m[50], 50);
}

TEST(TestMapErase, EraseFourth) {
  s21::map<int, int> m = {{1, 10}, {-3, 20}, {6, 30},   {4, 40},
                          {3, 50}, {-1, 60}, {-10, 70}, {-11, 110}};
  auto it = m.begin();
  it++;
  m.erase(it);
  ASSERT_EQ(m.size(), 7u);
  ASSERT_EQ(m[1], 10);
  ASSERT_EQ(m[-1], 60);
  ASSERT_EQ(m[6], 30);
  ASSERT_EQ(m[4], 40);
  ASSERT_EQ(m[3], 50);
  ASSERT_EQ(m[-11], 110);
}

TEST(TestMapErase, EraseFifth) {
  s21::map<int, int> m = {{1, 10}, {-3, 20}, {6, 30},  {4, 40},
                          {3, 50}, {-1, 60}, {-10, 70}};
  auto it = m.begin();
  it++;
  m.erase(it);
  ASSERT_EQ(m.size(), 6u);
  ASSERT_EQ(m[1], 10);
  ASSERT_EQ(m[-1], 60);
  ASSERT_EQ(m[6], 30);
  ASSERT_EQ(m[4], 40);
  ASSERT_EQ(m[3], 50);
  ASSERT_EQ(m[-10], 70);
}

TEST(TestMapErase, EraseSixth) {
  s21::map<int, int> m = {{20, 4}, {10, 3}, {4, 3},  {2, 2},  {5, 2},  {16, 3},
                          {3, 1},  {14, 2}, {17, 2}, {12, 2}, {15, 2}, {11, 1},
                          {19, 1}, {25, 3}, {23, 2}, {30, 2}};
  auto it = m.begin();
  it++;
  it++;
  it++;
  it++;
  it++;
  it++;
  it++;
  it++;
  m.erase(it);
  ASSERT_EQ(m.size(), 15u);
  ASSERT_EQ(m[20], 4);
  ASSERT_EQ(m[10], 3);
  ASSERT_EQ(m[4], 3);
  ASSERT_EQ(m[2], 2);
  ASSERT_EQ(m[5], 2);
  ASSERT_EQ(m[16], 3);
  ASSERT_EQ(m[3], 1);
  ASSERT_EQ(m[14], 2);
  ASSERT_EQ(m[17], 2);
  ASSERT_EQ(m[12], 2);
  ASSERT_EQ(m[11], 1);
  ASSERT_EQ(m[19], 1);
  ASSERT_EQ(m[25], 3);
  ASSERT_EQ(m[23], 2);
  ASSERT_EQ(m[30], 2);
}

TEST(TestMapErase, EraseSeventh) {
  s21::map<int, int> m = {{20, 4}, {10, 3}, {4, 3},  {2, 2},  {5, 2},  {16, 3},
                          {3, 1},  {14, 2}, {17, 2}, {12, 2}, {15, 2}, {11, 1},
                          {19, 1}, {25, 3}, {23, 2}, {30, 2}};
  auto it = m.begin();
  it++;
  it++;
  it++;
  it++;
  it++;
  it++;
  it++;
  m.erase(it);
  ASSERT_EQ(m.size(), 15u);
  ASSERT_EQ(m[20], 4);
  ASSERT_EQ(m[10], 3);
  ASSERT_EQ(m[4], 3);
  ASSERT_EQ(m[2], 2);
  ASSERT_EQ(m[5], 2);
  ASSERT_EQ(m[16], 3);
  ASSERT_EQ(m[3], 1);
  ASSERT_EQ(m[17], 2);
  ASSERT_EQ(m[12], 2);
  ASSERT_EQ(m[15], 2);
  ASSERT_EQ(m[11], 1);
  ASSERT_EQ(m[19], 1);
  ASSERT_EQ(m[25], 3);
  ASSERT_EQ(m[23], 2);
  ASSERT_EQ(m[30], 2);
}

TEST(TestMapErase, EraseEighth) {
  s21::map<int, int> m = {{20, 4}, {10, 3}, {4, 3},  {2, 2},  {5, 2},  {16, 3},
                          {3, 1},  {14, 2}, {17, 2}, {12, 2}, {15, 2}, {11, 1},
                          {19, 1}, {25, 3}, {23, 2}, {30, 2}};
  auto it = m.begin();
  it++;
  it++;
  it++;
  it++;
  it++;
  it++;
  m.erase(it);
  ASSERT_EQ(m.size(), 15u);
  ASSERT_EQ(m[20], 4);
  ASSERT_EQ(m[10], 3);
  ASSERT_EQ(m[4], 3);
  ASSERT_EQ(m[2], 2);
  ASSERT_EQ(m[5], 2);
  ASSERT_EQ(m[16], 3);
  ASSERT_EQ(m[3], 1);
  ASSERT_EQ(m[15], 2);
  ASSERT_EQ(m[17], 2);
  ASSERT_EQ(m[14], 2);
  ASSERT_EQ(m[11], 1);
  ASSERT_EQ(m[19], 1);
  ASSERT_EQ(m[25], 3);
  ASSERT_EQ(m[23], 2);
  ASSERT_EQ(m[30], 2);
}

TEST(TestMapErase, EraseNinth) {
  s21::map<int, int> m = {{20, 4}, {10, 3}, {4, 3},  {2, 2},  {5, 2},  {16, 3},
                          {3, 1},  {14, 2}, {17, 2}, {12, 2}, {15, 2}, {11, 1},
                          {19, 1}, {25, 3}, {23, 2}, {30, 2}};
  auto it = m.begin();
  it++;
  it++;
  it++;
  it++;
  it++;
  m.erase(it);
  ASSERT_EQ(m.size(), 15u);
  ASSERT_EQ(m[20], 4);
  ASSERT_EQ(m[10], 3);
  ASSERT_EQ(m[4], 3);
  ASSERT_EQ(m[2], 2);
  ASSERT_EQ(m[5], 2);
  ASSERT_EQ(m[16], 3);
  ASSERT_EQ(m[3], 1);
  ASSERT_EQ(m[15], 2);
  ASSERT_EQ(m[17], 2);
  ASSERT_EQ(m[14], 2);
  ASSERT_EQ(m[12], 2);
  ASSERT_EQ(m[19], 1);
  ASSERT_EQ(m[25], 3);
  ASSERT_EQ(m[23], 2);
  ASSERT_EQ(m[30], 2);
}

// TEST(TestMapErase, EraseTenth) {
//   s21::map<int, int> m = {
//       {20, 4}, {10, 3}, {4, 3},  {2, 2},  {5, 2},  {16, 3}, {3, 1},  {14, 2},
//       {17, 2}, {12, 2}, {15, 2}, {11, 1}, {19, 1}, {25, 3}, {23, 2}, {30,
//       2}};
//   auto it = m.begin();
//   it++;
//   it++;
//   it++;
//   it++;
//   m.erase(it);
//   ASSERT_EQ(m.size(), 15u);
//   ASSERT_EQ(m[20], 4);
//   ASSERT_EQ(m[11], 1);
//   ASSERT_EQ(m[4], 3);
//   ASSERT_EQ(m[2], 2);
//   ASSERT_EQ(m[5], 2);
//   ASSERT_EQ(m[16], 3);
//   ASSERT_EQ(m[3], 1);
//   ASSERT_EQ(m[15], 2);
//   ASSERT_EQ(m[17], 2);
//   ASSERT_EQ(m[14], 2);
//   ASSERT_EQ(m[12], 2);
//   ASSERT_EQ(m[19], 1);
//   ASSERT_EQ(m[25], 3);
//   ASSERT_EQ(m[23], 2);
//   ASSERT_EQ(m[30], 2);
// }

TEST(TestMapErase, EraseEleventh) {
  s21::map<int, int> m = {{20, 4}, {10, 3}, {4, 3},  {2, 2},  {5, 2},  {16, 3},
                          {3, 1},  {14, 2}, {17, 2}, {12, 2}, {15, 2}, {11, 1},
                          {19, 1}, {25, 3}, {23, 2}, {30, 2}};
  auto it = m.begin();
  it++;
  it++;
  it++;
  m.erase(it);
  ASSERT_EQ(m.size(), 15u);
  ASSERT_EQ(m[20], 4);
  ASSERT_EQ(m[11], 1);
  ASSERT_EQ(m[4], 3);
  ASSERT_EQ(m[2], 2);
  ASSERT_EQ(m[10], 3);
  ASSERT_EQ(m[16], 3);
  ASSERT_EQ(m[3], 1);
  ASSERT_EQ(m[15], 2);
  ASSERT_EQ(m[17], 2);
  ASSERT_EQ(m[14], 2);
  ASSERT_EQ(m[12], 2);
  ASSERT_EQ(m[19], 1);
  ASSERT_EQ(m[25], 3);
  ASSERT_EQ(m[23], 2);
  ASSERT_EQ(m[30], 2);
}

TEST(TestMapErase, EraseTwelfth) {
  s21::map<int, int> m = {{20, 4}, {10, 3}, {4, 3},  {2, 2},  {5, 2},  {16, 3},
                          {3, 1},  {14, 2}, {17, 2}, {12, 2}, {15, 2}, {11, 1},
                          {19, 1}, {25, 3}, {23, 2}, {30, 2}};
  auto it = m.begin();
  it++;
  it++;
  m.erase(it);
  ASSERT_EQ(m.size(), 15u);
  ASSERT_EQ(m[20], 4);
  ASSERT_EQ(m[10], 3);
  ASSERT_EQ(m[2], 2);
  ASSERT_EQ(m[5], 2);
  ASSERT_EQ(m[11], 1);
  ASSERT_EQ(m[16], 3);
  ASSERT_EQ(m[3], 1);
  ASSERT_EQ(m[15], 2);
  ASSERT_EQ(m[17], 2);
  ASSERT_EQ(m[14], 2);
  ASSERT_EQ(m[12], 2);
  ASSERT_EQ(m[19], 1);
  ASSERT_EQ(m[25], 3);
  ASSERT_EQ(m[23], 2);
  ASSERT_EQ(m[30], 2);
}

TEST(TestMapErase, EraseThirteenth) {
  s21::map<int, int> m = {{20, 4}, {10, 3}, {4, 3},  {2, 2},  {5, 2},  {16, 3},
                          {3, 1},  {14, 2}, {17, 2}, {12, 2}, {15, 2}, {11, 1},
                          {19, 1}, {25, 3}, {23, 2}, {30, 2}};
  auto it = m.begin();
  it++;
  m.erase(it);
  ASSERT_EQ(m.size(), 15u);
  ASSERT_EQ(m[20], 4);
  ASSERT_EQ(m[11], 1);
  ASSERT_EQ(m[4], 3);
  ASSERT_EQ(m[2], 2);
  ASSERT_EQ(m[5], 2);
  ASSERT_EQ(m[16], 3);
  ASSERT_EQ(m[10], 3);
  ASSERT_EQ(m[15], 2);
  ASSERT_EQ(m[17], 2);
  ASSERT_EQ(m[14], 2);
  ASSERT_EQ(m[12], 2);
  ASSERT_EQ(m[19], 1);
  ASSERT_EQ(m[25], 3);
  ASSERT_EQ(m[23], 2);
  ASSERT_EQ(m[30], 2);
}

TEST(TestMapErase, EraseFourteenth) {
  s21::map<int, int> m = {{20, 4}, {10, 3}, {4, 3},  {2, 2},  {5, 2},  {16, 3},
                          {3, 1},  {14, 2}, {17, 2}, {12, 2}, {15, 2}, {11, 1},
                          {19, 1}, {25, 3}, {23, 2}, {30, 2}};
  auto it = m.begin();
  m.erase(it);
  ASSERT_EQ(m.size(), 15u);
  ASSERT_EQ(m[20], 4);
  ASSERT_EQ(m[11], 1);
  ASSERT_EQ(m[4], 3);
  ASSERT_EQ(m[10], 3);
  ASSERT_EQ(m[5], 2);
  ASSERT_EQ(m[16], 3);
  ASSERT_EQ(m[3], 1);
  ASSERT_EQ(m[15], 2);
  ASSERT_EQ(m[17], 2);
  ASSERT_EQ(m[14], 2);
  ASSERT_EQ(m[12], 2);
  ASSERT_EQ(m[19], 1);
  ASSERT_EQ(m[25], 3);
  ASSERT_EQ(m[23], 2);
  ASSERT_EQ(m[30], 2);
}

// TEST(TestMapErase, EraseFifteenth) {
//   s21::map<int, int> m = {
//       {20, 4}, {10, 3}, {4, 3},  {2, 2},  {5, 2},  {16, 3}, {3, 1},  {14, 2},
//       {17, 2}, {12, 2}, {15, 2}, {11, 1}, {19, 1}, {25, 3}, {23, 2}, {30,
//       2}};
//   auto it = m.begin();
//   it++;
//   it++;
//   it++;
//   it++;
//   it++;
//   it++;
//   it++;
//   it++;
//   it++;
//   m.erase(it);
//   ASSERT_EQ(m.size(), 15u);
//   ASSERT_EQ(m[20], 4);
//   ASSERT_EQ(m[10], 3);
//   ASSERT_EQ(m[4], 3);
//   ASSERT_EQ(m[2], 2);
//   ASSERT_EQ(m[5], 2);
//   ASSERT_EQ(m[15], 2);
//   ASSERT_EQ(m[3], 1);
//   ASSERT_EQ(m[14], 2);
//   ASSERT_EQ(m[17], 2);
//   ASSERT_EQ(m[12], 2);
//   ASSERT_EQ(m[11], 1);
//   ASSERT_EQ(m[19], 1);
//   ASSERT_EQ(m[25], 3);
//   ASSERT_EQ(m[23], 2);
//   ASSERT_EQ(m[30], 2);
// }

TEST(TestMapErase, EraseNineteenth) {
  s21::map<int, int> m = {{20, 4}, {10, 3}, {4, 3},  {2, 2},  {5, 2},  {16, 3},
                          {3, 1},  {14, 2}, {17, 2}, {12, 2}, {15, 2}, {11, 1},
                          {19, 1}, {25, 3}, {23, 2}, {30, 2}};
  auto it = m.begin();
  it++;
  it++;
  it++;
  it++;
  it++;
  it++;
  it++;
  it++;
  it++;
  it++;
  m.erase(it);
  ASSERT_EQ(m.size(), 15u);
  ASSERT_EQ(m[20], 4);
  ASSERT_EQ(m[10], 3);
  ASSERT_EQ(m[4], 3);
  ASSERT_EQ(m[2], 2);
  ASSERT_EQ(m[5], 2);
  ASSERT_EQ(m[16], 3);
  ASSERT_EQ(m[3], 1);
  ASSERT_EQ(m[14], 2);
  ASSERT_EQ(m[15], 2);
  ASSERT_EQ(m[12], 2);
  ASSERT_EQ(m[11], 1);
  ASSERT_EQ(m[19], 1);
  ASSERT_EQ(m[25], 3);
  ASSERT_EQ(m[23], 2);
  ASSERT_EQ(m[30], 2);
}

// TEST(TestMapErase, EraseSixteenth) {
//   s21::map<int, int> m = {
//       {20, 4}, {10, 3}, {4, 3},  {2, 2},  {5, 2},  {16, 3}, {3, 1},  {14, 2},
//       {17, 2}, {12, 2}, {15, 2}, {11, 1}, {19, 1}, {25, 3}, {23, 2}, {30,
//       2}};
//   auto it = m.begin();
//   it++;
//   it++;
//   it++;
//   it++;
//   it++;
//   it++;
//   it++;
//   it++;
//   it++;
//   it++;
//   it++;
//   m.erase(it);
//   ASSERT_EQ(m.size(), 15u);
//   ASSERT_EQ(m[20], 4);
//   ASSERT_EQ(m[10], 3);
//   ASSERT_EQ(m[4], 3);
//   ASSERT_EQ(m[2], 2);
//   ASSERT_EQ(m[5], 2);
//   ASSERT_EQ(m[16], 3);
//   ASSERT_EQ(m[3], 1);
//   ASSERT_EQ(m[14], 2);
//   ASSERT_EQ(m[17], 2);
//   ASSERT_EQ(m[12], 2);
//   ASSERT_EQ(m[11], 1);
//   ASSERT_EQ(m[15], 2);
//   ASSERT_EQ(m[25], 3);
//   ASSERT_EQ(m[23], 2);
//   ASSERT_EQ(m[30], 2);
// }

TEST(TestMapErase, EraseSeventeenth) {
  s21::map<int, int> m = {{20, 4}, {10, 3}, {4, 3},  {2, 2},  {5, 2},  {16, 3},
                          {3, 1},  {14, 2}, {17, 2}, {12, 2}, {15, 2}, {11, 1},
                          {19, 1}, {25, 3}, {23, 2}, {30, 2}};
  auto it = m.begin();
  it++;
  it++;
  it++;
  it++;
  it++;
  it++;
  it++;
  it++;
  it++;
  it++;
  it++;
  it++;
  m.erase(it);
  ASSERT_EQ(m.size(), 15u);
  ASSERT_EQ(m[15], 2);
  ASSERT_EQ(m[10], 3);
  ASSERT_EQ(m[4], 3);
  ASSERT_EQ(m[2], 2);
  ASSERT_EQ(m[5], 2);
  ASSERT_EQ(m[16], 3);
  ASSERT_EQ(m[3], 1);
  ASSERT_EQ(m[14], 2);
  ASSERT_EQ(m[17], 2);
  ASSERT_EQ(m[12], 2);
  ASSERT_EQ(m[11], 1);
  ASSERT_EQ(m[19], 1);
  ASSERT_EQ(m[25], 3);
  ASSERT_EQ(m[23], 2);
  ASSERT_EQ(m[30], 2);
}

TEST(TestMapErase, EraseEighteenth) {
  s21::map<int, int> m = {{20, 4}, {10, 3}, {4, 3},  {2, 2},  {5, 2},  {16, 3},
                          {3, 1},  {14, 2}, {17, 2}, {12, 2}, {15, 2}, {11, 1},
                          {19, 1}, {25, 3}, {23, 2}, {30, 2}};
  auto it = m.begin();
  it++;
  it++;
  it++;
  it++;
  it++;
  it++;
  it++;
  it++;
  it++;
  it++;
  it++;
  it++;
  it++;
  it++;
  m.erase(it);
  ASSERT_EQ(m.size(), 15u);
  ASSERT_EQ(m[20], 4);
  ASSERT_EQ(m[10], 3);
  ASSERT_EQ(m[4], 3);
  ASSERT_EQ(m[2], 2);
  ASSERT_EQ(m[5], 2);
  ASSERT_EQ(m[16], 3);
  ASSERT_EQ(m[3], 1);
  ASSERT_EQ(m[14], 2);
  ASSERT_EQ(m[17], 2);
  ASSERT_EQ(m[12], 2);
  ASSERT_EQ(m[11], 1);
  ASSERT_EQ(m[19], 1);
  ASSERT_EQ(m[15], 2);
  ASSERT_EQ(m[23], 2);
  ASSERT_EQ(m[30], 2);
}

TEST(TestMapErase, EraseTwentieth) {
  s21::map<int, int> m = {{20, 4}, {10, 3}, {4, 3},  {2, 2},  {5, 2},  {16, 3},
                          {3, 1},  {14, 2}, {17, 2}, {12, 2}, {15, 2}, {11, 1},
                          {19, 1}, {25, 3}, {23, 2}, {30, 2}};
  auto it = m.begin();
  it++;
  it++;
  it++;
  it++;
  it++;
  it++;
  it++;
  it++;
  it++;
  it++;
  it++;
  it++;
  it++;
  m.erase(it);
  ASSERT_EQ(m.size(), 15u);
  ASSERT_EQ(m[20], 4);
  ASSERT_EQ(m[10], 3);
  ASSERT_EQ(m[4], 3);
  ASSERT_EQ(m[2], 2);
  ASSERT_EQ(m[5], 2);
  ASSERT_EQ(m[16], 3);
  ASSERT_EQ(m[3], 1);
  ASSERT_EQ(m[14], 2);
  ASSERT_EQ(m[17], 2);
  ASSERT_EQ(m[12], 2);
  ASSERT_EQ(m[11], 1);
  ASSERT_EQ(m[19], 1);
  ASSERT_EQ(m[15], 2);
  ASSERT_EQ(m[25], 3);
  ASSERT_EQ(m[30], 2);
}

TEST(TestMapErase, EraseTwentyFirst) {
  s21::map<int, int> m = {{20, 4}, {10, 3}, {4, 3},  {2, 2},  {5, 2},  {16, 3},
                          {3, 1},  {14, 2}, {17, 2}, {12, 2}, {15, 2}, {11, 1},
                          {19, 1}, {25, 3}, {23, 2}, {30, 2}};
  auto it = m.begin();
  it++;
  it++;
  it++;
  it++;
  it++;
  it++;
  it++;
  it++;
  it++;
  it++;
  it++;
  it++;
  it++;
  it++;
  it++;
  m.erase(it);
  ASSERT_EQ(m.size(), 15u);
  ASSERT_EQ(m[20], 4);
  ASSERT_EQ(m[10], 3);
  ASSERT_EQ(m[4], 3);
  ASSERT_EQ(m[2], 2);
  ASSERT_EQ(m[5], 2);
  ASSERT_EQ(m[16], 3);
  ASSERT_EQ(m[3], 1);
  ASSERT_EQ(m[14], 2);
  ASSERT_EQ(m[17], 2);
  ASSERT_EQ(m[12], 2);
  ASSERT_EQ(m[11], 1);
  ASSERT_EQ(m[19], 1);
  ASSERT_EQ(m[15], 2);
  ASSERT_EQ(m[23], 2);
  ASSERT_EQ(m[25], 3);
}

TEST(TestMapErase, EraseTwentySecond) {
  s21::map<int, int> m = {{20, 4}, {10, 3}, {4, 3},  {2, 2},  {5, 2},  {16, 3},
                          {3, 1},  {14, 2}, {17, 2}, {12, 2}, {15, 2}, {11, 1},
                          {19, 1}, {25, 3}, {23, 2}, {30, 2}, {1, 4}};
  auto it = m.begin();
  it++;
  m.erase(it);
  ASSERT_EQ(m.size(), 16u);
  ASSERT_EQ(m[20], 4);
  ASSERT_EQ(m[10], 3);
  ASSERT_EQ(m[4], 3);
  ASSERT_EQ(m[3], 1);
  ASSERT_EQ(m[5], 2);
  ASSERT_EQ(m[16], 3);
  ASSERT_EQ(m[1], 4);
  ASSERT_EQ(m[14], 2);
  ASSERT_EQ(m[17], 2);
  ASSERT_EQ(m[12], 2);
  ASSERT_EQ(m[11], 1);
  ASSERT_EQ(m[19], 1);
  ASSERT_EQ(m[15], 2);
  ASSERT_EQ(m[23], 2);
  ASSERT_EQ(m[25], 3);
  ASSERT_EQ(m[30], 2);
}

TEST(TestMapErase, EraseTwentyThird) {
  s21::map<int, int> m = {{20, 4}, {10, 3}, {4, 3},  {2, 2},  {5, 2},  {16, 3},
                          {3, 1},  {14, 2}, {17, 2}, {12, 2}, {15, 2}, {11, 1},
                          {19, 1}, {25, 3}, {23, 2}, {30, 2}, {1, 4}};
  auto it = m.begin();
  it++;
  it++;
  m.erase(it);
  ASSERT_EQ(m.size(), 16u);
  ASSERT_EQ(m[20], 4);
  ASSERT_EQ(m[10], 3);
  ASSERT_EQ(m[4], 3);
  ASSERT_EQ(m[2], 2);
  ASSERT_EQ(m[5], 2);
  ASSERT_EQ(m[16], 3);
  ASSERT_EQ(m[1], 4);
  ASSERT_EQ(m[14], 2);
  ASSERT_EQ(m[17], 2);
  ASSERT_EQ(m[12], 2);
  ASSERT_EQ(m[11], 1);
  ASSERT_EQ(m[19], 1);
  ASSERT_EQ(m[15], 2);
  ASSERT_EQ(m[23], 2);
  ASSERT_EQ(m[25], 3);
  ASSERT_EQ(m[30], 2);
}

TEST(TestMapErase, EraseTwentyFourth) {
  s21::map<int, int> m = {{20, 4}, {10, 3}, {4, 3},  {2, 2},  {5, 2},  {16, 3},
                          {3, 1},  {14, 2}, {17, 2}, {12, 2}, {15, 2}, {11, 1},
                          {19, 1}, {25, 3}, {23, 2}, {30, 2}, {1, 4}};
  auto it = m.begin();
  it++;
  it++;
  it++;
  m.erase(it);
  ASSERT_EQ(m.size(), 16u);
  ASSERT_EQ(m[20], 4);
  ASSERT_EQ(m[10], 3);
  ASSERT_EQ(m[2], 2);
  ASSERT_EQ(m[2], 2);
  ASSERT_EQ(m[5], 2);
  ASSERT_EQ(m[16], 3);
  ASSERT_EQ(m[1], 4);
  ASSERT_EQ(m[14], 2);
  ASSERT_EQ(m[17], 2);
  ASSERT_EQ(m[12], 2);
  ASSERT_EQ(m[11], 1);
  ASSERT_EQ(m[19], 1);
  ASSERT_EQ(m[15], 2);
  ASSERT_EQ(m[23], 2);
  ASSERT_EQ(m[25], 3);
  ASSERT_EQ(m[30], 2);
}

TEST(TestMapErase, EraseTwentyEighth) {
  s21::map<std::string, int> m{{"this", 1}, {"sentence", 2}, {"is", 3},
                               {"not", 4},  {"a", 5},        {"word", 6}};
  auto it = m.begin();
  it++;
  m.erase(it);
  ASSERT_EQ(m["this"], 1);
  ASSERT_EQ(m["sentence"], 2);
  ASSERT_EQ(m["not"], 4);
  ASSERT_EQ(m["a"], 5);
  ASSERT_EQ(m["word"], 6);
}

TEST(TestMapErase, TestMapEraseTwentyNinth) {
  s21::map<int, int> m = {{20, 4}, {10, 3}, {4, 3},  {2, 2},  {5, 2},
                          {3, 1},  {14, 2}, {17, 2}, {12, 2}, {15, 2},
                          {11, 1}, {19, 1}, {25, 6}};
  auto it = m.end();
  it--;
  m.erase(it);
  it = m.end();
  it--;
  m.erase(it);
  ASSERT_EQ(m.size(), 11u);
  ASSERT_EQ(m[10], 3);
  ASSERT_EQ(m[4], 3);
  ASSERT_EQ(m[2], 2);
  ASSERT_EQ(m[5], 2);
  ASSERT_EQ(m[3], 1);
  ASSERT_EQ(m[12], 2);
  ASSERT_EQ(m[15], 2);
  ASSERT_EQ(m[11], 1);
  ASSERT_EQ(m[19], 1);
}

TEST(TestMapErase, TestMapEraseThirtieth) {
  s21::map<int, int> m = {{30, 4}, {10, 3}, {4, 3},  {2, 2},  {5, 2},  {3, 1},
                          {12, 2}, {15, 2}, {11, 2}, {20, 2}, {25, 1}, {18, 1},
                          {13, 5}, {14, 6}, {21, 1}, {17, 7}};
  auto it = m.end();
  it--;
  it--;
  m.erase(it);
  ASSERT_EQ(m.size(), 15u);
  ASSERT_EQ(m[30], 4);
  ASSERT_EQ(m[10], 3);
  ASSERT_EQ(m[4], 3);
  ASSERT_EQ(m[2], 2);
  ASSERT_EQ(m[5], 2);
  ASSERT_EQ(m[3], 1);
  ASSERT_EQ(m[12], 2);
  ASSERT_EQ(m[15], 2);
  ASSERT_EQ(m[11], 2);
  ASSERT_EQ(m[20], 2);
  ASSERT_EQ(m[17], 7);
  ASSERT_EQ(m[18], 1);
  ASSERT_EQ(m[13], 5);
  ASSERT_EQ(m[14], 6);
  ASSERT_EQ(m[21], 1);
}

TEST(TestMapErase, TestMapEraseThirtiethFirst) {
  s21::map<int, int> m = {{30, 4}};
  auto it = m.begin();
  m.erase(it);
  ASSERT_EQ(m.size(), 0u);
}

// int main(int argc, char** argv) {
//   testing::InitGoogleTest(&argc, argv);
//   return RUN_ALL_TESTS();
// }