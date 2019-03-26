#include <bits/stdc++.h>
using namespace std;

// Function returning the max area under the histogram
int largestArea(int hist[],int n)
{
	stack <int> index ;
	int currentArea , maxArea = -1 ;
	int left , top ;
	for ( int i = 0 ; i <= n ; i++)
	{
		while( !index.empty() && (i == n || hist[index.top()] > hist[i]) )
		{
			// Calculating the nearest smallest pillar
			if ( index.size() > 1 )
			{
				top = index.top();
				index.pop();
				left = index.top();
			}
			// Case of only one element
			else
			{
				left = -1 ;
				top = index.top() ;
				index.pop();
			}
			currentArea = hist[top] * ( i - left - 1) ;
			// Updating the maxArea if condition evaluates out to be true
			maxArea = maxArea < currentArea ? currentArea : maxArea ;
		}
		if( i < n )
		{
			index.push(i);
		}
	}
	return maxArea ;
}

int main()
{
	// Array containing the heights of the various histogram
	int arr[] = { 3, 2, 5, 6, 1, 4, 4 };
	// sizeof(arr)/sizeof(arr[0]) gives the size of the array i.e. 7 in this case
	cout << largestArea(arr,sizeof(arr)/sizeof(arr[0])) << endl ;
	return 0 ;
}
