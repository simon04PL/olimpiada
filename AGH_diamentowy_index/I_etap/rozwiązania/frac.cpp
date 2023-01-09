#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

int x, y, z, r, j=0, tmp, l;

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	map<int, int> m;
	vector<int>v;
	cin>>x>>y;
	z=x/y;
	r=x%y;
	if(r==0){
		cout<<z;
		return 0;
	}
	m.insert({r,0});
	while(r!=0){
		if(r<y){
			r=r*10;
		}
		tmp=r/y;
		v.push_back(tmp);
		tmp=tmp*y;
		r=r-tmp;
		if(m.count(r)==1){
			l=m[r]+1;
			break;
		}
		m.insert({r, j+1});
		if(r==0){
			break;
		}
		j++;
	}
	cout<<z<<".";
	if(r==0){
		for(int i=0;i<=v.size()-1;i++){
			cout<<v[i];
		}
	}else if(r!=0){
		if(l>0){
			for(int i =0;i<=m[r]-1;i++){
				cout<<v[i];
			}
		}
		cout<<"(";
		for(int i=l-1;i<j+1;i++){
			cout<<v[i];
		}
		cout<<")";
	}
	return 0;
}
