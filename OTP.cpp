//Name - Pranav Kumar
//Roll No. - CSB19065
// 2.A. Progam to implement One Time Pad
#include<iostream>
#include<time.h>
#include<math.h>
#include<vector>

using namespace std;

string key_gen(int msg_len)
{
   srand(time(0));
   string key = "";
   for(int i=0;i<msg_len;i++)
   {
      char temp=rand()%26+'a';
      key+=temp;
   }
   return key;
}

string encryption(string msg,string key)
{
   
   for(int i=0;i<msg.length();i++)
   {
      if(msg[i]==' ')
         continue;
      msg[i] = ((msg[i]-'a')+(key[i]-'a'))%26+'a';
   }
     
   return msg;      
}

string decryption(string c_text,string key)
{
   for(int i=0;i<c_text.length();i++)
   {
      if(c_text[i]==' ')
         continue;
      key[i]=(26-(key[i]-'a'))+'a';
      c_text[i] = ((c_text[i]-'a')+(key[i]-'a'))%26+'a';
   }
      
   return c_text;
}
int main()
{
   string msg;
   cout<<"Enter the massege : ";
   getline(cin,msg);
   string key=key_gen(msg.length()); 
   string c_text=encryption(msg,key);
   string p_text=decryption(c_text,key);
   cout<<"key : "<<key<<endl;
   cout<<"cipher text : "<<c_text<<endl;
   cout<<"plain text : "<<p_text;
   return 0;

}