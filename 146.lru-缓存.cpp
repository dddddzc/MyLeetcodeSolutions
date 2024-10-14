/*
 * @lc app=leetcode.cn id=146 lang=cpp
 *
 * [146] LRU 缓存
 */

// @lc code=start
#include <list>
#include <unordered_map>
#include <utility>
using namespace std;

class LRUCache {
private:
    int capacity;
    list<pair<int, int>> cache_list; // 双向链表
    unordered_map<int, list<pair<int, int>>::iterator> cache_map; // map的value是list的迭代器
    
public:
    LRUCache(int capacity) : capacity(capacity) {}
    
    int get(int key) {
        if(cache_map.find(key) == cache_map.end()) {
            return -1; // map中没有找到key对应的迭代器
        }
        // 存在,将key挪到list的头部:说明该key最新被访问过
        cache_list.splice(cache_list.begin(), cache_list, cache_map[key]);
        return cache_map[key]->second;
    }
    
    void put(int key, int value) {
        // 如果已经存在该key,将key挪到list的头部:说明该key最新被访问过
        // 并且将该key的value更新
        if(cache_map.find(key) != cache_map.end()) {
            cache_list.splice(cache_list.begin(), cache_list, cache_map[key]);
            cache_map[key]->second = value;
        } else { // 不存在该key
            if(cache_list.size() == capacity) { //容量满了
                cache_map.erase(cache_list.back().first); // 从map中移除LRU元素的key
                cache_list.pop_back(); // 从list中移除LRU节点
            } 
            // 此处不用else,因为不管容量满不满,都要插入
            cache_list.emplace_front(key, value);
            cache_map[key] = cache_list.begin();
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end

