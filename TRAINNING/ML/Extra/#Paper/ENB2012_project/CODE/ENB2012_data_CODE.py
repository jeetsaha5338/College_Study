import os
import math
import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
from sklearn import metrics
from sklearn import tree
from sklearn import neighbors
from sklearn import linear_model
from sklearn import neural_network
from sklearn.cross_validation import KFold

    
os.chdir("E:\STUDY\Data_Files")
data=pd.read_csv("ENB2012_data_csv.csv")
data=data[:768]

index=np.random.permutation(data.shape[0])
data=data.iloc[index,:]

data=data.drop(["Unnamed: 10","Unnamed: 11"],axis=1)
data['X234']=data['X4']+data['X2']+data['X3']

X=data.drop(["X2","X3","X4","Y1","Y2"],axis=1)
y1=data["Y1"]
y2=data["Y2"]

def show(Actual,Predicted,s):
    plt.scatter(Actual,Predicted)
    ax=plt.axes()
    plt.title(s)
    ax.plot([Actual.min(),Actual.max()],[Actual.min(),Actual.max()],'r-',lw=4)
    ax.set_xlabel('Actual')
    ax.set_ylabel('Predicted')
    plt.show()


f=10
kf = KFold(data.shape[0], n_folds=f)


print("================================Y1===================================")

e1=[]
e2=[]
e3=[]
e4=[]
Y1=pd.DataFrame()
P1=pd.DataFrame()

Y2=Y3=Y4=Y1
P2=P3=P4=P1

i=0

for train, test in kf:
    i=i+1
    X_train = X.iloc[train,:]
    y_train = y1.iloc[train]
    X_test = X.iloc[test,:]
    y_test = y1.iloc[test]
    model=neural_network.MLPRegressor()
    model.fit(X_train,y_train.values.ravel())
    predicted=model.predict(X_test)
    Y1=pd.concat([Y1,y_test],axis=0)
    P1=pd.concat([P1,pd.DataFrame(predicted)],axis=0)  
    result_NN= math.sqrt(metrics.mean_squared_error(y_test,predicted))
    e1.append(result_NN)
    
    model=linear_model.LinearRegression()
    model.fit(X_train,y_train)
    predicted=model.predict(X_test)
    Y2=pd.concat([Y2,y_test],axis=0)
    P2=pd.concat([P2,pd.DataFrame(predicted)],axis=0)
    result_LR= math.sqrt(metrics.mean_squared_error(y_test,predicted))
    e2.append(result_LR)
    
    model=neighbors.KNeighborsRegressor(5,weights='distance')
    model.fit(X_train,y_train.values.ravel())
    predicted=model.predict(X_test)
    Y3=pd.concat([Y3,y_test],axis=0)
    P3=pd.concat([P3,pd.DataFrame(predicted)],axis=0)
    result_KNN= math.sqrt(metrics.mean_squared_error(y_test,predicted))
    e3.append(result_KNN)
    
    model=tree.DecisionTreeRegressor()
    model.fit(X_train,y_train.values.ravel())
    predicted=model.predict(X_test)
    Y4=pd.concat([Y4,y_test],axis=0)
    P4=pd.concat([P4,pd.DataFrame(predicted)],axis=0)
    result_DT= math.sqrt(metrics.mean_squared_error(y_test,predicted))
    e4.append(result_DT)
    
    print("n\tItaration:",i)
    print("MLP_R: %s" % "{0:.4}".format(result_NN))
    print("__LR_: %s" % "{0:.3}".format(result_LR))
    print("KNN_R: %s" % "{0:.3}".format(result_KNN))
    print("DT__R: %s" % "{0:.2}".format(result_DT))
    '''if i==f:
        show(Y1,P1,"MLP_Regressor")
        show(Y2,P2,"Linear Regressor")
        show(Y3,P3,"K-NN")
        show(Y4,P4,"Decision Tree")'''
    

print("\n\t\tAverage Result:")
print("MLP_R: %s" % "{0:.4}".format(np.mean(e1)))
print("__LR_: %s" % "{0:.3}".format(np.mean(e2)))
print("KNN_R: %s" % "{0:.3}".format(np.mean(e3)))
print("DT__R: %s" % "{0:.2}".format(np.mean(e4)))

print("===============================Y2================================")

e1=[]
e2=[]
e3=[]
e4=[]
Y1=pd.DataFrame()
P1=pd.DataFrame()

Y2=Y3=Y4=Y1
P2=P3=P4=P1

i=0

for train, test in kf:
    i=i+1
    X_train = X.iloc[train,:]
    y_train = y2.iloc[train]
    X_test = X.iloc[test,:]
    y_test = y2.iloc[test]
    model=neural_network.MLPRegressor()
    model.fit(X_train,y_train.values.ravel())
    predicted=model.predict(X_test)
    Y1=pd.concat([Y1,y_test],axis=0)
    P1=pd.concat([P1,pd.DataFrame(predicted)],axis=0)  
    result_NN= math.sqrt(metrics.mean_squared_error(y_test,predicted))
    e1.append(result_NN)
    
    model=linear_model.LinearRegression()
    model.fit(X_train,y_train)
    predicted=model.predict(X_test)
    Y2=pd.concat([Y2,y_test],axis=0)
    P2=pd.concat([P2,pd.DataFrame(predicted)],axis=0)
    result_LR= math.sqrt(metrics.mean_squared_error(y_test,predicted))
    e2.append(result_LR)
    
    model=neighbors.KNeighborsRegressor(9,weights='distance')
    model.fit(X_train,y_train.values.ravel())
    predicted=model.predict(X_test)
    Y3=pd.concat([Y3,y_test],axis=0)
    P3=pd.concat([P3,pd.DataFrame(predicted)],axis=0)
    result_KNN= math.sqrt(metrics.mean_squared_error(y_test,predicted))
    e3.append(result_KNN)
    
    model=tree.DecisionTreeRegressor()
    model.fit(X_train,y_train.values.ravel())
    predicted=model.predict(X_test)
    Y4=pd.concat([Y4,y_test],axis=0)
    P4=pd.concat([P4,pd.DataFrame(predicted)],axis=0)
    result_DT= math.sqrt(metrics.mean_squared_error(y_test,predicted))
    e4.append(result_DT)
    
    print("n\tItaration:",i)
    print("MLP_R: %s" % "{0:.4}".format(result_NN))
    print("__LR_: %s" % "{0:.3}".format(result_LR))
    print("KNN_R: %s" % "{0:.3}".format(result_KNN))
    print("DT__R: %s" % "{0:.2}".format(result_DT))
    '''if i==f:
        show(Y1,P1,"MLP_Regressor")
        show(Y2,P2,"Linear Regressor")
        show(Y3,P3,"K-NN")
        show(Y4,P4,"Decision Tree")'''
    

print("\n\t\tAverage Result:")
print("MLP_R: %s" % "{0:.4}".format(np.mean(e1)))
print("__LR_: %s" % "{0:.3}".format(np.mean(e2)))
print("KNN_R: %s" % "{0:.3}".format(np.mean(e3)))
print("DT__R: %s" % "{0:.2}".format(np.mean(e4)))
     



