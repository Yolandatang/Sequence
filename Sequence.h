#ifndef SEQUENCE_H
#define SEQUENCE_H
#include<cstdio>
#include<sstream>
#include<stdlib.h>
#include<iostream>
#include<string>
#include<fstream>
#include<string.h>
#include<algorithm>
#include<vector>
#include<limits.h>
using namespace std;
class Sequence
{
public:
  Sequence(string fliename);
  ~Sequence(){}
  int length();
  int numberOf(char base);
  string longestConsecutive();
  string longestRepeated();
  int comlen(char*str1,char*str2);
private:
  string strFile;
  int a;
  int c;
  int g;
  int t;
};
#endif
