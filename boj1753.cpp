#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
const int MAX_V = 20000;
#define INF 1e9
typedef pair<int, int> P;

vector<P> adj[MAX_V];
int dist[MAX_V];
bool visited[MAX_V] = {false};

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int V, E, K;
	cin>>V>>E>>K;
	K--;
	for(int i=0;i<E;i++){
		int u, v, w;
		cin>>u>>v>>w;
		adj[u-1].push_back(P{v-1, w});
	}
	fill(dist, dist+MAX_V, INF);
	priority_queue<P, vector<P>, greater<P> > PQ;
	dist[K] = 0;
	PQ.push(P{0, K});
	while(!PQ.empty()){
		int curr;
		do{
			curr = PQ.top().second;
			PQ.pop();
		}while(!PQ.empty()&&visited[curr]);
		if(visited[curr]) break;
		visited[curr] = true;
		for(auto &p: adj[curr]){
			int next = p.first, d = p.second;
			if(dist[next]>dist[curr]+d){
				dist[next] = dist[curr]+d;
				PQ.push(P{dist[next], next});
			}
		}
	}
	for(int i=0;i<V;i++){
		if(dist[i]==INF) cout<<"INF"<<endl;
		else cout<<dist[i]<<endl;
	}
}