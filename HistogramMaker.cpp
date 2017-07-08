//
// Created by Jyotirmai Singh on 7/7/17.
//

#include "HistogramMaker.h"
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

    // Promts
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
    hfollowers_nhits = new TH1F("hfollowers_nhit","NHits Neutron Followers",100,0,1000);
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