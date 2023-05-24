#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

/*
 * 质数筛：对于每一个质数创建一个对应的进程
 */

int isPrime(int num) {
    //判断一个数是否为质数
    if(num < 2) {
        return 0;
    }
    for(int i = 2; i * i <= num; i++) {
        if(num % i == 0) {
            return 0;
        }
    }
    return 1;
}

//递归的传递对应的数,
void settochild(int num,int pipeport[2]){
    int counter = 2;
    while(counter < num){
        close(pipeport[0]);
        close(pipeport[1]);
        if(isPrime(counter)){
            printf("prime %d\n",counter);
            fork();
        }
        counter++;
//        settochild(num,pipeport);
    }


}

int main(int argc , char* agrv[]){
    if(argc != 1){
        printf("Invalid Parameter!\n");
        exit(1);
    }
    int pipeport[2];
    int num = 35;
    settochild(num,pipeport);
    wait(0);
    exit(0);
}