
struct TrieNode{
    TrieNode* alphabet[26];
    bool isendofword;

    TrieNode(){
        isendofword=false;
        for(int i=0; i<26; i++) alphabet[i]=NULL;
    }
};


class Trie {
private : 
    TrieNode * root;

public:

    Trie() {
       root=new TrieNode();
    }
    
    void insert(string word) {
       TrieNode* curr=root;
       for(int i=0; i<word.length(); i++){
            if(curr->alphabet[word[i]-'a']==NULL){
                curr->alphabet[word[i]-'a']=new TrieNode();
            }
            curr=curr->alphabet[word[i]-'a'];
        }
        curr->isendofword=true;
    }
    
    bool search(string word) {
        TrieNode* curr=root;
        for(int i=0; i<word.length(); i++){
            if(curr->alphabet[word[i]-'a']==NULL) return false;
            else curr=curr->alphabet[word[i]-'a'];
        }
        return curr->isendofword;
    }
    
    bool startsWith(string prefix) {
        TrieNode* curr=root;
        for(int i=0; i<prefix.length(); i++){
            if(curr->alphabet[prefix[i]-'a']==NULL) return false;
            else curr=curr->alphabet[prefix[i]-'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */