#include"Sequence.h"
#include<iostream>
#include<string>
#include<fstream>
#include<vector>
using namespace std;
int main()
{
  Sequence w("/data/dna.txt");
  cout<<w.length()<<endl;
  cout<<w.numberOf('A')<<endl;
  cout<<w.longestConsecutive()<<endl;
  cout<<w.longestRepeated()<<endl;


}
