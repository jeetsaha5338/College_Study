# -*- coding: utf-8 -*-
"""
Created on Wed Jan 17 13:53:46 2018

@author: didactics8
"""

import numpy as np
import pandas as pd
from sklearn import tree
from sklearn import metrics
from sklearn import model_selection
from sklearn import preprocessing
from sklearn import pipeline
from sklearn import linear_model
from sklearn import datasets
from sklearn import grid_search
import matplotlib.pyplot as plt
from sklearn import svm

def print_score(prediction,actual):
    print("confution Matrix :")
    print(metrics.confusion_matrix(actual,prediction))
    print("Accuracy score :",metrics.accuracy_score(actual,prediction))
    print("Precision score :",metrics.precision_score(actual,prediction))
    print("Recall score :",metrics.recall_score(actual,prediction))
    print("F1 score :",metrics.f1_score(actual,prediction))
    print("AUC score :",metrics.roc_auc_score(actual,prediction))

X,y=datasets.make_moons(4000,noise=0.15,random_state=42)
X_train,X_test,y_train,y_test=model_selection.train_test_split(X,y,test_size=.25,random_state=42)
X_train.shape

#plt.plot(X_train[:,0][y_train==0],X_train[:,1][y_train==0],"b.")
#plt.plot(X_train[:,0][y_train==1],X_train[:,1][y_train==1],"y.")

lnsvc=pipeline.Pipeline([("scaler",preprocessing.StandardScaler()),("svc",svm.SVC(C=1, kernel="poly", coef0=1, degree=2))])
    
lnsvc.fit(X_train,y_train)
predicted_train=lnsvc.predict(X_train)
predicted_test=lnsvc.predict(X_test)

print("TRAIN:==========================")
print_score(predicted_train,y_train)
print("TEST:===========================")
print_score(predicted_test,y_test)




X,y=datasets.make_circles(1000,noise=0.11,factor=0.6)
X_train,X_test,y_train,y_test=model_selection.train_test_split(X,y,test_size=.25,random_state=42)
X_train.shape

plt.plot(X_train[:,0][y_train==0],X_train[:,1][y_train==0],"b.")
plt.plot(X_train[:,0][y_train==1],X_train[:,1][y_train==1],"y.")

lnsvc=pipeline.Pipeline([("scaler",preprocessing.StandardScaler()),("svc",svm.SVC(C=1, kernel="poly", coef0=1, degree=2))])
    
lnsvc.fit(X_train,y_train)
predicted_train=lnsvc.predict(X_train)
predicted_test=lnsvc.predict(X_test)

print("TRAIN:==========================")
print_score(predicted_train,y_train)
print("TEST:===========================")
print_score(predicted_test,y_test)
