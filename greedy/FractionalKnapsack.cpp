struct item{
  int value;
  int weight;
};

bool static comp(item a,item b){
  double r1 = (double)a.value / (double)a.weight;
  double r2 = (double)b.value / (double)b.weight;
  return r1 > r2;
}
double fractKnapsack(item arr[],int n,int w){
  sort(arr,arr+n,comp);
  double currw = 0.0;
  double ans = 0.0;
  for(int i=0;i<n;i++){
    if(currw + arr[i].weight <= w){
      currw += arr[i].weight;
      ans += arr[i].value;
    }
    else{
      double remain = w-currw;
      ans += ((double)arr[i].value / (double)arr[i].weight) * remain;
      break;
    }
  }
  return ans;
}
