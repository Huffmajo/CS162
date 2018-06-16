CXX = g++
CXXFLAGS = -std=c++0x -g

OBJS = main.o recursiveFunctions.o  utils.o

SRCS = main.cpp recursiveFunctions.cpp utils.cpp

HEADERS = recursiveFunctions.hpp utils.hpp

lab5: ${OBJS} ${HEADERS}
	${CXX} ${CXXFLAGS} ${OBJS} -o lab5

${OBJS}: ${SRCS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)

clean:
	rm *.o lab5 
