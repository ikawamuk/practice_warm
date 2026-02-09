#define _GNU_SOURCE
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    char *s = "#define _GNU_SOURCE%c#include <stdlib.h>%c#include <stdio.h>%c#include <unistd.h>%c%cint main(int argc, char *argv[])%c{%c    char *s = %c%s%c;%c    char fn[] = %c./quine_XXXX.c%c;%c    int  fd = mkstemps(fn, 2);%c    FILE *fp = fdopen(fd, %cw%c);%c    fprintf(fp, s, 10, 10, 10, 10, 10, 10, 10, 34, s, 34, 34, 34, 34, 34, 10, 10, 10);%c    fclose(fp);%c    return 0;%c}%c";
    char fn[] = "./quine_XXXX.c";
    int  fd = mkstemps(fn, 2);
    FILE *fp = fdopen(fd, "w");
    fprintf(fp, s, 10, 10, 10, 10, 10, 10, 10, 34, s, 34, 34, 34, 34, 34, 10, 10, 10);
    fclose(fp);
    return 0;
}
