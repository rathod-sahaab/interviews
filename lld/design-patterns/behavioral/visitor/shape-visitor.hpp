#ifndef SHAPE_VISITOR_HPP
#define SHAPE_VISITOR_HPP

class Circle;
class Rect;

class ShapeVisitor {
public:
  virtual void visit(Circle &c) = 0;
  virtual void visit(Rect &r) = 0;
};

#endif // !SHAPE_VISITOR_HPP
