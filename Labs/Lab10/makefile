CXX = g++
CXXFLAGS = -std=c++0x -g

OBJS = main.o

SRCS = main.cpp

lab10: ${OBJS} 
	${CXX} ${CXXFLAGS} ${OBJS} -o lab10

${OBJS}: ${SRCS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)

clean:
	rm *.o lab10
