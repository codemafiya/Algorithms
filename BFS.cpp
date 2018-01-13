#include "bits/stdc++.h"
using namespace std;

vector<long long> graph[1000];
vector<bool> visited(1001,0);

int main(){
	
	long long n,e;
	cin >> n >> e;
	
	while(e--){
		
		long long a,b;
		cin >> a >> b;
		
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	
	queue<long long> q;
	q.push(1);
	visited[1] = 1;
	
	while(!q.empty()){
		
		long long top = q.front();
		q.pop();
		cout << top << " ";
		for(vector<long long>::iterator it = graph[top].begin() ; it != graph[top].end() ; it++){
			
			if(visited[*it] == 0){
				
				q.push(*it);
				visited[*it] = 1;
			}
		}
	}
	
}
