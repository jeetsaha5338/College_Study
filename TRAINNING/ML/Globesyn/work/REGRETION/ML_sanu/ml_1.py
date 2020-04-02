#insert data into dataframe
import statsmodels.formula.api as smf#library for statistical calculation
#REGRESSION
import pandas as pd 
import matplotlib.pyplot as plt
data = pd.read_csv('D://AOT//Programings//Machine_Learning_Training//Advertising.csv',index_col=0)
print(data)
print(data.shape)#print shape of dataframe
fig,axs=plt.subplots(1,3,sharey=True)
data.plot(kind='scatter',x='TV',y='sales',ax=axs[0],figsize=(16,8))
data.plot(kind='scatter',x='radio',y='sales',ax=axs[1])
data.plot(kind='scatter',x='newspaper',y='sales',ax=axs[2])
lm=smf.ols(formula='sales~TV',data=data).fit()#ols()-ordirany least square helps in linear regression, formula takes the argument btw which dependency is to find
#fit()-create a fitted model in one line
print(lm.params)#print the coefficient 
#y=mx+c ,m=value of TV & c=value of intercept & x=quantity of TV
lm1=smf.ols(formula='sales~radio',data=data).fit()
print(lm1.params)

lm2=smf.ols(formula='sales~newspaper',data=data).fit()
print(lm2.params)

lm3=smf.ols(formula='sales~TV+newspaper+radio',data=data).fit()
print(lm3.params)
print(lm3.summary())

lm4=smf.ols(formula='sales~TV+radio',data=data).fit()
print(lm4.params)
print(lm4.summary())
X_new_TV=pd.DataFrame({'TV':[50,40,30]})
print(X_new_TV.head())
Y_perdicted_TV=lm.predict(X_new_TV)#to find Y value
print(Y_perdicted_TV)
data.plot(kind='scatter',x='TV',y='sales')#plot original data
plt.plot(X_new_TV,Y_perdicted_TV,c='red',linewidth=5)#plot predicted data

X_new_radio=pd.DataFrame({'radio':[50,40,30]})
print(X_new_radio.head())
Y_perdicted_radio=lm1.predict(X_new_radio)
print(Y_perdicted_radio)
data.plot(kind='scatter',x='radio',y='sales')
plt.plot(X_new_radio,Y_perdicted_radio,c='red',linewidth=5)

X_new_newspaper=pd.DataFrame({'newspaper':[50,40,30]})
print(X_new_newspaper.head())
Y_perdicted_newspaper=lm2.predict(X_new_newspaper)
print(Y_perdicted_newspaper)
data.plot(kind='scatter',x='newspaper',y='sales')
plt.plot(X_new_newspaper,Y_perdicted_newspaper,c='red',linewidth=5)