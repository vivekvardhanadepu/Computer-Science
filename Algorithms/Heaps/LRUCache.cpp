unordered_map<int, pair<int, int>> cache;
int maxCap;
int endKey;

void printHeap(){
    for(auto x:cache){
        cout<<"key: "<<x.first<<" value: "<<x.second.first<<endl;
       
    }
     cout<<endl;
}

class Comparator{
    public:
        bool operator()(pair<int, int> &a, pair<int, int> &b){
            return a.second > b.second;
        } 
};

priority_queue<pair<int, int>, vector<pair<int, int>>, Comparator> keys;


LRUCache::LRUCache(int capacity) {
    cache.clear();
    // keys.clear();
    keys = priority_queue<pair<int, int>, vector<pair<int, int>>, Comparator>();
    maxCap = capacity;
    endKey=-1;
}

int LRUCache::get(int key) {
    if(cache.find(key)==cache.end()){
        return -1;
    }
    // int value = cache[key].first;
    // cache[key]=make_pair(value, ++endKey);
    cache[key].second = ++endKey;
    keys.push({key, endKey});
    // // cache.erase(key);
    // cache[key] = value;
    return cache[key].first;
}

void LRUCache::set(int key, int value) {
    if(cache.find(key)==cache.end()){
        if(cache.size()==maxCap){
            while((keys.top().second)!=(cache[keys.top().first].second))
                keys.pop();
            cache.erase(keys.top().first);
            keys.pop();
        }
    }
    cache[key]=make_pair(value, ++endKey);
    keys.push({key, endKey});
}

#include <list>

list<pair<int, int>> lst;
    // Pair of key, value
    
    // Hashtable
    vector<list<pair<int, int>>::iterator> hshtable;
    int mxLimit;


LRUCache::LRUCache(int capacity) {
mxLimit = capacity;
        lst.clear();
        hshtable.clear();
        hshtable.resize(10001);
        fill(hshtable.begin(), hshtable.end(), lst.end());
}

int LRUCache::get(int key) {


    if(hshtable[key] != lst.end()) {
            // The value already exists
            // Move it to the back
            auto it = hshtable[key];
            int value = it->second;
            lst.erase(it);
            
            // This value does not exist in the list
            // Add it
            lst.push_back({key, value});
            it = --lst.end();
            hshtable[key] = it;
        }
        
        
        if (hshtable[key] == lst.end()) return -1;
        else {
            return hshtable[key]->second;
        }
}

void LRUCache::set(int key, int value) {

    if(hshtable[key] != lst.end()) {
            // The value already exists
            // Move it to the back
            auto it = hshtable[key];
            lst.erase(it);
        }
        
        // This value does not exist in the list
        // Add it
        lst.push_back({key, value});
        auto it = --lst.end();
        hshtable[key] = it;
        
        if (lst.size() > mxLimit) {
            // We need to pop the value from the front
            auto it = lst.begin();
            hshtable[it->first] = lst.end();

            lst.pop_front();
        }

}

// https://www.interviewbit.com/problems/lru-cache/