# -*- coding: utf-8 -*-
"""
Created on Mon Jan 15 14:41:13 2018

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
from sklearn import grid_search

def print_score(prediction,actual):
    print("confution Matrix :")
    print(metrics.confusion_matrix(actual,prediction))
    print("Accuracy score :",metrics.accuracy_score(actual,prediction))
    print("Precision score :",metrics.precision_score(actual,prediction))
    print("Recall score :",metrics.recall_score(actual,prediction))
    print("F1 score :",metrics.f1_score(actual,prediction))
    print("AUC score :",metrics.roc_auc_score(actual,prediction))
    
os.chdir("H:\Data_Files")
lc=pd.read_csv("lungscancer.csv")
lc.head()

X=lc.drop(["id","diagnosis"],axis=1)
y=lc["diagnosis"]

stdscaler=preprocessing.StandardScaler()
X_std=stdscaler.fit_transform(X)
X_std[:3]
type(X_std)
X_std=pd.DataFrame(X_std,columns=X.columns.values)#convert ndarray to DataFrame
type(X_std)

y=(y=='M').astype(np.int)
X_train,X_test,y_train,y_test=model_selection.train_test_split(X_std,y,test_size=.25,random_state=42)

knnclf=neighbors.KNeighborsClassifier()
knnclf.fit(X_train,y_train)
predict=knnclf.predict(X_test)
print_score(predict,y_test)

param_grid={"n_neighbors":[3,5,7,9,11],"weights":["uniform","distance"]}
grid=grid_search.GridSearchCV(estimator=knnclf, param_grid=param_grid, scoring="roc_auc")
grid_fit=grid.fit(X_train,y_train)
print("Best Param :" ,grid_fit.best_params_)
print("Best Score :" ,grid_fit.best_score_)

bestclf=grid_fit.best_estimator_
type(bestclf)
predict=bestclf.predict(X_test)
print_score(predict,y_test)
















print("Using Pipeline:==================================")
knnclf=pipeline.Pipeline([("std",preprocessing.StandardScaler()),("clf",neighbors.KNeighborsClassifier())])
knnclf.fit(X_train,y_train)
predict=knnclf.predict(X_test)
print_score(predict,y_test)
