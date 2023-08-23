#include "./file_manager.h"
#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool is_regular_file(char *path) {
  struct stat path_stat;
  if (stat(path, &path_stat) != 0) {
    return false;
  }
  return S_ISREG(path_stat.st_mode);
}

bool is_directory(char *path) {
  struct stat path_stat;
  if (stat(path, &path_stat) != 0) {
    return false;
  }
  return S_ISDIR(path_stat.st_mode);
}

bool path_exists(char *path) {
  struct stat path_stat;
  if (stat(path, &path_stat) == 0) {
    return true;
  }

  return false;
}

void get_files(char *path) {
  if (path_exists(path) == false) {
    exit(EXIT_FAILURE);
  }

  if (is_directory(path)) {
    DIR *dirpointer;
    struct dirent *entrypointer;
    dirpointer = opendir(path);
    if (dirpointer != NULL) {
      while ((entrypointer = readdir(dirpointer)) != NULL) {
        printf("%s\n", entrypointer->d_name);
      }

      closedir(dirpointer);
    }
  }
}
