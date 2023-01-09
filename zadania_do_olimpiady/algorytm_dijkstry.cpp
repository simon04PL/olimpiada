#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include<map>

using namespace std;

int N, n, *poprzednicy, *odleglosc,k, w;
set<int>nieodwiedzone;
vector<int>*graf;
map<pair<int,int>,int>wagi;

bool minimalna(int v1, int v2){
	return odleglosc[v1]<odleglosc[v2];
}
int main(){
    cin>>N;
    graf=new vector<int>[N];
    for(int i=0;i<N;i++){
        cin>>n;
        for(int j =0;j<n;j++){
            cin>>k>>w;
            graf[i].push_back(k);
            wagi.insert({{i,k},w});
        }
        nieodwiedzone.insert(i);
    }
    poprzednicy=new int[N];
    odleglosc=new int[N];
    fill(poprzednicy,poprzednicy+N,-1);
    fill(odleglosc,odleglosc+N,1001);
    odleglosc[0]=0;
    while(!nieodwiedzone.empty()){
        int u=*min_element(nieodwiedzone.begin(),nieodwiedzone.end(), minimalna);
        nieodwiedzone.erase(u);
        for(int i =0;i<graf[u].size();i++){
        	int v=graf[u][i];
        	if(odleglosc[v]>odleglosc[u]+wagi[{u,v}]){
        		odleglosc[v]=odleglosc[u]+wagi[{u,v}];
        		poprzednicy[v]=u;
			}
		}
    }
    for(int i =0;i<N;i++){
    	cout<<odleglosc[i]<<" ";
	}
	cout<<endl;
	for(int i =0;i<N;i++){
	cout<<poprzednicy[i]<<" ";
	}
    return 0;
}
