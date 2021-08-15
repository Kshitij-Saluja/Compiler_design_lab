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
Grammar :-
A -> TE
E -> +TE | epsi
T -> FS
K -> *FK | epsi
F -> (E) | alpha
*/

int main() {
map <string,int> m;
string arr[15][15];
stack <string> st;
m["A"]=1;
m["E"]=2;
m["T"]=3;
m["K"]=4;
m["F"]=5;
m["alpha"]=6;
m["+"]=7;
m["*"]=8;
m["("]=9;
m[")"]=10;
m["$"]=11;
for(int i=0;i<15;i++){

for(int j=0;j<15;j++){
arr[i][j]="-1";
}
}
arr[m["A"]][m["alpha"]]="TE";
arr[m["A"]][m["("]]="TE";
arr[m["E"]][m["+"]]="+TE";
arr[m["E"]][m[")"]]="epsi";
arr[m["E"]][m["$"]]="epsi";
arr[m["T"]][m["alpha"]]="FK";
arr[m["T"]][m["("]]="FK";
arr[m["K"]][m["+"]]="epsi";
arr[m["K"]][m["*"]]="*FK";
arr[m["K"]][m[")"]]="epsi";
arr[m["K"]][m["$"]]="epsi";
arr[m["F"]][m["alpha"]]="alpha";
arr[m["F"]][m["("]]="(E)";
for(int i=0;i<=11;i++){

for(int j=0;j<=11;j++){
// cout<<arr[i][j]<<" ";
}
//cout<<"\n";
}
st.push("$");
st.push("A");
string s;
cin>>s;
s=s+"$";
int n=s.size();
int inde=0;
while(st.top()!="$"){
if(inde==n)
{
cout<<"NO\n";
break;
}
string y="";
if(int(s[inde])>=97 && int(s[inde])<=122){
y="alpha";

}
else{
y.push_back(s[inde]);
}
if(st.top()==y){
inde++;
st.pop();
continue;
}
string an=arr[m[st.top()]][m[y]];
st.pop();
if(an!="-1"){
for(int j=an.size()-1;j>=0;j--)
{
if(an=="epsi")
break;
if(an=="alpha"){
st.push(an);
break;
}
string h="";
h.push_back(an[j]);
st.push(h);
}
}

}
if(inde==(n-1)){
cout<<"YES\n";
}
else{
cout<<"NO\n";
}
}