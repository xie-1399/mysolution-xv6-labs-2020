#include "kernel/types.h"
#include "user/user.h"

int main(){
    /* copy input to output
     * 文件描述符0连接到console输入，1连接到输出
     * 系统调用read:(文件描述符，指针 ， 读取的字符大小) Return 读取的字节数
     *
     */
    char buf[64];

    while(1){
        int n = read(0,buf,sizeof (buf));
        if(n <= 0){
            break;
        }
        write(1,buf,n);
    }
    exit(0);
}