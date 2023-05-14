### Mysolution about XV6 Lab

------

some tips between clion and xv6

```
查看xv6终端的进程：ctrl + p
关闭xv6 ： ctrl + a 再按x
Clion查看某一个函数被哪些函数调用：ctrl + alt + h
```

#### 开启调试

在一个终端打开qemu-gdb运行

```
make qemu-gdb

//另外终端
gdb-multiarch
file user/_ls
br main
target remote localhost:26000
进入GDB正常进行调试
```

