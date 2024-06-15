import sys;
import os;
import platform;
import time;
from pathlib import Path;
from os.path import getsize,join
import subprocess
import string
import multiprocessing
# subprocess.run(['cmd.exe', '/c', 'dir'])
# os.system('dir')
# os.system('cmd /k "date"')
# time.sleep(3)
# subprocess.run(['cmd.exe', '/c','cls'],shell=True)
p = subprocess.Popen(['cmd','/c','dir'])
out = p.wait()
print(out)