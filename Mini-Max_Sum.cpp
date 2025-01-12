#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'miniMaxSum' function below.
 *
 * The function accepts INTEGER_ARRAY arr as parameter.
 */

void miniMaxSum(vector<int> arr) {
  unsigned long minIndex = arr[0];
  unsigned long maxIndex = arr[0];
  unsigned long sum = 0;
  for (int i = 0; i < arr.size(); i++) {
    sum += arr[i];
    if (minIndex > arr[i]) {
      minIndex = arr[i];
    }
    if (maxIndex < arr[i]) {
      maxIndex = arr[i];
    }
  }

  cout << sum - maxIndex << " " << sum - minIndex;
}

int main() {
  string arr_temp_temp;
  getline(cin, arr_temp_temp);

  vector<string> arr_temp = split(rtrim(arr_temp_temp));

  vector<int> arr(5);

  for (int i = 0; i < 5; i++) {
    int arr_item = stoi(arr_temp[i]);
    arr[i] = arr_item;
  }

  miniMaxSum(arr);

  return 0;
}

string ltrim(const string &str) {
  string s(str);

  // Sử dụng std::not_fn với ::isspace
  s.erase(s.begin(), find_if(s.begin(), s.end(), not_fn(::isspace)));

  return s;
}

string rtrim(const string &str) {
  string s(str);

  // Sử dụng std::not_fn với ::isspace
  s.erase(find_if(s.rbegin(), s.rend(), not_fn(::isspace)).base(), s.end());

  return s;
}

vector<string> split(const string &str) {
  vector<string> tokens;

  string::size_type start = 0;
  string::size_type end = 0;

  while ((end = str.find(" ", start)) != string::npos) {
    tokens.push_back(str.substr(start, end - start));

    start = end + 1;
  }

  tokens.push_back(str.substr(start));

  return tokens;
}
