import os
import numpy as np
import pandas as pd
from sklearn import linear_model
from sklearn import model_selection 
import matplotlib.pyplot as plt
os.chdir("d:/Data Files")

records=100
x=np.arange(-10,10,.002)
#print(x)
y=1/(1+np.exp(-x))#logit(logistic regression)
plt.plot(x,y,'b--')
