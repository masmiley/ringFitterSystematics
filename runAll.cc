#include <string> 
#include <iostream>
void runAll(bool USEWATER, std::string fName) {
 gROOT->ProcessLine(".L Systematic.cpp");
 gROOT->ProcessLine(".L HighScaleSystematics.cpp");
 gROOT->ProcessLine(".L LowScaleSystematics.cpp");
 gROOT->ProcessLine(".L HistogramMaker.cpp");
 gROOT->ProcessLine(".L HistogramMerger.cpp");
 std::string command = ".x loop.cc(" + std::string(USEWATER ? "true" : "false") + ", \"" + fName + "\")";
 std::cout << command << std::endl;
 gROOT->ProcessLine(command.c_str());
 gROOT->ProcessLine(".x superimposeData.cpp(\"Systematics.root\", \"SystematicsData.root\")");
}
