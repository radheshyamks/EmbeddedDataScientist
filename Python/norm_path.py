import os;
import pathlib;
from pathlib import Path
Env_Path=r'E:\NotepadPlusPlus\Python\Env'
print(os.sep)
print(os.path.normpath(Env_Path).split(os.sep))
print(Env_Path.split(os.sep))
print(f"{os.sep}".join(Env_Path.split(os.sep)))

def decorator_fun(fun):
    def wrapper(x):
        print('bye ',x)
        fun()
    return wrapper
@decorator_fun
def dec_fun():
    print('hello')
dec_fun(10)