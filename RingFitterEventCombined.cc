#define RingFitterEvent_cxx
#include "RingFitterEvent.h"
#include <iostream>
#include <TH1F.h>
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <string>
#include "HistogramMaker.h"
#include "HighScaleSystematics.h"
#include "LowScaleSystematics.h"

/* Systematic Parameters */

// Low Energy
const double lowEnergyShift = 0.0041;
const double lowEnergyDelta = 0.0;
#define scaleXYZ true;
const double sysUpXYZ = 0.10;
const double sysDownXYZ = -0.57;
#define scaleZ true;
const double sysUpScZ = 0.40;
const double sysDownScZ = 0.0;
#define offsetX true;
const double sysUpOffX = 1.15 * 10;
const double sysDownOffX = -0.13 * 10;
#define offsetY true;
const double sysUpOffY = 2.87 * 10;
const double sysDownOffY = -0.17 * 10;
#define offsetZ true;
const double sysUpOffZ = 2.58 * 10;
const double sysDownOffZ = -0.15 * 10;
#define resolutionX true;
#define resolutionY true;
#define resolutionZ true;
#define edepFidVol true;
const double sysEdepFidVolUp = 0.85;
const double sysEdepFidVolDown = -0.49;

// High Energy
#define highEnergy true;
const double highEnergyShift = TMath::Abs(37.23 - 38.75)/37.23;

/* ************************************* */

/* Systematic Application Functions */

/** Applies a scaling to given variable var by parameter param */
double applyScale(double var, double param)
{
    return var * (1 + param/100);
}

/** Smears the value var with the function func */
double applySmear(double var, TF1* func)
{
    return var + func->GetRandom();
}

/** Calculates the norm of the point (x,y,z) */
double norm(double x, double y, double z)
{
    return (x * x) + (y * y) + (z * z);
}

/** Applies the Monte Carlo Energy Correction from the LETA Unidoc */
Double_t correctMCEnergy(Double_t energy, Double_t cr3)
{
    return -0.10872 + 1.0277 * (energy/cr3) - 0.0012247 * pow(energy/cr3, 2);
}

/** Applies the Michel Electron Cut */
bool micheleCut(int ifol, RingFitterEvent* rFitEv)
{
    return rFitEv->followers_nhit[ifol]>100
           && rFitEv->followers_deltat[ifol] > 800e-9
           && rFitEv->followers_deltat[ifol] < 20e-6
           && (rFitEv->followers_datacleaning2[ifol] & 0x100000) == 0x0;
}

/** Applies the Neutron Cuts */
bool neutronCut(int ifol, RingFitterEvent* rFitEv)
{
    return (rFitEv->followers_deltat[ifol] <= 20e-6 ||
            rFitEv->followers_deltat[ifol] >= 250e-3 ||
            (rFitEv->followers_datacleaning2[ifol] & 0xB56DE1) != 0x0 ||
             sqrt(rFitEv->followers_ftkpos_fX[ifol] * rFitEv->followers_ftkpos_fX[ifol]
             + rFitEv->followers_ftkpos_fY[ifol] * rFitEv->followers_ftkpos_fY[ifol]
             + rFitEv->followers_ftkpos_fZ[ifol] * rFitEv->followers_ftkpos_fZ[ifol]) > 6000.0 ||
             rFitEv->followers_energy[ifol][0] <= 4.0 ||
             double(rFitEv->followers_intime[ifol][0])/double(rFitEv->followers_nhit[ifol]) <= 0.5);
}


/* *********************************** */

