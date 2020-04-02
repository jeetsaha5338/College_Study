# -*- coding: utf-8 -*-
"""
Created on Mon Jan 15 17:02:58 2018

@author: didactics8
"""

import os
import numpy as np
import pandas as pd
from sklearn import neighbors
from sklearn import metrics
from sklearn import model_selection
from sklearn import preprocessing
from sklearn import pipeline

os.chdir("D:\Data_Files")
advt=pd.read_csv("advertising.csv")
advt=advt.drop("srno",axis=1)

y=advt["sales"]
X=advt.drop("sales",axis=1)
X_train,X_test,y_train,y_test=model_selection.train_test_split(X,y,test_size=.2,random_state=42)
pipeclf=pipeline.Pipeline([("imputer",preprocessing.Imputer(strategy="median")),("scaler",preprocessing.StandardScaler()),("regression",neighbors.KNeighborsRegressor())])
pipeclf.fit(X_train,y_train)
predicted=pipeclf.predict(X_test)
print("MSE :",metrics.mean_squared_error(y_test,predicted))
