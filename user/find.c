#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"
#include "kernel/fs.h"
char* fmtname(char *path)
{
    static char buf[DIRSIZ+1];
    char *p;

    // Find first character after last slash.
    for(p=path+strlen(path); p >= path && *p != '/'; p--)
        ;
    p++;

    // Return blank-padded name.
    if(strlen(p) >= DIRSIZ)
        return p;
    memmove(buf, p, strlen(p));
    memset(buf+strlen(p), ' ', DIRSIZ-strlen(p));
    return buf;
}

//some questions

void print_path(char* path,const char* filename){
    struct stat st;
    int fd;
    char buf[512];
    if((fd = open(path, 0)) < 0){
        printf("cannot open %s\n", path);
        return;
    }

    if(fstat(fd, &st) < 0){
        printf("cannot stat %s\n", path);
        close(fd);
        return;
    }
    //递归寻找路径
    switch (st.type) {

        case T_FILE:
            if(strcmp(fmtname(path),filename) == 0){
                printf("%s\n", fmtname(path));
                return;
            }
        case T_DIR:
            printf("%s",path);
            print_path(fmtname(path),filename);
    }


}


int main(int argc , char* argv[]){
    if(argc != 3){
        printf("Invalid Parameter!");
        exit(1);
    }
    char* path = argv[1];
    char* filename = argv[2];
    print_path(path,filename);
    exit(0);
}