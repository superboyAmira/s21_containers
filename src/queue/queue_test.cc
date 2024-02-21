#include <gtest/gtest.h>

#include <queue>

#include "s21_queue.h"

TEST(QueueInt, Constructor_Default) {
  s21::queue<int> our_queue;
  std::queue<int> std_queue;
  EXPECT_EQ(our_queue.empty(), std_queue.empty());
}

TEST(QueueInt, Constructor_List) {
  s21::queue<int> our_queue = {1, 2, 3};
  std::queue<int> std_queue;
  std_queue.push(1);
  std_queue.push(2);
  std_queue.push(3);
  EXPECT_EQ(our_queue.front(), std_queue.front());
  EXPECT_EQ(our_queue.back(), std_queue.back());
}

TEST(QueueInt, Constructor_Copy) {
  s21::queue<int> our_queue = {1, 2, 3, 4, 5, 6};
  s21::queue<int> our_copy(our_queue);
  std::queue<int> std_queue;
  std_queue.push(1);
  std_queue.push(2);
  std_queue.push(3);
  std_queue.push(4);
  std_queue.push(5);
  std_queue.push(6);
  std::queue<int> std_copy(std_queue);
  EXPECT_EQ(our_copy.front(), std_copy.front());
  EXPECT_EQ(our_copy.back(), std_copy.back());
}

TEST(QueueInt, Operator_Copy) {
  s21::queue<int> our_queue_int = {1, 2, 3};
  std::queue<int> std_queue_int;
  std_queue_int.push(1);
  std_queue_int.push(2);
  std_queue_int.push(3);
  s21::queue<int> our_queue_empty;
  std::queue<int> std_queue_empty;
  our_queue_empty = our_queue_int;
  std_queue_empty = std_queue_int;
  EXPECT_EQ(our_queue_empty.front(), std_queue_empty.front());
  EXPECT_EQ(our_queue_empty.back(), std_queue_empty.back());
  EXPECT_EQ(our_queue_int.empty(), std_queue_int.empty());
}

TEST(QueueInt, Constructor_Move) {
  s21::queue<int> our_queue = {1, 2, 3};
  s21::queue<int> our_move(std::move(our_queue));
  std::queue<int> std_queue;
  std_queue.push(1);
  std_queue.push(2);
  std_queue.push(3);
  std::queue<int> std_move(std::move(std_queue));
  EXPECT_EQ(our_move.front(), std_move.front());
  EXPECT_EQ(our_move.back(), std_move.back());
  EXPECT_EQ(our_queue.empty(), std_queue.empty());
}

TEST(QueueInt, Operator_Move) {
  s21::queue<int> our_queue_int = {1, 2, 3};
  std::queue<int> std_queue_int;
  std_queue_int.push(1);
  std_queue_int.push(2);
  std_queue_int.push(3);
  s21::queue<int> our_queue_empty;
  std::queue<int> std_queue_empty;
  our_queue_empty = std::move(our_queue_int);
  std_queue_empty = std::move(std_queue_int);
  EXPECT_EQ(our_queue_empty.front(), std_queue_empty.front());
  EXPECT_EQ(our_queue_empty.back(), std_queue_empty.back());
  EXPECT_EQ(our_queue_int.empty(), std_queue_int.empty());
}

TEST(QueueInt, Empty) {
  s21::queue<int> our_queue_int = {1, 2, 3};
  std::queue<int> std_queue_int;
  std_queue_int.push(1);
  std_queue_int.push(2);
  std_queue_int.push(3);
  EXPECT_EQ(our_queue_int.empty(), std_queue_int.empty());
  s21::queue<int> our_queue_empty;
  std::queue<int> std_queue_empty;
  EXPECT_EQ(our_queue_empty.empty(), std_queue_empty.empty());
}

TEST(QueueInt, Size) {
  s21::queue<int> our_queue_int = {1, 2, 3};
  std::queue<int> std_queue_int;
  std_queue_int.push(1);
  std_queue_int.push(2);
  std_queue_int.push(3);
  EXPECT_EQ(our_queue_int.size(), std_queue_int.size());
  s21::queue<int> our_queue_empty;
  std::queue<int> std_queue_empty;
  EXPECT_EQ(our_queue_empty.size(), std_queue_empty.size());
}

