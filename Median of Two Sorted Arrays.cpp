#include<iostream>
#include<assert.h>

using namespace std;

class Solution {
public:
  double findMedianSortedArrays(int A[], int m, int B[], int n) {
    if(( m+n) %2 == 0){
      int k = (m+n)/2;
      return (findMergeKth(A,m,B,n,k) + findMergeKth(A,m,B,n,k+1))/2;
    } else {
      int  k = (m+n+1)/2;
      return findMergeKth(A,m,B,n,k);
    }
  }
  double findMergeKth(int A[], int m, int B[], int n, int k){
    if( m == 0) 
      return B[k-1];
    if( n == 0)
      return A[k-1];
    // before Ai, there are i numbers, before Bj, there are j numbers. 
    int i = int( m*(k-1)/(m+n) );
    int j =  k-i-1;

    int Ai_1 = (i==0)?  INT_MIN:A[i-1];
    int Ai   = (i==m)?  INT_MAX:A[i];
    int Bj_1 = (j ==0)? INT_MIN:B[j-1];
    int Bj   = (j==n)?  INT_MAX:B[j];
			  
    if(Ai_1 <= Bj && Bj <= Ai)
      return Bj;
    if(Bj_1 <=  Ai && Ai <= Bj)
      return Ai;

    // assert( (Ai < Bj && Ai < Bj_1) || ( Bj < Ai && Bj < Ai_1) );

    if(Ai <= Bj)
      return  findMergeKth(A+i+1, m-i-1,B,n,k-i-1);
    else
      return findMergeKth(A,m,B+j+1,n-j-1,k-j-1);
  }
};

int main(){
  Solution s;
  //int A[] = { 3, 4, 12, 23, 32, 33, 67, 102};
  //int B[] = { -3,2,6,10,14,39,45,55,89,104};
  int A[] = {1,1,2};
  int B[] = {1,2,2};
  //int key =  s.findMergeKth(A, sizeof(A)/sizeof(int),
  //B, sizeof(B)/sizeof(int), 4);
  double key = s.findMedianSortedArrays(A,sizeof(A)/sizeof(int),B,sizeof(B)/sizeof(int));
	
  cout <<  key << endl;
  printf("%d",1<<2);
  getchar();
  return 0;
}
