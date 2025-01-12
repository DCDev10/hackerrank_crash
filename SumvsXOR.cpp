#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'sumXor' function below.
 *
 * The function is expected to return a LONG_INTEGER.
 * The function accepts LONG_INTEGER n as parameter.
 */

long sumXor(long n) {
  if (n == 0) {
    return 1;
  }

  int count = 0;

  while (n > 0) {
    if ((n & 1) == 0) {
      count++;
    }
    n = n >> 1;
  }

  return 1L << count;
}

int main() {
  ofstream fout(getenv("OUTPUT_PATH"));

  string n_temp;
  getline(cin, n_temp);

  long n = stol(ltrim(rtrim(n_temp)));

  long result = sumXor(n);

  fout << result << "\n";

  fout.close();

  return 0;
}

string ltrim(const string &str) {
  string s(str);
  s.erase(s.begin(), find_if(s.begin(), s.end(),
                             [](unsigned char ch) { return !isspace(ch); }));
  return s;
}

string rtrim(const string &str) {
  string s(str);
  s.erase(find_if(s.rbegin(), s.rend(),
                  [](unsigned char ch) { return !isspace(ch); })
              .base(),
          s.end());
  return s;
}
