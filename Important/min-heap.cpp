#include <bits/stdc++.h>
using namespace std;
#define vt vector
#define pq priority_queue
#define pb push_back
#define all(c) (c).begin(), (c).end()
#define sz(x) (int)(x).size()

class Point
{
    int x;
    int y;

public:
    Point(int x, int y)
    {
        this->x = x;
        this->y = y;
    }

    int getX() const
    {
        return x;
    }

    int getY() const
    {
        return y;
    }
};

class myComparator
{
public:
    int operator()(const Point &p1, const Point &p2)
    {
        return p1.getX() > p2.getX();
    }
};

int main()
{
    pq<Point, vector<Point>, myComparator> q;

    q.push(Point(10, 2));
    q.push(Point(2, 1));
    q.push(Point(3, 1));
    q.push(Point(1, 10));

    while (q.empty() == false)
    {
        Point p = q.top();
        cout << "(" << p.getX() << ", " << p.getY() << ")";
        cout << endl;
        q.pop();
    }

    return 0;
}
