#include "./main.h"
#include "./epub.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

  char *path;
  char **files;
  int i;

  if (argc < 2) {
    printf("%s: missing file operand\n", PROJECT_NAME);
    exit(EXIT_FAILURE);
  }

  path = argv[1];

  files = get_epubs(path);

  i = 0;
  while (files[i]) {
    printf("%s\n", files[i]);
    i++;
  }

  exit(EXIT_SUCCESS);
}
