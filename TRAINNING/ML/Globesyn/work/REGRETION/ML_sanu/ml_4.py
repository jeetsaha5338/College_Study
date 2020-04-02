import numpy as np
import statsmodels.formula.api as smf
import pandas as pd 
import matplotlib.pyplot as plt
import numpy as np
data = pd.read_csv('D://AOT//Programings//Machine_Learning_Training//Advertising.csv',index_col=0)

#data_train=data.iloc[:150]
#print(data_train)
#print(data_train.shape)
#data_test=data.iloc[150:]
#print(data_test)
#print(data_test.shape)
# set a seed for reproducibility
np.random.seed(12345)

# create a Series of booleans in which roughly half are True
nums = np.random.rand(len(data))
mask_large = nums > 0.5

# initially set Size to small, then change roughly half to be large
data['Size'] = 'small'
data.loc[mask_large, 'Size'] = 'large'
data.loc[180:, 'Size'] = 'medium'
# create a new Series called IsLarge
data['IsLarge'] = data.Size.map({'small':0, 'large':1,'medium':0})
data['IsSmall'] = data.Size.map({'small':1, 'large':0,'medium':0})
data['IsMedium'] = data.Size.map({'small':0, 'large':0,'medium':1})
print(data)
print(data.head())
