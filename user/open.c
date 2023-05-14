/*
 *create a file , write to it
 */
#include "kernel/types.h"
#include "user/user.h"
#include "kernel/fcntl.h"

int main(){
    /*
     * open返回一些文件描述符，write可以将数据写入文件描述符对应的文件中
     */
    int fd = open("output.txt",O_WRONLY | O_CREATE);
    write(fd,"ooo\n",4);
    exit(0);
}