import os
import numpy as np
import pandas as pd
from sklearn import linear_model
from sklearn import model_selection 
import matplotlib.pyplot as plt
os.chdir("d:/Data_Files")
advt=pd.read_csv("advertising.csv")
#model_selection.train_test_split()


#plt.scatter(advt['TV'],advt['sales'])
#plt.xlabel("TV")

#plt.scatter(advt['radio'],advt['sales'])
#plt.xlabel("radio")


advt=advt.drop("srno",axis=1)
train,test=model_selection.train_test_split(advt,test_size=.25,random_state=42)
test.shape
train.shape


#y_advt=advt['sales']
#X_advt=advt[['TV','radio']]
y_train=train['sales']
X_train=train[['TV','radio','newspaper']]

y_test=test['sales']
X_test=test[['TV','radio','newspaper']]

linmod=linear_model.LinearRegression()
linmod.fit(X_train,y_train)
print("intercept: ",linmod.intercept_)

print("TV :",linmod.coef_[0])
print("radio :",linmod.coef_[1])
#sales=2.921 + 0.457*TV+1.88 * radio

adj_r_sq=linmod.score(X_train,y_train)
print("Score training :",adj_r_sq)

#advt['sales'].head()


advt[:3]
#linmod.predict([[17.2,45.9],[44.5,39.3]])
predicted_sales=linmod.predict(X_test)
#(predicted_sales-y_advt)**2
print(np.average((predicted_sales-y_test)**2))


