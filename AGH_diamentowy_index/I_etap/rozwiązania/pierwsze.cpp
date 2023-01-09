#include <iostream>
#include <fstream>

using namespace std;


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
int main (){
	ofstream plik;
	plik.open("liczby.txt");
	for(int i =1;i<=1048575;i++){
		if(czyPierwsza(i)==true){
			plik<<i<<", ";
		}
	}
	return 0;
}
