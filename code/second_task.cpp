#define _USE_MATH_DEFINES
#include <iostream>
#include <vector>
#include <random>
#include <math.h>
using namespace std;

struct Point {
    Point(double x0, double y0) : x(x0), y(y0) {}
    double x;
    double y;
};

double angleBetween(const Point& v2)
{
    auto angle = atan2(v2.y, v2.x);
    return (angle < 0.0) ? (angle + 2.0 * M_PI) : angle;
}
//to sort by angle
struct myclass {
    bool operator() (Point& i, Point& j) { return (angleBetween(i) < angleBetween(j)); }
} myobject;

int main() {
    random_device rd;
    const auto seed = rd();
    mt19937 mt(seed);
    uniform_int_distribution<int> dist(-100, 100);

    vector<Point> numbers;
    int N = 0;
    cin >> N;
    for (int i = 0; i < N; i++) {
        numbers.push_back(Point(dist(mt), dist(mt)));
    }
    for (int i = 0; i < N - 1; i++) {
        cout << numbers[i].x << " ";
        cout << numbers[i].y << endl;
    }
    int R = 80;
    for (int i = numbers.size()-1; i > 0; i--) {
        double distance = abs(R - sqrt(pow(numbers[i].x, 2) + pow(numbers[i].y, 2)));
        if (distance >= 10) {
            numbers.erase(numbers.begin()+i);
        }
    }
    cout << endl << "Sorted by distance" << endl;
    for (int i = 0; i < numbers.size()-1; i++) {
        cout << numbers[i].x << " ";
        cout << numbers[i].y << endl;
    }
   
    sort(numbers.begin(), numbers.end(), myobject);

    cout << endl << "Sorted by angle" << endl;
    for (int i = 0; i < numbers.size() - 1; i++) {
        cout << numbers[i].x << " ";
        cout << numbers[i].y << endl;
    }
}
