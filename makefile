CC=g++
CFLAGS=-c -Wall
LDFLAGS=
SOURCES=Administrator.cpp AdministratorBilder.cpp Bilder.cpp Conference.cpp main.cpp MyException.cpp Presetion.cpp Speaker.cpp SpeakerBilder.cpp WorkEnd.cpp Program.cpp  ProgramBilder.cpp Keeper.cpp

BUILDDIR  = obj/

OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=lab1

all: $(SOURCES) $(EXECUTABLE)


$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@