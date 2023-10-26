#pragma once

#include "Point.h"

#include <cmath>
class Curve {
public:
    virtual Point GetPoint(double t) = 0;

    virtual Point GetFirstDerivative(double t) = 0;
};

class Circle : public Curve {
public:
    explicit Circle(double r);

    double GetRadius() const;

    virtual Point GetPoint(double t) override final;

    virtual Point GetFirstDerivative(double t) override final;

protected:
    double r;
};

class Ellipse : public Curve {
public:
    Ellipse(double r1, double r2);

    virtual Point GetPoint(double t) override final;

    virtual Point GetFirstDerivative(double t) override final;

    double getR1() const;

    double getR2() const;

protected:

    double r1, r2;
};

class Helix : public Curve {
public:
    Helix(double r, double steep);

private:
    virtual Point GetPoint(double t) override final;

    virtual Point GetFirstDerivative(double t) override final;

protected:
    double r, steep;
};