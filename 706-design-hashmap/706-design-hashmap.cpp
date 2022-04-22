struct Node {
    int key, value;
    Node* next;
    Node(int x, int y, Node* z) {
        key = x;
        value = y;
        next = z;
    }
};

class MyHashMap {
public:
    const static int size = 19997;
    const static int mult =  12582917;
    Node* data[size]; //array of pointers type Node
//     MyHashMap() {
        
//     }
    
    void put(int key, int value) {
        remove(key);
        int h = hash(key);
        Node* node = new Node(key, value, data[h]);
        data[h] = node;
    }
    
    int get(int key) {
        int h = hash(key);
        Node* node;
        for(node = data[h]; node != NULL; node = node -> next)
            if(node -> key == key) return node -> value;
        
        return -1;
        
    }
    
    void remove(int key) {
        int h = hash(key);
        Node* node = data[h];
        if(node == NULL) return;
        if(node -> key == key) data[h] = node -> next;
        else for(;node -> next != NULL; node = node -> next) {
            if(node -> next -> key == key) {
                node -> next = node -> next -> next;
                return;
            }
        }
        
    }                       
    
private:
    int hash(int key) {
        return (int)((long)key * mult % size);
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */