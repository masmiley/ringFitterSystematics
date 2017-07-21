//
// Created by Max Smiley on 7/19/17.
//

#ifndef HISTOGRAMOVERLAYER_H
#define HISTOGRAMOVERLAYER_H


#include <string>
#include <TFile>
#include <HistogramMerger.h>
#include <HistogramMaker.h>

class HistogramOverlayer {
    public:
        HistogramOverlayer(TFile* mcFile, TFile* dataFile, TFile* outFile);
        void makeHistograms();
        TFile* _outFile;

    private:
        TFile* _mcFile;
        TFile* _dataFile;
        std::string _pdfFilename;
        void printCanvas(TCanvas* canv, int index, int maxsize, bool first, bool oftwo);
};


#endif
