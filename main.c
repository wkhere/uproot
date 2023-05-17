#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int uproot(const char *direntry);

void usage() {
	fprintf(stderr, "usage: uproot git|st\n");
	exit(2);
}

int main(int argc, char *argv[]) {
	if (argc != 2) usage();

	const char *d;
	if (strcmp(argv[1], "git") == 0)
		d = ".git";
	else if (strcmp(argv[1], "st") == 0)
		d = ".stfolder";
	else
		usage();

	exit( uproot(d) );
}
