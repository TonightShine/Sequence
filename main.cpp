#include"Sequence.h"
#include<iostream>
#include<fstream>
using namespace std;
int main()
{
  Sequence w("dna.txt");
  cout<<w.length()<<endl;
  cout<<w.numberOf('A')<<endl;
  cout<<w.longestConsecutive()<<endl;
  cout<<"end"<<endl;
  cout<<w.longestRepeated()<<endl;


}
