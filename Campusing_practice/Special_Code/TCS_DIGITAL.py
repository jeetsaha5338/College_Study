import numpy as np

'''inp=[]

for i in range(6):
    inp.append(int(input()))
print(inp)'''

inp=[1, 0, 4, 9, 9, 9]

l=inp.copy()

#search for max month

lm=l

if 1 in lm:
    lm.remove(1)
    m1=1
    if 2 in lm:
        lm.remove(2)
        m2=2
    else:
        if 1 in lm:
            lm.remove(1)
            m2=1
        else:
            if 0 in lm:
                lm.remove(0)
                m2=0
            else:
                lm=l.copy()
else:
    if 0 in lm:
        lm.remove(0)
        m1=0
        m2=np.max(lm)
        lm.remove(m2)
    else:
        d1=0
        d2=100

l=lm.copy()


m=10*m1+m2

a=[1,3,5,7,8,10,12]
b=[4,6,9,11]

#search for max data
f=1
if m in a:
    if 3 in lm:
        f=0
        lm.remove(3)
        d1=3
        if 1 in lm:
            lm.remove(1)
            d2=1
        else:
            if 0 in lm:
                lm.remove(0)
                d2=0
            else:
                lm=l.copy()
                f=1
    if f==1 and 2 in lm:
        lm.remove(2)
        d1=2
        d2=np.max(lm)
        lm.remove(d2)
    else:
        if f==1 and 1 in lm:
            lm.remove(1)
            d1=1
            d2=np.max(lm)
            lm.remove(d2)
        else:
            if f==1 and 0 in lm:
                lm.remove(0)
                d1=0
                d2=np.max(lm)
                lm.remove(d2)
            else:
                if f==1:
                    d2=100
f=1
if m in b:
    if 3 in lm:
        f=0
        lm.remove(3)
        d1=3
        if 0 in lm:
            lm.remove(0)
            d2=0
        else:
            lm=l.copy()
            f=1
    if f==1 and 2 in lm:
        lm.remove(2)
        d1=2
        d2=np.max(lm)
        lm.remove(d2)
    else:
        if f==1 and 1 in lm:
            lm.remove(1)
            d1=1
            d2=np.max(lm)
            lm.remove(d2)
        else:
            if f==1 and 0 in lm:
                lm.remove(0)
                d1=0
                d2=np.max(lm)
                lm.remove(d2)
            else:
                if f==1:
                    d2=100

if m == 2:
    if 2 in lm:
        lm.remove(2)
        d1=2
        if np.max(lm)==9:
            lm.remove(9)
        d2=np.max(lm)
        lm.remove(d2)
    else:
        if 1 in lm:
            lm.remove(1)
            d1=1
            d2=np.max(lm)
            lm.remove(d2)
        else:
            if 0 in lm:
                lm.remove(0)
                d1=0
                d2=np.max(lm)
                lm.remove(d2)
            else:
                d2=100
         
d=d1*10+d2
print(inp)
if d>50 and m!=10:  
    print("Error")

if d>50 and m==10:
    l=lm=inp.copy()
    m1=0
    lm.remove(0)
    m2=np.max(lm)
    lm.remove(m2)
    m=m1*10+m2
    f=1
    if m in a:
        if 3 in lm:
            f=0
            lm.remove(3)
            d1=3
            if 1 in lm:
                lm.remove(1)
                d2=1
            else:
                if 0 in lm:
                    lm.remove(0)
                    d2=0
                else:
                    lm=l.copy()
                    f=1
        if f==1 and 2 in lm:
            lm.remove(2)
            d1=2
            d2=np.max(lm)
            lm.remove(d2)
        else:
            if f==1 and 1 in lm:
                lm.remove(1)
                d1=1
                d2=np.max(lm)
                lm.remove(d2)
            else:
                if f==1 and 0 in lm:
                    lm.remove(0)
                    d1=0
                    d2=np.max(lm)
                    lm.remove(d2)
                else:
                    if f==1:
                        d2=100
    f=1
    if m in b:
        if 3 in lm:
            f=0
            lm.remove(3)
            d1=3
            if 0 in lm:
                lm.remove(0)
                d2=0
            else:
                lm=l.copy()
                f=1
        if f==1 and 2 in lm:
            lm.remove(2)
            d1=2
            d2=np.max(lm)
            lm.remove(d2)
        else:
            if f==1 and 1 in lm:
                lm.remove(1)
                d1=1
                d2=np.max(lm)
                lm.remove(d2)
            else:
                if f==1 and 0 in lm:
                    lm.remove(0)
                    d1=0
                    d2=np.max(lm)
                    lm.remove(d2)
                else:
                    if f==1:
                        d2=100

    if m == 2:
        if 2 in lm:
            lm.remove(2)
            d1=2
            if np.max(lm)==9:
                lm.remove(9)
                d2=np.max(lm)
                lm.remove(d2)
            else:
                if 1 in lm:
                    lm.remove(1)
                    d1=1
                    d2=np.max(lm)
                    lm.remove(d2)
                else:
                    if 0 in lm:
                        lm.remove(0)
                        d1=0
                        d2=np.max(lm)
                        lm.remove(d2)
                    else:
                        d2=100
    d=d1*10+d2
    if d>50:
        print("Error")
    else:
        print(d,"/",m)
        print(lm)
            
      
else:
    print(d,"/",m)
    print(lm)
    