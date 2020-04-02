import os
import numpy as np
import pandas as pd

os.chdir("E:\\STUDY\\COLLEGE_LAB\\4th_yr\\DATA\\Working_Data")
data=pd.read_csv("polish_data.csv")

data.head()
data.shape

data.target.unique()
data[data.target==1].shape[0]

#print(data.apply(lambda data: sum(data=='?'), adatais=0))

data.replace("?", np.nan, inplace = True)

#print(data.apply(lambda data: sum(data.isnull()), adatais=0))
#print("=========================================")
#print(data.apply(lambda data: sum(data=='?'), adatais=0))

for s in data:
    v = data[s].astype("float").mean(axis = 0)
    data[s].replace(np.nan, v, inplace = True)
    data[s] = data[s].astype("float")
    
    
#print(data.apply(lambda data: sum(data.isnull()), adatais=0))


#print(data.dtypes)

d=data.corr()
#plt.matshow(d)

a=[]
for i in range(64):
    if abs(d.iloc[64][i]) < 0.01:
        a.append(data.columns.values[i])


data=data.drop(a,axis=1)


data.to_csv('clr_polish_data.csv')

