//
// Created by Jyotirmai Singh on 7/7/17.
//

#ifndef COMBINEDSYSTEMATIC_SYSTEMATIC_H
#define COMBINEDSYSTEMATIC_SYSTEMATIC_H


class Systematic {
    protected:
        virtual ~Systematic() {}
        double applyEnergyShift(double var, double param, int dir);
        double applyPositionShift(double var, double param, int dir);
        double applySmearing(double var, TF1* func);
};


#endif //COMBINEDSYSTEMATIC_SYSTEMATIC_H

