//
// Created by Jyotirmai Singh on 7/11/17.
//

#ifndef HIGHANDLOW_HISTOGRAMMERGER_H
#define HIGHANDLOW_HISTOGRAMMERGER_H


class HistogramMerger {
    HistogramMerger(TFile* nomFile, TFile* upFile, TFile* lowFile);
    void mergeHistograms();

    private:
        TFile* _nomFile;
        TFile* _upFile;
        TFile* _lowFile;
        void applyBinErrorCorrection(TH1F* nominal, TH1F* upper, TH1F* lower);
};


#endif //HIGHANDLOW_HISTOGRAMMERGER_H
