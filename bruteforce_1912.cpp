#include <iostream>
#define MAX 100001
using namespace std;
int series[MAX] = {0,};
int main(){
    int n;
    cin>>n;
    cin>>series[0];
    int maxnum = series[0];
    int tmp = series[0];
    for(int i=1;i<n;i++){
        cin>>series[i];
        tmp = max(series[i],tmp+series[i]);
        if(tmp>maxnum){
            maxnum = tmp;
        }
    }
    cout<<maxnum<<endl;
    return 0;
}
