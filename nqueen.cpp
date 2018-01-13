#include<bits/stdc++.h>
using namespace std;
int chess[100][100]={0};
void display();
bool safe(int n,int row,int col)
{
	int i,j;
	for(i=0;i<col;i++)
	
		if(chess[row][i])
		return false;
	
	for(i=row,j=col;i>=0 && j>=0;i--,j--)
	
		if(chess[i][j])
		return false;
	
//	for(i=row,j=col;j>=0 && i<n;i++,j--)
	for(i=row,j=col;j<n && i>=0;i--,j++)
		if(chess[i][j])
		return false;
	return true;
}
bool nqueen(int n,int col)
{
	int i;
	if(col>=n)
	return true;
	for(i=0;i<n;i++)
	{
	    if(safe(n,i,col))
	    {
			chess[i][col]=1;
		    if(nqueen(n,col+1))
			return true;
		    chess[i][col]=0;
		    display();
        }
	}
	return false;
}

void display(int n)
{
	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			cout<<chess[i][j]<<" ";
		}
		cout<<endl;
	}
	
}
int main()
{
	int n;
	cout<<"enter the size of chess board\n";
	cin>>n;
	if( nqueen(n,0) == false)
	{
		cout<<"solution not possible\n";
		return false;
	}
		//display(n);
		return true;
	return 0;
}







