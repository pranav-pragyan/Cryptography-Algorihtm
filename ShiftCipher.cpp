//Name - Pranav Kumar
//Roll No. - CSB19065
// 2.A. Progam to implement shift cipher
#include<iostream>
#include<vector>
#include<time.h>
#include<string>
using namespace std;

int key_gen()
{
  srand(time(0));
  int key = rand()%26;
  return key;
}
string encryprtion(string msg,int key)
{
   for(auto i=msg.begin();i!=msg.end();i++)
   {
     if(*i==' ')
      continue;
     int msg_text_int=*i-'a';
     msg_text_int = (msg_text_int+key)%26;
     *i=msg_text_int+'a';
   }
   return msg;
}
string decryprtion(string cipher_txt,int key)
{
   key = 26-key;
   for(auto i=cipher_txt.begin();i!=cipher_txt.end();i++)
   {
     if(*i==' ')
      continue;
     int c_text_int=*i-'a';
     c_text_int = (c_text_int+key)%26;
     *i=c_text_int+'a';
   }
   return cipher_txt;
}
int main()
{
    string msg;
    cout<<"Enter the plain-text : "<<endl;
    getline(cin,msg);
    int key = key_gen();
    cout<<"\nkey  '"<<key<<"'"<<endl;
    string cipher_text = encryprtion(msg,key);
    cout<<"\nCipher text : "<<cipher_text<<endl;
    string msg_text = decryprtion(cipher_text,key);
    cout<<"\nPlain text = "<<msg_text<<endl;
    return 0;

}