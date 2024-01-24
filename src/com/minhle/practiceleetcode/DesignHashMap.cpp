class MyHashMap {
public:
    MyHashMap() {
    }
    
    void put(int key, int value) {
        map.at(key) = value;
        occupied.at(key) = true;
    }
    
    int get(int key) {
        return occupied.at(key) ? map.at(key) : -1;
    }
    
    void remove(int key) {
        occupied.at(key) = false;
    }
private:
    array<int, 10000000> map;
    array<bool, 10000000> occupied;
};

