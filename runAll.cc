#include <string> 
#include <iostream>
void runAll(std::string dataName, std::string mcName) {
 gROOT->ProcessLine(".L Systematic.cpp");
 gROOT->ProcessLine(".L HighScaleSystematics.cpp");
 gROOT->ProcessLine(".L LowScaleSystematics.cpp");
 gROOT->ProcessLine(".L HistogramMaker.cpp");
 gROOT->ProcessLine(".L HistogramMerger.cpp");
 std::string dataCommand = ".x loop.cc(true, \"" + dataName + "\")";
 std::cout << dataCommand << std::endl;
 gROOT->ProcessLine(dataCommand.c_str());
 std::string mcCommand = ".x loop.cc(false, \"" +  mcName + "\")";
 gROOT->ProcessLine(mcCommand.c_str());
 gROOT->ProcessLine(".x superimposeDataMC.cpp(\"Systematics.root\", \"SystematicsData.root\")");
}
