//Szymon Mastalerz
#include <iostream>
#include <vector>
using namespace std;
long double n,V,v,D,d,x,W,w,M,m,t=0,zmiana=0,k=1, y=0;
bool czyLewy=false;
vector<float>odleglosc;
vector<float>dlugosc;
vector<float>predkosc;
int wyprzedzanie(){
	for(int j=n;j<=1;j--){
        if((predkosc[j]*t)+odleglosc[j]-dlugosc[j]<=odleglosc[j-1]+(t*predkosc[j-1])){
            odleglosc[j-1]=odleglosc[j]-dlugosc[j];
            predkosc[j-1]=predkosc[j];
        }
    }
    return 1;
}
int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    cin>>n>>D>>W>>M;
    V=W/M;
    odleglosc.push_back(0);
    dlugosc.push_back(0);
    predkosc.push_back(0);
    for(int i=1;i<=n;i++){
        cin>>x>>d>>w>>m;
        v=w/m;
        odleglosc.push_back(x);
        dlugosc.push_back(d);
        predkosc.push_back(v);
    }
    while(k<=n){
    	if(czyLewy==false){
    		t=(dlugosc[k]-odleglosc[k])/(predkosc[k]-V);
    		zmiana++;
    		czyLewy=true;
    		if(t!=0){
    			wyprzedzanie();
			}    		
		}else if(czyLewy==true){
			t=(D+odleglosc[k])/(V-predkosc[k]);
			wyprzedzanie();
			if(y>=10){
				t+=0.0000000001;
			}
			if((V*t)-D>=(predkosc[k]*t)+odleglosc[k]){
				k++;
				y=0;
			}else{
				y++;
			}
			if((V*t)<(predkosc[k]*t)+odleglosc[k]-dlugosc[k]){
				czyLewy=false;
			}
		}
	}
    cout<<zmiana;
    return 0;
}
