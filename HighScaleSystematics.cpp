/** @class High Scale Systematics
 *  Designed to implement the High Energy Systematics.
 *  Inherits from Systematic.
 *  @author Jyotirmai Singh */

#include "HighScaleSystematics.h"

HighScaleSystematics::HighScaleSystematics(double systematicParameter)
{
    _systematicParameter = systematicParameter;
}

/** Application of shift specific to high energy systematics.
 *  @param var The energy to be shifted.
 *  @param dir The direction in which the energy is shifted. +1 for up, -1 for down.
 *  @return The shifted energy. */
double HighScaleSystematics::applyEnergyShift(double var, int dir)
{
    return super::applyEnergyShift(var, _systematicParameter, dir);
}
