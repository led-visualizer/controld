CXX=clang++
EXECUTABLE=controld

.PHONY: all
all: build

.PHONY: build
build:
	$(CXX) src/main.cpp -o $(EXECUTABLE) -Iinclude -std=c++11 -Wall -Wextra

.PHONY: clean
clean:
	find src -name '*.o' -print0 | xargs -0 rm -fv
	rm -fv $(EXECUTABLE)
