#include <iostream>
#include <algorithm>
using namespace std;

bool isPossible(int stalls[], int n, int c, int minDist) {
    int lastPos = stalls[0];
    int count = 1;

    for (int i = 1; i < n; i++) {
        if (stalls[i] - lastPos >= minDist) {
            count++;
            lastPos = stalls[i];
            if (count == c) return true;
        }
    }
    return false;
}

int aggressiveCows(int stalls[], int n, int c) {
    sort(stalls, stalls + n);

    int low = 1;
    int high = stalls[n-1] - stalls[0];
    int result = 0;

    while (low <= high) {
        int mid = low + (high - low)/2;

        if (isPossible(stalls, n, c, mid)) {
            result = mid;
            low = mid + 1; // try for bigger distance
        } else {
            high = mid - 1; // reduce distance
        }
    }

    return result;
}

int main() {
    int stalls[] = {1, 2, 8, 4, 9};
    int n = sizeof(stalls)/sizeof(stalls[0]);
    int c = 3; // number of cows

    cout << "Largest minimum distance = " << aggressiveCows(stalls, n, c) << endl;
    return 0;
}
