//Szymon Mastalerz
#include <iostream>
#include <stack>
using namespace std;
int n, H, xMax=0,x=0;
string nawias;
int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    stack<char> stos;
    cin>>n>>H;
    cin>>nawias;
    for(int i =0;i<n;i++){
        if(nawias[i]=='('){
            stos.push(nawias[i]);
            if(stos.size()>H&&xMax<stos.size()){
                xMax=stos.size();
            }
        }else if(nawias[i]==')'){
            stos.pop();
        }
        if(stos.size()==0){
            if(xMax>0){
                xMax=xMax-H;
                if(xMax%2!=0){
                    xMax++;
                }
                x+=xMax;
                xMax=0;
            }
        }
    }
    cout<<x;
    return 0;
}
