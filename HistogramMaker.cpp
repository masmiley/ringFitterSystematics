//
// Created by Jyotirmai Singh on 7/7/17.
//

#include <string>
#include "HistogramMaker.h"


TH1F* HistogramMaker::getHisto(std::string name, TFile* file)
{
    return (TH1F*) file->Get(name.c_str());
}

TH2F* HistogramMaker::get2DHisto(std::string name, TFile* file)
{
    return (TH2F*) file->Get(name.c_str());
}

HistogramMaker::HistogramMaker(TFile* file)
{
    hseedpos[0] = getHisto("hseedpos_x", file);
    hseedpos[1] = getHisto("hseedpos_y", file);
    hseedpos[2] = getHisto("hseedpos_z", file);

    hseedposdiff[0] = getHisto("hseedposdiff_x", file);
    hseedposdiff[1] = getHisto("hseedposdiff_y", file);
    hseedposdiff[2] = getHisto("hseedposdiff_z", file);

    hfitpos[0] = getHisto("hfitpos_x", file);
    hfitpos[1] = getHisto("hfitpos_y", file);
    hfitpos[2] = getHisto("hfitpos_z", file);

    hfitposdiff[0] = getHisto("hfitposdiff_x", file);
    hfitposdiff[1] = getHisto("hfitposdiff_y", file);
    hfitposdiff[2] = getHisto("hfitposdiff_z", file);

    // Prompts
    hprompt_nhits = getHisto("hprompt_nhits", file);
    hprompt_nrings = getHisto("hprompt_nrings", file);
    hprompt_pid = getHisto("hprompt_pid", file);
    hprompt_eeffenergy = getHisto("hprompt_eeffenergy", file);
    hprompt_ueffenergy = getHisto("hprompt_ueffenergy", file);
    hprompt_meffenergy = getHisto("hprompt_meffenergy", file);

    // Michel e
    hmichele_nhits = getHisto("hmichele_nhits", file);
    hmichele_deltat = getHisto("hmichele_deltat", file);
    hmichele_energy0 = getHisto("hmichele_energy0", file);
    hmichele_energy1 = getHisto("hmichele_energy1", file);
    hmichele_energy2 = getHisto("hmichele_energy2", file);

    // Neutrons
    hfollowers_nhits = getHisto("hfollowers_nhits", file);
    hfollowers_deltat = getHisto("hfollowers_deltat", file);
    hfollowers_energy0 = getHisto("hfollowers_energy0", file);
    hfollowers_energy1 = getHisto("hfollowers_energy1", file);
    hfollowers_energy2 = getHisto("hfollowers_energy2", file);
    hfollowers_dist = getHisto("hfollowers_dist", file);
    nfollowers_tot = getHisto("nfollowers_tot", file);
    nfollowers_sring = getHisto("nfollowers_sring", file);
    nfollowers_mring = getHisto("nfollowers_mring", file);
    nhit_nofollow_tot = getHisto("nhit_nofollow_tot", file);
    nhit_nofollow_sring = getHisto("nhit_nofollow_sring", file);
    nhit_nofollow_mring = getHisto("nhit_nofollow_mring", file);
    nfollowers_eeffenergy = get2DHisto("nfollowers_eeffenergy", file);
    nfollowersmean_eeffenergy = getHisto("nfollowersmean_eeffenergy", file);
    nfollowersmean_eeffenergy_norm = getHisto("nfollowersmean_eeffenergy_norm", file);
    nfollowers_sr_eeffenergy = get2DHisto("nfollowers_sr_eeffenergy", file);
    nfollowersmean_sr_eeffenergy = getHisto("nfollowersmean_sr_eeffenergy", file);
    nfollowersmean_sr_eeffenergy_norm = getHisto("nfollowersmean_sr_eeffenergy_norm", file);
    nfollowers_mr_eeffenergy = get2DHisto("nfollowersmean_mr_eeffenergy", file);
    nfollowersmean_mr_eeffenergy = getHisto("nfollowersmean_mr_eeffenergy", file);
    nfollowersmean_mr_eeffenergy_norm = getHisto("nfollowersmean_mr_eeffenergy_norm", file);

}

