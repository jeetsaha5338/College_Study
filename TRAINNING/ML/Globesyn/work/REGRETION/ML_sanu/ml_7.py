import os
import statsmodels.formula.api as smf
import pandas as pd 
import matplotlib.pyplot as plt
import numpy as np
os.chdir("H:\Data_Files")
data = pd.read_csv('mtcars.csv')
print(data)

data['cyl_4'] = data.cyl.map({4:1,6:0,8:0})
data['cyl_6'] = data.cyl.map({4:0,6:1,8:0})
data['cyl_8'] = data.cyl.map({4:0,6:0,8:1})

data['gear_3'] = data.gear.map({3:1,4:0,5:0})
data['gear_4'] = data.gear.map({3:0,4:1,5:0})
data['gear_5'] = data.gear.map({3:0,4:0,5:1})

data['carb_1'] = data.carb.map({1:1,2:0,3:0,4:0,6:0,8:0})
data['carb_2'] = data.carb.map({1:0,2:1,3:0,4:0,6:0,8:0})
data['carb_3'] = data.carb.map({1:0,2:0,3:1,4:0,6:0,8:0})
data['carb_4'] = data.carb.map({1:0,2:0,3:0,4:1,6:0,8:0})
data['carb_6'] = data.carb.map({1:0,2:0,3:0,4:0,6:1,8:0})
data['carb_8'] = data.carb.map({1:0,2:0,3:0,4:0,6:0,8:1})

print('TRAINING DATA')
data_train=data.iloc[:20]
print(data_train)
print(data_train.shape)

print('TESTING DATA')
data_test=data.iloc[20:]
print(data_test)
print(data_test.shape)

co_rel=np.corrcoef(data_train[['disp','hp','drat','wt','qsec','vs','am','cyl_4','cyl_6','cyl_8','gear_3','gear_4','gear_5','carb_1','carb_2','carb_3','carb_4']])
co_rel1=pd.DataFrame(co_rel)
print(co_rel1)
data_test=data.iloc[20:]
print(data_test)
print(data_test.shape)

print('MODEL_1')
lm1=smf.ols(formula='mpg~disp+hp+drat+wt+qsec+vs+am+cyl_4+cyl_6+cyl_8+gear_3+gear_4+gear_5+carb_1+carb_2+carb_3+carb_4+carb_6+carb_8 ',data=data_train).fit()
print(lm1.params)
print(lm1.summary())

X_new1=data_test[['disp','hp','drat','wt','qsec','vs','am','cyl_4','cyl_6','cyl_8','gear_3','gear_4','gear_5','carb_1','carb_2','carb_3','carb_4','carb_6','carb_8']]
print(X_new1.head())

Y_perdicted1=lm1.predict(X_new1)
Y_actual1=np.array(data_test['mpg'])
Y_predict1=np.array(Y_perdicted1)

print("++++++++++++++++++++++++++++++++++++++++++++++++")
print(Y_perdicted1.dtype)
print("++++++++++++++++++++++++++++++++++++++++++++++++")
print(Y_actual1.dtype)
print("++++++++++++++++++++++++++++++++++++++++++++++++")
print(Y_predict1.dtype)
print("++++++++++++++++++++++++++++++++++++++++++++++++")
print(Y_perdicted1)#column
print(Y_actual1)#array
print(Y_predict1)#array
err1=(Y_actual1-Y_predict1)**2
err1_mean=np.mean(err1)
err1_sqrt=np.sqrt(err1_mean)
print('ERROR IN MODEL_1:',err1_sqrt)

print('MODEL_2')
lm2=smf.ols(formula='mpg~disp+drat+wt+qsec+vs+am+cyl_4+cyl_6+cyl_8+gear_3+gear_4+gear_5+carb_1+carb_2+carb_3+carb_4+carb_6+carb_8 ',data=data_train).fit()
print(lm2.params)

X_new2=data_test[['disp','drat','wt','qsec','vs','am','cyl_4','cyl_6','cyl_8','gear_3','gear_4','gear_5','carb_1','carb_2','carb_3','carb_4','carb_6','carb_8']]
print(X_new2.head())
Y_perdicted2=lm2.predict(X_new2)
Y_actual2=np.array(data_test['mpg'])
Y_predict2=np.array(Y_perdicted2)
print(Y_actual2)
print(Y_predict2)
err2=(Y_actual2-Y_predict2)**2
err2_mean=np.mean(err2)
err2_sqrt=np.sqrt(err2_mean)
print('ERROR IN MODEL_2:',err2_sqrt)
