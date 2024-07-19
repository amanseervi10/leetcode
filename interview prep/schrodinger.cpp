#include<bits/stdc++.h>
using namespace std;

int solve(vector<int> skills, int i, int k,vector<int>& temp,vector<vector<int>> &memoize){

    if(i<0) return temp.size();

    if(memoize[i][k]!=-1) return memoize[i][k];

    int not_take=solve(skills, i-1, k,temp,memoize);

    int a=k;
    if(temp.empty()) temp.push_back(skills[i]);
    else{
        if(temp.back()!=skills[i]){
            if(a>0) a--;
            else return not_take;
        }
        temp.push_back(skills[i]);
    }
    int take=solve(skills,i-1,a,temp,memoize);

    return memoize[i][k]=max(take,not_take);
}

int findMaxLength(vector<int> skills, int k){
    vector<int> temp;
    vector<vector<int>> memoize(skills.size()+1,vector<int>(k+1,-1));
    return solve(skills,skills.size()-1,k,temp,memoize);
}

int main(){
    vector<int> skills={1,1,2,2,3,2,1};
    cout<<findMaxLength(skills,2);
    return 0;
}







// #include<bits/stdc++.h>
// using namespace std;


// int solve(vector<int> skills, int i, int k,vector<int>& temp){

//     if(i<0) return temp.size();
    

//     int not_take=solve(skills, i-1, k,temp);

//     int a=k;
//     if(temp.empty()) temp.push_back(skills[i]);
//     else{
//         if(temp.back()!=skills[i]){
//             if(a>0) a--;
//             else return not_take;
//         }
//         temp.push_back(skills[i]);
//     }
//     int take=solve(skills,i-1,a,temp);
//     temp.pop_back();

//     return max(take,not_take);
// }

// int findMaxLength(vector<int> skills, int k){
//     vector<int> temp;
//     return solve(skills,skills.size()-1,k,temp);
// }

// int main(){
//     vector<int> skills={1,2,2,3,2,1};
//     cout<<findMaxLength(skills,1);
//     return 0;
// }