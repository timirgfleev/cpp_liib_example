#pragma once

struct Point {
    double x, y, z;
};

Point operator+(const Point &lhs, const Point &rhs);

Point operator*(const double &lhs, const Point &rhs);