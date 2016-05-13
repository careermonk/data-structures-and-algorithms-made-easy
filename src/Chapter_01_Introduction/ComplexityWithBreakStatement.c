//=========================================================================
// Copyright (c) Dec 22, 2014 CareerMonk Publications and others.
// E-Mail           		: info@careermonk.com
// Creation Date    		: 2014-01-10 06:15:46
// Last modification		: 2008-10-31
//               by			: Narasimha Karumanchi
// Book Title				: Data Structures And Algorithms made Easy
// Warranty         		: This software is provided "as is" without any
// 				   				warranty; without even the implied warranty of
// 				    			merchantability or fitness for a particular purpose.
//=========================================================================

int functionWithBreak(int n){
	int count = 0;
	int i = 0,j;
	for(i=n/2;i<n;i++){
		j = 1;
		count++;
		while (j+n/2 <=n){
			break;
			j = j * 2;
		}
	}
    printf("%d\n", count);
}
int functionWithBreak_test(){
	int n = 20;
	functionWithBreak(n);
}
