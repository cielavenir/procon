#!/usr/bin/python
import sys
if sys.version_info[0]>=3: raw_input=input
for _ in range(int(raw_input())):
	raw_input()
	a=[(int(e),i) for i,e in enumerate(raw_input().split())]
	mi_idx=min(a)[1]
	print('Yes' if all(sorted(e)==e for e in ([e[0] for e in reversed(a[:mi_idx])],a[mi_idx:])) else 'No')