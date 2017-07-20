//
// Created by Jyotirmai Singh on 7/11/17.
//

#ifndef HISTOGRAMMERGER_H
#define HISTOGRAMMERGER_H


#include <string>

class HistogramMerger {
    public:
        HistogramMerger(TFile* nomFile, TFile* upFile, TFile* lowFile, TFile* outFile, bool useData);
        void makeHistograms();
        TFile* _outFile;

    private:
        TFile* _nomFile;
        TFile* _upFile;
        TFile* _lowFile;
        bool _data;
        void applyBinErrorCorrection(TH1F* nominal, TH1F* upper, TH1F* lower);
        void mergeHistograms(TH1F* nominal, TH1F* upper, TH1F* lower, TCanvas* canv);
        void mergeNormDivisionHistograms(TH1F* nominal, TH1F* upper, TH1F* lower
                                         TH1F* nominalNorm, TH1F* upperNorm, TH1F* lowerNorm,
                                         TCanvas* canv);
        void plotPromptHistogram(TH1F* nominal, TH1F* upper, TH1F* lower, TCanvas* canv);
        void plotMeanFollowerHistogram(TH1F* nominal, TH1F* upper, TH1F* lower
                                         TH1F* nominalNorm, TH1F* upperNorm, TH1F* lowerNorm,
                                         TCanvas* canv);
};


#endif //HIGHANDLOW_HISTOGRAMMERGER_H
