# Portable replacement for the Code::Blocks project (MasterChef.cbp).
# Same flags as the original project: -Wall -fexceptions -g, plus -std=c++11
# (Team.cpp uses an initializer list for new[], which needs C++11).
CXX      ?= g++
CXXFLAGS ?= -std=c++11 -Wall -fexceptions -g
TARGET   = masterchef_d
SRCS     = $(wildcard *.cpp)
OBJS     = $(SRCS:.cpp=.o)
HDRS     = $(wildcard *.h)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJS)

%.o: %.cpp $(HDRS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Non-interactive run: stdin comes from sample_input.txt
run: $(TARGET)
	./$(TARGET) < sample_input.txt

clean:
	rm -f $(OBJS) $(TARGET)

.PHONY: all run clean
