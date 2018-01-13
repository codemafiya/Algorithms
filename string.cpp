#include <iostream>
using namespace std;

int main()
{
    //printf("Hello World!\n");
    long long t,flag;
    string s;
    cin>>t;
    while(t--)
    {
    	cin>>s;
    	int i=0;
    	flag=0;
	    	while(i<s.length())
	    	{
	    		if(s[i]=='0'||s[i]=='1'||s[i]=='8')
	    		{
	    			flag=0;
	    			//break;
	    		}
	    		else
	    		{
	    			flag=1;
	    			break;
	    		}
	    		//n=n/10;
	    		i++;
	    	}
	    	if(flag==1)
	    	cout<<"NO"<<endl;
	    	else
	    	cout<<"YES"<<endl;
    }
    return 0;
}

