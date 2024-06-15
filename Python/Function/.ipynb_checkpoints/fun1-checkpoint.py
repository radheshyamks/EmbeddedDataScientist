def fun():
    print('hello')
def __main__(f):
    print('Main')
    f()
# fun()
__main__(fun)
import pandas as pd;
# pd.DataFrame()
Name=['Radhe','Nikki','Rakesh','Nikku']
Age=[30,24,27,19]
d={k:v for k,v in enumerate([5,1,4,4])}
print(d)
Details= {Name:Age for Name,Age in zip(Name,Age)}
print(Details)