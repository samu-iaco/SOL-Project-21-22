

CC = gcc
CFLAGS += -g -std=c99 -Wall
CXXFLAGS += -DDEBUG
# CXXFLAGS += -DDEBUG -DDEBUG_VERBOSE # stampa informazioni relative all'invio e ricezione dei messaggi
LDLIBS = -lpthread 
INCLUDES = -I ./headers


# dir
BINARIES_DIR = ./bin 
OBJECT_DIR = ./objs
SOURCE_DIR = ./src
LIBRARIES_DIR = ./libs


EXE = $(BINARIES_DIR)/client 

all: $(EXE)

CLIENT_LIBRARIES = $(LIBRARIES_DIR)/libapi.so
CLIENT_OBJECTS = $(OBJECT_DIR)/client.o $(OBJECT_DIR)/api.o
CLIENT_HEADERS = ./headers/api.h


# obj/api.o:
# 	$(CC) $(CFLAGS) $(INCLUDES) -c src/api.c $(LIBS)
# 	@mv api.o $(OBJ_DIR)/api.o

$(OBJECT_DIR)/api.o: $(SOURCE_DIR)/api.c headers/api.h
	$(CC) $(INCLUDES) $(CFLAGS) -c src/api.c -o api.o $(LDLIBS)

$(OBJECT_DIR)/client.o: $(SOURCE_DIR)/client.c $(CLIENT_HEADERS) $(CLIENT_LIBRARIES)
	$(CC) $(CFLAGS) -c src/client.c  $(LDLIBS)


$(BINARIES_DIR)/client: $(CLIENT_OBJECTS) $(LDLIBS) $(CLIENT_LIBRARIES)
	$(CC) $(INCLUDES) $(CFLAGS) client.c -o client -Wl,-rpath,./libs -L ./libs  

libs/libapi.so: $(OBJECT_DIR)/api.o
	$(CC) -shared -o $(LIBRARIES_DIR)/libapi.so $^	

clean :
	-rm $(TARGETS) $(EXE) *~ core 

