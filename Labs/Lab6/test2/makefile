CXX = g++
CXXFLAGS = -std=c++0x -g

OBJS = main.o DoubleLink.o Node.o utils.o

SRCS = main.cpp DoubleLink.cpp Node.cpp utils.cpp

HEADERS = DoubleLink.hpp Node.hpp utils.hpp

lab5: ${OBJS} ${HEADERS}
	${CXX} ${CXXFLAGS} ${OBJS} -o lab6

${OBJS}: ${SRCS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)

clean:
	rm *.o lab6 

