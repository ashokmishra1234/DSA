class RandomizedSet {
public:
    vector<int> store;
    unordered_map<int,int> mp;
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(mp.find(val)!=mp.end()) return false;
        store.push_back(val);
        mp[val]=store.size()-1;
        return true;
    }
    
    bool remove(int val) {
        if(mp.find(val)==mp.end())return false;
        int ind=mp[val];
        int back_ele=store.back();
        store[ind]=back_ele;
        mp[back_ele]=ind;
        mp.erase(val);
        store.pop_back();
        return true;
    }
    
    int getRandom() {
        int rand_ind=rand()%(store.size());
        return store[rand_ind];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */