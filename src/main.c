#include "./main.h"
#include "./file_manager.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

  char *path;

  if (argc < 2) {
    printf("%s: missing file operand\n", PROJECT_NAME);
    exit(EXIT_FAILURE);
  }

  path = argv[1];

  get_files(path);

  exit(EXIT_SUCCESS);
}
