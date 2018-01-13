#include<iostream>
using namespace std;
int pop()
{
	if(top==-1)
	return;
	else
	{
		return a[top];
		top--;
	}
}
void push(int val)
{
	if(top>=999)
	return;
	a[++top]=val;
}
bool isempty()
{
	if(top==-1)
	return true;
	return false;	
}
bool isfull()
{
	if(top>=999)
	return true;
	return false;
}
int precidence(char ch)
{
	switch(ch)
	{
		case '+':
		case '-':
			return 1;
		case '*':
		case '/':
			return 2;
		case '^':
			return 3;
			
	}
	return -1;
}
bool isoperand(char ch)
{
	if(ch>='A'&&ch<='Z')||(ch>='a'||ch<='z')
	return true;
	else
	return false;
}
int main()
{
	int t;
	string s;
	int k=0,i;
	char post[1000];
	cin>>t;
	while(t--)
	{
		cin>>s;
		for(i=0;i<s.length();i++)
		{
			if(isoperand(s[i]))
			post[k++]=s[i];
			else if(s[i]=='(')
			{
				puch(s[i]);
			}
			else if(s[i]==')')
			{
				
			}
		}
		
	}
}
