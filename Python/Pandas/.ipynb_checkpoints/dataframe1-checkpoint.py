import pandas as pd
# path=r'E:/NotepadPlusPlus/Python\basic_python/GDP.csv'
df=pd.read_csv('GDP.csv')
# df = pd.DataFrame(df)
print(df.shape)
print(df.head(10))
print(df.info())
pd.set_option('display.max_columns',None)
pd.set_option('display.max_rows',None)
print(df.isnull())