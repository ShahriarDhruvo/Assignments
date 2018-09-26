#include <stdio.h>
#include <string.h>
#include <iostream>

using namespace std;

int match(char [], char []);

int main() {
  char a[100], b[100];
  int position;

  cout << "Enter The string: ";
  cin >> a;

  cout << "Enter the substring to which you want to find: ";
  cin >> b;

  position = match(a, b);

  if(position != -1) {
    cout << "Found at location " << position + 1 << endl;
  }
  else {
    cout << "Not found." << endl;
  }
}

int match(char str[], char sub[]) {
  int c, d, e, ln1, ln2, position = -1;

  ln1 = strlen(str);
  ln2 = strlen(sub);

  if (ln2 > ln1) {
    return -1;
  }

  for (c = 0; c <= ln1 - ln2; c++) {
    position = e = c;

    for (d = 0; d < ln2; d++) {
      if (sub[d] == str[e]) {
        e++;
      }
      else {
        break;
      }
    }
    if (d == ln2) {
      return position;
    }
  }

  return -1;
}
