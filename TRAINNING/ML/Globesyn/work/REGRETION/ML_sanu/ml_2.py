#REGRESSION
import statsmodels.formula.api as smf
import pandas as pd 
import matplotlib.pyplot as plt
import numpy as np
data = pd.read_csv('D://AOT//Programings//Machine_Learning_Training//Advertising.csv',index_col=0)
print(data)
print(data.shape)
data_train=data.iloc[:150]
print(data_train)
print(data_train.shape)
data_test=data.iloc[150:]
print(data_test)
print(data_test.shape)
lm1=smf.ols(formula='sales~TV',data=data_train).fit()
print(lm1.params)
X_new_TV=data_test['TV']
print(X_new_TV.head())
Y_perdicted_TV=lm1.predict(X_new_TV)
Y_actual=np.array(data_test['sales'])
Y_predict=np.array(Y_perdicted_TV)
#print(Y_actual)
#print(Y_predict)
err1=(Y_actual-Y_predict)**2
err1_mean=np.mean(err1)
err1_sqrt=np.sqrt(err1_mean)
print(err1_sqrt)
data.plot(kind='scatter',x='TV',y='sales')
plt.plot(X_new_TV,Y_perdicted_TV,c='red',linewidth=0.5)

lm2=smf.ols(formula='sales~TV+radio',data=data_train).fit()
print(lm2.params)
X_new=data_test[['TV','radio']]
print(X_new.head())
Y_perdicted=lm2.predict(X_new)
Y_actual1=np.array(data_test['sales'])
Y_predict1=np.array(Y_perdicted)
print(Y_actual1)
print(Y_predict1)
err2=(Y_actual1-Y_predict1)**2
err2_mean=np.mean(err2)
err1_sqrt=np.sqrt(err2_mean)
print(err1_sqrt)