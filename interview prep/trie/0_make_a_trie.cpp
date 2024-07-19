// trie node
/*
struct TrieNode {
    struct TrieNode *children[ALPHABET_SIZE];

    // isLeaf is true if the node represents
    // end of a word
    bool isLeaf;
};
*/

//Function to insert string into TRIE.
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

//Function to use TRIE data structure and search the given string.
bool search(struct TrieNode *root, string key) 
{
    TrieNode* curr=root;
    for(int i=0; key.length(); i++){
        if(curr->children[key[i]-'a']==NULL) return false;
        curr=curr->children[key[i]-'a'];
    }
    return key->isLeaf;
}