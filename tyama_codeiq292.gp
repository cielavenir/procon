\\ gp --quiet
a=primes(100)
r=Str(a[1])
for(i=2,length(a),r=Str(r"\n"a[i]))
print(r)
quit