/*
   Author : Shivam Chauhan
   Date   : Feb 27 , 2019
   String is Pallindrome or Not
*/
#include <bits/stdc++.h>
using namespace std;
string isPallindrome(string str)
{
	stack<char>stck;
	int i = 0 ;
	while( str[i] != 'X' )
	{
		stck.push(str[i]); 
		i++ ;
	}
	i++;
	while(str[i])
	{
		if( stck.empty() || str[i] != stck.top() )
		{
			return "Not Pallindrome";
		}
		else
		{
			stck.pop();
		}
		i++;
	}			
	return stck.empty() ? "Pallindrome" : "Not Pallindrome" ;
}
int main()
{
	string str = "ABCXCBA"; // Left and right part of X are taken into account for pallindrome evaluation
	cout << isPallindrome(str) << endl ;
	return 0 ;
}