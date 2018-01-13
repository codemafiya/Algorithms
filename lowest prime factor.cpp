#include<iostream>
#include<stdio.h>
#include<bitset>
#include<vector>
#include<math.h>
#define N 100
using namespace std;
bitset <N> bits ;
int primes[N]	;
void precomputation(){
    for(int i = 2; i < N; i += 2)	primes[i] = 2 ;
	int sq=sqrt(N-1);
    for(int i = 3; i < N; i += 2)
            if (!bits[i]){
                primes[i] = i   ;
                if(i<=sq) for(int j = i * i; j < N; j += 2 * i)
                    if (!bits[j]){
                        primes[j] = i ;
                        bits[j] = 1 ;
 
                    }
            }
}
int main()
{
precomputation();
return 0;
}

