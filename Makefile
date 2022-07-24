CXX = g++
CXXFLAGS = -std=c++14 -g -Wall -MMD 
OBJECTS = start.o DcTims.o gooseNestings.o goToDcTims.o main.o player.o property.o templatedesign.o randomUint.o ownable.o subject.o mapclass.o gym.o rez.o grid.o errorclass.o
DEPENDS = ${OBJECTS:.o=.d}
EXEC = display

${EXEC} : ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -lncurses -o ${EXEC}


clean :
	rm ${DEPENDS} ${OBJECTS} ${EXEC}

-include ${DEPENDS}