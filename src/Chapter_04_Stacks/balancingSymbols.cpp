/*
   Author : Shivam Chauhan
   Date   : Feb 26 , 2019
   Balancing Symbols Implementation
*/
#include <bits/stdc++.h>
using namespace std ;
bool isBalanced( string str )
{
	stack<char>s;
	char ch ;
	for ( auto c : str )
	{
		switch(c)
		{
			case '[' :
			case '{' :
			case '(' : s.push(c);			
						break;
			case ']' : if( s.empty() || s.top() != '[')
						{
							return false;
						} 
						s.pop();
						break;
			case '}' : if( s.empty() || s.top() != '{')
						{
							return false;
						} 
						s.pop();
						break;
			case ')' : if( s.empty() || s.top() != '(')
						{
							return false;
						} 
						s.pop();
						break;
		}
	} 
	return s.empty();
}
int main()
{	
	string str  = "{{[]()}}";
	if( isBalanced(str) )
	{
		cout << "balanced" << endl ;
	}
	else
	{
		cout << "not balanced" << endl ;		
	}
	return 0;
}

