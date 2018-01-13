#include<bits/stdc++.h>
#include<vector>

using namespace std;


int main(){
    int n1;
    int n2;
    int n3,i,j,k;
    cin >> n1 >> n2 >> n3;
    int c1=0,c2=0,c3=0;
    vector<int> h1(n1);
    for(int h1_i = 0;h1_i < n1;h1_i++){
       cin >> h1[h1_i];
       c1=c1+h1[h1_i];
    }
    vector<int> h2(n2);
    for(int h2_i = 0;h2_i < n2;h2_i++){
       cin >> h2[h2_i];
       c2=c2+h2[h2_i];
    }
    vector<int> h3(n3);
    for(int h3_i = 0;h3_i < n3;h3_i++){
       cin >> h3[h3_i];
       c3=c3+h3[h3_i];
    }
    while(c1!=c2||c2!=c3||c1!=c3){
        if((c1>c2&&c1>c3)||(c1>=c2&&c1>c3)||(c1>c2&&c1>=c3))
        {
        	c1=c1- *(h1.end() - 1) ;
        	h1.erase((h1.end()- 1));
        	//i--;
        	
        }
        if((c2>c1&&c2>c3)||(c2>=c1&&c2>c3)||(c2>c1&&c2>=c3))
        {
        	c2=c2- *(h2.end() - 1) ;
        	h2.erase((h2.end()- 1));
        	
        }
        if((c3>c2&&c3>c1)||(c3>=c2&&c3>c1)||(c3>c2&&c3>=c1))
        {
        	c2=c2- *(h2.end() - 1) ;
        	h2.erase((h2.end()- 1));      	
        }
        	
    }
    cout<<c1<<" "<<c2<<" "<<c3;
    return 0;
}

