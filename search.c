#include "search.h"

int NameOfFiles(char argv[]) {
  FILE *NamesOfFiles;
  NamesOfFiles = fopen("./txt/NamesOfFiles.txt", "w+");

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

void Search(char where_search[], char what_search[]) {
  FILE *NamesOfFiles;
  FILE *File;
  NamesOfFiles = fopen("./txt/NamesOfFiles.txt", "r");
  char FileName[256];
  char way[256];
  char fullway[512] = "\0";

  strcat(way, where_search);
  strcat(way, "/");

  printf("%s\n", fullway);

  if ((NamesOfFiles = fopen("./txt/NamesOfFiles.txt", "r")) == NULL) {
    printf("UPS TT\nIt`s not working normally\n");
  } else {
    while (!feof(NamesOfFiles)) {
      strcpy(fullway, "");
      strcpy(FileName, "");
      fgets(FileName, 510, NamesOfFiles);
      
      strcat(fullway, way);
      strcat(fullway,FileName);
      printf("%s\n", fullway);
    }
  }
  fclose(NamesOfFiles);
}