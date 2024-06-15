# delete the Env folders completely
import os;
import sys;
import platform
import colorama
from colorama import Fore,Style,init
import shutil;
import shutils;
import pathlib;
from pathlib import Path
Env_Path=r'E:\NotepadPlusPlus\Python\Env'
try:
    def del_env_recursively(cur_path):
        for dir in os.listdir(cur_path):
            path = os.path.join(cur_path,dir)
            if os.path.isfile(path):
                os.remove(path)
            else:
                del_env_recursively(path)
        os.rmdir(cur_path)
    del_env_recursively(Env_Path)
except FileNotFoundError:
    print('file not found')