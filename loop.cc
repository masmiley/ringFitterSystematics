#include "RingFitterEventCombined.cc"
#include <string>
void loop() {
  std::string filename = "merged_mc_d2o_smallsample.root";
  TFile* file = new TFile(filename.c_str(), "OPEN");
  TTree* tree = (TTree*) file->Get("Events");
  RingFitterEvent events(tree);
  std::cout << "Initiating Loop" << std::endl; 
  events.Loop(1);
} 
