# -*- coding: utf-8 -*-
"""
Created on Thu Dec 28 13:51:53 2017

@author: Sanmitra Kumar
"""

x=[2010,2011,2012,2013,2014]
y=[70,75,82,85,90]
import matplotlib.pyplot as plt
#%matplotlib inline
#x=range(0,100,1)
#y=[x+1 for x in range(0,100,1)]#this is known as list argument
plt.plot(x,y)

#z=[x+200 for x in range(0,100,1)]
#plt.plot(x,z)
plt.show()
