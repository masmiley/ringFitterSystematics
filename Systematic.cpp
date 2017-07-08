//
// Created by Jyotirmai Singh on 7/7/17.
//

#include <stdexcept>
#include "Systematic.h"

double Systematic::applyEnergyShift(double var, double param, int dir) {
    switch (dir) {
        case 1:
            return var * (1 + param);
        case -1:
            return var * (1 - param);
        default:
            throw new std::invalid_argument("Incorrect value for Direction, must be 1 or -1");
    }
}
double Systematic::applyPositionShift(double var, double param, int dir) {
    switch (dir) {
        case 1:
            return var + param;
        case -1:
            return var - param;
        default:
            throw new std::invalid_argument("Incorrect value for Direction, must be 1 or -1");
    }
}

double Systematic::applySmearing(double var, TF1* func) {
    return var + func->GetRandom();
}
