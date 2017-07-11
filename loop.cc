#include "RingFitterEventCombined.cc"
#include <string>
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
    events.loop(1, -1);
    std::cout << "Looping Done, creating Histograms" << std::endl;
} 
