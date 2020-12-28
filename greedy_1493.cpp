#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int length, width, height;
int result = 0;
int typenum;
bool check = true;

struct block{
    int blocklen;
    int blocknum;
};

block* b;

bool compare(block first, block second){
    return(first.blocklen>second.blocklen);
}

void solve(int ll, int ww, int hh){
    if(check==false){
        return;
    }
    else if((ll==0)||(ww==0)||(hh==0)){
        return;
    }
    else{
        for(int i=0;i<typenum;i++){
            if((ll>=b[i].blocklen)&&(ww>=b[i].blocklen)&&(hh>=b[i].blocklen)&&(b[i].blocknum>0)){
                b[i].blocknum--;
                result++;
                solve(ll, ww, hh-b[i].blocklen);
                solve(b[i].blocklen, ww-b[i].blocklen, b[i].blocklen);
                solve(ll-b[i].blocklen, ww, b[i].blocklen);
                return;
            }
            else{
                continue;
            }
        }
    }
    check = false;
}

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(0);
    int tmp;
    cin>>length>>width>>height;
    cin>>typenum;
    b = new block[typenum];
    for(int i=0;i<typenum;i++){
        cin>>tmp;
        b[i].blocklen = pow(2,tmp);
        cin>>b[i].blocknum;
    }
    sort(b,b+typenum,compare);
    solve(length, width, height);
    if(check==true){
        cout<<result<<endl;
    }
    else{
        cout<<-1<<endl;
    }
    return 0;
}
