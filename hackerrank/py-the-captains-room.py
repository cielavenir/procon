#!/usr/bin/python
from collections import Counter
import sys
if sys.version_info[0]>=3: raw_input=input
raw_input()
print(Counter(map(int,raw_input().split())).most_common()[-1][0])