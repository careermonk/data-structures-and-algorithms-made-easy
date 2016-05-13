/*Copyright (c) 2016 CareerMonk Publications and others.
#E-Mail            : info@careermonk.com 
#Creation Date     : 2008-01-10 06:15:46 
#Created by        : Narasimha Karumanchi 
#Book Title        : Data Structures And Algorithms Made Easy
#Warranty          : This software is provided "as is" without any 
#                    warranty; without even the implied warranty of 
#                    merchantability or fitness for a particular purpose.*/

int table[256];
void buildTable(void){
    int i;
    for(i = 0; i < 256; i++){
        unsigned char t = i;
        table[i] = 0;
        for(int j = 0; j < 8; j++){
            if(t & 1) table[i]++;
            t >>= 1;
        }
    }
}
int countingNumberofOneswithPreprocessing(unsigned int n){
    int count = 0;
    for(; n; n >>= 4)
        count = count + table[n & 0xf];
    return count;
}
void countingNumberofOneswithPreprocessing_test(){
    buildTable();
    int i=10;
    printf("Number of one's in %d is/are %d\n",i, countingNumberofOneswithPreprocessing(i));
    i = 5;
    printf("Number of one's in %d is/are %d\n",i, countingNumberofOneswithPreprocessing(i));
    i = 100;
    printf("Number of one's in %d is/are %d\n",i, countingNumberofOneswithPreprocessing(i));
    i = 1;
    printf("Number of one's in %d is/are %d\n",i, countingNumberofOneswithPreprocessing(i));
    i = 0;
    printf("Number of one's in %d is/are %d\n",i, countingNumberofOneswithPreprocessing(i));    
}