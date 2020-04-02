# -*- coding: utf-8 -*-
"""
Created on Tue Jan 16 16:10:58 2018

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
from sklearn import datasets
import matplotlib.pyplot as plt

m=1000
X=6*np.random.rand(m,1) - 3
y=.5*X**2 + .3*X + 2 + np.random.randn(m,1)
plt.plot(X,y,"g*")

X_train,X_test,y_train,y_test=model_selection.train_test_split(X,y,test_size=.2,random_state=42)
linmod=linear_model.LinearRegression()
linmod.fit(X_train,y_train)
predicted1=linmod.predict(X_test)
linmod.intercept_

print(metrics.mean_squared_error(y_test,predicted1))
plt.plot(X,y,"b.")
plt.plot(X_test,predicted1,"r--")

poly_mod=preprocessing.PolynomialFeatures(degree=2,include_bias=False)
Xtrain_poly=poly_mod.fit_transform(X_train)
X.shape
Xtrain_poly.shape

linmod=linear_model.LinearRegression()
linmod.fit(Xtrain_poly,y_train)
predicted2=linmod.predict(Xtrain_poly)
plt.plot(X_train,y_train,"g.")
plt.plot(X_train,predicted2,"r.")

linmod.intercept_
linmod.coef_

X,y=datasets.make_circles(100,noise=0.09,factor=.6)
X.shape
plt.plot(X[:,0][y==0],X[:,1][y==0],"go")
plt.plot(X[:,0][y==1],X[:,1][y==1],"bo")
#os.chdir("D:\Data_Files")
