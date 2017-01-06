#!/usr/bin/python
import sys
print(1+sum(c.isupper() for c in sys.stdin.readline()))
