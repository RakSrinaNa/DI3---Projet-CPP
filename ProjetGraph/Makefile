export CPPFLAGS=-std=c++11 -Wall -Werror -W -pedantic -static -g
export LDFLAGS=-lm
export EXEC=Graph
SRC_DIR=ProjetGraph

all: clall $(EXEC) clean

$(EXEC):
	cd $(SRC_DIR) && $(MAKE) && cd .. && mv $(SRC_DIR)/$(EXEC) .

.PHONY: clean

clean:
	cd $(SRC_DIR) && $(MAKE) $@

clall:
	-rm $(EXEC) ; cd $(SRC_DIR) ; $(MAKE) $@

test: all
	./$(EXEC) && valgrind --track-origins=yes --leak-check=full --error-exitcode=50 ./$(EXEC)
