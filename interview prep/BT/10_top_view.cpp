//In the map the first element is the x-coordinate
//when we move left we are going in negative x direction
//while right side is the +ve x direction

//Now since this is top view along with x-coordinate we also need to see the y-coordinate
//as if two nodes are at the same x-coordinate , then the higher one is prefered as
//that is the node we can see from the top
//so the second part of the map is a pair, the first element is the data of ndoe itself
//the other is the height

//so if a particular x-coordinate has never been explored, we insert it's data into the map
//later during the traversal if we find another node at the same x-coordinate
//then we check if it is at a more height(i.e closer to the top), if it is, then we give
//it priority

//we can do the bottom view similarly, except that the one with less height(i.e which is more below),
//should be given priority

map<int,pair<int,int>> s;

void preorder(Node* root,int k,int height){
    if(root!=NULL){
        if(s.find(k)==s.end() || height<s[k].second){
            s[k]={root->data,height};
        }
        preorder(root->left,k-1,height+1);
        preorder(root->right,k+1,height+1);
    }
}

vector<int> topView(Node *root)
{
    preorder(root,0,0);
    vector<int> ans;
    for(auto it: s){
        ans.push_back(it.second.first);
    }
    return ans;
}