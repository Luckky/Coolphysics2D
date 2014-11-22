OBJS=main.o Vector.o Entity.o GameWorld.o
Engine:$(OBJS)
	g++ -o Engine $(OBJS)
main.o:Entity.h GameWorld.h
	g++ -c main.cpp
Vector.o:
	g++ -c Vector.cpp
Entity.o:Vector.h
	g++ -c Entity.cpp
GameWorld.o:Vector.h
	g++ -c GameWorld.cpp
.PHONY:clean
clean:
	-rm Engine $(OBJS) 