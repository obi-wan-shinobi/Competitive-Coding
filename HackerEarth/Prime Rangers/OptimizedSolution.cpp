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
    long L,R,new_L,new_R;
    cin>>L>>R;

    new_L = L;
    new_R = R;
    long cntr = 0;

    if(L<0 || R<0 || L>pow(10,18) || R>pow(10,18) || L>R)
      continue;

    for(long i = L; (i-1)%10!=0; i++){
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
      new_L = i;
    }

    for(long i = R; i%10!=0; i--){
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
      cout<<endl<<i;
      new_R = i;
    }
    cout<<endl<<new_L<<endl<<new_R;
    long range_diff = new_R - new_L + 1;

    cout<<endl<<"Range diff:"<<range_diff;
    long range_in_multiples_of_ten = range_diff/10;

    cout<<endl<<"Range in multiples of ten:"<<range_in_multiples_of_ten;

    long count = range_in_multiples_of_ten * 7;

    cout<<endl<<count;

    cntr += count;

    cout<<endl<<cntr%1000000007;
  }
}
