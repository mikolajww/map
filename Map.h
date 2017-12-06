#include <iostream>
#include "list.h"
using namespace std;

template <typename Key, typename Val> class Map {
public:
    struct Pair {
        Pair(Key _k, Val _v) : k(_k), v(_v) {};
        Pair() = default;
        Key k;
        Val v;
    };
    Map();
    Map(const Map& m);
    Map& operator= (const Map& m);
    template <typename K, typename V> friend ostream& operator<< (ostream& o, Map<K,V>& m);
    Val* find(const Key& k);
    void add(Key k, Val v);
private:
    unsigned size;
    list<Pair> data;
};

template <typename Key, typename Val> Map<Key,Val>::Map() {
    size = 0;
}

template <typename Key, typename Val> Map<Key,Val>::Map(const Map<Key,Val>& m) {
    data = m.data;
    size = m.size;
}

template <typename Key, typename Val> Map<Key,Val>& Map<Key,Val>::operator= (const Map<Key,Val>& m) {
    data = m.data;
    size = m.size;
    return *this;
}

template <typename K, typename V> ostream& operator<< (ostream& o, Map<K,V>& m) {
    typename Map<K,V>::Pair* nextValue;
    m.data.goToHead ();
    if (!m.data.moreData ())
    {
        o << "Map is empty" << endl;
        return o;
    }
    while (m.data.moreData ())
    {
        nextValue = m.data.getCurrentData();
        o << "[ " << nextValue->k << ", " << nextValue->v << " ]" << endl;
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