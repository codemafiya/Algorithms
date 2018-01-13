#include "bits/stdc++.h"
using namespace std;

long long n,sum,arr[123];

void func(bool used[],long long index){
	
	if(index == n+1){
		
		long long value = 0;
		for(long long i=1;i<=n;i++)
			if(used[i] == 1)
				value = value + arr[i];
		if(value == sum){
			
			cout << endl ;
			cout << "Indices  =  ";
			for(long long i=1;i<=n;i++){
				
				if(used[i] == 1)
					cout << i << " ";
			}
			cout << endl ;
		}
		return ;
	}
	used[index] = 1;
	func(used,index+1);
	used[index] = 0;
	func(used,index+1);
}
int main(){
	
	cout << "Enter n : ";
	cin >> n;
	cout << endl;
	
	cout << "Enter elements : ";
	for(long long i=1;i<=n;i++)
		cin >> arr[i];
	cout << endl ;
	
	cout << "Enter Sum : ";
	cin >> sum;
	cout << endl;
	
	cout << endl;
	
	bool used[n+1];
	for(long long i=1;i<=n;i++)
		used[i] = 0;
	
	func(used,1LL);
}
