#include<bits/stdc++.h>
using namespace std;
int main(){
  int a[5][5];
  int i, j, result = 0;

  for (i = 0; i < 5; i++) {
    for (j = 0; j < 5; j++) {
      cin >> a[i][j];
      if (a[i][j] == 1) {
        result = abs(i - 2) + abs(j - 2);
      }
    }
  }

  cout << result;
  return 0;
}