# -*- coding: utf-8 -*-
"""
Created on Thu Jul  5 09:32:04 2018

@author: USER
"""
from sklearn import pipeline
import os
import numpy as np
import pandas as pd
  

os.chdir("E:\Data_Files")#for home
data= pd.read_csv("startup_funding.csv")

data.columns.values

data.shape

data.Date.unique().shape
data.StartupName.unique().shape
data.IndustryVertical.unique().shape
data.SubVertical.unique().shape
data.CityLocation.unique().shape
data.InvestorsName.unique().shape
data.InvestmentType.unique().shape
data.AmountInUSD.unique().shape
data.SNo.unique().shape


a=np.ndarray(10,dtype=pipeline.Pipeline)
a
a=a.repeat(3)
type(a[1])
a.shape
a
