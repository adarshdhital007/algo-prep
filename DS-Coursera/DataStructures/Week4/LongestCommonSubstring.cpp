
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

class Solver {
public:
  Solver(string str) : str(str), hashes1(str.size() + 1), hashes2(str.size() + 1) {
    for (int i = 0; i < str.size(); i++) {
      hashes1[i + 1] = (hashes1[i] * multiplier + str[i]) % prime1;
      hashes2[i + 1] = (hashes2[i] * multiplier + str[i]) % prime2;
    }
  }

  bool check_equality(int a, int b, int l) {
    if (l == 0) {
      return true;
    } else {
      int hash1_a = (hashes1[a + l] - 1LL * hashes1[a] * powerMod(multiplier, l, prime1) % prime1 + prime1) % prime1;
      int hash1_b = (hashes1[b + l] - 1LL * hashes1[b] * powerMod(multiplier, l, prime1) % prime1 + prime1) % prime1;

      int hash2_a = (hashes2[a + l] - 1LL * hashes2[a] * powerMod(multiplier, l, prime2) % prime2 + prime2) % prime2;
      int hash2_b = (hashes2[b + l] - 1LL * hashes2[b] * powerMod(multiplier, l, prime2) % prime2 + prime2) % prime2;

      return (hash1_a == hash1_b) && (hash2_a == hash2_b);
    }
  }

private:
  string str;
  vector<int> hashes1;
  vector<int> hashes2;

  const int multiplier = 273;
  const int prime1 = 1000000007;
  const int prime2 = 1000000009;

  // Custom modular exponentiation function
  long long powerMod(long long base, long long exp, long long modulus) {
    long long result = 1;
    base %= modulus;
    while (exp > 0) {
      if (exp & 1)
        result = (result * base) % modulus;
      base = (base * base) % modulus;
      exp >>= 1;
    }
    return result;
  }
};

int main() {
  string str;
  int n_queries;

  cin >> str >> n_queries;

  Solver solver(str);

  for (int i = 0; i < n_queries; i++) {
    int a, b, l;
    cin >> a >> b >> l;

    cout << (solver.check_equality(a, b, l) ? "Yes" : "No") << endl;
  }

  return 0;
}
