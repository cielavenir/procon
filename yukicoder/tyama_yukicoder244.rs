fn getint() -> i32{
    let mut __str=String::new();
    std::io::stdin().read_line(&mut __str);
    let l=__str.len();
    __str.truncate(l-1);
    return i32::from_str_radix(&__str,10).unwrap();
}

fn main(){
    let n=getint();
    println!("{}",n-1);
}