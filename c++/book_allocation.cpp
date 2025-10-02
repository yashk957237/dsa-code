#include <iostream>
#include <algorithm>
using namespace std;

// Helper function
bool isPossible(int A[], int n, int m, int maxPages) {
    int studentsRequired = 1;
    int currSum = 0;

    for (int i = 0; i < n; i++) {
        if (A[i] > maxPages) return false;
        if (currSum + A[i] > maxPages) {
            studentsRequired++;
            currSum = A[i];
            if (studentsRequired > m) return false;
        } else {
            currSum += A[i];
        }
    }
    return true;
}

// Main function to find minimum maximum pages
int allocateBooks(int A[], int n, int m) {
    if (m > n) return -1; // More students than books

    int sum = 0, maxBook = 0;
    for (int i = 0; i < n; i++) {
        sum += A[i];
        maxBook = max(maxBook, A[i]);
    }

    int low = maxBook, high = sum;
    int result = -1;

    while (low <= high) {
        int mid = low + (high - low)/2;
        if (isPossible(A, n, m, mid)) {
            result = mid;
            high = mid - 1; // try to minimize
        } else {
            low = mid + 1; // increase limit
        }
    }

    return result;
}

// Driver code
int main() {
    int A[] = {12, 34, 67, 90};
    int n = sizeof(A)/sizeof(A[0]);
    int m = 2; // number of students

    cout << "Minimum maximum pages = " << allocateBooks(A, n, m) << endl;
    return 0;
}
