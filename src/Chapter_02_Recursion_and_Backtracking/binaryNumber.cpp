#include<iostream>
#include<vector>

using namespace std;
void binary(int n,vector<int> v,int i)
{
	if(i==n)
	{
		for(int x:v)
		{
			cout<<x;
		}
		cout<<endl;
		return ;
	}
	else{
		v[i]=0;
		binary(n,v,i+1);
		v[i]=1;//backtrack(going back to same position)
		binary(n,v,i+1);
	}
}
int main()
{
	int n=3;
	vector<int> v(n);
	binary(n,v,0);
	return 0;
}