//
//  main.cpp
//  Vigenere
//
//  Created by Aditeya Shukla on 03/08/18.
//  Copyright © 2018 Aditeya Shukla. All rights reserved.
//

#include <iostream>
#include <string.h>
#include <stdlib.h>
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
            //cout<<"key= "<<keyw<<" p="<<p<<endl;
        }
        else if(str[p]>=65&&str[p]<=90){
            keyw.push_back(key[q]);
            q++;
            //cout<<"key= "<<keyw<<" p="<<p<<endl;
        }
        else {
            
            keyw.push_back(str[p]);
            
            
            //cout<<"SPACE key= "<<keyw<<" p="<<p<<endl;
            
        }
    }
    
    return keyw;
}

void ncrpt(string longkey, string str, int table[26][26]){
    int i=str.size(),lky,sty;
    string crypt;
    cout<<"\n CIPHER ";
    for(int z=0;z<i;z++){
        lky=longkey[z];
        sty=str[z];
        if(str[z]>=97&&str[z]<=122||str[z]>=65&&str[z]<=90){
            crypt[z]=table[lky-97][sty-97];
            cout<<crypt[z];
        }
        else{
            cout<<str[z];
        }
    }
    cout<<endl<<endl;
    
}

void solve(string stro, string longkey, int table[26][26]){
    int si=stro.size();
    string orig;
    int orgz,lky;
    char p;
    cout<<"\n Original is:   ";
    for(int w=0;w<si;w++){
        
        for(int x=0;x<26;x++){
            lky = longkey[w]-97;
            orgz = stro[w]-97;
            // cout<<"LKY IS "<<lky<<longkey[w]<<orgz<<stro[w]<<endl;
            if(table[x][lky]==stro[w]){
                //cout<<"X IS "<<x<<endl;
                //char p = x +97;
                cout<<char(x+97)<<" ";
            }
            
            //
        }
        
        //cout<<endl;
        
        
    }
    
}
int main() {
    int table[26][26];
    char a;
    
    string str, key;
    /*str = "hello world";
     key = "adi";*/
    cout<<"ENTER THE MESSAGE TO BE HIDDEN"<<endl;
    getline(cin, str);
    
    cout<<"ENTER KEY"<<endl;
    getline(cin,key);
    string longkey = generateKey(str, key);
    cout<<"\n The Key is now "<<longkey<<endl<<endl;
    for(int i=0;i<26;i++){
        for(int j=0;j<26;j++){
            if(j+i+97>122){
                table[i][j]=j+i+97-26;
                
            }
            else{
                table[i][j]=j+i+97;}
            a = table[i][j];
            cout<<a<<"\t";
            // cout<<table[i][j]<<"\t";
            
        }
        cout<<endl;
    }
    ncrpt(longkey,str,table);
    string stro = "hhtlr eoutd";
    solve(stro, longkey, table);
    return 0;
}