HistogramMaker::HistogramMaker() {

    hseedpos[0] = new TH1F("hseedpos_x","Seed Position X",200,-9000,9000);
    hseedpos[1] = new TH1F("hseedpos_y","Seed Position Y",200,-9000,9000);
    hseedpos[2] = new TH1F("hseedpos_z","Seed Position Z",200,-9000,9000);

    hseedposdiff[0]= new TH1F("hseedposdiff_x","Delta Seed Position X",200,-5000,5000);
    hseedposdiff[1]= new TH1F("hseedposdiff_y","Delta Seed Position Y",200,-5000,5000);
    hseedposdiff[2]= new TH1F("hseedposdiff_z","Delta Seed Position Z",200,-5000,5000);

    hfitpos[0] = new TH1F("hfitpos_x","Fit Position X",200,-9000,9000);
    hfitpos[1] = new TH1F("hfitpos_y","Fit Position Y",200,-9000,9000);
    hfitpos[2] = new TH1F("hfitpos_z","Fit Position Z",200,-9000,9000);

    hfitposdiff[0] = new TH1F("hfitposdiff_x","Delta Fit Position X",200,-5000,5000);
    hfitposdiff[1] = new TH1F("hfitposdiff_y","Delta Fit Position Y",200,-5000,5000);
    hfitposdiff[2] = new TH1F("hfitposdiff_z","Delta Fit Position Z",200,-5000,5000);

    // Prompts
    hprompt_nhits = new TH1F("hprompt_nhits","NHits Prompt",10,200,10000);
    hprompt_nrings = new TH1F("hprompt_nrings","NRings Prompt",3,0,3);
    hprompt_pid = new TH1F("hprompt_pid","PID Prompt",3,0,3);
    hprompt_eeffenergy = new TH1F("hprompt_eeffenergy","e Eff. Energy Prompt",28,0,5600);
    hprompt_ueffenergy = new TH1F("hprompt_ueffenergy","#mu Eff. Energy Prompt",16,0,3200);
    hprompt_meffenergy = new TH1F("hprompt_meffenergy","Multi-ring Eff. Energy Prompt",50,0,10000);

    // Michel e
    hmichele_nhits = new TH1F("hmichele_nhits","NHits Michel-e",30,0,600);
    hmichele_deltat = new TH1F("hmichele_deltat","DeltaT Michel-e",30,0,12e-6);
    hmichele_energy0 = new TH1F("hmichele_energy0","WaterFitter Look-Up Energy Michel-e",30,0,100);
    hmichele_energy1 = new TH1F("hmichele_energy1","Alt. Fitter Look-Up Energy Michel-e",30,0,100);
    hmichele_energy2 = new TH1F("hmichele_energy2","FTK Energy Michel-e",30,0,100);

    // Neutrons
    hfollowers_nhits = new TH1F("hfollowers_nhits","NHits Neutron Followers",100,0,1000);
    hfollowers_deltat = new TH1F("hfollowers_deltat","DeltaT Neutron Followers",30,0,.25);
    hfollowers_energy0 = new TH1F("hfollowers_energy0","WaterFitter Energy Neutron Followers",15,3,10.5);
    hfollowers_energy1 = new TH1F("hfollowers_energy1","Alt. Fitter Corrected Energy Neutron Followers",15,3,10.5);
    hfollowers_energy2 = new TH1F("hfollowers_energy2","FTK Energy Neutron Followers",15,3,10.5);
    hfollowers_dist = new TH1F("hfollowers_dist","Distance From Prompt Neutron Follower",30,0,10000);
    nfollowers_tot = new TH1F("nfollowers_tot","Number of Neutron Followers",15,0,15);
    nfollowers_sring = new TH1F("nfollowers_sring","Number of Neutron Followers for Single-rings",15,0,15);
    nfollowers_mring = new TH1F("nfollowers_mring","Number of Neutron Followers for Multi-rings",15,0,15);
    nhit_nofollow_tot = new TH1F("nhit_nofollow_tot","NHit for Prompts with No Neutron Followers",10,0,10000);
    nhit_nofollow_sring = new TH1F("nhit_nofollow_sring","NHit for Prompts Single-ring with No Neutron Followers",10,0,10000);
    nhit_nofollow_mring = new TH1F("nhit_nofollow_mring","NHit for Prompts Multi-ring with No Neutron Followers",10,0,10000);
    nfollowers_eeffenergy = new TH2F("nfollowers_eeffenergy","Number of Neutron Followers vs Prompt Energy",7,15,1e4,15,0,15);
    nfollowersmean_eeffenergy = new TH1F("nfollowersmean_eeffenergy","Mean Number of Neutron Followers vs Prompt Energy",7,15,1e4);
    nfollowersmean_eeffenergy_norm = new TH1F("nfollowersmean_eeffenergy_norm","nfollowersmean_eeffenergy_norm",7,15,1e4);
    nfollowers_sr_eeffenergy = new TH2F("nfollowers_sr_eeffenergy","Number of Neutron Followers vs Prompt Single-Ring Energy",7,15,1e4,15,0,15);
    nfollowersmean_sr_eeffenergy = new TH1F("nfollowersmean_sr_eeffenergy","Mean Number of Neutron Followers vs Prompt Single-Ring Energy",7,15,1e4);
    nfollowersmean_sr_eeffenergy_norm = new TH1F("nfollowersmean_sr_eeffenergy_norm","nfollowersmean_sr_eeffenergy_norm",7,15,1e4);
    nfollowers_mr_eeffenergy = new TH2F("nfollowers_mr_eeffenergy","Number of Neutron Followers vs Prompt Multi-Ring Energy",7,15,1e4,15,0,15);
    nfollowersmean_mr_eeffenergy = new TH1F("nfollowersmean_mr_eeffenergy","Mean Number of Neutron Followers vs Prompt Single-Ring Energy",7,15,1e4);
    nfollowersmean_mr_eeffenergy_norm = new TH1F("nfollowersmean_mr_eeffenergy_norm","nfollowersmean_mr_eeffenergy_norm",7,15,1e4);

    BinLogX(nfollowers_eeffenergy, false);
    BinLogX(nfollowersmean_eeffenergy,false);
    BinLogX(nfollowersmean_eeffenergy_norm,false);
    BinLogX(nfollowers_sr_eeffenergy,false);
    BinLogX(nfollowersmean_sr_eeffenergy,false);
    BinLogX(nfollowersmean_sr_eeffenergy_norm,false);
    BinLogX(nfollowers_mr_eeffenergy,false);
    BinLogX(nfollowersmean_mr_eeffenergy,false);
    BinLogX(nfollowersmean_mr_eeffenergy_norm,false);
}

