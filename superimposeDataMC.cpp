//
// Created by Jyotirmai Singh on 7/19/17.
//
#include <string>
#include <HistogramOverlayer.cpp>
TH1F* getHisto(std::string name, TFile* file)
{
    return (TH1F*) file->Get(name.c_str());
}

void plot(TCanvas* canv, int num, std::string name, TFile* dataFile, TFile* mcFile, bool follower)
{
    canv->cd(num);
    if (follower) {
     canv->cd(num)->SetLogx();
    }
    TH1F* histData = getHisto(name, dataFile);
    TH1F* histMC = getHisto(name, mcFile);

    histMC->SetFillColor(kRed);
    histMC->SetFillStyle(3001);
    histData->Draw("e1");
    histMC->Draw("e2, same");
    std::string promptXLabel = "Effective Prompt Energy/MeV (Black: Data, Red: MC)"; 
    std::string promptYLabel = "Number of Prompt Events";
    std::string followerXLabel = "Effective Prompt Energy (Black: Data, Red: MC)";
    std::string followerYLabel = "Average number of neutron followers per event";
    
    if (follower) {
        histData->GetXaxis()->SetTitle(followerXLabel.c_str());
        histData->GetYaxis()->SetTitle(followerYLabel.c_str());
    } else {
        histData->GetXaxis()->SetTitle(promptXLabel.c_str());
        histData->GetYaxis()->SetTitle(promptYLabel.c_str());;
   }
}

void superimposeDataMC(std::string nameMC, std::string nameDATA)
{
    TFile* mcFile = new TFile(nameMC.c_str(), "open");
    TFile* dataFile = new TFile(nameDATA.c_str(), "open");
    TFile* combinedPlot = new TFile("FinalPlots.root", "recreate");
    TFile* outF = new TFile("AllPlots.root", "recreate");
    HistogramOverlayer* over = new HistogramOverlayer(dataFile, mcFile, outF);
    over->makeHistograms();

    TCanvas* cprompts = new TCanvas("cprompts","Prompt Distributions", 1600, 800);
    cprompts->Divide(3, 1);
    plot(cprompts, 1, "hprompt_eeffenergy", dataFile, mcFile, false);
    plot(cprompts, 2, "hprompt_ueffenergy", dataFile, mcFile, false);
    plot(cprompts, 3, "hprompt_meffenergy", dataFile, mcFile, false); 

    TCanvas* cnfollowersmean_eeffenergy = new TCanvas("cnfollowersmean_eeffenergy", "Number of Followers vs Prompt Energy", 1600, 800);
    cnfollowersmean_eeffenergy->Divide(3, 1);
    plot(cnfollowersmean_eeffenergy, 1, "nfollowersmean_eeffenergy", dataFile, mcFile, true);
    plot(cnfollowersmean_eeffenergy, 2, "nfollowersmean_sr_eeffenergy", dataFile, mcFile, true);
    plot(cnfollowersmean_eeffenergy, 3, "nfollowersmean_mr_eeffenergy", dataFile, mcFile, true);
    
    combinedPlot->WriteTObject(cprompts);
    combinedPlot->WriteTObject(cnfollowersmean_eeffenergy);
    combinedPlot->Close();
    dataFile->Close();
    mcFile->Close();
}
