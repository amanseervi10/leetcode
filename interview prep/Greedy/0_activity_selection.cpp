bool comparator(pair<int,int> &a, pair<int,int> &b){
    return (a.second<b.second);
}


int activitySelection(vector<int> start, vector<int> end, int n)
{
    vector<pair<int,int>> a;
    for(int i=0; i<n; i++){
        a.push_back({start[i],end[i]});
    }

    //sort according to end time
    sort(a.begin(),a.end(),comparator);

    //Keep picking them if the times don't collide
    int count=0;

    int curr_end_time=0;
    for(int i=0; i<n; i++){
        if(a[i].first>curr_end_time){
            count++;
            curr_end_time=a[i].second;
        }
    }

    return count;
}