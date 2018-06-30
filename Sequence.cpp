#include"Sequence.h"
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include<algorithm>
#include<string.h>
using namespace std;
string k;
Sequence::Sequence( string filename)
{

  
  fin.open(filename.c_str(),ios::in|ios::app);
  if(!fin) {cout<<"failed";}
  char a ,last='h';
  int count =1;
  while(fin.get(a))
  {
   switch(a)
   { 
   case 'C': sum_C++;k += 'C';data.push_back(a);break;  
   case 'G': sum_G++;k += 'G';data.push_back(a);break;
   case 'A': sum_A++;k += 'A';data.push_back(a);break;
   case 'T': sum_T++;k += 'T';data.push_back(a);break;
   default:  break;
   }
   if(last==a) count++; else count=1;
   if(longest<count) {longest=count;longest_base=a;}
   last=a;
  
  }
  fin.close();
}


int Sequence::length()
{
 return data.size();
}


int Sequence::numberOf(char base)
{
    if(base=='C') return sum_C; 
    if(base=='G') return sum_G;
    if(base=='A') return sum_A; 
    if(base=='T') return sum_T;
        
}


string Sequence::longestConsecutive()
{
   string c;
   c.assign(longest,longest_base);
   return c;
   
}

int  judge(const void *m,const void *n)
{
   char **pm=(char**)m;
   char **pn=(char**)n;
   return strcmp(*pm,*pn);

}


int comlength(char *m,char *n)
{
  int i=0;
  while(*m && (*m++ == *n++))
  {i++;}
  return i;
}


char a[1200000],*b[1200000];
string Sequence::longestRepeated()
{ 
  
   
  
   
   const  int maxlen=k.length();
   
   for (int i=0;i<maxlen;++i)
   {
     a[i]=k[i];b[i]=&a[i];
   }
  
   
   
   b[maxlen]=0;b[maxlen+1]=0;
   qsort(b,maxlen,sizeof(char*),judge);
  
  

   int maxi=0,len=0,z=-1;
   for(int i=1;i<maxlen;++i){
     len=comlength(b[i-1],b[i]);
     if(len>z) {z=len;maxi=i;}
   }
  


  string str;
  for(int i=0;i<z;++i)
  str=str+b[maxi][i];
  return str;
  
 
 
}


