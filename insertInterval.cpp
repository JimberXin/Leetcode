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

struct Interval 
{
      int start;
      int end;
      Interval() : start(0), end(0) {}
      Interval(int s, int e) : start(s), end(e) {}
  };

class Compare
{
	     bool operator()(const Interval& I1, const Interval& I2)
		 {
			 return I1.start < I2.start? true:false;
		 }
};

class Solution {
public:
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval)
    {
        //
         /*  vector<Interval> result;
		   Interval temp;
		   if(intervals.size() == 0)
		    {
				result.push_back(newInterval);
				return result;
		    }
		   for(size_t i=0; i< intervals.size(); i++)
		   {

			   if(newInterval.start >= intervals[i].start && newInterval.start <= intervals[i].end)
			     {
				     temp.start = intervals[i].start;
					 while( i < intervals.size() &&  newInterval.end >= intervals[i].end)
                           ++i;
					      if(i == intervals.size() || newInterval.end < intervals[i--].start)
						      temp.end  = newInterval.end;
					      else
						      temp.end = intervals[++i].end;
					 result.push_back(temp);
			      }
			   else	              
			        result.push_back(intervals[i]);
		   }
		   if(newInterval.start > intervals[intervals.size()-1].end)
			   result.push_back(newInterval);
            return result;*/
        
		  vector<Interval> result;
		  vector<Interval>::iterator it;
		  bool flag = true;
		  for(it = intervals.begin(); it != intervals.end(); it++)
		  {
			     if(it->end < newInterval.start)
				 {
					 result.push_back(*it);
					 continue;
				 }
				 if(it -> start  >  newInterval.end)
				 {
					 if(flag)
					  {
						 result.push_back(newInterval);
						 flag = false;
					  }
					 result.push_back(*it);
					 continue;			     
				 }
				 newInterval.start =  it->start < newInterval.start? it-> start: newInterval.start;
				 newInterval.end  =  it -> end > newInterval.end? it->end: newInterval.end;
		  }
		  if(flag)
			  result.push_back(newInterval);
		  return result;
        //
        
    }
};

int main()
{
	Solution s;
	vector<Interval> res;
	int arr[] ={1,5};
	Interval newIn;
	newIn.start = 6;
	newIn.end = 8;
	for(int i=0;i<sizeof(arr)/sizeof(int);i++)
	{
		  Interval temp(arr[i],arr[i+1]);
		  res.push_back(temp);
		  i++;	  
	}
	
	vector<Interval> result  = s.insert(res,newIn);
	getchar();
	return 0;
}
	
	