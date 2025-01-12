#include <bits/stdc++.h>
#include <string>

using namespace std;

/*
 * Complete the 'timeConversion' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

string timeConversion(string s) {
  int hour = stoi(s.substr(0, 2));
  string ampm = s.substr(8, 2);
  string result = s.substr(2, 6);

  if (ampm == "AM") {
    if (hour == 12) {
      hour = 0;
    }
  }

  if (ampm == "PM") {
    if (hour != 12) {
      hour += 12;
    }
  }

  result = (hour < 10 ? "0" : "") + to_string(hour) + result;
  return result;
}

int main() {
  ofstream fout(getenv("OUTPUT_PATH"));

  string s;
  getline(cin, s);

  string result = timeConversion(s);

  fout << result << "\n";

  fout.close();

  return 0;
}
