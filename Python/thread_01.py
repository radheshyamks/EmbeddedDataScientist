import os;
import sys;
import pathlib;
import string;
import subprocess
import threading;
import logging;
import time
import multiprocessing
def fun1():
    for i in range(10000000):
        print('hello')
def fun():
    for i in range(10000000):
        print('Bye')
p = threading.Thread(target=fun1)
_p = threading.Thread(target=fun)
p.start()
_p.start()
p.join()
_p.join()