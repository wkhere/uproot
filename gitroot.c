#include <unistd.h>
#include <glob.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define PATH_SZ PATH_MAX

static void go() {
  static glob_t glob_buf;
  static char cwd_buf[PATH_SZ];
  const char *cwd = getcwd(cwd_buf, PATH_SZ);
  if (glob(".git", 0, NULL, &glob_buf) != 0) {
    if (strcmp("/", cwd) != 0) {
      chdir("..");
      go();
    } else {
      exit(1);
    }
  } else {
    printf("%s\n", cwd);
    exit(0);
  }
}

int main() { go(); }
