CC=g++
CFLAGS=-c -Wall

SOURCES=Administrator.cpp AdministratorBuilder.cpp Builder.cpp Conference.cpp main.cpp MyException.cpp Presetion.cpp Speaker.cpp SpeakerBuilder.cpp WorkEnd.cpp Program.cpp  ProgramBuilder.cpp Keeper.cpp

BUILDDIR  = obj/
DIR = C:\Users\nepos\Documents\GitHub\TP_lab05
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=lab1

all: $(SOURCES) $(EXECUTABLE)


$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@