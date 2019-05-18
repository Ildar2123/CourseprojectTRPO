#include "search.h"

int NameOfFiles(char argv[]) {
  FILE *NamesOfFiles;
  char fullway[512] = "\0";
  strcat(fullway, argv);
  strcat(fullway, "/");
  strcat(fullway, "NamesOfFiles.txt");
  NamesOfFiles = fopen(fullway, "w+");

  DIR *mydir = opendir(argv);
  if (mydir == NULL) {
    perror("opendir");
    return -1;
  }
  struct dirent *entry;
  while (entry = readdir(mydir)) {
    if ((strcmp(entry->d_name, "NamesOfFiles.txt")) &&
        (strcmp(entry->d_name, ".")) && (strcmp(entry->d_name, "..")))
      fprintf(NamesOfFiles, "%s\n", entry->d_name);
  }
  closedir(mydir);
  fclose(NamesOfFiles);
  return 0;
}

void Search(char w_search[])
{
    printf("hello, world");
}