#ifndef RingFitterEvent_h
#define RingFitterEvent_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

// Header file for the classes stored in the TTree if any.
#include <TObject.h>
#include <TVector3.h>

// Fixed size dimensions of array or collections stored in the TTree if any.
   const Int_t kMaxfollowers = 37709;

class RingFitterEvent {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

   // Declaration of leaf types
 //Prompt          *prompts;
   UInt_t          fUniqueID;
   UInt_t          fBits;
   Int_t           runid;
   Int_t           gtid;
   Int_t           days;
   Int_t           secs;
   Int_t           nsecs;
   Int_t           nhit;
   Int_t           owl;
   Int_t           neck;
   Int_t           trigtype;
   ULong64_t       datacleaning;
   UInt_t          datacleaning1;
   UInt_t          datacleaning2;
   string          file;
   UInt_t          qpos_fUniqueID;
   UInt_t          qpos_fBits;
   Double_t        qpos_fX;
   Double_t        qpos_fY;
   Double_t        qpos_fZ;
   UInt_t          wpos_fUniqueID;
   UInt_t          wpos_fBits;
   Double_t        wpos_fX;
   Double_t        wpos_fY;
   Double_t        wpos_fZ;
   UInt_t          wdir_fUniqueID;
   UInt_t          wdir_fBits;
   Double_t        wdir_fX;
   Double_t        wdir_fY;
   Double_t        wdir_fZ;
   Double_t        itr;
   Double_t        qpdt;
   Double_t        nearly;
   Double_t        totalq;
   Double_t        hough;
   Double_t        area;
   Double_t        avgdensity;
   Double_t        ringavgdist;
   Double_t        hks;
   UInt_t          hintersect_fUniqueID;
   UInt_t          hintersect_fBits;
   Double_t        hintersect_fX;
   Double_t        hintersect_fY;
   Double_t        hintersect_fZ;
   Double_t        hough2[2];
   Double_t        area2[2];
   Double_t        avgdensity2[2];
   Double_t        ringavgdist2[2];
   Double_t        hks2[2];
   UInt_t          hintersect20_fUniqueID;
   UInt_t          hintersect20_fBits;
   Double_t        hintersect20_fX;
   Double_t        hintersect20_fY;
   Double_t        hintersect20_fZ;
   UInt_t          hintersect21_fUniqueID;
   UInt_t          hintersect21_fBits;
   Double_t        hintersect21_fX;
   Double_t        hintersect21_fY;
   Double_t        hintersect21_fZ;
   Bool_t          fit[2];
   Int_t           pid[2];
   Int_t           nrings[2];
   UInt_t          cpos0_fUniqueID;
   UInt_t          cpos0_fBits;
   Double_t        cpos0_fX;
   Double_t        cpos0_fY;
   Double_t        cpos0_fZ;
   UInt_t          cpos1_fUniqueID;
   UInt_t          cpos1_fBits;
   Double_t        cpos1_fX;
   Double_t        cpos1_fY;
   Double_t        cpos1_fZ;
   UInt_t          cpos2_fUniqueID;
   UInt_t          cpos2_fBits;
   Double_t        cpos2_fX;
   Double_t        cpos2_fY;
   Double_t        cpos2_fZ;
   UInt_t          cpos3_fUniqueID;
   UInt_t          cpos3_fBits;
   Double_t        cpos3_fX;
   Double_t        cpos3_fY;
   Double_t        cpos3_fZ;
   UInt_t          cpos4_fUniqueID;
   UInt_t          cpos4_fBits;
   Double_t        cpos4_fX;
   Double_t        cpos4_fY;
   Double_t        cpos4_fZ;
   UInt_t          cpos5_fUniqueID;
   UInt_t          cpos5_fBits;
   Double_t        cpos5_fX;
   Double_t        cpos5_fY;
   Double_t        cpos5_fZ;
   UInt_t          cdir0_fUniqueID;
   UInt_t          cdir0_fBits;
   Double_t        cdir0_fX;
   Double_t        cdir0_fY;
   Double_t        cdir0_fZ;
   UInt_t          cdir1_fUniqueID;
   UInt_t          cdir1_fBits;
   Double_t        cdir1_fX;
   Double_t        cdir1_fY;
   Double_t        cdir1_fZ;
   UInt_t          cdir2_fUniqueID;
   UInt_t          cdir2_fBits;
   Double_t        cdir2_fX;
   Double_t        cdir2_fY;
   Double_t        cdir2_fZ;
   UInt_t          cdir3_fUniqueID;
   UInt_t          cdir3_fBits;
   Double_t        cdir3_fX;
   Double_t        cdir3_fY;
   Double_t        cdir3_fZ;
   UInt_t          cdir4_fUniqueID;
   UInt_t          cdir4_fBits;
   Double_t        cdir4_fX;
   Double_t        cdir4_fY;
   Double_t        cdir4_fZ;
   UInt_t          cdir5_fUniqueID;
   UInt_t          cdir5_fBits;
   Double_t        cdir5_fX;
   Double_t        cdir5_fY;
   Double_t        cdir5_fZ;
   Double_t        ctime[4];
   Double_t        cenergy[4];
   Double_t        effenergy[4];
   Double_t        effenergy2[4];
   Double_t        energy[3];
   Int_t           intime[2];
   Int_t           cintime[4];
   Double_t        totlike[4];
   Double_t        anglike[4];
   Int_t           outside;
   UInt_t          mcpos_fUniqueID;
   UInt_t          mcpos_fBits;
   Double_t        mcpos_fX;
   Double_t        mcpos_fY;
   Double_t        mcpos_fZ;
   UInt_t          mcdir_fUniqueID;
   UInt_t          mcdir_fBits;
   Double_t        mcdir_fX;
   Double_t        mcdir_fY;
   Double_t        mcdir_fZ;
   Double_t        mcenergy;
   Double_t        mctime;
   Double_t        gtrigtime;
   Int_t           mcid;
   Int_t           evi;
   Bool_t          mc;
   Int_t           interaction;
   Int_t           nutype;
   Int_t           pneutrons;
   Int_t           tneutrons;
   string          particles;
   Int_t           followers_;
   UInt_t          followers_fUniqueID[kMaxfollowers];   //[followers_]
   UInt_t          followers_fBits[kMaxfollowers];   //[followers_]
   Int_t           followers_runid[kMaxfollowers];   //[followers_]
   Int_t           followers_gtid[kMaxfollowers];   //[followers_]
   Int_t           followers_days[kMaxfollowers];   //[followers_]
   Int_t           followers_secs[kMaxfollowers];   //[followers_]
   Int_t           followers_nsecs[kMaxfollowers];   //[followers_]
   Int_t           followers_nhit[kMaxfollowers];   //[followers_]
   Int_t           followers_owl[kMaxfollowers];   //[followers_]
   Int_t           followers_neck[kMaxfollowers];   //[followers_]
   Int_t           followers_trigtype[kMaxfollowers];   //[followers_]
   ULong64_t       followers_datacleaning[kMaxfollowers];   //[followers_]
   UInt_t          followers_datacleaning1[kMaxfollowers];   //[followers_]
   UInt_t          followers_datacleaning2[kMaxfollowers];   //[followers_]
   string          followers_file[kMaxfollowers];
   UInt_t          followers_qpos_fUniqueID[kMaxfollowers];   //[followers_]
   UInt_t          followers_qpos_fBits[kMaxfollowers];   //[followers_]
   Double_t        followers_qpos_fX[kMaxfollowers];   //[followers_]
   Double_t        followers_qpos_fY[kMaxfollowers];   //[followers_]
   Double_t        followers_qpos_fZ[kMaxfollowers];   //[followers_]
   UInt_t          followers_wpos_fUniqueID[kMaxfollowers];   //[followers_]
   UInt_t          followers_wpos_fBits[kMaxfollowers];   //[followers_]
   Double_t        followers_wpos_fX[kMaxfollowers];   //[followers_]
   Double_t        followers_wpos_fY[kMaxfollowers];   //[followers_]
   Double_t        followers_wpos_fZ[kMaxfollowers];   //[followers_]
   Double_t        followers_ftkpos_fX[kMaxfollowers]; //[followers_]
   Double_t        followers_ftkpos_fY[kMaxfollowers]; //[followers_]
   Double_t        followers_ftkpos_fZ[kMaxfollowers]; //[followers_]
   UInt_t          followers_wdir_fUniqueID[kMaxfollowers];   //[followers_]
   UInt_t          followers_wdir_fBits[kMaxfollowers];   //[followers_]
   Double_t        followers_wdir_fX[kMaxfollowers];   //[followers_]
   Double_t        followers_wdir_fY[kMaxfollowers];   //[followers_]
   Double_t        followers_wdir_fZ[kMaxfollowers];   //[followers_]
   Double_t        followers_itr[kMaxfollowers];   //[followers_]
   Double_t        followers_ftkitr[kMaxfollowers]; //[followers_]
   Double_t        followers_qpdt[kMaxfollowers];   //[followers_]
   Double_t        followers_nearly[kMaxfollowers];   //[followers_]
   Double_t        followers_totalq[kMaxfollowers];   //[followers_]
   Double_t        followers_hough[kMaxfollowers];   //[followers_]
   Double_t        followers_area[kMaxfollowers];   //[followers_]
   Double_t        followers_avgdensity[kMaxfollowers];   //[followers_]
   Double_t        followers_ringavgdist[kMaxfollowers];   //[followers_]
   Double_t        followers_hks[kMaxfollowers];   //[followers_]
   UInt_t          followers_hintersect_fUniqueID[kMaxfollowers];   //[followers_]
   UInt_t          followers_hintersect_fBits[kMaxfollowers];   //[followers_]
   Double_t        followers_hintersect_fX[kMaxfollowers];   //[followers_]
   Double_t        followers_hintersect_fY[kMaxfollowers];   //[followers_]
   Double_t        followers_hintersect_fZ[kMaxfollowers];   //[followers_]
   Double_t        followers_hough2[kMaxfollowers][2];   //[followers_]
   Double_t        followers_area2[kMaxfollowers][2];   //[followers_]
   Double_t        followers_avgdensity2[kMaxfollowers][2];   //[followers_]
   Double_t        followers_ringavgdist2[kMaxfollowers][2];   //[followers_]
   Double_t        followers_hks2[kMaxfollowers][2];   //[followers_]
   UInt_t          followers_hintersect20_fUniqueID[kMaxfollowers];   //[followers_]
   UInt_t          followers_hintersect20_fBits[kMaxfollowers];   //[followers_]
   Double_t        followers_hintersect20_fX[kMaxfollowers];   //[followers_]
   Double_t        followers_hintersect20_fY[kMaxfollowers];   //[followers_]
   Double_t        followers_hintersect20_fZ[kMaxfollowers];   //[followers_]
   UInt_t          followers_hintersect21_fUniqueID[kMaxfollowers];   //[followers_]
   UInt_t          followers_hintersect21_fBits[kMaxfollowers];   //[followers_]
   Double_t        followers_hintersect21_fX[kMaxfollowers];   //[followers_]
   Double_t        followers_hintersect21_fY[kMaxfollowers];   //[followers_]
   Double_t        followers_hintersect21_fZ[kMaxfollowers];   //[followers_]
   Bool_t          followers_fit[kMaxfollowers][2];   //[followers_]
   Int_t           followers_pid[kMaxfollowers][2];   //[followers_]
   Int_t           followers_nrings[kMaxfollowers][2];   //[followers_]
   UInt_t          followers_cpos0_fUniqueID[kMaxfollowers];   //[followers_]
   UInt_t          followers_cpos0_fBits[kMaxfollowers];   //[followers_]
   Double_t        followers_cpos0_fX[kMaxfollowers];   //[followers_]
   Double_t        followers_cpos0_fY[kMaxfollowers];   //[followers_]
   Double_t        followers_cpos0_fZ[kMaxfollowers];   //[followers_]
   UInt_t          followers_cpos1_fUniqueID[kMaxfollowers];   //[followers_]
   UInt_t          followers_cpos1_fBits[kMaxfollowers];   //[followers_]
   Double_t        followers_cpos1_fX[kMaxfollowers];   //[followers_]
   Double_t        followers_cpos1_fY[kMaxfollowers];   //[followers_]
   Double_t        followers_cpos1_fZ[kMaxfollowers];   //[followers_]
   UInt_t          followers_cpos2_fUniqueID[kMaxfollowers];   //[followers_]
   UInt_t          followers_cpos2_fBits[kMaxfollowers];   //[followers_]
   Double_t        followers_cpos2_fX[kMaxfollowers];   //[followers_]
   Double_t        followers_cpos2_fY[kMaxfollowers];   //[followers_]
   Double_t        followers_cpos2_fZ[kMaxfollowers];   //[followers_]
   UInt_t          followers_cpos3_fUniqueID[kMaxfollowers];   //[followers_]
   UInt_t          followers_cpos3_fBits[kMaxfollowers];   //[followers_]
   Double_t        followers_cpos3_fX[kMaxfollowers];   //[followers_]
   Double_t        followers_cpos3_fY[kMaxfollowers];   //[followers_]
   Double_t        followers_cpos3_fZ[kMaxfollowers];   //[followers_]
   UInt_t          followers_cpos4_fUniqueID[kMaxfollowers];   //[followers_]
   UInt_t          followers_cpos4_fBits[kMaxfollowers];   //[followers_]
   Double_t        followers_cpos4_fX[kMaxfollowers];   //[followers_]
   Double_t        followers_cpos4_fY[kMaxfollowers];   //[followers_]
   Double_t        followers_cpos4_fZ[kMaxfollowers];   //[followers_]
   UInt_t          followers_cpos5_fUniqueID[kMaxfollowers];   //[followers_]
   UInt_t          followers_cpos5_fBits[kMaxfollowers];   //[followers_]
   Double_t        followers_cpos5_fX[kMaxfollowers];   //[followers_]
   Double_t        followers_cpos5_fY[kMaxfollowers];   //[followers_]
   Double_t        followers_cpos5_fZ[kMaxfollowers];   //[followers_]
   UInt_t          followers_cdir0_fUniqueID[kMaxfollowers];   //[followers_]
   UInt_t          followers_cdir0_fBits[kMaxfollowers];   //[followers_]
   Double_t        followers_cdir0_fX[kMaxfollowers];   //[followers_]
   Double_t        followers_cdir0_fY[kMaxfollowers];   //[followers_]
   Double_t        followers_cdir0_fZ[kMaxfollowers];   //[followers_]
   UInt_t          followers_cdir1_fUniqueID[kMaxfollowers];   //[followers_]
   UInt_t          followers_cdir1_fBits[kMaxfollowers];   //[followers_]
   Double_t        followers_cdir1_fX[kMaxfollowers];   //[followers_]
   Double_t        followers_cdir1_fY[kMaxfollowers];   //[followers_]
   Double_t        followers_cdir1_fZ[kMaxfollowers];   //[followers_]
   UInt_t          followers_cdir2_fUniqueID[kMaxfollowers];   //[followers_]
   UInt_t          followers_cdir2_fBits[kMaxfollowers];   //[followers_]
   Double_t        followers_cdir2_fX[kMaxfollowers];   //[followers_]
   Double_t        followers_cdir2_fY[kMaxfollowers];   //[followers_]
   Double_t        followers_cdir2_fZ[kMaxfollowers];   //[followers_]
   UInt_t          followers_cdir3_fUniqueID[kMaxfollowers];   //[followers_]
   UInt_t          followers_cdir3_fBits[kMaxfollowers];   //[followers_]
   Double_t        followers_cdir3_fX[kMaxfollowers];   //[followers_]
   Double_t        followers_cdir3_fY[kMaxfollowers];   //[followers_]
   Double_t        followers_cdir3_fZ[kMaxfollowers];   //[followers_]
   UInt_t          followers_cdir4_fUniqueID[kMaxfollowers];   //[followers_]
   UInt_t          followers_cdir4_fBits[kMaxfollowers];   //[followers_]
   Double_t        followers_cdir4_fX[kMaxfollowers];   //[followers_]
   Double_t        followers_cdir4_fY[kMaxfollowers];   //[followers_]
   Double_t        followers_cdir4_fZ[kMaxfollowers];   //[followers_]
   UInt_t          followers_cdir5_fUniqueID[kMaxfollowers];   //[followers_]
   UInt_t          followers_cdir5_fBits[kMaxfollowers];   //[followers_]
   Double_t        followers_cdir5_fX[kMaxfollowers];   //[followers_]
   Double_t        followers_cdir5_fY[kMaxfollowers];   //[followers_]
   Double_t        followers_cdir5_fZ[kMaxfollowers];   //[followers_]
   Double_t        followers_ctime[kMaxfollowers][4];   //[followers_]
   Double_t        followers_cenergy[kMaxfollowers][4];   //[followers_]
   Double_t        followers_effenergy[kMaxfollowers][4];   //[followers_]
   Double_t        followers_effenergy2[kMaxfollowers][4];   //[followers_]
   Double_t        followers_energy[kMaxfollowers][3];   //[followers_]
   Int_t           followers_intime[kMaxfollowers][2];   //[followers_]
   Int_t           followers_cintime[kMaxfollowers][4];   //[followers_]
   Double_t        followers_totlike[kMaxfollowers][4];   //[followers_]
   Double_t        followers_anglike[kMaxfollowers][4];   //[followers_]
   Int_t           followers_outside[kMaxfollowers];   //[followers_]
   UInt_t          followers_mcpos_fUniqueID[kMaxfollowers];   //[followers_]
   UInt_t          followers_mcpos_fBits[kMaxfollowers];   //[followers_]
   Double_t        followers_mcpos_fX[kMaxfollowers];   //[followers_]
   Double_t        followers_mcpos_fY[kMaxfollowers];   //[followers_]
   Double_t        followers_mcpos_fZ[kMaxfollowers];   //[followers_]
   UInt_t          followers_mcdir_fUniqueID[kMaxfollowers];   //[followers_]
   UInt_t          followers_mcdir_fBits[kMaxfollowers];   //[followers_]
   Double_t        followers_mcdir_fX[kMaxfollowers];   //[followers_]
   Double_t        followers_mcdir_fY[kMaxfollowers];   //[followers_]
   Double_t        followers_mcdir_fZ[kMaxfollowers];   //[followers_]
   Double_t        followers_mcenergy[kMaxfollowers];   //[followers_]
   Double_t        followers_mctime[kMaxfollowers];   //[followers_]
   Double_t        followers_gtrigtime[kMaxfollowers];   //[followers_]
   Int_t           followers_mcid[kMaxfollowers];   //[followers_]
   Int_t           followers_evi[kMaxfollowers];   //[followers_]
   Bool_t          followers_mc[kMaxfollowers];   //[followers_]
   Double_t        followers_deltat[kMaxfollowers];   //[followers_]
   vector<Double_t> reweight_up;
   vector<Double_t> reweight_down;

