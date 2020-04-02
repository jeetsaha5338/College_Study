import os
#import math
import numpy as np
import pandas as pd
#import matplotlib.pyplot as plt
from sklearn import metrics
from sklearn import neighbors
#from sklearn import model_selection
from sklearn import linear_model
#from sklearn import preprocessing
#from sklearn import pipeline
from sklearn import naive_bayes
from sklearn import tree
#from sklearn import neural_network
from scipy.spatial import distance_matrix
#from sklearn.decomposition import PCA
from sklearn.cross_validation import KFold

class HY_Regressor:
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
        s1=0
        s2=0
        s3=0
        s4=0
#        s5=0
        for i in range(self.k):
            X1=X_train1[X_train1.cluster==i].drop(['cluster'],axis=1)
            Y1=y_train1[y_train1.cluster==i].drop(['cluster'],axis=1)
            X2=X_test1[X_test1.cluster==i].drop(['cluster'],axis=1)
            Y2=y_test1[y_test1.cluster==i].drop(['cluster'],axis=1)
            if (Y2.shape[0]!=0):                
                m1= naive_bayes.GaussianNB()
                m1.fit(X1,Y1.values.ravel())
                p1 = m1.predict(X2)
                s1+=metrics.accuracy_score(Y2,p1)
                
                m2= linear_model.LogisticRegression(solver='liblinear')
                m2.fit(X1,Y1.values.ravel())
                p2 = m2.predict(X2)
                s2+=metrics.accuracy_score(Y2,p2)
                
                m3=neighbors.KNeighborsClassifier(weights='distance')
                m3.fit(X1,Y1.values.ravel())
                p3 = m3.predict(X2)
                s3+=metrics.accuracy_score(Y2,p3)
                
                m4=tree.DecisionTreeClassifier()
                m4.fit(X1,Y1.values.ravel())
                p4 = m4.predict(X2)
                s4+=metrics.accuracy_score(Y2,p4)
                
#                m5 = neural_network.MLPClassifier()
#                m5.fit(X1,Y1.values.ravel())
#                p5 = m5.predict(X2)
#                s5+=metrics.accuracy_score(Y2,p5)

        return(s1/self.k,s2/self.k,s3/self.k,s4/self.k)

#--------------------------------DATA LOADING----------------------------------
       
os.chdir("E:\STUDY\Data_Files")#for home
data= pd.read_csv("messidor_features.csv")

#------------------------------DATA PREPARATION--------------------------------

index=np.random.permutation(data.shape[0])
data=data.iloc[index,:]

'''
Y=data['Y']
X=data.drop(['Y'],axis=1)
X.head()
pca=PCA(n_components=15)
pca.fit(X)
X=pca.transform(X)
X.head()

X_train=X[:800]
X_test=X[800:]
y_train=Y[:800]
y_test=Y[800:]'''

attr=data.columns.values
d=data.corr().iloc[19]
dc=[]

for i in range(20):
    if (d.iloc[i])<0:
        dc.append(attr[i])

data=data.drop(dc,axis=1)

X=data.drop(['Y'],axis=1)
y=data['Y']




f=10

kf = KFold(data.shape[0], n_folds=f)

e1=[]
e2=[]
e3=[]
e4=[]
en1=[]
en2=[]
en3=[]
en4=[]
#e5=[]

for train, test in kf:
    X_train = X.iloc[train,:]
    y_train = y.iloc[train]
    X_test = X.iloc[test,:]
    y_test = y.iloc[test]
    
    p = HY_Regressor(3)
    result_HY =p.result(X_train,y_train,X_test,y_test)
    e1.append(result_HY[0])
    e2.append(result_HY[1])
    e3.append(result_HY[2])
    e4.append(result_HY[3])
#    e5.append(result_HY[4])

    model1 = naive_bayes.GaussianNB()
    model1.fit(X_train,y_train)
    predicted1 = model1.predict(X_test)
    en1.append(metrics.accuracy_score(y_test,predicted1))
    
    model2=linear_model.LogisticRegression(solver='liblinear')
    model2.fit(X_train,y_train)
    predicted2 = model2.predict(X_test)
    en2.append(metrics.accuracy_score(y_test,predicted2))

    model3 = neighbors.KNeighborsClassifier(weights='distance')
    model3.fit(X_train,y_train)
    predicted3 = model3.predict(X_test)
    en3.append(metrics.accuracy_score(y_test,predicted3))

    model4 = tree.DecisionTreeClassifier()
    model4.fit(X_train,y_train)
    predicted4 = model4.predict(X_test)
    en4.append(metrics.accuracy_score(y_test,predicted4))


print("NB_H:",np.mean(e1))
print("NB_N:",np.mean(en1))

print("LR_H:",np.mean(e2))
print("LR_N:",np.mean(en2))

print("KNN_H:",np.mean(e3))
print("KNN_N:",np.mean(en3))

print("DT_H:",np.mean(e4))
print("DT_N:",np.mean(en4))
















#model5 = neural_network.MLPClassifier()
#model5.fit(X_train,y_train)
#predicted5 = model5.predict(X_test)
#print("MLP_Avg:",np.mean(e5),end=', ')
#print("MLP:",metrics.accuracy_score(y_test,predicted5))
