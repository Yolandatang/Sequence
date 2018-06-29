#include"Sequence.h"
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>

Sequence::Sequence(string fliename)
{
  const char* file=fliename.c_str();
  ifstream test(file,ios::in);
  string str;
  while(getline(test,str))
  {
    for(int i=0;i<str.length()+1;i++)
     {
       if(str[i]=='A')
         a++;
       else if(str[i]=='C')
         c++;
       else if(str[i]=='T')
         t++;
       else if(str[i]=='G')
         g++;
     }   
    if(str[0]=='\n')
      continue;
    else
      strFile.insert(strFile.length(),str,0,str.size());
  }
}

int Sequence::length()
{
  return strlen(strFile.c_str());
}

int Sequence::numberOf(char base)
{
  if(base=='A')
   return a;
  if(base=='C')
   return c;
  if(base=='T')
   return t;
  if(base=='G')
   return g;
}

string Sequence::longestConsecutive()
{
  int len1=0,len2=0,x;
  char most;
  string con;
  int i=0;
  while(i<strFile.length())
   {
     while(strFile[i]==strFile[i+1])
     {
      len1++;
      i++;
     }
     if(len1>len2)
     {
       len2=len1;
       x=i;
     }  
    len1=0;
    i++;
  }
  con=strFile.substr(x-len2,len2+1);
  return con;
}

int pstrcmp(const void *a,const void*b)
{
  return strcmp(*(char**)a,*(char**)b);
}

int Sequence::comlen(char *str1,char *str2)
{
  int i=0;
  while(*str1&&(*(str1++)==*(str2++)))
    ++i;
  return i;
}

bool equal(char *str,int b)
{
  int c=0;
  for(int i=0;i<b;i++)
  {
    if(str[0]==str[i])
    {
      c++;
    }
  }
  if(c==b)
   return true;
  return false;
}

string Sequence::longestRepeated()
{
  int maxlen=0;
  char*str=const_cast<char*>(strFile.c_str());
  int length=strlen(str);
  char** a=new char *[length+1];
  for(int i=0;i<length;++i)
     a[i]=&str[i];
  qsort(a,length,sizeof(char **),pstrcmp);
  int maxi=INT_MIN;
  char *maxPtr=0;
  for(int i=1;i<length;i++)
  {
    int length=comlen(a[i-1],a[i]);
    if(equal(a[i-1],length))
    {
      length=0;
    }
    if(length>maxlen)
    {
      maxlen=length;
      maxPtr=a[i-1];
    }
  }
  stringstream stream;
  for(char *s=maxPtr;s<maxPtr+maxlen;s++)
  {
    stream<<(*s);
  }
  return stream.str();
  delete[] a;
}
