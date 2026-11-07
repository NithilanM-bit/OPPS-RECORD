#include <iostream>
using namespace std;

class Shape
{
public:
    virtual float area() = 0;
};

class Circle : public Shape
{
private:
    float radius;

public:
    Circle(float r) : radius(r) {}

    float area() override
    {
        return 3.14f * radius * radius;
    }
};

class Rectangle : public Shape
{
private:
    float length, breadth;

public:
    Rectangle(float l, float b) : length(l), breadth(b) {}

    float area() override
    {
        return length * breadth;
    }
};

class Triangle : public Shape
{
private:
    float base, height;

public:
    Triangle(float b, float h) : base(b), height(h) {}

    float area() override
    {
        return 0.5f * base * height;
    }
};

int main()
{
    Circle c(10.5);
    Rectangle r(9, 8);
    Triangle t(7, 6);

    Shape *ptr[] = {&c, &r, &t};

    cout << "Area of Circle: " << ptr[0]->area() << endl;
    cout << "Area of Rectangle: " << ptr[1]->area() << endl;
    cout << "Area of Triangle: " << ptr[2]->area() << endl;

    cout << "Shape objects are calculated using runtime polymorphism." << endl;

    return 0;
}