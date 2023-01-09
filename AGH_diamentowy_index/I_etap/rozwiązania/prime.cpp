#include <iostream>
#include <string>

using namespace std;

int n, y;
string x;

bool czyPierwsza(int l){
	if(l==1){
		return false;
	}
	if(l==2){
		return true;
	}
	for(int i =2;i<=l-1;i++){
		if(l%i==0){
			return false;
		}
	}
	return true;
}
int main(){
	std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int l, i;
    cin>>n;
    for(int i =1;i<=250000;i++){
    	if(czyPierwsza(i)==true){
    		x=to_string(i);
    		l=x.length();
    		y=0;
    		for(int j=0;j<=l-1;j++){
    			y=y+x[j]-48;
			}
			if(y==n){
				cout<<i;
				return 0;
			}
			x.clear();
		}
	}
	cout<<"BRAK";
	return 0;
}
