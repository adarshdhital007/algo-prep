#include <iostream>
#include <vector>

using namespace std;

int binarysearch(const vector<int>& arr, int target) {
    int left = 0;
    int right = arr.size() - 1;
    int result=-1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) {
            result=mid;
            right=mid-1;
        } else if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return result;
}

int main() {
    int n,m;

    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    cin >> m;
    vector<int> queries(m);
    for (int i = 0; i < m; ++i) {
        cin >> queries[i];
    }

    for (int i = 0; i < m; ++i) {
        int queryIndex = binarysearch(arr, queries[i]);
        cout << queryIndex << " ";
    }

    return 0;
}
