#include "Entry.h"
#include <iostream>

using std::cout;
using std::endl;

int main() {
  Entry<string> s = Entry<string>("hello", "world");

  cout << "Key: " << s.getKey() << endl;
  cout << "Value: " << s.getValue() << endl;;

  return 0;
}
