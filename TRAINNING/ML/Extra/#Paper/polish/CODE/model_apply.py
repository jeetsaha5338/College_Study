# -*- coding: utf-8 -*-
"""
Created on Thu Oct 25 17:55:25 2018

@author: USER
"""
import os
import numpy as np
import pandas as pd
from sklearn import neighbors
from sklearn import metrics
#from sklearn import model_selection
from sklearn import linear_model
from sklearn import preprocessing
from sklearn import pipeline
from sklearn import naive_bayes
from sklearn import tree
from sklearn import neural_network
#import matplotlib.pyplot as plt
from sklearn.cross_validation import KFold



os.chdir("E:\\STUDY\\COLLEGE_LAB\\4th_yr\\DATA\\Working_Data")
data=pd.read_csv("clr_polish_data.csv")

index=np.random.permutation(data.shape[0])
data=data.iloc[index,:]

data=data.drop(["Unnamed: 0"],axis=1)


X=data.drop(["target"],axis=1)

y=data["target"]


f=10

kf = KFold(data.shape[0], n_folds=f)
e_nv=[]
e_lr=[]
e_knn=[]
e_dt=[]
e_mlp=[]

for train, test in kf:
    X_train = X.iloc[train,:]
    y_train = y.iloc[train]
    X_test = X.iloc[test,:]
    y_test = y.iloc[test]
    
    model1 = naive_bayes.GaussianNB()
    model1.fit(X_train,y_train)
    predicted1 = model1.predict(X_test)
    e_nv.append(metrics.accuracy_score(y_test,predicted1))
    
    model2=linear_model.LogisticRegression()
    model2.fit(X_train,y_train)
    predicted2 = model2.predict(X_test)
    e_lr.append(metrics.accuracy_score(y_test,predicted2))

    model3 = neighbors.KNeighborsClassifier(weights='distance')
    model3.fit(X_train,y_train)
    predicted3 = model3.predict(X_test)
    e_knn.append(metrics.accuracy_score(y_test,predicted3))

    model4 = tree.DecisionTreeClassifier()
    model4.fit(X_train,y_train)
    predicted4 = model4.predict(X_test)
    e_dt.append(metrics.accuracy_score(y_test,predicted4))

    model5=pipeline.Pipeline([("scaler",preprocessing.StandardScaler()),("nn",neural_network.MLPClassifier( hidden_layer_sizes=100))])
    model5.fit(X_train,y_train)
    predicted5 = model5.predict(X_test)
    e_mlp.append(metrics.accuracy_score(y_test,predicted5))



print("Avg_nv:",np.mean(e_nv))
print("Avg_lr:",np.mean(e_lr))
print("Avg_knn:",np.mean(e_knn))
print("Avg_dt:",np.mean(e_dt))
print("Avg_mlp:",np.mean(e_mlp))
