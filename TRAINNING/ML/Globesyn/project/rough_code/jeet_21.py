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
from sklearn import naive_bayes
from sklearn import grid_search

def print_score(prediction,actual):
    print("confution Matrix :")
    print(metrics.confusion_matrix(actual,prediction))
    print(metrics.confusion_matrix(actual,prediction).shape)
    print("Accuracy score :",metrics.accuracy_score(actual,prediction))
    print("Precision score :",metrics.precision_score(actual,prediction))
    print("Recall score :",metrics.recall_score(actual,prediction))
    print("F1 score :",metrics.f1_score(actual,prediction))
    print("AUC score :",metrics.roc_auc_score(actual,prediction))

#os.chdir("E:\Data_Files")#for clg
os.chdir("H:\Data_Files")#for home
data=pd.read_csv("data_tenis.csv")
#data = pd.read_csv("tennis_data1.csv")#for small data
data=data.drop(["tourney_name","tourney_id","match_num","round_","minutes","draw_size","tourney_date","winner_seed","loser_seed","winner_name","loser_name","winner_rank","loser_rank","score"],axis=1)
data.head()

data.shape

##

'''n=data.round_.unique()
a=n.shape
data['Round'] = data.round_.map({n[i]:i for i in range(a[0])})
data=data.drop(["round_"],axis=1)'''

'''n=data.tourney_id.unique()#name or id
a=n.shape
#print(n[0])
#n[331]
#a[0]
data['T_name'] = data.tourney_id.map({n[i]:i for i in range(a[0])})
data=data.drop(["tourney_name","tourney_id"],axis=1)'''




n=data.surface.unique()
a=n.shape
data['SUR'] = data.surface.map({n[i]:i for i in range(a[0])})
data=data.drop(["surface"],axis=1)

n=data.tourney_level.unique()
a=n.shape
data['T_lavel'] = data.tourney_level.map({n[i]:i for i in range(a[0])})
data=data.drop(["tourney_level"],axis=1)

n=pd.concat([data.winner_id, data.loser_id]).unique()
a=n.shape
data['l_id'] = data.winner_id.map({n[i]:i for i in range(a[0])})
data['w_id'] = data.loser_id.map({n[i]:i for i in range(a[0])})
data=data.drop(["winner_id","loser_id"],axis=1)

n=pd.concat([data.loser_entry, data.winner_entry]).unique()
a=n.shape
data['l_entry'] = data.loser_entry.map({n[i]:i for i in range(a[0])})
data['w_entry'] = data.winner_entry.map({n[i]:i for i in range(a[0])})
data=data.drop(["winner_entry","loser_entry"],axis=1)

n=pd.concat([data.loser_ioc, data.winner_ioc]).unique()
a=n.shape
data['l_ioc'] = data.loser_ioc.map({n[i]:i for i in range(a[0])})
data['w_ioc'] = data.winner_ioc.map({n[i]:i for i in range(a[0])})
data=data.drop(["winner_ioc","loser_ioc"],axis=1)

n=pd.concat([data.loser_hand, data.winner_hand]).unique()
a=n.shape
data['l_hand'] = data.loser_hand.map({n[i]:i for i in range(a[0])})
data['w_hand'] = data.winner_hand.map({n[i]:i for i in range(a[0])})
data=data.drop(["winner_hand","loser_hand"],axis=1)

data.shape
data.columns.values


for p_d in data:
    md=data[p_d].median()
    data[p_d]=data[p_d].fillna(value=md)




s=data.shape[0]+1
s1=int(s/2)
s2=s-s1
zero=np.zeros(s1,dtype=int)
one=np.ones(s2,dtype=int)
v=np.concatenate((zero, one), axis=0)
np.random.shuffle(v)
#print(v)
v_pd=pd.Series(v)
#v_pd
data['p1_id']=pd.DataFrame.empty
data['p2_id']=pd.DataFrame.empty

i=0
while i<(s-1):
    if v_pd.iloc[i]==0:
        data.p1_id.iloc[i]=data.w_id.iloc[i]
        data.p2_id.iloc[i]=data.l_id.iloc[i]
    else:
        data.p1_id.iloc[i]=data.l_id.iloc[i]
        data.p2_id.iloc[i]=data.w_id.iloc[i]
    
    i=i+1


v_pd.shape


#    data['p2_id']=v_pd.map({0:data.l_id.iloc[i],1:data.w_id.iloc[i]})

'''
for p_d in data:
    md=data[p_d].isnull().sum()
    print(md)
'''




data_1=data.iloc[:3000]
z=data.iloc[3000:]

y=(data_1['w_id']!=data_1['p1_id']).astype(np.int)
X=data_1.drop(["w_id","l_id"],axis=1)

#FINAL TESTING SET
'''X_z=z.drop(["w_id"],axis=1)
y_z=z["w_id"]'''

X_train,X_test,y_train,y_test=model_selection.train_test_split(X,y,test_size=.10,random_state=42)

model=neighbors.KNeighborsClassifier()#naive_bayes.MultinomialNB()
#model=naive_bayes.GaussianNB()            # FOR DISCRIT DISTIBUTION
model.fit(X_train,y_train)
predicted=model.predict(X_test)
print_score(predicted,y_test)

param_grid={"n_neighbors":[3,5,7,9,11],"weights":["uniform","distance"]}
grid=grid_search.GridSearchCV(estimator=model, param_grid=param_grid, scoring="roc_auc")
grid_fit=grid.fit(X_train,y_train)
print("Best Param :" ,grid_fit.best_params_)
print("Best Score :" ,grid_fit.best_score_)

bestclf=grid_fit.best_estimator_
type(bestclf)
predict=bestclf.predict(X_test)
print_score(predict,y_test)




