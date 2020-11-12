#include<iostream>
#include<bits/stdc++.h>

using namespace std;

void smallestInt(int a){
  vector<int>res;

  for(int i = 9; i>1; i--){
    while(a%i==0){
      a = a/i;
      res.push_back(i);
    }
  }
  for(auto it=res.rbegin(); it!=res.rend(); it++)
    cout<<*it;
}

int main()
{
  int a;
  cin>>a;

  if(a<10){
    cout<<a+10;
    return 0;
  }

  vector<int> sieve(a+1, 0);

  //0 & 1 are not prime
  sieve[0] = sieve[1] = 1;
  for(int i=2; i<a; i++){
    if(sieve[i]==0){
      int j=2;
      while(i*j<=a){
        sieve[i*j] = 1;
        j++;
      }
    }
  }
  if(sieve[a] == 0){
    cout<<"Not Possible";
    return 0;
  }
  smallestInt(a);
}
