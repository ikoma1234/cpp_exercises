#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

struct Point {
    Point():x(0.0), y(0.0), z(0.0) {
    }
    Point(double x, double y, double z) : x(x), y(y), z(z) {
    }
    
    double x, y, z;
};

struct CompareDistance {
    bool operator()(Point& p1, Point& p2){
        double nagasa1 = 0, nagasa2 = 0;
        nagasa1 = sqrt(pow(p1.x, 2)+pow(p1.y, 2)+pow(p1.z, 2) );
        nagasa2 = sqrt(pow(p2.x, 2)+pow(p2.y, 2)+pow(p2.z, 2) );
        return nagasa1 > nagasa2;
    }
};

vector<Point> find_k_closest(int k, vector<Point> p) {
    priority_queue<Point, vector<Point>, CompareDistance> que;

    int i;
    for(i=0; i<6; i++){
        que.push(p[i]);
    }
    vector<Point> ans;
    for(i=0; i<k; i++){
        ans.push_back(que.top());
        que.pop();
    }
    return ans;
}

int main(void) {
    vector<Point> points;

    points.push_back(Point(1.0,2.0,3.0));
    points.push_back(Point(5.0,5.0,5.0));
    points.push_back(Point(0.0,2.0,1.0));
    points.push_back(Point(9.0,2.0,1.0));
    points.push_back(Point(1.0,2.0,1.0));
    points.push_back(Point(2.0,2.0,1.0));

    vector<Point> closest = find_k_closest(3, points);
    for (size_t i=0; i<3; ++i) {
    cout << closest[i].x << "," << closest[i].y << "," << closest[i].z << endl;
    }

}