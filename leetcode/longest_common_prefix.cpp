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
    string longestCommonPrefix(vector<string>& strs) {
        Trie *node=new Trie();
        for(int i=0; i<strs.size(); i++){
            node->insert(strs[i]);
        }

        string ans="";
        TrieNode* curr=node->root;
        while(1){
            int count=0;
            int index=-1;
            int flag=0;
            for(int i=0; i<26; i++){
                if(curr->alphabet[i]!=NULL){
                    count++;
                    if(count>1){
                        flag=1; break;
                    }
                    index=i;
                }
            }
            if(flag==1 || count==0 || curr->isendofword) break;
            ans+=(index+'a');
            curr=curr->alphabet[index];
        }
        return ans;
    }
};