TEST(QueueInt, Push) {
  s21::queue<int> our_queue_int;
  our_queue_int.push(1);
  our_queue_int.push(2);
  our_queue_int.push(3);
  std::queue<int> std_queue_int;
  std_queue_int.push(1);
  std_queue_int.push(2);
  std_queue_int.push(3);
  EXPECT_EQ(our_queue_int.front(), std_queue_int.front());
  EXPECT_EQ(our_queue_int.back(), std_queue_int.back());
}

TEST(QueueInt, Pop) {
  s21::queue<int> our_queue_int;
  our_queue_int.push(1);
  our_queue_int.push(2);
  our_queue_int.push(3);
  our_queue_int.pop();
  std::queue<int> std_queue_int;
  std_queue_int.push(1);
  std_queue_int.push(2);
  std_queue_int.push(3);
  std_queue_int.pop();
  EXPECT_EQ(our_queue_int.front(), std_queue_int.front());
  EXPECT_EQ(our_queue_int.back(), std_queue_int.back());
  our_queue_int.pop();
  our_queue_int.pop();
  std_queue_int.pop();
  std_queue_int.pop();
  EXPECT_EQ(our_queue_int.empty(), std_queue_int.empty());
}

TEST(QueueInt, Swap) {
  s21::queue<int> our_queue_int = {1, 2, 3};
  std::queue<int> std_queue_int;
  std_queue_int.push(1);
  std_queue_int.push(2);
  std_queue_int.push(3);
  s21::queue<int> our_queue_empty;
  std::queue<int> std_queue_empty;
  our_queue_empty.swap(our_queue_int);
  std_queue_empty.swap(std_queue_int);
  EXPECT_EQ(our_queue_empty.front(), std_queue_empty.front());
  EXPECT_EQ(our_queue_empty.back(), std_queue_empty.back());
  EXPECT_EQ(our_queue_int.empty(), std_queue_int.empty());
}

TEST(QueueDouble, Constructor_Default_Double) {
  s21::queue<double> our_queue;
  std::queue<double> std_queue;
  EXPECT_EQ(our_queue.empty(), std_queue.empty());
}

TEST(QueueDouble, Constructor_List_double) {
  s21::queue<double> our_queue = {123.123, 243.123, 3.123, 41231.123123,
                                  45645.12333};
  std::queue<double> std_queue;
  std_queue.push(123.123);
  std_queue.push(243.123);
  std_queue.push(3.123);
  std_queue.push(41231.123123);
  std_queue.push(45645.12333);
  EXPECT_EQ(our_queue.front(), std_queue.front());
  EXPECT_EQ(our_queue.back(), std_queue.back());
}

TEST(QueueDouble, Constructor_Copy_Double) {
  s21::queue<double> our_queue = {1.1234,   2.34123,  3432.1231,
                                  123.4356, 3456.341, 987543.123};
  s21::queue<double> our_copy(our_queue);
  std::queue<double> std_queue;
  std_queue.push(1.1234);
  std_queue.push(2.34123);
  std_queue.push(3432.1231);
  std_queue.push(123.4356);
  std_queue.push(3456.341);
  std_queue.push(987543.123);
  std::queue<double> std_copy(std_queue);
  EXPECT_EQ(our_copy.front(), std_copy.front());
  EXPECT_EQ(our_copy.back(), std_copy.back());
}

TEST(QueueDouble, Swap) {
  s21::queue<double> our_queue_one = {1.23412, 223.1234, 3.2341, 4532.123,
                                      12.321};
  std::queue<double> std_queue_one;
  std_queue_one.push(1.23412);
  std_queue_one.push(223.1234);
  std_queue_one.push(3.2341);
  std_queue_one.push(4532.123);
  std_queue_one.push(12.321);
  s21::queue<double> our_queue_second = {232.123123, 423.123};
  std::queue<double> std_queue_second;
  std_queue_second.push(232.123123);
  std_queue_second.push(423.123);
  our_queue_second.swap(our_queue_one);
  std_queue_second.swap(std_queue_one);
  EXPECT_EQ(our_queue_one.front(), std_queue_one.front());
  EXPECT_EQ(our_queue_one.back(), std_queue_one.back());
  EXPECT_EQ(our_queue_one.empty(), std_queue_one.empty());
  EXPECT_EQ(our_queue_second.front(), std_queue_second.front());
  EXPECT_EQ(our_queue_second.back(), std_queue_second.back());
  EXPECT_EQ(our_queue_second.empty(), std_queue_second.empty());
}

