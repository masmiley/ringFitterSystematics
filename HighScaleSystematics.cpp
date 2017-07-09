//
// Created by Jyotirmai Singh on 7/7/17.
//

#include "HighScaleSystematics.h"

HighScaleSystematics::HighScaleSystematics(double systematicParameter)
{
    _systematicParameter = systematicParameter;
}

/** Application of shift specific to high energy systematics.
 *  @param var The energy to be shifted.
 *  @param dir The direction in which the energy is shifted. +1 for up, -1 for down. */
double HighScaleSystematics::applyEnergyShift(double var, int dir)
{
    return Systematic::applyEnergyShift(var, _systematicParameter, dir);
}
