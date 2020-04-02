import pandas as pd
p3=pd.read_csv('file_1.csv',header=None,names=['col1','col2','col3'])
p3.columns=['col4','col5','col6']#set column name
p3['col7']=[1,2,3]#to add new column
df=pd.DataFrame(p3)#to convert .csv file to dataframe
df.index=['r1','r2','r3']#to rename row
print(df)
df1=df.loc['r2':'r3']#to slice using row name
print(df1)
df2=df.iloc[1:2]#to slice using index no.
print(df2)
e=df.at['r2','col5']#to return value using row name & column name
print(e)
f=df.iat[1,1]#to return value using row index & column index
print(f)