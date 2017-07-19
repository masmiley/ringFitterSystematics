//
// Created by Jyotirmai Singh on 7/19/17.
//
#include <string>
TH1F* getHisto(std::string name, TFile* file)
{
    return (TH1F*) file->Get(name.c_str());
}

void plot(TCanvas* canv, int num, std::string name, TFile* dataFile, TFile* mcFile)
{
    canv->cd(num);
    TH1F* histData = getHisto(name, dataFile);
    TH1F* histMC = getHisto(name, mcFile);

    histMC->SetFillColor(kRed);
    histMC->SetFillStyle(3001);
    histData->Draw("e1");
    histMC->Draw("e2 same");
}

void superimposeDataMC(std::string nameMC, std::string nameDATA)
{
    TFile* mcFile = new TFile(nameMC, "open");
    TFile* dataFile = new TFile(nameDATA, "open");
    TFile* combinedPlot = new TFile("DataMC", "recreate");

    TCanvas* cprompts = new TCanvas("cprompts","Prompt Distributions", 1600, 800);
    cprompts->Divide(3, 1);
    plot(cprompts, 1, "hprompt_eeffenergy", dataFile, mcFile);

}
