#include <iostream>

using namespace std;

int x, y=0,z=0,xW=0,yW=0;
char lab[20][20];

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	cin>>x;

	for(int i=0;i<=x-1;i++){
		for(int j =0;j<=x-1;j++){
			cin>>lab[i][j];
		}
	}
	while(xW!=x-1||yW!=x-1){
		if(lab[yW-1][xW]=='.'){
			lab[yW][xW]='b';
			yW--;
			y++;
		}else if(lab[yW+1][xW]=='.'){
			lab[yW][xW]='b';
			yW++;
			y++;
		}else if(lab[yW][xW+1]=='.'){
			lab[yW][xW]='b';
			xW++;
			y++;
		}else{
			cout<<"BRAK";
			return 0;
		}
	}
	cout<<y;
	return 0;
}
