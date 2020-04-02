# -*- coding: utf-8 -*-
"""
Created on Wed Jan 17 16:49:50 2018

@author: didactics8
"""

import os
import numpy as np
import pandas as pd
from sklearn import tree
from sklearn import metrics
from sklearn import model_selection
from sklearn import preprocessing
from sklearn import naive_bayes
from sklearn import linear_model

def print_score(prediction,actual):
    print("confution Matrix :")
    print(metrics.confusion_matrix(actual,prediction))
    print("Accuracy score :",metrics.accuracy_score(actual,prediction))
    print("Precision score :",metrics.precision_score(actual,prediction))
    print("Recall score :",metrics.recall_score(actual,prediction))
    print("F1 score :",metrics.f1_score(actual,prediction))
    print("AUC score :",metrics.roc_auc_score(actual,prediction))


os.chdir("H:\Data_Files")
car=pd.read_csv("car_classification.csv")
car.tail()
car=car.iloc[np.random.permutation(car.shape[0]),:]
y=(car["class"]!="unacc").astype(np.int)
type(y)
car.columns.values
leenc=preprocessing.LabelEncoder()
buying_enc=leenc.fit_transform(car["buying"])
#leenc.classes_
maint_enc=leenc.fit_transform(car["maint"])
doors_enc=leenc.fit_transform(car["doors"])
persons_enc=leenc.fit_transform(car["persons"])
lug_boot_enc=leenc.fit_transform(car["lug_boot"])
safety_enc=leenc.fit_transform(car["safety"])

enc_car=np.c_[buying_enc,maint_enc,doors_enc,persons_enc,lug_boot_enc,safety_enc]

encdf=pd.DataFrame(enc_car,columns=["buying","maint","doors","persons","lug_boot","safety"])

Xtrain,Xtest,ytrain,ytest=model_selection.train_test_split(encdf,y,test_size=.2,random_state=42)
type(encdf)
model=naive_bayes.MultinomialNB()
#naive_bayes.GaussianNB()             FOR DISCRIT DISTIBUTION
model.fit(Xtrain,ytrain)
predicted=model.predict(Xtest)

print_score(predicted,ytest)

predicted

ytest



