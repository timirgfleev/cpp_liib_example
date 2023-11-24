#pragma once

#include "Point.h"

#include <cmath>
class Curve {
public:
    virtual ~Curve();

    virtual Point GetPoint(double t) const = 0;

    virtual Point GetFirstDerivative(double t) const = 0;
};

class Circle : public Curve {
public:
    explicit Circle(double r);

    double GetRadius() const;

    virtual Point GetPoint(double t) const override final;

    virtual Point GetFirstDerivative(double t) const override final;

    ~Circle() override;

protected:
    double r;
};

class Ellipse : public Curve {
public:
    Ellipse(double r1, double r2);

    Point GetPoint(double t) const final;

    Point GetFirstDerivative(double t) const final;

    double getR1() const;

    double getR2() const;

    ~Ellipse() override;

protected:

    double r1, r2;
};

class Helix : public Curve {
public:
    Helix(double r, double steep);

    Point GetPoint(double t) const final;

    Point GetFirstDerivative(double t) const final;

    double getR() const;

    double getSteep() const;

    ~Helix() override;

protected:
    double r, steep;
};