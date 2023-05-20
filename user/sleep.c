//implement the sleep for the xv6::
#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int main(int argc, char *argv[]){

    if(argc != 2){
        write(1, "InValid Parameter error\n", sizeof ("InValid Parameter error\n"));
        exit(1);
    }
    //atoi change char* number to int
    sleep(atoi(argv[1]));
    exit(0);
}
