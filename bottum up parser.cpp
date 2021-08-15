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
/*
1. E->E+T
2. E->T
3. T->T*F
4. T->F
5. F->(E)
6. F->id
*/
using namespace std;
int main(int argc, char *argv[]) {
map <int,int> m;
map <int,char> m2;
m[1]=6;

m[2]=2;
m[3]=6;
m[4]=2;
m[5]=6;
m[6]=2;
m2[1]='E';
m2[2]='E';
m2[3]='T';
m2[4]='T';
m2[5]='F';
m2[6]='F';
string table[12][9]= {
{"s5", " ", " ", "s4", " "," ", "1", "2", "3"},
{" ", "s6", " ", " ", " ", "Acc", " ", " ", " "},
{" ", "r2", "s7", " ", "r2", "r2", " ", " ", " "},
{"", "r4", "r4", " ", "r4", "r4", " ", " ", " "},
{"s5", " "," ", "s4", " "," ", "8", "2", "3"},
{" ", "r6", "r6", " ", "r6", "r6", " ", " ", " "},
{"s5", " "," ", "s4", " "," ", " ", "9", "3"},
{"s5", " "," ", "s4", " "," ", " ", " ", "q"},
{" ", "s6", " ", " ", "s11"," ", " ", " ", " "},
{" ", "r1", "s7", " ", "r1", "r1", " ", " ", " "},
{" ", "r3", "r3", " ", "r3", "r3", " ", " ", " "},
{" ", "r5", "r5", " ", "r5", "r5", " ", " ", " "}
};
stack <char> st;
st.push('0');
string s;
cin>>s;
s=s+"$";
int ind=0;
while(st.size()!=0){
cout<<st.top()<<"\n";
int a,b;
a=int(st.top())-48;
if(st.top()=='q')
a=10;
else if(int(s[ind])>=97 && int(s[ind])<=122)
s[ind]='a';
switch(s[ind]){
case 'a':
b=0;
break;
case '+':
b=1;
break;
case '*':
b=2;
break;
case '(':
b=3;
break;
case ')':
b=4;

break;
case '$':
b=5;
break;
case 'E':
b=6;
break;
case 'T':
b=7;
break;
case 'F':
b=8;
break;

}
string an=table[a][b];
// cout<<a<<" "<<b<<"\n";
//cout<<an;
if(an[0]=='s'){
st.push(s[ind]);
st.push(an[1]);
ind++;
}
else if(an[0]=='r'){
int x=int(an[1])-48;
int y=m[x];
while(y!=0 && st.size()!=0){
st.pop();
y--;
}
if(y!=0){
cout<<"Error";
return 0;
}
char jj=st.top();
st.push(m2[x]);
a=int(jj)-48;
switch(m2[x]){
case 'a':
b=0;
break;
case '+':
b=1;
break;
case '*':
b=2;
break;
case '(':
b=3;
break;
case ')':
b=4;
break;
case '$':

b=5;
break;
case 'E':
b=6;
break;
case 'T':
b=7;
break;
case 'F':
b=8;
break;

}
st.push(table[a][b][0]); }
else if(an[0]=='A'){
cout<<"YES";
return 0;
}
else{
cout<<"Error";
return 0;
}
}

}