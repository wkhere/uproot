uproot:	uproot.c main.c
			cc -Wall -O3 uproot.c main.c -o uproot

static:		uproot.c main.c
			cc -Wall -O3 -static uproot.c main.c -o uproot

install:	uproot gitroot
			strip uproot
			install -t /usr/local/bin/ uproot gitroot

.PHONY: install
