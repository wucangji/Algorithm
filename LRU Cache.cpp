class LRUCache{

private:
    struct CacheNode {
        int key;
        int value;
        CacheNode(int k, int v):key(k), value(v){}   // cannot have ; need to have{}
    };
    list<CacheNode> cacheList;
    unordered_map<int,list<CacheNode>::iterator> cacheMap;   // map 存的iterator 位置  就可以保证O(1)  ?
    int capacity;


public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        if (cacheMap.find(key) == cacheMap.end()) return -1;  // cannot find, what if we use count here?
        // put the key to the front
        cacheList.splice(cacheList.begin(),cacheList,cacheMap[key]);
        cacheMap[key] = cacheList.begin();
        return cacheList.begin()->value;
        // return cacheMap[key]->value  is  OK too.
    }
    
    void set(int key, int value) {
        if(cacheMap.count(key) == 0) {
            if (capacity == cacheList.size()){
                cacheMap.erase(cacheList.back().key);
                cacheList.pop_back();      //Map use erase.   list just need to pop
                
            }
            cacheList.push_front(CacheNode(key,value));
            cacheMap[key] = cacheList.begin();
        }else{  // 找到了 那么就需要更新value 重复 get 的操作即可
            cacheMap[key]->value = value;
            cacheList.splice(cacheList.begin(),cacheList,cacheMap[key]);
            cacheMap[key] = cacheList.begin();
        }
    }
};


// need to be careful. when it is an iterator pointer (in the map) we should use ->    otherwise use.