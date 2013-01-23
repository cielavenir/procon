N=40
a=[1,1]
2.step(N+2){|i|a<<a[i-1]+a[i-2]}
puts "#{a[N+1]}x#{a[N+2]}"