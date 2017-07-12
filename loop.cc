#include "RingFitterEventCombined.cc"
#include <string>
#include "HistogramMerger.h"
void loop() {
    std::string filename = "merged_mc_d2o_smallsample.root";
    TFile* file = new TFile(filename.c_str(), "OPEN");
    TTree* tree = (TTree*) file->Get("Events");
    RingFitterEvent events(tree);
    std::cout << "Initiating Loops" << std::endl;

    std::cout << "Nominal Loop" << std::endl;
    events.Loop(1, 0);
    std::cout << "Upper Loop" << std::endl;
    events.Loop(1, 1);
    std::cout << "Lower Loop" << std::endl;
    events.Loop(1, -1);
    std::cout << "Looping Done, creating Histograms" << std::endl;

    TFile* nominalFile = new TFile("MC_CombinedSystematicNominal.root", "open");
    TFile* upperFile = new TFile("MC_CombinedSystematicUpper.root", "open");
    TFile* lowerFile = new TFile("MC_CombinedSystematicLower.root", "open");
    TFile* outFile = new TFile("Systematics.root", "recreate");

    HistogramMerger* merge = new HistogramMerger(nominalFile, upperFile, lowerFile, outFile);
    merge->makeHistograms();

} 
