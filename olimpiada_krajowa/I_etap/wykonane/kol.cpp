//Szymon Mastalerz
#include <iostream>
#include <vector>

using namespace std;

int m, p, n,wI,kI,cI,wJ,kJ,x=1,y=1,l=1, s,xTemp, yTemp;
char krok;
int **plansza;
vector<char>ostatnieKroki;

int temp(){
	if(ostatnieKroki[s]=='G'){
		yTemp++;
	}
	if(ostatnieKroki[s]=='D'){
		yTemp--;
	}
	if(ostatnieKroki[s]=='P'){
		xTemp--;
	}
	if(ostatnieKroki[s]=='L'){
		xTemp++;
	}
	return 1;
}

int przesuniecie(){
	s--;
	for(int i =1;i<=l;i++){
		if(ostatnieKroki[s]=='G'){
			plansza[yTemp][xTemp]=plansza[yTemp+1][xTemp];
			temp();
		}else if(ostatnieKroki[s]=='D'){
			plansza[yTemp][xTemp]=plansza[yTemp-1][xTemp];
			temp();
		}else if(ostatnieKroki[s]=='P'){
			plansza[yTemp][xTemp]=plansza[yTemp][xTemp-1];
			temp();
		}else if(ostatnieKroki[s]=='L'){
			plansza[yTemp][xTemp]=plansza[yTemp][xTemp+1];
			temp();
		}
		s--;
	}
	plansza[yTemp][xTemp]=-1;
	return 1;
}

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    cin>>m>>p>>n;
    int **przekaski =new int *[m+1];
    plansza=new int *[m+1];
    for(int i =0;i<=m;i++){
    	plansza[i]=new int [m+1];
    	przekaski[i]=new int [m+1];
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			plansza[i][j]=-1;
			przekaski[i][j]=-1;
		}
	}
	plansza[1][1]=0;
	for(int i=1;i<=p;i++){
		cin>>wI>>kI>>cI;
		przekaski[wI][kI]=cI;
	}
	for(int i =1;i<=n;i++){
		cin>>krok;
		if(krok=='Z'){
			cin>>wJ>>kJ;
			cout<<plansza[wJ][kJ]<<'\n';
		}else if(krok=='G'){
			y--;
			ostatnieKroki.push_back(krok);
			if(przekaski[y][x]!=-1){
				l++;
				plansza[y][x]=przekaski[y][x];
			}else{
				xTemp=x;
				yTemp=y;
				s=ostatnieKroki.size();
				przesuniecie();
			}
		}else if(krok=='D'){
			y++;
			ostatnieKroki.push_back(krok);
			if(przekaski[y][x]!=-1){
				l++;
				plansza[y][x]=przekaski[y][x];
			}else{
				xTemp=x;
				yTemp=y;
				s=ostatnieKroki.size();
				przesuniecie();
			}
		}else if(krok=='P'){
			x++;
			ostatnieKroki.push_back(krok);
			if(przekaski[y][x]!=-1){
				l++;
				plansza[y][x]=przekaski[y][x];
			}else{
				xTemp=x;
				yTemp=y;
				s=ostatnieKroki.size();
				przesuniecie();
			}
		}else if(krok=='L'){
			x--;
			ostatnieKroki.push_back(krok);
			if(przekaski[y][x]!=-1){
				l++;
				plansza[y][x]=przekaski[y][x];
			}else{
				xTemp=x;
				yTemp=y;
				s=ostatnieKroki.size();
				przesuniecie();
			}
		}
	}
    return 0;
}
