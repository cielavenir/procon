#!/usr/bin/python
from math import factorial as f;n=input();print f(31)/f(n)/f(31-n)if 0<=n<32 else 0,f(30)/f(n-1)/f(31-n)*(2**31-1)if 0<n<32 else 0
#from scipy.misc import comb;n=input();print int(comb(31,n)),int(comb(30,n-1))*(2**31-1)