/** Write all the histograms to the ROOT file */
void HistogramMaker::writeAllToFile(TFile* file)
{
    for (int i = 0; i < 3; i++) {
        file->WriteTObject(hseedpos[i]);
        file->WriteTObject(hseedposdiff[i]);
        file->WriteTObject(hfitpos[i]);
        file->WriteTObject(hfitposdiff[i]);
    }

    file->WriteTObject(hprompt_nhits);
    file->WriteTObject(hprompt_nrings);
    file->WriteTObject(hprompt_pid);
    file->WriteTObject(hprompt_eeffenergy);
    file->WriteTObject(hprompt_ueffenergy);
    file->WriteTObject(hprompt_meffenergy);

    file->WriteTObject(hmichele_nhits);
    file->WriteTObject(hmichele_deltat);
    file->WriteTObject(hmichele_energy0);
    file->WriteTObject(hmichele_energy1);
    file->WriteTObject(hmichele_energy2);

    file->WriteTObject(hfollowers_nhits);
    file->WriteTObject(hfollowers_deltat);
    file->WriteTObject(hfollowers_energy0);
    file->WriteTObject(hfollowers_energy1);
    file->WriteTObject(hfollowers_energy2);
    file->WriteTObject(hfollowers_dist);
    file->WriteTObject(nfollowers_tot);
    file->WriteTObject(nfollowers_sring);
    file->WriteTObject(nfollowers_mring);
    file->WriteTObject(nhit_nofollow_tot);
    file->WriteTObject(nhit_nofollow_sring);
    file->WriteTObject(nhit_nofollow_mring);
    file->WriteTObject(nfollowers_eeffenergy);
    file->WriteTObject(nfollowersmean_eeffenergy);
    file->WriteTObject(nfollowersmean_eeffenergy_norm);
    file->WriteTObject(nfollowers_sr_eeffenergy);
    file->WriteTObject(nfollowersmean_sr_eeffenergy);
    file->WriteTObject(nfollowersmean_sr_eeffenergy_norm);
    file->WriteTObject(nfollowers_mr_eeffenergy);
    file->WriteTObject(nfollowersmean_mr_eeffenergy);
    file->WriteTObject(nfollowersmean_mr_eeffenergy_norm);
}

/** Set the X Bins to a Logarithmic Scale on the TH1 Histogram h */
void HistogramMaker::BinLogX(TH1* h, bool loglimits)
{

    TAxis *axis = h->GetXaxis();
    int bins = axis->GetNbins();

    Axis_t from = 0;
    Axis_t to = 0;
    Axis_t width = 0;
    if(loglimits){
        from = axis->GetXmin();
        to = axis->GetXmax();
        width = (to - from) / bins;
    } else{
        from = log10(axis->GetXmin());
        to = log10(axis->GetXmax());
        width = (to - from) / bins;
    }

    Axis_t *new_bins = new Axis_t[bins + 1];

    for (int i = 0; i <= bins; i++) {
        new_bins[i] = TMath::Power(10, from + i * width);
    }
    axis->Set(bins, new_bins);
    delete new_bins;
}

/** Set the X Bins to a Logarithmic Scale on the TH2 Histogram h */
// TODO Fix log bin function names so that they are both the same.
void HistogramMaker::BinLogX (TH2* h, bool loglimits)
{

    TAxis *axis = h->GetXaxis();
    int bins = axis->GetNbins();

    Axis_t from = 0;
    Axis_t to = 0;
    Axis_t width = 0;
    if(loglimits){
        from = axis->GetXmin();
        to = axis->GetXmax();
        width = (to - from) / bins;
    } else{
        from = log10(axis->GetXmin());
        to = log10(axis->GetXmax());
        width = (to - from) / bins;
    }

    Axis_t *new_bins = new Axis_t[bins + 1];

    for (int i = 0; i <= bins; i++) {
        new_bins[i] = TMath::Power(10, from + i * width);
    }
    axis->Set(bins, new_bins);
    delete new_bins;
}
