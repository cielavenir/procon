def identify_class(obj)
	case obj
	when Hacker then puts "It's a Hacker!"
	when Submission then puts "It's a Submission!"
	when TestCase then puts "It's a TestCase!"
	when Contest then puts "It's a Contest!"
	else puts "It's an unknown model"
	end
end