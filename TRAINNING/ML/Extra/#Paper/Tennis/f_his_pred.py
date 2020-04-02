# -*- coding: utf-8 -*-
"""
Created on Sun Feb 18 15:53:45 2018

@author: User
"""
import os
import pandas as pd
from sklearn import neighbors
from sklearn import metrics
from sklearn import model_selection
from sklearn import linear_model
from sklearn import preprocessing
from sklearn import pipeline
from sklearn import naive_bayes
from sklearn import tree
#from sklearn.neural_network import MLPClassifier
from sklearn import neural_network
def print_score(str1,prediction,actual):
    print("\n\n\n",str1,"\n")
    print("confution Matrix :")
    print(metrics.confusion_matrix(actual,prediction))
    print("Accuracy score :",metrics.accuracy_score(actual,prediction))
    print("Precision score :",metrics.precision_score(actual,prediction))
    print("Recall score :",metrics.recall_score(actual,prediction))
    print("F1 score :",metrics.f1_score(actual,prediction))
    print("AUC score :",metrics.roc_auc_score(actual,prediction))
#os.chdir("F:\\jeet\\jeet_ml\\ML\\project\\given")
os.chdir("E:\Data_Files")#for home

data= pd.read_csv("tennis_new.csv")
data.iloc[:,0]
data=data.drop(data.columns.values[0:1],axis=1)
data.columns.values[10]

X=data.drop(['win'],axis=1)
y=data['win']
X_train,X_test,y_train,y_test = model_selection.train_test_split(X,y,test_size=.2,random_state=42)

#NAIVE BAYES
model = naive_bayes.GaussianNB()
model.fit(X_train,y_train)
predicted = model.predict(X_test)
print_score('NAIVE BAYES:',predicted,y_test)

#LOGISTIC REGRESSION
model1=linear_model.LogisticRegression()
model1.fit(X_train,y_train)
predicted1 = model1.predict(X_test)
print_score('LOGISTIC REGRESSION:',predicted1,y_test)

#KNN CLASSIFIER
knnclf = neighbors.KNeighborsClassifier()
knnclf.fit(X_train,y_train)
predict = knnclf.predict(X_test)
print_score('KNN CLASSIFIER:',predict,y_test)
'''knnclf = pipeline.Pipeline([("scaler",preprocessing.StandardScaler()),("knn",neighbors.KNeighborsClassifier())])
knnclf.fit(X_train,y_train)
predict = knnclf.predict(X_test)
print_score('KNN CLASSIFIER_STD:',predict,y_test)
'''
#DECISION TREE
treeclf = tree.DecisionTreeClassifier()
treeclf.fit(X_train,y_train)
predicted2 = treeclf.predict(X_test)
print_score('DECISION TREE:',predicted2,y_test)

#NEURAL_NETWORK
'''
np_model=neural_network.MLPClassifier()
np_model.fit(X_train,y_train)
predicted4 = np_model.predict(X_test)
print_score('NEURAL NETWORK:',predicted4,y_test)'''
np_model=pipeline.Pipeline([("scaler",preprocessing.StandardScaler()),("nn",neural_network.MLPClassifier())])
np_model.fit(X_train,y_train)
predicted4 = np_model.predict(X_test)
print_score('NEURAL NETWORK_STD:',predicted4,y_test)