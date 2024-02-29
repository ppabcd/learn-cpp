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
    Kind k;
    Point center;
    Color col;

public:
    void draw();
    void rotate(int);
};

void Shape::draw()
{
    switch (k)
    {
    case circle:
        /* code */
        break;
    case triangle:
        /* code */
        break;
    default:
        break;
    }
}

/**
 * This is the basic things that might recreate every new shapes.
 */
