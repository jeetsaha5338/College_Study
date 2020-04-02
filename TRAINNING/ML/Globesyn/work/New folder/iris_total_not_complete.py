import os
import numpy as np
import pandas as pd
from sklearn import linear_model
from sklearn import model_selection 
import matplotlib.pyplot as plt
os.chdir("d:/Data_Files")
iris=pd.read_csv("iris.csv")

list(iris)
iris['type']
#mydic={'Iris-setosa':1,'Iris-versicolor':2,'Iris-virginica':3}
iris['class']=(iris['type']=='Iris-setosa').astype(np.int)#type casting
X=iris[['pl','pw']]
y=iris['class']
model=linear_model.LogisticRegression()
model.fit(X,y)
predicted=model.predict(X)
model.predict_proba(X)
np.set_printoptions(suppress=True)
for actual,prediction in zip(y,predicted):
    print("Actual :{} ,Predicted:{}".format(actual,prediction))
    

#iris_setosa=iris[iris['class']==1]
#iris_nsetosa=iris[iris['class']!=1]
#print(iris_setosa)
#print(iris_nsetosa)

#plt.plot(iris_setosa['pw'],iris_setosa['pl'],'go')
#plt.plot(iris_nsetosa['pw'],iris_nsetosa['pl'],'r^')
