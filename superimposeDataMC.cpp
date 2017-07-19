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
    histMC->Draw("e2");
    histData->Draw("e1 same");
}

void superimposeDataMC(std::string nameMC, std::string nameDATA)
{
    TFile* mcFile = new TFile(nameMC.c_str(), "open");
    TFile* dataFile = new TFile(nameDATA.c_str(), "open");
    TFile* combinedPlot = new TFile("FinalPlots.root", "recreate");

    TCanvas* cprompts = new TCanvas("cprompts","Prompt Distributions", 1600, 800);
    cprompts->Divide(3, 1);
    plot(cprompts, 1, "hprompt_eeffenergy", dataFile, mcFile);
    plot(cprompts, 2, "hprompt_ueffenergy", dataFile, mcFile);
    plot(cprompts, 3, "hprompt_meffenergy", dataFile, mcFile); 

    TCanvas* cnfollowersmean_eeffenergy = new TCanvas("cnfollowersmean_eeffenergy", "Number of Followers vs Prompt Energy", 1600, 800);
    cnfollowersmean_eeffenergy->Divide(3, 1);
    plot(cnfollowersmean_eeffenergy, 1, "nfollowersmean_eeffenergy", dataFile, mcFile);
    plot(cnfollowersmean_eeffenergy, 2, "nfollowersmean_sr_eeffenergy", dataFile, mcFile);
    plot(cnfollowersmean_eeffenergy, 3, "nfollowersmean_mr_eeffenergy", dataFile, mcFile);
    
    combinedPlot->WriteTObject(cprompts);
    combinedPlot->WriteTObject(cnfollowersmean_eeffenergy);
    combinedPlot->Close();
    dataFile->Close();
    mcFile->Close();
}
