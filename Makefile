uproot:	uproot.c main.c
			cc -Wall -O3 uproot.c main.c -o uproot

static:		uproot.c main.c
			cc -Wall -O3 -static uproot.c main.c -o uproot

install:	uproot
			strip uproot
			install uproot /usr/local/bin/

.PHONY: install
