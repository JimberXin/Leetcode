#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) {
       //
        int Left = searchPos(A,0,n-1,target,true);
		int Right = searchPos(A,0,n-1,target,false);
		vector<int> result;
		result.push_back(Left);
		result.push_back (Right);
		return result;
       //
        
    }

public:
	 int searchPos(int A[],  int beg, int end,  int key,  bool isLeftOrRight)
	 {
		      if( beg > end)
				  return -1;
			  
			  int mid = beg + (end - beg)/2;
			  if( A[mid] == key)
			  {
				    int pos = isLeftOrRight?searchPos(A,beg,mid-1,key,isLeftOrRight): searchPos(A,mid+1,end,key,isLeftOrRight);
 				     return pos== -1?mid: pos;
			  }
			  else if(A[mid]<key)
				  return searchPos(A,mid+1,end,key,isLeftOrRight);
			  else
				  return searchPos(A,beg,mid-1,key,isLeftOrRight);
	 }
};

int main()
{
	Solution s;
	int a[] = {5,5,5,5,5,5,6};
	vector<int> range = s.searchRange(a,sizeof(a)/sizeof(int),5);
     //cout << *(range.begin() )<< " "  << *(range.end());
	 getchar();
	 return 0;
}