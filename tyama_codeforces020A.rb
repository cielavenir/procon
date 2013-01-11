a=gets.chomp
while a!=(b=a.gsub("//","/")) do a=b end
puts a[0,a.length-(a.length>1&&a[a.length-1,1]=="/"?1:0)]