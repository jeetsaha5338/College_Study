# -*- coding: utf-8 -*-
"""
Created on Fri Jan 19 22:50:19 2018

@author: User
"""

import os
import numpy as np
import pandas as pd
from sklearn import neighbors
from sklearn import metrics
from sklearn import linear_model
from sklearn import model_selection
from sklearn import preprocessing
from sklearn import pipeline
from sklearn import grid_search

'''def print_score(prediction,actual):
    print("confution Matrix :")
    print(metrics.confusion_matrix(actual,prediction))
    print("Accuracy score :",metrics.accuracy_score(actual,prediction))
    print("Precision score :",metrics.precision_score(actual,prediction))
    print("Recall score :",metrics.recall_score(actual,prediction))
    print("F1 score :",metrics.f1_score(actual,prediction))
    print("AUC score :",metrics.roc_auc_score(actual,prediction))
'''  
os.chdir("H:\Data_Files")
data=pd.read_csv("data_tenis.csv")
data.head()

n=data.t_name.unique()#name or id
a=n.shape
#print(n[0])
#n[331]
#a[0]
data['T_name'] = data.t_name.map({n[i]:i for i in range(a[0])})
data=data.drop(["t_name","t_id"],axis=1)

n=data.surface.unique()
a=n.shape
data['SUR'] = data.surface.map({n[i]:i for i in range(a[0])})
data=data.drop(["surface"],axis=1)

n=data.t_level.unique()
a=n.shape
data['T_lavel'] = data.t_level.map({n[i]:i for i in range(a[0])})
data=data.drop(["t_level"],axis=1)

n=pd.concat([data.loser_entry, data.winner_entry]).unique()
a=n.shape
data['l_entry'] = data.loser_entry.map({n[i]:i for i in range(a[0])})
data['w_entry'] = data.winner_entry.map({n[i]:i for i in range(a[0])})
data=data.drop(["winner_entry","loser_entry"],axis=1)

data.head()
data.tail()

data_1=data.iloc[:3001]
z=data.iloc[3001:]

X=data_1.drop(["winner_id"],axis=1)
y=data_1["winner_id"]

#FINAL TESTING SET
X_z=z.drop(["winner_id"],axis=1)
y_z=z["winner_id"]

X_train,X_test,y_train,y_test=model_selection.train_test_split(X,y,test_size=.25,random_state=42)

linmod=linear_model.LinearRegression()
linmod.fit(X_train,y_train)

