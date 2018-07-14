import numpy as np  
import pandas as pd  
import matplotlib.pyplot as plt 
import os
import scipy.optimize as opt 

def sigmoid(z):
    return 1/(1+np.exp(-z))

def cost(theta, X, y):  
    theta = np.matrix(theta)
    X = np.matrix(X)
    y = np.matrix(y)
    first = np.multiply(-y, np.log(sigmoid(X * theta.T)))
    second = np.multiply((1 - y), np.log(1 - sigmoid(X * theta.T)))
    return np.sum(first - second) / (len(X))

def gradient(theta, X, y):  
    theta = np.matrix(theta)
    X = np.matrix(X)
    y = np.matrix(y)

    parameters = int(theta.ravel().shape[1])
    grad = np.zeros(parameters)

    error = sigmoid(X * theta.T) - y

    for i in range(parameters):
        term = np.multiply(error, X[:,i])
        grad[i] = np.sum(term) / len(X)

    return grad


path = os.getcwd() + '/data/ex2data1.txt'  
data = pd.read_csv(path, header=None, names=['Exam 1', 'Exam 2', 'Admitted'])
data.insert(0,'Ones',1)
cols = data.shape[1]  
X = data.iloc[:,0:cols-1]  
y = data.iloc[:,cols-1:cols]
X = np.array(X.values)  
y = np.array(y.values)  
theta = np.zeros(3)
result = opt.fmin_tnc(func=cost, x0=theta, fprime=gradient, args=(X, y))  
print result 