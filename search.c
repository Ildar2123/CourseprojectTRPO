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
  while ((entry = readdir(mydir)) != NULL) {
    if ((strcmp((entry->d_name), "NamesOfFiles.txt")) &&
        (strcmp((entry->d_name), ".")) && (strcmp((entry->d_name), "..")))
      fprintf(NamesOfFiles, "%s\n", (entry->d_name));
  }
  closedir(mydir);
  fclose(NamesOfFiles);
  return 0;
}

void Search(char where_search[], char what_search[]) {
  FILE *NamesOfFiles;

  char FileName[256] = "\0";
  char way[256] = "\0";
  char fullway[512] = "\0";
  char string[512];
  char file[512] = "\0";
  int c = 0;
  char *entry;
  strcat(file, where_search);
  strcat(file, "/");
  strcat(file, "NamesOfFiles.txt");
  NamesOfFiles = fopen(file, "r");

  strcat(way, where_search);
  strcat(way, "/");

  if ((NamesOfFiles = fopen(file, "r")) == NULL) {
    printf("UPS TT\nIt`s not working normally\n");
  } else {
    while (!feof(NamesOfFiles)) {
      fgets(FileName, 510, NamesOfFiles);

      c++;
    }

    fseek(NamesOfFiles, 0, SEEK_SET);

    for (int i = 1; i < c; i++) {
      FILE *File;
      int str = 0, k_v = 0;
      strcpy(fullway, "\0");
      strcpy(FileName, "\0");
      fgets(FileName, 510, NamesOfFiles);
      strcat(fullway, way);
      strcat(fullway, FileName);
      fullway[strlen(fullway) - 1] = '\0';
      File = fopen(fullway, "r");
      if ((File = fopen(fullway, "r")) == NULL) {
        printf("UPS TT\nIt`s not working normally\n");
      } else {
        while (!feof(File)) {
          entry = NULL;
          fgets(string, 510, File);
          str++;
          entry = strstr(string, what_search);
          if (entry != NULL) {
            printf("Строка номер %d : %s\n", str, string);
            k_v++;
          }
        }
        if (k_v != 0) {
          printf("\n\nДанные из файла %s\n", FileName);
        }
      }
      fclose(File);
    }
  }
  fclose(NamesOfFiles);
}