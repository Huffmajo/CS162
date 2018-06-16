CXX = g++
CXXFLAGS = -std=c++0x -g

OBJS = main.o Queue.o QueueNode.o utils.o Barbarian.o BlueMen.o Character.o Game.o HarryPotter.o Medusa.o Vampire.o Tournament.o 

SRCS = main.cpp Queue.cpp QueueNode.cpp utils.cpp Barbarian.cpp BlueMen.cpp Character.cpp Game.cpp HarryPotter.cpp Medusa.cpp Tournament.cpp Vampire.cpp

HEADERS = Queue.hpp QueueNode.hpp utils.hpp Barbarian.hpp BlueMen.hpp Character.hpp Game.hpp HarryPotter.hpp Medusa.hpp Tournament.hpp Vampire.hpp

lab1: ${OBJS} ${HEADERS}
	${CXX} ${CXXFLAGS} ${OBJS} -o project4

${OBJS}: ${SRCS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)

clean:
	rm *.o project4
