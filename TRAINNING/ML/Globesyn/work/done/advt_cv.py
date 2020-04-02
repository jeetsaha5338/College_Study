
import os
import numpy as np
import pandas as pd
from sklearn import metrics
import math
from sklearn import linear_model
import matplotlib.pyplot as plt
from sklearn import model_selection

os.chdir("E:\STUDY\Data_Files")
advt=pd.read_csv("advertising.csv")


advt=advt.drop("srno",axis=1)
y=advt['sales']
X=advt[['TV','radio']]

linmod=linear_model.LinearRegression()
'''cv=model_selection.cross_val_predict(linmod,X,y,cv=5)
cv.mean()
print(cv)

cv.shape
y.shape'''




X_train,X_test,y_train,y_test = model_selection.train_test_split(X,y,test_size=.2,random_state=42)


model=linear_model.LinearRegression()
model.fit(X_train,y_train)
predicted = model.predict(X_test)

print(math.sqrt((metrics.mean_squared_error(y_test,predicted))))


predicted2=model_selection.cross_val_score(linmod,X,y,cv=5)
print(predicted2)




#print(model_selection.cross_val_score.__doc__)
#train,test=model_selection.train_test_split(advt,test_size=0.25,random_state=42)







