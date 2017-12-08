#ifndef A
#define A

#include <iostream>
#include <memory>
#include "list.h"
using namespace std;

template <typename Key, typename Val> class Map {
public:
    struct Pair {
        Pair(Key _k, Val _v) : k(_k), v(_v) {};
        Pair() = default;
        Key k;
        Val v;
		Pair(const Pair& p) : k(p.k), v(p.v) {}; 
    };
    Map() = default;
    Map(const Map& m);
    Map& operator= (const Map& m);
    template <typename K, typename V> friend ostream& operator<< (ostream& o, Map<K,V>& m);
    Val* find(const Key& k);
    void add(Key k, Val v);
private:
    list<Pair> data;

};


template <typename Key, typename Val> Map<Key,Val>::Map(const Map<Key,Val>& m) {
	cout << &data << " " << &m.data << endl;
    data = m.data;
}

template <typename Key, typename Val> Map<Key,Val>& Map<Key,Val>::operator= (const Map<Key,Val>& m) {
    data = m.data;
    return *this;
}


template <typename K, typename V> ostream& operator<< (ostream& o, Map<K,V>& m) {
    typename Map<K,V>::Pair* nextValue;
    m.data.goToHead();
    if (!m.data.moreData()) {
        o << "Map is empty" << endl;
        return o;
    }
    while (m.data.moreData()) {
        nextValue = m.data.getCurrentData();
        o << "[ " << nextValue->k << ", " << nextValue->v << " ]" << "@" << nextValue <<endl;
        m.data.advance ();
    }
    return o;
}
template <typename Key, typename Val> Val* Map<Key,Val>::find(const Key& k) {
    data.goToHead ();
    if (!data.moreData ()) {
        return nullptr;
    }
    while (data.moreData ())
    {
        if(data.getCurrentData()->k == k ) {
            return &data.getCurrentData()->v;
        }
        data.advance ();
    }
    return nullptr;
}

template <typename Key, typename Val> void Map<Key,Val>::add(Key k, Val v) {
    auto t = new Pair(k,v);
    data.insert(t);
}

#endif
