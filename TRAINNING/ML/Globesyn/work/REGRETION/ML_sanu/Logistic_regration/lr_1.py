import statsmodels.formula.api as smf
import pandas as pd 
import matplotlib.pyplot as plt
import numpy as np

data = pd.read_csv('D:\\AOT\\Programings\\Machine_Learning_Training\\binary.csv')
data.columns = ["admit","gre","gpa","prestige"]
print(data.head())
print(data.describe())
print(data.prestige.unique())
dummy_ranks = pd.get_dummies(data['prestige'],prefix='prestige')
print(dummy_ranks)
print(data.head())

#join dummy_ranks & main data
cols_to_keep=['admit','gre','gpa']
data=data[cols_to_keep].join(dummy_ranks.loc[:,'prestige_2':])
print(data.head())
data['intercept']=1.0
print(data.head())
print('TRAINING DATA')
data_train=data.iloc[:250]
print(data_train)
print(data_train.shape)

print('TESTING DATA')
data_test=data.iloc[251:]
print(data_test)
print(data_test.shape)

print('MODEL_1')
train_cols=data.columns[1:]

logit = smf.Logit(data_train['admit'],data_train[train_cols])
result = logit.fit()
print(result.params)
print(result.summary())
print(result.conf_int())
print(result.pred_table())
data_test['prediction']=result.predict(data_test[train_cols])
data_test['admit_pred']=data_test['prediction']>0.5
print('MODEL_2')
#train_cols=data.columns[]

logit1 = smf.Logit(data_train['admit'],data_train[['gre','prestige_2','prestige_3','prestige_4']])
result1 = logit1.fit()
print(result1.params)
print(result1.summary())
print(result1.conf_int())
print(result1.pred_table())

data_test['prediction1']=result1.predict(data_test[['gre','prestige_2','prestige_3','prestige_4']])
data_test['admit_pred1']=data_test['prediction1']>0.5
print(data_test)

pred=np.array(data_test['admit_pred1'])
table=np.histogram2d(data_test['admit'],pred,bins=2)[0]
print(table)