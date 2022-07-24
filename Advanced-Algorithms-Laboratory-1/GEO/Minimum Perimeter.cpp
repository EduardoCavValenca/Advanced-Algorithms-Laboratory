#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define pi acos(-1.0)
#define pb push_back
#define pii pair<long long int,long long int>
class Point
{
public:
    long long int x;
    long long int y;
    Point() {}
    Point(long long int _x, long long int _y)
    {
        x = _x;
        y = _y;
    }
    bool operator < (const Point&p)
    {
        return (x<p.x or (x==p.x and y<p.y));
    }
    bool operator > (const Point & p)
    {
        return ((x > p.x) or (x == p.x && y > p.y));
    }
};
bool cw(Point a,Point b,Point c)
{
    return (a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y))<0;
}
bool acw(Point a,Point b,Point c)
{
    return (a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y))>0;
}
vector<Point>convex_hull(vector<Point>v)
{
    if(v.size()==1)
        return v;
    sort(v.begin(),v.end());
    long long int n = v.size();
    Point left=v[0];
    Point right=v[n-1];
    vector<Point>up,down;
    up.pb(left);
    down.pb(left);
    for(long long int i=1; i<n; i++)
    {
        if(i==n-1 or acw(left,right,v[i]))
        {
            while(up.size()>=2 and !cw(up[up.size()-2],up[up.size()-1],v[i]))
                up.pop_back();
            up.push_back(v[i]);
        }
        if(i==n-1 or cw(left,right,v[i]))
        {
            while(down.size()>=2 and !acw(down[down.size()-2],down[down.size()-1],v[i]))
                down.pop_back();
            down.push_back(v[i]);
        }
    }
    vector<Point>c_hull;
    ///anticlockwise
    for(int i=0; i< (int) down.size(); i++)
    {
        c_hull.push_back(down[i]);
    }
    for(int i=up.size()-2; i>=1; i--)
    {
        c_hull.push_back(up[i]);
    }
    return c_hull;
}
double dist(Point a,Point b)
{
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}


int main() {

    for(long long int k=1; k<=1; k++)
    {
        long long int n;
        cin>>n;
        vector<Point>v;
        map<pii,long long int>m;
       // cout << endl << "pinto" << endl;
        for(long long int i=0; i<n; i++)
        {
            long long int x,y;
            cin>>x>>y;
            m[ {x,y}]++;
            if(m[ {x,y}]==1)
                v.push_back({x,y});
        }
        vector<Point>ans=convex_hull(v);
        long long int sz=ans.size();
        double perimeter=2*pi;
        if(sz==1)
        {
            cout<<perimeter<<endl;
            continue;
        }
        for(long long int i=0; i<sz; i++)
        {
            long long int beg=i;
            long long int last=(i+1)%sz;
            perimeter+=(dist(ans[beg],ans[last]));
        }
        cout<<fixed<<setprecision(6)<<(perimeter- 6.283185)<<endl;
    }


}