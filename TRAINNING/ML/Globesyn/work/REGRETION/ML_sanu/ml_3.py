#whose t value is >0.01
import statsmodels.formula.api as smf
import pandas as pd 
import matplotlib.pyplot as plt
import numpy as np
data = pd.read_csv('machine.csv',header=None,index_col=0,names=['c0','c1','c2','c3','c4','c5','c6','c7','c8','c9'])
print(data)
print(data.shape)
data_train=data.iloc[:120]
print(data_train)
print(data_train.shape)
data_test=data.iloc[120:]
print(data_test)
print(data_test.shape)
lm1=smf.ols(formula='c8~c2+c3+c4+c5+c6+c7',data=data_train).fit()
print(lm1.params)
print(lm1.summary())
X_new1=data_test[['c2','c3','c4','c5','c6','c7']]
print(X_new1.head())
Y_perdicted1=lm1.predict(X_new1)
Y_actual1=np.array(data_test['c8'])
Y_predict1=np.array(Y_perdicted1)
print(Y_actual1)
print(Y_predict1)
err1=(Y_actual1-Y_predict1)**2
err1_mean=np.mean(err1)
err1_sqrt=np.sqrt(err1_mean)
print(err1_sqrt)

lm2=smf.ols(formula='c8~c3+c4+c5',data=data_train).fit()
print(lm2.params)
print(lm2.summary())
X_new2=data_test[['c3','c4','c5']]
print(X_new2.head())
Y_perdicted2=lm2.predict(X_new1)
Y_actual2=np.array(data_test['c8'])
Y_predict2=np.array(Y_perdicted2)
print(Y_actual2)
print(Y_predict2)
err2=(Y_actual2-Y_predict2)**2
err2_mean=np.mean(err2)
err2_sqrt=np.sqrt(err2_mean)
print(err2_sqrt) 