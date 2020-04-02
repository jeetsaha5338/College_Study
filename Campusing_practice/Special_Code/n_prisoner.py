import numpy as np
n=100

l=[]
l1=[]
for i in range(n):
    l.append(i+1)
l.reverse()
while True:
    m=np.size(l)
    if m==1:
        break
    m1=int(m/2)
    for i in range(m1):
        l1.append(l.pop())
        l.pop()
    if m%2!=0:
        l1.insert(0,l.pop())
    l=l1.copy()
    l1.clear()
    l.reverse()
print(l)

