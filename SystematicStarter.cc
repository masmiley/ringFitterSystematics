//A macro to load in and run the systematics package
//#include <TH1.h>
//#include <vector>
#include <vector>
#include <TH1.h>
#ifdef __MAKECINT__
#pragma link C++ class std::vector<TH1*>;
#endif

void SystematicStarter(){
  gROOT->ProcessLine(".L Systematic.cpp");
  gROOT->ProcessLine(".L HighScaleSystematics.cpp");
  gROOT->ProcessLine(".L LowScaleSystematics.cpp");
  gROOT->ProcessLine(".L HistogramMaker.cpp");
  gROOT->ProcessLine(".L HistogramMerger.cpp");
  gROOT->ProcessLine(".x loop.cc"); 
}