// string

TEST(QueueString, FrontAndBack) {
  s21::queue<int> our_queue_int = {1, 2, 3};
  std::queue<int> std_queue_int;
  std_queue_int.push(1);
  std_queue_int.push(2);
  std_queue_int.push(3);
  s21::queue<double> our_queue_double = {1.1f, 2.1f, 3.1f};
  std::queue<double> std_queue_double;
  std_queue_double.push(1.1f);
  std_queue_double.push(2.1f);
  std_queue_double.push(3.1f);
  s21::queue<std::string> our_queue_string = {"abc", "def", "ghf"};
  std::queue<std::string> std_queue_string;
  std_queue_string.push("abc");
  std_queue_string.push("def");
  std_queue_string.push("ghf");
  EXPECT_EQ(our_queue_int.front(), std_queue_int.front());
  EXPECT_EQ(our_queue_double.front(), std_queue_double.front());
  EXPECT_EQ(our_queue_string.front(), std_queue_string.front());
  EXPECT_EQ(our_queue_int.back(), std_queue_int.back());
  EXPECT_EQ(our_queue_double.back(), std_queue_double.back());
  EXPECT_EQ(our_queue_string.back(), std_queue_string.back());
}

TEST(QueueString, Constructor_Default) {
  s21::queue<std::string> our_queue;
  std::queue<std::string> std_queue;
  EXPECT_EQ(our_queue.empty(), std_queue.empty());
}

TEST(QueueString, Constructor_List) {
  s21::queue<std::string> our_queue = {"some", "dog", "shit"};
  std::queue<std::string> std_queue;
  std_queue.push("some");
  std_queue.push("dog");
  std_queue.push("shit");
  EXPECT_EQ(our_queue.front(), std_queue.front());
  EXPECT_EQ(our_queue.back(), std_queue.back());
}

TEST(QueueString, Swap) {
  s21::queue<std::string> our_queue_one = {"some", "dog", "shit"};
  std::queue<std::string> std_queue_one;
  std_queue_one.push("some");
  std_queue_one.push("dog");
  std_queue_one.push("shit");
  s21::queue<std::string> our_queue_second = {"nenavigu", "containers"};
  std::queue<std::string> std_queue_second;
  std_queue_second.push("nenavigu");
  std_queue_second.push("containers");
  our_queue_second.swap(our_queue_one);
  std_queue_second.swap(std_queue_one);
  EXPECT_EQ(our_queue_one.front(), std_queue_one.front());
  EXPECT_EQ(our_queue_one.back(), std_queue_one.back());
  EXPECT_EQ(our_queue_one.empty(), std_queue_one.empty());
  EXPECT_EQ(our_queue_second.front(), std_queue_second.front());
  EXPECT_EQ(our_queue_second.back(), std_queue_second.back());
  EXPECT_EQ(our_queue_second.empty(), std_queue_second.empty());
}

TEST(Queue, InsertManyBack) {
  s21::queue<int> our_queue_int;
  our_queue_int.insert_many_back(1, 2, 3);
  EXPECT_EQ(our_queue_int.front(), 1);
  EXPECT_EQ(our_queue_int.back(), 3);
  our_queue_int.insert_many_back(4, 5, 6);
  EXPECT_EQ(our_queue_int.front(), 1);
  EXPECT_EQ(our_queue_int.back(), 6);
  our_queue_int.pop();
  EXPECT_EQ(our_queue_int.front(), 2);
  EXPECT_EQ(our_queue_int.back(), 6);
}

TEST(QueueString, InsertManyBack) {
  s21::queue<std::string> our_queue_int;
  our_queue_int.insert_many_back("asdz", "asfasd", "asdfasdf");
  EXPECT_EQ(our_queue_int.front(), "asdz");
  EXPECT_EQ(our_queue_int.back(), "asdfasdf");
  our_queue_int.insert_many_back("ddd", "fff", "zzz");
  EXPECT_EQ(our_queue_int.front(), "asdz");
  EXPECT_EQ(our_queue_int.back(), "zzz");
  our_queue_int.pop();
  EXPECT_EQ(our_queue_int.front(), "asfasd");
  EXPECT_EQ(our_queue_int.back(), "zzz");
}
