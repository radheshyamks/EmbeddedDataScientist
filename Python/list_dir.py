import os;
import sys;
import platform
import string
import colorama;
from colorama import Fore,Style,init
st_path=r'E:\NotepadPlusPlus\Python\Env'
if os.path.exists(st_path):
    def dir_fun(st_path):
        for name in os.listdir(st_path):
            path=os.path.join(st_path,name)
            if os.path.isfile(path):
                os.remove(path)
            else:
                dir_fun(path)
        os.rmdir(st_path)
    dir_fun(st_path)
else:
    print(f'{Fore.BLUE}{st_path}{Fore.RED}{Style.BRIGHT} does not exist')