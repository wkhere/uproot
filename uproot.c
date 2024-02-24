#include <unistd.h>
#include <glob.h>
#include <string.h>
#include <stdio.h>
#include <limits.h>

int uproot(const char *direntry) {
  static glob_t glob_buf;
  static char cwd_buf[PATH_MAX];
  const char *cwd;
  int glob_ret;

  while (1) {
    cwd = getcwd(cwd_buf, PATH_MAX);
    if (cwd == NULL) { perror("getcwd"); return 1; }

    glob_ret = glob(direntry, GLOB_NOSORT, NULL, &glob_buf);
    globfree(&glob_buf);

    switch (glob_ret) {
    case 0:
      printf("%s\n", cwd);
      return 0;

    default:
      if (strcmp("/", cwd) == 0) return 1; // no .git up to root dir
      if (chdir("..") != 0) {perror("chdir"); return 1;}
      continue;
    }
  }
}
