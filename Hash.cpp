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
  bool exist = false;

  for (int i = 0; i < (int) table[x].size(); ++i) {
    if (table[x][i].getKey() == k) {
      exist = true;
      table[x][i].setValue(v);
    }
  }

  if (!exist)
    table[x].push_back(newEntry);
}

template <typename V>
V Hash<V>::find(string k) {
  int x = hash(k);

  for (int i = 0; i < (int) table[x].size(); ++i) {
    if (table[x][i].getKey() == k)
      return table[x][i].getValue();
  }

  // if not found, return 0 casted as type V
  cout << "Key not found" << endl;
  return (V) 0;
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

  for (int i = 0; i < (int) s.size(); ++i)
    sum += (int) s[i];

  hash = sum%size;

  return hash;
}

template class Hash<int>;
template class Hash<double>;
template class Hash<string>;
