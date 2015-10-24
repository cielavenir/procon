def strike(s) '<strike>'+s+'</strike>' end
def mask_article(s,a) a.each{|e|s.gsub!(e,&method(:strike))};s end