#include "bits/stdc++.h"
using namespace std;

vector<long long> graph[1000];
vector<bool> visited(1001,0);

void dfs(long long src){
	
	cout  << src << " ";
	visited[src] = 1;
	for(vector<long long>::iterator it = graph[src].begin() ; it != graph[src].end() ; it++){
		
		if(visited[*it] == 0){
			
			dfs(*it);
		}
	}
}

int main(){
	
	long long n,e;
	cin >> n >> e;
	
	while(e--){
		
		long long a,b;
		cin >> a >> b;
		
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	
	
	for(long long i=1;i<=n;i++)
		if(visited[i] == 0){
			dfs(i);
			cout << endl;
		}
}
