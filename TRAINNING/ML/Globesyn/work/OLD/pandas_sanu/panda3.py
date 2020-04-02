#to create table using .csv file 
import pandas as pd
p3=pd.read_csv('file_1.csv',header=None,names=['col1','col2','col3'])
print(p3.head())
print(p3.head(2))#to show from start
print(p3.tail(1))#to show from end
print(p3.head(2).tail(3))#to show a single row
print(p3.columns)#to show columns
print(p3.values)#to show values of dataframe
print(p3['col2'].max())#to show max value of a column
print(p3['col2'].min())#to show min value of a column
print(p3['col2'].unique())#to show unique value of a column
print(p3['col2'].describe())#to show details of a column
print(p3['col1'].describe())#to show details of a column
print("==============")
p3.columns=['col4','col5','col6']#set column name
p3['col7']=[1,2,3]#to add new column
df=pd.DataFrame(p3)#to convert .csv file to dataframe
print(p3)
print(df)
df.index=['r1','r2','r3']#to rename row
df['col7']=df['col7']+1#to add value with existing value
print(df)
del df['col7']#to delete a column
print(df)