   // List of branches
   TBranch        *b_prompts_fUniqueID;   //!
   TBranch        *b_prompts_fBits;   //!
   TBranch        *b_prompts_runid;   //!
   TBranch        *b_prompts_gtid;   //!
   TBranch        *b_prompts_days;   //!
   TBranch        *b_prompts_secs;   //!
   TBranch        *b_prompts_nsecs;   //!
   TBranch        *b_prompts_nhit;   //!
   TBranch        *b_prompts_owl;   //!
   TBranch        *b_prompts_neck;   //!
   TBranch        *b_prompts_trigtype;   //!
   TBranch        *b_prompts_datacleaning;   //!
   TBranch        *b_prompts_datacleaning1;   //!
   TBranch        *b_prompts_datacleaning2;   //!
   TBranch        *b_prompts_file;   //!
   TBranch        *b_prompts_qpos_fUniqueID;   //!
   TBranch        *b_prompts_qpos_fBits;   //!
   TBranch        *b_prompts_qpos_fX;   //!
   TBranch        *b_prompts_qpos_fY;   //!
   TBranch        *b_prompts_qpos_fZ;   //!
   TBranch        *b_prompts_wpos_fUniqueID;   //!
   TBranch        *b_prompts_wpos_fBits;   //!
   TBranch        *b_prompts_wpos_fX;   //!
   TBranch        *b_prompts_wpos_fY;   //!
   TBranch        *b_prompts_wpos_fZ;   //!
   TBranch        *b_prompts_wdir_fUniqueID;   //!
   TBranch        *b_prompts_wdir_fBits;   //!
   TBranch        *b_prompts_wdir_fX;   //!
   TBranch        *b_prompts_wdir_fY;   //!
   TBranch        *b_prompts_wdir_fZ;   //!
   TBranch        *b_prompts_itr;   //!
   TBranch        *b_prompts_qpdt;   //!
   TBranch        *b_prompts_nearly;   //!
   TBranch        *b_prompts_totalq;   //!
   TBranch        *b_prompts_hough;   //!
   TBranch        *b_prompts_area;   //!
   TBranch        *b_prompts_avgdensity;   //!
   TBranch        *b_prompts_ringavgdist;   //!
   TBranch        *b_prompts_hks;   //!
   TBranch        *b_prompts_hintersect_fUniqueID;   //!
   TBranch        *b_prompts_hintersect_fBits;   //!
   TBranch        *b_prompts_hintersect_fX;   //!
   TBranch        *b_prompts_hintersect_fY;   //!
   TBranch        *b_prompts_hintersect_fZ;   //!
   TBranch        *b_prompts_hough2;   //!
   TBranch        *b_prompts_area2;   //!
   TBranch        *b_prompts_avgdensity2;   //!
   TBranch        *b_prompts_ringavgdist2;   //!
   TBranch        *b_prompts_hks2;   //!
   TBranch        *b_prompts_hintersect20_fUniqueID;   //!
   TBranch        *b_prompts_hintersect20_fBits;   //!
   TBranch        *b_prompts_hintersect20_fX;   //!
   TBranch        *b_prompts_hintersect20_fY;   //!
   TBranch        *b_prompts_hintersect20_fZ;   //!
   TBranch        *b_prompts_hintersect21_fUniqueID;   //!
   TBranch        *b_prompts_hintersect21_fBits;   //!
   TBranch        *b_prompts_hintersect21_fX;   //!
   TBranch        *b_prompts_hintersect21_fY;   //!
   TBranch        *b_prompts_hintersect21_fZ;   //!
   TBranch        *b_prompts_fit;   //!
   TBranch        *b_prompts_pid;   //!
   TBranch        *b_prompts_nrings;   //!
   TBranch        *b_prompts_cpos0_fUniqueID;   //!
   TBranch        *b_prompts_cpos0_fBits;   //!
   TBranch        *b_prompts_cpos0_fX;   //!
   TBranch        *b_prompts_cpos0_fY;   //!
   TBranch        *b_prompts_cpos0_fZ;   //!
   TBranch        *b_prompts_cpos1_fUniqueID;   //!
   TBranch        *b_prompts_cpos1_fBits;   //!
   TBranch        *b_prompts_cpos1_fX;   //!
   TBranch        *b_prompts_cpos1_fY;   //!
   TBranch        *b_prompts_cpos1_fZ;   //!
   TBranch        *b_prompts_cpos2_fUniqueID;   //!
   TBranch        *b_prompts_cpos2_fBits;   //!
   TBranch        *b_prompts_cpos2_fX;   //!
   TBranch        *b_prompts_cpos2_fY;   //!
   TBranch        *b_prompts_cpos2_fZ;   //!
   TBranch        *b_prompts_cpos3_fUniqueID;   //!
   TBranch        *b_prompts_cpos3_fBits;   //!
   TBranch        *b_prompts_cpos3_fX;   //!
   TBranch        *b_prompts_cpos3_fY;   //!
   TBranch        *b_prompts_cpos3_fZ;   //!
   TBranch        *b_prompts_cpos4_fUniqueID;   //!
   TBranch        *b_prompts_cpos4_fBits;   //!
   TBranch        *b_prompts_cpos4_fX;   //!
   TBranch        *b_prompts_cpos4_fY;   //!
   TBranch        *b_prompts_cpos4_fZ;   //!
   TBranch        *b_prompts_cpos5_fUniqueID;   //!
   TBranch        *b_prompts_cpos5_fBits;   //!
   TBranch        *b_prompts_cpos5_fX;   //!
   TBranch        *b_prompts_cpos5_fY;   //!
   TBranch        *b_prompts_cpos5_fZ;   //!
   TBranch        *b_prompts_cdir0_fUniqueID;   //!
   TBranch        *b_prompts_cdir0_fBits;   //!
   TBranch        *b_prompts_cdir0_fX;   //!
   TBranch        *b_prompts_cdir0_fY;   //!
   TBranch        *b_prompts_cdir0_fZ;   //!
   TBranch        *b_prompts_cdir1_fUniqueID;   //!
   TBranch        *b_prompts_cdir1_fBits;   //!
   TBranch        *b_prompts_cdir1_fX;   //!
   TBranch        *b_prompts_cdir1_fY;   //!
   TBranch        *b_prompts_cdir1_fZ;   //!
   TBranch        *b_prompts_cdir2_fUniqueID;   //!
   TBranch        *b_prompts_cdir2_fBits;   //!
   TBranch        *b_prompts_cdir2_fX;   //!
   TBranch        *b_prompts_cdir2_fY;   //!
   TBranch        *b_prompts_cdir2_fZ;   //!
   TBranch        *b_prompts_cdir3_fUniqueID;   //!
   TBranch        *b_prompts_cdir3_fBits;   //!
   TBranch        *b_prompts_cdir3_fX;   //!
   TBranch        *b_prompts_cdir3_fY;   //!
   TBranch        *b_prompts_cdir3_fZ;   //!
   TBranch        *b_prompts_cdir4_fUniqueID;   //!
   TBranch        *b_prompts_cdir4_fBits;   //!
   TBranch        *b_prompts_cdir4_fX;   //!
   TBranch        *b_prompts_cdir4_fY;   //!
   TBranch        *b_prompts_cdir4_fZ;   //!
   TBranch        *b_prompts_cdir5_fUniqueID;   //!
   TBranch        *b_prompts_cdir5_fBits;   //!
   TBranch        *b_prompts_cdir5_fX;   //!
   TBranch        *b_prompts_cdir5_fY;   //!
   TBranch        *b_prompts_cdir5_fZ;   //!
   TBranch        *b_prompts_ctime;   //!
   TBranch        *b_prompts_cenergy;   //!
   TBranch        *b_prompts_effenergy;   //!
   TBranch        *b_prompts_effenergy2;   //!
   TBranch        *b_prompts_energy;   //!
   TBranch        *b_prompts_intime;   //!
   TBranch        *b_prompts_cintime;   //!
   TBranch        *b_prompts_totlike;   //!
   TBranch        *b_prompts_anglike;   //!
   TBranch        *b_prompts_outside;   //!
   TBranch        *b_prompts_mcpos_fUniqueID;   //!
   TBranch        *b_prompts_mcpos_fBits;   //!
   TBranch        *b_prompts_mcpos_fX;   //!
   TBranch        *b_prompts_mcpos_fY;   //!
   TBranch        *b_prompts_mcpos_fZ;   //!
   TBranch        *b_prompts_mcdir_fUniqueID;   //!
   TBranch        *b_prompts_mcdir_fBits;   //!
   TBranch        *b_prompts_mcdir_fX;   //!
   TBranch        *b_prompts_mcdir_fY;   //!
   TBranch        *b_prompts_mcdir_fZ;   //!
   TBranch        *b_prompts_mcenergy;   //!
   TBranch        *b_prompts_mctime;   //!
   TBranch        *b_prompts_gtrigtime;   //!
   TBranch        *b_prompts_mcid;   //!
   TBranch        *b_prompts_evi;   //!
   TBranch        *b_prompts_mc;   //!
   TBranch        *b_prompts_interaction;   //!
   TBranch        *b_prompts_nutype;   //!
   TBranch        *b_prompts_pneutrons;   //!
   TBranch        *b_prompts_tneutrons;   //!
   TBranch        *b_prompts_particles;   //!
   TBranch        *b_prompts_followers_;   //!
   TBranch        *b_followers_fUniqueID;   //!
   TBranch        *b_followers_fBits;   //!
   TBranch        *b_followers_runid;   //!
   TBranch        *b_followers_gtid;   //!
   TBranch        *b_followers_days;   //!
   TBranch        *b_followers_secs;   //!
   TBranch        *b_followers_nsecs;   //!
   TBranch        *b_followers_nhit;   //!
   TBranch        *b_followers_owl;   //!
   TBranch        *b_followers_neck;   //!
   TBranch        *b_followers_trigtype;   //!
   TBranch        *b_followers_datacleaning;   //!
   TBranch        *b_followers_datacleaning1;   //!
   TBranch        *b_followers_datacleaning2;   //!
   TBranch        *b_followers_file;   //!
   TBranch        *b_followers_qpos_fUniqueID;   //!
   TBranch        *b_followers_qpos_fBits;   //!
   TBranch        *b_followers_qpos_fX;   //!
   TBranch        *b_followers_qpos_fY;   //!
   TBranch        *b_followers_qpos_fZ;   //!
   TBranch        *b_followers_wpos_fUniqueID;   //!
   TBranch        *b_followers_wpos_fBits;   //!
   TBranch        *b_followers_wpos_fX;   //!
   TBranch        *b_followers_wpos_fY;   //!
   TBranch        *b_followers_wpos_fZ;   //!
   TBranch        *b_followers_ftkpos_fX; //!
   TBranch        *b_followers_ftkpos_fY; //!
   TBranch        *b_followers_ftkpos_fZ; //!
   TBranch        *b_followers_wdir_fUniqueID;   //!
   TBranch        *b_followers_wdir_fBits;   //!
   TBranch        *b_followers_wdir_fX;   //!
   TBranch        *b_followers_wdir_fY;   //!
   TBranch        *b_followers_wdir_fZ;   //!
   TBranch        *b_followers_itr;   //!
   TBranch        *b_followers_ftkitr; //!
   TBranch        *b_followers_qpdt;   //!
   TBranch        *b_followers_nearly;   //!
   TBranch        *b_followers_totalq;   //!
   TBranch        *b_followers_hough;   //!
   TBranch        *b_followers_area;   //!
   TBranch        *b_followers_avgdensity;   //!
   TBranch        *b_followers_ringavgdist;   //!
   TBranch        *b_followers_hks;   //!
   TBranch        *b_followers_hintersect_fUniqueID;   //!
   TBranch        *b_followers_hintersect_fBits;   //!
   TBranch        *b_followers_hintersect_fX;   //!
   TBranch        *b_followers_hintersect_fY;   //!
   TBranch        *b_followers_hintersect_fZ;   //!
   TBranch        *b_followers_hough2;   //!
   TBranch        *b_followers_area2;   //!
   TBranch        *b_followers_avgdensity2;   //!
   TBranch        *b_followers_ringavgdist2;   //!
   TBranch        *b_followers_hks2;   //!
   TBranch        *b_followers_hintersect20_fUniqueID;   //!
   TBranch        *b_followers_hintersect20_fBits;   //!
   TBranch        *b_followers_hintersect20_fX;   //!
   TBranch        *b_followers_hintersect20_fY;   //!
   TBranch        *b_followers_hintersect20_fZ;   //!
   TBranch        *b_followers_hintersect21_fUniqueID;   //!
   TBranch        *b_followers_hintersect21_fBits;   //!
   TBranch        *b_followers_hintersect21_fX;   //!
   TBranch        *b_followers_hintersect21_fY;   //!
   TBranch        *b_followers_hintersect21_fZ;   //!
   TBranch        *b_followers_fit;   //!
   TBranch        *b_followers_pid;   //!
   TBranch        *b_followers_nrings;   //!
   TBranch        *b_followers_cpos0_fUniqueID;   //!
   TBranch        *b_followers_cpos0_fBits;   //!
   TBranch        *b_followers_cpos0_fX;   //!
   TBranch        *b_followers_cpos0_fY;   //!
   TBranch        *b_followers_cpos0_fZ;   //!
   TBranch        *b_followers_cpos1_fUniqueID;   //!
   TBranch        *b_followers_cpos1_fBits;   //!
   TBranch        *b_followers_cpos1_fX;   //!
   TBranch        *b_followers_cpos1_fY;   //!
   TBranch        *b_followers_cpos1_fZ;   //!
   TBranch        *b_followers_cpos2_fUniqueID;   //!
   TBranch        *b_followers_cpos2_fBits;   //!
   TBranch        *b_followers_cpos2_fX;   //!
   TBranch        *b_followers_cpos2_fY;   //!
   TBranch        *b_followers_cpos2_fZ;   //!
   TBranch        *b_followers_cpos3_fUniqueID;   //!
   TBranch        *b_followers_cpos3_fBits;   //!
   TBranch        *b_followers_cpos3_fX;   //!
   TBranch        *b_followers_cpos3_fY;   //!
   TBranch        *b_followers_cpos3_fZ;   //!
   TBranch        *b_followers_cpos4_fUniqueID;   //!
   TBranch        *b_followers_cpos4_fBits;   //!
   TBranch        *b_followers_cpos4_fX;   //!
   TBranch        *b_followers_cpos4_fY;   //!
   TBranch        *b_followers_cpos4_fZ;   //!
   TBranch        *b_followers_cpos5_fUniqueID;   //!
   TBranch        *b_followers_cpos5_fBits;   //!
   TBranch        *b_followers_cpos5_fX;   //!
   TBranch        *b_followers_cpos5_fY;   //!
   TBranch        *b_followers_cpos5_fZ;   //!
   TBranch        *b_followers_cdir0_fUniqueID;   //!
   TBranch        *b_followers_cdir0_fBits;   //!
   TBranch        *b_followers_cdir0_fX;   //!
   TBranch        *b_followers_cdir0_fY;   //!
   TBranch        *b_followers_cdir0_fZ;   //!
   TBranch        *b_followers_cdir1_fUniqueID;   //!
   TBranch        *b_followers_cdir1_fBits;   //!
   TBranch        *b_followers_cdir1_fX;   //!
   TBranch        *b_followers_cdir1_fY;   //!
   TBranch        *b_followers_cdir1_fZ;   //!
   TBranch        *b_followers_cdir2_fUniqueID;   //!
   TBranch        *b_followers_cdir2_fBits;   //!
   TBranch        *b_followers_cdir2_fX;   //!
   TBranch        *b_followers_cdir2_fY;   //!
   TBranch        *b_followers_cdir2_fZ;   //!
   TBranch        *b_followers_cdir3_fUniqueID;   //!
   TBranch        *b_followers_cdir3_fBits;   //!
   TBranch        *b_followers_cdir3_fX;   //!
   TBranch        *b_followers_cdir3_fY;   //!
   TBranch        *b_followers_cdir3_fZ;   //!
   TBranch        *b_followers_cdir4_fUniqueID;   //!
   TBranch        *b_followers_cdir4_fBits;   //!
   TBranch        *b_followers_cdir4_fX;   //!
   TBranch        *b_followers_cdir4_fY;   //!
   TBranch        *b_followers_cdir4_fZ;   //!
   TBranch        *b_followers_cdir5_fUniqueID;   //!
   TBranch        *b_followers_cdir5_fBits;   //!
   TBranch        *b_followers_cdir5_fX;   //!
   TBranch        *b_followers_cdir5_fY;   //!
   TBranch        *b_followers_cdir5_fZ;   //!
   TBranch        *b_followers_ctime;   //!
   TBranch        *b_followers_cenergy;   //!
   TBranch        *b_followers_effenergy;   //!
   TBranch        *b_followers_effenergy2;   //!
   TBranch        *b_followers_energy;   //!
   TBranch        *b_followers_intime;   //!
   TBranch        *b_followers_cintime;   //!
   TBranch        *b_followers_totlike;   //!
   TBranch        *b_followers_anglike;   //!
   TBranch        *b_followers_outside;   //!
   TBranch        *b_followers_mcpos_fUniqueID;   //!
   TBranch        *b_followers_mcpos_fBits;   //!
   TBranch        *b_followers_mcpos_fX;   //!
   TBranch        *b_followers_mcpos_fY;   //!
   TBranch        *b_followers_mcpos_fZ;   //!
   TBranch        *b_followers_mcdir_fUniqueID;   //!
   TBranch        *b_followers_mcdir_fBits;   //!
   TBranch        *b_followers_mcdir_fX;   //!
   TBranch        *b_followers_mcdir_fY;   //!
   TBranch        *b_followers_mcdir_fZ;   //!
   TBranch        *b_followers_mcenergy;   //!
   TBranch        *b_followers_mctime;   //!
   TBranch        *b_followers_gtrigtime;   //!
   TBranch        *b_followers_mcid;   //!
   TBranch        *b_followers_evi;   //!
   TBranch        *b_followers_mc;   //!
   TBranch        *b_followers_deltat;   //!
   TBranch        *b_prompts_reweight_up;   //!
   TBranch        *b_prompts_reweight_down;   //!

