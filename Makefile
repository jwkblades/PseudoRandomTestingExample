FLAGS:=-Wall -pedantic -std=c++11
UNITTEST_FLAGS=-pthread -lgtest -lgtest_main
CC:=g++

EXE=Base16
TEST=Base16Test

.cpp.o:
	${CC} ${FLAGS} -c $^ -o $@

${EXE}: main.o Base16Codec.o
	${CC} ${FLAGS} -o $@ $^

${TEST}: Base16CodecTest.o Base16Codec.o
	${CC} ${FLAGS} ${UNITTEST_FLAGS} -o $@ $^

.Phony: clean

clean:
	@rm -f *.o ${EXE}
