#include<bits/stdc++.h>
using namespace std;

pair<int,int> getTime(string s){

    int first=-1,second=-1;
    for(int i=0; i<s.length(); i++){
        if(s[i]==':' && first==-1) first=i;
        else if(s[i]==':'){ second=i; break;}
    }

    int a1=stoi(s.substr(first-2,2));
    int a2=stoi(s.substr(first+1,2));
    int b1=stoi(s.substr(second-2,2));
    int b2=stoi(s.substr(second+1,2));

    int from=a1*60 + a2;
    int to=b1*60 + b2;

    return {from,to};
}

string getName(string s){
    string ans="";
    for(int i=0; i<s.length(); i++){
        if(s[i]==' ') return ans;
        ans+=s[i];
    }
    return ans;
}

string convert_to_string(int temp){

    string ans="";
    int hours=temp/60;
    if(hours<=9) ans+='0';
    ans+= to_string(hours);
    
    ans+=':';

    int mins=temp-(hours)*60;
    if(mins<=9) ans+='0';
    ans+=to_string(mins);
    return ans;
}

string getEarliestMeetTime(vector<string> events, int k){
    vector<int> arr[1440];

    unordered_map<string,int> names;
    int count=1;

    for(int i=0; i<events.size(); i++){
        string name=getName(events[i]);
        // cout<<name<<" ";
        
        int curr;
        if(names.find(name)!=names.end()) curr=names[name];
        else{
            curr=count;
            names[name]=count;
            count++;
        }
        auto temp=getTime(events[i]);
        // cout<<temp.first<<" "<<temp.second<<endl;

        arr[temp.first].push_back(curr);
        arr[temp.second].push_back(curr);
    }

    multiset<int> track;
    for(int i=0; i<k; i++){
        for(int j=0; j<arr[i].size(); j++){
            if(track.find(arr[i][j])==track.end()){
                track.insert(arr[i][j]);
                // cout<<i<<" "<<arr[i][j]<<endl;
            }
            else{
                // cout<<i<<" "<<arr[i][j]<<endl;
                track.erase(track.find(arr[i][j]));
            }
        }
    }
    
    // cout<<track.size()<<endl;
    int start=0,end=k-1;
    while(1){
        if(track.size()==0){
            // cout<<end<<" end "<<endl;
            return convert_to_string(start+1);
        }
        else{

            start++;
            for(int j=0; j<arr[start].size(); j++){
                if(track.find(arr[start][j])!=track.end()){
                    track.erase(track.find(arr[start][j]));
                }
            }

            end++;
            for(int j=0; j<arr[end].size(); j++){
                if(track.find(arr[end][j])==track.end()){
                    track.insert(arr[end][j]);
                }
            }
        }
        
        if(end==1439) break;
    }

    return "-1";
}

int main(){
    
    vector<string> events={"sam sleep 12:00 23:59","alex gaming 00:00 11:00"};
    // int k; cin>>k;

    cout<<getEarliestMeetTime(events,1);

    return 0;
}