CC = g++
CFLAGS =
TARGET = test_main
SRCS = test_main.cpp main.cpp
OBJS = $(SRCS:.cpp=.o)

HEADERS = main.h

.PHONY: build run clean all build

all: build run

build: $(TARGET)
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS)

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(OBJS) $(TARGET)
