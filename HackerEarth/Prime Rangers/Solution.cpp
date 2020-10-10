#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main(){
  int T;
  cin>>T;

  if(T<0 || T>5)
    return 0;

  while(T>0){
    T--;
    long L,R;
    cin>>L>>R;

    long cntr = 0;

    if(L<0 || R<0 || L>pow(10,18) || R>pow(10,18) || L>R)
      continue;

    for(long i=L; i<=R; i++){
      vector<int>freq(10,0);
      long temp = i;

      while(temp!=0){
        int a = temp%10;
        temp = temp/10;
        freq[a]++;
      }

      int freq_2 = freq[2];
      int freq_3 = freq[3];
      int freq_5 = freq[5];
      int freq_7 = freq[7];

      if(freq_2 >= freq_3)
        if(freq_3 >= freq_5)
          if(freq_5 >= freq_7)
            cntr++;
    }
    cout<<cntr%1000000007;
  }
}
