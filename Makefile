TARGET=todoC
CC=gcc
DEBUG=-g
WARN=-Wall
INCLUDE_PATH=include
CFLAGS=$(DEBUG) $(WARN)
OBJS=build/main.o build/time_management.o build/cmd_tasks.o build/interactive_tasks.o 
HEADERS=$(INCLUDE_PATH)/time_management.h $(INCLUDE_PATH)/cmd_tasks.h $(INCLUDE_PATH)/interactive_tasks.h
CHECK_SOURCES=src/main.c $(HEADERS)

all: $(OBJS)
	$(CC) -o build/$(TARGET) $(OBJS) $(CFLAGS) -I$(INCLUDE_PATH)

build/main.o: src/main.c $(HEADERS) | build 
	$(CC) -c src/main.c -o build/main.o

build/time_management.o: src/time_management.c
	$(CC) -c src/time_management.c -o build/time_management.o

build/cmd_tasks.o: src/cmd_tasks.c
	$(CC) -c src/cmd_tasks.c -o build/cmd_tasks.o

build/interactive_tasks.o: src/interactive_tasks.c
	$(CC) -c src/interactive_tasks.c -o build/interactive_tasks.o

build:
	mkdir -p build

run:
	build/$(TARGET)

clean:
	rm build/$(OBJS) build/$(TARGET)
