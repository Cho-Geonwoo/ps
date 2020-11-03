#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int main(int argc, char* argv[])
{
	int n;
	int tmp_first, tmp_second;
	priority_queue<int, vector<int>, greater<int> > pq;
	cin >> n;
	vector< pair<int, int> > v;
	for (int i = 0; i < n; ++i) {
		cin >> tmp_first >> tmp_second;
		v.push_back(make_pair(tmp_first,tmp_second));
	}
	sort(v.begin(), v.end());
	pq.push(v[0].second);
	for (int i = 1; i < n; ++i) {
		if (pq.top() <= v[i].first) {
			pq.pop();
			pq.push(v[i].second);
		}
		else {
			pq.push(v[i].second);
		}
	}
	cout << pq.size() << endl;

	return 0;
}
