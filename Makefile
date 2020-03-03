gitroot:	gitroot.c
			cc -Wall -O3 gitroot.c -o gitroot

static:		gitroot.c
			cc -Wall -O3 -static gitroot.c -o gitroot

install:	gitroot
			strip gitroot
			install gitroot /usr/local/bin/

.PHONY: install
