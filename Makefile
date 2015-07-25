CXX=clang++
CFLAGS=-Iinclude -std=c++11 -Wall -Wextra
EXECUTABLE=controld

.PHONY: all
all: build

.PHONY: build
build:
	$(CXX) src/main.cpp -o $(EXECUTABLE) $(CFLAGS)

.PHONY: debug
debug:
	$(CXX) src/main.cpp -o $(EXECUTABLE) $(CFLAGS) -O0 -g

.PHONY: clean
clean:
	find src -name '*.o' -print0 | xargs -0 rm -fv
	rm -fv $(EXECUTABLE)
