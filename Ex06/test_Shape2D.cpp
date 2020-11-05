// COMPLETE include the necessary headers here
#ifndef LIB_H
#define LIB_H

#include <iostream>
#include <string>
#include <cmath>
#include <cassert>

#endif

#include "lib.h"
#include "Shape2D.h"
#include "Circle.h"
#include "Rectangle.h"
#include "Polygon.h"

using namespace std;

const float PI = 3.141593f;

inline void assertFloat(float x, float y, float eps=1e-5) {
    assert(fabs(x-y) < eps);
}

int main(void) {
  const int NUM_SHAPES = 3;
  Shape2D* shapes[NUM_SHAPES];
  Point2D center(0.0f, 0.0f);
  shapes[0] = new Circle(center, 1.0f);

  Point2D left_corner(-1.0f, -1.0f);
  shapes[1] = new Rectangle(left_corner, 4.0f, 2.0f);

  // New code for testing the class Polygon:
  const int NUM_VERTICES = 4;
  Point2D* vertices[] = {
    new Point2D(2.0f,-1.0f),
    new Point2D(2.0f,1.0f),
    new Point2D(-2.0f,1.0f),
    new Point2D(-2.0f,-1.0f)
  };

  shapes[2] = new Polygon(vertices, NUM_VERTICES);
  for(int i = 0; i < NUM_VERTICES; i++) delete vertices[i];
  // End

  for (int i = 0; i < NUM_SHAPES; ++i) {
    float tx = 1.0f;
    float ty = -1.0f;
    shapes[i]->translate(tx, ty);
  }
  
  assertFloat(shapes[0]->compute_area(), PI);
  assertFloat(shapes[1]->compute_area(), 8.0f);
  assertFloat(shapes[2]->compute_area(), 8.0f);

  // COMPLETE free memory for shapes
  for(int i = 0; i < NUM_SHAPES; i++) {
    delete shapes[i];
  }

  return 0;
}