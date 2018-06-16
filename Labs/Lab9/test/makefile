CXX = g++
CXXFLAGS = -std=c++0x -g

OBJS = main.o buffer.o palindrome.o utils.o

SRCS = main.cpp buffer.cpp palindrome.cpp utils.cpp

HEADERS = buffer.hpp palindrome.hpp utils.hpp

lab1: ${OBJS} ${HEADERS}
	${CXX} ${CXXFLAGS} ${OBJS} -o lab9

${OBJS}: ${SRCS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)

clean:
	rm *.o lab9
