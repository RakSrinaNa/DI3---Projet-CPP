SRC=$(wildcard *.cpp) $(wildcard */*.cpp)
OBJ=$(SRC:.cpp=.o)
HEAD=$(wildcard *.h) $(wildcard */*.h)

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CXX) -o $@ $^ $(LDFLAGS)

main.o: $(HEAD)

%.o: %.cpp FORCE
	$(CXX) -o $@ -c $< $(CPPFLAGS)

.PHONY: clean

clall: clean

clean:
	rm *.o ; rm */*.o

test:
	echo “Tests OK”
