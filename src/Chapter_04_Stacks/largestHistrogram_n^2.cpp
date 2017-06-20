#include <iostream>
#include <vector>
using namespace std;

int largestHistrogram(vector<int> &A) {
    int maxArea = 0;
    for (int i = 0; i < A.size(); i++) {
        for (int j = i, minimum_height = A[i]; j < A.size(); j++) {
            minimum_height = min(minimum_height, A[j]);
            maxArea = max(maxArea, (j-i+1) * minimum_height);
        }
    }
    return maxArea;
}

int main() {
	vector <int> A;        
    A.push_back(6);        
    A.push_back(2);       
    A.push_back(5);
    A.push_back(4);        
    A.push_back(5);       
    A.push_back(1);   
    A.push_back(6);   
	printf("largestRectangleArea: %d", largestHistrogram(A));
	return 0;
}
