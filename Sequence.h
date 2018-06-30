#ifndef SEQUENCE_H
#define SEQUENCE_H


#include <string>
#include <fstream>
#include <vector>
#include<cmath>
#include<bits/stdc++.h>
using namespace std;
class Sequence 
{
public:
  Sequence( string filename);
  int length();
  int numberOf(char base);
  string longestConsecutive();
  string longestRepeated();
private:    
  vector<char> data;
  fstream fin;
  int sum_A = 0,sum_C = 0,sum_G = 0,sum_T = 0;
  int longest_base,longest = 1;
  string k; 
};
#endif
