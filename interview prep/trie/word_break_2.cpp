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

void solve(string &s, int index, TrieNode* curr, TrieNode* &root, string temp,vector<string> &ans){

    for(int i=index; i<s.length(); i++){
        if(curr->isLeaf){
            solve(s,i,root,root,temp+" ",ans);
        }
        if(curr->children[s[i]-'a']==NULL) return;
        else{
            curr=curr->children[s[i]-'a'];
            temp+=s[i];
        }
    }
    if(curr->isLeaf) ans.push_back(temp);
}

vector<string> wordBreak(int n, vector<string> &dict, string s)
{
    TrieNode* root=new TrieNode();

    for(int i=0; i<dict.size(); i++){
        insert(root,dict[i]);
    }

    vector<string> ans;
    solve(s,0,root,root,"",ans);
    return ans;
}