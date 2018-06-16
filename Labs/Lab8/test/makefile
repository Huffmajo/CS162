CXX = g++
CXXFLAGS = -std=c++0x -g

OBJS = main.o bubbleSort.o readFileToArray.o searchFor.o  utils.o

SRCS = main.cpp bubbleSort.cpp readFileToArray.cpp searchFor.cpp utils.cpp

HEADERS = bubbleSort.hpp readFileToArray.hpp searchFor.hpp utils.hpp

lab1: ${OBJS} ${HEADERS}
	${CXX} ${CXXFLAGS} ${OBJS} -o lab8

${OBJS}: ${SRCS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)

clean:
	rm *.o lab8
