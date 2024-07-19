// class Solution {
// public:

//     int search(vector<vector<int>>& v,int flag,int key){
//         int start=0,end=v.size()-1;

//         if(key<v[0][flag]) return -1;
//         else if(key>v[v.size()-1][flag]) return -2;

//         while(end>start){
//             int mid=(start+end)/2;
//             if(v[mid][flag]==key) return mid;
//             else if(v[mid][flag]>key) end=mid-1;
//             else{
//                 if(v[start+1][flag]>key) return start;
//                 start=mid+1;
//             }
//         }
//         return start;
//     }

//     vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
//         int a=newInterval[0],b=newInterval[1];

//         int start=search(intervals,0,a);
//         int end=search(intervals,1,b);
//         cout<<start<<" "<<end<<endl;

//         vector<int> temp(2);
//         if(start==-1 || start==-2) temp[0]=a;
//         else temp[0]=min(a,intervals[start][0]);

//         cout<<temp[0]<<" ";
        
//         if(end==-1 || end==-2) temp[1]=b;
//         else temp[1]=max(a,intervals[end][1]);
//         cout<<temp[1]<<" ";

//         if(end==-1) intervals.insert(intervals.begin(),temp);
//         else if(start==-2) intervals.push_back(temp);
//         else{
//             if(start==-1) start=0;
//             if(end == -2) end=intervals.size();

//             intervals.erase(intervals.begin()+start,intervals.begin()+end);
//             intervals.insert(intervals.begin()+start,temp);
//         }

//         return intervals;
//     }
// };



class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;

        int flag=0;
        for(auto i : intervals){
            if(flag){
                ans.push_back(i);
                continue;
            }
            if(newInterval[0]>i[1]){
                ans.push_back(i);
            }

            else if(newInterval[1]<i[0]){
                ans.push_back(newInterval);
                ans.push_back(i);
                flag=1;
            }

            else{
                newInterval[0]=min(newInterval[0],i[0]);
                newInterval[1]=max(newInterval[1],i[1]);
            }
        }

        if(!flag) ans.push_back(newInterval);
        return ans;
    }
};