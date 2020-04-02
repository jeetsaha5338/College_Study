import numpy as np
a = np.array([2,3,4],dtype='float64')
print(a)
print(a.dtype)
b = np.array([(2,3,4),(5,6,7),(8,9,10),(11,12,13)])#2D array
print(b)
print(b.dtype)
c = np.array([[(2,3),(5,6),(8,9)],[(11,12),(1,1),(2,2)]])#3D array
print(c)
print(c.dtype)#to dispaly the datatype
print(c.shape)#to display the shape of matrix
print(c.ndim)#to show dimension of array
print(c[0][2][1])
d=np.arange(5,12,2)#to generate no. btw a range
print(d)
e=d.reshape(2,2)
print(e)
f=b.reshape(2,6)#to reshape the matrix i.e. convert 1D matrix to 2D
print(f)
g=np.arange(100000).reshape(100,100,10)
print(g)
h=np.zeros((3,3))#create zero matrix
print(h)
i=np.ones((3,3),dtype=np.int16)#create one's matrix
print(i)

