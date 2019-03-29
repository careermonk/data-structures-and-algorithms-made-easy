/*
   Author : Shivam Chauhan
   Date   : Feb 27 , 2019
   Infix to Postfix Implementation
*/
#include <bits/stdc++.h>
using namespace std ;
int getPriority(char ch )
{
	switch(ch)
	{
		case '+' :	
		case '-' :	return 1;
					break;
		case '*' :	
		case '/' :	return 2;
					break;

		case '^' :	return 3;
					break;

		default  :  return 0 ;
					break ;

	}
}
string infix_to_postfix(string str )
{
	stack<char>s;
	string result = "";
	for ( auto c : str)
	{
		if( ( c >= 'a' && c <= 'z' ) || (c >= 'A' && c <= 'Z') )
		{
			result += c ;
		}
		else if ( c == ')')
		{
			while ( !s.empty() && s.top() != '(' )
			{
				result += s.top();
				s.pop();
			}
			if( !s.empty() && s.top() == '(' ) s.pop() ;
		}
		else
		{
			while( !s.empty() && getPriority(s.top()) >= getPriority(c) && c != '(')
			{
				result += s.top();
				s.pop();
			}
			s.push(c);
		}
	}
	while(!s.empty())
	{
		result += s.top(); 
		s.pop();
	}
	return result ;
}

int main()
{
	string str = "(A+B)/(C+D)";
	cout << infix_to_postfix(str) << endl ;
	return 0 ;
}