
#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'theGreatXor' function below.
 *
 * The function is expected to return a LONG_INTEGER.
 * The function accepts LONG_INTEGER x as parameter.
 */

long theGreatXor(long x) {
  int bitCount = 1;
  long sum = 0;

  while (x > 0) {
    if ((x & 1) == 0) {
      sum += 1L << (bitCount - 1);
    }
    bitCount++;
    x = x >> 1;
  }

  return sum;
}

// long theGreatXor(long x) {
//   int bitCount = 1;
//   long lesser = 0;

//   if (x == 1) {
//     return 0;
//   }
//   while (x > 1) {
//     if ((x & 1) == 1) {
//       lesser += 1L << (bitCount - 1);
//     }
//     bitCount++;
//     x = x >> 1;
//   }

//   return (1L << (bitCount - 1)) - 1 - lesser;
// }

int main() {
  ofstream fout(getenv("OUTPUT_PATH"));

  string q_temp;
  getline(cin, q_temp);

  int q = stoi(ltrim(rtrim(q_temp)));

  for (int q_itr = 0; q_itr < q; q_itr++) {
    string x_temp;
    getline(cin, x_temp);

    long x = stol(ltrim(rtrim(x_temp)));

    long result = theGreatXor(x);

    cout << result << "\n";
  }

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
