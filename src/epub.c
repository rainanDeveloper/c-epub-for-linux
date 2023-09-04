#include "./epub.h"
#include "./file_manager.h"
#include <regex.h>
#include <stdio.h>
#include <stdlib.h>

char **get_epubs(char *path) {
  int filecount = get_file_count(path);
  char **epubs = malloc(sizeof(char *) * filecount);
  regex_t regexp;
  int i = 0;
  int match;

  if (regcomp(&regexp, ".epub$", REG_EXTENDED) != 0) {
    printf("regcomp failed");
  }

  if (path_exists(path) == false) {
    exit(EXIT_FAILURE);
  }

  if (is_directory(path)) {
    DIR *dirpointer;
    struct dirent *entrypointer;
    dirpointer = opendir(path);
    if (dirpointer != NULL) {
      while ((entrypointer = readdir(dirpointer)) != NULL) {
        match = regexec(&regexp, entrypointer->d_name, 0, NULL, REG_EXTENDED);
        if (match == 0) {
          epubs[i] = entrypointer->d_name;
          i++;
        }
      }

      closedir(dirpointer);
    }
  }

  regfree(&regexp);
  return epubs;
}
