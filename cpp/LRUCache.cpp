#include <iostream>
#include <unordered_map>
#include <memory>
#include <list>

using namespace std;

struct KeyVal
{
	int key;
	int value;
};

class LRUCache{
private:
	int capacity;			// cache capacity
	list<KeyVal> cache;		// cache, implement in Double-Linked-List
	unordered_map<int, list<KeyVal>::iterator> cacheMap;	// Hash Map, quickly access to value

public:
    LRUCache(int capacity):
    	capacity(capacity) 
    { }
    
    int get(int key) {
    	auto it = cacheMap.find(key);
    	// Find by key
    	if (it != cacheMap.end()) {
    		//Find it! Get the value.
    		auto kv = it->second;
    		// Move to front
    		if (kv != cache.begin())
    			cache.splice(cache.begin(), cache, kv, next(kv));

    		return kv->value;
    	}

    	return -1;
    }
    
    void set(int key, int value) {
        auto it = cacheMap.find(key);
        // Find by key
        if (it != cacheMap.end() ){
        	// find and set new value
        	auto kv = it->second;
        	kv->value = value;
        	// move front
        	if (kv != cache.begin())
        		cache.splice(cache.begin(), cache, kv, next(kv));
        }
        else {
        	// Not found
        	if (cacheMap.size() < capacity) {
        		KeyVal newKv = {key, value};
        		// set in cache
        		cache.push_front(newKv);
				// add to map
        		cacheMap.insert(make_pair(key, cache.begin()));
        	}else {
        		// Capacity is not enough
        		// Delete the least used value
        		int oldKey = cache.back().key;
        		cache.pop_back();
        		cacheMap.erase(oldKey);
        		
        		// Add new value
        		KeyVal newKv = {key, value};
        		cache.push_front(newKv);
        		cacheMap.insert(make_pair(key, cache.begin()));
        	}
        }
    }
};

int main(int argc, char const *argv[])
{
	LRUCache lru(1);
	lru.set(2, 1);
	// lru.set(2002, 3);
	// lru.set(2003, 1);
	// lru.set(2004, 4);
	cout<<lru.get(2);
	return 0;
}