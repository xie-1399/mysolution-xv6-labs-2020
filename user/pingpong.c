/*
 * 父进程发送一个字节到子进程，子进程接收到该字节后，在终端打印": received ping"，
 * 把该字节写入管道到父进程，然后退出。父进程收到该字节后，在终端打印": received pong"
 * pipe[0] : read   pipe[1]:write
 */
#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

void check_and_write(int type,int pipe, char buf[] , int bytes){
    if(write(pipe,buf,bytes) != bytes){
        printf("type %d write error!\n",type);
        exit(1);
    }
}


int main(int argc , char* argv[]){
    if(argc != 1){
        printf("Invalid Parameter!\n");
        exit(1);
    }
    //Create the Pipe
    int fatherpipe[2],childpipe[2];
    pipe(fatherpipe);
    pipe(childpipe);
    char buf[1];
    if(fork() == 0){
        close(fatherpipe[0]);
        close(childpipe[1]);
        if(read(childpipe[0],buf,1) == 1){
            printf("%d: received ping\n",getpid());
            //write(fatherpipe[1],buf,1);  //not check
            check_and_write(1,fatherpipe[1],buf,1);
        }
        close(childpipe[0]);
        close(fatherpipe[1]);
        exit(0);

    }
    buf[0] = 'a';
    close(childpipe[0]);
    close(fatherpipe[1]);

    //write(childpipe[1],buf,1); //向子进程写入一个字节
    check_and_write(0,childpipe[1],buf,1);
    wait(0);
    close(childpipe[1]);
    if(read(fatherpipe[0],buf,1) == 1){
        printf("%d: received pong\n",getpid());
        close(fatherpipe[0]);
    }
    exit(0);
}