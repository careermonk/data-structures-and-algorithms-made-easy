/*
   Author : Shivam Chauhan
   Date   : Feb 28 , 2019
   Finding the Span
*/

#include <bits/stdc++.h>
using namespace std;
void getSpan( int span[] , int n )
{
	stack<int>s;
	int calculatedSpan[n] , price ;
	for ( int i = 0 ; i < n ; i++ )
	{
		while( !s.empty() && span[s.top()] <= span[i] )
		{
			s.pop();
		}
		calculatedSpan[i] = i - ( s.empty() ? -1 : s.top() ) ;
		s.push(i);
	}
	for( int i = 0 ; i < n ; i++ )
	{
		cout << calculatedSpan[i] << " ";
	}
	cout << endl ;	
}
int main()
{
	int n ;
	cin >> n ;
	int span[n];
	for ( int i = 0 ; i < n ; i++ )
	{
		cin >> span[i];
	}
	getSpan(span,n);
	return 0 ;
}