//Name - Pranav Kumar
//Roll No. - CSB19065
// 2.A. Progam to implement Viginere cipher
#include<iostream>
#include<vector>
#include<time.h>
#include<math.h>
#include<string>
using namespace std;

vector<int> key_gen(int msg_len)
{
  srand(time(0));
  int len = rand()%msg_len+1;
  vector<int> key;
  
  for(int i=0;i<len;i++)
  {
    key.push_back(rand()%26);
  }

  return key;
  
}

string encryprtion(string msg,vector<int> key)
{
 int j=0;
   for(int i=0;i<msg.length();i++)
   {
     if((msg.length()-i)<key.size())
       {
              if(msg[i]==' ')
                continue;
              else
              {
                int msg_char_int=msg[i]-'a';
                msg_char_int = (msg_char_int+key[j%key.size()])%26;
                msg[i]= msg_char_int+'a';
                
              }
        }
        else
        {
              if(msg[i]==' ')
                 continue;
               else
               {
                 int msg_char_int=msg[i]-'a';
                 msg_char_int = (msg_char_int+key[j%key.size()])%26;
                 msg[i]= msg_char_int+'a';
                 
               }
        }
    }

    return msg;   
}

string decryprtion(string c_text ,vector<int> key)
{
   for(int i=0;i<key.size();i++)
     key[i]=26-key[i];
   int j=0;
   for(int i=0;i<c_text.length();i++)
   {
     if((c_text.length()-i)<key.size())
       {
              if(c_text[i]==' ')
                continue;
              else
              {
                int msg_char_int=c_text[i]-'a';
                msg_char_int = (msg_char_int+key[j%key.size()])%26;
                c_text[i]= msg_char_int+'a';
                
              }
        }
        else
        {
              if(c_text[i]==' ')
                 continue;
               else
               {
                 int msg_char_int=c_text[i]-'a';
                 msg_char_int = (msg_char_int+key[j%key.size()])%26;
                 c_text[i]= msg_char_int+'a';
                 
               }
          }
    }

    return c_text; 
}
int main()
{
    string msg;
    cout<<"Enter the plain-text : ";
   getline(cin,msg);
   vector<int> key=key_gen(msg.length());
   string cipher_text= encryprtion(msg,key);
   string plain_text = decryprtion(cipher_text,key);
   cout<<"size of key : "<<key.size()<<endl;
   cout<<"The key : ";
   for(auto i=key.begin();i!=key.end();i++)
     cout<<*i<<" ";
   cout<<endl;
   cout<<"cipher text :"<<cipher_text<<endl;
   cout<<"plain text recieved : "<<plain_text;
  return 0;
}