//
// Created by Jyotirmai Singh on 7/7/17.
//

#ifndef HIGHSCALESYSTEMATICS_H
#define HIGHSCALESYSTEMATICS_H


#include "Systematic.h"

class HighScaleSystematics : public Systematic {
    public:
        HighScaleSystematics(double systematicParameter);
        double applyEnergyShift(double var, int dir);
    private:
        double _systematicParameter;
};


#endif //COMBINEDSYSTEMATIC_HIGHSCALESYSTEMATICS_H
