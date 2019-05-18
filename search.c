#include "search.h"

int NameOfFiles(char argv[])
{
    FILE *NamesOfFiles;
    NamesOfFiles = fopen("./txt/NamesOfFiles.txt", "w+");

    DIR *mydir = opendir(argv);
    if (mydir == NULL)
    {
        perror("opendir");
        return -1;
    }
    struct dirent *entry;
    while (entry = readdir(mydir))
    {
        if ((strcmp(entry->d_name, "NamesOfFiles.txt")) && (strcmp(entry->d_name, ".")) && (strcmp(entry->d_name, "..")))
            fprintf(NamesOfFiles, "%s\n", entry->d_name);
    }
    closedir(mydir);
    fclose(NamesOfFiles);
    return 0;
}

void Search(char w_search[])
{
    FILE *NamesOfFiles;
    NamesOfFiles = fopen("./txt/NamesOfFiles.txt", "r");
    fseek(NamesOfFiles,0,SEEK_SET);
    char FileName[256];

    if ((NamesOfFiles = fopen("./txt/NamesOfFiles.txt", "r"))==NULL){
        printf("UPS TT\nIt`s not working normally\n");
    }
    else{
        while(!feof(NamesOfFiles)){
            
            fgets(FileName,254,NamesOfFiles);
            printf("%s\n",FileName);
        }
    }
    fclose(NamesOfFiles);
}