gitroot:	gitroot.c
			cc -Wall -O3 -s gitroot.c -o gitroot

install:	gitroot
			install gitroot $(HOME)/bin/

.PHONY: install
