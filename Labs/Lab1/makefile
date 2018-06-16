CXX = g++
CXXFLAGS = -std=c++0x
LDFLAGS = -lboost_date_time

OBJS = main.o readMatrix.o determinant.o

SRCS = main.cpp readMatrix.cpp determinant.cpp

HEADERS = readMatrix.hpp determinant.hpp

lab1: ${OBJS} ${HEADERS}
	${CXX} ${CXXFLAGS} ${OBJS} -o lab1

${OBJS}: ${SRCS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)

clean:
	rm *.o lab1
