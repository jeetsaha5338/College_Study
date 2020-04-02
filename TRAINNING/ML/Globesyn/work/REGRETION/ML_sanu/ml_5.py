import statsmodels.formula.api as smf
import pandas as pd 
import matplotlib.pyplot as plt
import numpy as np
data = pd.read_csv('servo.csv',header=None,names=['c0','c1','c2','c3','c4'])
print(data)
print(data.shape)

data['c0A'] = data.c0.map({'A':1, 'B':0,'C':0,'D':0,'E':0})
data['c0B'] = data.c0.map({'A':0, 'B':1,'C':0,'D':0,'E':0})
data['c0C'] = data.c0.map({'A':0, 'B':0,'C':1,'D':0,'E':0})
data['c0D'] = data.c0.map({'A':0, 'B':0,'C':0,'D':1,'E':0})
data['c0E'] = data.c0.map({'A':0, 'B':0,'C':0,'D':0,'E':1})
data['c1A'] = data.c1.map({'A':1, 'B':0,'C':0,'D':0,'E':0})
data['c1B'] = data.c1.map({'A':0, 'B':1,'C':0,'D':0,'E':0})
data['c1C'] = data.c1.map({'A':0, 'B':0,'C':1,'D':0,'E':0})
data['c1D'] = data.c1.map({'A':0, 'B':0,'C':0,'D':1,'E':0})
data['c1E'] = data.c1.map({'A':0, 'B':0,'C':0,'D':0,'E':1})

print(data)
print(data.shape)

data_train=data.iloc[:120]
print(data_train)
print(data_train.shape)

co_rel=np.corrcoef(data_train.c2,data_train.c3)
print(co_rel)

co_rel=np.corrcoef(data_train[['c2','c3','c0A','c0B','c0C','c0D','c0E','c1A','c1B','c1C','c1D','c1E']])
print(co_rel)
data_test=data.iloc[120:]
print(data_test)
print(data_test.shape)

print('MODEL_1 WITH ALL ATTRIBUTES')
lm1=smf.ols(formula='c4~c2+c3+c0A+c0B+c0C+c0D+c0E+c1A+c1B+c1C+c1D+c1E',data=data_train).fit()
print(lm1.params)
print(lm1.summary())

X_new1=data_test[['c2','c3','c0A','c0B','c0C','c0D','c0E','c1A','c1B','c1C','c1D','c1E']]
print(X_new1.head())
Y_perdicted1=lm1.predict(X_new1)
Y_actual1=np.array(data_test['c4'])
Y_predict1=np.array(Y_perdicted1)
print(Y_actual1)
print(Y_predict1)
err1=(Y_actual1-Y_predict1)**2
err1_mean=np.mean(err1)
err1_sqrt=np.sqrt(err1_mean)
print('MODEL_1:',err1_sqrt)

print('MODEL_2 WITHOUT C2 & C0D')
lm2=smf.ols(formula='c4~c3+c0A+c0B+c0C+c0E+c1A+c1B+c1C+c1D+c1E',data=data_train).fit()
print(lm2.params)
print(lm2.summary())

X_new2=data_test[['c3','c0A','c0B','c0C','c0E','c1A','c1B','c1C','c1D','c1E']]
print(X_new2.head())
Y_perdicted2=lm2.predict(X_new2)
Y_actual2=np.array(data_test['c4'])
Y_predict2=np.array(Y_perdicted2)
print(Y_actual2)
print(Y_predict2)
err2=(Y_actual2-Y_predict2)**2
err2_mean=np.mean(err2)
err2_sqrt=np.sqrt(err2_mean)
print('MODEL_2',err2_sqrt)

print('MODEL_3 WITHOUT C3 & C0D')
lm3=smf.ols(formula='c4~c2+c0A+c0B+c0C+c0E+c1A+c1B+c1C+c1D+c1E',data=data_train).fit()
print(lm3.params)
print(lm3.summary())

X_new3=data_test[['c2','c0A','c0B','c0C','c0E','c1A','c1B','c1C','c1D','c1E']]
print(X_new3.head())
Y_perdicted3=lm3.predict(X_new3)
Y_actual3=np.array(data_test['c4'])
Y_predict3=np.array(Y_perdicted3)
print(Y_actual3)
print(Y_predict3)
err3=(Y_actual3-Y_predict3)**2
err3_mean=np.mean(err3)
err3_sqrt=np.sqrt(err3_mean)
print('MODEL_3',err3_sqrt)