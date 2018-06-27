#include"Sequence.h"
#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;


Sequence::Sequence(string filename)
{
  fin.open(filename,ios::in|ios::app);
  char a ,last='h';
  int count =1;
  while(fin.get(a))
  {
  
   if(a=='C') sum_C++;  
   if(a=='G') sum_G++;
   if(a=='A') sum_A++; 
   if(a=='T') sum_T++;
   

   
   if(last==a) count++; else count=1;
   if(longest<count) {longest=count;longest_base=a;}
   last=a;
   data.push_back(a);
  }
  
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
string Sequence::longestRepeated()
{
   int longest_begin=0;
   int len=longest-1;
 
 
 for(int a_begin=0;a_begin<data.size();a_begin++)
 {
  
      for(int b_begin=a_begin+1;b_begin<data.size();b_begin++)
      {
         for(int i=0;i<=len;i++)
         {
            if( ((b_begin)+i)<data.size()  && (a_begin+i)<data.size() )
              {
               if(data[a_begin+i]==data[b_begin+i])  
               {
                 if(i==len) {len=i+1;longest_begin=b_begin;}
               }
               else {break;}
              }
         }
      }
 }
 


 string l="";
 for(int i=0;i<len;i++)
 {
   l=l+data[longest_begin+i];
 }
 
 return l;
}

