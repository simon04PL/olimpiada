//Szymon Mastalerz
//pomoc w zrozumieni algorytmu Dijskry kopcowego Emil Hotkowski http://www.algorytm.org/algorytmy-grafowe/algorytm-dijkstry/dijkstra-kopce-c.html
#include <iostream>
#include <algorithm>
#include <vector>
#include <stdio.h>
#include<map>
#define N 100000
#define NUM 9223372036854775807
using namespace std;

class kopiec{
    public:
    int tab[N];
    int node_nr[N];
    int size;
    kopiec();
    void insert_into(int v,int node);
    void delete_into();
};
int n,k,a,b,c,d,vN,uN;
long long int suma=0;
long long int *odleglosc;
int *poprzednicy;
vector<vector<int>>graf(N);
vector<vector<int>>wagiVector(N);
vector<vector<int>>wagiVectorKopia(N);
vector<vector<int>>grafKopia(N);
map<pair<int,int>,long long int>wagi;
bool nieodwiedzone[N+1];
int najkrutsza(int h){
    fill(odleglosc,odleglosc+n+1,NUM);
    fill(poprzednicy,poprzednicy+n+1,-1);
    odleglosc[h]=0;
    nieodwiedzone[h]=false;
    kopiec K;
    int uN = h;
    for(int i=0;i<=n;i++){
        for(int j=0;j<graf[i].size();j++){
            grafKopia[i].push_back(graf[i][j]);
            wagiVectorKopia[i].push_back(wagiVector[i][j]);
        }
    }
    for(int x = 1 ; x <= n ; x++){
        while(!grafKopia[uN].empty()){
            int vN = grafKopia[uN].back();
            if(odleglosc[vN] > odleglosc[uN]+wagiVectorKopia[uN].back()){
                odleglosc[vN] = odleglosc[uN] + wagiVectorKopia[uN].back();
                nieodwiedzone[vN]=true;
                K.insert_into(odleglosc[vN],vN);
            }
            grafKopia[uN].pop_back();
            wagiVectorKopia[uN].pop_back();
        }
        uN = K.node_nr[1];
        K.delete_into();
    }
    return 1;
}
kopiec::kopiec(){
    size = 0;
}
void kopiec::insert_into(int v,int node){
    tab[size+1] = v;
    int s = size+1;
    node_nr[s] = node;
    while(s!=1){
        if(tab[s/2] > tab[s]){
            tab[s]=tab[s]^tab[s/2];
            tab[s/2]=tab[s]^tab[s/2];
            tab[s]=tab[s]^tab[s/2];
            node_nr[s]=node_nr[s]^node_nr[s/2];
            node_nr[s/2]=node_nr[s]^node_nr[s/2];
            node_nr[s]=node_nr[s]^node_nr[s/2];
            s/=2;
        }else{
            break;  
        }
    }
    size++;
}
void kopiec::delete_into(){
    tab[1] = tab[size];
    int tmp = 1;
    while(tmp*2 <= size){
        if(tab[tmp] > tab[tmp*2] || tab[tmp] > tab[tmp*2+1]){
            if(tab[tmp*2] < tab[tmp*2+1] || tmp*2+1 > size){
                tab[tmp]=tab[tmp]^tab[tmp*2];
                tab[tmp*2]=tab[tmp]^tab[tmp*2];
                tab[tmp]=tab[tmp]^tab[tmp*2];
                node_nr[tmp]=node_nr[tmp]^node_nr[tmp*2];
                node_nr[tmp*2]=node_nr[tmp]^node_nr[tmp*2];
                node_nr[tmp]=node_nr[tmp]^node_nr[tmp*2];
                tmp=tmp*2;
            }
            else{
                tab[tmp]=tab[tmp]^tab[tmp*2+1];
                tab[tmp*2+1]=tab[tmp]^tab[tmp*2+1];
                tab[tmp]=tab[tmp]^tab[tmp*2+1];
                node_nr[tmp]=node_nr[tmp]^node_nr[tmp*2+1];
                node_nr[tmp*2+1]=node_nr[tmp]^node_nr[tmp*2+1];
                node_nr[tmp]=node_nr[tmp]^node_nr[tmp*2+1];
                tmp=tmp*2+1;
            }
        }else{
            nieodwiedzone[tmp]=false;
            break;
        }
    }
    size--;
    if(nieodwiedzone[node_nr[1]]==false){
        delete_into();
    }
}
int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    vector<int>wioski;
    cin>>n>>k;
    odleglosc = new long long [n+1];
    poprzednicy =new int[n+1];
    wioski.push_back(1);
    for(int i=1;i<=n-1;i++){
        cin>>a>>b>>c;
        graf[a].push_back(b);
        wagi.insert({{a,b},c});
        graf[b].push_back(a);
        wagi.insert({{b,a},c});
        wagiVector[a].push_back(c);
        wagiVector[b].push_back(c);
    }
    for(int i=1;i<=k;i++){
        cin>>d;
        wioski.push_back(d);
    }
    for(int i =1;i<k+1;i++){
        najkrutsza(wioski[i]);
        for(int j=0;j<=i-1;j++){
            suma+=odleglosc[wioski[j]];
        }
        cout<<suma*2<<'\n';
    }
    return 0;   
}
