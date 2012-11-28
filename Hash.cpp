#include "Hash.h"

template <typename V>
Hash<V>::Hash() {
  size = 101;
  table.resize(size);
}

template <typename V>
void Hash<V>::insert(string k, V v) {
  Entry<V> newEntry = Entry<V>(k, v);
  int x = hash(k);
  table[x].push_back(newEntry);
}

template <typename V>
bool Hash<V>::find(string k) {
  int x = hash(k);

  for (int i = 0; i < (int) table[x].size(); ++i) {
    if (table[x][i].getKey() == k) {
      cout << "Found, with a value of: " << table[x][i].getValue() << endl;
      return true;
    }
  }

  cout << "Key not found" << endl;
  return false;
}

template <typename V>
void Hash<V>::remove(string k) {
  int x = hash(k);

  for (int i = 0; i < (int) table[x].size(); ++i) {
    if (table[x][i].getKey() == k)
      table[x].erase(table[x].begin() + i);
  }
}

template <typename V>
int Hash<V>::hash(string s) {
  int hash;
  int sum = 0;

  for (int i = 0; i < (int) s.size(); ++i) {
    sum += (int) s[i];
  }

  hash = sum%size;

  return hash;
}

template class Hash<int>;
template class Hash<double>;
template class Hash<string>;
