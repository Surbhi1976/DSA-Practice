vector<int>maxMeetings(vector<int>&start,vector<int>&end){
  vector<tuple<int,int,int>>meetings;
  for(int i=0;i<start.size();i++){
    meetings.push_back({end[i],start[i],i+1});
  }
  sort(meetings.begin(),meetings.end());
  vector<int>result;
  int finalend = -1;
  for(auto&it:meetings){
    int s = get<1>it;
    int e = get<0>it;
    int v = get<2>it;
    if(s > finalend){
      result.push_back(v);
      finalend = e;
    }
  }
  return result;
}
  
  
