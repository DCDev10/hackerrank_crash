
#include <bits/stdc++.h>
using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'gradingStudents' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts INTEGER_ARRAY grades as parameter.
 */
vector<int> gradingStudents(vector<int> grades) {
  for (int &grade : grades) {
    if (grade >= 38) {
      int nextMultipleOfFive = ((grade / 5) + 1) * 5;
      if (nextMultipleOfFive - grade < 3) {
        grade = nextMultipleOfFive;
      }
    }
  }
  return grades;
}

int main() {
  string grades_count_temp;
  getline(cin, grades_count_temp);

  int grades_count = stoi(ltrim(rtrim(grades_count_temp)));
  vector<int> grades(grades_count);

  for (int i = 0; i < grades_count; i++) {
    string grades_item_temp;
    getline(cin, grades_item_temp);
    grades[i] = stoi(ltrim(rtrim(grades_item_temp)));
  }

  vector<int> result = gradingStudents(grades);

  for (size_t i = 0; i < result.size(); i++) {
    cout << result[i] << (i != result.size() - 1 ? "\n" : "");
  }
  cout << endl;

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
