#include<iostream>
#include<vector>
using namespace std;
void k_strings(int requiredStringLen, int givenLen,vector<int> v,int i)
{
	//backtrack
	if(i==requiredStringLen)
	{
		for(int x:v)
			cout<<x;
		cout<<endl;
		return;
	}
	for(int j=0;j<givenLen;j++)
	{
		v[i]=j;
		k_strings(requiredStringLen,givenLen,v,i+1);
	}
}
int main()
{
	int n=3;
	vector<int> a(n);
	k_strings(n,3,a,0);
	return 0;
}