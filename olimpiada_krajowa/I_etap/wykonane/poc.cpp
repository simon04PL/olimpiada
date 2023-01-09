//Szymon Mastalerz
#include <iostream>
#include <vector>
using namespace std;
int n, m, k, x, opcje=1, a, g=0;
int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    vector<int>Bajtek;
    vector<int>Bitek;
    Bajtek.push_back(0);
    Bitek.push_back(0);
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++){
        cin>>x;
        Bajtek.push_back(x);
    }
    for(int i=1;i<=m;i++){
        cin>>x;
        Bitek.push_back(x);
    }
    for(int i =1;i<=n;i++){
        for(int j=opcje;j>=1;j--){
            if(Bajtek[i]==Bitek[j]){
				if(j!=m){
					a=j+1;
					for(int z=i+1;z<=n;z++){
						if(Bajtek[z]==Bitek[a]){
							if(a<m){
								a++;
							}
							if(a==m){
								cout<<"1 ";
								g++;
								if(opcje<=m&&j==opcje){
									opcje++;
								}
								break;
							}
						}
					}
				}else{
					a=m;
					cout<<"1 ";
					g++;
				}
				if(g==1){
					break;
				}
            }
        }
        if(g==0){
        	cout<<"0 ";
		}
		g=0;
    }
    return 0;
}
