#using dictionary
import pandas as pd
data1={'Name':['sa','ss','ab'],'Age':[20,30,''],'Address':['asasa','dfss','sdsd']}
data2=[['sanu',30,4.0,'sanu'],[],[3.5,'jeet']]
d1=pd.DataFrame(data1,columns=['Name','Address'],index=['rank1','rank2','rank3'])
d2=pd.DataFrame(data2,index=['rank1','rank2','rank3'])
print(d1)
print(d2)
print(d1.index)#to show row name.
f=int(d2.iat[2,0])#to return value using row index & column index
print(f)