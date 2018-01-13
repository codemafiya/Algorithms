#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t>0){
		int n=t;
		int count=0;
		while(n>1){
			n=n/2;
			count++;
			
		}
		cout<<count<<endl;
		cin>>t;
	}
	return 0;
}
