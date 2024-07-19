//there's a printing version of this too
//there you gotta store the node  values in a vector and all
//see gfg article 

void solve(Node* root, int k, unordered_map<int,int> &mp,int &count,int sum){

    if(root==NULL) return;

    sum+=root->data;
    count+=mp[sum-k];
    if(sum==k) count++;
    mp[sum]++;

    solve(root->left,k,mp,count,sum);
    solve(root->right,k,mp,count,sum);

    mp[sum]--;
}

int sumK(Node *root, int k)
{
    int count=0;
    unordered_map<int,int> mp;

    solve(root,k,mp,count,0);
    return count;
}