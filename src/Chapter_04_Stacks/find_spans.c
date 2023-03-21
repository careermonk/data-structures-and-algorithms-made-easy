// Copyright (c) 2008 CareerMonk Publications and others.
// #E-Mail          : info@careermonk.com
// Creation Date    : 2008-01-10 06:15:46
// Created by       : Narasimha Karumanchi
// Book Title       : Data Structures And Algorithms Made Easy
// Warranty         : This software is provided "as is" without any
//                    warranty; without even the implied warranty of
//                    merchantability or fitness for a particular purpose.

#include <stdio.h>
#include <stdlib.h>

#define MAX_N 100000

int stack[MAX_N], top = -1;

int largest_rectangle_area(int heights[], int n) {
    int max_area = 0, i = 0;
    while (i < n) {
        if (top == -1 || heights[i] >= heights[stack[top]]) {
            stack[++top] = i++;
        } else {
            int top_index = stack[top--];
            int area = heights[top_index] * (top == -1 ? i : i - stack[top] - 1);
            if (area > max_area) {
                max_area = area;
            }
        }
    }
    while (top != -1) {
        int top_index = stack[top--];
        int area = heights[top_index] * (top == -1 ? i : i - stack[top] - 1);
        if (area > max_area) {
            max_area = area;
        }
    }
    return max_area;
}

int main() {
    int n, heights[MAX_N];
    printf("Enter the number of bars in the histogram: ");
    scanf("%d", &n);
    printf("Enter the heights of the bars:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &heights[i]);
    }
    int max_area = largest_rectangle_area(heights, n);
    printf("The largest rectangle under the histogram has area %d\n", max_area);
    return 0;
}
