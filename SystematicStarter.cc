//A macro to load in and run the systematics package
void SystematicStarter(){
  gROOT->ProcessLine(".L Systematic.cpp");
  gROOT->ProcessLine(".L HighScaleSystematics.cpp");
  gROOT->ProcessLine(".L LowScaleSystematics.cpp");
  gROOT->ProcessLine(".L HistogramMaker.cpp");
  gROOT->ProcessLine(".L HistogramMerger.cpp");
  gROOT->ProcessLine(".x loop.cc"); 
}
