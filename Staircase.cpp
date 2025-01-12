
#include <bits/stdc++.h>
using namespace std;

string ltrim(const string &str);
string rtrim(const string &str);

/*
 * Complete the 'staircase' function below.
 *
 * The function accepts INTEGER n as parameter.
 */
void staircase(int n) {
  for (int i = 0; i < n; i++) {
    cout << string(n - i - 1, ' ') << string(i + 1, '*') << endl;
  }
}

int main() {
  string n_temp;
  getline(cin, n_temp);

  int n = stoi(ltrim(rtrim(n_temp)));

  staircase(n);

  return 0;
}

string ltrim(const string &str) {
  string s(str);

  s.erase(s.begin(), find_if(s.begin(), s.end(), std::not_fn(::isspace)));

  return s;
}

string rtrim(const string &str) {
  string s(str);

  s.erase(find_if(s.rbegin(), s.rend(), std::not_fn(::isspace)).base(),
          s.end());

  return s;
}
