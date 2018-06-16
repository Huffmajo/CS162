CXX = g++
CXXFLAGS = -std=c++0x -g

OBJS = main.o Building.o Instructor.o Student.o Person.o University.o utils.o

SRCS = main.cpp Building.cpp Instructor.cpp Student.cpp Person.cpp University.cpp utils.cpp

HEADERS = Building.hpp Instructor.hpp Student.hpp Person.hpp University.hpp utils.hpp

lab4: ${OBJS} ${HEADERS}
	${CXX} ${CXXFLAGS} ${OBJS} -o lab4

${OBJS}: ${SRCS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)

clean:
	rm *.o lab4
