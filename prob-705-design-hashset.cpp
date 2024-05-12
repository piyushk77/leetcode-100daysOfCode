#include <vector>
using namespace std;

class MyHashSet
{
    const int SIZE{1000000};
    vector<int> HashSet;

public:
    MyHashSet()
    {
        vector<int> newHash(SIZE + 1, -1);
        HashSet = newHash;
    }

    void add(int key) { HashSet[key] = key; }

    void remove(int key) { HashSet[key] = -1; }

    bool contains(int key)
    {
        if (HashSet[key] == -1)
            return false;
        return true;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */