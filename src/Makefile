CFLAGS=-Wall -Wextra -Werror -std=c++17
LDFLAGS=-lgtest -lgtest_main -pthread


all: build

build: clean s21_matrix_oop.a test.o
	g++ -lstdc++ $(CFLAGS) test.o s21_matrix_oop.a -o s21_matrix_oop $(LDFLAGS)

clean:
	rm -rf *.o s21_matrix_oop *.a *.gcno *.gcda *.gcov *.info report

test: build
	./s21_matrix_oop

s21_matrix_oop.a: s21_matrix_oop.o
	ar rcs s21_matrix_oop.a s21_matrix_oop.o
	ranlib s21_matrix_oop.a

test.o: test.cpp
	g++ $(CFLAGS) $^ -o $@ -c

s21_matrix_oop.o: s21_matrix_oop.cpp
	g++ $(CFLAGS) $^ -o $@ -c

gcov_report: CFLAGS+=--coverage
gcov_report: LDFLAGS+=--coverage
gcov_report: test
	lcov -t s21_matrix_oop -o s21_matrix_oop.info -c -d .
	genhtml -o report s21_matrix_oop.info

rebuild: clean all

style:
	cp ../materials/linters/CPPLINT.cfg ../src
	python3 ../materials/linters/cpplint.py --extensions=cpp,h *.cpp *.h
	rm -rf CPPLINT.cfg
