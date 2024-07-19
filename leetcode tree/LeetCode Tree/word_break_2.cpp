struct TrieNode{
    TrieNode* alphabet[26];
    bool isendofword;

    TrieNode(){
        isendofword=false;
        for(int i=0; i<26; i++) alphabet[i]=NULL;
    }
};


class Trie {

public:
    TrieNode * root;

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

class Solution {
public:

    vector<string> ans;

    void solve(string&s, int index, string collect, TrieNode* curr,TrieNode* root){

        for(int i=index; i<s.length(); i++){

            if(curr->isendofword){
                collect+=" ";   
                solve(s,i,collect,root,root);
                collect.pop_back();
            }
            if(curr->alphabet[s[i]-'a']==NULL) return;
            else if(curr->alphabet[s[i]-'a']!=NULL){
                curr=curr->alphabet[s[i]-'a'];
                collect+=s[i];
            }
        }

        if(curr->isendofword) ans.push_back(collect);
    }

    vector<string> wordBreak(string s, vector<string>& wordDict) {
        Trie *node= new Trie();
        for(int i=0; i<wordDict.size(); i++){
            node->insert(wordDict[i]);
        }
        TrieNode* root=node->root;

        solve(s,0,"",root,root);
        return ans;
    }
};