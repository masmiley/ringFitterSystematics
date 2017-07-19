// Loop file
#include "RingFitterEventCombined.cc"
#include <string>
#include "HistogramMerger.h"
void loop(bool USEDATA, std::string fName) {
    std::string filename = fName;
    TFile* file = new TFile(fName.c_str(), "OPEN");
    TTree* tree = (TTree*) file->Get("Events");
    RingFitterEvent events(tree);
    std::cout << "Initiating Loops" << std::endl;

    std::cout << "Nominal Loop" << std::endl;
    events.Loop(1, 0, USEDATA);
    std::cout << "Upper Loop" << std::endl;
    events.Loop(1, 1, USEDATA);
    std::cout << "Lower Loop" << std::endl;
    events.Loop(1, -1, USEDATA);
    std::cout << "Looping Done, creating Histograms" << std::endl;
    
    std::string outname = USEDATA ? "SystematicsData.root" : "Systematics.root";
    TFile* nominalFile = new TFile("MC_CombinedSystematicNominal.root", "open");
    TFile* upperFile = new TFile("MC_CombinedSystematicUpper.root", "open");
    TFile* lowerFile = new TFile("MC_CombinedSystematicLower.root", "open");
    TFile* outFile = new TFile(outname.c_str(), "recreate");
 
    HistogramMerger* merge = new HistogramMerger(nominalFile, upperFile, lowerFile, outFile);
    merge->makeHistograms();

    nominalFile->Close();
    upperFile->Close();
    lowerFile->Close();
    outFile->Close();

} 
