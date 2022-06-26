//Name - Pranav Kumar
//Roll No. - CSB19065
// 1. Program to compute Language Statistics of diagram frequency.
// Second part of the question 1.
#include<iostream>
#include<string>
#include<map>
using namespace std;

int main()
{
  string msg;
  cout<<"Enter the massege : ";
  getline(cin,msg);
  map<string,int> freq;
  for(int i=0;i<msg.length()-1;i++)
  {
    if(msg[i]==' '||msg[i+1]==' ')
      continue;
    
    if(msg[i]>='a'&&msg[i]<='z'&&msg[i]>='A'&&msg[i]<='Z')
    {
       string temp;
       temp.insert(temp.end(),1,tolower(msg[i]));
       temp.insert(temp.end(),1,tolower(msg[i+1]));
       if(freq.find(temp)!=freq.end())
       {
         freq[temp]++;
       }
       else
       {
         freq[temp]=1;
       }
    }
    
  }
  cout<<" Diagram "<<"  "<<" frequency "<<endl;
  for(auto i : freq)
    cout<<"   "<<i.first<<"           "<<i.second<<endl; 
  return 0;
}