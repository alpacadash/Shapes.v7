// Programmer: Younghyun Kwon
// Programmer's ID: 1651849
#ifndef PSHAPES_H
#define PSHAPES_H

#include <string>
#include <vector>
#include <cstdlib>
using namespace std;

struct Shape{
  virtual void output(ostream&) const = 0;
  virtual ~Shape(){}
};

class Square : public Shape
{
protected:
  const double side;

public:
  Square(const vector<string>& tokens): side(tokens.size() >= 2 ? atof(tokens[1].c_str()) : 0){}
  Square& operator=(const Square&);
  void output(ostream&) const;
};

namespace comsc
{
class Rectangle : public Shape
{
protected:
  const double length;
  const double width;

public:
  Rectangle(const vector<string>& tokens): length(tokens.size() >= 2 ? atof(tokens[1].c_str()) : 0), width(tokens.size() >= 3 ? atof(tokens[2].c_str()) : 0){}
  Rectangle& operator=(const Rectangle&);
  void output(ostream&) const;
};
}

class Circle : public Shape
{
protected:
  const double radius;

public:
  Circle(const vector<string>& tokens): radius(tokens.size() >= 2 ? atof(tokens[1].c_str()) : 0){}
  Circle& operator=(const Circle&);
  void output(ostream&) const;
};

class Triangle : public Shape
{
protected:
  const double side;

public:
  Triangle(const vector<string>& tokens): side(tokens.size() >= 2 ? atof(tokens[1].c_str()) : 0){}
  Triangle& operator=(const Triangle&);
  void output(ostream&) const;
};

class Cube : public Square
{
public:
  Cube(const vector<string>& tokens): Square(tokens){}
  Cube& operator=(const Cube&);
  void output(ostream&) const;
};

class Box : public comsc::Rectangle
{
protected:
  const double height;

public:
  Box(const vector<string>& tokens): comsc::Rectangle(tokens), height(tokens.size() >= 4 ? atof(tokens[3].c_str()) : 0){}
  Box& operator=(const Box&);
  void output(ostream&) const;
};

class Cylinder : public Circle
{
protected:
  const double height;

public:
  Cylinder(const vector<string>& tokens): Circle(tokens), height(tokens.size() >= 3 ? atof(tokens[2].c_str()) : 0){}
  Cylinder& operator=(const Cylinder&);
  void output(ostream&) const;
};

class Prism : public Triangle
{
protected:
  const double height;

public:
  Prism(const vector<string>& tokens): Triangle(tokens), height(tokens.size() >= 3 ? atof(tokens[2].c_str()) : 0){}
  Prism& operator=(const Prism&);
  void output(ostream&) const;
};

ostream& operator<<(ostream&, const Shape&);

#endif
