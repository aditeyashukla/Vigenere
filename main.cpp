//
//  main.cpp
//  h
//
//  Created by Aditeya Shukla on 03/08/18.
//  Copyright © 2018 Aditeya Shukla. All rights reserved.
//

#include <iostream>
#include <string.h>
using namespace std;


string generateKey(string str, string key)
{
    int x = str.size();
    int q=0;
    int t = key.size();
    string keyw;
    /*
    for (int i = 0; ; i++)
    {
        if (x == i)
            i = 0;
        if (key.size() == str.size())
            break;
        key.push_back(key[i]);
    }*/
    for(int p=0;p<x;p++){
        if(q>=t){q=0;}
        if(str[p]>=97&&str[p]<=122){
            keyw.push_back(key[q]);
            q++;
            cout<<"key= "<<keyw<<" p="<<p<<endl;
        }
        else if(str[p]>=65&&str[p]<=90){
            keyw.push_back(key[q]);
            q++;
            cout<<"key= "<<keyw<<" p="<<p<<endl;
        }
        else {
            
            keyw.push_back(str[p]);
            
            
            cout<<"SPACE key= "<<keyw<<" p="<<p<<endl;
            
        }
    }
     
    return keyw;
}

void solve(string longkey, string str, int table[26][26]){
    int i=str.size(),lky,sty;
    string crypt;
    cout<<"CIPHER ";
    for(int z=0;z<i;z++){
        lky=longkey[z];
        sty=str[z];
        crypt[z]=table[lky-97][sty-97];
        cout<<crypt[z]<<"\t";
    }
    
}

int main() {
    int table[26][26];
    
    for(int i=0;i<26;i++){
        for(int j=0;j<26;j++){
            if(j+i+97>122){
                table[i][j]=j+i+97-26;
            }
            else{
                table[i][j]=j+i+97;}
            
       // cout<<table[i][j]<<"\t";
            
        }
        cout<<endl;
    }
    string str = "hello world";
    string key = "adi";
    string longkey = generateKey(str, key);
    cout<<longkey;
    solve(longkey,str,table);
    return 0;
}
