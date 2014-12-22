a=[[1]]
1.step(1000){|i|
    a<<[1]+a.last.each_cons(2).map{|x,y|x+y}+[1]
}
gets.to_i.times{
    n,k=gets.split.map(&:to_i)
    p a[n].count{|e|e%k==0}
}