/** @class Low Scale Systematics
 *  Designed to implement the Low Energy Systematics.
 *  Inherits from Systematic.
 *  @author Jyotirmai Singh */

#include <cmath>
#include <stdexcept>
#include "LowScaleSystematics.h"

/** Constructor. All arguments are systematic parameters.
 *  The first two are Energy parameters. The remainder are
 *  Position parameters (defined in Unidoc 2.11.5).
 *  @param lowEnergyShift The Low Energy Shift
 *  @param lowEnergyDelta The Low Energy Delta Parameter.
 *  @param sysUpXYZ The upper parameter for XYZ Scaling.
 *  @param sysDownXYZ The lower parameter for XYZ Scaling.
 *  @param sysUpScZ The upper parameter for Z scaling.
 *  @param sysDownScZ The lower parameter for Z scaling.
 *  @param sysUpOffX The upper parameter for the X offset.
 *  @param sysDownOffX The lower parameter for the X offset.
 *  @param sysUpOffY The upper parameter for the Y offset.
 *  @param sysDownOffY The lower parameter for the Y offset.
 *  @param sysUpOffZ The upper parameter for the Z offset.
 *  @param sysDownOffZ The lower parameter for the Z offset.
 *  @param sysEdepFidVolUp The upper parameter for the Edep. Fid. Vol.
 *  @param sysEdepFidVolDown The lower parameter for the Edep. Fid. Vol. */
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
    _sysUpXYZFlag = true;
    _sysDownXYZFlag = true;
}

/** Application of shift specific to low energy systematics.
 *  @param var The energy to be shifted.
 *  @param dir The direction in which the energy is shifted. +1 for up, -1 for down.
 *  @return The shifted energy. */
double LowScaleSystematics::applyEnergyShift(double var, int dir)
{
    return super::applyEnergyShift(var, _lowEnergyShift/100, dir);
}

/** Smear var with the function func.
 *  @param var The variable being smeared.
 *  @param func The function used for the smearing.
 *  @return The smeared value of var. */
double LowScaleSystematics::applySmearing(double var, TF1* func)
{
    return super::applySmearing(var, func);
}

/** The application of the MC Energy Correction for the D2O phase
 *  (Section 2.4.1 of Unidoc)
 *  @param energy The MC energy to be corrected.
 *  @param cr3 The C(R^3) parameter as defined in Section 2.4.1.
 *  @return The corrected MC energy. */
double LowScaleSystematics::correctFollowerEnergy(double energy, double cr3)
{
    return -0.10872 + 1.0277 * (energy/cr3) - 0.0012247 * pow(energy/cr3, 2);
}

/** Calculation of the upper weighting for the Edep. Fid. Vol. systematic.
 *  @param energy The corrected nominal energy.
 *  @return The new weight the event should be given in the histogram. */
double LowScaleSystematics::getwPlus(double energy)
{
    return (1. + (_sysEdepFidVolUp/100.) * (energy - 5.05));
}

/** Calculutation of the lower weighting for the Edep. Fid. Vol. systematic.
 *  @param energy The corrected nominal energy.
 *  @return The new weight the event should be given in the histogram. */
double LowScaleSystematics::getwMinus(double energy)
{
    return (1. + (_sysEdepFidVolDown/100.) * (energy - 5.05));
}



/** Applies the position systematic scaling (for scale XYZ/Z in sec. 2.11.5)
 * @param var The variable being scaled
 * @param param The systematic parameter corresponding to the scaling
 * @return The scaled postition. */
double LowScaleSystematics::applyPositionScale(double var, double param)
{
    return var * (1 + param/100);
}

/** Apply systematics to var.
 *  @param var The variable to which systematics are applied.
 *  @param dir The direction of systematics. 1 for upper, -1 for lower.
 *  @param varFlag The flag indicating which variable var's value corresponds to:
 *                 x = 1, y = 2, z = 3. Used to determine systematic parameters for
 *                 systematic application.
 *  @return The result of applying all active systematics to var. */
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
 *                 use as in applyPositionSystematics.
 *  @return The result of applying all active systematics with upper parameters to var. */
double LowScaleSystematics::applyUpSystematics(double var, int varFlag) {
    double varUp = var;
    if (_sysUpXYZFlag) {
        varUp = applyPositionScale(varUp, _sysUpXYZ);
    }

    if (_sysUpScZFlag) {
        varUp = applyPositionScale(varUp, _sysUpScZ);
    }

    TF1* resFunc;

    switch (varFlag) {
        case 1:
            if (_sysUpOffXFlag) {
                varUp = applyPositionShift(varUp, _sysUpOffX, -1);
            }
            if (_sysResXFlag) {
                resFunc = new TF1("X", "TMath::Gaus(x, 0, 3.3)", -10, 10);
                varUp = applySmearing(varUp, resFunc);
            }
            break;
        case 2:
            if (_sysUpOffYFlag) {
                varUp = applyPositionShift(varUp, _sysDownOffY, -1);
            }
            if (_sysResYFlag) {
                resFunc = new TF1("X", "TMath::Gaus(x, 0, 2.2)", -10, 10);
                varUp = applySmearing(varUp, resFunc);
            }
            break;
        case 3:
            if (_sysUpOffZFlag) {
                varUp = applyPositionShift(varUp, _sysDownOffZ, -1);
            }
            if (_sysResZFlag) {
                resFunc = new TF1("X", "TMath::Gaus(x, 0, 1.5)", -10, 10);
                varUp = applySmearing(varUp, resFunc);
            }
            break;
        default:
            throw new std::invalid_argument("Incorrect value for varFlag");

    }
    return varUp;
}

/** Apply Lower Systematics to var. Utility function for applyPositionSystematics.
 *  @param var The variable to which systematics are applied.
 *  @param varFlag The flag indicating which variable var's value corresponds to. Same
 *                 use as in applyPositionSystematics.
 *  @return The result of applying all active systematics with lower parameters to var. */
double LowScaleSystematics::applyLowSystematics(double var, int varFlag) {
    double varLow = var;
    if (_sysDownXYZFlag) {
        varLow = applyPositionScale(varLow, _sysDownXYZ);
    }

    if (_sysDownScZFlag) {
        varLow = applyPositionScale(varLow, _sysDownScZ);
    }

    TF1* resFunc;

    switch (varFlag) {
        case 1:
            if (_sysDownOffXFlag) {
                varLow = applyPositionShift(varLow, _sysDownOffX, -1);
            }
            if (_sysResXFlag) {
                resFunc = new TF1("X", "TMath::Gaus(x, 0, 3.3)", -10, 10);
                varLow = applySmearing(varLow, resFunc);
            }
            break;
        case 2:
            if (_sysDownOffYFlag) {
                varLow = applyPositionShift(varLow, _sysDownOffY, -1);
            }
            if (_sysResYFlag) {
                resFunc = new TF1("X", "TMath::Gaus(x, 0, 2.2)", -10, 10);
                varLow = applySmearing(varLow, resFunc);
            }
            break;
        case 3:
            if (_sysDownOffZFlag) {
                varLow = applyPositionShift(varLow, _sysDownOffZ, -1);
            }
            if (_sysResZFlag) {
                resFunc = new TF1("X", "TMath::Gaus(x, 0, 1.5)", -10, 10);
                varLow = applySmearing(varLow, resFunc);
            }
            break;
        default:
            throw new std::invalid_argument("Incorrect value for varFlag");

    }
    return varLow;
}
