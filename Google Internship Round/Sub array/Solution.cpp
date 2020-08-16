#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int main()
{
  int T;
  cin>>T;

  while(T>0){
    int N;
    cin>>N;
    vector<int> arr, ans;
    int temp;
    for(int i=0; i<N; i++){
        cin>>temp;
        arr.push_back(temp);
    }

    for(int i=0; i<arr.size(); i++){
        int num = arr[i], for_count=0, back_count=0;
        int forward = i+1, backward = i-1;
        while(arr[forward]>num){
          if(forward==arr.size())
            break;
          for_count++;
          forward++;
        }
        while(arr[backward]>num)
        {
          if(backward<0)
            break;
          back_count++;
          backward--;
        }
        int tot_count = for_count+back_count+1+for_count*back_count;
        ans.push_back(tot_count);
    }
    for(auto i:ans)
      cout<<i<<'\t';
    T--;
  }

}
