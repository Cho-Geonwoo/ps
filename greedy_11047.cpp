#include <iostream>
using namespace std;

#define n 10

int main(){
    int N, K;
    cin>>N>>K;
    int coin[n];
    for(int i=0;i<N;i++){
        cin>>coin[i];
    }
    int cnt = 0;
    int tmp;
    for(int i=(N-1);i>=0;i--){
        tmp = K/coin[i];
        cnt += tmp;
        K -= coin[i]*(tmp);
    }
    cout<<cnt;
    return 0;
}
