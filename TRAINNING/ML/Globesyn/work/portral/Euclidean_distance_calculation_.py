# -*- coding: utf-8 -*-
"""
Created on Sun Jan 14 17:43:51 2018

@author: titas
"""

import os
import pandas as pd
import numpy as np

import matplotlib.pyplot as plt
def eudist(matrix,row):
    dist=[]
    for r in matrix:
        diff=[(a-b)**2 for a,b in zip(r,row)]
        dist.append(np.sqrt(np.sum(diff)))
    return dist
    
os.chdir('D:\Data_Files')
iris=pd.read_csv("iris.csv")
iris=iris[['sl','sw','pl','pw']]
ir=iris.values # converting into numpy array
a_record=[5.9,3.0,5.1,1.8] # a particular flowers sepal length,width,petal lengtj,width
# calculating distance of the above flower from other flowers
distances=eudist(ir,[5.9,3.0,5.1,1.8])
print (distances)



