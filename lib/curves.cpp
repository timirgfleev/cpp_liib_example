//
// Created by mu_tempa on 24.10.2023.
//

#include "curves.h"

Point Circle::GetPoint(double t) {
    return r * Point{cos(t), sin(t), 0};
}

Point Circle::GetFirstDerivative(double t) {
    return r * Point{-sin(t), cos(t), 0};
}

Circle::Circle(double r) : r(r) {}

double Circle::GetRadius() const {
    return r;
}

Point Ellipse::GetPoint(double t) {
    return Point{cos(t) * r1, sin(t) * r2, 0};
}

Point Ellipse::GetFirstDerivative(double t) {
    return Point{-sin(t) * r1, cos(t) * r2, 0};
}

double Ellipse::getR1() const {
    return r1;
}

double Ellipse::getR2() const {
    return r2;
}

Ellipse::Ellipse(double r1, double r2) : r1(r1), r2(r2) {}

Point Helix::GetPoint(double t) {
    return Point{cos(t) * r, sin(t) * r, steep * (t / (2 * M_PI))};
}

Point Helix::GetFirstDerivative(double t) {
    return Point{-sin(t) * r, cos(t) * r, 0};
}

Helix::Helix(double r, double steep) : r(r), steep(steep) {}
