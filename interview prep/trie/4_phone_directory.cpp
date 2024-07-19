class Solution{
public:
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

void solve(string s, TrieNode* curr, vector<string> &store){

    if(curr->isLeaf){
        store.push_back(s);
    }

    for(int i=0; i<26; i++){
        if(curr->children[i]){
            char k='a'+i;
            solve(s+k,curr->children[i],store);
        }
    }
}

vector<vector<string>> displayContacts(int n, string contact[], string s)
{
    TrieNode* root=new TrieNode();

    for(int i=0; i<n; i++){
        insert(root,contact[i]);
    }

    vector<vector<string>> ans;
    string temp="";
    TrieNode* curr=root;

    for(int i=0; i<s.length(); i++){
        temp+=s[i];
        if(curr->children[s[i]-'a']){
            curr=curr->children[s[i]-'a'];
            vector<string> store;
            solve(temp,curr,store);
    
            ans.push_back(store);
        }
        else{
            while(i<s.length()){
                ans.push_back({"0"});
                i++;
            }
        }
        
    }

    return ans;
}






//See this solution below, it is better

// struct TrieNode {
//     struct TrieNode* child[26];
//     bool isEnd;
//     vector<int> idx;
//     TrieNode(){
//         for(int i=0;i<26;i++){
//             child[i]=NULL;
//         }
//         isEnd=false;
//     }
// };

// class Solution{
// public:
    
//     void insert(TrieNode* root,string word,int i){
//         TrieNode* curr = root;
//         for(auto c: word){
//             int p=c-'a';
//             if(curr->child[p]==NULL){
//                 curr->child[p]=new TrieNode();
//             }
//             curr=curr->child[p];
//             curr->idx.push_back(i);
//         }
//         curr->isEnd = true;
//     }
    
//     void helper(TrieNode* root,string temp,vector<vector<string>>&ans,string contact[]){
//         TrieNode* curr=root;
//         for(auto c: temp){
//             int ch=c-'a';
//             if(curr->child[ch]==NULL){
//                 ans.push_back({"0"});
//                 return;
//             }
//             curr=curr->child[ch];
//         }
//         set<string>t;
//         for(auto i: curr->idx){
//             t.insert(contact[i]);
//         }
//         if(t.size()==0){
//             ans.push_back({"0"});
//         }
//         else{
//             vector<string>te;
//             for(auto i: t){
//                 te.push_back(i);
//             }
//             ans.push_back(te);
//         }
//     }
    
//     vector<vector<string>> displayContacts(int n, string contact[], string s){
//         TrieNode* root = new TrieNode();
//         for(int i=0;i<n;i++){
//             insert(root,contact[i],i);
//         }
//         vector<vector<string>>ans;
//         string temp="";
//         for(int i=0;i<s.length();i++){
//             temp+=s[i];
//             helper(root,temp,ans,contact);
//         }
//         return ans;
//     }
// };