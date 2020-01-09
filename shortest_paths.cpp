#include <iostream>
#include <limits>
#include <vector>
#include <queue>

using namespace std;

using std::vector;
using std::queue;
using std::pair;
using std::priority_queue;

void shortest_paths(vector<vector<int> > &adj, vector<vector<int> > &cost, int s, vector<long long> &dist) {
  //write your code here
  for(int k = 1 ; k < adj.size() ; k++){
  	// |v| - 1 iterations
  	for(int i = 0 ; i < adj.size() ; i++){
  		for(int j = 0 ; j < adj[i].size() ; j++){
  			int v = adj[i][j];
  			if(dist[v] > dist[i] + cost[i][j]){
  				dist[v] = dist[i] + cost[i][j];
			}
		}
	}
  }
}

int main() {
  int n, m, s;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  vector<vector<int> > cost(n, vector<int>());
  for (int i = 0; i < m; i++) {
    int x, y, w;
    std::cin >> x >> y >> w;
    adj[x - 1].push_back(y - 1);
    cost[x - 1].push_back(w);
  }
  std::cin >> s;
  s--;
  const int INF = 1000000;
  vector<long long> distance(n, INF);
  distance[s] = 0;
  shortest_paths(adj, cost, s, distance);
  for(int i = 0 ; i < distance.size() ; i++){
  	cout << distance[i] << endl;
  }
}
