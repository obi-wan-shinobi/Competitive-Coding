#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the timeConversion function below.
 */
string timeConversion(string s) {
    /*
     * Write your code here.
     */
     vector<string> vec;
     string temp="";
     for(char i: s){
         if(i==':'){
             vec.push_back(temp);
             temp = "";
         }
         else
            temp+=i;
     }
     string new_temp1="",new_temp2="";
     for(char i:temp){
         if(i>='0' && i<='9'){
             new_temp1 += i;
         }
         else{
             new_temp2 += i;
         }
     }
     vec.push_back(new_temp1);
     vec.push_back(new_temp2);
     string new_format = "";

     bool PM = false;

     if(vec[vec.size()-1]=="PM")
        PM =  true;

    if(PM){
        int hour = stoi(vec[0]);
        hour = 12+ (hour%12);
        vec[0] = to_string(hour);
    }
    else{
        int hour = stoi(vec[0]);
        hour %= 12;
        stringstream ss;
        ss<<setw(2)<<setfill('0')<<hour;
        vec[0] = ss.str();
    }
    for(string i:vec){
        if(i!="AM" && i!="PM")
            new_format+=i+":";
    }
    new_format.erase(new_format.begin()+new_format.size()-1);
    return new_format;

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = timeConversion(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
