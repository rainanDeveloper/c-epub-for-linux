#include <dirent.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

bool is_regular_file(char *path);

bool is_directory(char *path);

bool path_exists(char *path);

bool is_epub_file(char *path);

int get_file_count(char *path);

char **get_files(char *path);
