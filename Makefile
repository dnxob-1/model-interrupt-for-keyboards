CC = gcc
CFLAGS = -I include -Wall -Wextra -O2

$(shell mkdir -p build)

TARGET = build/run
dataDir = data

SRCS = main.c idtConfig.c io.c keyboardIsr.c
OBJS = $(SRCS:.c=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(TARGET) *.o
