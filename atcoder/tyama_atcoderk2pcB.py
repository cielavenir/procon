#!/usr/bin/python
from sys import stdin
from itertools import groupby, izip, imap
n = int(stdin.readline())
print('YES' if all(i >= j for i, j in izip(sorted(imap(int, stdin.readline().split()), reverse=True), sorted(imap(lambda s: reduce(0,max,(len(tuple(y)) for x, y in groupby(s) if x == 'X')), izip(*imap(lambda x: x[0].strip(), izip(stdin, xrange(n))))), reverse=True))) else 'NO')

#import sys
#n=int(next(sys.stdin))
#print('YES' if all(i>=j for i,j in zip(reversed(sorted(map(int,next(sys.stdin).split()))),reversed(sorted(map(lambda s:max(map(len,''.join(s).split('-'))), zip(*map(lambda x:x[0].strip(), zip(sys.stdin,range(n))))))))) else 'NO')