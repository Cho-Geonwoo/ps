#include <iostream>
#include <algorithm>
using namespace std;

#define n 1001

int main(){
    int N,L;
    int pos[n];
    cin>>N>>L;
    for(int i=0;i<N;i++){
        cin>>pos[i];
    }
    int cnt = 1;
    sort(pos,pos+N);
    int tmp = pos[0];
    for(int i=1;i<N;i++){
        if(pos[i]<=(tmp+L-1)){
            continue;
        }
        else{
            tmp = pos[i];
            cnt++;
        }
    }
    cout<<cnt;
    return 0;
}
