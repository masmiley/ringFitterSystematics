//
// Created by Jyotirmai Singh on 7/7/17.
//

#include <stdexcept>
#include "Systematic.h"

/** Application of shift specific to general energy systematics.
 *  @param var The energy to be shifted.
 *  @param param The energy systematic parameter.
 *  @param dir The direction in which the energy is shifted. +1 for up, -1 for down. */
double Systematic::applyEnergyShift(double var, double param, int dir) {
    switch (dir) {
        case 1:
            return var * (1 + param);
        case -1:
            return var * (1 - param);
        default:
            throw new std::invalid_argument("Incorrect value for dir, must be 1 or -1");
    }
}

/** Application of shift specific to general position systematics.
 *  @param var The position to be shifted.
 *  @param param The position systematic parameter.
 *  @param dir The direction in which the energy is shifted. +1 for up, -1 for down. */
double Systematic::applyPositionShift(double var, double param, int dir) {
    switch (dir) {
        case 1:
            return var + param;
        case -1:
            return var - param;
        default:
            throw new std::invalid_argument("Incorrect value for dir, must be 1 or -1");
    }
}

/** Application of general smearing systematic.
 *  @param var The value to be smeared.
 *  @param func The function to use for smearing. */
double Systematic::applySmearing(double var, TF1* func) {
    return var + func->GetRandom();
}
