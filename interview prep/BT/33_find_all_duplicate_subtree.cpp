string solve(Node* root,unordered_map<string,pair<Node*,int>>& mp){
    if(root==NULL) return "";

    string s= to_string(root->data)+'#'+solve(root->left,mp)+'#'+solve(root->right,mp);

    if(mp.find(s)!=mp.end()) mp[s].second++;

    else{
        mp[s].first=root;
        mp[s].second=1;
    }
    return s;
}

vector<Node*> printAllDups(Node* root)
{
    unordered_map<string,pair<Node*,int>> mp;
    vector<Node*> ans;
    solve(root,mp);

    for(auto it: mp){
        if(it.second.second>=2) ans.push_back(it.second.first);
    }
    return ans;
}