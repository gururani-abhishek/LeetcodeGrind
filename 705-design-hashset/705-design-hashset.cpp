class MyHashSet {
public:
    vector<int> hashSet;
    
    MyHashSet() {
        
    }
    
    void add(int key) {
        if(find(hashSet.begin(), hashSet.end(), key) == hashSet.end()) 
            hashSet.push_back(key);
    }
    
    void remove(int key) {
        auto it = find(hashSet.begin(), hashSet.end(), key);
        if(it != hashSet.end()) hashSet.erase(it);
    }
    
    bool contains(int key) {
        if(find(hashSet.begin(), hashSet.end(), key) != hashSet.end()) return true;
        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */