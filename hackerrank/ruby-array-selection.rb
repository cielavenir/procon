def select_arr(arr) arr.select(&:odd?) end

def reject_arr(arr) arr.reject{|e|e%3==0} end

def delete_arr(arr) arr.reject{|e|e<0} end

def keep_arr(arr) arr.select{|e|e>=0} end