void RingFitterEvent::Loop(int USEWATER)
{
    TFile* outf = new TFile("MC_CombinedSystematics.root", "recreate");
    HistogramMaker* histograms = new HistogramMaker();

    if (fChain == 0) return;

    Long64_t nentries = fChain->GetEntriesFast();
    std::cout << "Entries: " << std::endl;

    int nfol_tot = 0;
    Long64_t nbytes = 0;
    Long64_t nb = 0;

    for (Long64_t jentry = 0; jentry < nentries; jentry++) {

        Long64_t ientry = LoadTree(jentry);

        if (ientry < 0) break;
        nb = fChain->GetEntry(jentry);
        nbytes += nb;

        int seed;
        double spos_fX;
        double spos_fY;
        double spos_fZ;
        double fpos_fX;
        double fpos_fY;
        double fpos_fZ;
        double effen_e;
        double effen_m;


        if(USEWATER==1){
            seed = 0;
            spos_fX = wpos_fX;
            spos_fY = wpos_fY;
            spos_fZ = wpos_fZ;
            fpos_fX = cpos4_fX;
            fpos_fY = cpos4_fY;
            fpos_fZ = cpos4_fZ;
            effen_e = effenergy[0]; //cenergy[0]; //effenergy[0];
            effen_m = effenergy[1]; //cenergy[1]; //effenergy[1];
        }
        else{
            seed = 1;
            spos_fX = qpos_fX;
            spos_fY = qpos_fY;
            spos_fZ = qpos_fZ;
            if(USEWATER==2){
                spos_fX = hpos_fX;
                spos_fY = hpos_fY;
                spos_fZ = hpos_fZ;
            }
            fpos_fX = cpos5_fX;
            fpos_fY = cpos5_fY;
            fpos_fZ = cpos5_fZ;
            effen_e = effenergy[2]; //cenergy[2]; //effenergy[2];
            effen_m = effenergy[3]; //cenergy[3]; //effenergy[3];
        }

        //Seed tests
        histograms->hseedpos[0]->Fill(spos_fX);
        histograms->hseedpos[1]->Fill(spos_fY);
        histograms->hseedpos[2]->Fill(spos_fZ);
        histograms->hseedposdiff[0]->Fill(spos_fX - wpos_fX);
        histograms->hseedposdiff[1]->Fill(spos_fY - wpos_fY);
        histograms->hseedposdiff[2]->Fill(spos_fZ - wpos_fZ);
        histograms->hfitpos[0]->Fill(fpos_fX);
        histograms->hfitpos[1]->Fill(fpos_fY);
        histograms->hfitpos[2]->Fill(fpos_fZ);
        histograms->hfitposdiff[0]->Fill(fpos_fX - cpos4_fX);
        histograms->hfitposdiff[1]->Fill(fpos_fY - cpos4_fY);
        histograms->hfitposdiff[2]->Fill(fpos_fZ - cpos4_fZ);

        histograms->hseedpos[0]->Fill(spos_fX);
        histograms->hseedpos[1]->Fill(spos_fY);
        histograms->hseedpos[2]->Fill(spos_fZ);
        histograms->hseedposdiff[0]->Fill(spos_fX - wpos_fX);
        histograms->hseedposdiff[1]->Fill(spos_fY - wpos_fY);
        histograms->hseedposdiff[2]->Fill(spos_fZ - wpos_fZ);
        histograms->hfitpos[0]->Fill(fpos_fX);
        histograms->hfitpos[1]->Fill(fpos_fY);
        histograms->hfitpos[2]->Fill(fpos_fZ);
        histograms->hfitposdiff[0]->Fill(fpos_fX - cpos4_fX);
        histograms->hfitposdiff[1]->Fill(fpos_fY - cpos4_fY);
        histograms->hfitposdiff[2]->Fill(fpos_fZ - cpos4_fZ);

	std::cout << "Histograms Made" << std::endl;
        /* Prompt Cuts */
        if(fit[seed] == false) continue;
        if(double(intime[seed])/double(nhit) <= 0.3) continue;
        if(neck != 0) continue;
        if(owl >= 3) continue;
        if(sqrt(spos_fX*spos_fX + spos_fY*spos_fY + spos_fZ*spos_fZ) >= 8500.) continue;
        if(sqrt(fpos_fX*fpos_fX + fpos_fY*fpos_fY + fpos_fZ*fpos_fZ) <= 0 || sqrt(fpos_fX*fpos_fX + fpos_fY*fpos_fY + fpos_fZ*fpos_fZ) >= 5500) continue;
        if((datacleaning & 0xB62CC103000000) != 0) continue;
        if((trigtype & 0x7) == 0x0) continue;

        histograms->hprompt_nhits->Fill(nhit);
        histograms->hprompt_nrings->Fill(nrings[seed]);
        histograms->hprompt_pid->Fill(pid[seed]);
        if(nrings[seed] == 1){
            if(pid[seed]==0)
                histograms->hprompt_eeffenergy->Fill(effen_e);
            else if(nrings[seed] == 1 && pid[seed]==1)
                histograms->hprompt_ueffenergy->Fill(effen_m);
        } else if(nrings[seed] == 2){
            histograms->hprompt_meffenergy->Fill(effen_e);
        }

        int nfol = 0;
        double nFolNom = 0;
        double nFolLow = 0;
        double nFolUp = 0;
	
	std::cout << "At follower loop" << std::endl;
        for (int ifol = 0; ifol < followers_; ifol++) {

            // Michel E Cuts
            if (micheleCut(ifol, this)) {
                histograms->hmichele_nhits->Fill(followers_nhit[ifol]);
                histograms->hmichele_deltat->Fill(followers_deltat[ifol]);
                histograms->hmichele_energy0->Fill(followers_energy[ifol][0]);
                histograms->hmichele_energy1->Fill(followers_energy[ifol][1]);
                histograms->hmichele_energy2->Fill(followers_energy[ifol][2]);
            }

            // Neutron Cuts
            if (neutronCut(ifol, this)) continue;
            histograms->hfollowers_nhits->Fill(followers_nhit[ifol]);
            histograms->hfollowers_deltat->Fill(followers_deltat[ifol]);
            histograms->hfollowers_energy0->Fill(followers_energy[ifol][0]);
            histograms->hfollowers_energy1->Fill(followers_energy[ifol][1]);
            histograms->hfollowers_energy2->Fill(followers_energy[ifol][2]);
            histograms->hfollowers_dist->Fill(sqrt(pow((followers_wpos_fX[ifol] - wpos_fX),2) +
                                                   pow((followers_wpos_fY[ifol] - wpos_fY),2) +
                                                   pow((followers_wpos_fZ[ifol] - wpos_fZ),2)));

            double xPos = followers_wpos_fX[ifol];
            double yPos = followers_wpos_fY[ifol];
            double zPos = followers_wpos_fZ[ifol];

            double followerFTK = followers_energy[ifol][2];

            HighScaleSystematics* HSS = new HighScaleSystematics(highEnergyShift);
            double shiftUpPromptEnergy = HSS->applyEnergyShift(effen_e, 1);
            double shiftDownPromptEnergy = HSS->applyEnergyShift(effen_e, -1);

            LowScaleSystematics* LSS = new LowScaleSystematics(lowEnergyShift, lowEnergyDelta, sysUpXYZ, sysDownXYZ,
                                                               sysUpScZ, sysDownScZ, sysUpOffX, sysDownOffX,
                                                               sysUpOffY, sysDownOffY, sysUpOffZ, sysDownOffZ,
                                                               sysEdepFidVolUp, sysEdepFidVolDown);

            double xPosUp = LSS->applyPositionSystematics(xPos, 1, 1);
            double xPosDown = LSS->applyPositionSystematics(xPos, -1, 1);
            double yPosUp = LSS->applyPositionSystematics(yPos, 1, 2);
            double yPosDown = LSS->applyPositionSystematics(yPos, -1, 2);
            double zPosUp = LSS->applyPositionSystematics(zPos, 1, 3);
            double zPosDown = LSS->applyPositionSystematics(zPos, -1, 3);

            double normalSquareDistance = norm(xPos, yPos, zPos);
            double upperSquareDistance = norm(xPosUp, yPosUp, zPosUp);
            double lowerSquareDistance = norm(xPosDown, yPosDown, zPosDown);

            TF1* nominal_f = new TF1("X", "TMath::Gaus(x, 0.0, 0.154)", lowEnergyDelta - 10, lowEnergyDelta + 10);
            TF1* lower_f = new TF1("X", "TMath::Gaus(x, 0.0, 0.136)", lowEnergyDelta - 10, lowEnergyDelta + 10);
            TF1* upper_f = new TF1("X", "TMath::Gaus(x, 0.0, 0.172)", lowEnergyDelta - 10, lowEnergyDelta + 10);

            double nominalFTK = LSS->applySmearing(followerFTK, nominal_f);
            double lowerFTK = LSS->applySmearing(followerFTK, lower_f);
            double upperFTK = LSS->applySmearing(followerFTK, upper_f);

            double r3Up = (sqrt(upperSquareDistance))/(600 * 10);
            double r3Low = sqrt((lowerSquareDistance))/(600 * 10);
            double r3Nom = sqrt((normalSquareDistance))/(600 * 10);

            double cr3Up = 1.01159 - 0.0389943 * r3Up + 0.0250065 * pow(r3Up, 2);
            double cr3Low = 1.01159 - 0.0389943 * r3Low + 0.0250065 * pow(r3Low, 2);
            double cr3Nom = 1.01159 - 0.0389943 * r3Nom + 0.0250065 * pow(r3Nom, 2);

            nominalFTK = LSS->correctFollowerEnergy(nominalFTK, cr3Nom);
            lowerFTK = LSS->correctFollowerEnergy(lowerFTK, cr3Low);
            upperFTK = LSS->correctFollowerEnergy(upperFTK, cr3Up);

            double wPlus = (1. + (sysEdepFidVolUp/100.) * (nominalFTK - 5.05));
            double wMinus = (1. + (sysEdepFidVolDown/100.) * (nominalFTK - 5.05));

            if (sqrt(normalSquareDistance) <= 6000.0 && nominalFTK > 4.0) {
                nFolNom++;
            }

            if (sqrt(upperSquareDistance) <= 6000.0 && upperFTK > 4.0) {
                if (edepFidVol) {
                    nFolUp += wPlus;
                } else {
                    nFolUp++;
                }
            }

            if (sqrt(lowerSquareDistance) <= 6000.0 && lowerFTK > 4.0) {
                if (edepFidVol) {
                    nFolLow += wMinus;
                } else {
                    nFolLow++;
                }
            }

            nfol++;
            nfol_tot++;
        }
    }
    std::cout << "dONE" << std::endl;
}