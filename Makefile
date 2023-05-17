uproot:	uproot.c
			cc -Wall -O3 uproot.c -o uproot

static:		uproot.c
			cc -Wall -O3 -static uproot.c -o uproot

install:	uproot
			strip uproot
			install uproot /usr/local/bin/

.PHONY: install
