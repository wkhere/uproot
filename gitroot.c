#include <unistd.h>
#include <glob.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <errno.h>
#include <error.h>
#define PATH_SZ PATH_MAX

int main() {
  static glob_t glob_buf;
  static char cwd_buf[PATH_SZ];
  const char *cwd;
  int glob_ret;

  while (1) {
    cwd = getcwd(cwd_buf, PATH_SZ);
    glob_ret = glob(".git", GLOB_NOSORT|GLOB_ONLYDIR, NULL, &glob_buf);
    globfree(&glob_buf);

    switch (glob_ret) {
    case 0:
      printf("%s\n", cwd);
      exit(0);

    case GLOB_NOMATCH:
      if (strcmp("/", cwd) == 0) exit(1); // no .git up to root dir
      if (chdir("..") != 0) error(1, errno, "chdir");
      continue;

    default:
      error(1, errno, "glob");
    }
  }
}
