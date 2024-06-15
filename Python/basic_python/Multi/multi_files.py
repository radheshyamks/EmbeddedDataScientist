##
# Radheshyam
##
import os;
import time
from time import sleep
MAX=11
# for i in range(MAX):
#     with open('file_%d.txt' %i, 'w') as p:
#         # sleep(2)
#         pass
# for i in range(MAX):
#     sleep(0.5)
#     os.remove('file_%d.txt' %i)
# print(all(os.scandir(os.getcwd())))
# if all(os.scandir(os.getcwd())):
#     print('All file is deleted')
# print(os.getcwd(),' ',len(os.getcwd()))
# if len(os.getcwd()):
#     print('Not Empty')
# if os.path.exists(os.getcwd()):
#     print('yes')
dir_cnt=0
MAX:int=11
def creat_dir(cur_path,arg):
    global dir_cnt
    dir_cnt+=1
    try:
        os.mkdir(os.path.join(cur_path,str(arg)))
        # print(dir_cnt)
        print(cur_path)
        if dir_cnt>=MAX:
            dir_cnt=0
            return
        else:
            path=os.path.join(cur_path,str(arg))
            creat_dir(path)
        arg=dir_cnt
    except:
        path=os.path.join(cur_path,str(arg))
        creat_dir(path,dir_cnt)
for i in range(MAX):
    creat_dir(os.getcwd(),i)