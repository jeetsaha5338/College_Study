import os
import numpy as np
import pandas as pd
from sklearn import linear_model
from sklearn import model_selection 
import matplotlib.pyplot as plt

os.chdir("E:\STUDY\Data_Files")
pima=pd.read_csv("pima_diabetics.csv")
#print(dibe)
y=pima['class']

X=pima.drop("class",axis=1)#search on the header coloumn rowwise

X_train,X_test,y_train,y_test=model_selection.train_test_split(X,y,test_size=.25,random_state=42)
model=linear_model.LogisticRegression()
model.fit(X_train,y_train)

predicted=model.predict(X_test)
predicted

for act,pred in zip(y_test,predicted):
    print("actual : {} , prediction : {} ".format(act,pred))
y_test.value_counts()
    


