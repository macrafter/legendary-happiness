#include <iostream>
#include <string>
using namespace std;

int main() {
  int n;
  string s;

  cin >> n >> s;

  bool out = true;

  for(int i = 0;i < n; i++) {
    if(s[i] == '*') {
      
      if(out)
        cout << "out";
      else
        cout << "in";
      
      return 0;
    }

    if(s[i] == '|')
      out = !out;
  }
}