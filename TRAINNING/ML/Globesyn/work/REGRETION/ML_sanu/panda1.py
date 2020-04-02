#to create table using DataFrame 
import pandas as pd
data1=[2,3,5,'abcd']
print(data1)
#data2=[(2,30,4.0,'sanu'),(3,30,5.2,'sush')]
data2=[['sanu',30,4.0,'sanu'],[],[3.5,'jeet']]
print(data2)
df1=pd.DataFrame(data1)
print(df1)
df2=pd.DataFrame(data2,columns=['ID','AGE','SALARY','NAME'])
print(df2)
