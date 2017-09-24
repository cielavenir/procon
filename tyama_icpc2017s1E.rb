#!/usr/bin/ruby
M=998244353
class Fixnum
	def/o;o.is_a?(Array)?o/self :self*o%M end
	def-o;[self,o]end
end
class Array
	def/o;s=self;o.is_a?(Array)?(s[0]/o[0]+s[1]/o[1])%M : [s[0]/o,s[1]/o]end
end
p eval gets.gsub(/\d+/){$&.to_i%M}.tr'*,','/-'
