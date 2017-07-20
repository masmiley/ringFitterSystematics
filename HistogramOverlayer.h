//
// Created by Max Smiley on 7/19/17.
//

#ifndef HISTOGRAMOVERLAYER_H
#define HISTOGRAMOVERLAYER_H


#include <string>

class HistogramOverlayer {
    public:
        HistogramOverlayer(TFile* mcFile, TFile* dataFile, TFile* outFile);
        void makeHistograms();
        TFile* _outFile;

    private:
        TFile* _mcFile;
        TFile* _dataFile;
};


#endif
