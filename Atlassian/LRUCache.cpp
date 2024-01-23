class LRUCache {

    unordered_map<int, list<pair<int,int>>::iterator> mpp; 
    list<pair<int,int>> cache;
    int cap;
public:
    LRUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {
        
        auto it = mpp.find(key);
        if(it==mpp.end()) return -1;

        cache.splice(cache.begin(), cache, it->second);
        return it->second->second;

    }
    
    void put(int key, int value) {
        
        auto it = mpp.find(key);

        if(it != mpp.end()){
            cache.splice(cache.begin(), cache, it->second);
            it->second->second = value;
            return;
        }

        if(cap==mpp.size()){
            mpp.erase(cache.back().first);
            cache.pop_back();
        }

        cache.push_front({key, value});
        mpp[key] = cache.begin();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */