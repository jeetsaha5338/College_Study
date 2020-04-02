import numpy as np
import pandas as pd
from sklearn import model_selection
import os




def predict(row,weights):
    activation=np.dot(weights[1:],row[:-1])+weights[0]
    return 1.0 if activation >=0.0 else  0.0

# this function is applying stocastic gradient descent (sgd)
def train_weights(xtrain,ytrain,lrate,nepoch):
    weights=np.zeros(xtrain.shape[1]+1)
    for epoch in range(nepoch):
        sum_error=0.0
        for xi ,target in zip(xtrain,ytrain):
            activation=np.dot(weights[1:],xi)+weights[0]
            p=1.0 if activation >=0.0 else 0.0
            error=target-p
            sum_error+=error**2
            update=lrate*error
            weights[1:] += update * xi
            weights[0] += update
        print('>epoch=%d, lrate=%.3f, error=%.3f' % (epoch, lrate, sum_error))
    return weights

def classify(train,test,lrate,epoch):
    ytrain=train[:,-1]#only take the last coloumn
    xtrain=train[:,:-1]#only take until the last coloumn
    predictions=list()
    weights=train_weights(xtrain,ytrain,lrate,epoch)
    for row in test:
        p=predict(row,weights)
        predictions.append(p)
    return predictions,weights
        


#lr=.01
#epoch=20
#w=train_weights(dataset,lr,epoch)
#print (w)


os.chdir('d:/Data_Files')
iris=pd.read_csv("iris.csv")
iris['class']=(iris['class']=='Iris-virginica').astype(np.float)
iris=iris[['pl','pw','class']]

iristrain,iristest=model_selection.train_test_split(iris,test_size=.25,random_state=42)

#type(iristrain.values)
#iristrain.describe()
preds,w=classify(iristrain.values,iristest.values,.01,1000)
print(w)

for r,p in zip(iristest.values[:,-1],preds):
    print("real : {} predicted : {}".format(r,p))


