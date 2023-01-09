#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int l, lMax,L, M,x;

int main(){
	std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
	vector<int>liczbaL;
	vector<int>liczbaM;
	cin>>x;
	for(int i =0;i<=x-1;i++){
		cin>>L>>M;
		liczbaL.push_back(L);
		liczbaM.push_back(M);
	}
	for(int i =0;i<=x-3;i++){
		if(liczbaL[i+1]*liczbaL[i+1]*liczbaM[i]*liczbaM[i+2]==liczbaL[i]*liczbaL[i+2]*liczbaM[i+1]*liczbaM[i+1]){
			l=3;
			for(int j=i+1;j<=x-2;j++){
				if(liczbaL[j+1]*liczbaL[j+1]*liczbaM[j]*liczbaM[j+2]==liczbaL[j]*liczbaL[j+2]*liczbaM[j+1]*liczbaM[j+1]){
					l++;
				}else{
					if(lMax<=l){
						lMax=l;
					}
					l=0;
					break;
				}
			}
		}
	}
	if(lMax>=3){
		cout<<lMax;
	}else{
		cout<<"BRAK";
	}
	return 0;
}
