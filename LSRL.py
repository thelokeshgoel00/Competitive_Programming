import matplotlib.pyplot as plt
import numpy as np
from sklearn import datasets, linear_model

diabetes = datasets.load_diabetes()
diabetesX = diabetes.data[:, np.newaxis, 2]
diabetesXTrain = diabetesX[:-20]
diabetesXTest = diabetesX[-20:]
diabetesYTrain = diabetes.target[:-20]
diabetesYTest = diabetes.target[-20:]

regr = linear_model.LinearRegression()
regr.fit(diabetesXTrain, diabetesYTrain)

print('Coefficients: \n', regr.coef_, regr.intercept_)
print("Mean squared error: %.2f" % np.mean((regr.predict(diabetesXTest)-diabetesYTest)**2))
print('Variance score: %.2f' % regr.score(diabetesXTest, diabetesYTest))

plt.scatter(diabetesXTest, diabetesYTest,  color='black')
plt.plot(diabetesXTest, regr.predict(diabetesXTest), color='blue', linewidth=3)

plt.xticks(())
plt.yticks(())

plt.show()

