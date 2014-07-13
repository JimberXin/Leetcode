#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int> > combinationSum2(vector<int> &num, int target) 
    {
        //
          sort(num.begin(),num.end());
		  vector<vector<int> > result;
		  vector<int> temp;
		   DFS(num,target,0,temp,result);
           return result;
        //
    }
	void DFS(vector<int>&num, int gap, int current, vector<int>  &temp, vector<vector<int> > &result)
	{
		if(gap == 0)
		{
			 result.push_back (temp);
			 return;
		}

		int last = -1;  // mark last time vist

		for(size_t  i= current; i< num.size(); i++)
		{
				if(last == num[i])  continue;   //make sure that the value has not yet been visited
			    if(gap < num[i] )
					return;    //cut it down
			    last = num[i];
				temp.push_back(num[i]);
				DFS(num,gap-num[i],i+1,temp,result);  //the current index becomes i+1, not i
				temp.pop_back ();
		}
	}
};

int main(void)
{
	int arr[] = {10,1,2,7,6,1,5};
	Solution s;
	vector<int> num;
	for(int i=0; i< sizeof(arr)/sizeof(int);i++)
		num.push_back (arr[i]);
	vector<vector<int> > result = s.combinationSum2(num,8);
	vector<vector<int> >::iterator outside;
	vector<int>::iterator inside;
	for(outside=result.begin(); outside != result.end(); outside++)
	{
		  for(inside = outside -> begin(); inside != outside -> end(); inside++)
			    cout << *inside << " " ;
		  cout << endl;
	}
	 getchar();
	 return 0;
}