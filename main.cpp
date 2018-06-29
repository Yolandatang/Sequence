#include"Sequence.h"

int main()
{
  string file;
  cout<<"Please enter the filename."<<endl;
  cin>>file;
  Sequence a1(file);
  int c;
  c=a1.length();
  cout<<c<<endl;
  int b;
  b=a1.numberOf('A');
  cout<<b<<endl;
  string f;
  f=a1.longestConsecutive();
  cout<<f<<endl;
  string q;
  q=a1.longestRepeated();
  cout<<q<<endl;
  return 0;

}
