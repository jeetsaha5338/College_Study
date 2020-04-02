# -*- coding: utf-8 -*-
"""
Created on Fri Feb  2 23:49:04 2018

@author: User
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
from sklearn import feature_selection
from sklearn import naive_bayes
from sklearn.decomposition import PCA,TruncatedSVD

def print_score(prediction,actual):
    print("confution Matrix :")
    print(metrics.confusion_matrix(actual,prediction))
    print("Accuracy score :",metrics.accuracy_score(actual,prediction))
    print("Precision score :",metrics.precision_score(actual,prediction))
    print("Recall score :",metrics.recall_score(actual,prediction))
    print("F1 score :",metrics.f1_score(actual,prediction))
    print("AUC score :",metrics.roc_auc_score(actual,prediction))

#os.chdir("E:\Data_Files")#for clg
os.chdir("H:\Data_Files")#for home
#os.chdir("D:\\AOT\\Programings\\Machine_Learning_Training\\Data_set")
data= pd.read_csv("data_tenis.csv")
data=data.drop(data.columns.values[25:],axis=1) 
data.columns.values.shape
data=data.drop(["tourney_id","tourney_name","draw_size","tourney_level","tourney_date",
                "match_num","winner_entry","winner_name","winner_ht","winner_ioc","winner_rank",
                "winner_rank_points","loser_entry","loser_name","loser_ht","loser_ioc"],axis=1)

type(data)    
n=data.surface.unique()
a=n.shape
data['sur'] = data.surface.map({n[i]:i for i in range(a[0])})
data=data.drop(["surface"],axis=1)


n=pd.concat([data.loser_hand, data.winner_hand]).unique()
a=n.shape
data['l_hand'] = data.loser_hand.map({n[i]:i for i in range(a[0])})
data['w_hand'] = data.winner_hand.map({n[i]:i for i in range(a[0])})
data=data.drop(["winner_hand","loser_hand"],axis=1)   

n=pd.concat([data.loser_id, data.winner_id]).unique()
a=n.shape
data['l_id'] = data.loser_id.map({n[i]:i for i in range(a[0])})
data['w_id'] = data.winner_id.map({n[i]:i for i in range(a[0])})
data=data.drop(["winner_id","loser_id"],axis=1)  
    
for p_d in data:
    md=data[p_d].median()
    data[p_d]=data[p_d].fillna(value=md)



data
data1=pd.DataFrame(columns=['surface','player','p_seed','p_age','p_hand','o_seed','o_age','o_hand','win'])
data2=pd.DataFrame(columns=['surface','player','p_seed','p_age','p_hand','o_seed','o_age','o_hand','win'])

data1["player"]=data['w_id']
data1["p_seed"]=data['winner_seed']
data1["p_age"]=data['winner_age']
data1["p_hand"]=data['w_hand']
data1["o_seed"]=data['loser_seed']
data1["o_age"]=data['loser_age']
data1["o_hand"]=data['l_hand']
data1["surface"]=data['sur']
data1["win"]=1

data2["player"]=data['l_id']
data2["p_seed"]=data['loser_seed']
data2["p_age"]=data['loser_age']
data2["p_hand"]=data['l_hand']
data2["o_seed"]=data['winner_seed']
data2["o_age"]=data['winner_age']
data2["o_hand"]=data['w_hand']
data2["surface"]=data['sur']
data2["win"]=0


    
data_ = pd.concat([data1,data2],axis=0)    
data_.columns.values.shape 
data_.head()   
data_.tail()   
data_.shape 
data_.iloc[3362,:]
  
    
    
    
    
    
    
    
    
    