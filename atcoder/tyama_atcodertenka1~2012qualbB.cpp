#include <algorithm>
#include <iostream>
#define between(a,x,b) ((a)<=(x)&&(x)<=(b))
using namespace std;

string snake2camel(const string &orig){ //underscore
    string r;
    for(int i=0;i<orig.size();i++){
        if(orig[i]=='_'){
            if(orig[i+1]==0||orig[i+1]=='_'||between('0',orig[i+1],'9'))return orig;
            r+=orig[i+1]-0x20;
            i++;
        }else{
            r+=orig[i];
        }
    }
    return r;
}

string camel2snake(const string &orig){
    string r;
    for(int i=0;i<orig.size();i++){
        if(between('A',orig[i],'Z')){
		        r+='_',r+=orig[i]+0x20;
        }else{
            r+=orig[i];
      }
    }
    return r;
}

string convert(const string &orig){
    string s=orig;
    int start_underscore=0;
    int end_underscore=0;
    for(;s[0]=='_';s.erase(0,1))start_underscore++;
    if(s.empty())return orig;
    if(between('A',s[0],'Z')||between('0',s[0],'9'))return orig;
    for(;s[s.length()-1]=='_';s.erase(s.length()-1,1))end_underscore++;
    if(find(s.begin(),s.end(),'_')!=s.end()){
        for(int i=0;i<s.length();i++)
            if(between('A',s[i],'Z'))return orig;
        return string(start_underscore,'_')+snake2camel(s)+string(end_underscore,'_');
    }else{
        return string(start_underscore,'_')+camel2snake(s)+string(end_underscore,'_');
    }
}

int main(){
    string s;
    cin>>s;
    cout<<convert(s)<<endl;
}