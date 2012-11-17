CXX=g++
CXXFLAGS=-Wall -g -Wno-reorder
LDFLAGS= -l allegro -l allegro_image -l allegro_primitives -l allegro_dialog -l allegro_font -l allegro_ttf -lm

%.o: %.cpp
	${CXX} ${CXXFLAGS} -c -o $@ $(filter %.cpp, $^) $(foreach f, $(filter %.o, $^), -l $f ) ${LDFLAGS}
%: %.cpp
	${CXX} ${CXXFLAGS} -o $@ $^ $f ${LDFLAGS}
	
all:	clean main 
main:	Board.o	Animal.o Field.o Speed.o Position.o GroundType.o 
Animal.o:	Speed.o	Object.o	Position.o 	GroundType.o	Board.o
Field.o:	
Object.o:	Position.o 
#Chickens.o: Animal.o Death.o
Board.o:	Field.o
#Egg.o: Death.o 
clean:	;yes|rm *.o main -rf

#g++ -Wall -o Animal.o -l Position.o Animal.cpp
