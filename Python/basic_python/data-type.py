import calendar as cal;
import time;
import timeit;
import pandas as pd;
lst = ['name','.','txt']
file_name = ''.join(lst)
#print(file_name)

data = {
    'Name': ['Radhe','Shyam','Kumar'],
    'salary':[3000,2000,4000],
    'age': [20,30,28]
}
#pandas.DataFrame(data=None, index=None, columns=None, dtype=None, copy=None)

df = pd.DataFrame(data)
print(df)
#print(df['salary'])