CC = gcc

CFLAGS  = -Wall -Wextra -Wpedantic -Wdeprecated-declarations -O2 

TARGET = ttt

all: $(TARGET)

$(TARGET): $(TARGET).c
	$(CC) $(CFLAGS) -o $(TARGET) $(TARGET).c

clean:
	$(RM) $(TARGET)
