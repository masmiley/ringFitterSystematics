/** @class HistogramOverlayer
 *  Takes a data file and MC file (or any two files) and
 *  overlays the 1D or profile histograms within, 
 *  and writes out any 2D histograms as before
 *  @author Max Smiley */

#include <cmath>
#include "HistogramOverlayer.h"
#include "HistogramMaker.h"

HistogramOverlayer::HistogramOverlayer() {}

HistogramOverlayer::HistogramOverlayer(TFile* dataFile, TFile* mcFile, TFile* outFile)
{
    _dataFile = dataFile;
    _mcFile = mcFile;
    _outFile = outFile;
}

/** Main method, makes all histograms and draws them on
 *  canvases. Saves canvases to _outFile for later access. Applies */
void HistogramOverlayer::makeHistograms()
{
    HistogramMaker* histsData = new HistogramMaker(_dataFile);
    HistogramMaker* histsMC = new HistogramMaker(_mcFile);

    std::string outfilename = std::string(_outFile->GetName());
    size_t index = outfilename.find(".");
    std::string pdffilename;
    pdffilename = outfilename.substr(0, index) + ".pdf";
    TCanvas* c1 = new TCanvas();
    TCanvas* c2 = new TCanvas();

    if (histsData->hists.size() != histsMC->hists.size()) return;
    for (unsigned i =0; i < histsData->hists.size(); i++) {
      if (histsData->hists.at(i)->IsA() == TH1F::Class() && histsMC->hists.at(i)->IsA() == TH1F::Class()) {
        TH1F* hData = (TH1F*) histsData->hists.at(i);
        TH1F* hMC = (TH1F*) histsMC->hists.at(i);
        hMC->SetMarkerColor(2);
        hMC->SetLineColor(2);
        hMC->Sumw2();
        hData->Sumw2();
        
        if ((string(hData->GetName())).find("nfollowers") == std::string::npos && (string(hData->GetName())).find("eeffenergy") == std::string::npos) {
          hData->Scale(1./hData->Integral(), "width");
          hMC->Scale(1./hMC->Integral(), "width");
        }
        c1->SetName(hData->GetName());
        hData->SetName((string(hData->GetName())+string("data")).c_str());
        hMC->SetName((string(hMC->GetName())+string("mc")).c_str());
        hData->SetTitle((string(hData->GetTitle())+string(" Data")).c_str());
        hMC->SetTitle((string(hMC->GetTitle())+string(" MC")).c_str());

        TPaveStats *st1;
        TPaveStats *st2; 
        if (hMC->GetMaximum() >= hData->GetMaximum()) {
          c1->cd();
          if ((string(hData->GetName())).find("nfollowers") != std::string::npos && (string(hData->GetName())).find("eeffenergy") != std::string::npos) {
            hMC->SetFillColor(kRed);
            hMC->SetFillStyle(3001);
            hMC->Draw("e2");
            c1->SetLogx();
          }
          else {
            c1->SetLogx(0);
            hMC->Draw("hist");
          }
          c1->Modified();
          c1->Update();
          st1 = (TPaveStats*) c1->GetPrimitive("stats");
          st1->SetName((string(st1->GetName())+string(hMC->GetName())).c_str());
          hData->Draw("e1sames");
          c1->Modified();
          c1->Update();
          st2 = (TPaveStats*) c1->GetPrimitive("stats");
          st2->SetName((string(st2->GetName())+string(hData->GetName())).c_str());
        }
        else {
          c1->cd();
          std::string mcstyle;
          if ((string(hData->GetName())).find("nfollowers") != std::string::npos && (string(hData->GetName())).find("eeffenergy") != std::string::npos) {
            hMC->SetFillStyle(3001);
            c1->SetLogx();
            mcstyle = "e2sames";
          }
          else {
            c1->SetLogx(0);
            mcstyle = "histsames";
          }
          hData->Draw("e1");
          c1->Modified();
          c1->Update();
          st2 = (TPaveStats*) c1->GetPrimitive("stats");
          st2->SetName((string(st2->GetName())+string(hData->GetName())).c_str());
          hMC->Draw(mcstyle.c_str());
          c1->Modified();
          c1->Update();
          st1 = (TPaveStats*) c1->GetPrimitive("stats");
          st1->SetName((string(st1->GetName())+string(hMC->GetName())).c_str());
        }
        Double_t newY2 = st1->GetY1NDC();
        Double_t newY1 = newY2 - (st2->GetY2NDC() - st2->GetY1NDC());
        st2->SetY1NDC(newY1);
        st2->SetY2NDC(newY2);
        c1->Modified();
        c1->Update();

        TLegend* leg = c1->BuildLegend(st2->GetX1NDC(), st2->GetY1NDC() - (st2->GetY2NDC() - st2->GetY1NDC()),st1->GetX2NDC(), st2->GetY1NDC());
        c1->Modified();
        c1->Update();
        _outFile->WriteTObject(c1);
        if (i == 0) {
          c1->Print((pdffilename+string("(")).c_str(), "pdf");
        }
        else if (i == histsMC->hists.size() - 1) {
          c1->Print((pdffilename+string(")")).c_str(), "pdf");
        }
        else {
          c1->Print(pdffilename.c_str(), "pdf");
        }
        c1->Clear();
      }
      else if (histsData->hists.at(i)->IsA() == TH2F::Class() && histsMC->hists.at(i)->IsA() == TH2F::Class()) {
        TH2F* h2Data = (TH2F*) histsData->hists.at(i);
        TH2F* h2MC = (TH2F*) histsMC->hists.at(i);
        c1->SetName(h2Data->GetName());
        c2->SetName(h2MC->GetName());
        h2Data->SetName((string(h2Data->GetName())+string("data")).c_str());
        h2MC->SetName((string(h2MC->GetName())+string("mc")).c_str());
        h2Data->SetTitle((string(h2Data->GetTitle())+string(" Data")).c_str());
        h2MC->SetTitle((string(h2MC->GetTitle())+string(" MC")).c_str());
        if ((string(h2Data->GetName())).find("nfollowers") != std::string::npos && (string(h2Data->GetName())).find("eeffenergy") != std::string::npos) {
          c1->SetLogx();
          c2->SetLogx();
        }
        else {
          c1->SetLogx(0);
          c2->SetLogx(0);
        }
        c1->cd();
        h2Data->Draw("colz");
        c2->cd();
        h2MC->Draw("colz");
        if (i == 0) {
          c1->Print((pdffilename+string("(")).c_str(), "pdf");
          c2->Print(pdffilename.c_str(), "pdf");
        }
        else if (i == histsMC->hists.size() - 1) {
          c1->Print(pdffilename.c_str(), "pdf");
          c2->Print((pdffilename+string(")")).c_str(), "pdf");
        }
        else {
          c1->Print(pdffilename.c_str(), "pdf");
          c2->Print(pdffilename.c_str(), "pdf");
        }
        c1->Clear();
        c2->Clear();
      }
      else if (i == histsMC->hists.size() - 1) {
         c1->Print((pdffilename+string("]")).c_str(), "pdf");
    
      }
    }
    //_outFile->Close();

}
