import os;
import platform;
import sys;
import threading;
from concurrent.futures import ThreadPoolExecutor
import subprocess;
import time;
import shutil;
import shutils;
# E:\NotepadPlusPlus\Python
Folder_Path = r'E:\NotepadPlusPlus\Python\Env'
# print(os.getcwd())
# print(os.walk(Folder_Path))
# Gen_walk = os.walk(Folder_Path)
# print(Gen_walk)
File_Name_list = []
host_name=[]
# for dir_path, dir, name in os.walk(Folder_Path):
#     print(dir)
#     print(dir_path)
#     if name:
#         File_Name_list.append(name.pop())
# print(File_Name_list)
# print(host_name)
print('Os CPU count: ', os.cpu_count())