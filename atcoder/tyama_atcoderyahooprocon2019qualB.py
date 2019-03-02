#!/usr/bin/env python3
print('YES'if __import__('collections').Counter(map(int,open(0).read().split())).most_common()[0][1]<3 else'NO')
