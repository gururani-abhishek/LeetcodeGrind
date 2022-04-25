/*
 * Below is the interface for Iterator, which is already defined for you.
 * **DO NOT** modify the interface for Iterator.
 *
 *  class Iterator {
 *		struct Data;
 * 		Data* data;
 *  public:
 *		Iterator(const vector<int>& nums);
 * 		Iterator(const Iterator& iter);
 *
 * 		// Returns the next element in the iteration.
 *		int next();
 *
 *		// Returns true if the iteration has more elements.
 *		bool hasNext() const;
 *	};
 */

class PeekingIterator : public Iterator {
public:
    vector<int> storage;
	PeekingIterator(const vector<int>& nums) : Iterator(nums) {
	    storage.resize(nums.size());
        storage = nums;
	}
	
    // Returns the next element in the iteration without advancing the iterator.
	int peek() {
        return storage[0];
	}
	
	// hasNext() and next() should behave the same as in the Iterator interface.
	// Override them if needed.
	int next() {
	    int x = storage[0];
        storage.erase(storage.begin() + 0);
        return x;
    }
	
	bool hasNext() const {
        return (storage.size() != 0 ? true: false);
	}
};