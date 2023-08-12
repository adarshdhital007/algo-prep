#include <iostream>
#include <vector>

using namespace std;

int getFibonacciLastDigit(int n) {
    if (n <= 1) {
        return n;
    }

    vector<int> fibLastDigit(n + 1);
    fibLastDigit[0] = 0;
    fibLastDigit[1] = 1;

    for (int i = 2; i <= n; ++i) {
        fibLastDigit[i] = (fibLastDigit[i - 1] + fibLastDigit[i - 2]) % 10;
    }

    return fibLastDigit[n];
}

int main() {
    int n;
    cin >> n;

    int lastDigit = getFibonacciLastDigit(n);
    cout << lastDigit << endl;

    return 0;
}
