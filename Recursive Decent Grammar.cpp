#include <iostream>
#include<queue>
#include<vector>
#include<unordered_set>
#include<unordered_map>
#include<set>
#include<map>
#include<algorithm>
#include<stack>
#include<math.h>
using namespace std;
/*
Grammar:
E -> T | T+E
T -> int | int*T | (E)
*/
//str=a
string str;
int inde = 0;
int n;
bool T();
bool E();
bool E1();
bool E2();
bool match();
bool T1();
bool T2();
bool T3();
bool match(string tok){
if(tok == "int"){
int c = int(str[inde])-47;
inde++;
if(c >=0 && c <= 9) return true;
return false;
}
else{
char c = tok[0];
return c == str[inde++];
}
}
bool E1(){
return T();

}
bool E2(){
if(T()){
if(match("+")){
if(E()) return true;
}
}
return false;
}
bool E(){
int c = inde;
bool x;
x = E1();
if(x) return true;
inde=c;
x = E2();
if(x) return true;
//inde = c;
inde = c;
return false;
}
bool T1(){
return match("int") ;
}
bool T2(){
if(match("int")){
if(match("*")){
if(T()) return true;
}
}
return false;
}
bool T3(){
if(match("(")){
if(E()){
if(match(")")) return true;
}
}
return false;
}
bool T(){
int copy = inde;
if(T2()) return true;

inde = copy;
if(T1()) return true;
inde = copy;
if(T3()) return true;
inde = copy;
return false;
}
int main(){
str = "1*1";
int n=str.size();
inde = 0;
if(E()) cout<<"YES";
else cout<<"NO";
//cout<<inde;
}