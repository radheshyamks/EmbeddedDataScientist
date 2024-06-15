import calendar as cal;
import time;
import timeit;
import pandas as pd;
import os;
import matplotlib as mtplt;
import matplotlib.pyplot as plt;
#os.chdir(r'E:\project\archive')
df = pd.read_csv(r'E:\project\archive\GlobalLandTemperaturesByState.csv')
# plt.plot(df)
# plt.show()
# pd.DataFrame()
# print(df)
# print(df.head(10))
# print(pd.options.display.max_rows)
# print('\n10 bottom records')
# print(df.tail(10))
# clmn_1 = df.tail(10)
print(df['AverageTemperature'].tail(10))
print(df['Country'].tail(10))
df.loc()