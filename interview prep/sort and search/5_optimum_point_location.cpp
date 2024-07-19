double dist_calc(vector<pair<int,int>>& p, tuple<int,int,int>& l, int n, double x){
    double a=get<0>(l);
    double b=get<1>(l);
    double c=get<2>(l);
    double y=-1*(c+(a*x))/b;
    double dist=0;
    for(int i=0; i<n; i++){
        double x1=p[i].first;
        double y1=p[i].second;
        dist+=sqrt((x1-x)*(x1-x)+(y1-y)*(y1-y));
    }
    return dist;
}

double findOptimumCost(tuple<int, int, int> line, vector<pair<int, int>> p, int n)
{
    double l=-1000,r=1000;
    double mid1,mid2;

    while(r-l>0.001){
        mid1=l+ (r-1)/3;
        mid2=r- (r-l)/3;

        double a=dist_calc(p,line,n,mid1);
        double b=dist_calc(p,line,n,mid2);

        if(a<b) r=mid2;
        else if(a>b) l=mid1;
        else{
            l=mid1;
            r=mid2;
        }
    }

    return dist_calc(p,line,n,r);
}