
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

long long modularExponentiation(long long base, long long exponent, long long modulus) {
    long long result = 1;
    while (exponent > 0) {
        if (exponent % 2 == 1) {
            result = (result * base) % modulus;
        }
        base = (base * base) % modulus;
        exponent /= 2;
    }
    return result;
}

vector<long long> HashTable(const string& s, long long prime, int x) {
    vector<long long> hash_table(s.length() + 1, 0);
    for (int i = 1; i <= s.length(); i++) {
        hash_table[i] = (hash_table[i - 1] * x + s[i - 1]) % prime;
    }
    return hash_table;
}

long long HashValue(const vector<long long>& hash_table, long long prime, int x, int start, int length) {
    long long y = modularExponentiation(x, length, prime);
    long long hash_value = (hash_table[start + length] - (y * hash_table[start]) % prime + prime) % prime;
    return hash_value;
}

string AreEqual(const vector<long long>& table1, const vector<long long>& table2, long long prime1, long long prime2, int x, int a, int b, int l) {
    long long a_hash1 = HashValue(table1, prime1, x, a, l);
    long long a_hash2 = HashValue(table2, prime2, x, a, l);
    long long b_hash1 = HashValue(table1, prime1, x, b, l);
    long long b_hash2 = HashValue(table2, prime2, x, b, l);
    if (a_hash1 == b_hash1 && a_hash2 == b_hash2) {
        return "Yes";
    }
    else {
        return "No";
    }
}

int main() {
    string s;
    cin >> s;
    int n_queries;
    cin >> n_queries;
    long long m = 1000000007;
    long long m2 = 1000000009;
    int x = 263;
    vector<long long> hash_table1 = HashTable(s, m, x);
    vector<long long> hash_table2 = HashTable(s, m2, x);
    for (int i = 0; i < n_queries; i++) {
        int a, b, l;
        cin >> a >> b >> l;
        cout << AreEqual(hash_table1, hash_table2, m, m2, x, a, b, l) << endl;
    }
    return 0;
}