   RingFitterEvent(TTree *tree=0);
   virtual ~RingFitterEvent();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop(int USEWATER, int dir, bool data);
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
};

#endif

#ifdef RingFitterEvent_cxx
RingFitterEvent::RingFitterEvent(TTree *tree) : fChain(0)
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   if (tree == 0) {
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("/Users/snoplus/Work/SNO/data/ring-fitter/d2o-leta/richieD2O.root");
      if (!f || !f->IsOpen()) {
         f = new TFile("/Users/snoplus/Work/SNO/data/ring-fitter/d2o-leta/richieD2O.root");
      }
      f->GetObject("Events",tree);

   }
   Init(tree);
}

RingFitterEvent::~RingFitterEvent()
{
   if (!fChain) return;
   //   delete fChain->GetCurrentFile();
}

Int_t RingFitterEvent::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t RingFitterEvent::LoadTree(Long64_t entry)
{
// Set the environment to read one entry
   if (!fChain) return -5;
   Long64_t centry = fChain->LoadTree(entry);
   if (centry < 0) return centry;
   if (fChain->GetTreeNumber() != fCurrent) {
      fCurrent = fChain->GetTreeNumber();
      Notify();
   }
   return centry;
}

void RingFitterEvent::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("fUniqueID", &fUniqueID, &b_prompts_fUniqueID);
   fChain->SetBranchAddress("fBits", &fBits, &b_prompts_fBits);
   fChain->SetBranchAddress("runid", &runid, &b_prompts_runid);
   fChain->SetBranchAddress("gtid", &gtid, &b_prompts_gtid);
   fChain->SetBranchAddress("days", &days, &b_prompts_days);
   fChain->SetBranchAddress("secs", &secs, &b_prompts_secs);
   fChain->SetBranchAddress("nsecs", &nsecs, &b_prompts_nsecs);
   fChain->SetBranchAddress("nhit", &nhit, &b_prompts_nhit);
   fChain->SetBranchAddress("owl", &owl, &b_prompts_owl);
   fChain->SetBranchAddress("neck", &neck, &b_prompts_neck);
   fChain->SetBranchAddress("trigtype", &trigtype, &b_prompts_trigtype);
   fChain->SetBranchAddress("datacleaning", &datacleaning, &b_prompts_datacleaning);
   fChain->SetBranchAddress("datacleaning1", &datacleaning1, &b_prompts_datacleaning1);
   fChain->SetBranchAddress("datacleaning2", &datacleaning2, &b_prompts_datacleaning2);
   fChain->SetBranchAddress("file", &file, &b_prompts_file);
   fChain->SetBranchAddress("qpos.fUniqueID", &qpos_fUniqueID, &b_prompts_qpos_fUniqueID);
   fChain->SetBranchAddress("qpos.fBits", &qpos_fBits, &b_prompts_qpos_fBits);
   fChain->SetBranchAddress("qpos.fX", &qpos_fX, &b_prompts_qpos_fX);
   fChain->SetBranchAddress("qpos.fY", &qpos_fY, &b_prompts_qpos_fY);
   fChain->SetBranchAddress("qpos.fZ", &qpos_fZ, &b_prompts_qpos_fZ);
   fChain->SetBranchAddress("wpos.fUniqueID", &wpos_fUniqueID, &b_prompts_wpos_fUniqueID);
   fChain->SetBranchAddress("wpos.fBits", &wpos_fBits, &b_prompts_wpos_fBits);
   fChain->SetBranchAddress("wpos.fX", &wpos_fX, &b_prompts_wpos_fX);
   fChain->SetBranchAddress("wpos.fY", &wpos_fY, &b_prompts_wpos_fY);
   fChain->SetBranchAddress("wpos.fZ", &wpos_fZ, &b_prompts_wpos_fZ);
   fChain->SetBranchAddress("wdir.fUniqueID", &wdir_fUniqueID, &b_prompts_wdir_fUniqueID);
   fChain->SetBranchAddress("wdir.fBits", &wdir_fBits, &b_prompts_wdir_fBits);
   fChain->SetBranchAddress("wdir.fX", &wdir_fX, &b_prompts_wdir_fX);
   fChain->SetBranchAddress("wdir.fY", &wdir_fY, &b_prompts_wdir_fY);
   fChain->SetBranchAddress("wdir.fZ", &wdir_fZ, &b_prompts_wdir_fZ);
   fChain->SetBranchAddress("itr", &itr, &b_prompts_itr);
   fChain->SetBranchAddress("qpdt", &qpdt, &b_prompts_qpdt);
   fChain->SetBranchAddress("nearly", &nearly, &b_prompts_nearly);
   fChain->SetBranchAddress("totalq", &totalq, &b_prompts_totalq);
   fChain->SetBranchAddress("hough", &hough, &b_prompts_hough);
   fChain->SetBranchAddress("area", &area, &b_prompts_area);
   fChain->SetBranchAddress("avgdensity", &avgdensity, &b_prompts_avgdensity);
   fChain->SetBranchAddress("ringavgdist", &ringavgdist, &b_prompts_ringavgdist);
   fChain->SetBranchAddress("hks", &hks, &b_prompts_hks);
   fChain->SetBranchAddress("hintersect.fUniqueID", &hintersect_fUniqueID, &b_prompts_hintersect_fUniqueID);
   fChain->SetBranchAddress("hintersect.fBits", &hintersect_fBits, &b_prompts_hintersect_fBits);
   fChain->SetBranchAddress("hintersect.fX", &hintersect_fX, &b_prompts_hintersect_fX);
   fChain->SetBranchAddress("hintersect.fY", &hintersect_fY, &b_prompts_hintersect_fY);
   fChain->SetBranchAddress("hintersect.fZ", &hintersect_fZ, &b_prompts_hintersect_fZ);
   fChain->SetBranchAddress("hough2[2]", hough2, &b_prompts_hough2);
   fChain->SetBranchAddress("area2[2]", area2, &b_prompts_area2);
   fChain->SetBranchAddress("avgdensity2[2]", avgdensity2, &b_prompts_avgdensity2);
   fChain->SetBranchAddress("ringavgdist2[2]", ringavgdist2, &b_prompts_ringavgdist2);
   fChain->SetBranchAddress("hks2[2]", hks2, &b_prompts_hks2);
   fChain->SetBranchAddress("hintersect20.fUniqueID", &hintersect20_fUniqueID, &b_prompts_hintersect20_fUniqueID);
   fChain->SetBranchAddress("hintersect20.fBits", &hintersect20_fBits, &b_prompts_hintersect20_fBits);
   fChain->SetBranchAddress("hintersect20.fX", &hintersect20_fX, &b_prompts_hintersect20_fX);
   fChain->SetBranchAddress("hintersect20.fY", &hintersect20_fY, &b_prompts_hintersect20_fY);
   fChain->SetBranchAddress("hintersect20.fZ", &hintersect20_fZ, &b_prompts_hintersect20_fZ);
   fChain->SetBranchAddress("hintersect21.fUniqueID", &hintersect21_fUniqueID, &b_prompts_hintersect21_fUniqueID);
   fChain->SetBranchAddress("hintersect21.fBits", &hintersect21_fBits, &b_prompts_hintersect21_fBits);
   fChain->SetBranchAddress("hintersect21.fX", &hintersect21_fX, &b_prompts_hintersect21_fX);
   fChain->SetBranchAddress("hintersect21.fY", &hintersect21_fY, &b_prompts_hintersect21_fY);
   fChain->SetBranchAddress("hintersect21.fZ", &hintersect21_fZ, &b_prompts_hintersect21_fZ);
   fChain->SetBranchAddress("fit[2]", fit, &b_prompts_fit);
   fChain->SetBranchAddress("pid[2]", pid, &b_prompts_pid);
   fChain->SetBranchAddress("nrings[2]", nrings, &b_prompts_nrings);
   fChain->SetBranchAddress("cpos0.fUniqueID", &cpos0_fUniqueID, &b_prompts_cpos0_fUniqueID);
   fChain->SetBranchAddress("cpos0.fBits", &cpos0_fBits, &b_prompts_cpos0_fBits);
   fChain->SetBranchAddress("cpos0.fX", &cpos0_fX, &b_prompts_cpos0_fX);
   fChain->SetBranchAddress("cpos0.fY", &cpos0_fY, &b_prompts_cpos0_fY);
   fChain->SetBranchAddress("cpos0.fZ", &cpos0_fZ, &b_prompts_cpos0_fZ);
   fChain->SetBranchAddress("cpos1.fUniqueID", &cpos1_fUniqueID, &b_prompts_cpos1_fUniqueID);
   fChain->SetBranchAddress("cpos1.fBits", &cpos1_fBits, &b_prompts_cpos1_fBits);
   fChain->SetBranchAddress("cpos1.fX", &cpos1_fX, &b_prompts_cpos1_fX);
   fChain->SetBranchAddress("cpos1.fY", &cpos1_fY, &b_prompts_cpos1_fY);
   fChain->SetBranchAddress("cpos1.fZ", &cpos1_fZ, &b_prompts_cpos1_fZ);
   fChain->SetBranchAddress("cpos2.fUniqueID", &cpos2_fUniqueID, &b_prompts_cpos2_fUniqueID);
   fChain->SetBranchAddress("cpos2.fBits", &cpos2_fBits, &b_prompts_cpos2_fBits);
   fChain->SetBranchAddress("cpos2.fX", &cpos2_fX, &b_prompts_cpos2_fX);
   fChain->SetBranchAddress("cpos2.fY", &cpos2_fY, &b_prompts_cpos2_fY);
   fChain->SetBranchAddress("cpos2.fZ", &cpos2_fZ, &b_prompts_cpos2_fZ);
   fChain->SetBranchAddress("cpos3.fUniqueID", &cpos3_fUniqueID, &b_prompts_cpos3_fUniqueID);
   fChain->SetBranchAddress("cpos3.fBits", &cpos3_fBits, &b_prompts_cpos3_fBits);
   fChain->SetBranchAddress("cpos3.fX", &cpos3_fX, &b_prompts_cpos3_fX);
   fChain->SetBranchAddress("cpos3.fY", &cpos3_fY, &b_prompts_cpos3_fY);
   fChain->SetBranchAddress("cpos3.fZ", &cpos3_fZ, &b_prompts_cpos3_fZ);
   fChain->SetBranchAddress("cpos4.fUniqueID", &cpos4_fUniqueID, &b_prompts_cpos4_fUniqueID);
   fChain->SetBranchAddress("cpos4.fBits", &cpos4_fBits, &b_prompts_cpos4_fBits);
   fChain->SetBranchAddress("cpos4.fX", &cpos4_fX, &b_prompts_cpos4_fX);
   fChain->SetBranchAddress("cpos4.fY", &cpos4_fY, &b_prompts_cpos4_fY);
   fChain->SetBranchAddress("cpos4.fZ", &cpos4_fZ, &b_prompts_cpos4_fZ);
   fChain->SetBranchAddress("cpos5.fUniqueID", &cpos5_fUniqueID, &b_prompts_cpos5_fUniqueID);
   fChain->SetBranchAddress("cpos5.fBits", &cpos5_fBits, &b_prompts_cpos5_fBits);
   fChain->SetBranchAddress("cpos5.fX", &cpos5_fX, &b_prompts_cpos5_fX);
   fChain->SetBranchAddress("cpos5.fY", &cpos5_fY, &b_prompts_cpos5_fY);
   fChain->SetBranchAddress("cpos5.fZ", &cpos5_fZ, &b_prompts_cpos5_fZ);
   fChain->SetBranchAddress("cdir0.fUniqueID", &cdir0_fUniqueID, &b_prompts_cdir0_fUniqueID);
   fChain->SetBranchAddress("cdir0.fBits", &cdir0_fBits, &b_prompts_cdir0_fBits);
   fChain->SetBranchAddress("cdir0.fX", &cdir0_fX, &b_prompts_cdir0_fX);
   fChain->SetBranchAddress("cdir0.fY", &cdir0_fY, &b_prompts_cdir0_fY);
   fChain->SetBranchAddress("cdir0.fZ", &cdir0_fZ, &b_prompts_cdir0_fZ);
   fChain->SetBranchAddress("cdir1.fUniqueID", &cdir1_fUniqueID, &b_prompts_cdir1_fUniqueID);
   fChain->SetBranchAddress("cdir1.fBits", &cdir1_fBits, &b_prompts_cdir1_fBits);
   fChain->SetBranchAddress("cdir1.fX", &cdir1_fX, &b_prompts_cdir1_fX);
   fChain->SetBranchAddress("cdir1.fY", &cdir1_fY, &b_prompts_cdir1_fY);
   fChain->SetBranchAddress("cdir1.fZ", &cdir1_fZ, &b_prompts_cdir1_fZ);
   fChain->SetBranchAddress("cdir2.fUniqueID", &cdir2_fUniqueID, &b_prompts_cdir2_fUniqueID);
   fChain->SetBranchAddress("cdir2.fBits", &cdir2_fBits, &b_prompts_cdir2_fBits);
   fChain->SetBranchAddress("cdir2.fX", &cdir2_fX, &b_prompts_cdir2_fX);
   fChain->SetBranchAddress("cdir2.fY", &cdir2_fY, &b_prompts_cdir2_fY);
   fChain->SetBranchAddress("cdir2.fZ", &cdir2_fZ, &b_prompts_cdir2_fZ);
   fChain->SetBranchAddress("cdir3.fUniqueID", &cdir3_fUniqueID, &b_prompts_cdir3_fUniqueID);
   fChain->SetBranchAddress("cdir3.fBits", &cdir3_fBits, &b_prompts_cdir3_fBits);
   fChain->SetBranchAddress("cdir3.fX", &cdir3_fX, &b_prompts_cdir3_fX);
   fChain->SetBranchAddress("cdir3.fY", &cdir3_fY, &b_prompts_cdir3_fY);
   fChain->SetBranchAddress("cdir3.fZ", &cdir3_fZ, &b_prompts_cdir3_fZ);
   fChain->SetBranchAddress("cdir4.fUniqueID", &cdir4_fUniqueID, &b_prompts_cdir4_fUniqueID);
   fChain->SetBranchAddress("cdir4.fBits", &cdir4_fBits, &b_prompts_cdir4_fBits);
   fChain->SetBranchAddress("cdir4.fX", &cdir4_fX, &b_prompts_cdir4_fX);
   fChain->SetBranchAddress("cdir4.fY", &cdir4_fY, &b_prompts_cdir4_fY);
   fChain->SetBranchAddress("cdir4.fZ", &cdir4_fZ, &b_prompts_cdir4_fZ);
   fChain->SetBranchAddress("cdir5.fUniqueID", &cdir5_fUniqueID, &b_prompts_cdir5_fUniqueID);
   fChain->SetBranchAddress("cdir5.fBits", &cdir5_fBits, &b_prompts_cdir5_fBits);
   fChain->SetBranchAddress("cdir5.fX", &cdir5_fX, &b_prompts_cdir5_fX);
   fChain->SetBranchAddress("cdir5.fY", &cdir5_fY, &b_prompts_cdir5_fY);
   fChain->SetBranchAddress("cdir5.fZ", &cdir5_fZ, &b_prompts_cdir5_fZ);
   fChain->SetBranchAddress("ctime[4]", ctime, &b_prompts_ctime);
   fChain->SetBranchAddress("cenergy[4]", cenergy, &b_prompts_cenergy);
   fChain->SetBranchAddress("effenergy[4]", effenergy, &b_prompts_effenergy);
   fChain->SetBranchAddress("effenergy2[4]", effenergy2, &b_prompts_effenergy2);
   fChain->SetBranchAddress("energy[3]", energy, &b_prompts_energy);
   fChain->SetBranchAddress("intime[2]", intime, &b_prompts_intime);
   fChain->SetBranchAddress("cintime[4]", cintime, &b_prompts_cintime);
   fChain->SetBranchAddress("totlike[4]", totlike, &b_prompts_totlike);
   fChain->SetBranchAddress("anglike[4]", anglike, &b_prompts_anglike);
   fChain->SetBranchAddress("outside", &outside, &b_prompts_outside);
   fChain->SetBranchAddress("mcpos.fUniqueID", &mcpos_fUniqueID, &b_prompts_mcpos_fUniqueID);
   fChain->SetBranchAddress("mcpos.fBits", &mcpos_fBits, &b_prompts_mcpos_fBits);
   fChain->SetBranchAddress("mcpos.fX", &mcpos_fX, &b_prompts_mcpos_fX);
   fChain->SetBranchAddress("mcpos.fY", &mcpos_fY, &b_prompts_mcpos_fY);
   fChain->SetBranchAddress("mcpos.fZ", &mcpos_fZ, &b_prompts_mcpos_fZ);
   fChain->SetBranchAddress("mcdir.fUniqueID", &mcdir_fUniqueID, &b_prompts_mcdir_fUniqueID);
   fChain->SetBranchAddress("mcdir.fBits", &mcdir_fBits, &b_prompts_mcdir_fBits);
   fChain->SetBranchAddress("mcdir.fX", &mcdir_fX, &b_prompts_mcdir_fX);
   fChain->SetBranchAddress("mcdir.fY", &mcdir_fY, &b_prompts_mcdir_fY);
   fChain->SetBranchAddress("mcdir.fZ", &mcdir_fZ, &b_prompts_mcdir_fZ);
   fChain->SetBranchAddress("mcenergy", &mcenergy, &b_prompts_mcenergy);
   fChain->SetBranchAddress("mctime", &mctime, &b_prompts_mctime);
   fChain->SetBranchAddress("gtrigtime", &gtrigtime, &b_prompts_gtrigtime);
   fChain->SetBranchAddress("mcid", &mcid, &b_prompts_mcid);
   fChain->SetBranchAddress("evi", &evi, &b_prompts_evi);
   fChain->SetBranchAddress("mc", &mc, &b_prompts_mc);
   fChain->SetBranchAddress("interaction", &interaction, &b_prompts_interaction);
   fChain->SetBranchAddress("nutype", &nutype, &b_prompts_nutype);
   fChain->SetBranchAddress("pneutrons", &pneutrons, &b_prompts_pneutrons);
   fChain->SetBranchAddress("tneutrons", &tneutrons, &b_prompts_tneutrons);
   fChain->SetBranchAddress("particles", &particles, &b_prompts_particles);
   fChain->SetBranchAddress("followers", &followers_, &b_prompts_followers_);
   fChain->SetBranchAddress("followers.fUniqueID", followers_fUniqueID, &b_followers_fUniqueID);
   fChain->SetBranchAddress("followers.fBits", followers_fBits, &b_followers_fBits);
   fChain->SetBranchAddress("followers.runid", followers_runid, &b_followers_runid);
   fChain->SetBranchAddress("followers.gtid", followers_gtid, &b_followers_gtid);
   fChain->SetBranchAddress("followers.days", followers_days, &b_followers_days);
   fChain->SetBranchAddress("followers.secs", followers_secs, &b_followers_secs);
   fChain->SetBranchAddress("followers.nsecs", followers_nsecs, &b_followers_nsecs);
   fChain->SetBranchAddress("followers.nhit", followers_nhit, &b_followers_nhit);
   fChain->SetBranchAddress("followers.owl", followers_owl, &b_followers_owl);
   fChain->SetBranchAddress("followers.neck", followers_neck, &b_followers_neck);
   fChain->SetBranchAddress("followers.trigtype", followers_trigtype, &b_followers_trigtype);
   fChain->SetBranchAddress("followers.datacleaning", followers_datacleaning, &b_followers_datacleaning);
   fChain->SetBranchAddress("followers.datacleaning1", followers_datacleaning1, &b_followers_datacleaning1);
   fChain->SetBranchAddress("followers.datacleaning2", followers_datacleaning2, &b_followers_datacleaning2);
   fChain->SetBranchAddress("followers.file", followers_file, &b_followers_file);
   fChain->SetBranchAddress("followers.qpos.fUniqueID", followers_qpos_fUniqueID, &b_followers_qpos_fUniqueID);
   fChain->SetBranchAddress("followers.qpos.fBits", followers_qpos_fBits, &b_followers_qpos_fBits);
   fChain->SetBranchAddress("followers.qpos.fX", followers_qpos_fX, &b_followers_qpos_fX);
   fChain->SetBranchAddress("followers.qpos.fY", followers_qpos_fY, &b_followers_qpos_fY);
   fChain->SetBranchAddress("followers.qpos.fZ", followers_qpos_fZ, &b_followers_qpos_fZ);
   fChain->SetBranchAddress("followers.wpos.fUniqueID", followers_wpos_fUniqueID, &b_followers_wpos_fUniqueID);
   fChain->SetBranchAddress("followers.wpos.fBits", followers_wpos_fBits, &b_followers_wpos_fBits);
   fChain->SetBranchAddress("followers.wpos.fX", followers_wpos_fX, &b_followers_wpos_fX);
   fChain->SetBranchAddress("followers.wpos.fY", followers_wpos_fY, &b_followers_wpos_fY);
   fChain->SetBranchAddress("followers.wpos.fZ", followers_wpos_fZ, &b_followers_wpos_fZ);
   fChain->SetBranchAddress("followers.ftkpos.fX", followers_ftkpos_fX, &b_followers_ftkpos_fX);
   fChain->SetBranchAddress("followers.ftkpos.fY", followers_ftkpos_fY, &b_followers_ftkpos_fY);
   fChain->SetBranchAddress("followers.ftkpos.fZ", followers_ftkpos_fZ, &b_followers_ftkpos_fZ);
   fChain->SetBranchAddress("followers.wdir.fUniqueID", followers_wdir_fUniqueID, &b_followers_wdir_fUniqueID);
   fChain->SetBranchAddress("followers.wdir.fBits", followers_wdir_fBits, &b_followers_wdir_fBits);
   fChain->SetBranchAddress("followers.wdir.fX", followers_wdir_fX, &b_followers_wdir_fX);
   fChain->SetBranchAddress("followers.wdir.fY", followers_wdir_fY, &b_followers_wdir_fY);
   fChain->SetBranchAddress("followers.wdir.fZ", followers_wdir_fZ, &b_followers_wdir_fZ);
   fChain->SetBranchAddress("followers.itr", followers_itr, &b_followers_itr);
   fChain->SetBranchAddress("followers.ftkitr", followers_ftkitr, &b_followers_ftkitr);
   fChain->SetBranchAddress("followers.qpdt", followers_qpdt, &b_followers_qpdt);
   fChain->SetBranchAddress("followers.nearly", followers_nearly, &b_followers_nearly);
   fChain->SetBranchAddress("followers.totalq", followers_totalq, &b_followers_totalq);
   fChain->SetBranchAddress("followers.hough", followers_hough, &b_followers_hough);
   fChain->SetBranchAddress("followers.area", followers_area, &b_followers_area);
   fChain->SetBranchAddress("followers.avgdensity", followers_avgdensity, &b_followers_avgdensity);
   fChain->SetBranchAddress("followers.ringavgdist", followers_ringavgdist, &b_followers_ringavgdist);
   fChain->SetBranchAddress("followers.hks", followers_hks, &b_followers_hks);
   fChain->SetBranchAddress("followers.hintersect.fUniqueID", followers_hintersect_fUniqueID, &b_followers_hintersect_fUniqueID);
   fChain->SetBranchAddress("followers.hintersect.fBits", followers_hintersect_fBits, &b_followers_hintersect_fBits);
   fChain->SetBranchAddress("followers.hintersect.fX", followers_hintersect_fX, &b_followers_hintersect_fX);
   fChain->SetBranchAddress("followers.hintersect.fY", followers_hintersect_fY, &b_followers_hintersect_fY);
   fChain->SetBranchAddress("followers.hintersect.fZ", followers_hintersect_fZ, &b_followers_hintersect_fZ);
   fChain->SetBranchAddress("followers.hough2[2]", followers_hough2, &b_followers_hough2);
   fChain->SetBranchAddress("followers.area2[2]", followers_area2, &b_followers_area2);
   fChain->SetBranchAddress("followers.avgdensity2[2]", followers_avgdensity2, &b_followers_avgdensity2);
   fChain->SetBranchAddress("followers.ringavgdist2[2]", followers_ringavgdist2, &b_followers_ringavgdist2);
   fChain->SetBranchAddress("followers.hks2[2]", followers_hks2, &b_followers_hks2);
   fChain->SetBranchAddress("followers.hintersect20.fUniqueID", followers_hintersect20_fUniqueID, &b_followers_hintersect20_fUniqueID);
   fChain->SetBranchAddress("followers.hintersect20.fBits", followers_hintersect20_fBits, &b_followers_hintersect20_fBits);
   fChain->SetBranchAddress("followers.hintersect20.fX", followers_hintersect20_fX, &b_followers_hintersect20_fX);
   fChain->SetBranchAddress("followers.hintersect20.fY", followers_hintersect20_fY, &b_followers_hintersect20_fY);
   fChain->SetBranchAddress("followers.hintersect20.fZ", followers_hintersect20_fZ, &b_followers_hintersect20_fZ);
   fChain->SetBranchAddress("followers.hintersect21.fUniqueID", followers_hintersect21_fUniqueID, &b_followers_hintersect21_fUniqueID);
   fChain->SetBranchAddress("followers.hintersect21.fBits", followers_hintersect21_fBits, &b_followers_hintersect21_fBits);
   fChain->SetBranchAddress("followers.hintersect21.fX", followers_hintersect21_fX, &b_followers_hintersect21_fX);
   fChain->SetBranchAddress("followers.hintersect21.fY", followers_hintersect21_fY, &b_followers_hintersect21_fY);
   fChain->SetBranchAddress("followers.hintersect21.fZ", followers_hintersect21_fZ, &b_followers_hintersect21_fZ);
   fChain->SetBranchAddress("followers.fit[2]", followers_fit, &b_followers_fit);
   fChain->SetBranchAddress("followers.pid[2]", followers_pid, &b_followers_pid);
   fChain->SetBranchAddress("followers.nrings[2]", followers_nrings, &b_followers_nrings);
   fChain->SetBranchAddress("followers.cpos0.fUniqueID", followers_cpos0_fUniqueID, &b_followers_cpos0_fUniqueID);
   fChain->SetBranchAddress("followers.cpos0.fBits", followers_cpos0_fBits, &b_followers_cpos0_fBits);
   fChain->SetBranchAddress("followers.cpos0.fX", followers_cpos0_fX, &b_followers_cpos0_fX);
   fChain->SetBranchAddress("followers.cpos0.fY", followers_cpos0_fY, &b_followers_cpos0_fY);
   fChain->SetBranchAddress("followers.cpos0.fZ", followers_cpos0_fZ, &b_followers_cpos0_fZ);
   fChain->SetBranchAddress("followers.cpos1.fUniqueID", followers_cpos1_fUniqueID, &b_followers_cpos1_fUniqueID);
   fChain->SetBranchAddress("followers.cpos1.fBits", followers_cpos1_fBits, &b_followers_cpos1_fBits);
   fChain->SetBranchAddress("followers.cpos1.fX", followers_cpos1_fX, &b_followers_cpos1_fX);
   fChain->SetBranchAddress("followers.cpos1.fY", followers_cpos1_fY, &b_followers_cpos1_fY);
   fChain->SetBranchAddress("followers.cpos1.fZ", followers_cpos1_fZ, &b_followers_cpos1_fZ);
   fChain->SetBranchAddress("followers.cpos2.fUniqueID", followers_cpos2_fUniqueID, &b_followers_cpos2_fUniqueID);
   fChain->SetBranchAddress("followers.cpos2.fBits", followers_cpos2_fBits, &b_followers_cpos2_fBits);
   fChain->SetBranchAddress("followers.cpos2.fX", followers_cpos2_fX, &b_followers_cpos2_fX);
   fChain->SetBranchAddress("followers.cpos2.fY", followers_cpos2_fY, &b_followers_cpos2_fY);
   fChain->SetBranchAddress("followers.cpos2.fZ", followers_cpos2_fZ, &b_followers_cpos2_fZ);
   fChain->SetBranchAddress("followers.cpos3.fUniqueID", followers_cpos3_fUniqueID, &b_followers_cpos3_fUniqueID);
   fChain->SetBranchAddress("followers.cpos3.fBits", followers_cpos3_fBits, &b_followers_cpos3_fBits);
   fChain->SetBranchAddress("followers.cpos3.fX", followers_cpos3_fX, &b_followers_cpos3_fX);
   fChain->SetBranchAddress("followers.cpos3.fY", followers_cpos3_fY, &b_followers_cpos3_fY);
   fChain->SetBranchAddress("followers.cpos3.fZ", followers_cpos3_fZ, &b_followers_cpos3_fZ);
   fChain->SetBranchAddress("followers.cpos4.fUniqueID", followers_cpos4_fUniqueID, &b_followers_cpos4_fUniqueID);
   fChain->SetBranchAddress("followers.cpos4.fBits", followers_cpos4_fBits, &b_followers_cpos4_fBits);
   fChain->SetBranchAddress("followers.cpos4.fX", followers_cpos4_fX, &b_followers_cpos4_fX);
   fChain->SetBranchAddress("followers.cpos4.fY", followers_cpos4_fY, &b_followers_cpos4_fY);
   fChain->SetBranchAddress("followers.cpos4.fZ", followers_cpos4_fZ, &b_followers_cpos4_fZ);
   fChain->SetBranchAddress("followers.cpos5.fUniqueID", followers_cpos5_fUniqueID, &b_followers_cpos5_fUniqueID);
   fChain->SetBranchAddress("followers.cpos5.fBits", followers_cpos5_fBits, &b_followers_cpos5_fBits);
   fChain->SetBranchAddress("followers.cpos5.fX", followers_cpos5_fX, &b_followers_cpos5_fX);
   fChain->SetBranchAddress("followers.cpos5.fY", followers_cpos5_fY, &b_followers_cpos5_fY);
   fChain->SetBranchAddress("followers.cpos5.fZ", followers_cpos5_fZ, &b_followers_cpos5_fZ);
   fChain->SetBranchAddress("followers.cdir0.fUniqueID", followers_cdir0_fUniqueID, &b_followers_cdir0_fUniqueID);
   fChain->SetBranchAddress("followers.cdir0.fBits", followers_cdir0_fBits, &b_followers_cdir0_fBits);
   fChain->SetBranchAddress("followers.cdir0.fX", followers_cdir0_fX, &b_followers_cdir0_fX);
   fChain->SetBranchAddress("followers.cdir0.fY", followers_cdir0_fY, &b_followers_cdir0_fY);
   fChain->SetBranchAddress("followers.cdir0.fZ", followers_cdir0_fZ, &b_followers_cdir0_fZ);
   fChain->SetBranchAddress("followers.cdir1.fUniqueID", followers_cdir1_fUniqueID, &b_followers_cdir1_fUniqueID);
   fChain->SetBranchAddress("followers.cdir1.fBits", followers_cdir1_fBits, &b_followers_cdir1_fBits);
   fChain->SetBranchAddress("followers.cdir1.fX", followers_cdir1_fX, &b_followers_cdir1_fX);
   fChain->SetBranchAddress("followers.cdir1.fY", followers_cdir1_fY, &b_followers_cdir1_fY);
   fChain->SetBranchAddress("followers.cdir1.fZ", followers_cdir1_fZ, &b_followers_cdir1_fZ);
   fChain->SetBranchAddress("followers.cdir2.fUniqueID", followers_cdir2_fUniqueID, &b_followers_cdir2_fUniqueID);
   fChain->SetBranchAddress("followers.cdir2.fBits", followers_cdir2_fBits, &b_followers_cdir2_fBits);
   fChain->SetBranchAddress("followers.cdir2.fX", followers_cdir2_fX, &b_followers_cdir2_fX);
   fChain->SetBranchAddress("followers.cdir2.fY", followers_cdir2_fY, &b_followers_cdir2_fY);
   fChain->SetBranchAddress("followers.cdir2.fZ", followers_cdir2_fZ, &b_followers_cdir2_fZ);
   fChain->SetBranchAddress("followers.cdir3.fUniqueID", followers_cdir3_fUniqueID, &b_followers_cdir3_fUniqueID);
   fChain->SetBranchAddress("followers.cdir3.fBits", followers_cdir3_fBits, &b_followers_cdir3_fBits);
   fChain->SetBranchAddress("followers.cdir3.fX", followers_cdir3_fX, &b_followers_cdir3_fX);
   fChain->SetBranchAddress("followers.cdir3.fY", followers_cdir3_fY, &b_followers_cdir3_fY);
   fChain->SetBranchAddress("followers.cdir3.fZ", followers_cdir3_fZ, &b_followers_cdir3_fZ);
   fChain->SetBranchAddress("followers.cdir4.fUniqueID", followers_cdir4_fUniqueID, &b_followers_cdir4_fUniqueID);
   fChain->SetBranchAddress("followers.cdir4.fBits", followers_cdir4_fBits, &b_followers_cdir4_fBits);
   fChain->SetBranchAddress("followers.cdir4.fX", followers_cdir4_fX, &b_followers_cdir4_fX);
   fChain->SetBranchAddress("followers.cdir4.fY", followers_cdir4_fY, &b_followers_cdir4_fY);
   fChain->SetBranchAddress("followers.cdir4.fZ", followers_cdir4_fZ, &b_followers_cdir4_fZ);
   fChain->SetBranchAddress("followers.cdir5.fUniqueID", followers_cdir5_fUniqueID, &b_followers_cdir5_fUniqueID);
   fChain->SetBranchAddress("followers.cdir5.fBits", followers_cdir5_fBits, &b_followers_cdir5_fBits);
   fChain->SetBranchAddress("followers.cdir5.fX", followers_cdir5_fX, &b_followers_cdir5_fX);
   fChain->SetBranchAddress("followers.cdir5.fY", followers_cdir5_fY, &b_followers_cdir5_fY);
   fChain->SetBranchAddress("followers.cdir5.fZ", followers_cdir5_fZ, &b_followers_cdir5_fZ);
   fChain->SetBranchAddress("followers.ctime[4]", followers_ctime, &b_followers_ctime);
   fChain->SetBranchAddress("followers.cenergy[4]", followers_cenergy, &b_followers_cenergy);
   fChain->SetBranchAddress("followers.effenergy[4]", followers_effenergy, &b_followers_effenergy);
   fChain->SetBranchAddress("followers.effenergy2[4]", followers_effenergy2, &b_followers_effenergy2);
   fChain->SetBranchAddress("followers.energy[3]", followers_energy, &b_followers_energy);
   fChain->SetBranchAddress("followers.intime[2]", followers_intime, &b_followers_intime);
   fChain->SetBranchAddress("followers.cintime[4]", followers_cintime, &b_followers_cintime);
   fChain->SetBranchAddress("followers.totlike[4]", followers_totlike, &b_followers_totlike);
   fChain->SetBranchAddress("followers.anglike[4]", followers_anglike, &b_followers_anglike);
   fChain->SetBranchAddress("followers.outside", followers_outside, &b_followers_outside);
   fChain->SetBranchAddress("followers.mcpos.fUniqueID", followers_mcpos_fUniqueID, &b_followers_mcpos_fUniqueID);
   fChain->SetBranchAddress("followers.mcpos.fBits", followers_mcpos_fBits, &b_followers_mcpos_fBits);
   fChain->SetBranchAddress("followers.mcpos.fX", followers_mcpos_fX, &b_followers_mcpos_fX);
   fChain->SetBranchAddress("followers.mcpos.fY", followers_mcpos_fY, &b_followers_mcpos_fY);
   fChain->SetBranchAddress("followers.mcpos.fZ", followers_mcpos_fZ, &b_followers_mcpos_fZ);
   fChain->SetBranchAddress("followers.mcdir.fUniqueID", followers_mcdir_fUniqueID, &b_followers_mcdir_fUniqueID);
   fChain->SetBranchAddress("followers.mcdir.fBits", followers_mcdir_fBits, &b_followers_mcdir_fBits);
   fChain->SetBranchAddress("followers.mcdir.fX", followers_mcdir_fX, &b_followers_mcdir_fX);
   fChain->SetBranchAddress("followers.mcdir.fY", followers_mcdir_fY, &b_followers_mcdir_fY);
   fChain->SetBranchAddress("followers.mcdir.fZ", followers_mcdir_fZ, &b_followers_mcdir_fZ);
   fChain->SetBranchAddress("followers.mcenergy", followers_mcenergy, &b_followers_mcenergy);
   fChain->SetBranchAddress("followers.mctime", followers_mctime, &b_followers_mctime);
   fChain->SetBranchAddress("followers.gtrigtime", followers_gtrigtime, &b_followers_gtrigtime);
   fChain->SetBranchAddress("followers.mcid", followers_mcid, &b_followers_mcid);
   fChain->SetBranchAddress("followers.evi", followers_evi, &b_followers_evi);
   fChain->SetBranchAddress("followers.mc", followers_mc, &b_followers_mc);
   fChain->SetBranchAddress("followers.deltat", followers_deltat, &b_followers_deltat);
   fChain->SetBranchAddress("reweight_up", &reweight_up, &b_prompts_reweight_up);
   fChain->SetBranchAddress("reweight_down", &reweight_down, &b_prompts_reweight_down);
   Notify();
}

Bool_t RingFitterEvent::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void RingFitterEvent::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t RingFitterEvent::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
#endif // #ifdef RingFitterEvent_cxx

