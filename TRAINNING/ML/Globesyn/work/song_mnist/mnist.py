# -*- coding: utf-8 -*-
"""
Created on Fri Jan 12 16:13:54 2018

@author: GFS36
"""

import os
import numpy as np
import pandas as pd
from sklearn import linear_model
from sklearn import model_selection 
import matplotlib.pyplot as plt
import matplotlib
from sklearn import metrics
os.chdir("d:/Data_Files")
#train=pd.read_csv("mnist_train.csv",header=None)
mnist=pd.read_csv("mnist_test.csv",header=None)
train,test=model_selection.train_test_split(mnist,test_size=.25,random_state=42)

Xtrain=train.iloc[:,1:]
ytrain=train.iloc[:,0]
Xtest=test.iloc[:,1:]
ytest=test.iloc[:,0]

ytrain5=(ytrain==5).astype(np.int)
ytest5=(ytest==5).astype(np.int)

arow=Xtrain.iloc[0,:].reshape(28,28)
plt.imshow(arow,cmap=matplotlib.cm.binary,interpolation="nearest")
ytrain[0]

sgd=linear_model.SGDClassifier(loss="log",random_state=42)
sgd.fit(Xtrain,ytrain5)
ytrain5.value_counts()
predicted=sgd.predict(Xtest)
conf_mat=metrics.confusion_matrix(ytest5,predicted)
print(conf_mat)

acc_score=metrics.accuracy_score(ytest5,predicted)
print("acuracy :",acc_score)
prec_score=metrics.precision_score(ytest5,predicted)
print("precition :",prec_score)
rec_score=metrics.recall_score(ytest5,predicted)
print("recall :",rec_score)
auc_score=metrics.roc_auc_score(ytest5,predicted)
print("auc :",auc_score)

sgd.predict_proba(Xtest)#as it is not use sigmoaed func

yscore=sgd.decision_function(Xtest)

np.max(yscore)
np.min(yscore)

predicted1=(yscore >= 0).astype(np.int)
print(predicted1)

conf_mat1=metrics.confusion_matrix(ytest5,predicted1)
print(conf_mat)
print(conf_mat1)

precition,recall,threshold=metrics.precision_recall_curve(ytest5,yscore)
for p,r,t in zip(precition,recall,threshold):
    print("Treshold : {:.4f} , Precition : {:.4f} , Recall : {:.4f}".format(t,p,r))

plt.plot(threshold,precition[:-1],'r--')
plt.plot(threshold,recall[:-1],'g--')

plt.plot(precition[:-1],recall[:-1],'b--')
plt.plot(recall[:-1],precition[:-1],'b--')#precition recall carve

fpr,tpr,threshold=metrics.roc_curve(ytest5,yscore)
plt.plot(fpr,tpr)#roc_auc curve