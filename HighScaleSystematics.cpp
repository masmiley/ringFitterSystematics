//
// Created by Jyotirmai Singh on 7/7/17.
//

#include "HighScaleSystematics.h"

HighScaleSystematics::HighScaleSystematics(double systematicParameter) {
    _systematicParameter = systematicParameter;
}

double HighScaleSystematics::applyEnergyShift(double var, int dir) {
    return Systematic::applyEnergyShift(var, _systematicParameter, dir);
}
