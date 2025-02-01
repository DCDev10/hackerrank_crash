#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'dayOfProgrammer' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts INTEGER year as parameter.
 */

bool isLeapYear(int year) {
  bool result = false;
  if (year < 1918 && (year % 4 == 0)) {
    result = true;
  } else if (year > 1918 &&
             (year % 400 == 0 || ((year % 4 == 0) && (year % 100 != 0)))) {
    result = true;
  } else {
    result = false;
  }

  return result;
}

string dayOfProgrammer(int year) {
  int monthOfYear = 0;
  int dayOfMonth = 0;
  string result;
  if (year == 1918) {
    monthOfYear = 9;
    dayOfMonth = 26;
  } else {
    if (isLeapYear(year)) {
      monthOfYear = 9;
      dayOfMonth = 12;
    } else {
      monthOfYear = 9;
      dayOfMonth = 13;
    }
  }

  std::ostringstream oss;
  oss << std::setw(2) << std::setfill('0') << dayOfMonth << "." << std::setw(2)
      << std::setfill('0') << monthOfYear << "." << year;

  result = oss.str();

  return result;
}

int main() {
  ofstream fout(getenv("OUTPUT_PATH"));

  string year_temp;
  getline(cin, year_temp);

  int year = stoi(ltrim(rtrim(year_temp)));

  string result = dayOfProgrammer(year);

  fout << result << "\n";

  fout.close();

  return 0;
}

string ltrim(const string &str) {
  string s(str);

  s.erase(s.begin(),
          find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace))));

  return s;
}

string rtrim(const string &str) {
  string s(str);

  s.erase(
      find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
      s.end());

  return s;
}
