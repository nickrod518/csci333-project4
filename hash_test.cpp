#include "Hash.h"

int main() {
  Hash<int> table;

  table.insert("hello", 5);
  cout << table.find("hello") << endl;

  table.remove("hello");
  cout << table.find("hello") << endl;

  return 0;
}
