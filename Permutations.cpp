#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	bool isVisited[200];
	void DFS(vector<vector<int> >&result,  vector<int> &temp, vector<int> &num, int index)
	{
		   if(temp.size() == num.size() )
		   {
			   result.push_back(temp);
			   return;
		   }

		   for(size_t i=0; i < num.size(); i++)
		   {
			      if( !isVisited[i])
				  {
					  temp.push_back(num[i]);
					  isVisited[i] = 1;    // mark the currrent num
					  DFS(result, temp, num,i+1);
					  isVisited[i] =  0;  // restore
					  temp.pop_back();
				  }
		   }
	}
    vector<vector<int> > permute(vector<int> &num) 
    {
        //
           vector<vector<int> > all;
		   vector<int> temp;
		   memset(isVisited,0,sizeof(isVisited));
		   DFS(all,temp,num,0);
		   return all;
              
        //        
    }
};

int main(void)
{
	  Solution s;
	  int arr[] = {1,2,3};
	  vector<int> numbers;
	  for(int i=0; i<sizeof(arr)/sizeof(int);i++)
		  numbers.push_back(arr[i]);
	  vector<vector<int> > result = s.permute(numbers);
	  getchar();
	  return 0;
}