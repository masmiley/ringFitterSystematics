//
// Created by Jyotirmai Singh on 7/7/17.
//

#include <cmath>
#include <stdexcept>
#include "LowScaleSystematics.h"

LowScaleSystematics::LowScaleSystematics(double lowEnergyShift, double lowEnergyDelta, double sysUpXYZ,
                                         double sysDownXYZ, double sysUpScZ, double sysDownScZ, double sysUpOffX,
                                         double sysDownOffX, double sysUpOffY, double sysDownOffY, double sysUpOffZ,
                                         double sysDownOffZ, double sysEdepFidVolUp, double sysEdepFidVolDown) {
    _lowEnergyShift = lowEnergyShift;
    _lowEnergyDelta = lowEnergyDelta;
    _sysDownOffX = sysDownOffX;
    _sysUpOffX = sysUpOffX;
    _sysDownOffY = sysDownOffY;
    _sysUpOffY = sysUpOffY;
    _sysDownOffZ = sysDownOffZ;
    _sysUpOffZ = sysUpOffZ;
    _sysUpXYZ = sysUpXYZ;
    _sysDownXYZ = sysDownXYZ;
    _sysDownScZ = sysDownScZ;
    _sysUpScZ = sysUpScZ;
    _sysEdepFidVolDown = sysEdepFidVolDown;
    _sysEdepFidVolUp = sysEdepFidVolUp;

}

/** Application of shift specific to low energy systematics.
 *  @param var The energy to be shifted.
 *  @param dir The direction in which the energy is shifted. +1 for up, -1 for down. */
double LowScaleSystematics::applyEnergyShift(double var, int dir)
{
    return Systematic::applyEnergyShift(var, _lowEnergyShift/100, dir);
}

/** Smear var with the function func.
 *  @param var The variable being smeared.
 *  @param func The function used for the smearing. */
double LowScaleSystematics::applySmearing(double var, TF1 *func)
{
    return Systematic::applySmearing(var, func);
}

/** The application of the MC Energy Correction for the D2O phase
 *  (Section 2.4.1 of Unidoc)
 *  @param energy The MC energy to be corrected.
 *  @param the C(R^3) parameter as defined in Section 2.4.1. */
double LowScaleSystematics::correctFollowerEnergy(double energy, double cr3)
{
    return -0.10872 + 1.0277 * (energy/cr3) - 0.0012247 * pow(energy/cr3, 2);
}

/** Applies the position systematic scaling.
 * @param var The variable being scaled
 * @param param The systematic parameter corresponding to the scaling */
double LowScaleSystematics::applyPositionScale(double var, double param)
{
    return var * (1 + param/100);
}

/** Apply systematics to var.
 *  @param var The variable to which systematics are applied.
 *  @param dir The direction of systematics. 1 for upper, -1 for lower.
 *  @param varFlag The flag indicating which variable var's value corresponds to:
 *                 x = 1, y = 2, z = 3. Used to determine systematic parameters for
 *                 systematic application. */
double LowScaleSystematics::applyPositionSystematics(double var, int dir, int varFlag)
{
    switch (dir) {
        case 1:
            return applyUpSystematics(var, varFlag);
        case -1:
            return applyLowSystematics(var, varFlag);
        default:
            throw new std::invalid_argument("Incorrect value for position systematic direction, must be 1 or -1");
    }
}

/** Apply Upper Systematics to var. Utility function for applyPositionSystematics.
 *  @param var The variable to which systematics are applied.
 *  @param varFlag The flag indicating which variable var's value corresponds to. Same
 *                 use as in applyPositionSystematics. */
double LowScaleSystematics::applyUpSystematics(double var, int varFlag) {
    double varUp = var;
    varUp = applyPositionScale(varUp, _sysUpXYZ);
    varUp = applyPositionScale(varUp, _sysUpScZ);
    TF1* resFunc;
    switch (varFlag) {
        case 1:
            varUp = applyPositionShift(varUp, _sysUpOffX, 1);
            resFunc = new TF1("X", "TMath::Gaus(x, 0, 3.3)", -10, 10);
            break;
        case 2:
            varUp = applyPositionShift(varUp, _sysUpOffY, 1);
            resFunc = new TF1("X", "TMath::Gaus(x, 0, 2.2)", -10, 10);
            break;
        case 3:
            varUp = applyPositionShift(varUp, _sysUpOffZ, 1);
            resFunc = new TF1("X", "TMath::Gaus(x, 0, 1.5)", -10, 10);
            break;
        default:
            throw new std::invalid_argument("Incorrect value for varFlag");

    }
    varUp = applySmearing(varUp, resFunc);
    return varUp;
}

/** Apply Lower Systematics to var. Utility function for applyPositionSystematics.
 *  @param var The variable to which systematics are applied.
 *  @param varFlag The flag indicating which variable var's value corresponds to. Same
 *                 use as in applyPositionSystematics. */
double LowScaleSystematics::applyLowSystematics(double var, int varFlag) {
    double varLow = var;
    varLow = applyPositionScale(varLow, _sysDownXYZ);
    varLow = applyPositionScale(varLow, _sysDownScZ);
    TF1* resFunc;
    switch (varFlag) {
        case 1:
            varLow = applyPositionShift(varLow, _sysDownOffX, -1);
            resFunc = new TF1("X", "TMath::Gaus(x, 0, 3.3)", -10, 10);
            break;
        case 2:
            varLow = applyPositionShift(varLow, _sysDownOffY, -1);
            resFunc = new TF1("X", "TMath::Gaus(x, 0, 2.2)", -10, 10);
            break;
        case 3:
            varLow = applyPositionShift(varLow, _sysDownOffZ, -1);
            resFunc = new TF1("X", "TMath::Gaus(x, 0, 1.5)", -10, 10);
            break;
        default:
            throw new std::invalid_argument("Incorrect value for varFlag");

    }
    varLow = applySmearing(varLow, resFunc);
    return varLow;
}
