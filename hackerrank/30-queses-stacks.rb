#!/usr/bin/ruby

class Solution<Array
	alias :pushCharacter :push
	def enqueueCharacter(x) end #lol
	alias :popCharacter :pop
	alias :dequeueCharacter :shift
end

# read the string s
s=gets
#Create the Solution class object
obj=Solution.new()   
l=s.length
# push/enqueue all the characters of string s to stack
for i in 0...l
	obj.pushCharacter(s[i])
	obj.enqueueCharacter(s[i])
end

isPalindrome=true
'''
pop the top character from stack
dequeue the first character from queue
compare both the characters
''' 
for i in 0...(l / 2)   
	if obj.popCharacter()!=obj.dequeueCharacter()   
		
		isPalindrome=false
		break
	end
end
#finally print whether string s is palindrome or not.
if isPalindrome
	puts("The word, "+s+", is a palindrome.")
else
	puts("The word, "+s+", is not a palindrome.")	
end 