struct TrieNode{
    TrieNode* children[26];
    bool isLeaf;

    TrieNode(){
        for(int i=0; i<26; i++) children[i]=NULL;
        isLeaf=false;
    }
};

void insert(struct TrieNode *root, string key)
{
    TrieNode* curr=root;
    for(int i=0; i<key.length(); i++){
        if(curr->children[key[i]-'a']==NULL){
            curr->children[key[i]-'a']=new TrieNode();
        }
        curr=curr->children[key[i]-'a'];
    }
    curr->isLeaf=true;
}

bool solve(string &s, int index, TrieNode* curr,TrieNode* &root ){

    if(index==s.length()) return true;

    for(int i=index; i<s.length(); i++){
        if(curr->isLeaf){
            if(solve(s,i,root,root)) return true;
        }
        if(curr->children[s[i]-'a']==NULL) return false;
        else curr=curr->children[s[i]-'a'];
    }
    return curr->isLeaf;
}

int wordBreak(string A, vector<string> &B)
{
    TrieNode* root=new TrieNode();

    for(int i=0; i<B.size(); i++){
        insert(root,B[i]);
    }

    return solve(A,0,root,root);
}
