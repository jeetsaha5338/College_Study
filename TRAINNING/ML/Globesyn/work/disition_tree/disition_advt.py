# -*- coding: utf-8 -*-
"""
Created on Tue Jan 16 15:51:07 2018

@author: didactics8
"""

import os
import numpy as np
import pandas as pd
from sklearn import tree
from sklearn import metrics
from sklearn import model_selection
from sklearn import preprocessing
from sklearn import pipeline
from sklearn import linear_model

os.chdir("D:\Data_Files")
advt=pd.read_csv("advertising.csv")
advt=advt.drop("srno",axis=1)

y=advt["sales"]
X=advt.drop("sales",axis=1)

treereg=tree.DecisionTreeRegressor()
treereg.fit(X,y)
predicted1=treereg.predict(X)
tree.export_graphviz(treereg,out_file='D:/pic/advt.dot',feature_names=X.columns.values,rounded=True,filled=True)


linear_reg=linear_model.LinearRegression()
linear_reg.fit(X,y)
predicted2=linear_reg.predict(X)
print("MSE (tree) :",metrics.mean_squared_error(y,predicted1))
print("MSE (lin reg) :",metrics.mean_squared_error(y,predicted2))