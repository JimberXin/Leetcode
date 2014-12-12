#include<iostream>
#include<vector>
#include<map>
using namespace std;

class Solution {
public:
  vector<int> twoSum(vector<int> &numbers, int target) 
  {
    //  initial method, time complexity is O(n^2)
    /*
      vector<int>::iterator start, end;
      vector<int> index;
      int index1, index2;
      for(start = numbers.begin(); start!= numbers.end(); start ++)
      {
      for(end = start + 1; end != numbers.end(); end++)
       if( (*start + *end) == target)
       {
        index1 = start - numbers.begin() + 1;
        index2 = end -  numbers.begin() + 1;
        index.push_back(index1);
	index.push_back(index2);
	return index;
       }
      }
        start =  numbers.begin();
	end =  numbers.end() -1;
	while(start != end)
	{
	  if ((*start + *end) == target )
	   {
	     index1 = start - numbers.begin() + 1;
	     index2 = end -  numbers.begin() + 1;
	     index.push_back(index1);
	     index.push_back(index2);
	     return index;
	   }
	   else if ( (*start + *end) > target)
	     end -- ;
	   else
	     start ++;
	   }

    */
    map<int,int> mapping;
    map<int,int>::iterator iter;
    vector<int> index;
    for(int i =0 ;i<numbers.size(); i++)
      {
	iter = mapping.find(target - numbers[i]);
	if( iter != mapping.end() )
	  {
	    index.push_back(iter -> second);
	    index.push_back(i+1);
	    break;
	  }
	else
	  mapping[numbers[i]] = i+1;
      }
    return index;
    //
  }
};


int main()
{
  Solution s;
  //int num[] = {3,2,4};
  int num[] = {0,2,4,6,8,10,12,14,16,18,20,22,24,26,28,30,32,34,36,38,40,42,44,46,48,50,52,54,56,58,60,62,64,66,68,70,72,74,76};
  vector<int> v;
  for(int i =0; i<sizeof(num)/sizeof(int); i++)
    v.push_back(num[i]);
  vector<int> index = s.twoSum(v,40);
  vector<int>::iterator it ;
  for(it =  index.begin(); it != index.end();it++)
    cout << *it << " ";
  cout <<  endl;
  getchar();
  return 0;
}
