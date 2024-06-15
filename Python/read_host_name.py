import os;
import string;
import platform;
import sys;
import pathlib;
from pathlib import Path
C_Files=[]
path = r'E:\NotepadPlusPlus\Python\Env'
with open('c_file.txt','r') as f:
    for line in f:
        C_Files.append(line.strip())
for file in C_Files:
    pass
for Host in os.scandir(path):
    for files in os.scandir(Host):
        if files.is_file():
            if files.name==f'{Host.name}.env1':
                # print(os.path.join(os.path.join(path,Host),files.name))
                with open(os.path.join(os.path.join(path,Host),files.name),'r') as f:
                    for txt in f:
                        lst=[]
                        if txt.startswith('Env'):
                            for i in txt.split(':'):
                                lst.append(i.strip())
                        if lst:
                            for f1 in C_Files:
                                for f2 in lst:
                                    if f1==f2:
                                        print(Host.name)
                                        break