#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
 
int main()
{
  int a[] = {7, 7, 7,  9, 9, 10};
  vector<int> v(a, a+6);
  cout <<"\nHere are the contents of v:\n";
  for (vector<int>::size_type i=0; i<v.size(); i++)
    cout <<v.at(i)<<" ";  
 
  int upper;

 int lower;
  upper = upper_bound(v.begin(), v.end(), 7)-v.begin();
  lower = lower_bound(v.begin(), v.end(), 7)-v.begin();
 
    cout <<"\nUpper bound of 7 in v = "<<v[upper];
    cout <<"\nUpper bound of 7 in v = "<<v[lower];
 
 
 
  return 0;
}
