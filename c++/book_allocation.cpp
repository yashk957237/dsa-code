// Problem: Book Allocation - Allocate minimum pages to each student
// Given an array of page counts and the number of students, find the minimum maximum pages any student can be assigned.
#include <bits/stdc++.h>
using namespace std;

bool canAllocate(vector<int>& pages, int students, int maxPages) {
    int count = 1;
    int currPages = 0;
    for (int page : pages) {
        if (currPages + page <= maxPages) {
            currPages += page;
        } else {
            count++;
            currPages = page;
            if (page > maxPages) return false;
        }
    }
    return count <= students;
}

int bookAllocation(vector<int>& pages, int students) {
    if (pages.size() < students) return -1;
    int left = *max_element(pages.begin(), pages.end());
    int right = accumulate(pages.begin(), pages.end(), 0);
    int result = INT_MAX;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (canAllocate(pages, students, mid)) {
            result = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return result;
}

int main() {
    vector<int> pages = {10, 20, 30, 40};
    int students = 2;
    cout << bookAllocation(pages, students) << endl;
    return 0;
}