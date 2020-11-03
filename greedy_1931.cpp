#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(pair<int,int> a, pair <int,int> b){
    if(a.second==b.second){
        return (a.first<b.first);
    }
    else{
        return (a.second<b.second);
    }
}

int main(){
    int N, tmp_start, tmp_final;
    int cnt = 1;
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    //increase the speed of cin
    cin>>N;
    vector <pair <int, int> > v;
    for(int i=0;i<N;i++){
        cin>>tmp_start;
        cin>>tmp_final;
        v.push_back(make_pair(tmp_start, tmp_final));
    }
    sort(v.begin(),v.end(),compare);
    int min = v[0].second;
    for(int i=1;i<N;i++){
        if(v[i].first>=min){
            min = v[i].second;
            cnt++;
        }
    }
    cout<<cnt<<endl;
    return 0;
}
