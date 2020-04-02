# -*- coding: utf-8 -*-
"""
Created on Thu Jan 11 15:59:56 2018

@author: GFS36
"""

# -*- coding: utf-8 -*-
"""
Created on Fri Dec 29 19:53:14 2017

@author: titas
"""

import os
import numpy as np
import pandas as pd
from sklearn import linear_model

os.chdir("d:/Data_Files")
advt=pd.read_csv("advertising.csv")
y=advt["sales"]
predictors=advt[['TV','radio','newspaper']]
linmod=linear_model.LinearRegression()
X=pd.DataFrame()
for col in predictors:
    X[col]=predictors[col]
    linmod.fit(X,y)
    print("intercept : {:5f}".format(linmod.intercept_))
    for c,coef in zip(X.columns.values,linmod.coef_):
        print("{} : {:5f}".format(c,coef))
    print("score : {:.7f}".format(linmod.score(X,y)))
    print("\n")

