CC = g++
CFLAGS = -std=c++20 -Wall
WXCONFIG = $(shell wx-config --cxxflags --gl-libs --libs)

SRC = $(wildcard *.cpp)
OBJ = $(SRC:.cpp=.o)

EXTENDFLAGS = -lGL -lGLU

TARGET = MyApp

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) $(WXCONFIG) $(EXTENDFLAGS) -o $@ $^

%.o: %.cpp
	$(CC) $(CFLAGS) $(WXCONFIG) -c -o $@ $<

clean:
	rm -f $(TARGET) $(OBJ)

refresh:
	rm -f RayTracingUtils.o main.o
	$(MAKE)
