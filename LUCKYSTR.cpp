#include <cstring>
#include <iostream>
using namespace std;

const int maxK = 50;
const int maxL = 50;

int main()
{
	int k,n;
	cin >> k >> n;
	char s[maxK][maxL+1];
	for(int j=0;j<k;j++)
		cin >> s[j];
	for(int i=0;i<n;i++)
	{
		char w[maxL+1];
		cin >> w;
		if(strlen(w)>=47) puts("Good"); else
		{
			int j;
			for(j=0;j<k && !strstr(w,s[j]);j++);
			puts(j<k?"Good":"Bad");
		}
	}
	return 0;
}
