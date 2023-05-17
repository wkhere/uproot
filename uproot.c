#include <unistd.h>
#include <glob.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define PATH_SZ PATH_MAX

int main() {
  static glob_t glob_buf;
  static char cwd_buf[PATH_SZ];
  const char *cwd;
  int glob_ret;

  while (1) {
    cwd = getcwd(cwd_buf, PATH_SZ);
    glob_ret = glob(".git", GLOB_NOSORT, NULL, &glob_buf);
    globfree(&glob_buf);

    switch (glob_ret) {
    case 0:
      printf("%s\n", cwd);
      exit(0);

    default:
      if (strcmp("/", cwd) == 0) exit(1); // no .git up to root dir
      if (chdir("..") != 0) {perror("chdir"); exit(1);}
      continue;
    }
  }
}
