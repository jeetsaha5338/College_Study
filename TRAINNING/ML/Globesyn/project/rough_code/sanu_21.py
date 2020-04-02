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
from sklearn import feature_selection
from sklearn import svm

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
data = pd.read_csv("tennis_data1.csv")
#data=pd.read_csv("data_tenis.csv")
data=data.drop(["draw_size","tourney_name","tourney_date","winner_seed","loser_seed","winner_name","loser_name","winner_rank","loser_rank","score"],axis=1)
data.head()

leenc = preprocessing.LabelEncoder()
round_enc = leenc.fit_transform(data["round_"])

tourney_id_enc = leenc.fit_transform(data["tourney_id"])

surface_enc = leenc.fit_transform(data["surface"])

tourney_level_enc = leenc.fit_transform(data["tourney_level"])

winner_id_enc = leenc.fit_transform(data["winner_id"])

loser_id_enc = leenc.fit_transform(data["loser_id"])

loser_ioc_enc = leenc.fit_transform(data["loser_ioc"])

winner_ioc_enc = leenc.fit_transform(data["winner_ioc"])


n=pd.concat([data.loser_entry, data.winner_entry]).unique()
a=n.shape
data['l_entry'] = data.loser_entry.map({n[i]:i for i in range(a[0])})
data['w_entry'] = data.winner_entry.map({n[i]:i for i in range(a[0])})
data=data.drop(["winner_entry","loser_entry"],axis=1)

n=pd.concat([data.loser_hand, data.winner_hand]).unique()
a=n.shape
data['l_hand'] = data.loser_hand.map({n[i]:i for i in range(a[0])})
data['w_hand'] = data.winner_hand.map({n[i]:i for i in range(a[0])})
data=data.drop(["winner_hand","loser_hand"],axis=1)

data=data.drop(['round_','tourney_id','surface','tourney_level','winner_id','loser_id','loser_ioc','winner_ioc'],axis=1)
enc_data = np.c_[round_enc,tourney_id_enc,surface_enc,tourney_level_enc,winner_id_enc,loser_id_enc,loser_ioc_enc,winner_ioc_enc]
enc_data_df = pd.DataFrame(enc_data,columns=['round_','tourney_id','surface','tourney_level','winner_id','loser_id','loser_ioc','winner_ioc'])

enc_data_df = pd.concat([data,enc_data_df],axis=1)

for p_d in enc_data_df:
    md=enc_data_df[p_d].median()
    enc_data_df[p_d]=enc_data_df[p_d].fillna(value=md)

enc_data_df["winner_id"].unique()

for p_d in enc_data_df:
    md=enc_data_df[p_d].isnull().sum()
    print(md)


#data_1=enc_data_df.iloc[:300]
#z=enc_data_df.iloc[300:]



X=enc_data_df.drop(["winner_id"],axis=1)
y=(enc_data_df["winner_id"]==5).astype(np.int)

#FINAL TESTING SET
#X_z=z.drop(["winner_id"],axis=1)
#y_z=z["winner_id"]

X_train,X_test,y_train,y_test=model_selection.train_test_split(X,y,test_size=.20,random_state=42)
X_train.shape
X_train.columns.values
linmod=svm.SVC(kernel="poly")





selector = feature_selection.RFE(linmod,30,step=1)
selector = selector.fit(X_train,y_train)
selector.support_
selector.ranking_
linmod.fit(X_train,y_train)
#bestof,L_hand,W_hand,l_entry,w_entry,sur,t_level,l_svgm
predicted=linmod.predict(X_test)
print_score(predicted,y_test)