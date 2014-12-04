#include<iostream>
#include<vector>
#include<map>

using namespace std;

/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
struct Point {
  int x;
  int y;
  Point() : x(0), y(0) {}
  Point(int a, int b) : x(a), y(b) {}
};

class Solution {
public:
  int maxPoints(vector<Point> &points) {
    map<float,int> HashMap;
    int maxNum = 0;
    float k;
    for(int i = 0; i < points.size(); i++){
      // in case that points[] has only one point or only duplicates
      HashMap[INT_MIN] = 0;  
      int duplicates = 1;
      for(int j = 0;  j < points.size(); j++){
	if( j == i) continue;
	if(points[j].x == points[i].x && points[j].y == points[i].y) {
	  duplicates++;
	  continue;
	}
	if(points[i].x == points[j].x)
	  k = INT_MAX;
	else
	  k = (float)(points[j].y - points[i].y)/(points[j].x - points[i].x);
	HashMap[k] ++;
      }		  
      map<float,int>::iterator it;
      for(it = HashMap.begin(); it != HashMap.end(); it++)
	{
	  if(it ->second + duplicates > maxNum)
	    maxNum = it -> second + duplicates;
	}
      HashMap.clear();
    }
    return maxNum;
  }
};

int main(void){
  Solution s;
  vector<Point> points;
  points.push_back(Point(7,7));
  points.push_back(Point(3,2));
  points.push_back(Point(5,4));
  points.push_back(Point(8,8));
  points.push_back(Point(6,3));
  points.push_back(Point(11,11));
  points.push_back(Point(0,1));
  int result = s.maxPoints(points);
  getchar();
  return 0;
}
