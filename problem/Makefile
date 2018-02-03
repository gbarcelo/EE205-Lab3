all: ./lib/libContainer.a

# This is the rule you need to fill out
./lib/libContainer.a:
	g++ ./src/ListNode.cpp -I./include/ -c -o ./src/ListNode.o
	g++ ./src/Vector.cpp -I./include/ -c -o ./src/Vector.o
	g++ ./src/List.cpp -I./include/ -c -o ./src/List.o
	ar rcs ./lib/libContainer.a ./src/ListNode.o ./src/Vector.o ./src/List.o

test-Vector: ./lib/libContainer.a ./tst/test-Vector.cpp
	g++ -o ./bin/test-Vector.out -I./include/ \
		./tst/test-Vector.cpp -L./lib/ -lContainer
	./bin/test-Vector.out

test-ListNode: ./lib/libContainer.a ./tst/test-ListNode.cpp
	g++ -o ./bin/test-ListNode.out -I./include/ \
		./tst/test-ListNode.cpp -L./lib/ -lContainer
	./bin/test-ListNode.out

test-List: ./lib/libContainer.a ./tst/test-List.cpp
	g++ -o ./bin/test-List.out -I./include/ \
		./tst/test-List.cpp -L./lib/ -lContainer
	./bin/test-List.out

test-all: test-Vector test-ListNode test-List

# `make clean` edited to ignore errors and continue cleaning
clean:
	-rm ./lib/*.a
	-rm ./bin/*.out
	-rm ./src/*.o
