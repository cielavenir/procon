#!/usr/bin/ruby

def snake2camel(orig)
    r=''.dup
    i=0
    while i<orig.size
        if orig[i]=='_'
            return orig if i+1==orig.size || orig[i+1]=='_' || ('0'<=orig[i+1]&&orig[i+1]<='9')
            r<<orig[i+1].upcase
            i+=1
        else
            r<<orig[i]
        end
        i+=1
    end
    return r
end

def camel2snake(orig)
    r=''.dup
    orig.chars{|c|
        if 'A'<=c&&c<='Z'
            r<<'_'
            r<<c.downcase
        else
            r<<c
        end
    }
    return r
end

def convert(orig)
    s=orig
    start_underscore=0
    end_underscore=0
    while s.size>0 && s[0]=='_'
        start_underscore+=1
        s=s[1..-1]
    end
    return orig if s.empty?
    return orig if ('A'<=s[0]&&s[0]<='Z') || ('0'<=s[0]&&s[0]<='9')
    while s[-1]=='_'
        end_underscore+=1
        s=s[0...-1]
    end
    if s.index('_')
        return orig if s.chars.any?{|c|'A'<=c&&c<='Z'}
        return '_'*start_underscore+snake2camel(s)+'_'*end_underscore
    else
        return '_'*start_underscore+camel2snake(s)+'_'*end_underscore
    end
end

$<.each{|e|puts convert e.chomp}
