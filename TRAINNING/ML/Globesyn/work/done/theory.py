# -*- coding: utf-8 -*-
"""
Created on Mon Jan  8 13:58:59 2018

@author: GFS39
"""

import numpy as np
records=10000
np.random.seed(42)#discuss later
X=2*np.random.rand(records,1)
y=4+3*X+np.random.randn(records,1)
#X.shape
Xt = X.T
lr=0.001
weights=np.random.randn(2,1)
#weights.shape
X_b=np.c_[np.ones((records,1)),X]
#X_b.shape
for i in range(10000):
    pderivatives=(2/records)*X_b.T.dot(X_b.dot(weights)-y)
    weights= weights-(lr*pderivatives)
print(weights)


