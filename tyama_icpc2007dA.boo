#!/usr/bin/booi
import System

while 1:
  n=int.Parse(Console.ReadLine())
  if n==0:
    break
  ma=0
  mi=1000
  s=0
  for i in range(0,n):
    x=int.Parse(Console.ReadLine())
    if x<mi:
      mi=x
    if x>ma:
      ma=x
    s+=x
  print ((s-ma-mi)/(n-2))