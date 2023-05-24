
'''
Shell不断的使用getcmd函数读取命令行的输入，然后使用runcmd来执行命令行的命令
'''
import random
from enum import Enum
import os
# class Cmd_type(Enum):
#     EXEC = 1
#     REDIR = 2
#     PIPE = 3
#     LIST = 4
#     BACK = 5

class Cmd(Enum):
    EXEC = 1
    REDIR = 2
    PIPE = 3
    LIST = 4
    BACK = 5
    def __init__(self,type):
        self.type = type
    def get_type(self):
        typelist = [self.EXEC,self.REDIR,self.PIPE,self.LIST,self.BACK]
        for cmd_type in typelist:
            if(self.type == cmd_type.value):
                return cmd_type.name + " cmd"
        raise Exception("No match cmd Type")

def runcmd(cmd):
    print(cmd)

def getcmd():
    try:
        command = str(input("$"))
        type = random.randint(1,5)
        cmd = Cmd(type).get_type()
        print(cmd)
        runcmd("excute {cmd}".format(cmd = command))
    except:
        raise RuntimeError("cmd error")

if __name__ == '__main__':
    while(True):
        getcmd()

