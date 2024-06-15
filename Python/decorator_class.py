from typing import Any
import os

class decorator_class:
    def __init__(self,fun):
        self.fun = fun
    def __call__(self, Name) -> Any:
        print('Bye')
        print('Name: {}'.format(Name))
        return self.fun()
@decorator_class
def fun():
    print('display')
fun('Radhe')
print(type(os.scandir()))