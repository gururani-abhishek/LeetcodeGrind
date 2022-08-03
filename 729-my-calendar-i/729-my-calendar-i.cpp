class MyCalendar {
set<pair<int, int>> bookings;
public:
    MyCalendar() {
        
    }
    
    bool book(int s1, int e1) {
        //search for the slot, just greater or equal to our slot using lower_bound
        auto slot = bookings.lower_bound({s1, e1});
        if(slot != end(bookings) && !(slot -> first >= e1) ||
          slot != begin(bookings) && !(prev(slot) -> second <= s1)) return false;
        
        bookings.insert({s1,  e1});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */