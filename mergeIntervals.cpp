#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
struct Interval{
  int start;
  int end;
  Interval(): start(0),end(0){}
  Interval(int s, int e): start(s),end(e){}
};

class Compare
{
public:
  bool  operator()(const Interval& I1, const Interval& I2)
  {
    return I1.start < I2.start? true:false;
  }
};

class Solution {
public:
  vector<Interval> merge(vector<Interval> &intervals) 
  {
    //
    /* vector<Interval> result;
       if (intervals.size() == 0 || intervals.size() == 1)
          return intervals;
       sort(intervals.begin(),intervals.end(),Compare());
       vector<Interval>::iterator current, next;
       current = intervals.begin();
			 
       while( (current+1) != intervals.end() )
       {
          next = current +1;
	  if( next->start  <= current -> end && next ->end <= current -> end )
	  intervals.erase(next);
	  else if(next -> start  <= current -> end && next -> end >= current -> end)
	  {
	     current -> end = next -> end;
	     intervals.erase(next);
	  }
	  else
	     current  = next;
	  }
	  return intervals;*/

    vector<Interval> result;
    if (intervals.size() == 0 || intervals.size() == 1)
      return intervals;
    sort(intervals.begin(),intervals.end(),Compare());
    result.clear();
    result.push_back(intervals[0]);
    for(int i=1; i<intervals.size();i++)
      {
	int size = result.size();
	if( result[size-1].end >= intervals[i].start )
	  result[size-1].end = max(result[size-1].end,intervals[i].end);
	else
	  result.push_back(intervals[i]);
      }
    return result;               
  }
};

int main()
{
  Solution s;
  vector<Interval> res;
  int arr[] ={1,2,2,3,3,4,6,7,8,9,13,20,14,19,16,23};
  for(int i=0;i<sizeof(arr)/sizeof(int);i++){
      Interval temp(arr[i],arr[i+1]);
      res.push_back(temp);
      i++;		  
  }	
  vector<Interval> result  = s.merge(res);
  getchar();
  return 0;
}
	
