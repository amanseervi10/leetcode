//For this question the trie node structure has been changed a little to suit the needs
//the insert function was also changed accordingly

struct TrieNode{
    TrieNode* children[26];
    bool isLeaf;
    int prefix;

    TrieNode(){
        for(int i=0; i<26; i++) children[i]=NULL;
        isLeaf=false;
        prefix=0;
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
        curr->prefix++;
    }
    curr->isLeaf=true;
}

vector<string> findPrefixes(string arr[], int n)
{
    TrieNode* root=new TrieNode();
    for(int i=0; i<n; i++){
        insert(root,arr[i]);
    }

    vector<string> ans;
    
    for(int i=0; i<n; i++){
        string temp="";
        TrieNode* curr=root;

        for(int j=0; j<arr[i].length(); j++){
            curr=curr->children[arr[i][j]-'a'];
            temp+=arr[i][j];

            if(curr->prefix==1) break;
        }
        ans.push_back(temp);
    }

    return ans;
    
}