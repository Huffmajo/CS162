CXX = g++
CXXFLAGS = -std=c++0x -g

OBJS = main.o Barbarian.o BlueMen.o Character.o Game.o HarryPotter.o Medusa.o Vampire.o utils.o

SRCS = main.cpp Barbarian.cpp BlueMen.cpp Character.cpp Game.cpp HarryPotter.cpp Medusa.cpp Vampire.cpp utils.cpp

HEADERS = Barbarian.hpp BlueMen.hpp Character.hpp Game.hpp HarryPotter.hpp Medusa.hpp Vampire.hpp utils.hpp

project3: ${OBJS} ${HEADERS}
	${CXX} ${CXXFLAGS} ${OBJS} -o project3

${OBJS}: ${SRCS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)

clean:
	rm *.o project3
