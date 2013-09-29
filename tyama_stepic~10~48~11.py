#!/usr/bin/python
import sys
if sys.version_info[0]>=3: raw_input=input
print(raw_input()[12:-1:5])