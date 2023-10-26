//
// Created by mu_tempa on 24.10.2023.
//

#include "Point.h"

Point operator+(const Point &lhs, const Point &rhs) {
    return Point{lhs.x + rhs.x,
                 lhs.y + rhs.y,
                 lhs.z + rhs.z};
}



Point operator*(const double &lhs, const Point &rhs) {
    return Point{ lhs * rhs.x,
                  lhs * rhs.y,
                  lhs * rhs.z};
}
