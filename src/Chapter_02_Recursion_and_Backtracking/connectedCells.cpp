#include<iostream>
#include<vector>
using namespace std;
int getVal(vector<vector<int>> &a,int i,int j,int H,int L)
{
	if(i<0 || j<0 || i>=L || j>=H)
		return 0;
	else
		return a[i][j];
}
void connectedCells(vector<vector<int>> &a,int i,int j,int maxRow,int maxCol,int size,vector<vector<int>> &cnt,int &mxSize){
	if(i>=maxRow || j>= maxCol)
		return ;
	cnt[i][j]=1;
	size++;//we have encountered one
	mxSize=max(size,mxSize);
	int directions[][2]={{-1,-1},{-1,0},{-1,+1},{0,-1},{0,+1},{+1,-1},{+1,0},{+1,+1}};
	//check its neighbours
	for(int z=0;z<8;z++)
	{
		int new_i=i+directions[z][0];
		int new_j=j+directions[z][1];
		int val=getVal(a,new_i,new_j,maxRow,maxCol);
		if(val>0 && cnt[new_i][new_j]==0){
			connectedCells(a,new_i,new_j,maxRow,maxCol,size,cnt,mxSize);
		}
	}
	cnt[i][j]=0;
}
int maxOnes(vector<vector<int>> &a,int maxRow,int maxCol)
{
	int size=0;
	int mxSize=0;
	vector<vector<int>> cnt( maxRow , vector<int> (maxCol, 0));
	for(int x=0;x<maxRow;x++)
	{
		for(int y=0;y<maxCol;y++)
		{
			if(a[x][y]==1){
				connectedCells(a,x,y,maxRow,maxCol,size,cnt,mxSize);
			}
		}
	}
	return mxSize;
}
int main()
{
	vector<vector<int>> a{{1,1,0,0,0},{0,1,1,0,0},{0,0,1,0,1},{1,0,0,0,1},{0,1,0,1,1}};
	cout<<maxOnes(a,a.size(),a[0].size())<<endl;
	return 0;
}