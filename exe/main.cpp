#include "../lib/curves.h"
#include <vector>
#include <memory>
#include <list>
#include <algorithm>
#include <omp.h>
#include <iostream>

int GetRandInt(int max = 100){
    return rand() % 100;
}

int main() {
    std::vector<std::shared_ptr<Curve>> v(10);

    for (int i = 0; i < v.size(); ++i) {
        int diceroll = rand() % 3;

        switch (diceroll) {
            case 0:
                v[i].reset(new Circle(GetRandInt()));
                break;
            case 1:
                v[i].reset(new Ellipse(GetRandInt(), GetRandInt()));
                break;
            case 2:
                v[i].reset(new Helix(GetRandInt(), GetRandInt()));
                break;
        }
    }

    for(const auto& item : v){
        Point temp = item.get()->GetPoint(M_PI/4);

        std::cout << 'p' << temp.x << ' ' << temp.y << ' ' << temp.z << ' ' << std::endl;

        temp = item.get()->GetFirstDerivative(M_PI/4);
        std::cout << 'd' << temp.x << ' ' << temp.y << ' ' << temp.z << ' ' << std::endl;
    }

    std::list<Circle *> circles;
    for (auto &curve: v) {
        if (auto circle = std::dynamic_pointer_cast<Circle>(curve)) {
            circles.push_back(circle.get());
        }
    }


    circles.sort([](const Circle *a, const Circle *b) {
        return a->GetRadius() < b->GetRadius();
    });

    double sum_of_radii = 0.0;

    #pragma omp parallel for reduction(+:sum_of_radii)
    for (auto it = circles.begin(); it != circles.end(); ++it) {
        sum_of_radii += (*it)->GetRadius();
    }

    //std::cout << sum_of_radii;


    return 0;
}