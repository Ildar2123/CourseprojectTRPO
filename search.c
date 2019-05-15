#include "search.h"

int NameOfFiles(char argv[])
{
    printf(argv);
    FILE *NamesOfFiles;
    NamesOfFiles = fopen("./txt/NamesOfFiles.txt", "w+");

    DIR *mydir = opendir(argv); // вместо / напиши нужный адрес
    if (mydir == NULL)
    {
        perror("opendir");
        return -1;
    }
    struct dirent *entry;
    while (entry = readdir(mydir))
    {

        printf("%s\n", entry->d_name);
        if ((strcmp(entry->d_name, "NamesOfFiles.txt")) && (strcmp(entry->d_name, ".")) && (strcmp(entry->d_name, "..")))
        fprintf(NamesOfFiles, "%s\n", entry->d_name);
    }
    closedir(mydir);
    return 0;
}