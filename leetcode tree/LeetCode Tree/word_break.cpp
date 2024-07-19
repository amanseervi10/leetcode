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

    bool wordBreak(string s, vector<string>& wordDict) {
        Trie *node= new Trie();
        for(int i=0; i<wordDict.size(); i++){
            node->insert(wordDict[i]);
        }
        TrieNode* root=node->root;

        bool dp[s.length()];
        for(int i=0; i<s.length(); i++) dp[i]=false;

        string k=""; k+=s[0];
        dp[0]=node->search(k);
        for(int i=1; i<s.length(); i++){
            for(int j=i-1; j>=0; j--){
                if(dp[j]){
                    if(node->search(s.substr(j+1,i-(j+1)+1))){
                        dp[i]=true; break;
                    }
                }
            }
            if(node->search(s.substr(0,i+1))) dp[i]=true;
        }
         for(int i=0; i<s.length(); i++) cout<<dp[i]<<" ";
        return dp[s.length()-1];
    }
};