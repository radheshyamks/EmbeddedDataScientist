def fun(a,/,b,c,d):
    print(__name__)
    print(a, b,c,d)
def fun1(a,*,b,c,d):
    print(a,b,c,d)
fun(1,d=4,c=3,b=2)
fun1(1,d=4,c=3,b=2)
fun(6,7,8,9)