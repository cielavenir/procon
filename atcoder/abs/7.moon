#!/usr/bin/env moon
n = io.read("*n")
arr = [io.read("*n") for i=1,n]
table.sort(arr)
r = 1
r+=1 for i=2,n when arr[i-1]!=arr[i]
print r
