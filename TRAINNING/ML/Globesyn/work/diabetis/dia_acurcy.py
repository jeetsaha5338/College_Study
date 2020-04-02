import os
import numpy as np
import pandas as pd
from sklearn import linear_model
from sklearn import model_selection 
#import matplotlib.pyplot as plt
os.chdir("d:/Data_Files")
pima=pd.read_csv("pima_diabetics.csv")
#print(dibe)
y=pima['class']

X=pima.drop("class",axis=1)#search on the header coloumn rowwise

X_train,X_test,y_train,y_test=model_selection.train_test_split(X,y,test_size=.25,random_state=42)
model=linear_model.LogisticRegression()
model.fit(X_train,y_train)

predicted=model.predict(X_test)
predicted
i=0
for act,pred in zip(y_test,predicted):
    print("actual : {} , prediction : {} ".format(act,pred))
    i=i+1

e=np.count_nonzero(y_test-predicted)
print("accurecy :",100-((e*100)/i),"%")
