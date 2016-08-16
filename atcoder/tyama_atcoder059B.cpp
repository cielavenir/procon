//clang does not crash on this funny pop_back().
#import<string>
#import<cstdio>
int main(){std::string s;for(int c;~(c=getchar());)c=='B'?s.pop_back():s.push_back(c);printf(s.c_str());}