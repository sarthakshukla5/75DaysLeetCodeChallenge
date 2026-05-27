class MyCalendarTwo {
map<int,int> map;
public:
    MyCalendarTwo() {
        
    }
    bool book (int s, int e) {
        map[s]++; map[e]--;
        int prefix = 0;
        for (auto it: map){
            prefix += it.second;
            if(prefix ==3){
                map[s] --; map[e]++;
                return false;
            }
        }
        return true;
    }
    
 
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(startTime,endTime);
 */