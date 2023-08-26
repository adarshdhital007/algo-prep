#include <iostream>
#include <vector>

using namespace std;

int binarySearch(const vector<int>& arr, int target) {
    int left = 0;
    int right = arr.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            return mid;
        } else if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return -1; // Element not found
}

int main() {
    int n;
    cin >> n;
    vector<int> sortedArray(n);
    for (int i = 0; i < n; ++i) {
        cin >> sortedArray[i];
    }

    int m;
    cin >> m;
    vector<int> queries(m);
    for (int i = 0; i < m; ++i) {
        cin >> queries[i];
    }

    // Process queries and output results
    for (int i = 0; i < m; ++i) {
        int queryIndex = binarySearch(sortedArray, queries[i]);
        cout << queryIndex << " ";
    }

    return 0;
}
