#!/usr/bin/python
import sys,ctypes
if sys.platform.startswith('linux'):
	libm=ctypes.cdll.LoadLibrary('libm.so.6')
	libc=ctypes.cdll.LoadLibrary('libc.so.6')
elif sys.platform=='darwin':
	libm=ctypes.cdll.LoadLibrary('libSystem.dylib')
	libc=libm
elif sys.platform=='win32':
	libm=ctypes.cdll.LoadLibrary('msvcr120.dll')
	libc=libm
else:
	raise ImportError

libm.sqrtl.restype=ctypes.c_longdouble
n=ctypes.c_longdouble()
z=int(sys.stdin.readline())*8+1
libc.sscanf(str(z),'%Lf',ctypes.byref(n))
n=libm.sqrtl(n)
q=int(n)
print('NO' if q*q!=z else 'YES\n%d'%(q/2))
