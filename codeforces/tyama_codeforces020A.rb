a=gets.chomp
while a!=(b=a.gsub("//","/")) do a=b end
puts a[0,a.size-(a.size>1&&a[a.size-1,1]=="/"?1:0)]