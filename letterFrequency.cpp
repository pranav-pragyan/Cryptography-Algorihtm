//Name - Pranav Kumar
//Roll No. - CSB19065
// 1. Program to compute Language Statistics of letter frequency.
// First part of the question 1.
#include<iostream>
#include<string>
#include<vector>
using namespace std;

vector<int> letter_freq(string msg)
{
  vector<int> freq(26,0);
  for(int i=0;i<msg.length();i++)
  {
    
    char letter = tolower(msg[i]);
    freq[letter-'a']++;
  }
  return freq;
}
int main()
{
  string msg;
  cout<<"Enter the massege : ";
  getline(cin,msg);
  vector<int> frequency=letter_freq(msg);

  char letter_a = 'a';
  cout<<" char "<<" frequency "<<endl;
  for(auto i=frequency.begin();i!=frequency.end();i++)
  {
     cout<<"   "<<letter_a<<"       "<<*i<<endl;
     letter_a++;
  } 
  return 0;
}