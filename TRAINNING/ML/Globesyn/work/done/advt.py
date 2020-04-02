import os
import numpy as np
import pandas as pd
os.chdir("d:/Data Files")
advt=pd.read_csv("advertising.csv")
type(advt)
advt.columns.values
advt["TV"].max()
advt["TV"].median()
advt.describe()
advt1=advt.drop("srno",axis=1)
advt1.shape
advt.shape
advt1.columns.values
co_ma=advt1.corr() #co-relation matrix
print(co_ma)
co_ma['sales'].sort_values(ascending=False)
y_advt1=advt1['sales']
y_advt1.shape
x_advt1=advt1[['TV'],['radio']]

