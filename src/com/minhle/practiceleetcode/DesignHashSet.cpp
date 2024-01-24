class MyHashSet {
public:
    MyHashSet() {
    }
    
    void add(int key) {
        set.at(key) = key;
    }
    
    void remove(int key) {
        set.at(key) = -1;
    }
    
    bool contains(int key) {
        return set.at(key) == key;
    }
private:
    array<int, 10000000> set;
};
