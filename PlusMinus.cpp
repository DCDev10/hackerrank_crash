
#include <bits/stdc++.h>
using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'plusMinus' function below.
 *
 * The function accepts INTEGER_ARRAY arr as parameter.
 */
void plusMinus(vector<int> arr) {
  double pos = 0, neg = 0, zero = 0;
  int size = arr.size();

  for (int num : arr) {
    if (num > 0) {
      pos++;
    } else if (num < 0) {
      neg++;
    } else {
      zero++;
    }
  }

  // Tính tỉ lệ và in kết quả
  cout << fixed << setprecision(6) << pos / size << endl;
  cout << fixed << setprecision(6) << neg / size << endl;
  cout << fixed << setprecision(6) << zero / size << endl;
}

int main() {
  string n_temp;
  getline(cin, n_temp);

  int n = stoi(ltrim(rtrim(n_temp)));

  string arr_temp_temp;
  getline(cin, arr_temp_temp);

  vector<string> arr_temp = split(rtrim(arr_temp_temp));
  vector<int> arr(n);

  for (int i = 0; i < n; i++) {
    arr[i] = stoi(arr_temp[i]);
  }

  plusMinus(arr);
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

vector<string> split(const string &str) {
  vector<string> tokens;
  stringstream ss(str);
  string item;

  while (getline(ss, item, ' ')) {
    tokens.push_back(item);
  }

  return tokens;
}
