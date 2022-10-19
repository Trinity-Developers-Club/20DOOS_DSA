import matplotlib.pyplot as plt
import numpy

x=[]
y=[]
x1=[]
y1=[]
x2=[]
y2=[]

precision=0.001
maxIteration=100
t=maxIteration//10

for i in numpy.arange(-2,2+precision, precision):
    for j in numpy.arange(-2,2+precision, precision):
        n=0
        a=i
        a1=i
        b=j
        b1=j
        while(n < maxIteration):
            aa=(a*a)-(b*b)
            bb=2*a*b
            a=aa+a1
            b=bb+b1
            #if ((a*a)+(b*b))>4:
            if (a+b)>2:
                break
            n+=1
        
        if n==maxIteration:
            x.append(a1)
            y.append(b1)
        elif (n<maxIteration and n>=t):
            x1.append(a1)
            y1.append(b1)
        elif (n<t and n>=0):
            x2.append(a1)
            y2.append(b1)

        

plt.title("Mandelbrot Set")
plt.scatter(x, y, label = "stars", color = "blue", marker = "*", s = 1)
plt.scatter(x1, y1, label = "stars", color = "red", marker = "*", s = 1)
plt.scatter(x2, y2, label = "stars", color = "black", marker = "*", s = 1)
plt.show()
