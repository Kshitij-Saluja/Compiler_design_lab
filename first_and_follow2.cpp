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
string ans="";
vector <string> grammer[101];
map <string,int> m;
map <int,string> m2;
map <string,string> firs;
int ii;
string follow(char a){
	int count=0;
	for(auto i: grammer){
		for(int j=0;j<i.size();j++){
			int hh=0;
		//	cout<<i[j]<<"sss";
		for(int k=0;k<i[j].size();k++){
			if(i[j][k]==a || hh==1){
				if(k==(i[j].size()-1)){
					if(m2[count][0]==a)
					break;
					ans=ans+"x(";
					ans=ans+m2[count];
					ans=ans+")";
					break;
				}
				hh=0;
				string kk;
				kk.push_back(i[j][k+1]);
				if(firs.find(kk)==firs.end()){
					ans=ans+kk[0];
				}
				else{
				for(auto q: firs[kk]){
					if(q=='q'){
						hh=1;
						break;
					}
					ans=ans+q;
				}
				}
			}
		}
		}
		count++;
	}
	return ans;
}
string first(string a,int yy,string kk){
		if(m.find(a)==m.end()){
		return a;
	}
	for(auto i: grammer[m[a]]){
		string h="";
		h.push_back(i[0]);
		string rr=first(h,0,i);
		int jj=yy;
		int uu=kk.size();
		while(rr=="q" && (jj<(uu-1))){
			jj++;
			string h="";
			h.push_back(kk[jj]);
			rr=first(h,jj,kk);
			jj=yy;
		}
		ans=ans+rr;
	}
	return ans;
}
int main() {
	int n;
	m["S"]=1;
	m["A"]=2;
	m["B"]=3;
	m["C"]=4;
	n=5;
	grammer[1].push_back("ACB");
	grammer[1].push_back("CbB");
	grammer[1].push_back("Ba");
	grammer[2].push_back("da");
	grammer[2].push_back("BC");
	grammer[3].push_back("g");
	grammer[3].push_back("q");
	grammer[4].push_back("h");
	grammer[4].push_back("q");
	for(auto i: m){
		m2[i.second]=i.first;
	}
	int u;
	for(int i=1;i<n;i++){
		string h=first(m2[i],0,"");
		set <char> ss1;
		for(auto i: ans){
			ss1.insert(i);
		}
		string b="";
		for(auto i: ss1){
			cout<<i<<" ";
			b.push_back(i);
		}
		firs[m2[i]]=b;
		cout<<"\n";
		ans="";
	}
	string follo[101];
	
		for(int i=1;i<n;i++){
			string as=follow(m2[i][0]);
			if(i==1){
				follo[i].push_back('$');
			}
			for(auto y: as){
				follo[i].push_back(y);
			}
			ans="";
		}
		cout<<"\n";
		while(1){
			int l=1;
			for(int i=1;i<n;i++){
				for(int j=0;j<follo[i].size();j++){
					if(follo[i][j]=='x')
					{
						l=0;
						break;
					}
				}
				if(l==0)
				break;
			}
			if(l==1)
			break;
			string follo_temp[101];
			for(int i=1;i<n;i++){
					int j=0;
					while(j<follo[i].size()){
						if(follo[i][j]=='x'){
							j=j+2;
							string jj;
							jj.push_back(follo[i][j]);
							int y=m[jj];
							for(int ww=0;ww<follo[y].size();ww++){
								follo_temp[i].push_back(follo[y][ww]);
							}
							j=j+2;
							continue;
						}
						follo_temp[i].push_back(follo[i][j]);
						j++;
					}
			}
			for(int i=1;i<n;i++){
				follo[i].clear();
			}
			for(int i=1;i<n;i++){
				for(int j=0;j<follo_temp[i].size();j++)
				follo[i].push_back(follo_temp[i][j]);
			}
		}
		for(auto i: follo){
			set <char> ss;
			for(auto j: i){
				ss.insert(j);
			}
			for(auto i: ss){
				cout<<i<<" ";
			}
			cout<<"\n";
		}
}