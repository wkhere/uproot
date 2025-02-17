BIN=uproot

$(BIN):	uproot.o main.o
	cc $^ -o $(BIN)

%.o: %.c
	cc -c $< -Wall -O3 -o $@


install: $(BIN) gitroot
	install $(BIN) gitroot /usr/local/bin/

clean:
	rm -f *.o $(BIN)

.PHONY: install clean
