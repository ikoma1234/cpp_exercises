#include <iostream>
#include <fstream>
#include <unordered_set>
#include <set>

using namespace std;

struct Point {
    int x, y;
};

namespace std {

template<>
struct hash<Point> {
    std::size_t operator()(const Point & obj) const{
        return hash<int>{}(obj.x) ^ hash<int>{}(obj.y);
    }
};

template<>
struct equal_to<Point> {
    bool operator()(const Point& p1, const Point& p2) const{
        return (p1.x == p2.x) && (p1.y == p2.x);
    }
};

}

int main(void) {
 
 unordered_set<Point> table;

 ifstream in("point_list.txt");

 cout << "Reading points from file" << endl;
 while (!in.eof()) {
  int x, y;
  in >> x >> y;

  Point p{x,y};
  table.insert(p);
 }
 cout << "Points read from file. Now enter some query point." << endl;

 while (std::cin) {
  int x, y;
  cin >> x >> y;
  Point p{x,y};

  if(table.find(p) != table.end()){
      cout << "point found" << endl;
  }
  else {
      cout << "not found" << endl;
  }
 }
 return 0;
}