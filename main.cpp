#include <iostream>
#include <algorithm>
#include "inord_list.h"
#include <string.h>
#include <string>
#include <fstream>
using namespace std;
int main(int argc , char* argv[])
{   if(argc!=3) {cout<<"Incorrect number of arguments"<<endl; return 0;}
    int spaces=0,lines=0,words=0,chars=0,distwords=0,sum=0; string m; inord_list l; int v[1000]; bool file; char cc;
    ifstream mazin;
    mazin.open(argv[1]);
    file=mazin.good();
    if(!file) {cout<<"File not found"<<endl; return 0;}
    while(!mazin.eof())
    {
        getline(mazin,m);
        lines++;
    }
    mazin.close();
    string x[lines];
    mazin.open(argv[1]);
    for(int i=0;i<lines;i++)
    {
        getline(mazin,x[i]);
    }
    mazin.close();
    mazin.open(argv[1]);
    for(int i=0;i<lines;i++)
    {
        int k=x[i].size();
        replace(x[i].begin(),x[i].end(),',',' ');
        replace(x[i].begin(),x[i].end(),';',' ');
        replace(x[i].begin(),x[i].end(),':',' ');
        replace(x[i].begin(),x[i].end(),'`',' ');
        replace(x[i].begin(),x[i].end(),'&',' ');
        replace(x[i].begin(),x[i].end(),'"',' ');
        replace(x[i].begin(),x[i].end(),'.',' ');
        replace(x[i].begin(),x[i].end(),'[',' ');
        replace(x[i].begin(),x[i].end(),']',' ');
        replace(x[i].begin(),x[i].end(),'{',' ');
        replace(x[i].begin(),x[i].end(),'}',' ');
        replace(x[i].begin(),x[i].end(),'(',' ');
        replace(x[i].begin(),x[i].end(),')',' ');
        for(int jj=0;jj<k;jj++)
        {   int jjj=x[i][jj];
            if(jjj==39)
                x[i][jj]=' ';
        }
        for(int j=0;j<k;j++)
        {
            x[i][j]=tolower(x[i][j]);
            int y;
            y=x[i][j];
            if(y==32) spaces++;
        }
    }
    mazin.close();
    mazin.open(argv[1]);
    while(mazin.get(cc))
    {
        sum++;
    }
    mazin.close();
    for(int i=0;i<lines;i++)
    {   int f=x[i][0];
        if(f==32)
        {
            int t1=0,t2=0;
            string word,temp;
            while(t2!=-1)
            {
                t1=x[i].find(" ",t1);
                t2=x[i].find(" ",t1+1);
                if((t2-t1)!=1)
                    {
                        temp=x[i].substr(t1+1,t2-t1-1);
                        if(temp!="")
                            {
                                word=temp;
                                l.insert1(word,i+1);
                                chars=chars+word.size();
                                words++;
                            }
                    }
                t1++;
            }
        }
        else
        {
            int t1=0,t2=0,t3=0;
            string word,temp;
            while(t3!=-1)
            {
                t2=x[i].find(" ",t2);
                temp=x[i].substr(t1,t2-t1);
                if(temp!="")
                {
                    word=temp;
                    l.insert1(word,i+1);
                    chars=chars+word.size();
                    words++;
                }
                t1=t2+1;
                t3=t2;
                t2++;
            }
        }
    }
        bool flag; string word; int c;
        //////////////////////////////////////////////////////////////////
        mazin.open(argv[2]); string command,arg; int comlines=0;
        file=mazin.good();
        if(!file) {cout<<"File not found"<<endl; return 0;}
        while(getline(mazin,m)) comlines++;
        mazin.close();
        string comline[comlines];
        mazin.open(argv[2]);
        for(int i=0;i<comlines;i++)
        {   int t=0, tt=0;
            flag=getline(mazin,comline[i]);
            //int siz=comline[i].size();
            int f=comline[i][0]; string pointer[1000]; int ii=0;
            if(f==32)
            {
                int t1=0,t2=0;
                string temp;
                while(t2!=-1)
                {   t1=comline[i].find(" ",t1);
                    t2=comline[i].find(" ",t1+1);
                    if((t2-t1)!=1)
                        {
                            temp=comline[i].substr(t1+1,t2-t1-1);
                            if(temp!="")
                                {
                                    pointer[ii]=temp;
                                    ii++;
                                }
                        }
                    t1++;
                }
            }
            else
            {
                int t1=0,t2=0,t3=0;
                string temp;
                while(t3!=-1)
                {
                    t2=comline[i].find(" ",t2);
                    temp=comline[i].substr(t1,t2-t1);
                    if(temp!="")
                    {
                        pointer[ii]=temp;
                        ii++;
                    }
                    t1=t2+1;
                    t3=t2;
                    t2++;
                }
            }
            command=pointer[0]; int found=0;
            if(command=="wordCount")
            {   if(ii!=1) { cout<<"Incorrect number of arguments"; tt=1;}
                else
                {
                    t=1;
                    cout<<words<<" words";
                }
                cout<<endl;
            }
            else if(command=="distWords")
            {   if(ii!=1) { cout<<"Incorrect number of arguments"; tt=1;}
                else
                {
                    t=1;
                    flag=l.first(word,c,v);
                    while(flag)
                    {   distwords++;
                        flag=l.next(word,c,v);
                    }
                    cout<<distwords<<" distinct words";
                }
                cout<<endl;
            }
            else if(command=="charCount")
            {   if(ii!=1) { cout<<"Incorrect number of arguments"<<endl; tt=1;}
                else
                {
                    t=1;
                    //int charss=chars+spaces+lines;
                    //if(charss==-1) cout<<"0 characters"<<endl;
                     cout<<sum<<" characters"<<endl;
                }
            }
            else if(command=="countWord")
            {   if(ii!=2) { cout<<"Incorrect number of arguments"<<endl; tt=1;}
                else
                {   t=1;
                    arg=pointer[1];
                    string temp1=arg;
                    int sz=arg.size();
                    for(int j=0;j<sz;j++)
                    {
                        temp1[j]=tolower(temp1[j]);
                    }
                    int e=0;
                    flag=l.first(word,c,v);
                    while(flag)
                    {   if(temp1==word)
                        {
                        e=1;
                        cout<<temp1<<" is repeated "<<c<<" times"<<endl;
                        }
                        flag=l.next(word,c,v);
                    }
                    if(e==0)
                    cout<<temp1<<" is repeated 0 times"<<endl;
                }
            }
            if(command=="frequentWord")
            {   if(ii!=1) {cout<<"Incorrect number of arguments"; tt=1;}
                else
                {
                    t=1;
                    int mx=0;
                    flag=l.first(word,c,v);
                    while(flag)
                    {   if(word!="a"&&word!="an"&&word!="the"&&word!="in"&&word!="on"&&word!="of"&&word!="and"&&word!="is"&&word!="are")
                        {
                            if(c>mx)
                            mx=c;
                        }
                        flag=l.next(word,c,v);
                    }
                    if(mx==0) cout<<"Word not found";
                    else
                    {
                    cout<<"Most frequent word is: ";
                    flag=l.first(word,c,v);
                    while(flag)
                    {   if(c==mx)
                        if(word!="a"&&word!="an"&&word!="the"&&word!="in"&&word!="on"&&word!="of"&&word!="and"&&word!="is"&&word!="are")
                        cout<<word<<" ";
                        flag=l.next(word,c,v);
                    }
                    }
                }
                cout<<endl;
            }
            if(command=="starting")
            {
                if(ii!=2) {cout<<"Incorrect number of arguments"; tt=1;}
                else
                {   t=1;
                    int L;
                    arg=pointer[1];
                    int sz=arg.size();
                    for(int j=0;j<sz;j++)
                    {
                        arg[j]=tolower(arg[j]);
                    }
                    flag=l.first(word,c,v);
                    while(flag)
                    {
                        L=word.find(arg,0);
                        if(L==0)
                        {
                            found=1;
                            cout<<word<<": "<<c<<"\t";
                        }
                        flag=l.next(word,c,v);
                    }
                    if(found==0) cout<<"Word not found";
                }
                cout<<endl;
            }
            if(command=="containing")
            {
                if(ii!=2) {cout<<"Incorrect number of arguments"; tt=1;}
                else
                {
                    t=1;
                    int u;
                    arg=pointer[1];
                    flag=l.first(word,c,v);
                    while(flag)
                    {
                        u=word.find(arg,0);
                        if(u!=-1)
                        {
                            found=1;
                            cout<<word<<": "<<c<<"\t";
                        }
                        flag=l.next(word,c,v);
                    }
                    if(found==0) cout<<"Word not found";
                }
                cout<<endl;
            }
            if(command=="search")
            {
                if(ii!=2) {cout<<"Incorrect number of arguments"<<endl; tt=1;}
                else
                {
                    t=1;
                    int p;
                    arg=pointer[1];
                    flag=l.first(word,c,v);
                    while(flag)
                    {   int prev=0;
                        p=word.find(arg,0);
                        if(p!=-1)
                        {
                            found=1;
                            cout<<word<<":\tlines ";
                            for(int o=0;o<c;o++)
                            {
                                if(o>0) prev=v[o-1];
                                if(v[o]!=prev)
                                cout<<v[o]<<" ";
                            }
                            cout<<endl;
                        }
                        flag=l.next(word,c,v);
                    }
                    if(found==0) cout<<"Word not found"<<endl;
                }
            }
            if(t==0&&tt==0&&ii!=0) cout<<"Undefined command"<<endl;
        }
    mazin.close();
    return 0;
}
