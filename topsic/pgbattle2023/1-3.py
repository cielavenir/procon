#!/usr/bin/env python
import sys
from operator import eq,gt,lt
hasattr(sys,'set_int_max_str_digits') and sys.set_int_max_str_digits(99999)
a=int(sys.stdin.readline())
b=int(sys.stdin.readline(), 2)
print(next(op for op,fn in [('=',eq),('>',gt),('<',lt)] if fn(a,b)))

'''
set_int_max_str_digits

https://twitter.com/yukicoder/status/1647620917143699461
https://zenn.dev/ykesamaru/articles/2175b317a5410e
'''
