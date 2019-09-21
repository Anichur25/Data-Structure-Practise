#include<bits/stdc++.h>
#define pi 3.1416
using namespace std;

void Cylinder_area()
{
    double r,h,area;
    cout << "Enter radius & height value : ";
    cin >> r >> h;
    area = 2 * pi * r * (r + h);
    cout << "Area of the cylinder is : " << area  <<" sq.units"<< endl;
}

void Ellipsoid_area()
{
    double a,b,c,area;
    cout << "Enter a,b,c : ";
    cin >> a >> b >> c;
    area = 4 * pi * pow((pow((a * b),1.6) + pow((b * c),1.6) + pow((c * a),1.6)) / 3.00,1.0/1.6);
    cout << "Area of the ellipsoid is : " << area <<" sq.units"<< endl;
}

void Circle_area()
{
    double r,area;
    cout <<"Enter radius : ";
    cin >> r;
    area = pi * r * r;
    cout <<"Area of the circle is : " << area <<" sq.units"<<endl;
}

int main()
{
    Cylinder_area();
    Ellipsoid_area();
    Circle_area();
    return 0;
}
