class LRUCache
{
    private:
        list<pair<int,int>> l;
        unordered_map<int,list<pair<int,int>>::iterator> s;
        int cap;
        int size=0;

    public:
    //Constructor for initializing the cache capacity with the given value.
    LRUCache(int cap)
    {
        this->cap=cap;
    }
    
    //Function to return value corresponding to the key.
    int GET(int key)
    {
        if(s.find(key)==s.end()) return -1;
        l.splice(l.begin(),l,s[key]);
        return s[key]->second;
    }
            
    //Function for storing key-value pair.
    void SET(int key, int value)
    {
        if(get(key)!=-1){
            (s[key])->second=value;
            return;
        }
        if(s.size()==cap){          //if size equals capacity we reomve least needed element
            s.erase(l.back().first);
            l.pop_back();
        }

        l.emplace_front(key,value);            //we proceed with entering the nnew element
        s[key]=l.begin();
    }
};