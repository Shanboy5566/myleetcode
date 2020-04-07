/*
 * @lc app=leetcode id=146 lang=cpp
 *
 * [146] LRU Cache
 */

// @lc code=start
class LRUCache {
public:
    /*  
        int capacity -> int
        key to val -> unordered_map<int (key), list<int (val)>::iterator>
        cache -> List<int (val)> 
        
        put(1, 1); -> 
        put(2, 2); -> need to insert val 2 to begin of the list (emplace_front)
        get(1); -> need to switch the node position from old to new(List.begin()) cache.splic(cache.begin(), cache, iterator that point to val 1, could call map)

        step    key     val                     List
        1       1       point to node in List   (1 new)->n
        2       2       point to node in List   (2 new)->(1 old)->n
        3       1       get pointer to Node 1   (1 new)->(2 old)->n

    */
    int capacity_;
    unordered_map<int, list<pair<int, int>>::iterator> map;
    list<pair<int, int>> cache;

    LRUCache(int capacity) {
        capacity_ = capacity;
    }
    
    int get(int key) {
        auto it = map.find(key);
        if (it == map.end()) return -1; // not found
        cache.splice(cache.begin(), cache, it->second);
        return it->second->second;
    }
    
    void put(int key, int value) {
        auto it = map.find(key);
        // check if exists
        if (it != map.end()){
            // update val
            it->second->second = value;
            // switch to new in cache
            cache.splice(cache.begin(), cache, it->second);
            return;
        }
        // if capacity max
        if (cache.size() == capacity_){
            // remove oldest from map
            auto last = cache.back();
            map.erase(last.first);
            // remove oldest from cache
            cache.pop_back();
        }
        //  normal case
        // insert the val to the front of the list
        cache.emplace_front(key, value);
        // map the iterator to its key
        map[key] = cache.begin();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end

