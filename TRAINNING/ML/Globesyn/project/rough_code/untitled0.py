# -*- coding: utf-8 -*-
"""
Created on Sat Jan 27 23:15:47 2018

@author: User
"""

# -*- coding: utf-8 -*-
"""
Created on Sat Jan 27 13:42:17 2018

@author: Sanmitra Kumar
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

data=data.drop(data.columns.values[30:],axis=1)        
data.columns.values
#data=pd.read_csv("data_tenis.csv")

data=data.drop(["draw_size","tourney_name","tourney_date","winner_seed","loser_seed","winner_name","loser_name","winner_rank","loser_rank"],axis=1)

leenc = preprocessing.LabelEncoder()
round_enc = leenc.fit_transform(data["round_"])
tourney_id_enc = leenc.fit_transform(data["tourney_id"])
surface_enc = leenc.fit_transform(data["surface"])
tourney_level_enc = leenc.fit_transform(data["tourney_level"])
loser_ioc_enc = leenc.fit_transform(data["loser_ioc"])
winner_ioc_enc = leenc.fit_transform(data["winner_ioc"])

data=data.drop(['round_','tourney_id','surface','tourney_level','loser_ioc','winner_ioc'],axis=1)

n=pd.concat([data.loser_entry, data.winner_entry]).unique()
a=n.shape
data['l_entry'] = data.loser_entry.map({n[i]:i for i in range(a[0])})
data['w_entry'] = data.winner_entry.map({n[i]:i for i in range(a[0])})
data=data.drop(["winner_entry","loser_entry"],axis=1)

n=pd.concat([data.loser_id, data.winner_id]).unique()
a=n.shape
data['l_id'] = data.loser_id.map({n[i]:i for i in range(a[0])})
data['w_id'] = data.winner_id.map({n[i]:i for i in range(a[0])})
data=data.drop(["winner_id","loser_id"],axis=1)

n=pd.concat([data.loser_hand, data.winner_hand]).unique()
a=n.shape
data['l_hand'] = data.loser_hand.map({n[i]:i for i in range(a[0])})
data['w_hand'] = data.winner_hand.map({n[i]:i for i in range(a[0])})
data=data.drop(["winner_hand","loser_hand"],axis=1)


w=np.zeros(5*data.shape[0]).reshape(data.shape[0],5)
l=np.zeros(5*data.shape[0]).reshape(data.shape[0],5)
for i in range(0,data.shape[0]):
    str1=data.score.iloc[i]
    scr=str1.split()
    j=0
    for setr in scr:
        if (setr!='RET') & (setr!='W/O') & (setr!='DEF') & (setr!='Default'):
            ptr=setr.split("-")
            w[i][j]=ptr[0]
            l[i][j]=ptr[1].split('(')[0]
            j=j+1


w_pd=pd.DataFrame(w,dtype=int)
l_pd=pd.DataFrame(l,dtype=int)

data['w_set1']=w_pd[0][i]
data['w_set2']=w_pd[1][i]
data['w_set3']=w_pd[2][i]
data['w_set4']=w_pd[3][i]
data['w_set5']=w_pd[4][i]


data['l_set1']=l_pd[0][i]
data['l_set2']=l_pd[1][i]
data['l_set3']=l_pd[2][i]
data['l_set4']=l_pd[3][i]
data['l_set5']=l_pd[4][i]

s=data.shape[0]+1
s1=int(s/2)
s2=s-s1
zero=np.zeros(s1,dtype=int)
one=np.ones(s2,dtype=int)
v=np.concatenate((zero, one), axis=0)
np.random.shuffle(v)
#print(v)
v_pd=pd.Series(v)

data['p1_id']=pd.DataFrame.empty
data['p2_id']=pd.DataFrame.empty

for i in range(0,data.shape[0]):
    if v_pd[i]==0:
        data['p1_id'][i] = data['w_id'][i]
        data['p2_id'][i]  = data['l_id'][i]
    
    else:
        data['p1_id'][i]  = data['l_id'][i]
        data['p2_id'][i]  = data['w_id'][i]
    


data['p1_id']=pd.DataFrame.empty
data.p1_id.iloc[2]= data['l_id'][5]





data['p1_id'].head()
data['w_id'].head()
data['p2_id'].head()
data['l_id'].head()





data.columns.values
data.shape
data=data.drop(["score","match_num"],axis=1)


enc_data = np.c_[round_enc,tourney_id_enc,surface_enc,tourney_level_enc,loser_ioc_enc,winner_ioc_enc]

enc_data_df = pd.DataFrame(enc_data,columns=['round_','tourney_id','surface','tourney_level','loser_ioc','winner_ioc'])

enc_data_df = pd.concat([data,enc_data_df],axis=1)

for p_d in enc_data_df:
    md=enc_data_df[p_d].median()
    enc_data_df[p_d]=enc_data_df[p_d].fillna(value=md)

 



data_1=enc_data_df.iloc[:3000]
z=enc_data_df.iloc[3000:]
data_1.shape
z.shape
y=(data_1["w_id"]!=data_1["p1_id"]).astype(np.int)
X=data_1.drop(["w_id","l_id"],axis=1)

#FINAL TESTING SET
y_z=(z["w_id"]!=z["p1_id"]).astype(np.int)
X_z=z.drop(["w_id","l_id"],axis=1)




#BAYES
X_train,X_test,y_train,y_test=model_selection.train_test_split(X,y,test_size=.20,random_state=42)
X_train.shape
X_train.columns.values
model = naive_bayes.GaussianNB()
model.fit(X_train,y_train)
model.classes_
model.class_count_
#model.feature_count_
predicted = model.predict(X_test)
print_score(predicted,y_test)


#PCA
pca = PCA(n_components=20,whiten=False)
X1 = pca.fit(X).transform(X)
print (X1)
svd = TruncatedSVD(n_components=15)
X2 = svd.fit(X).transform(X)

X_train,X_test,y_train,y_test=model_selection.train_test_split(X1,y,test_size=.20,random_state=42)
X_train.shape
#X_train.columns.values
model = naive_bayes.GaussianNB()
model.fit(X_train,y_train)
model.classes_
model.class_count_
#model.feature_count_
predicted = model.predict(X_test)
print_score(predicted,y_test)





#FOR KNN
X_train,X_test,y_train,y_test=model_selection.train_test_split(X,y,test_size=.20,random_state=42)
X_train.shape
X_train.columns.values
knnclf = neighbors.KNeighborsClassifier(algorithm ='kd_tree', n_neighbors= 11, weights= 'distance')
knnclf.fit(X_train,y_train)
predict = knnclf.predict(X_test)

print_score(predict,y_test)

param_grid = {"n_neighbors":[3,5,7,9,11],"weights":["uniform","distance"],"algorithm":['kd_tree','ball_tree','brute']}

grid = grid_search.GridSearchCV(estimator=knnclf,param_grid=param_grid,scoring="roc_auc")

grid_fit = grid.fit(X_train,y_train)
print("Best param : ",grid_fit.best_params_)
print("Best score : ",grid_fit.best_score_)

bestclf = grid_fit.best_estimator_
type(bestclf)
predicted = bestclf.predict(X_test)
print_score(predicted,y_test)