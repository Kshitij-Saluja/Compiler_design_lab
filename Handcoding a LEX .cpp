#include <iostream>
#include<queue>
#include<vector>
#include<unordered_set>
#include<unordered_map>
#include<set>
#include<map>
#include<algorithm>
#include<math.h>
using namespace std;
int main( )
{
FILE *fp ;
char c ;
printf( "Opening the file test.c in read mode\n" ) ;
fp = fopen ( "Keywords.txt", "r" ) ; // opening an existing file
if ( fp == NULL )
{
printf ( "Could not open file Keywords.txt\n" ) ;
return 1;
}
printf( "Reading the file Keywords.txt\n" ) ;
string s="";
map <string,int> m;
while ( 1 )
{
c = fgetc ( fp ) ; // reading the file
if ( c == EOF ){
m[s]++;
break ;
}
if(c=='\n'){
m[s]++;
s="";
continue;
}
s=s+c;
}
for(auto i: m){
cout<<i.first<<" ";
}
printf("Closing the file Keywords.txt\n") ;
fclose ( fp ) ; // Closing the file
printf( "Opening the file test.c in read mode\n" ) ;
map <string,int> m2;
fp = fopen ( "special_symbols.txt", "r" ) ; // opening an existing file
if ( fp == NULL )
{
printf ( "Could not open file special_symbols.txt\n" ) ;
return 1;
}
printf( "Reading the file special_symbols.txt\n" ) ;
s="";
while ( 1 )
{
c = fgetc ( fp ) ; // reading the file
if ( c == EOF ){
m[s]++;
break ;
}
if(c=='\n'){
m2[s]++;
s="";
continue;
}
s=s+c;
}
printf("Closing the file special_symbols.txt\n") ;

fclose ( fp ) ;
vector <string> keywords;
vector <string> identifiers;
vector <string> symbols;
printf( "Opening the file Simple_c_code.txt in read mode\n" ) ;
fp = fopen ( "Simple_c_code.txt", "r" ) ; // opening an existing file
if ( fp == NULL )
{
printf ( "Could not open file Simple_c_code.txt\n" ) ;
return 1;
}
printf( "Reading the file Simple_c_code.txt\n" ) ;
s="";
while ( 1 )
{
cout<<c<<" "<<s<<"\n";
c = fgetc ( fp ) ; // reading the file
if ( c == EOF ){
break ;
}
// cout<<c<<" "<<s<<"\n";
string h;
h=h+c;
if(int(c)==10 || int(c)==32 || c=='\t'){
if(m.find(s)!=m.end()){
keywords.push_back(s);
s="";
}
else {
// cout<<s<<" "<<"r\n";
identifiers.push_back(s);
s="";
}
continue;
}
if(m2.find(h)!=m2.end()){
//cout<<s<<" "<<h<<" uuuu\n";
symbols.push_back(h);
if(m.find(s)!=m.end()){
keywords.push_back(s);
s="";
}
else {
identifiers.push_back(s);
s="";
}
s="";
continue;
}
if(m2.find(s)!=m2.end()){
symbols.push_back(s);
s="";
continue;
}
// cout<<c<<"wqww "<<s<<"\n";
s=s+c;
}
for(auto i: keywords){
cout<<i<<" ";
}
cout<<"\n\n";
for(auto i: identifiers){
int l=0;
// cout<<"start"<<"\n";
for(int j=0;j<i.size();j++){
if(i[j]=='\n' || i[j]==' ' || i[j]=='\t')
l=1;
// cout<<int(i[j])<<" tyy ";
}
// cout<<"\n";
if(l==1){
// cout<<"yyyy";
continue;
}
cout<<i<<" ";
}
cout<<"\n\n";
for(auto i: symbols){
cout<<i<<" ";
}
cout<<"\n\n";
printf("Closing the file special_symbols.txt\n") ;
fclose ( fp ) ;
return 0;
}