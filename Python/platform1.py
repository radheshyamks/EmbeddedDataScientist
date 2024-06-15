import os;
import sys
import pathlib;
import platform;
from colorama import Fore,Style,init
from pathlib import Path;
import shutil
import shutils;
import string
uname = list(platform.uname())
release = platform.release()
node = platform.node()
version = platform.version()
machine = platform.machine()
system = platform.system()
sys_details = ['system','node','release','version','machine']
i=0
print(platform.platform())
print(platform.processor())
print(platform.architecture())
try:
    print(platform.freedesktop_os_release())
except FileNotFoundError:
    print("File not found error")
for name in sys_details:
    print(f'{name:<8}: {uname[i]}')
    i+=1
try:
    def get_like_distro():
        info = platform.freedesktop_os_release()
        ids = [info["ID"]]
        if "ID_LIKE" in info:
            # ids are space separated and ordered by precedence
            ids.extend(info["ID_LIKE"].split())
        return ids
    get_like_distro()
except OSError:
    print('Error raised')