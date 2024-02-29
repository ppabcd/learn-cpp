enum Kind
{
    circle,
    triangle,
    square
};
class Point
{
};
class Color
{
};
class Shape
{
    Point center;
    Color col;

public:
    Point where() { return center; };
    void move(Point to)
    {
        center = to; /**/
        draw();
    }
    virtual void draw() = 0;
    virtual void rotate(int angle) = 0;
};

#include <vector> // Include this to define 'vector'
#include <iostream>
using namespace std;

class Circle : public Shape
{
public:
    void rotate(int angle) override
    {
        cout << "Rotating Circle by " << angle << " degrees." << endl;
    }
    void draw() override
    {
        cout << "Drawing Circle." << endl;
    }
};

void rotate_all(vector<Shape *> &v, int angle)
{
    for (int i = 0; i < v.size(); ++i)
        v[i]->rotate(angle);
}

int main()
{
    Circle circle1, circle2; // Create instances of Circle

    std::vector<Shape *> shapes;
    shapes.push_back(&circle1); // Add pointers to the instances to the vector
    shapes.push_back(&circle2);

    rotate_all(shapes, 45); // Rotate all shapes by 45 degrees

    // Additionally, demonstrating the draw function
    for (auto *shape : shapes)
    {
        shape->draw(); // This will call Circle's implementation of draw
    }

    return 0;
}
