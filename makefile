CXX = g++

SRC_DIR = src
INC_DIR = include
TARGET = program

SRCS = $(shell find $(SRC_DIR) -name '*.cpp')

OBJS = $(SRCS:.cpp=.o)

CXXFLAGS = -I$(INC_DIR) -Wall -Wextra -std=c++17

LDFLAGS =

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(LDFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(TARGET) $(OBJS)

