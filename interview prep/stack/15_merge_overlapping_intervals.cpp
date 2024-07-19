vector<vector<int>> overlappedInterval(vector<vector<int>> &intervals)
{
    //we first sort the intervals based on starting time
    //think about it ans it will make sense
    
    sort(intervals.begin(),intervals.end());

    vector<vector<int>> ans;    //the vector which will contain answer
    ans.push_back(intervals[0]);

    for(int i=1; i<intervals.size(); i++){
        if(ans.back()[1]<intervals[i][0]){      //i.e they don't overlap
            ans.push_back(intervals[i]);
        }
        else{                                   //the case where where they do overlap
            ans.back()[1]=max(ans.back()[1],intervals[i][1]);   
            //the start of the interval will ofcourse be greater of equal 
            //as we sorted the intervals array in the beginning

            //as for the second, the intervals[i][1] could be smaller than ans.back()[1],
            //in which case intervals[i] would be subset of ans.back(), ot it could be greater
            // we handle both these cases with a single line by using max function
        }
    }
    return ans;
}