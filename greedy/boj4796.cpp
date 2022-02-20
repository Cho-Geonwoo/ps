#include <iostream>
#include <queue>

using namespace std;

int calc(int a, int b, int c){
    int tot = c/b;
    int cnt = (c-tot*b);
    int sum = 0;
    sum+=a*tot;
    if(a<cnt){
        sum+=a;
    }
    else{
        sum+=cnt;
    }
    return sum;
}

int main(){
    int tmp_a,tmp_b,tmp_c;
    queue<int> q;
    while(true){
        cin>>tmp_a>>tmp_b>>tmp_c;
        if((tmp_a==0)&&(tmp_b==0)&&(tmp_c==0)){
            break;
        }
        q.push(calc(tmp_a,tmp_b,tmp_c));
    }
    int t = q.size();
    for(int i=0;i<t;i++){
        cout<<"Case "<<i+1<<": "<<q.front()<<endl;
        q.pop();
    }
    return 0;
}
