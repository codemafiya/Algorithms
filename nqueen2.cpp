#include<bits/stdc++.h>
using namespace std;

int flag=0,countt=0;

void print_board(int board[][20],int n)
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cout<<board[i][j]<<"  ";
		}
		cout<<endl;
	}
}

int check(int board[][20],int row,int col,int n)
{
	for(int i=0;i<row;i++)
	{
		if(board[i][col]==1)
		return 0;
	}
	for(int i=row,j=col;i>=0&&j<n;i--,j++)
	{
		if(board[i][j]==1)
		return 0;
	}
	for(int i=row,j=col;i>=0&&j>=0;i--,j--)
	{
		if(board[i][j]==1)
		return 0;
	}
	return 1;
}

void back_track(int board[][20],int n,int row)
{
	if(row>=n)
	{
		flag=1;
	}
	
	else
	{
		for(int i=0;i<n;i++)
		{
			if(check(board,row,i,n)==1)
			{
				board[row][i]=1;
				back_track(board,n,row+1);
				
				if(flag==1)
				{
					print_board(board,n);
					countt++;
					cout<<endl<<endl;
					flag=0;
				}
				board[row][i]=0;
			}
		}
		flag=0;
	}
}

int main()
{
	int board[20][20]={{0}},n;
	cout<<"Enter the no of queens:  ";
	cin>>n;
	back_track(board,n,0);
	cout<<endl<<"No of possible solutions: "<<countt;
	return 0;
}
