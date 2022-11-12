class MedianFinder {
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
       // add that num to heap1, 
        heap1.push(num); 
        
        // <= check : 
        if(!heap1.empty() && !heap2.empty() 
          && (heap1.top() > heap2.top())) {
            int val = heap1.top();
            heap1.pop();
            heap2.push(val); 
        }    
        
        // size difference : 
        // size of heap1 - heap2 > 1
        if(heap1.size() > heap2.size() + 1) {
            int val = heap1.top(); 
            heap1.pop(); 
            heap2.push(val); 
        }
        
        // size of heap2 - heap1 > 1
        if(heap2.size() > heap1.size() + 1) {
            int val = heap2.top(); 
            heap2.pop(); 
            heap1.push(val); 
        }
        
    }
    
    double findMedian() {
        if(heap1.size() > heap2.size()) return heap1.top(); 
        if(heap2.size() > heap1.size()) return heap2.top(); 
        return (heap1.top() + heap2.top()) / 2.0; 
    }
    
private: 
    // two heaps, max and min heap : heap1(maxHeap), heap2(minHeap); 
    priority_queue<int> heap1; // max heap
    priority_queue<int, vector<int>, greater<int>> heap2; // min heap
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */