from functools import wraps
def decorator_fun(fun):
    @wraps(fun)
    def wrapper():
        print('wrapper')
        fun()
    return wrapper;
@decorator_fun
def display():
    print('display')
display()
print('hello')
display.__wrapped__()