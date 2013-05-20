#!/usr/bin/python
import sys

#2007 Domestic A
def judge(n):
  ma=0
  mi=1000
  s=0
  for i in range(0,n):
    x=int(sys.stdin.readline())
    if x<mi:
      mi=x
    if x>ma:
      ma=x
    s+=x
  print((s-ma-mi)//(n-2))

while 1:
  n=int(sys.stdin.readline())
  if n==0:
    break
  judge(n)