#include <iostream>
using namespace std;

int main() {
  int n, t;
  cin >> n >> t;

  int c[n], r[n], count = 0, valid[n];

  for (int i = 0; i < n; i++)
    cin >> c[i];
  for (int i = 0; i < n; i++)
    cin >> r[i];

  // checks if there are colors equal to T
  for (int i = 0; i < n; i++) {
    if (c[i] == t) {
      count++;
      valid[i] = i;
    }
  }

  if (count > 0) {

    int max = valid[0];
    for (int i = 1; i < count; i++) {
      if (valid[i] > max)
        max = valid[i];
    }

    cout << max;
  }
}