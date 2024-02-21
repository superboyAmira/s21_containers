G++ = g++ -std=c++17
CHECKFLAGS = -Wall -Werror -Wextra
TEST_LIBS = -lgtest -pthread
TEST_SRC = vector/vector_test.cc set/set_test.cc map/map_test.cc array/array_test.cc stack/stack_test.cc queue/queue_test.cc 
TEST_NAME = test

all: clean test

test: 
	$(G++) $(CHECKFLAGS) $(TEST_SRC) -o $(TEST_NAME) $(TEST_LIBS) -g
	./$(TEST_NAME) --gtest_break_on_failure

clean:
	rm -rf lib_obj test lib/*.o ./*.a ./*.o ./a.out gcov_test *.html *.css report lib/*.dSYM ./*.gcno ./*.gcda ./*.info ./*.dSYM ./CPPLINT*

gcov_report: clean
	$(G++) $(CHECKFLAGS) $(TEST_SRC) $(TEST_LIBS) -coverage -o gcov_test
	chmod +x *
	./gcov_test
	lcov -t "gcov_test" -o gcov_test.info --no-external -c -d .
	genhtml -o report/ gcov_test.info
	open ./report/index.html

format: 
	clang-format -style=google -i */*.cc
	clang-format -style=google -i */*.h
	clang-format -style=google -i */*.tpp

clang-format: 
	clang-format -style=google -n */*.cc
	clang-format -style=google -n */*.h
	clang-format -style=google -n */*.tpp

fsanitize: 
	$(G++) $(TEST_SRC) $(CHECKFLAGS) -g -fsanitize=address $(TEST_LIBS) -o $(TEST_NAME) 
	./$(TEST_NAME)

valgrind: test
	valgrind --track-origins=yes --leak-check=full --show-leak-kinds=all ./$(TEST_NAME)

GTest_install:
	echo -e "\e[32m[---Start install GTest lib ubuntu20---]\e[0m"
	sudo apt-get install libgtest-dev libgmock-dev
	sudo apt-get install libtbb-dev
	sudo apt-get install cmake
	cd /usr/src/googletest/
	sudo mkdir build
	cd build
	sudo cmake ..
	sudo make
	cd ..
	sudo cp lib/* /usr/lib
	echo -e "\e[32m[---Done---]\e[0m"
