import os
import math
import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
from sklearn import metrics
from sklearn import svm
from sklearn import tree
from sklearn import neighbors
from sklearn import naive_bayes
from sklearn import linear_model
from sklearn import neural_network
from sklearn import model_selection
from scipy.spatial import distance_matrix
from sklearn.cross_validation import KFold
from sklearn import preprocessing
from sklearn import pipeline

class K_MLP_CLS:
    k=0
    centroids = pd.DataFrame().astype(np.double)
    def __init__(self,k_value):
        self.k = k_value
    
    def update(self,data):
        for i in range(self.k):
            xk=data[data['cluster']==i]
            xk=xk.drop(['cluster'],axis=1)
            self.centroids.iloc[i]= np.apply_along_axis(np.mean, axis=0, arr=xk)

    def assign(self,data,centroids):
        dist_mat=distance_matrix(data,centroids,p=2)
        close=np.zeros(data.shape[0]).astype(np.int)
        for i in range(data.shape[0]):
            d = dist_mat[i]
            close[i] = (np.where(d==np.min(d)))[0][0].astype(np.int)
        data['cluster']=close
        
        return data
    
    def result(self,X_train,y_train,X_test,y_test):
        X_train1=X_train.copy()
        y_train1=y_train.copy()
        X_test1=X_test.copy()
        y_test1=y_test.copy()
        init_centroid_index = np.random.choice(X_train1.shape[0],self.k)
        self.centroids = X_train1.iloc[init_centroid_index].copy()
        X_train1=self.assign(X_train1,self.centroids)
        while True:
            closest_centroids = X_train1['cluster'].copy(deep=True)
            self.update(X_train1)
            X_train1=X_train1.drop(['cluster'],axis=1)
            X_train1 = self.assign(X_train1,self.centroids)
            if closest_centroids.equals(X_train1['cluster']):
                break
        y_train1=pd.concat([y_train1,X_train1['cluster']],axis=1)
        X_test1=self.assign(X_test1,self.centroids)
        y_test1=pd.concat([y_test1,X_test1['cluster']],axis=1)
        e=[]
        for i in range(self.k):
            X1=X_train1[X_train1.cluster==i].drop(['cluster'],axis=1)
            Y1=y_train1[y_train1.cluster==i].drop(['cluster'],axis=1)
            X2=X_test1[X_test1.cluster==i].drop(['cluster'],axis=1)
            Y2=y_test1[y_test1.cluster==i].drop(['cluster'],axis=1)
#            model = naive_bayes.GaussianNB()
#            model=linear_model.LogisticRegression()
#            model = neighbors.KNeighborsClassifier()
#            model = tree.DecisionTreeClassifier()
            model=pipeline.Pipeline([("scaler",preprocessing.StandardScaler()),
                                        ("nn",neural_network.MLPClassifier())])
            if (Y2.shape[0]!=0):
                model.fit(X1,Y1.values.ravel())
                predicted = model.predict(X2)
                e.append(metrics.accuracy_score(Y2,predicted))
        return(np.mean(e))
    

#                   END OF CLASS

#--------------------------------DATA LOADING----------------------------------
    
os.chdir("E:\\STUDY\\COLLEGE_LAB\\4th_yr\\DATA\\Working_Data")
data=pd.read_csv("clr_polish_data.csv")

index=np.random.permutation(data.shape[0])
data=data.iloc[index,:]

data=data.drop(["Unnamed: 0"],axis=1)


X=data.drop(["target"],axis=1)

y=data["target"]

#--------------------------DATA SPLITING AND APPLING MODELS--------------------

X_train,X_test,y_train,y_test = model_selection.train_test_split(X,y,test_size=.1,random_state=42)

p = K_MLP_CLS(3)
result_HY =p.result(X_train,y_train,X_test,y_test)
print("Value:",result_HY)
 


