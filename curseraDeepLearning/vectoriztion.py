import numpy as np
import time
import openai




a = np.array([1, 2, 3, 4])
print(a)

a = np.random.rand(1000000)
b = np.random.rand(1000000)
tic = time.time()
c = np.dot(a, b)
toc = time.time()
print("c="+str(c))
print("Vectorized version:" + str(1000*(toc-tic)) + "ms")
tic = time.time()
c=0
for i in range(1000000):
    c += a[i] * b[i]
toc = time.time()
print("c="+str(c))
print("For loop: " + str(1000 * (toc - tic)) + "ms")
print("------------------")
a = np.array([[1,1],[1,-1]])
b= np.array([[2],[3]])
c=a+b
print(c)
# Broadcasting example
#
A = np.array([[56.0, 0.0, 4.4, 68.0],[1.2, 104.0, 52.0, 8.0],[1.8, 135.0, 99.0, 0.9]])
z= np.dot(b.t,a) +3.13
print(z)

#Z=np.dot(w.t,X)+b
