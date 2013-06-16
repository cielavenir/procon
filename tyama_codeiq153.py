#!/usr/bin/python
import numpy as np
import scipy.stats as ss
import matplotlib.pyplot as plt

ss.binom(10,0.3).rvs()
np.random.binomial(10,0.3)

data = ss.binom(10,0.3).rvs(1000)
plt.hist(data,11,(-0.5,10.5))
plt.show()

ss.binom(10,0.3).pmf(6)
sum(ss.binom(10,0.3).pmf(range(6,11)))
1-ss.binom(10,0.3).cdf(5)

ss.binom(10,0.3).rvs(size=[5,3])

data=ss.binom(10,0.3).rvs(size=[500,200])
plt.hist([x.mean() for x in data])
plt.show()