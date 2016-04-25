#!/usr/bin/ruby
class Person
	def initialize(firstName, lastName, id)
		@firstName = firstName
		@lastName = lastName
		@id = id
	end
	def printPerson
		print("Name: ",@lastName , ", " + @firstName ,"\nID: " , @id)
	end
end

class Student <Person
	def initialize(firstName,lastName,id,scores)
		@score=scores.map(&:to_i).reduce(:+)/scores.size
		super(firstName,lastName,id)
	end
	def calculate
		@score>=90 ? 'O' : @score>=80 ? 'E' : @score>=70 ? 'A' : @score>=55 ? 'P' : @score>=40 ? 'D' : 'T'
	end
end

input = gets.split()
firstName = input[0]
lastName = input[1]
id = input[2].to_i
numScores = gets.to_i
scores = gets.split()
scores.each do |v|
	score = Integer(v)
end
s = Student.new(firstName, lastName, id, scores) # lol
s.printPerson		   
print("\nGrade: " + s.calculate)