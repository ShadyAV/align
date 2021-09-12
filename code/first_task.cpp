#include <iostream>
#include <vector>
#include <fstream>
#include <string>
using namespace std;

struct Point {
    Point(double x0, double y0) : x(x0), y(y0) {}
    double x;
    double y;
};

int pnpoly(Point point_coords, vector<Point> polygon_coords)
{
    int i, j, c = 0;
    for (i = 0, j = polygon_coords.size() - 1; i < polygon_coords.size(); j = i++) {
        if (((polygon_coords[i].y > point_coords.y) != (polygon_coords[j].y > point_coords.y)) &&
            (point_coords.x < (polygon_coords[j].x - polygon_coords[i].x) * (point_coords.y - polygon_coords[i].y) / (polygon_coords[j].y - polygon_coords[i].y) + polygon_coords[i].x))
            c = !c;
    }
    return c;
}

int main() {
    int n, m, count = 0;
    Point polygon_coords = Point(0, 0);
    Point point_coords = Point(0, 0);
    vector <Point> polygon;
    cin >> n >> m;
    for (int i = 0; i < 2 * n; i++) {
        cin >> polygon_coords.x >> polygon_coords.y; 
        polygon.push_back(polygon_coords);
    }
    for (int i = 0; i < m; i++) {
        cin >> point_coords.x >> point_coords.y;
        if (pnpoly(point_coords, polygon) == 1) {
            count++;
        }
    }
    cout << count;
}
