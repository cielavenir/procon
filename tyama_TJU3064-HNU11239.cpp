#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

int fromb(string &s){
  int i=0,r=0;
  for(;i<s.length();i++)r*=-2,r+=s[i]-'0';
  return r;
}

/*string fromd(int d){
  if(!d)return "0";
  
  string s="";
  for(;d;d/=-2){printf("---%d\n",d);s+=(d&1)?"1":s!=""?"0":"";}
  reverse(s.begin(),s.end());
  return s==""?"0":s;
}*/

string convert(int convertMe) {
   // http://everything2.com/index.pl?node_id=981370
   int digitPos = 33;
   bool carry = false, evenDigit = true;
   bool currentDigit;
   char convertedDigits[33];

   // Null-termine returned string
   convertedDigits[--digitPos] = '\0';
   do {
     // Get current base 2 digit
     currentDigit = convertMe % 2;
     // Add a '0' or a '1' at the front of the existing string
     convertedDigits[--digitPos] = '0' + (currentDigit ^ carry);
     if (evenDigit)
        carry &= currentDigit;
     else
        carry |= currentDigit;
     // Move to the next base 2 digit 
     convertMe >>= 1;
     evenDigit = !evenDigit;
   // Continue till all base 2 digits have been converted
   // and all carries written
   } while (convertMe || carry);

   return string(convertedDigits + digitPos);

}

string fromd(int d){
  string s=convert(d+1073741824);
  do s.erase(s.begin());while(s[0]=='0'); //really weird
  return s==""?"0":s;
}

int main(){
  int n,d;char c;string s;
  for(cin>>n;n;n--){
    cin>>c;
    if(c=='b')cin>>s,cout<<"From binary: "<<s<<" is "<<fromb(s)<<endl;
    else cin>>d,cout<<"From decimal: "<<d<<" is "<<fromd(d)<<endl;
  }
  return 0;
}