import os
import math
import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
from sklearn import metrics
from sklearn import svm
from sklearn import tree
from sklearn import neighbors
from sklearn import linear_model
from sklearn import neural_network
from sklearn import model_selection
from scipy.spatial import distance_matrix


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
        e=[]
        Y=pd.DataFrame()
        P=pd.DataFrame()
        for i in range(self.k):
            model=tree.DecisionTreeRegressor()
            X1=X_train1[X_train1.cluster==i].drop(['cluster'],axis=1)
            Y1=y_train1[y_train1.cluster==i].drop(['cluster'],axis=1)
            X2=X_test1[X_test1.cluster==i].drop(['cluster'],axis=1)
            Y2=y_test1[y_test1.cluster==i].drop(['cluster'],axis=1)
            if (Y2.shape[0]!=0):
                model.fit(X1,Y1.values.ravel())
                predicted=model.predict(X2)
                Y=pd.concat([Y,Y2],axis=0)
                P=pd.concat([P,pd.DataFrame(predicted)],axis=0)
                e.append(math.sqrt(metrics.mean_squared_error(Y2,predicted)))
           
#        if np.mean(e)<0.0022:
#            show(Y,P,"Hybrid")
        return(np.mean(e))
    

#                   END OF CLASS

def show(Actual,Predicted,s):
#    fig=plt.figure(figsize=(9,9))
    plt.scatter(Actual,Predicted)
    ax=plt.axes()
    plt.title(s)
    ax.plot([Actual.min(),Actual.max()],[Actual.min(),Actual.max()],'r-',lw=4)
    ax.set_xlabel('Actual')
    ax.set_ylabel('Predicted')
    plt.show()



#--------------------------------DATA LOADING----------------------------------
    
os.chdir("E:\STUDY\Data_Files")
data=pd.read_csv("UTM_EnvironmentalDataSet_2010_2.csv")

#------------------------------DATA PREPARATION--------------------------------

index=np.random.permutation(data.shape[0])
data=data.iloc[index,:]

X=data.filter(items=['field_soil_temp_c','field_air_temp_c','field_rh'])
y=pd.DataFrame(data["field_soil_wc"])



#--------------------------DATA SPLITING AND APPLING MODELS--------------------

X_train,X_test,y_train,y_test = model_selection.train_test_split(X,y,test_size=.2,random_state=42)

r=[]
minimum=0
for k in range(2,11):
    p = HY_Regressor(k)
    result_HY =p.result(X_train,y_train,X_test,y_test)
#    print("K_value:",k,"Value:",result_HY)
    r.append(result_HY)
    if result_HY==np.min(r):
        minimum=k
print("\nHY_REG:==>",np.min(r),"For K_value:",minimum)


k=minimum
#k=10

X_train,X_test,y_train,y_test=model_selection.train_test_split(X,y,test_size=.1,random_state=42)

e1=[]
e2=[]
e3=[]
e4=[]
e5=[]
e6=[]
for i in range(10):
    p = HY_Regressor(k)
    result_HY =p.result(X_train,y_train,X_test,y_test)
    e1.append(result_HY)
    
    '''model=neural_network.MLPRegressor()
    model.fit(X_train,y_train.values.ravel())
    predicted=model.predict(X_test)
#    if i==1:
#        show(y_test,predicted,"MLP_Regressor")
    result_NN= math.sqrt(metrics.mean_squared_error(y_test,predicted))
    e2.append(result_NN)
    
    model=linear_model.LinearRegression()
    model.fit(X_train,y_train)
    predicted=model.predict(X_test)
#    if i==1:
#        show(y_test,predicted,"LR")
    result_LR= math.sqrt(metrics.mean_squared_error(y_test,predicted))
    e3.append(result_LR)
    
    model=svm.SVR(kernel='poly', C=1e3, gamma='auto')
    model.fit(X_train,y_train.values.ravel())
    predicted=model.predict(X_test)
#    if i==1:
#        show(y_test,predicted,"Support Vector Machine")
    result_SVM= math.sqrt(metrics.mean_squared_error(y_test,predicted))
    e4.append(result_SVM)
    
    model=tree.DecisionTreeRegressor()
    model.fit(X_train,y_train.values.ravel())
    predicted=model.predict(X_test)
#    if i==1:
#        show(y_test,predicted,"Decision Tree")
    result_DT= math.sqrt(metrics.mean_squared_error(y_test,predicted))
    e5.append(result_DT)
    
    model=neighbors.KNeighborsRegressor(3,weights='distance')
    model.fit(X_train,y_train.values.ravel())
    predicted=model.predict(X_test)
#    if i==1:
#        show(y_test,predicted,"KNN")
    result_KNN= math.sqrt(metrics.mean_squared_error(y_test,predicted))
    e6.append(result_KNN)'''
    
    
#    print("\n\tItaration:",i,"\nHybrid:",result_HY,"\nNN:",result_NN,"\n\tLinear:",result_LR,
#          "\nSVM:",result_SVM,"\nDT:",result_DT,"\n\tK-NN:",result_KNN)


result=[]
result_HY=np.mean(e1)
result_NN=np.mean(e2)
result_LR=np.mean(e3)
result_SVM=np.mean(e4)
result_DT=np.mean(e5)
result_KNN=np.mean(e6)
result.append(result_HY)
result.append(result_NN)
result.append(result_LR)
result.append(result_SVM)
result.append(result_DT)
result.append(result_KNN)
s= result_HY==np.min(result)

print("\n\t\tAverage Result:\nHybrid:",result_HY,"\nNN:",result_NN,"\nLinear:",result_LR,
      "\nSVM:",result_SVM,"\nDT:",result_DT,"\nK-NN:",result_KNN)
print("\t\t\t\t",s)



