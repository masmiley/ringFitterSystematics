//
// Created by Jyotirmai Singh on 7/7/17.
//

#ifndef COMBINEDSYSTEMATIC_LOWENERGYSYSTEMATICS_H
#define COMBINEDSYSTEMATIC_LOWENERGYSYSTEMATICS_H

#include "Systematic.h"

class LowScaleSystematics : public Systematic {
    public:
        LowScaleSystematics(double lowEnergyShift,
                            double lowEnergyDelta,
                            double sysUpXYZ,
                            double sysDownXYZ,
                            double sysUpScZ,
                            double sysDownScZ,
                            double sysUpOffX,
                            double sysDownOffX,
                            double sysUpOffY,
                            double sysDownOffY,
                            double sysUpOffZ,
                            double sysDownOffZ,
                            double sysEdepFidVolUp,
                            double sysEdepFidVolDown);

        double applyEnergyShift(double var, int dir);
        double applyPositionScale(double var, double param);
        // VARFLAG IS 1 FOR X 2 FOR Y 3 FOR Z
        double applyPositionSystematics(double var, int dir, int varFlag);
        double correctFollowerEnergy(double energy, double cr3);
        double applySmearing(double var, TF1* func);

    private:
        double applyUpSystematics(double var, int variableFlag);
        double applyLowSystematics(double var, int variableFlag);
        double _sysUpXYZ;
        double _sysDownXYZ;
        double _sysUpScZ;
        double _sysDownScZ;
        double _sysUpOffX;
        double _sysDownOffX;
        double _sysUpOffY;
        double _sysDownOffY;
        double _sysUpOffZ;
        double _sysDownOffZ;
        double _sysEdepFidVolUp;
        double _sysEdepFidVolDown;
        double _lowEnergyShift;
        double _lowEnergyDelta;
};


#endif //COMBINEDSYSTEMATIC_LOWENERGYSYSTEMATICS_H
