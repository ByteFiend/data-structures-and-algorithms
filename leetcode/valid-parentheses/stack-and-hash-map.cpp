#include <iostream>
#include <string>
#include <stack>
#include <queue>
#include <deque>
#include <vector>
#include <assert.h>
#include <unordered_map>

using namespace std;

class Solution {
public:
  bool isValid(string s) {
    unordered_map<char, char> table;
    table.insert(std::make_pair(')', '('));
    table.insert(std::make_pair(']', '['));
    table.insert(std::make_pair('}', '{'));

    stack<char> to_pair;
    for (string::iterator itr = s.begin(); itr != s.end(); ++itr){
      if ('(' == *itr || '[' == *itr || '{' == *itr){
        to_pair.push(*itr);

      } else {
        unordered_map<char, char>::iterator found = table.find(*itr);
        if (table.end() == found){
          return false;

        } else {
          if (!to_pair.empty() && found->second == to_pair.top()){
            to_pair.pop();

          } else {
            return false;
          }
        }
      }
    }

    return to_pair.empty();
  }
};

struct Case {
  string str;
  bool expected;
};

int main(){
  vector<Case> cases;
  string str;
  bool expected;
  Solution s;

  str = "";
  expected = true;
  cases.push_back(Case{str, expected});

  str = "p";
  expected = false;
  cases.push_back(Case{str, expected});

  str = "(";
  expected = false;
  cases.push_back(Case{str, expected});

  str = "[";
  expected = false;
  cases.push_back(Case{str, expected});

  str = "{";
  expected = false;
  cases.push_back(Case{str, expected});

  str = ")";
  expected = false;
  cases.push_back(Case{str, expected});

  str = "]";
  expected = false;
  cases.push_back(Case{str, expected});

  str = "}";
  expected = false;
  cases.push_back(Case{str, expected});

  str = "()";
  expected = true;
  cases.push_back(Case{str, expected});

  str = "[]";
  expected = true;
  cases.push_back(Case{str, expected});

  str = "{}";
  expected = true;
  cases.push_back(Case{str, expected});

  str = ")(";
  expected = false;
  cases.push_back(Case{str, expected});

  str = "][";
  expected = false;
  cases.push_back(Case{str, expected});

  str = "}{";
  expected = false;
  cases.push_back(Case{str, expected});

  str = "()(";
  expected = false;
  cases.push_back(Case{str, expected});

  str = "(()";
  expected = false;
  cases.push_back(Case{str, expected});

  str = ")((";
  expected = false;
  cases.push_back(Case{str, expected});

  str = "([)]";
  expected = false;
  cases.push_back(Case{str, expected});

  str = "()[]";
  expected = true;
  cases.push_back(Case{str, expected});

  for (int i = 0; i < cases.size(); ++i){
    assert(cases[i].expected == s.isValid(cases[i].str));
    cout << "Pass case " << i << endl;
  }
}
