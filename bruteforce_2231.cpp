#include <iostream>

using namespace std;

long split_sum(long cal){
    long ans = cal;
    while(cal!=0){
        ans += cal%10;
        cal/=10;
    }
    return ans;
}

int main(){
    int check = 0;
    long N;
    cin>>N;
    int d = 0;
    long tmp = N;
    while(tmp!=0){
        tmp/=10;
        d++;
    }
    for(long i=(N-9*d);i<=N;i++){
        if(split_sum(i)==N){
            cout<<i<<endl;
            check = 1;
            break;
        }
    }
    if(check==0){
        cout<<0<<endl;
    }
    return 0;
}
