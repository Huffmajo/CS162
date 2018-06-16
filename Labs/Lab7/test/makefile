CXX = g++
CXXFLAGS = -std=c++0x -g

OBJS = main.o Queue.o QueueNode.o utils.o

SRCS = main.cpp Queue.cpp QueueNode.cpp utils.cpp

HEADERS = Queue.hpp QueueNode.hpp utils.hpp

lab1: ${OBJS} ${HEADERS}
	${CXX} ${CXXFLAGS} ${OBJS} -o lab7

${OBJS}: ${SRCS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)

clean:
	rm *.o lab7
