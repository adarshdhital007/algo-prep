#include<bits/stdc++.h>
using namespace std;

long long get_fibonacci_huge_naive(long long n, long long m) {
    if (n <= 1) return n;

    long long previous = 0;
    long long current = 1;

    for (long long i = 2; i <= n; ++i) {
        long long tmp = (previous + current) % m;
        previous = current;
        current = tmp;
    }

    return current;
}


long long get_fibonacci_huge(long long n, long long m) {
	if (n <= 1) return n;

	long long previous = 0;
	long long current = 1;
	long long tmp_previous = 0;

	vector<long> pisano;
	pisano.push_back(0);
	pisano.push_back(1);

	while (true) {
		tmp_previous = previous;
		previous = current;
		current = (tmp_previous + current) % m;
		if (current == 1 and previous == 0) {
			break;
		} else {
			pisano.push_back(current);
		}
	}
	pisano.pop_back();
	long index = n % pisano.size();
	return pisano.at(index);
}

int main() {
	long long n, m;
	cin >> n >> m;
	//cout << get_fibonacci_huge_naive(n, m) << '\n';
	cout << get_fibonacci_huge(n, m) << '\n';
}