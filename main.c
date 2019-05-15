#include <stdio.h>
#include <dirent.h>
#include <string.h>
int main(int argc, char **argv)
{
    printf("%s\n%s\n%s\n",argv[1],argv[2],argv[3]);
    DIR *mydir = opendir("/"); // вместо / напиши нужный адрес
    if(mydir == NULL) {
        perror("opendir");
        return -1;
    }
    struct dirent *entry;
    while(entry = readdir(mydir)) {
        // тут делаем что нам надо, в данном случае просто печатаем название файла
        printf("%s\n", entry->d_name);
    }
    closedir(mydir);
}