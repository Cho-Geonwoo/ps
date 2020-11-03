#include <iostream>
#include <algorithm>
using namespace std;

struct restpos{
    long long pos;
    long long taste;
};

bool compare(restpos a, restpos b){
    if(a.taste == b.taste){
        return(a.pos>b.pos);
    }
    else{
        return(a.taste>b.taste);
    }
}

long long L, N, farmer, bessie;
restpos *re;
long long result = 0;
long long pos_max =0;

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(0);
    cin>>L>>N>>farmer>>bessie;
    re = new restpos[N];
    for(int i=0;i<N;i++){
        cin>>re[i].pos>>re[i].taste;
    }
    pos_max = re[N-1].pos;
    sort(re,re+N,compare);
    long long tmp = 0;
    for(int i=0;i<N;i++){
        if(re[i].pos==pos_max){
            result+= re[i].taste*(re[i].pos-tmp)*(farmer-bessie);
            break;
        }
        else if(re[i].pos>tmp){
            result+= re[i].taste*(re[i].pos-tmp)*(farmer-bessie);
            tmp = re[i].pos;
        }
        else{
            continue;
        }
    }
    cout<<result<<endl;
    return 0;
}
