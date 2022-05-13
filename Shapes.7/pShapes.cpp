// Programmer: Younghyun Kwon
// Programmer's ID: 1651849
#include "pch.h"

#include "iostream"
#include "fstream"
#include <string>
#include <vector>
using namespace std;

#include <cmath>

#include "pShapes.h"

const double PI = 3.14159;

ostream& roundingTwo(ostream& out)
  {
    out.setf(ios::fixed);
    out.precision(2);
    return out;
  }

ostream& roundingOff(ostream& out)
  {
    out.unsetf(ios::fixed);
    out.precision(6);
    return out;
  }

Square& Square::operator=(const Square& square)
{
  Square& host = *this;
  if(this != &square)
  {
    const_cast<double&>(host.side)= square.side;
  }
  return *this;
}


void Square::output(ostream& out) const
{
  double side = this->side;
  double area = side*side;
  double perimeter = side*4;
  out << "SQUARE side=" << side;
  roundingTwo(out);
  out << " area=" << area << " perimeter=" << perimeter << endl;
  roundingOff(out);
}

comsc::Rectangle& comsc::Rectangle::operator=(const Rectangle& rectangle)
{
  Rectangle& host = *this;
  if(this != &rectangle)
  {
    const_cast<double&>(host.length)= rectangle.length;
    const_cast<double&>(host.width)= rectangle.width;
  }
  return *this;
}

void comsc::Rectangle::output(ostream& out) const
{
  double length = this->length;
  double width = this->width;
  double area = length*width;
  double perimeter = length*2 + width*2;
  out << "RECTANGLE length=" << length << " width=" << width;
  roundingTwo(out);
  out << " area=" << area << " perimeter=" << perimeter << endl;
  roundingOff(out);
}

Circle& Circle::operator=(const Circle& circle)
{
  Circle& host = *this;
  if(this != &circle)
  {
    const_cast<double&>(host.radius)= circle.radius;
  }
  return *this;
}

void Circle::output(ostream& out) const
{
  double radius = this->radius;
  double area = PI*radius*radius;
  double perimeter = 2*PI*radius;
  out << "CIRCLE radius=" << radius;
  roundingTwo(out);
  out << " area=" << area << " perimeter=" << perimeter << endl;
  roundingOff(out);
}

Triangle& Triangle::operator=(const Triangle& triangle)
{
  Triangle& host = *this;
  if(this != &triangle)
  {
    const_cast<double&>(host.side)= triangle.side;
  }
  return *this;
}

void Triangle::output(ostream& out) const
{
  double side = this->side;
  double area = (sqrt(3)*side*side)/4;
  double perimeter = 3*side;
  out << "TRIANGLE side=" << side;
  roundingTwo(out);
  out << " area=" << area << " perimeter=" << perimeter << endl;
  roundingOff(out);
}

Cube& Cube::operator=(const Cube& cube)
{
  Cube& host = *this;
  if(this != &cube)
  {
    const_cast<double&>(host.side)= cube.side;
  }
  return *this;
}

void Cube::output(ostream& out) const
{
  double side = this->side;
  double area = side*side*6;
  double volume = side*side*side;
  out << "CUBE side=" << side;
  roundingTwo(out);
  out << " area=" << area << " volume=" << volume << endl;
  roundingOff(out);
}

Box& Box::operator=(const Box& box)
{
  Box& host = *this;
  if(this != &box)
  {
    const_cast<double&>(host.length)= box.length;
    const_cast<double&>(host.width)= box.width;
    const_cast<double&>(host.height)= box.height;
  }
  return *this;
}

void Box::output(ostream& out) const
{
  double length = this->length;
  double width = this->width;
  double height = this->height;
  double area = length*width*2 + width*height*2 + length*height*2;
  double volume = length*width*height;
  out << "BOX side=" << length << " width=" << width << " height=" << height;
  roundingTwo(out);
  out << " area=" << area << " volume=" << volume << endl;
  roundingOff(out);
}

Cylinder& Cylinder::operator=(const Cylinder& cylinder)
{
  Cylinder& host = *this;
  if(this != &cylinder)
  {
    const_cast<double&>(host.radius)= cylinder.radius;
    const_cast<double&>(host.height)= cylinder.height;
  }
  return *this;
}

void Cylinder::output(ostream& out) const
{
  double radius = this->radius;
  double height = this->height;
  double area = PI*radius*radius*2 + height*2*PI*radius;
  double volume = PI*radius*radius*height;
  out << "CYLINDER radius=" << radius << " height=" << height;
  roundingTwo(out);
  out << " area=" << area << " volume=" << volume << endl;
  roundingOff(out);
}

Prism& Prism::operator=(const Prism& prism)
{
  Prism& host = *this;
  if(this != &prism)
  {
    const_cast<double&>(host.side)= prism.side;
    const_cast<double&>(host.height)= prism.height;
  }
  return *this;
}

void Prism::output(ostream& out) const
{
  double side = this->side;
  double height = this->height;
  double area = (sqrt(3)*side*side*2)/4 + 3*side*height;
  double volume = (sqrt(3)*side*side*height)/4;
  out << "PRISM side=" << side << " height=" << height;
  roundingTwo(out);
  out << " area=" << area << " volume=" << volume << endl;
  roundingOff(out);
}

ostream& operator<<(ostream& out, const Shape& s){
  s.output(out);
  return out;
}
