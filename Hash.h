#ifndef __HASH_H__
#define __HASH_H__

#include "Entry.h"
#include <vector>
#include <iostream>

using std::vector;
using std::cout;
using std::endl;

template <typename V>
class Hash {
  private:
    vector< vector< Entry<V> > > table;
    int size;
    int hash(string s);

  public:
    Hash<V>();
    void insert(string k, V v);
    V find(string k);
    void remove(string k);
};

#endif
