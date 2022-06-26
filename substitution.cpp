//Name - Pranav Kumar
//Roll No. - CSB19065
// 2.B. Progam to implement Substitution cipher
#include<iostream>
#include<string>
#include<vector>
using namespace std;

string encryption(string msg,vector<char> key)
{
    for(int i=0;i<msg.length();i++)
    {
        if(isupper(msg[i]))
            msg[i]= tolower(msg[i]);
        if(msg[i]>='a'&&msg[i]<='z')
            msg[i]=key[msg[i]-'a'];
    }

    return msg;

}

string decryption(string c_text,vector<char>key)
{
    string p_text;
    for(int i=0;i<c_text.length();i++)
    {
        if(c_text[i]>='a'&&c_text[i]<='z')
        {
            for(int j=0;j<26;j++)
            {
                if(c_text[i]==key[j])
                {
                    p_text.push_back(j+'a');
                    break;
                }    
            } 
        }
        else
            p_text.push_back(c_text[i]);
        
    }
    return p_text;
}
int main(){

    string msg;
    cout<<"Enter the massege : ";
    getline(cin,msg);
    vector<char>key{'d','a','z','m','b','n','e','r','y','w','o','h','f','l','i','x','u','t','j','c','q','s','p','g','v','k'};
    string cipher_text=encryption(msg,key);
    string plain_text=decryption(cipher_text,key);
    cout<<"Cipher Text : "<<cipher_text<<endl;
    cout<<"Recieved Plain Text : "<<plain_text<<endl;


}



