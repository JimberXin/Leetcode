#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	//for example, num1 ={3,3,3,3,3,3,3,0,1,2,3}; num2 ={4,4,3,4,4,4,4,4,4,4,4,4}
    int findMinHelper(vector<int> &num, int low, int high){
		 int result = num[low];
		 for(int i = low;  i <= high; ++i){
			   if(result > num[i])
				   return num[i];
		 }
		 return result;
	}

    int findMin(vector<int> &num) {
        int n = num.size();
		if(n == 1)
			return num[0];
		int left = 0;
		int right = n-1;
		int mid = 0;
		while(num[left] >= num[right])
		{
			if(right - left == 1)
				return num[right];

			mid = left + (right - left)/2;
			if(num[left] == num[right] && num[left] == num[right])
				return findMinHelper(num,left,right);
			if(num[left] <= num[mid])
				left = mid;
			else if(num[right] >= num[mid])
				right = mid;
		}
		return num[mid];
    }
};

int main(){
	Solution s;
	int arr[] = {10,1,10,10,10};
	vector<int> num;
	for(int i = 0; i < sizeof(arr)/sizeof(int); ++i)
		num.push_back(arr[i]);
	int findM = s.findMin(num);
	cout << findM << endl;
	getchar();
	return 0;
}
	