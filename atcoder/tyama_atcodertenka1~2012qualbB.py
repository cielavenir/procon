#!/usr/bin/python
from __future__ import print_function
import sys,re

def snake2camel(orig):
    r=[]
    i=0
    while i<len(orig):
        if orig[i]=='_':
            if i+1==len(orig) or orig[i+1]=='_' or '0'<=orig[i+1]<='9': return orig
            r.append(orig[i+1].upper())
            i+=1
        else:
            r.append(orig[i])
        i+=1
    return ''.join(r)

def camel2snake(orig):
    r=[]
    for c in orig:
        if 'A'<=c<='Z':
            r.append('_')
            r.append(c.lower())
        else:
            r.append(c)
    return ''.join(r)

def convert(orig):
    s=orig
    start_underscore=0
    end_underscore=0
    while len(s)>0 and s[0]=='_':
        start_underscore+=1
        s=s[1:]
    if not s: return orig
    if 'A'<=s[0]<='Z' or '0'<=s[0]<='9': return orig
    while s[-1]=='_':
        end_underscore+=1
        s=s[:-1]
    if '_' in s:
        if any('A'<=c<='Z' for c in s): return orig
        return '_'*start_underscore+snake2camel(s)+'_'*end_underscore
    else:
        return '_'*start_underscore+camel2snake(s)+'_'*end_underscore

for line in sys.stdin:
    print(convert(line.rstrip()))
