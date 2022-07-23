CXX = g++
CXXFLAGS = -std=c++14 -g -Wall -MMD 
OBJECTS = displaytester.o display.o player.o
DEPENDS = ${OBJECTS:.o=.d}
EXEC = display

${EXEC} : ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -lncurses -o ${EXEC}


clean :
	rm ${DEPENDS} ${OBJECTS} ${EXEC}

-include ${DEPENDS}