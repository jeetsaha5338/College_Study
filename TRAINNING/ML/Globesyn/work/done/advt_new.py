 # -*- coding: utf-8 -*-
"""
Created on Tue Jan  9 14:56:07 2018

@author: Russel
"""

import os
import numpy as np
import pandas as pd
from sklearn import linear_model
import matplotlib.pyplot as plt
from sklearn import model_selection

os.chdir("d:/data_files")
advt=pd.read_csv("advertising.csv")


'''plt.scatter(advt['TV'],advt['sales'])
plt.xlabel("TV")

plt.scatter(advt['radio'],advt['sales'])
plt.xlabel("radio")'''

advt=advt.drop("srno",axis=1)

train,test=model_selection.train_test_split(advt,test_size=0.25,random_state=42)
print(train.shape)
print(test.shape)

y_train=train['sales']
X_train=train[['TV','radio','newspaper']]

y_test=train['sales']
X_test=train[['TV','radio','newspaper']]

linmod=linear_model.LinearRegression()
linmod.fit(X_train,y_train)
print("intercept : ",linmod.intercept_)

print("TV :",linmod.coef_[0])
print("radio :",linmod.coef_[1])

#sales=2.921 + 0.0457 * TV + 0.188 * radio

adj_r_sq=linmod.score(X_train,y_train)
print("adj_r_sq :",adj_r_sq)
advt['sales'].head()

advt[:3]
predicted_sales=linmod.predict(X_test)
#print(predicted_sales)
#(predicted_sales - y_advt)**2
print("rms :",np.average((predicted_sales - y_test)**2))

print("rmsc :",np.sqrt(np.average((predicted_sales - y_test)**2)))






