# -*- coding: utf-8 -*-
"""
Created on Tue Jan 16 13:52:20 2018

@author: didactics8
"""

import os
import numpy as np
import pandas as pd
from sklearn import metrics
from sklearn import tree
from sklearn import model_selection
from sklearn import preprocessing
from sklearn import pipeline
from sklearn import grid_search

def print_score(prediction,actual):
    print("confution Matrix :")
    print(metrics.confusion_matrix(actual,prediction))
    print("Accuracy score :",metrics.accuracy_score(actual,prediction))
#    print("Precision score :",metrics.precision_score(actual,prediction))
#    print("Recall score :",metrics.recall_score(actual,prediction))
#    print("F1 score :",metrics.f1_score(actual,prediction))
#    print("AUC score :",metrics.roc_auc_score(actual,prediction))
    
os.chdir("D:/Data_Files")
iris=pd.read_csv("iris.csv")
iris
index=np.random.permutation(150)
iris=iris.iloc[index,:]
X=iris.drop("class",axis=1)
y=iris["class"]
X_train,X_test,y_train,y_test=model_selection.train_test_split(X,y,test_size=.2,random_state=42)

treeclf=tree.DecisionTreeClassifier(criterion="entropy",min_samples_leaf=20)
treeclf.fit(X_train,y_train)

tree.export_graphviz(treeclf,out_file='D:\pic\iris1.dot',
                     feature_names=iris.columns.values[:4],
                     class_names=["Iris-setosa","Iris-versicolor","Iris-virginica"],
                     rounded=True,filled=True)

#max_depth/min_samples_split/max_sample_leaf

predict=treeclf.predict(X_test)
print_score(predict,y_test)

param_grid1={"max_depth":[3,4,5,6,7],"min_samples_split":[10,15,20]}
param_grid2={"max_depth":[3,4,5,6,7],"max_sample_leaf":[10,15,20]}

grid=grid_search.GridSearchCV(estimator=treeclf, param_grid=param_grid1, scoring="roc_auc")
grid_fit=grid.fit(X_train,y_train)
#print("Best Param :" ,grid_fit.best_params_)
#print("Best Score :" ,grid_fit.best_score_)

bestclf=grid_fit.best_estimator_
type(bestclf)
predict=bestclf.predict(X_test)
print_score(predict,y_test)











