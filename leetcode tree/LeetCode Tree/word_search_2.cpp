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

    vector<string> final_ans;

    void solve(vector<vector<char>>& board, int a,int b, TrieNode* root,string& store){

        if(root->isendofword){
            final_ans.push_back(store);
            root->isendofword=false;
        }
        
        if(a>=0 && a<board.size() && b>=0 && b<board[0].size()){
            if(board[a][b]=='.') return;
            if(root->alphabet[board[a][b]-'a']!=NULL){
                char temp;
                store+=board[a][b];
                temp=board[a][b];
                board[a][b]='.';
                solve(board,a+1,b,root->alphabet[temp-'a'],store);
                solve(board,a-1,b,root->alphabet[temp-'a'],store);
                solve(board,a,b+1,root->alphabet[temp-'a'],store);
                solve(board,a,b-1,root->alphabet[temp-'a'],store);
                board[a][b]=temp;
                store.pop_back();
            }
            else return;
        }
    }


    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Trie* node=new Trie();
        for(auto i : words){
            node->insert(i);
        }

        TrieNode* root=node->root;
        for(int i=0; i<board.size(); i++){
            for(int j=0; j<board[0].size(); j++){
                if(root->alphabet[board[i][j]-'a']!=NULL){
                    char temp;
                    string s="";
                    s+=board[i][j];
                    temp=board[i][j];
                    board[i][j]='.';
                    solve(board,i+1,j,root->alphabet[temp-'a'],s);
                    solve(board,i-1,j,root->alphabet[temp-'a'],s);
                    solve(board,i,j+1,root->alphabet[temp-'a'],s);
                    solve(board,i,j-1,root->alphabet[temp-'a'],s);
                    board[i][j]=temp;
                }
            }
        }

        return final_ans;
    }
};
