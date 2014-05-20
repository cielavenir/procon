#!/usr/bin/python
import sys
if sys.version_info[0]>=3: raw_input=input

#2007 Domestic A
def judge(n):
  ma=0
  mi=1000
  s=0
  for i in range(0,n):
    x=int(raw_input())
    if x<mi:
      mi=x
    if x>ma:
      ma=x
    s+=x
  print((s-ma-mi)//(n-2))

while 1:
  n=int(raw_input())
  if n==0:
    break
  judge(n)