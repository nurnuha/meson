
#include "iostream"
#include <TROOT.h>
#include <TSystem.h>
#include <TROOT.h>
#include <TH1.h>

#include <TCanvas.h>
#include <TChain.h>
#include <TMath.h>
#include <TChain.h>
#include "stdlib.h"
#include <TH1F.h>
#include <TH2F.h>
#include <TFile.h>
#include <TNtuple.h>
#include <TF1.h>
#include <TVector3.h>
#include<math.h>
#include <string.h>
#include <TTree.h>
#include <TLorentzVector.h>

#define CAL_VAR 1.00

using namespace std;

Double_t q(Double_t a){
return a*a;
}
Double_t s(Double_t a){
return sqrt(a);
}

int main(int argc, char** argv){
Char_t outfile[1024]="ing_yang_hren.root";
//Char_t infile[1024]="zeus://acs/z/ntup/05/v02d/data/root/data_05_52258_52259_01.root";
//Char_t infile[1024]="zeus://acs/z/ntup/06p/v02d/data/root/data_06p_61456_61456_01.root";
//Char_t infile[1024]="zeus://acs/z/ntup/06e/v02d/data/root/data_06e_*";
//Char_t infile[1024]="zeusmc.hduwe25.f15892.py6156k.cc.ct46gr03.da104.root";
//Char_t infile[1024]="zeusmc.hduwe25.f15892.py6156k.cc.ct46gr03.da104.root";
Char_t infile[1024]="/pnfs/desy.de/dphep/online/zeus/z/ntup/06p/v08b/data/root/data_06p_61452_61452_01.root";

Int_t i;
Double_t w=1;
Int_t b=0;
for(i=1; i<argc; i++) {
	if(argv[i][0]=='-') {
		if(argc==i+1) {
			cerr << "To few arguments!"<<endl;

			return -1;
		}
		if(argv[i][1]=='o') {
			memset(outfile,0,1024);
			strncpy(outfile,argv[i+1],1024);
			i++;
		}
		else if(argv[i][1]=='i'){
			memset(infile,0,1024);
			strncpy(infile,argv[i+1],1024);
			i++; 
		}
		else if(argv[i][1]=='w'){
			sscanf(argv[i+1],"%le",&w);
			i++; 
		}
		else if(argv[i][1]=='b'){
			sscanf(argv[i+1],"%d",&b);
			i++; 
		}
		else {
			cerr<<"Ignoring wrong argument "<<argv[i]<<endl; 
		}
	}
	else {
		cerr << "Ignoring wrong argument "<<argv[i]<<endl;
	}
}
cout << "Weight: " << w << endl;
cout<<"Out!!!!!!!!!!!!!!!!!!!!!!!:      " << outfile << endl;

TChain * ntD=new TChain("orange");
// ntD->Add("zeus://acs/z/ntup/07p/v02e/mc/root/zeusmc.xfsy627.f15892.py6156k.cg.ct46gr03.da080.root");
// ntD->Add("zeus://acs/z/ntup/07p/v02e/mc/root/zeusmc.xfsy627.f15892.py6156k.cg.ct46gr03.da081.root");
// ntD->Add("zeus://acs/z/ntup/07p/v02e/mc/root/zeusmc.xfsy627.f15892.py6156k.cg.ct46gr03.da083.root");
// ntD->Add("zeus://acs/z/ntup/07p/v02e/mc/root/zeusmc.xfsz627.f15892.py6156k.cg.ct46gr03.da093.root");
// ntD->Add("zeus://acs/z/ntup/07p/v02e/mc/root/zeusmc.afsy627.f15892.py6156k.cc.ct46gr03.da003.root");
// ntD->Add("zeus://acs/z/ntup/07p/v02e/mc/root/zeusmc.afsy627.f15892.py6156k.cc.ct46gr03.da007.root");
// ntD->Add("zeus://acs/z/ntup/07p/v02e/mc/root/zeusmc.afsy627.f15892.py6156k.cc.ct46gr03.da013.root");
// ntD->Add("zeus://acs/z/ntup/07p/v02e/mc/root/zeusmc.afsz627.f15892.py6156k.cc.ct46gr03.da086.root");
/// Inclusiv MC
// ntD->Add("zeus://acs/z/ntup/07p/v02e/mc/root/zeusmc.hfsz627.f15125.inc.pyth.ccexp.103.root");
// ntD->Add("zeus://acs/z/ntup/07p/v02e/mc/root/zeusmc.hfsz627.f15125.inc.pyth.ccexp.104.root");
// ntD->Add("zeus://acs/z/ntup/07p/v02e/mc/root/zeusmc.hfsz627.f15125.inc.pyth.ccexp.105.root");
// ntD->Add("zeus://acs/z/ntup/07p/v02e/mc/root/zeusmc.hfsz627.f15125.inc.pyth.ccexp.108.root");
// ntD->Add("zeus://acs/z/ntup/07p/v02e/mc/root/zeusmc.hfsz627.f15125.inc.pyth.ccexp.109.root");
// ntD->Add("zeus://acs/z/ntup/07p/v02e/mc/root/zeusmc.hfsz627.f15125.inc.pyth.ccexp.110.root");
// ntD->Add("zeus://acs/z/ntup/07p/v02e/mc/root/zeusmc.hfsz627.f15125.inc.pyth.ccexp.111.root");
// ntD->Add("zeus://acs/z/ntup/07p/v02e/mc/root/zeusmc.hfsz627.f15125.inc.pyth.ccexp.112.root");
// ntD->Add("zeus://acs/z/ntup/07p/v02e/mc/root/zeusmc.hfsz627.f15125.inc.pyth.ccexp.113.root");
// ntD->Add("zeus://acs/z/ntup/07p/v02e/mc/root/zeusmc.hfsz627.f15125.inc.pyth.ccexp.114.root");
// ntD->Add("zeus://acs/z/ntup/07p/v02e/mc/root/zeusmc.hfsz627.f15125.inc.pyth.ccexp.115.root");
// ntD->Add("zeus://acs/z/ntup/07p/v02e/mc/root/zeusmc.hfsz627.f15125.inc.pyth.ccexp.116.root");
// ntD->Add("zeus://acs/z/ntup/07p/v02e/mc/root/zeusmc.hfsz627.f15125.inc.pyth.ccexp.117.root");
// ntD->Add("zeus://acs/z/ntup/07p/v02e/mc/root/zeusmc.hfsz627.f15125.inc.pyth.ccexp.120.root");
ntD->Add(infile);
Int_t nevents = ntD->GetEntries();

/// ////////////////....................Branch declare.................///////////////////////////////////

ntD->SetBranchStatus("*",0);



///.................Event................................
Int_t Runnr;
	ntD->SetBranchStatus("Runnr",1);
	ntD->SetBranchAddress("Runnr", &Runnr);

///.................Trigger................................
Int_t           Tltw[15];
ntD->SetBranchStatus("Tltw",1);
ntD->SetBranchAddress("Tltw", Tltw);

///.................Vertex...................................
   Float_t         Zvtx;
   Float_t         Chivtx;
   ntD->SetBranchStatus("Zvtx",1);
   ntD->SetBranchStatus("Chivtx",1);
   ntD->SetBranchAddress("Zvtx", &Zvtx);
   ntD->SetBranchAddress("Chivtx", &Chivtx);

///.................SIRA...................................
   Int_t           Sincand;
   ntD->SetBranchStatus("Sincand",1);
   ntD->SetBranchAddress("Sincand", &Sincand);
   Int_t           Sierror;
   ntD->SetBranchStatus("Sierror",1);
   ntD->SetBranchAddress("Sierror", &Sierror);
   Float_t         Siprob[4];   //[SiNcand]
   ntD->SetBranchStatus("Siprob", 1);
   ntD->SetBranchAddress("Siprob", Siprob);
   Float_t         Sicalene[4];   //[SiNcand]
   ntD->SetBranchStatus("Sicalene", 1);
   ntD->SetBranchAddress("Sicalene", Sicalene);

///.................ZUFOS...................................
   Float_t         V_h_pz_zu;
   Float_t         V_h_e_zu;
   ntD->SetBranchStatus("V_h_pz_zu",1);
   ntD->SetBranchStatus("V_h_e_zu",1);
   ntD->SetBranchAddress("V_h_pz_zu", &V_h_pz_zu);
   ntD->SetBranchAddress("V_h_e_zu", &V_h_e_zu);

///.................Trk_vtx...................................
   Int_t           Trk_vtx[2800];   //[trk_ntracks]
   Int_t           Trk_prim_vtx[2800];   //[trk_ntracks]
   Int_t           Trk_sec_vtx[2800];   //[trk_ntracks]
   Int_t           Trk_vxid[2800];   //[trk_ntracks]
   ntD->SetBranchStatus("Trk_vtx",0);
   ntD->SetBranchStatus("Trk_prim_vtx",0);
   ntD->SetBranchStatus("Trk_sec_vtx",0);
   ntD->SetBranchStatus("Trk_vxid",0);
   ntD->SetBranchAddress("Trk_vtx", Trk_vtx);
   ntD->SetBranchAddress("Trk_prim_vtx", Trk_prim_vtx);
   ntD->SetBranchAddress("Trk_sec_vtx", Trk_sec_vtx);
   ntD->SetBranchAddress("Trk_vxid", Trk_vxid);

///.................Trk_qual...................................
   Float_t         Trk_charge[2800];   //[trk_ntracks]
   ntD->SetBranchStatus("Trk_charge",1);
   ntD->SetBranchAddress("Trk_charge", Trk_charge);

   Int_t           Trk_layinner[2800];   //[trk_ntracks]
   Int_t           Trk_layouter[2800];
   ntD->SetBranchStatus("Trk_layinner",1);
   ntD->SetBranchStatus("Trk_layouter",1);
   ntD->SetBranchAddress("Trk_layinner", Trk_layinner);
   ntD->SetBranchAddress("Trk_layouter", Trk_layouter);
   Float_t  Trk_dedxctd[2800];
   ntD->SetBranchStatus("Trk_dedxctd", 1);
   ntD->SetBranchAddress("Trk_dedxctd", Trk_dedxctd);
   Float_t  Trk_dedxctdcr[2800];
   ntD->SetBranchStatus("Trk_dedxctdcr", 0);
   ntD->SetBranchAddress("Trk_dedxctdcr", Trk_dedxctdcr);
   Int_t  Trk_dedxctderr[2800];
   ntD->SetBranchStatus("Trk_dedxctderr", 0);
   ntD->SetBranchAddress("Trk_dedxctderr", Trk_dedxctderr);
   Int_t  Trk_dedxctdnh[2800];
   ntD->SetBranchStatus("Trk_dedxctdnh", 0);
   ntD->SetBranchAddress("Trk_dedxctdnh", Trk_dedxctdnh);

///.................Trk_MVD...................................
   Int_t           Trk_nbr[2800];   //[trk_ntracks]
   Int_t           Trk_nbz[2800];   //[trk_ntracks]
   Float_t         Trk_dedxmvd[1200];   //[trk_ntracks]
   ntD->SetBranchStatus("Trk_nbr",1);
   ntD->SetBranchStatus("Trk_nbz",1);
   ntD->SetBranchStatus("Trk_dedxmvd",1);
   ntD->SetBranchAddress("Trk_nbr", Trk_nbr);
   ntD->SetBranchAddress("Trk_nbz", Trk_nbz);
   ntD->SetBranchAddress("Trk_dedxmvd",Trk_dedxmvd);

///.................CHARMVTX.................................
   Int_t           Nchvtx;
   Float_t         Chvtxpar[1000][3];   //[nchvtx]
   Float_t         Chvtxcov[1000][6];   //[nchvtx]
   Float_t         Chchi2[1000];   //[nchvtx]
   ntD->SetBranchStatus("Nchvtx",1);
   ntD->SetBranchStatus("Chvtxpar",1);
   ntD->SetBranchStatus("Chvtxcov",1);
   ntD->SetBranchStatus("Chchi2",1);
   ntD->SetBranchAddress("Nchvtx", &Nchvtx);
   ntD->SetBranchAddress("Chvtxpar", Chvtxpar);
   ntD->SetBranchAddress("Chvtxcov", Chvtxcov);
   ntD->SetBranchAddress("Chchi2", Chchi2);

///.................DSSSH.................................
   Int_t           Nchdss;
   Float_t         Dssms[50];   //[Nchdss]
   Float_t         Dsspm[50];   //[Nchdss]
   Float_t         Dssth[50];   //[Nchdss]
   Float_t         Dssph[50];   //[Nchdss]
   Float_t         Dsphms[50];   //[Nchdss]
   Float_t         Dsphpm[50];   //[Nchdss]
   Float_t         Dsphth[50];   //[Nchdss]
   Float_t         Dsphph[50];   //[Nchdss]
   Float_t         Dsk1pm[50];   //[Nchdss]
   Float_t         Dsk1th[50];   //[Nchdss]
   Float_t         Dsk1ph[50];   //[Nchdss]
   Float_t         Dsk2pm[50];   //[Nchdss]
   Float_t         Dsk2th[50];   //[Nchdss]
   Float_t         Dsk2ph[50];   //[Nchdss]
   Float_t         Dspipm[50];   //[Nchdss]
   Float_t         Dspith[50];   //[Nchdss]
   Float_t         Dspiph[50];   //[Nchdss]
   ntD->SetBranchStatus("Nchdss", 1);
   ntD->SetBranchStatus("Dssms",  1);
   ntD->SetBranchStatus("Dsspm",  1);
   ntD->SetBranchStatus("Dssth",  1);
   ntD->SetBranchStatus("Dssph",  1);
   ntD->SetBranchStatus("Dsphms", 1);
   ntD->SetBranchStatus("Dsphpm", 1);
   ntD->SetBranchStatus("Dsphth", 1);
   ntD->SetBranchStatus("Dsphph", 1);
   ntD->SetBranchStatus("Dsk1pm", 1);
   ntD->SetBranchStatus("Dsk1th", 1);
   ntD->SetBranchStatus("Dsk1ph", 1);
   ntD->SetBranchStatus("Dsk2pm", 1);
   ntD->SetBranchStatus("Dsk2th", 1);
   ntD->SetBranchStatus("Dsk2ph", 1);
   ntD->SetBranchStatus("Dspipm", 1);
   ntD->SetBranchStatus("Dspith", 1);
   ntD->SetBranchStatus("Dspiph", 1);
   ntD->SetBranchAddress("Nchdss", &Nchdss);
   ntD->SetBranchAddress("Dssms", Dssms);
   ntD->SetBranchAddress("Dsspm", Dsspm);
   ntD->SetBranchAddress("Dssth", Dssth);
   ntD->SetBranchAddress("Dssph", Dssph);
   ntD->SetBranchAddress("Dsphms", Dsphms);
   ntD->SetBranchAddress("Dsphpm", Dsphpm);
   ntD->SetBranchAddress("Dsphth", Dsphth);
   ntD->SetBranchAddress("Dsphph", Dsphph);
   ntD->SetBranchAddress("Dsk1pm", Dsk1pm);
   ntD->SetBranchAddress("Dsk1th", Dsk1th);
   ntD->SetBranchAddress("Dsk1ph", Dsk1ph);
   ntD->SetBranchAddress("Dsk2pm", Dsk2pm);
   ntD->SetBranchAddress("Dsk2th", Dsk2th);
   ntD->SetBranchAddress("Dsk2ph", Dsk2ph);
   ntD->SetBranchAddress("Dspipm", Dspipm);
   ntD->SetBranchAddress("Dspith", Dspith);
   ntD->SetBranchAddress("Dspiph", Dspiph);

///.................DSSSH_RV.................................
   Int_t           Dsstrk[50];   //[Nchdss]
   Int_t           Tdssk1[50];   //[Nchdss]
   Int_t           Tdssk2[50];   //[Nchdss]
   Int_t           Tdsspi[50];   //[Nchdss]
   Int_t           Idssvtx[50];   //[Nchdss]
   Int_t           Idssrprm[50];   //[Nchdss]
   ntD->SetBranchStatus("Dsstrk", 1);
   ntD->SetBranchStatus("Tdssk1", 1);
   ntD->SetBranchStatus("Tdssk2", 1);
   ntD->SetBranchStatus("Tdsspi", 1);
   ntD->SetBranchStatus("Idssvtx", 1);
   ntD->SetBranchStatus("Idssrprm", 1);
   ntD->SetBranchAddress("Dsstrk", Dsstrk);
   ntD->SetBranchAddress("Tdssk1", Tdssk1);
   ntD->SetBranchAddress("Tdssk2", Tdssk2);
   ntD->SetBranchAddress("Tdsspi", Tdsspi);
   ntD->SetBranchAddress("Idssvtx", Idssvtx);
   ntD->SetBranchAddress("Idssrprm", Idssrprm);

///.................Cal .................................

   Float_t         Cal_et10;
   ntD->SetBranchStatus("Cal_et10", 1);
   ntD->SetBranchAddress("Cal_et10", &Cal_et10);
   Float_t         Cal_et;
   ntD->SetBranchStatus("Cal_et", 1);
   ntD->SetBranchAddress("Cal_et", &Cal_et);
   /*
///..................TrkMcMat............................. Richard
   Int_t           Mcmatquality[4000];   //[trk_ntracks]
   Int_t           Mcmattype[4000];   //[trk_ntracks]
   Float_t         Mcmatmother_prt[4000];   //[trk_ntracks]   
   Int_t         Mcmatmother[4000];
   Int_t         Mcmatfmckin_id[4000];
   ntD->SetBranchStatus("Mcmatquality",1);
   ntD->SetBranchStatus("Mcmattype", 1);
   ntD->SetBranchStatus("Mcmatmother_prt", 1);
   ntD->SetBranchStatus("Mcmatmother", 1);
   ntD->SetBranchStatus("Mcmatfmckin_id",1);
   ntD->SetBranchAddress("Mcmatquality", Mcmatquality);
   ntD->SetBranchAddress("Mcmattype", Mcmattype);
   ntD->SetBranchAddress("Mcmatmother_prt", Mcmatmother_prt);
   ntD->SetBranchAddress("Mcmatmother", Mcmatmother);
   ntD->SetBranchAddress("Mcmatfmckin_id",Mcmatfmckin_id);
*/
   /*
///....................FMCK...............................
   Int_t           Fmck_nstor;
   Int_t           Fmck_id[400];   //[fmck_nstor]
   Float_t         Fmck_px[400];   //[fmck_nstor]
   Float_t         Fmck_py[400];   //[fmck_nstor]
   Float_t         Fmck_pz[400];   //[fmck_nstor]
   Float_t         Fmck_e[400];   //[fmck_nstor]
   Float_t         Fmck_m[400];   //[fmck_nstor]
   Float_t         Fmck_w;
   Int_t           Fmck_isthep[400];   //[fmck_nstor]
   Int_t           Fmck_daug[400];   //[fmck_nstor]
   Int_t           Fmck_daug2[400];   //[fmck_nstor]
   Int_t           Fmck_prt[400];   //[fmck_nstor]
   Int_t           Fmck_prat[400];   //[fmck_nstor]
   ntD->SetBranchStatus("Fmck_nstor",1);
   ntD->SetBranchStatus("Fmck_id",1);
   ntD->SetBranchStatus("Fmck_px",1);
   ntD->SetBranchStatus("Fmck_py",1);
   ntD->SetBranchStatus("Fmck_pz",1);
   ntD->SetBranchStatus("Fmck_e",1);
   ntD->SetBranchStatus("Fmck_m",1);
   ntD->SetBranchStatus("Fmck_w",1);
   ntD->SetBranchStatus("Fmck_isthep",1);
   ntD->SetBranchStatus("Fmck_daug",1);
   ntD->SetBranchStatus("Fmck_daug2",1);
   ntD->SetBranchStatus("Fmck_prt",1);
   ntD->SetBranchStatus("Fmck_prat",1);  
   ntD->SetBranchAddress("Fmck_nstor", &Fmck_nstor);
   ntD->SetBranchAddress("Fmck_id", Fmck_id);
   ntD->SetBranchAddress("Fmck_px", Fmck_px);
   ntD->SetBranchAddress("Fmck_py", Fmck_py);
   ntD->SetBranchAddress("Fmck_pz", Fmck_pz);
   ntD->SetBranchAddress("Fmck_e", Fmck_e);
   ntD->SetBranchAddress("Fmck_m", Fmck_m);
   ntD->SetBranchAddress("Fmck_w", &Fmck_w);
   ntD->SetBranchAddress("Fmck_isthep", Fmck_isthep);
   ntD->SetBranchAddress("Fmck_daug", Fmck_daug);
   ntD->SetBranchAddress("Fmck_daug2", Fmck_daug2);
   ntD->SetBranchAddress("Fmck_prt", Fmck_prt);
   ntD->SetBranchAddress("Fmck_prat", Fmck_prat);
*/

  /// Bspt  ///

   Float_t         Bspt_x;
   Float_t         Bspt_y;
   Float_t         Bspt_z;
   Float_t         Bspt_xer;
   Float_t         Bspt_yer;
   Float_t         Bspt_zer;
   Float_t         Bspt_dxdz;
   Float_t         Bspt_dydz;
   Float_t         Bspt_dxdzer;
   Float_t         Bspt_dydzer;

   ntD->SetBranchStatus("Bspt_x", 1);
   ntD->SetBranchStatus("Bspt_y", 1);
   ntD->SetBranchStatus("Bspt_z", 1);
   ntD->SetBranchStatus("Bspt_xer", 1);
   ntD->SetBranchStatus("Bspt_yer", 1);
   ntD->SetBranchStatus("Bspt_zer", 1);
   ntD->SetBranchStatus("Bspt_dxdz", 1);
   ntD->SetBranchStatus("Bspt_dydz", 1);
   ntD->SetBranchStatus("Bspt_dxdzer", 1);
   ntD->SetBranchStatus("Bspt_dydzer", 1);

   ntD->SetBranchAddress("Bspt_x", &Bspt_x);
   ntD->SetBranchAddress("Bspt_y", &Bspt_y);
   ntD->SetBranchAddress("Bspt_z", &Bspt_z);
   ntD->SetBranchAddress("Bspt_xer", &Bspt_xer);
   ntD->SetBranchAddress("Bspt_yer", &Bspt_yer);
   ntD->SetBranchAddress("Bspt_zer", &Bspt_zer);
   ntD->SetBranchAddress("Bspt_dxdz", &Bspt_dxdz);
   ntD->SetBranchAddress("Bspt_dydz", &Bspt_dydz);
   ntD->SetBranchAddress("Bspt_dxdzer", &Bspt_dxdzer);
   ntD->SetBranchAddress("Bspt_dydzer", &Bspt_dydzer);

///   ........    ////

///   ........    ////
 Int_t         Simrun;
   ntD->SetBranchStatus("Simrun", 1);
   ntD->SetBranchAddress("Simrun", &Simrun);


/// deklare ///
const Float_t mass_pion=0.139570;
const Float_t mass_kaon=0.493677;
const Float_t mass_dplus=1.8696;
const Float_t mass_dsubs=1.96847;
const Float_t mass_proton=0.93827;
Float_t S1,S2,S3,S;
TLorentzVector PK1,PK2,PPi,PK1K2,PK1Pi,PK2Pi;

Float_t pxK1,pyK1,pzK1,pxK2,pyK2,pzK2,pxPi,pyPi,pzPi;

Float_t W;

Int_t HFL01,HFL05,HFL21,HFL22;

Int_t HFM01,HFM02,HFM03,HFM04,HFM05,HFM06,HFM07,HFM08,HFM09,HFM10,HFM11,HFM12,HFM13,HFM14,HFM15,HFM16,HFM17,HFM18,HFM19,HFM20,HFM21,HFM22,HFM23,HFM24,HFM25,HFM26,HFM27,HFM28,HFM29,HFM30,HFM31,HFM32;


Float_t mass[1000],massPhi[1000],ptK1[1000],ptK2[1000],ptPi[1000],etaK1[1000],etaK2[1000],etaPi[1000],etaD[1000],ptD[1000],louinK1[1000],louinK2[1000],louinPi[1000],chi2[1000],ptD_Et10[1000],cosP[1000],cosK[1000],signif_pt[1000],Lxy[1000],err_Lxy[1000],z[1000],w_cand[1000],chKa[1000];

/*
Float_t pD[1000],pKa[1000],pp1[1000],dedxKa[1000],dedxp1[1000],dedxp2[1000],nrKa[1000],nrp1[1000],nrp2[1000],nzKa[1000],nzp1[1000],nzp2[1000],G_res[1000],ptK_rel[1000],z[1000],MKapi[1000],mvdKa[1000],mvdp1[1000],mvdp2[1000];
*/
Float_t covxy,dlx,covxx,dly,covyy;
TVector3 v_dl,v_pD;

TVector3 vD,vP,vPfD,vK,vKD,vDD,vKfD,v_work;
TVector3 vKK,vPfKK,vKfKK;
Float_t Ek,Ep,Ed,Ekk;

TNtuple *dsubs = new TNtuple("dsubs","dsubs","");


///##################################### start LOOP #################################
Int_t nEvt;
Bool_t EventRejected = kFALSE;
Bool_t CandidateRejected = kFALSE;

Int_t cutSira=0;

const Int_t OffZvtx=0;
const Int_t OffSira=0;
const Int_t Offchi2=0;
const Int_t OffW=0;
const Int_t Offlouin=0;
const Int_t Offsignif_pt=0;

const Int_t OffmassPhi=0;

const Int_t OffptD=0;
const Int_t OffetaD=0;

const Int_t OffptK1=0;
const Int_t OffptK2=0;
const Int_t OffptPi=0;

const Int_t OffetaK1=0;
const Int_t OffetaK2=0;
const Int_t OffetaPi=0;

const Int_t OffptD_Et10=0;
const Int_t OffHFL=0;

const Int_t OffcosP=1;
const Int_t OffcosK=1;


Int_t ff,ss,tt; 
Int_t flag=0;

dsubs->Branch("beauty", &b, "beauty/I");
dsubs->Branch("Zvtx", &Zvtx, "Zvtx/F");
dsubs->Branch("W", &W, "W/F");
dsubs->Branch("Ngoodcand", &flag, "Ngoodcand/I");
dsubs->Branch("w_cand", w_cand, "w_cand/F");
dsubs->Branch("mass", mass, "mass[Ngoodcand]/F");
dsubs->Branch("chKa", chKa, "chKa[Ngoodcand]/F");
dsubs->Branch("massPhi", massPhi, "massPhi[Ngoodcand]/F");
dsubs->Branch("ptK1", ptK1, "ptK1[Ngoodcand]/F");
dsubs->Branch("ptK2", ptK2, "ptK2[Ngoodcand]/F");
dsubs->Branch("ptPi", ptPi, "ptPi[Ngoodcand]/F");
dsubs->Branch("etaK1", etaK1, "etaK1[Ngoodcand]/F");
dsubs->Branch("etaK2", etaK2, "etaK2[Ngoodcand]/F");
dsubs->Branch("etaPi", etaPi, "etaPi[Ngoodcand]/F");
dsubs->Branch("ptD", ptD, "ptD[Ngoodcand]/F");
dsubs->Branch("etaD", etaD, "etaD[Ngoodcand]/F");
dsubs->Branch("chi2", chi2, "chi2[Ngoodcand]/F");
dsubs->Branch("ptD_Et10", ptD_Et10, "ptD_Et10[Ngoodcand]/F");
dsubs->Branch("signif_pt", signif_pt, "signif_pt[Ngoodcand]/F");
dsubs->Branch("z", z, "z[Ngoodcand]/F");

dsubs->Branch("HFL01", &HFL01, "HFL01/I");
dsubs->Branch("HFL05", &HFL05, "HFL05/I");
dsubs->Branch("HFL21", &HFL21, "HFL21/I");

dsubs->Branch("HFM01", &HFM01, "HFM01/I");
dsubs->Branch("HFM02", &HFM02, "HFM02/I");
dsubs->Branch("HFM03", &HFM03, "HFM03/I");
dsubs->Branch("HFM04", &HFM04, "HFM04/I");
dsubs->Branch("HFM05", &HFM05, "HFM05/I");
dsubs->Branch("HFM06", &HFM06, "HFM06/I");
dsubs->Branch("HFM07", &HFM07, "HFM07/I");
dsubs->Branch("HFM08", &HFM08, "HFM08/I");
dsubs->Branch("HFM09", &HFM09, "HFM09/I");
dsubs->Branch("HFM10", &HFM10, "HFM10/I");
dsubs->Branch("HFM11", &HFM11, "HFM11/I");
dsubs->Branch("HFM12", &HFM12, "HFM12/I");
dsubs->Branch("HFM13", &HFM13, "HFM13/I");
dsubs->Branch("HFM14", &HFM14, "HFM14/I");
dsubs->Branch("HFM15", &HFM15, "HFM15/I");
dsubs->Branch("HFM16", &HFM16, "HFM16/I");
dsubs->Branch("HFM17", &HFM17, "HFM17/I");
dsubs->Branch("HFM18", &HFM18, "HFM18/I");
dsubs->Branch("HFM19", &HFM19, "HFM19/I");
dsubs->Branch("HFM20", &HFM20, "HFM20/I");
dsubs->Branch("HFM21", &HFM21, "HFM21/I");
dsubs->Branch("HFM22", &HFM22, "HFM22/I");
dsubs->Branch("HFM23", &HFM23, "HFM23/I");
dsubs->Branch("HFM24", &HFM24, "HFM24/I");
dsubs->Branch("HFM25", &HFM25, "HFM25/I");
dsubs->Branch("HFM26", &HFM26, "HFM26/I");
dsubs->Branch("HFM27", &HFM27, "HFM27/I");
dsubs->Branch("HFM28", &HFM28, "HFM28/I");
dsubs->Branch("HFM29", &HFM29, "HFM29/I");
dsubs->Branch("HFM30", &HFM30, "HFM30/I");
dsubs->Branch("HFM31", &HFM31, "HFM31/I");
dsubs->Branch("HFM32", &HFM32, "HFM32/I");

Float_t decays[1000],m[1000],m11[1000],MATCH[1000],autoMATCH[1000],dellta[1000];
dsubs->Branch("decays", decays, "decays[Ngoodcand]/F");
dsubs->Branch("m", m, "m[Ngoodcand]/F");
dsubs->Branch("m11", m11, "m11[Ngoodcand]/F");
dsubs->Branch("MATCH", MATCH, "MATCH[Ngoodcand]/F");
dsubs->Branch("autoMATCH", autoMATCH, "autoMATCH[Ngoodcand]/F");
dsubs->Branch("dellta", dellta, "dellta[Ngoodcand]/F");

Float_t dLc[1000],dDp[1000];
dsubs->Branch("dLc", dLc, "dLc[Ngoodcand]/F");
dsubs->Branch("dDp", dDp, "dDp[Ngoodcand]/F");

Int_t nM[1000];
dsubs->Branch("nM", nM, "nM[Ngoodcand]/I");

Int_t sign_bug[1000];
dsubs->Branch("sign_bug",sign_bug,"sign_bug[Ngoodcand]/I");

Float_t dlen[1000];
dsubs->Branch("dlen",dlen,"dlen[Ngoodcand]/F");


		for(nEvt=0; nEvt<nevents; nEvt++)
			{
				ntD->GetEntry(nEvt);

				if ((fabs(Zvtx)<30.0 && ( Chivtx >0.0)) || OffZvtx) {}
				else continue;

				if(!(Sierror == 0)){continue;}
				cutSira=0;
				for(Int_t ee=0;ee<Sincand;ee++)
					{
						if(Siprob[ee]>0.9&&Sicalene[ee]>5)cutSira=1;
						
					}
				if (!((cutSira == 0) || OffSira)) {continue;}

				W = pow((2*920*(V_h_e_zu-V_h_pz_zu)*CAL_VAR),0.5);
				
				if ((W>130 && W<300) || OffW) {}
    				else continue;

				HFM01=(Tltw[8]&1)/1;
				HFM02=(Tltw[8]&2)/2;
				HFM03=(Tltw[8]&4)/4;
				HFM04=(Tltw[8]&8)/8;
				HFM05=(Tltw[8]&16)/16;
				HFM06=(Tltw[8]&32)/32;
				HFM07=(Tltw[8]&64)/64;
				HFM08=(Tltw[8]&128)/128;
				HFM09=(Tltw[8]&256)/256;
				HFM10=(Tltw[8]&512)/512;
				HFM11=(Tltw[8]&1024)/1024;
				HFM12=(Tltw[8]&2048)/2048;
				HFM13=(Tltw[8]&4096)/4096;
				HFM14=(Tltw[8]&8192)/8192;
				HFM15=(Tltw[8]&16384)/16384;
				HFM16=(Tltw[8]&32768)/32768;
				
				HFM17=(Tltw[14]&1)/1;
				HFM18=(Tltw[14]&2)/2;
				HFM19=(Tltw[14]&4)/4;
				HFM20=(Tltw[14]&8)/8;
				HFM21=(Tltw[14]&16)/16;
				HFM22=(Tltw[14]&32)/32;
				HFM23=(Tltw[14]&64)/64;
				HFM24=(Tltw[14]&128)/128;
				HFM25=(Tltw[14]&256)/256;
				HFM26=(Tltw[14]&512)/512;
				HFM27=(Tltw[14]&1024)/1024;
				HFM28=(Tltw[14]&2048)/2048;
				HFM29=(Tltw[14]&4096)/4096;
				HFM30=(Tltw[14]&8192)/8192;
				HFM31=(Tltw[14]&16384)/16384;
				HFM32=(Tltw[14]&32768)/32768;

				HFL01=(Tltw[9]&1);
				HFL05=(Tltw[9]&16)/16;
				HFL21=(Tltw[13]&16)/16;
				if(!((HFL01||HFL05||HFL21)||OffHFL))continue;

					flag=0;
					for(ff=0;ff<Nchdss;ff++)
					{
						
						w_cand[flag]=1;
						
						mass[flag]=Dssms[ff];
						massPhi[flag]=Dsphms[ff];

						ptD[flag]=Dsspm[ff]*sin(Dssth[ff]);
						if(!(ptD[flag]>3.8||OffptD))continue;

						etaD[flag]=-log(sin(Dssth[ff]/2)/cos(Dssth[ff]/2));
						if(!(fabs(etaD[flag])<1.6||OffetaD))continue;

						if(!(massPhi[flag]>1.012&&massPhi[flag]<1.028||OffmassPhi))continue;

						ptK1[flag]=fabs(Dsk1pm[ff])*sin(Dsk1th[ff]);
						if(!(ptK1[flag]>0.7||OffptK1))continue;

						ptK2[flag]=fabs(Dsk2pm[ff])*sin(Dsk2th[ff]);
						if(!(ptK2[flag]>0.7||OffptK2))continue;

						ptPi[flag]=fabs(Dspipm[ff])*sin(Dspith[ff]);
						if(!(ptPi[flag]>0.5||OffptPi))continue;

						etaK1[flag]=-log(sin(Dsk1th[ff]/2)/cos(Dsk1th[ff]/2));
						if(!(fabs(etaK1[flag])<1.7||OffetaK1))continue;

						etaK2[flag]=-log(sin(Dsk2th[ff]/2)/cos(Dsk2th[ff]/2));
						if(!(fabs(etaK2[flag])<1.7||OffetaK2))continue;

						etaPi[flag]=-log(sin(Dspith[ff]/2)/cos(Dspith[ff]/2));
						if(!(fabs(etaPi[flag])<1.7||OffetaPi))continue;

						chKa[flag]=Trk_charge[Tdsspi[ff]-1];

						louinK1[flag]=Trk_layouter[Tdssk1[ff]-1]-Trk_layinner[Tdssk1[ff]-1];
						louinK2[flag]=Trk_layouter[Tdssk2[ff]-1]-Trk_layinner[Tdssk2[ff]-1];
						louinPi[flag]=Trk_layouter[Tdsspi[ff]-1]-Trk_layinner[Tdsspi[ff]-1];
						if (!((louinK1[flag]>2&&louinK2[flag]>2&&louinPi[flag]>2)||Offlouin))continue;

						/// Chi2 ///
						chi2[flag]=Chchi2[Idssvtx[ff]-1];
						if (!(chi2[flag] < 15 ||Offchi2))continue;
						/// ... ///

						/// ptD_Et10 ///
							
						if(Cal_et10>0)ptD_Et10[flag] = ptD[flag]/((Cal_et-Cal_et10)*CAL_VAR);
						//if(Cal_et10==0)ptD_Et10[flag] = 0;
						if(!(ptD_Et10[flag]>0.18||OffptD_Et10))continue;
						/// ... ///

						/// signif_pt ///
						dlx=Chvtxpar[Idssvtx[ff]-1][0]-Chvtxpar[Idssrprm[ff]-1][0];
						dly=Chvtxpar[Idssvtx[ff]-1][1]-Chvtxpar[Idssrprm[ff]-1][1];
						dlen[flag]=sqrt(dlx*dlx+dly*dly); if(dlen[flag]>1.5)continue;

						v_dl.SetXYZ(dlx,dly,0.0);
						v_pD.SetXYZ(ptD[flag]*cos(Dssph[ff]),ptD[flag]*sin(Dssph[ff]),0.0);
						Lxy[flag]=(v_dl.Dot(v_pD))/(ptD[flag]);
						covxy=Chvtxcov[Idssrprm[ff]-1][1]+Chvtxcov[Idssvtx[ff]-1][1];
						covxx=fabs(Chvtxcov[Idssrprm[ff]-1][0]+Chvtxcov[Idssvtx[ff]-1][0]);
						covyy=fabs(Chvtxcov[Idssrprm[ff]-1][2]+Chvtxcov[Idssvtx[ff]-1][2]);
						err_Lxy[flag]=sqrt(pow(cos(Dssph[ff]),2)*covxx + 2*covxy*cos(Dssph[ff])*sin(Dssph[ff]) + pow(sin(Dssph[ff]),2)*covyy);
						signif_pt[flag]=Lxy[flag]/err_Lxy[flag];

						sign_bug[flag]=0;
						   if(Chvtxpar[Idssrprm[ff]-1][0]==0.&&Chvtxpar[Idssrprm[ff]-1][1]==0.)
							{
								sign_bug[flag]=1;
								Float_t bx=Bspt_x;
								Float_t by=Bspt_y;
								if(Runnr<2) {
									if(Simrun<52000) {
   											Bspt_dxdz=-0.00037;
        										Bspt_dydz=-0.00039;
											}
									else if((Simrun>52000&&Simrun<58000)) {
        										Bspt_dxdz=-0.00045;
        										Bspt_dydz=-0.00031;
											}
									else if((Simrun>58000&&Simrun<60000)) {
        										Bspt_dxdz=-0.00049;
        										Bspt_dydz=-0.00029;
											}
									else if(Simrun<60000) {
        										Bspt_dxdz=-0.00046;
        										Bspt_dydz=-0.00030;
											}
									}
									bx+=Bspt_dxdz*(Zvtx-Bspt_z);
                                					by+=Bspt_dydz*(Zvtx-Bspt_z);
									//bx+=Bspt_dxdz*(chvtxpar[vtx_prim][2]-Bspt_z);
									//by+=Bspt_dydz*(chvtxpar[vtx_prim][2]-Bspt_z);
									dlx=Chvtxpar[Idssrprm[ff]-1][0]-bx;
									dly=Chvtxpar[Idssrprm[ff]-1][1]-by;
									dlen[flag]=sqrt(dlx*dlx+dly*dly);
									float covxx=0.0088*0.0088;
									float covxy=0.;
									float covyy=0.0024*0.0024;
									if((Simrun>52000&&Simrun<58000)||(Simrun>58000&&Simrun<60000)) {
									covxx=0.0080*0.0080;
									covyy=0.0022*0.0022;
									}
								v_dl.SetXYZ(dlx,dly,0.0);
								Lxy[flag]=(v_dl.Dot(v_pD))/(ptD[flag]);
								err_Lxy[flag]=sqrt(pow(cos(Dssph[ff]),2)*covxx + 2*covxy*cos(Dssph[ff])*sin(Dssph[ff]) + pow(sin(Dssph[ff]),2)*covyy);
								signif_pt[flag]=Lxy[flag]/err_Lxy[flag];

							}

						if (!((signif_pt[flag]>0&&signif_pt[flag]<90000)||Offsignif_pt))continue;
						/// ... ///

						/// cosP ///
						pxK1=fabs(Dsk1pm[ff])*sin(Dsk1th[ff])*cos(Dsk1ph[ff]);
						pyK1=fabs(Dsk1pm[ff])*sin(Dsk1th[ff])*sin(Dsk1ph[ff]);
						pzK1=fabs(Dsk1pm[ff])*cos(Dsk1th[ff]);

						pxK2=fabs(Dsk2pm[ff])*sin(Dsk2th[ff])*cos(Dsk2ph[ff]);
						pyK2=fabs(Dsk2pm[ff])*sin(Dsk2th[ff])*sin(Dsk2ph[ff]);
						pzK2=fabs(Dsk2pm[ff])*cos(Dsk2th[ff]);

						pxPi=fabs(Dspipm[ff])*sin(Dspith[ff])*cos(Dspiph[ff]);
						pyPi=fabs(Dspipm[ff])*sin(Dspith[ff])*sin(Dspiph[ff]);
						pzPi=fabs(Dspipm[ff])*cos(Dspith[ff]);

						PK1.SetXYZM(pxK1,pyK1,pzK1,mass_kaon);
						PK2.SetXYZM(pxK2,pyK2,pzK2,mass_kaon);
						PPi.SetXYZM(pxPi,pyPi,pzPi,mass_pion);

						PK1K2=PK1+PK2;
						PK1Pi=PK1+PPi;
						PK2Pi=PK2+PPi;

						//G_res[flag] = G(S1,S2,S,m2*m2,m1*m1,m3*m3);

						vD.SetXYZ(Dsspm[ff]*sin(Dssth[ff])*cos(Dssph[ff]),Dsspm[ff]*sin(Dssth[ff])*sin(Dssph[ff]),Dsspm[ff]*cos(Dssth[ff]));
						vP.SetXYZ(pxPi,pyPi,pzPi);

						Ep=PPi.E();
						Ed=sqrt(vD.Mag2()+mass_dsubs*mass_dsubs);
						vPfD=vP+(Ep/mass_pion)*((((Ep/mass_pion)*((vD.Dot(vP))/Ed))/(Ep/mass_pion+1)-Ep)/Ed)*vD;

						cosP[flag] = vPfD.Dot(vD)/vD.Mag()/vPfD.Mag();
						if(!(cosP[flag]<0.85||OffcosP))continue;

						vKK.SetXYZ(pxK1+pxK2,pyK1+pyK2,pzK1+pzK2);
						Ekk = PK1K2.E();

						vPfKK=vP+(Ep/mass_pion)*((((Ep/mass_pion)*((vKK.Dot(vP))/Ekk))/(Ep/mass_pion+1)-Ep)/Ekk)*vKK;

						vK.SetXYZ(pxK1,pyK1,pzK1);
						Ek=PK1.E();

						vKfKK=vK+(Ek/mass_kaon)*((((Ek/mass_kaon)*((vKK.Dot(vK))/Ekk))/(Ek/mass_kaon+1)-Ek)/Ekk)*vKK;

						cosK[flag]=fabs(pow((vPfKK.Dot(vKfKK)/vPfKK.Mag()/vKfKK.Mag()),3));
						if(!(cosK[flag]>0.1||OffcosK))continue;
						/// ... ///

						/// z ///
						z[flag]=(sqrt(Dsspm[ff]*Dsspm[ff]+mass_dsubs*mass_dsubs)-Dsspm[ff]*cos(Dssth[ff]))/(V_h_e_zu-V_h_pz_zu);
						/// ... ///
						
///Matching !!!!!!!!!!!!!!!!
/*
decays[flag]=-10;
m[flag]=0;
m11[flag]=0;
MATCH[flag]=0;
autoMATCH[flag]=0;

if((Mcmatquality[Tdssk1[ff]-1]+ Mcmatquality[Tdssk2[ff]-1]+Mcmatquality[Tdsspi[ff]-1])>-5)m[flag]=1;
if((Mcmatquality[Tdssk1[ff]-1]+ Mcmatquality[Tdssk2[ff]-1]+Mcmatquality[Tdsspi[ff]-1])>1)m11[flag]=1;

	Int_t  id_kaon1=Mcmatfmckin_id[Tdssk1[ff]-1];
	Int_t  id_kaon2=Mcmatfmckin_id[Tdssk2[ff]-1];
	Int_t  id_pion=Mcmatfmckin_id[Tdsspi[ff]-1];

Float_t ptD_true,etaD_true;
TVector3 vD_true;
	vD_true.SetXYZ(1000,1000,1000);

/// Ds matching !!! ///
nM[flag]=0;
 Float_t min_dellta=100;
for(Int_t f=0;f<Fmck_nstor;f++)
	{
		Int_t number_K=0;
		Int_t number_Pi=0;
		Int_t number_X=0;
		
		if(Fmck_prt[f]==68||Fmck_prt[f]==69)
		{
			for(Int_t s=0;s<Fmck_nstor;s++)
			{
				if(Fmck_id[f]==Fmck_daug[s])
				{
					if((Fmck_prt[s]==54||Fmck_prt[s]==55)){number_Pi++;}
					else if((Fmck_prt[s]==58||Fmck_prt[s]==59)){number_K++;}
					else if(Fmck_prt[s]==85||Fmck_prt[s]==148||Fmck_prt[s]==149||Fmck_prt[s]==81)
					{
					   for (Int_t t=0;t<Fmck_nstor;t++)
					   {
					     if(Fmck_id[s]==Fmck_daug[t])
					     {
					      if((Fmck_prt[t]==58||Fmck_prt[t]==59))number_K++;
					      else 
						if((Fmck_prt[t]==54||Fmck_prt[t]==55))number_Pi++;
						else number_X++;
					     }
					   }
					}
				}
			}
		if(number_X==0&&number_K==2&&number_Pi==1)
			{
				vD_true.SetXYZ(Fmck_px[f],Fmck_py[f],Fmck_pz[f]);nM[flag]++;
				dellta[flag]=((vD-vD_true).Mag())/((vD+vD_true).Mag());
				if(dellta[flag]<min_dellta)min_dellta=dellta[flag];
			}

		}
	dellta[flag]=min_dellta;
	}

if(dellta[flag]<0.05) MATCH[flag] = 1;
	/// ... ///

/// Dplus matching !!! ///
vD_true.SetXYZ(1000,1000,1000);
min_dellta=100;
for(Int_t f=0;f<Fmck_nstor;f++)
	{
		Int_t number_K=0;
		Int_t number_Pi=0;
		Int_t number_X=0;
		
		if(Fmck_prt[f]==64||Fmck_prt[f]==65)
		{
			for(Int_t s=0;s<Fmck_nstor;s++)
			{
				if(Fmck_id[f]==Fmck_daug[s])
				{
					if((Fmck_prt[s]==54||Fmck_prt[s]==55)){number_Pi++;}
					else if((Fmck_prt[s]==58||Fmck_prt[s]==59)){number_K++;}
					else if(Fmck_prt[s]==148||Fmck_prt[s]==149)
					{
					   for (Int_t t=0;t<Fmck_nstor;t++)
					   {
					     if(Fmck_id[s]==Fmck_daug[t])
					     {
					      if((Fmck_prt[t]==58||Fmck_prt[t]==59))number_K++;
					      else 
						if((Fmck_prt[t]==54||Fmck_prt[t]==55))number_Pi++;
						else number_X++;
					     }
					   }
					}
				}
			}
		if(number_X==0&&number_K==1&&number_Pi==2)
			{
				vD_true.SetXYZ(Fmck_px[f],Fmck_py[f],Fmck_pz[f]);nM[flag]++;
				dDp[flag]=((vD-vD_true).Mag())/((vD+vD_true).Mag());
				if(dDp[flag]<min_dellta)min_dellta=dDp[flag];
			}

		}
	dDp[flag]=min_dellta;
	}
/// ... ///

/// Lambda matching !!! ///
vD_true.SetXYZ(1000,1000,1000);
min_dellta=100;
for(Int_t f=0;f<Fmck_nstor;f++)
	{
		Int_t number_K=0;
		Int_t number_Pi=0;
		Int_t number_Pr=0;
		Int_t number_X=0;
		if(Fmck_prt[f]==208||Fmck_prt[f]==209)
		{
			for(Int_t s=0;s<Fmck_nstor;s++)
			{
				if(Fmck_id[f]==Fmck_daug[s])
				{
					if((Fmck_prt[s]==54||Fmck_prt[s]==55)){number_Pi++;}
					else if((Fmck_prt[s]==58||Fmck_prt[s]==59)){number_K++;}
					else if((Fmck_prt[s]==190||Fmck_prt[s]==191)){number_Pr++;}
					else if(Fmck_prt[s]==148||Fmck_prt[s]==149||Fmck_prt[s]==256||Fmck_prt[s]==257)
					{
					   for (Int_t t=0;t<Fmck_nstor;t++)
					   {
					     if(Fmck_id[s]==Fmck_daug[t])
					     {
					      if((Fmck_prt[t]==58||Fmck_prt[t]==59))number_K++;
					      else if((Fmck_prt[t]==54||Fmck_prt[t]==55))number_Pi++;
						else if((Fmck_prt[t]==190||Fmck_prt[t]==191)){number_Pr++;}
						else number_X++;
					     }
					   }
					}
				}
			}
		if(number_X==0&&number_K==1&&number_Pi==1&&number_Pr==1)
			{
				vD_true.SetXYZ(Fmck_px[f],Fmck_py[f],Fmck_pz[f]);
				dLc[flag]=((vD-vD_true).Mag())/((vD+vD_true).Mag());
				if(dLc[flag]<min_dellta)min_dellta=dLc[flag];
			}
		}
		dLc[flag]=min_dellta;
	}
/// ... ///

*/
							flag++;
							}

				if(flag>0) {dsubs->TTree::Fill();}
			}

TFile f(outfile,"RECREATE");
dsubs->Write();
f.Close();

cout<<"nevents= "<< nevents<<endl;
cout << "Events left:" <<dsubs->GetEntries()<< endl;
cout << "Finish!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
}


