BIN=uproot

$(BIN):	uproot.o main.o
	cc $^ -o $(BIN)

%.o: %.c
	cc -c $< -Wall -O3 -o $@


install: $(BIN) gitroot
	strip $(BIN)
	install -t /usr/local/bin/ $(BIN) gitroot

clean:
	rm -f *.o $(BIN)

.PHONY: install clean
