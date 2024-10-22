class Point
{
private:
    static double get_distance(const Point &point)
    {
        return sqrt(pow(point.x, 2) + pow(point.y, 2));
    }
public:
    int x;
    int y;
    Point(int x, int y) : x(x), y(y){};

    bool operator<(const Point &p) const
    {
        return get_distance(*this) < get_distance(p);
    }
};

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<Point> heap;
        for (const auto &point : points)
        {
            heap.push(Point{point[0], point[1]});
            if (heap.size() > k)
            {
                heap.pop();
            }
        }
        vector<vector<int>> res;
        while (!heap.empty())
        {
            auto top = heap.top();
            heap.pop();
            res.push_back({top.x, top.y});
        }
        return res;
    }
};
