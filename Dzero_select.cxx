
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


Double_t arccos(Double_t a,Double_t sign){
if(sign>0)return acos(a);
else return 2*3.14159265358979323846-acos(a);
}

int main(int argc, char** argv){

TChain * ntD=new TChain("orange");

Char_t outfile[1024]="ing_yang_hren.root";
//  Char_t infile[1024]="zeus://acs/z/ntup/06p/v02d/data/root/data_06p_61456_61456_01.root";
//Char_t infile[1024]="data_06p_61456_61456_01.root";
//Char_t infile[1024]="zeusmc.hduwe25.f15892.py6156k.cc.ct46gr03.da104.root";
Char_t infile[1024]="/pnfs/desy.de/dphep/online/zeus/z/ntup/06p/v08b/data/root/data_06p_61452_61452_01.root";



Int_t b=0;
Int_t i;
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


ntD->Add(infile);
//ntD->Add("../*.root");
cout<<"Out!!!!!!!!!!!!!!!!!!!!!!!:      " << outfile << endl;         

// ntD->Add("zeus://acs/z/ntup/07p/v02e/mc/root/zeusmc.xfsy627.f15892.py6156k.cg.ct46gr03.da080.root");
// ntD->Add("zeus://acs/z/ntup/07p/v02e/mc/root/zeusmc.xfsy627.f15892.py6156k.cg.ct46gr03.da081.root");
// ntD->Add("zeus://acs/z/ntup/07p/v02e/mc/root/zeusmc.xfsy627.f15892.py6156k.cg.ct46gr03.da083.root");
// ntD->Add("zeus://acs/z/ntup/07p/v02e/mc/root/zeusmc.xfsz627.f15892.py6156k.cg.ct46gr03.da093.root");
// ntD->Add("zeus://acs/z/ntup/07p/v02e/mc/root/zeusmc.afsy627.f15892.py6156k.cc.ct46gr03.da003.root");
// ntD->Add("zeus://acs/z/ntup/07p/v02e/mc/root/zeusmc.afsy627.f15892.py6156k.cc.ct46gr03.da007.root");
// ntD->Add("zeus://acs/z/ntup/07p/v02e/mc/root/zeusmc.afsy627.f15892.py6156k.cc.ct46gr03.da013.root");
// ntD->Add("zeus://acs/z/ntup/07p/v02e/mc/root/zeusmc.afsz627.f15892.py6156k.cc.ct46gr03.da086.root");
// 
//  ntD->Add("../*.root");



Int_t nevents = ntD->GetEntries();


////////////////////////////////////DECLARE values//////////////////////////////

///////////////////....................Branch declare.................///////////////////////////////////

ntD->SetBranchStatus("*",0);



///.................Event................................
Int_t Runnr;
	ntD->SetBranchStatus("Runnr",1);
	ntD->SetBranchAddress("Runnr", &Runnr);

///..................Tracking............................
   Int_t           Trk_ntracks;
   Int_t           Trk_type[2800];   //[trk_ntracks]
   Int_t           Ntrack_type[4];
   Int_t           Def_trk_type;
   Int_t           Trk_id[2800];   //[trk_ntracks]
   //   Int_t           Trk_id2[2800];   //[trk_ntracks]

   ntD->SetBranchStatus("Trk_ntracks",1);
   ntD->SetBranchStatus("Trk_type",0);
   ntD->SetBranchStatus("Ntrack_type",0);
   ntD->SetBranchStatus("Def_trk_type",0);
   ntD->SetBranchStatus("Trk_id",1);
   //   ntD->SetBranchStatus("Trk_id2",0);

   ntD->SetBranchAddress("Trk_ntracks", &Trk_ntracks);
   ntD->SetBranchAddress("Trk_type", Trk_type);
   ntD->SetBranchAddress("Ntrack_type", Ntrack_type);
   ntD->SetBranchAddress("Def_trk_type", &Def_trk_type);
   ntD->SetBranchAddress("Trk_id", Trk_id);
   //   ntD->SetBranchAddress("Trk_id2", Trk_id2);



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
   ntD->SetBranchStatus("Trk_dedxctdcr", 1);
   ntD->SetBranchAddress("Trk_dedxctdcr", Trk_dedxctdcr);
   Int_t  Trk_dedxctderr[2800];
   ntD->SetBranchStatus("Trk_dedxctderr", 1);
   ntD->SetBranchAddress("Trk_dedxctderr", Trk_dedxctderr);
   Int_t  Trk_dedxctdnh[2800];
   ntD->SetBranchStatus("Trk_dedxctdnh", 1);
   ntD->SetBranchAddress("Trk_dedxctdnh", Trk_dedxctdnh);


Float_t         Trk_charge[2800];   //[trk_ntracks]
ntD->SetBranchStatus("Trk_charge", 1);
ntD->SetBranchAddress("Trk_charge", Trk_charge);

Float_t         Trk_px[2800];   //[trk_ntracks]
ntD->SetBranchStatus("Trk_px", 1);
ntD->SetBranchAddress("Trk_px", Trk_px);

Float_t         Trk_py[2800];   //[trk_ntracks]
ntD->SetBranchStatus("Trk_py", 1);
ntD->SetBranchAddress("Trk_py", Trk_py);

Float_t         Trk_pz[2800];   //[trk_ntracks]
ntD->SetBranchStatus("Trk_pz", 1);
ntD->SetBranchAddress("Trk_pz", Trk_pz);

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
   
///.................Trk_imp...................................
   Float_t         Trk_imppar[2800];   //[trk_ntracks]
   Float_t         Trk_imperr[2800];   //[trk_ntracks]
   Float_t         Trk_pca[2800][3];   //[trk_ntracks]
   ntD->SetBranchStatus("Trk_imppar",0);
   ntD->SetBranchStatus("Trk_imperr",0);
   ntD->SetBranchStatus("Trk_pca",0);
   ntD->SetBranchAddress("Trk_imppar", Trk_imppar);
   ntD->SetBranchAddress("Trk_imperr", Trk_imperr);
   ntD->SetBranchAddress("Trk_pca", Trk_pca);
///.................Trk_vert...................................

///.................CHARMTRK...................................


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

///.................DZEROSH.................................
Int_t Nchd0;
ntD->SetBranchStatus("Nchd0",1);
ntD->SetBranchAddress("Nchd0", &Nchd0);
Float_t   D0ms[2500];
ntD->SetBranchStatus("D0ms",1);
ntD->SetBranchAddress("D0ms", D0ms);
Float_t   D0pm[2500];
ntD->SetBranchStatus("D0pm",1);
ntD->SetBranchAddress("D0pm", D0pm);
Float_t   D0th[2500];
ntD->SetBranchStatus("D0th",1);
ntD->SetBranchAddress("D0th", D0th);
Float_t   D0ph[2500];
ntD->SetBranchStatus("D0ph",1);
ntD->SetBranchAddress("D0ph", D0ph);

//Int_t   Id0ka[250];
//ntD->SetBranchStatus("Id0ka",1);
//ntD->SetBranchAddress("Id0ka", Id0ka);
Float_t   D0kapm[2500];
ntD->SetBranchStatus("D0kapm",1);
ntD->SetBranchAddress("D0kapm", D0kapm);
Float_t   D0kath[2500];
ntD->SetBranchStatus("D0kath",1);
ntD->SetBranchAddress("D0kath", D0kath);
Float_t   D0kaph[2500];
ntD->SetBranchStatus("D0kaph",1);
ntD->SetBranchAddress("D0kaph", D0kaph);

//Int_t   Id0pi[250];
//ntD->SetBranchStatus("Id0pi",1);
//ntD->SetBranchAddress("Id0pi", Id0pi);
Float_t   D0pipm[2500];
ntD->SetBranchStatus("D0pipm",1);
ntD->SetBranchAddress("D0pipm", D0pipm);
Float_t   D0pith[2500];
ntD->SetBranchStatus("D0pith",1);
ntD->SetBranchAddress("D0pith", D0pith);
Float_t   D0piph[2500];
ntD->SetBranchStatus("D0piph",1);
ntD->SetBranchAddress("D0piph", D0piph);

///.................D0SH_RV.................................
Int_t   D0trk[2500];
ntD->SetBranchStatus("D0trk",1);
ntD->SetBranchAddress("D0trk", D0trk);
Int_t   Td0ka[2500];
ntD->SetBranchStatus("Td0ka",1);
ntD->SetBranchAddress("Td0ka", Td0ka);
Int_t   Td0pi[2500];
ntD->SetBranchStatus("Td0pi",1);
ntD->SetBranchAddress("Td0pi", Td0pi);
Int_t   Id0vtx [2500];
ntD->SetBranchStatus("Id0vtx",1);
ntD->SetBranchAddress("Id0vtx", Id0vtx);
Int_t   Id0rprm[2500];
ntD->SetBranchStatus("Id0rprm",1);
ntD->SetBranchAddress("Id0rprm", Id0rprm);

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
   
/// ////////  FMCK   ////////////////////////////
   Int_t           Fmck_nstor;
   Int_t           Fmck_id[4000];   //[fmck_nstor]
   Float_t         Fmck_px[4000];   //[fmck_nstor]
   Float_t         Fmck_py[4000];   //[fmck_nstor]
   Float_t         Fmck_pz[4000];   //[fmck_nstor]
   Float_t         Fmck_e[4000];   //[fmck_nstor]
   Float_t         Fmck_m[4000];   //[fmck_nstor]
   Float_t         Fmck_w;
   Int_t           Fmck_isthep[4000];   //[fmck_nstor]
   Int_t           Fmck_daug[4000];   //[fmck_nstor]
   Int_t           Fmck_daug2[4000];   //[fmck_nstor]
   Int_t           Fmck_prt[4000];   //[fmck_nstor]
   Int_t           Fmck_prat[4000];   //[fmck_nstor]
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
///.................DSTAR1SH.................................
 Int_t           Nchds1;
   Float_t         Ds1ms[50];   //[Nchds1]
   Float_t         Ds1pm[50];   //[Nchds1]
   Float_t         Ds1th[50];   //[Nchds1]
   Float_t         Ds1ph[50];   //[Nchds1]
   Float_t         D1d0ms[50];   //[Nchds1]
   Float_t         D1d0pm[50];   //[Nchds1]
   Float_t         D1d0th[50];   //[Nchds1]
   Float_t         D1d0ph[50];   //[Nchds1]
   Float_t         D1kapm[50];   //[Nchds1]
   Float_t         D1kath[50];   //[Nchds1]
   Float_t         D1kaph[50];   //[Nchds1]
   Float_t         D1pipm[50];   //[Nchds1]
   Float_t         D1pith[50];   //[Nchds1]
   Float_t         D1piph[50];   //[Nchds1]
   Float_t         D1pspm[50];   //[Nchds1]
   Float_t         D1psth[50];   //[Nchds1]
   Float_t         D1psph[50];   //[Nchds1]
   ntD->SetBranchStatus("Nchds1", 1);
   ntD->SetBranchStatus("Ds1ms", 1);
   ntD->SetBranchStatus("Ds1pm", 1);
   ntD->SetBranchStatus("Ds1th", 1);
   ntD->SetBranchStatus("Ds1ph", 1);
   ntD->SetBranchStatus("D1d0ms", 1);
   ntD->SetBranchStatus("D1d0pm", 1);
   ntD->SetBranchStatus("D1d0th", 1);
   ntD->SetBranchStatus("D1d0ph", 1);
   ntD->SetBranchStatus("D1kapm", 1);
   ntD->SetBranchStatus("D1kath", 1);
   ntD->SetBranchStatus("D1kaph", 1);
   ntD->SetBranchStatus("D1pipm", 1);
   ntD->SetBranchStatus("D1pith", 1);
   ntD->SetBranchStatus("D1piph", 1);
   ntD->SetBranchStatus("D1pspm", 1);
   ntD->SetBranchStatus("D1psth", 1);
   ntD->SetBranchStatus("D1psph", 1);
   
   ntD->SetBranchAddress("Nchds1", &Nchds1);
   ntD->SetBranchAddress("Ds1ms", Ds1ms);
   ntD->SetBranchAddress("Ds1pm", Ds1pm);
   ntD->SetBranchAddress("Ds1th", Ds1th);
   ntD->SetBranchAddress("Ds1ph", Ds1ph);
   ntD->SetBranchAddress("D1d0ms", D1d0ms);
   ntD->SetBranchAddress("D1d0pm", D1d0pm);
   ntD->SetBranchAddress("D1d0th", D1d0th);
   ntD->SetBranchAddress("D1d0ph", D1d0ph);
   ntD->SetBranchAddress("D1kapm", D1kapm);
   ntD->SetBranchAddress("D1kath", D1kath);
   ntD->SetBranchAddress("D1kaph", D1kaph);
   ntD->SetBranchAddress("D1pipm", D1pipm);
   ntD->SetBranchAddress("D1pith", D1pith);
   ntD->SetBranchAddress("D1piph", D1piph);
   ntD->SetBranchAddress("D1pspm", D1pspm);
   ntD->SetBranchAddress("D1psth", D1psth);
   ntD->SetBranchAddress("D1psph", D1psph);

///.................DSTAR1SH_RV.................................
   Int_t           Ds1trk[50];   //[Nchds1]
   Int_t           Tds1ka[50];   //[Nchds1]
   Int_t           Tds1pi[50];   //[Nchds1]
   Int_t           Tds1ps[50];   //[Nchds1]
   Int_t           Id1d0vtx[50];   //[Nchds1]
   Int_t           Ids1rprm[50];   //[Nchds1]
   ntD->SetBranchStatus("Ds1trk", 1);
   ntD->SetBranchStatus("Tds1ka", 1);
   ntD->SetBranchStatus("Tds1pi", 1);
   ntD->SetBranchStatus("Tds1ps", 1);
   ntD->SetBranchStatus("Id1d0vtx", 1);
   ntD->SetBranchStatus("Ids1rprm",1); 
   
   ntD->SetBranchAddress("Ds1trk", Ds1trk);
   ntD->SetBranchAddress("Tds1ka", Tds1ka);
   ntD->SetBranchAddress("Tds1pi", Tds1pi);
   ntD->SetBranchAddress("Tds1ps", Tds1ps);
   ntD->SetBranchAddress("Id1d0vtx", Id1d0vtx);
   ntD->SetBranchAddress("Ids1rprm", Ids1rprm);  


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
 //   ntD->SetBranchStatus("Simrun", 1);
 //  ntD->SetBranchAddress("Simrun", &Simrun);


/// deklare ///

const Float_t mass_pion=0.13957018;
const Float_t mass_kaon=0.493677;
const Float_t mass_dzero=1.8648;

TLorentzVector P1,P2,P3,P1P2,P2P3,P3P1;
Float_t pxKa,pyKa,pzKa,pxPi,pyPi,pzPi;

Float_t W;


Int_t HFL01,HFL05,HFL21;

Int_t HFM01,HFM02,HFM03,HFM04,HFM05,HFM06,HFM07,HFM08,HFM09,HFM10,HFM11,HFM12,HFM13,HFM14,HFM15,HFM16,HFM17,HFM18,HFM19,HFM20,HFM21,HFM22,HFM23,HFM24,HFM25,HFM26,HFM27,HFM28,HFM29,HFM30,HFM31,HFM32;


//Float_t w_event=1;
Int_t beauty=1;

Float_t mass[1000],etaD[1000],ptD[1000],phiD[1000],chKa[1000],chPi[1000],phiPi[1000],phiKa[1000],ptKa[1000],ptp1[1000],pp1[1000],etaKa[1000],etap1[1000],louinKa[1000],louinp1[1000],signif_pt[1000],Lxy[1000],err_Lxy[1000],chi2[1000],cosK[1000],d[1000],ptD_Et10[1000],z[1000],Mkk[1000],Mpipi[1000];
Float_t mass_ref[1000];

Float_t covxy,dlx,covxx,dly,covyy;

TVector3 vD,vK,vP,v_dl,v_pD;



TNtuple *dzero = new TNtuple("dzero","dzero","");



///##################################### start LOOP #################################
Int_t nEvt;

Int_t cutSira=0;

const Int_t OffZvtx=0;
const Int_t OffSira=0;
const Int_t Offchi2=0;
const Int_t OffW=0;
const Int_t Offlouin=0;
const Int_t Offsignif_pt=0;

const Int_t OffHFL=0;
const Int_t OffptD_Et10=0;

const Int_t OffptD=0;
const Int_t OffetaD=0;

const Int_t OffptKa=0;
const Int_t Offptp1=0;

const Int_t OffetaKa=0;
const Int_t Offetap1=0;


Int_t ff,ss;
Int_t flag=0;

dzero->Branch("beauty", &b, "beauty/I");
dzero->Branch("Zvtx", &Zvtx, "Zvtx/F");
dzero->Branch("W", &W, "W/F");
dzero->Branch("HFL01", &HFL01, "HFL01/I");
dzero->Branch("HFL05", &HFL05, "HFL05/I");
dzero->Branch("HFL21", &HFL21, "HFL21/I");

dzero->Branch("HFM01", &HFM01, "HFM01/I");
dzero->Branch("HFM02", &HFM02, "HFM02/I");
dzero->Branch("HFM03", &HFM03, "HFM03/I");
dzero->Branch("HFM04", &HFM04, "HFM04/I");
dzero->Branch("HFM05", &HFM05, "HFM05/I");
dzero->Branch("HFM06", &HFM06, "HFM06/I");
dzero->Branch("HFM07", &HFM07, "HFM07/I");
dzero->Branch("HFM08", &HFM08, "HFM08/I");
dzero->Branch("HFM09", &HFM09, "HFM09/I");
dzero->Branch("HFM10", &HFM10, "HFM10/I");
dzero->Branch("HFM11", &HFM11, "HFM11/I");
dzero->Branch("HFM12", &HFM12, "HFM12/I");
dzero->Branch("HFM13", &HFM13, "HFM13/I");
dzero->Branch("HFM14", &HFM14, "HFM14/I");
dzero->Branch("HFM15", &HFM15, "HFM15/I");
dzero->Branch("HFM16", &HFM16, "HFM16/I");
dzero->Branch("HFM17", &HFM17, "HFM17/I");
dzero->Branch("HFM18", &HFM18, "HFM18/I");
dzero->Branch("HFM19", &HFM19, "HFM19/I");
dzero->Branch("HFM20", &HFM20, "HFM20/I");
dzero->Branch("HFM21", &HFM21, "HFM21/I");
dzero->Branch("HFM22", &HFM22, "HFM22/I");
dzero->Branch("HFM23", &HFM23, "HFM23/I");
dzero->Branch("HFM24", &HFM24, "HFM24/I");
dzero->Branch("HFM25", &HFM25, "HFM25/I");
dzero->Branch("HFM26", &HFM26, "HFM26/I");
dzero->Branch("HFM27", &HFM27, "HFM27/I");
dzero->Branch("HFM28", &HFM28, "HFM28/I");
dzero->Branch("HFM29", &HFM29, "HFM29/I");
dzero->Branch("HFM30", &HFM30, "HFM30/I");
dzero->Branch("HFM31", &HFM31, "HFM31/I");
dzero->Branch("HFM32", &HFM32, "HFM32/I");


//dzero->Branch("Sierror", &Sincand, "Sincand/I");
//dzero->Branch("Siprob",Siprob,"Siprob[Sincand]/F");
dzero->Branch("Ngoodcand", &flag, "Ngoodcand/I");
dzero->Branch("mass", mass, "mass[Ngoodcand]/F");
dzero->Branch("chKa", chKa, "chKa[Ngoodcand]/F");
dzero->Branch("Mkk", Mkk, "Mkk[Ngoodcand]/F");
dzero->Branch("Mpipi", Mpipi, "Mpipi[Ngoodcand]/F");
Float_t decays[1000],m[1000],m1[1000],dellta[1000],dKk[1000],dPp[1000];
dzero->Branch("decays", decays, "decays[Ngoodcand]/F");
dzero->Branch("m", m, "m[Ngoodcand]/F");
dzero->Branch("m1", m1, "m1[Ngoodcand]/F");
dzero->Branch("dellta", dellta, "dellta[Ngoodcand]/F");
dzero->Branch("dKk", dKk, "dKk[Ngoodcand]/F");
dzero->Branch("dPp", dPp, "dPp[Ngoodcand]/F");

dzero->Branch("ptD", ptD, "ptD[Ngoodcand]/F");
dzero->Branch("etaD", etaD, "etaD[Ngoodcand]/F");
dzero->Branch("ptKa", ptKa, "ptKa[Ngoodcand]/F");
dzero->Branch("ptp1", ptp1, "ptp1[Ngoodcand]/F");
dzero->Branch("pp1", pp1, "pp1[Ngoodcand]/F");

dzero->Branch("etaKa", etaKa, "etaKa[Ngoodcand]/F");
dzero->Branch("etap1", etap1, "etap1[Ngoodcand]/F");
 dzero->Branch("cosK", cosK, "cosK[Ngoodcand]/F");
 dzero->Branch("d", d, "d[Ngoodcand]/F");

 dzero->Branch("ptD_Et10", ptD_Et10, "ptD_Et10[Ngoodcand]/F");
dzero->Branch("z", z, "z[Ngoodcand]/F");

///dzero->Branch("louinKa", louinKa, "louinKa[Ngoodcand]/F");
///dzero->Branch("louinp1", louinp1, "louinp1[Ngoodcand]/F");
///dzero->Branch("Lxy", Lxy, "Lxy[Ngoodcand]/F");
///dzero->Branch("err_Lxy", err_Lxy, "err_Lxy[Ngoodcand]/F");
dzero->Branch("signif_pt", signif_pt, "signif_pt[Ngoodcand]/F");
dzero->Branch("chi2", chi2, "chi2[Ngoodcand]/F");
dzero->Branch("mass_ref", mass_ref, "mass_ref[Ngoodcand]/F");

Float_t kapiMATCH[1000],kakaMATCH[1000],pipiMATCH[1000];
dzero->Branch("kapiMATCH",kapiMATCH,"kapiMATCH[Ngoodcand]/F");
dzero->Branch("kakaMATCH",kakaMATCH,"kakaMATCH[Ngoodcand]/F");
dzero->Branch("pipiMATCH",pipiMATCH,"pipiMATCH[Ngoodcand]/F");
Float_t valKa[1000],valPi[1000],ref_valKa[1000],ref_valPi[1000];
dzero->Branch("valPi",valPi,"valPi[Ngoodcand]/F");
dzero->Branch("valKa",valKa,"valKa[Ngoodcand]/F");
dzero->Branch("ref_valPi",ref_valPi,"ref_valPi[Ngoodcand]/F");
dzero->Branch("ref_valKa",ref_valKa,"ref_valKa[Ngoodcand]/F");

Float_t kapi[1000],pika[1000],pipi[1000],kaka[1000];
dzero->Branch("kapi",kapi,"kapi[Ngoodcand]/F");
dzero->Branch("pika",pika,"pika[Ngoodcand]/F");
dzero->Branch("kaka",kaka,"kaka[Ngoodcand]/F");
dzero->Branch("pipi",pipi,"pipi[Ngoodcand]/F");

Float_t tag[1000],untag[1000],kaon[1000],pion[1000];
dzero->Branch("tag",tag,"tag[Ngoodcand]/F");
dzero->Branch("untag",untag,"untag[Ngoodcand]/F");
dzero->Branch("kaon",kaon,"kaon[Ngoodcand]/F");
dzero->Branch("pion",pion,"pion[Ngoodcand]/F");


Float_t alpha[1000],pt[1000];
dzero->Branch("alpha",alpha,"alpha[Ngoodcand]/F");
dzero->Branch("pt",pt,"pt[Ngoodcand]/F");


Float_t chK[1000];
dzero->Branch("chK",chK,"chK[Ngoodcand]/F");

Float_t kk[1000],pp[1000];
dzero->Branch("kk",kk,"kk[Ngoodcand]/F");
dzero->Branch("pp",pp,"pp[Ngoodcand]/F");

Float_t dedxPi[1000],dedxKa[1000],pPi[1000],pKa[1000],lka[1000],lpi[1000];
Int_t nhPi[1000],nhKa[1000];
dzero->Branch("dedxPi", &dedxPi, "dedxPi[Ngoodcand]/F");
dzero->Branch("nhPi", &nhPi, "nhPi[Ngoodcand]/I");
dzero->Branch("pPi", &pPi, "pPi[Ngoodcand]/F");
dzero->Branch("lpi", &lpi, "lpi[Ngoodcand]/F");
dzero->Branch("dedxKa", &dedxKa, "dedxKa[Ngoodcand]/F");
dzero->Branch("nhKa", &nhKa, "nhKa[Ngoodcand]/I");
dzero->Branch("pKa", &pKa, "pKa[Ngoodcand]/F");
dzero->Branch("lka", &lka, "lka[Ngoodcand]/F");

Int_t sign_bug[1000];
dzero->Branch("sign_bug",sign_bug,"sign_bug[Ngoodcand]/I");

Float_t dlen[1000];
dzero->Branch("dlen",dlen,"dlen[Ngoodcand]/F");

		for(nEvt=0; nEvt<nevents; nEvt++)
		//for(nEvt=11364; nEvt<=11364; nEvt++)
			{
 				ntD->GetEntry(nEvt);
				//cout << "New event!!!  " << nEvt << endl;
				beauty=b;

				W = pow((2*920*(V_h_e_zu-V_h_pz_zu)*CAL_VAR),0.5);
				
				if ((W>130 && W<300) || OffW) {}
    				else continue;
	

 				if ((fabs(Zvtx)<30.0 && ( Chivtx >0.0)) || OffZvtx) {}
 				else continue;




 				if(!(Sierror == 0)){continue;}
				cutSira=0;
				for(Int_t ee=0;ee<Sincand;ee++)
					{
						if(Siprob[ee]>0.9&&Sicalene[ee]>5)cutSira=1;
						
					}
				if (!((cutSira == 0) || OffSira)) {continue;}



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

				//cout << "Event : " << nEvt << endl;


 								flag=0;
 								for(ff=0;ff<Nchd0;ff++)
								//for(ff=0;ff<=3;ff++)
								
 									{
 										mass[flag]=D0ms[ff];
 									
 										ptD[flag]=D0pm[ff]*sin(D0th[ff]);
 										if (ptD[flag] > 3.8 || OffptD) {}
     										else continue;
 										
										phiD[flag]=D0ph[ff];
										phiPi[flag]=D0piph[ff];
										phiKa[flag]=D0kaph[ff];

										chPi[flag]=Trk_charge[Td0pi[ff]-1];
										chKa[flag]=Trk_charge[Td0ka[ff]-1];
			
 										etaD[flag]=-log(sin(D0th[ff]/2)/cos(D0th[ff]/2));
 										if (fabs(etaD[flag]) < 1.6 || OffetaD) {}
     										else continue;
 										
 										ptKa[flag]=fabs(D0kapm[ff]*sin(D0kath[ff]));
 										if (ptKa[flag] > 0.8 || OffptKa) {}
     										else continue;
 										

 										ptp1[flag]=fabs(D0pipm[ff]*sin(D0pith[ff]));
 										if (ptp1[flag] > 0.8 || Offptp1) {}
     										else continue;
 									
 										etaKa[flag]=-log(sin(D0kath[ff]/2)/cos(D0kath[ff]/2));
										if (fabs(etaKa[flag]) < 1.7 || OffetaKa) {}
     										else continue;
 										
 										etap1[flag]=-log(sin(D0pith[ff]/2)/cos(D0pith[ff]/2));
 										if (fabs(etap1[flag]) < 1.7 || Offetap1) {}
     										else continue;
										
 										
 										louinKa[flag]=Trk_layouter[Td0ka[ff]-1]-Trk_layinner[Td0ka[ff]-1];
 										louinp1[flag]=Trk_layouter[Td0pi[ff]-1]-Trk_layinner[Td0pi[ff]-1];
 										if ((louinKa[flag]>2&&louinp1[flag]>2)||Offlouin) {}
     										else continue;
 										
 								dlx=Chvtxpar[Id0vtx[ff]-1][0]-Chvtxpar[Id0rprm[ff]-1][0];
 								dly=Chvtxpar[Id0vtx[ff]-1][1]-Chvtxpar[Id0rprm[ff]-1][1];
								dlen[flag]=sqrt(dlx*dlx+dly*dly);
								if(dlen[flag]>1.5)continue;
 										v_dl.SetXYZ(dlx,dly,0.0);
 										v_pD.SetXYZ(ptD[flag]*cos(D0ph[ff]),ptD[flag]*sin(D0ph[ff]),0.0);
 										Lxy[flag]=(v_dl.Dot(v_pD))/(ptD[flag]);
 										covxy=Chvtxcov[Id0rprm[ff]-1][1]+Chvtxcov[Id0vtx[ff]-1][1];
 										covxx=fabs(Chvtxcov[Id0rprm[ff]-1][0]+Chvtxcov[Id0vtx[ff]-1][0]);
 										covyy=fabs(Chvtxcov[Id0rprm[ff]-1][2]+Chvtxcov[Id0vtx[ff]-1][2]);
 
 										err_Lxy[flag]=sqrt(pow(cos(D0ph[ff]),2)*covxx + 2*covxy*cos(D0ph[ff])*sin(D0ph[ff]) + pow(sin(D0ph[ff]),2)*covyy);
 										signif_pt[flag]=Lxy[flag]/err_Lxy[flag];
 
							sign_bug[flag]=0;
						   if(Chvtxpar[Id0rprm[ff]-1][0]==0.&&Chvtxpar[Id0rprm[ff]-1][1]==0.)
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
									dlx=Chvtxpar[Id0rprm[ff]-1][0]-bx;
									dly=Chvtxpar[Id0rprm[ff]-1][1]-by;
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
								err_Lxy[flag]=sqrt(pow(cos(D0ph[ff]),2)*covxx + 2*covxy*cos(D0ph[ff])*sin(D0ph[ff]) + pow(sin(D0ph[ff]),2)*covyy);
								signif_pt[flag]=Lxy[flag]/err_Lxy[flag];
							}

 								if ((signif_pt[flag]>1&&signif_pt[flag]<90000)||Offsignif_pt) {}
     										else continue;
 										
  										chi2[flag]=Chchi2[Id0vtx[ff]-1];
  										
  										if ( chi2[flag] < 15 ||Offchi2) {}
      										else continue;
										
										/// ptD_Et10 ///
										
										if(Cal_et10>0)ptD_Et10[flag] = ptD[flag]/((Cal_et-Cal_et10)*CAL_VAR);
										//if(Cal_et10==0)ptD_Et10[flag] = 0;
										if(!(ptD_Et10[flag]>0.18||OffptD_Et10))continue;
										//if(ptD_Et10[flag]<=0.18) continue;
													/// ... ///
//cout << "Still here!!!" << endl;
 										/// z ///
 										
 										z[flag]=(sqrt(D0pm[ff]*D0pm[ff]+1.86484*1.86484)-D0pm[ff]*cos(D0th[ff]))/(V_h_e_zu-V_h_pz_zu);
 										
 										/// ... ///


								/// Wrong charch combinetion!!! ///
								//TLorentzVector P1,P2,P1P2;
								//Double_t pxKa,pyKa,pzKa,pxPi,pyPi,pzPi;
								pxKa=fabs(D0kapm[ff])*sin(D0kath[ff])*cos(D0kaph[ff]);
								pyKa=fabs(D0kapm[ff])*sin(D0kath[ff])*sin(D0kaph[ff]);
								pzKa=fabs(D0kapm[ff])*cos(D0kath[ff]);
								pxPi=fabs(D0pipm[ff])*sin(D0pith[ff])*cos(D0piph[ff]);
								pyPi=fabs(D0pipm[ff])*sin(D0pith[ff])*sin(D0piph[ff]);
								pzPi=fabs(D0pipm[ff])*cos(D0pith[ff]);
				
								P1.SetXYZM(pxPi,pyPi,pzPi,mass_kaon);
								P2.SetXYZM(pxKa,pyKa,pzKa,mass_pion);
								P1P2 = P1 + P2;
								mass_ref[flag]=P1P2.Mag();
										/// ... ///

							/// Armenteros-Podolyanski ///
			vD.SetXYZ(D0pm[ff]*sin(D0th[ff])*cos(D0ph[ff]),D0pm[ff]*sin(D0th[ff])*sin(D0ph[ff]),D0pm[ff]*cos(D0th[ff]));
								vP.SetXYZ(pxPi,pyPi,pzPi);
								vK.SetXYZ(pxKa,pyKa,pzKa);
								pt[flag]=((vD.Cross(vP)).Mag())/vD.Mag();
				if(D0kapm[ff]>0){ alpha[flag]=(vK.Dot(vD)-vP.Dot(vD))/(vK.Dot(vD)+vP.Dot(vD)); chK[flag]=1;}
				else {alpha[flag]=(vP.Dot(vD)-vK.Dot(vD))/(vK.Dot(vD)+vP.Dot(vD)); chK[flag]=-1;}

							/// ... ///

								/// Mkk ,Mpipi!!! ///
								//TLorentzVector P1,P2,P1P2;
								//Double_t pxKa,pyKa,pzKa,pxPi,pyPi,pzPi;

								P1.SetXYZM(pxPi,pyPi,pzPi,mass_kaon);
								P2.SetXYZM(pxKa,pyKa,pzKa,mass_kaon);
								P1P2 = P1 + P2;
								Mkk[flag]=P1P2.Mag();
								
								P1.SetXYZM(pxPi,pyPi,pzPi,mass_pion);
								P2.SetXYZM(pxKa,pyKa,pzKa,mass_pion);
								P1P2 = P1 + P2;
								Mpipi[flag]=P1P2.Mag();
										/// ... ///

								/// cosK ///
								TLorentzVector PD,PK1;
								PD.SetXYZM(D0pm[ff]*sin(D0th[ff])*cos(D0ph[ff]),D0pm[ff]*sin(D0th[ff])*sin(D0ph[ff]),D0pm[ff]*cos(D0th[ff]),mass_dzero);
								PK1.SetXYZM(pxKa,pyKa,pzKa,mass_kaon);
								PK1.Boost(-PD.BoostVector());
								cosK[flag]=cos(PD.Vect().Angle(PK1.Vect()));
								/// ... ///

								/// d ///
								d[flag]=fabs(mass[flag]-mass_dzero);
								/// ... ///

								/// Dedx ///

								nhPi[flag]=Trk_dedxctdnh[Td0pi[ff]-1];
								nhKa[flag]=Trk_dedxctdnh[Td0ka[ff]-1];
								dedxPi[flag]=Trk_dedxctdcr[Td0pi[ff]-1];
								dedxKa[flag]=Trk_dedxctdcr[Td0ka[ff]-1];
								pPi[flag]=fabs(D0pipm[ff]);
								pKa[flag]=fabs(D0kapm[ff]);
								/// ... ///

TLorentzVector P1,P2,P3,P1P2,P2P3,P3P1,P1P2P3;


		/// Tag and untag !!! ///
tag[flag]=0;
kaon[flag]=0;
pion[flag]=0;
	for(ss=0;ss<Nchds1;ss++)
	{
			//cout << Ds1ms[ss] <<endl;
		if(Td0ka[ff]==Tds1ka[ss]&&Td0pi[ff]==Tds1pi[ss])
		{
		  if(Trk_charge[Td0ka[ff]-1]==-Trk_charge[Td0pi[ff]-1]&&Trk_charge[Td0ka[ff]-1]==-Trk_charge[Tds1ps[ss]-1])
			{
				if((Ds1ms[ss])<0.148&&(Ds1ms[ss])>0.143&&sqrt(pow(Trk_px[Tds1ps[ss]-1],2)+pow(Trk_py[Tds1ps[ss]-1],2))>0.2)tag[flag]=1;

			}
				//if((Ds1ms[ss]-D0ms[ff])<0.148&&(Ds1ms[ss]-D0ms[ff])>0.143){}
		}
	}


				for(ss=0;ss<Trk_ntracks;ss++)
 					{
					if(ss!=(Td0ka[ff]-1)&&ss!=(Td0pi[ff]-1)&&(Trk_layouter[ss]-Trk_layinner[ss])>2&&Trk_charge[Td0ka[ff]-1]!=Trk_charge[ss])
						{
						P1.SetXYZM(pxPi,pyPi,pzPi,mass_kaon);
						P2.SetXYZM(pxKa,pyKa,pzKa,mass_kaon);
						P3.SetXYZM(Trk_px[ss],Trk_py[ss],Trk_pz[ss],mass_pion);
						P1P2=P1+P2;
						P1P2P3=P1+P2+P3;
// 						P1P2P3=P1P2P3-P1P2;
						if((P1P2P3.Mag()-P1P2.Mag())<0.148&&(P1P2P3.Mag()-P1P2.Mag())>0.143&&sqrt(pow(Trk_px[ss],2)+pow(Trk_py[ss],2))>0.2)kaon[flag]=1;

					

						P1.SetXYZM(pxPi,pyPi,pzPi,mass_pion);
						P2.SetXYZM(pxKa,pyKa,pzKa,mass_pion);
						P3.SetXYZM(Trk_px[ss],Trk_py[ss],Trk_pz[ss],mass_pion);
						P1P2=P1+P2;
						P1P2P3=P1+P2+P3;
// 						P1P2P3=P1P2P3-P1P2;
						if((P1P2P3.Mag()-P1P2.Mag())<0.148&&(P1P2P3.Mag()-P1P2.Mag())>0.143&&sqrt(pow(Trk_px[ss],2)+pow(Trk_py[ss],2))>0.2)pion[flag]=1;

						}
 					}

		/// ... ///


/*
decays[flag]=-10;
m[flag]=0;
m1[flag]=0;
if((Mcmatquality[Td0ka[ff]-1]+Mcmatquality[Td0pi[ff]-1])>-5)m[flag]=1;
if((Mcmatquality[Td0ka[ff]-1]+Mcmatquality[Td0pi[ff]-1])>0)m1[flag]=1;
// if((Mcmatquality[Td0ka[ff]-1]+Mcmatquality[Td0pi[ff]-1])>-5)decays[flag]=-9;
// if((Mcmatquality[Td0ka[ff]-1]+Mcmatquality[Td0pi[ff]-1])>-1)decays[flag]=-8;
// if((Mcmatquality[Td0ka[ff]-1]+Mcmatquality[Td0pi[ff]-1])>1)decays[flag]=-7;

kk[flag]=0;
pp[flag]=0;

for(Int_t f=0;f<Fmck_nstor;f++)
	{
		if(Fmck_prt[f]==66||Fmck_prt[f]==67)
		{
			Int_t n_kaon=0;
			Int_t n_pion=0;
			Int_t n_x=0;
			for(Int_t s=0;s<Fmck_nstor;s++)
			{
				if(Fmck_daug[s]==Fmck_id[f])
				{
					if(Fmck_prt[s]==54||Fmck_prt[s]==55){n_pion++;}
					else if(Fmck_prt[s]==58||Fmck_prt[s]==59){n_kaon++;}
					else{n_x++;}
				}
			}
		if(n_kaon==2&&n_pion==0&&n_x==0)kk[flag]=1;
		if(n_kaon==0&&n_pion==2&&n_x==0)pp[flag]=1;
		}
	}
*/

/*
if((Mcmatquality[Td0ka[ff]-1]+ Mcmatquality[Td0pi[ff]-1])>-5)
{
	Int_t id_kaon=Mcmatfmckin_id[Td0ka[ff]-1];
	Int_t  id_pion=Mcmatfmckin_id[Td0pi[ff]-1];
	Int_t type_kaon=Mcmattype[Td0ka[ff]-1];
	Int_t type_pion=Mcmattype[Td0pi[ff]-1];

	Int_t type_moth_kaon_1 = (int)Mcmatmother_prt[Td0ka[ff]-1];
	Int_t type_moth_pion_1 = (int)Mcmatmother_prt[Td0pi[ff]-1];
	Int_t id_moth_kaon_1 = Mcmatmother[Td0ka[ff]-1];
	Int_t id_moth_pion_1 = Mcmatmother[Td0pi[ff]-1];

	Int_t type_moth_kaon_2;
	Int_t type_moth_pion_2;
	Int_t id_moth_kaon_2;
	Int_t id_moth_pion_2;

	Int_t nx_kaon=0,nx_pion=0;
	Int_t  id_brothers_kaon[50];
	Int_t  id_brothers_pion[50];
	Int_t  type_brothers_kaon[50];
	Int_t  type_brothers_pion[50];

*/

/*
	for(Int_t f=0;f<Fmck_nstor;f++)

	{	
		//if(Fmck_prt[f]==116||Fmck_prt[f]==117||Fmck_prt[f]==164||Fmck_prt[f]==165)cout <<Fmck_prt[f] << endl; 

		if(id_moth_kaon_1==Fmck_daug[f]&&(Fmck_id[f]!=id_kaon))
		{

			 id_brothers_kaon[nx_kaon]=Fmck_id[f];
			 type_brothers_kaon[nx_kaon]=Fmck_prt[f];
			 nx_kaon++;
		}
		if(id_moth_pion_1==Fmck_daug[f]&&Fmck_id[f]!=id_pion)
		{
			id_brothers_pion[nx_pion]=Fmck_id[f];
			type_brothers_pion[nx_pion]=Fmck_prt[f];
			nx_pion++;
		}
	}


	for(Int_t f=0;f<Fmck_nstor;f++)
	{
		if(id_moth_kaon_1==Fmck_id[f])
		{
			id_moth_kaon_2 = Fmck_daug[f];
			for(Int_t s=0;s<Fmck_nstor;s++)
				{
					if(Fmck_id[s]==id_moth_kaon_2) type_moth_kaon_2 = Fmck_prt[s];
				}
		}
		if(id_moth_pion_1==Fmck_id[f])
		{
			id_moth_pion_2 = Fmck_daug[f];
			for(Int_t s=0;s<Fmck_nstor;s++)
				{
					if(Fmck_id[s]==id_moth_pion_2)  type_moth_pion_2 =Fmck_prt[s];
				}
		}
	}
*/

/*
 ///0: D0-> K Pi
if(id_moth_kaon_1==id_moth_pion_1&&(type_moth_kaon_1==66||type_moth_kaon_1==67)&&(type_kaon==58||type_kaon==59)&& (type_pion==54||type_pion==55)&&(nx_pion==1&&id_brothers_kaon[0]==id_pion&&id_brothers_pion[0]==id_kaon&&nx_kaon==1))decays[flag]=0;
///1: D0-> K Pi  W mass
 if(id_moth_kaon_1==id_moth_pion_1&&(type_moth_kaon_1==66||type_moth_kaon_1==67)&&(type_kaon==54||type_kaon==55)&&(type_pion==58||type_pion==59)&&(nx_pion==1&&id_brothers_kaon[0]==id_pion&&id_brothers_pion[0]==id_kaon&&nx_kaon==1))decays[flag]=1;

/// 10: D0 -> PiPi
if(id_moth_kaon_1==id_moth_pion_1&&(type_moth_kaon_1==66||type_moth_kaon_1==67)&&(type_kaon==54||type_kaon==55)&& (type_pion==54||type_pion==55)&&(nx_pion==1&&id_brothers_kaon[0]==id_pion&&id_brothers_pion[0]==id_kaon&&nx_kaon==1))decays[flag]=10;

/// 12: D0 -> KK
if(id_moth_kaon_1==id_moth_pion_1&&(type_moth_kaon_1==66||type_moth_kaon_1==67)&&(type_kaon==58||type_kaon==59)&& (type_pion==58||type_pion==59)&&(nx_pion==1&&id_brothers_kaon[0]==id_pion&&id_brothers_pion[0]==id_kaon&&nx_kaon==1))decays[flag]=12;

/// 4: D0 -> K Lepton Neutrino
if(id_moth_kaon_1==id_moth_pion_1&&(type_moth_kaon_1==66||type_moth_kaon_1==67)&&(type_kaon==58||type_kaon==59)&& (type_pion==23||type_pion==24)&&(nx_pion==2&&nx_kaon==2))
		{
			for(Int_t j=0;j<nx_kaon;j++)
			{
				if(type_brothers_kaon[j]==17||type_brothers_kaon[j]==18)decays[flag]=4;
			}
		}
if(id_moth_kaon_1==id_moth_pion_1&&(type_moth_kaon_1==66||type_moth_kaon_1==67)&&(type_kaon==23||type_kaon==24)&& (type_pion==58||type_pion==59)&&(nx_pion==2&&nx_kaon==2))
		{
			for(Int_t j=0;j<nx_kaon;j++)
			{
				if(type_brothers_kaon[j]==17||type_brothers_kaon[j]==18)decays[flag]=4;
			}
		}
if(id_moth_kaon_1==id_moth_pion_1&&(type_moth_kaon_1==66||type_moth_kaon_1==67)&&(type_kaon==58||type_kaon==59)&& (type_pion==25||type_pion==26)&&(nx_pion==2&&nx_kaon==2))
		{
			for(Int_t j=0;j<nx_kaon;j++)
			{
				if(type_brothers_kaon[j]==19||type_brothers_kaon[j]==20)decays[flag]=4;
			}
		}
if(id_moth_kaon_1==id_moth_pion_1&&(type_moth_kaon_1==66||type_moth_kaon_1==67)&&(type_kaon==25||type_kaon==26)&& (type_pion==58||type_pion==59)&&(nx_pion==2&&nx_kaon==2))
		{
			for(Int_t j=0;j<nx_kaon;j++)
			{
				if(type_brothers_kaon[j]==19||type_brothers_kaon[j]==20)decays[flag]=4;
			}
		}
/// 11: D0 -> Pi Lepton Neutrino
if(id_moth_kaon_1==id_moth_pion_1&&(type_moth_kaon_1==66||type_moth_kaon_1==67)&&(type_kaon==54||type_kaon==55)&& (type_pion==23||type_pion==24)&&(nx_pion==2&&nx_kaon==2))
		{
			for(Int_t j=0;j<nx_kaon;j++)
			{
				if(type_brothers_kaon[j]==17||type_brothers_kaon[j]==18)decays[flag]=11;
			}
		}
if(id_moth_kaon_1==id_moth_pion_1&&(type_moth_kaon_1==66||type_moth_kaon_1==67)&&(type_kaon==23||type_kaon==24)&& (type_pion==54||type_pion==55)&&(nx_pion==2&&nx_kaon==2))
		{
			for(Int_t j=0;j<nx_kaon;j++)
			{
				if(type_brothers_kaon[j]==17||type_brothers_kaon[j]==18)decays[flag]=11;
			}
		}
if(id_moth_kaon_1==id_moth_pion_1&&(type_moth_kaon_1==66||type_moth_kaon_1==67)&&(type_kaon==54||type_kaon==55)&& (type_pion==25||type_pion==26)&&(nx_pion==2&&nx_kaon==2))
		{
			for(Int_t j=0;j<nx_kaon;j++)
			{
				if(type_brothers_kaon[j]==19||type_brothers_kaon[j]==20)decays[flag]=11;
			}
		}
if(id_moth_kaon_1==id_moth_pion_1&&(type_moth_kaon_1==66||type_moth_kaon_1==67)&&(type_kaon==25||type_kaon==26)&& (type_pion==54||type_pion==55)&&(nx_pion==2&&nx_kaon==2))
		{
			for(Int_t j=0;j<nx_kaon;j++)
			{
				if(type_brothers_kaon[j]==19||type_brothers_kaon[j]==20)decays[flag]=11;
			}
		}

/// 5: D0 -> K*(892) Lepton Neutrino
if((type_moth_pion_1==146 ||type_moth_pion_1==147)&&(type_pion==54||type_pion==55||type_pion==58||type_pion==59)&& (type_kaon==23||type_kaon==24||type_kaon==25||type_kaon==26)&&(nx_kaon==2&&nx_pion==1) && id_moth_pion_2==id_moth_kaon_1 &&(type_moth_pion_2 == 66 ||type_moth_pion_2 == 67) )
		{	
// 				printf("%d %d %d\n",type_moth_kaon_2,type_moth_kaon_1,type_kaon);
// 				printf("%d %d %d\n",type_moth_pion_2,type_moth_pion_1,type_pion);
// 				printf("%le\n",mass[flag]);
				Int_t neutrino=0;
				Int_t lepton=0;
				Int_t x=0;
		        	for(Int_t j=0;j<Fmck_nstor;j++)
			{	
				if(id_moth_pion_2==Fmck_daug[j])
				{
					if((Fmck_prt[j]==23||Fmck_prt[j]==24||Fmck_prt[j]==25||Fmck_prt[j]==26)) lepton++;
					else if((Fmck_prt[j]==17||Fmck_prt[j]==18||Fmck_prt[j]==19||Fmck_prt[j]==20)) neutrino++;
					else x++;
				}
			}
                     
			if(neutrino==1&&lepton==1&&x==1)decays[flag]=5;
		}

if((type_moth_kaon_1==146 ||type_moth_kaon_1==147)&&(type_kaon==54||type_kaon==55||type_kaon==58||type_kaon==59)&& (type_pion==23||type_pion==24||type_pion==25||type_pion==26)&&(nx_kaon==1&&nx_pion==2) && id_moth_kaon_2==id_moth_pion_1 &&(type_moth_kaon_2 == 66 ||type_moth_kaon_2 == 67) )
		{	
// 				printf("%d %d %d\n",type_moth_kaon_2,type_moth_kaon_1,type_kaon);
// 				printf("%d %d %d\n",type_moth_pion_2,type_moth_pion_1,type_pion);
// 				printf("%le\n",mass[flag]);
				Int_t neutrino=0;
				Int_t lepton=0;
				Int_t x=0;
		        	for(Int_t j=0;j<Fmck_nstor;j++)
			{
				if(id_moth_kaon_2==Fmck_daug[j])
				{
					if((Fmck_prt[j]==23||Fmck_prt[j]==24||Fmck_prt[j]==25||Fmck_prt[j]==26)) lepton++;
					else if((Fmck_prt[j]==17||Fmck_prt[j]==18||Fmck_prt[j]==19||Fmck_prt[j]==20)) neutrino++;
					else x++;
				}
			}
        
			if(neutrino==1&&lepton==1&&x==1)decays[flag]=5;
		}
/// 6: D0 -> K- pi0 Electron Neutrino
if(id_moth_kaon_1==id_moth_pion_1&&(type_moth_kaon_1==66||type_moth_kaon_1==67)&&(type_kaon==58||type_kaon==59||type_kaon==23||type_kaon==24)&& (type_pion==23||type_pion==24||type_pion==58||type_pion==59)&&(nx_pion==3&&nx_kaon==3))
		{
//			cout << "Good man 2!!!" << endl;
			Int_t pion0=0;
			Int_t neutrino=0;
			Int_t x=0;
			for(Int_t j=0;j<nx_kaon;j++)
			{
				if(type_brothers_kaon[j]==17||type_brothers_kaon[j]==18)neutrino++;
				else if(type_brothers_kaon[j]==56)pion0++;
				else x++;
			}
			if(x==1&&neutrino==1&&pion0==1)decays[flag]=6;
		}

/// 7: D0 -> K0 pi+ Electron Neutrino
if(id_moth_kaon_1==id_moth_pion_1&&(type_moth_kaon_1==66||type_moth_kaon_1==67)&&(type_kaon==54||type_kaon==55||type_kaon==23||type_kaon==24)&& (type_pion==23||type_pion==24||type_pion==54||type_pion==55)&&(nx_pion==3&&nx_kaon==3))
		{
//  			cout << "Good man 2!!!" << endl;
			Int_t kaon0=0;
			Int_t neutrino=0;
			Int_t x=0;
			for(Int_t j=0;j<nx_kaon;j++)
			{
				if(type_brothers_kaon[j]==17||type_brothers_kaon[j]==18)neutrino++;
				else if(type_brothers_kaon[j]==60||type_brothers_kaon[j]==61)kaon0++;
				else x++;
			}
			if(x==1&&neutrino==1&&kaon0==1)decays[flag]=7;
		}

/// 8: D+ -> K- pi+ pi+
if(id_moth_kaon_1==id_moth_pion_1&&(type_moth_kaon_1==64||type_moth_kaon_1==65)&&(type_kaon==58||type_kaon==59)&& (type_pion==54||type_pion==55)&&(nx_pion==2&&nx_kaon==2))
  {
		Int_t n_pion=0;
		Int_t x=0;
		for(Int_t j=0;j<nx_kaon;j++)
			{
				if(type_brothers_kaon[j]==54||type_brothers_kaon[j]==55)n_pion++;
				else x++;
			}
		if(x==0&&n_pion==2)decays[flag]=8;
  }

  if(id_moth_kaon_1==id_moth_pion_1&&(type_moth_kaon_1==64||type_moth_kaon_1==65)&&(type_kaon==54||type_kaon==55)&& (type_pion==58||type_pion==59)&&(nx_pion==2&&nx_kaon==2))
  {
		Int_t n_pion=0;
		Int_t n_kaon=0;
		Int_t x=0;
		for(Int_t j=0;j<nx_kaon;j++)
			{
				if(type_brothers_kaon[j]==54||type_brothers_kaon[j]==55)n_pion++;
				else if(type_brothers_kaon[j]==58||type_brothers_kaon[j]==59)n_kaon++;
				else x++;
			}
		if(x==0&&n_pion==1&&n_kaon==1)decays[flag]=8;
  }
   
  for(Int_t s=0;s<Fmck_nstor;s++)
	{
		if(Fmck_prt[s]==148||Fmck_prt[s]==149)
		{
		for(Int_t r=0;r<Fmck_nstor;r++)
		  {
		    if(Fmck_daug[s]==Fmck_id[r]&&(Fmck_prt[r]==64||Fmck_prt[r]==65))
		      {
			if(id_moth_kaon_1==id_moth_pion_1&&(id_moth_kaon_1==Fmck_id[s])&&(type_kaon==58||type_kaon==59)&& (type_pion==54||type_pion==55)&&(nx_pion==1&&nx_kaon==1))decays[flag]=8;
			if(id_moth_kaon_1==id_moth_pion_1&&(id_moth_kaon_1==Fmck_id[s])&&(type_kaon==54||type_kaon==55)&& (type_pion==58||type_pion==59)&&(nx_pion==1&&nx_kaon==1))decays[flag]=8;
			if(id_moth_pion_1==Fmck_id[r]&&(id_moth_kaon_1==Fmck_id[s])&&(type_kaon==58||type_kaon==59)&& (type_pion==54||type_pion==55)&&(nx_pion==1&&nx_kaon==1))decays[flag]=8;
			if(id_moth_pion_1==Fmck_id[s]&&(id_moth_kaon_1==Fmck_id[r])&&(type_kaon==54||type_kaon==55)&& (type_pion==58||type_pion==59)&&(nx_pion==1&&nx_kaon==1))decays[flag]=8;
		      }
		  }
		}
	}
*/
/*
/// 2: D0 -> K- pi+ pi0
if(id_moth_kaon_1==id_moth_pion_1&&(type_moth_kaon_1==66||type_moth_kaon_1==67)&&(type_kaon==58||type_kaon==59)&& (type_pion==54||type_pion==55)&&(nx_pion==2&&nx_kaon==2))
  {
		Int_t pion0=0;
		Int_t x=0;
		for(Int_t j=0;j<nx_kaon;j++)
			{
				if(type_brothers_kaon[j]==56)pion0++;
				else x++;
			}
		if(x==1&&pion0==1)decays[flag]=2;
  }


for(Int_t s=0;s<Fmck_nstor;s++)
	{
		if(Fmck_prt[s]==146||Fmck_prt[s]==147)
		{
		for(Int_t r=0;r<Fmck_nstor;r++)
		  {
		    if(Fmck_daug[s]==Fmck_id[r]&&(Fmck_prt[r]==66||Fmck_prt[r]==67))
		      {
			if(id_moth_pion_1==Fmck_id[r]&&(id_moth_kaon_1==Fmck_id[s])&&(type_kaon==58||type_kaon==59)&& (type_pion==54||type_pion==55)&&(nx_pion==1&&nx_kaon==1))decays[flag]=2;
			//cout << "da!!!" << endl;
		      }
		  }
		}

		if(Fmck_prt[s]==148||Fmck_prt[s]==149)
		{
		for(Int_t r=0;r<Fmck_nstor;r++)
		  {
		    if(Fmck_daug[s]==Fmck_id[r]&&(Fmck_prt[r]==66||Fmck_prt[r]==67))
		      {
			if(id_moth_pion_1==Fmck_id[s]&&(id_moth_kaon_1==Fmck_id[s])&&(type_kaon==58||type_kaon==59)&& (type_pion==54||type_pion==55)&&(nx_pion==1&&nx_kaon==1))decays[flag]=2;
			//cout << "da0!!!" << endl;
		      }
		  }
		}

		if(Fmck_prt[s]==76||Fmck_prt[s]==77)
		{
		for(Int_t r=0;r<Fmck_nstor;r++)
		  {
		    if(Fmck_daug[s]==Fmck_id[r]&&(Fmck_prt[r]==66||Fmck_prt[r]==67))
		      {
			if(id_moth_pion_1==Fmck_id[s]&&(id_moth_kaon_1==Fmck_id[r])&&(type_kaon==58||type_kaon==59)&& (type_pion==54||type_pion==55)&&(nx_pion==1&&nx_kaon==1))decays[flag]=2;
			//cout << "da1!!!" << endl;
		      }
		  }
		}
	}
*/



/// 3: D0 -> K- pi+ pi0 (wrong mass)
/*
if(id_moth_kaon_1==id_moth_pion_1&&(type_moth_kaon_1==66||type_moth_kaon_1==67)&&(type_kaon==54||type_kaon==55)&& (type_pion==58||type_pion==59)&&(nx_pion==2&&nx_kaon==2))
  {
		Int_t pion0=0;
		Int_t x=0;
		for(Int_t j=0;j<nx_kaon;j++)
			{
				if(type_brothers_kaon[j]==56)pion0++;
				else x++;
			}
		if(x==1&&pion0==1)decays[flag]=3;
  }

for(Int_t s=0;s<Fmck_nstor;s++)
	{
		if(Fmck_prt[s]==146||Fmck_prt[s]==147)
		{
		for(Int_t r=0;r<Fmck_nstor;r++)
		  {
		    if(Fmck_daug[s]==Fmck_id[r]&&(Fmck_prt[r]==66||Fmck_prt[r]==67))
		      {
			//cout << "da!!!" << endl;
			if(id_moth_pion_1==Fmck_id[s]&&(id_moth_kaon_1==Fmck_id[r])&&(type_kaon==54||type_kaon==55)&& (type_pion==58||type_pion==59)&&(nx_pion==1&&nx_kaon==1))decays[flag]=3;
		      }
		  }
		}

		if(Fmck_prt[s]==148||Fmck_prt[s]==149)
		{
		for(Int_t r=0;r<Fmck_nstor;r++)
		  {
		    if(Fmck_daug[s]==Fmck_id[r]&&(Fmck_prt[r]==66||Fmck_prt[r]==67))
		      {
			if(id_moth_pion_1==Fmck_id[s]&&(id_moth_kaon_1==Fmck_id[s])&&(type_kaon==54||type_kaon==55)&& (type_pion==58||type_pion==59)&&(nx_pion==1&&nx_kaon==1))decays[flag]=3;
			//cout << "da0!!!" << endl;
		      }
		  }
		}

		if(Fmck_prt[s]==76||Fmck_prt[s]==77)
		{
		for(Int_t r=0;r<Fmck_nstor;r++)
		  {
		    if(Fmck_daug[s]==Fmck_id[r]&&(Fmck_prt[r]==66||Fmck_prt[r]==67))
		      {
			//cout << "da1!!!" << endl;
			if(id_moth_pion_1==Fmck_id[r]&&(id_moth_kaon_1==Fmck_id[s])&&(type_kaon==54||type_kaon==55)&& (type_pion==58||type_pion==59)&&(nx_pion==1&&nx_kaon==1))decays[flag]=3;
		      }
		  }
		}
	}
*/
/*
/// 13: D0 -> pi+ pi- pi0

if(id_moth_kaon_1==id_moth_pion_1&&(type_moth_kaon_1==66||type_moth_kaon_1==67)&&(type_kaon==54||type_kaon==55)&& (type_pion==54||type_pion==55)&&(nx_pion==2&&nx_kaon==2))
  {
		Int_t pion0=0;
		Int_t x=0;
		for(Int_t j=0;j<nx_kaon;j++)
			{
				if(type_brothers_kaon[j]==56)pion0++;
				else x++;
			}
		if(x==1&&pion0==1)decays[flag]=13;
  }

for(Int_t s=0;s<Fmck_nstor;s++)
	{
		if(Fmck_prt[s]==76||Fmck_prt[s]==77)
		{
		for(Int_t r=0;r<Fmck_nstor;r++)
		  {
		    if(Fmck_daug[s]==Fmck_id[r]&&(Fmck_prt[r]==66||Fmck_prt[r]==67))
		      {
			//if(decays[flag]<0)cout << "da!!!" << endl;
			if(id_moth_pion_1==Fmck_id[s]&&(id_moth_kaon_1==Fmck_id[r])&&(type_kaon==54||type_kaon==55)&& (type_pion==54||type_pion==55)&&(nx_pion==1&&nx_kaon==1))decays[flag]=13;
			if(id_moth_pion_1==Fmck_id[r]&&(id_moth_kaon_1==Fmck_id[s])&&(type_kaon==54||type_kaon==55)&& (type_pion==54||type_pion==55)&&(nx_pion==1&&nx_kaon==1))decays[flag]=13;
		      }
		  }
		}
        }

for(Int_t s=0;s<Fmck_nstor;s++)
	{
		if(Fmck_prt[s]==78)
		{
		for(Int_t r=0;r<Fmck_nstor;r++)
		  {
		    if(Fmck_daug[s]==Fmck_id[r]&&(Fmck_prt[r]==66||Fmck_prt[r]==67))
		      {
			//if(decays[flag]<0)cout << "da!!!" << endl;
			if(id_moth_pion_1==Fmck_id[s]&&(id_moth_kaon_1==Fmck_id[s])&&(type_kaon==54||type_kaon==55)&& (type_pion==54||type_pion==55)&&(nx_pion==1&&nx_kaon==1))decays[flag]=13;
		      }
		  }
		}
        }

for(Int_t s=0;s<Fmck_nstor;s++)
	{
		if(Fmck_prt[s]==116||Fmck_prt[s]==117)
		{
		for(Int_t r=0;r<Fmck_nstor;r++)
		  {
		    if(Fmck_daug[s]==Fmck_id[r]&&(Fmck_prt[r]==66||Fmck_prt[r]==67))
		      {
			//if(decays[flag]<0)cout << "da!!!" << endl;
			if(id_moth_pion_1==Fmck_id[s]&&(id_moth_kaon_1==Fmck_id[r])&&(type_kaon==54||type_kaon==55)&& (type_pion==54||type_pion==55)&&(nx_pion==1&&nx_kaon==1))decays[flag]=13;
			if(id_moth_pion_1==Fmck_id[r]&&(id_moth_kaon_1==Fmck_id[s])&&(type_kaon==54||type_kaon==55)&& (type_pion==54||type_pion==55)&&(nx_pion==1&&nx_kaon==1))decays[flag]=13;
		      }
		  }
		}
        }

for(Int_t s=0;s<Fmck_nstor;s++)
	{
		if(Fmck_prt[s]==118)
		{
		for(Int_t r=0;r<Fmck_nstor;r++)
		  {
		    if(Fmck_daug[s]==Fmck_id[r]&&(Fmck_prt[r]==66||Fmck_prt[r]==67))
		      {
			//if(decays[flag]<0)cout << "da!!!" << endl;
			if(id_moth_pion_1==Fmck_id[s]&&(id_moth_kaon_1==Fmck_id[s])&&(type_kaon==54||type_kaon==55)&& (type_pion==54||type_pion==55)&&(nx_pion==1&&nx_kaon==1))decays[flag]=13;
		      }
		  }
		}
        }
*/
/*
if(id_moth_pion_2==id_moth_kaon_2&&id_moth_pion_1!=id_moth_kaon_1)decays[flag]=-5;
	}

kapi[flag]=0;
pika[flag]=0;
kaka[flag]=0;
pipi[flag]=0;

kapiMATCH[flag]=0;
kakaMATCH[flag]=0;
pipiMATCH[flag]=0;
valKa[flag]=-100;
valPi[flag]=-100;
ref_valKa[flag]=-100;
ref_valPi[flag]=-100;

for(Int_t f=0;f<Fmck_nstor;f++)
	{
		if(Fmck_prt[f]==66||Fmck_prt[f]==67)
		{
			Int_t kaon=0,pion=0,x=0;
			TVector3 truePi,trueKa,trueD0;
			TVector3 recoPi,recoKa,recoD0;
			recoPi.SetXYZ(pxPi,pyPi,pzPi);
			recoKa.SetXYZ(pxKa,pyKa,pzKa);
// 			recoD0=recoPi+recoKa;
			
			for(Int_t s=0;s<Fmck_nstor;s++)
			{
				if(Fmck_daug[s]==Fmck_id[f])
				{
					if(Fmck_prt[s]==54||Fmck_prt[s]==55)
					{
						if(pion==0)truePi.SetXYZ(Fmck_px[s],Fmck_py[s],Fmck_pz[s]);
						if(pion==1)trueKa.SetXYZ(Fmck_px[s],Fmck_py[s],Fmck_pz[s]);
						pion++;
					}
					else if(Fmck_prt[s]==58||Fmck_prt[s]==59)
					{
						if(kaon==0)trueKa.SetXYZ(Fmck_px[s],Fmck_py[s],Fmck_pz[s]);
						if(kaon==1)truePi.SetXYZ(Fmck_px[s],Fmck_py[s],Fmck_pz[s]);
						kaon++;
					}
					else x++;
				}
			}
		if(kaon==1&&pion==1&&x==0)
		{
			if(kapiMATCH[flag]>0)
			{
				valKa[flag]= - (trueKa-recoKa).Mag()/(trueKa+recoKa).Mag();
				valPi[flag]= - (truePi-recoPi).Mag()/(truePi+recoPi).Mag();
				ref_valKa[flag]= - (trueKa-recoPi).Mag()/(trueKa+recoPi).Mag();
				ref_valPi[flag]= - (truePi-recoKa).Mag()/(truePi+recoKa).Mag();
			}
			else
			{
				valKa[flag]=  (trueKa-recoKa).Mag()/(trueKa+recoKa).Mag();
				valPi[flag]=  (truePi-recoPi).Mag()/(truePi+recoPi).Mag();
				ref_valKa[flag]=  (trueKa-recoPi).Mag()/(trueKa+recoPi).Mag();
				ref_valPi[flag]=  (truePi-recoKa).Mag()/(truePi+recoKa).Mag();
			}
			kapiMATCH[flag]++;
		}
		if(kaon==2&&pion==0&&x==0)
		{
			if(kakaMATCH[flag]>0)
			{
				valKa[flag]= - (trueKa-recoKa).Mag()/(trueKa+recoKa).Mag();
				valPi[flag]= - (truePi-recoPi).Mag()/(truePi+recoPi).Mag();
				ref_valKa[flag]= - (trueKa-recoPi).Mag()/(trueKa+recoPi).Mag();
				ref_valPi[flag]= - (truePi-recoKa).Mag()/(truePi+recoKa).Mag();
			}
			else
			{
				valKa[flag]=  (trueKa-recoKa).Mag()/(trueKa+recoKa).Mag();
				valPi[flag]=  (truePi-recoPi).Mag()/(truePi+recoPi).Mag();
				ref_valKa[flag]=  (trueKa-recoPi).Mag()/(trueKa+recoPi).Mag();
				ref_valPi[flag]=  (truePi-recoKa).Mag()/(truePi+recoKa).Mag();
			}
			kakaMATCH[flag]++;
		}
		if(kaon==0&&pion==2&&x==0)
		{
			if(pipiMATCH[flag]>0)
			{
				valKa[flag]= - (trueKa-recoKa).Mag()/(trueKa+recoKa).Mag();
				valPi[flag]= - (truePi-recoPi).Mag()/(truePi+recoPi).Mag();
				ref_valKa[flag]= - (trueKa-recoPi).Mag()/(trueKa+recoPi).Mag();
				ref_valPi[flag]= - (truePi-recoKa).Mag()/(truePi+recoKa).Mag();
			}
			else
			{
				valKa[flag]=  (trueKa-recoKa).Mag()/(trueKa+recoKa).Mag();
				valPi[flag]=  (truePi-recoPi).Mag()/(truePi+recoPi).Mag();
				ref_valKa[flag]=  (trueKa-recoPi).Mag()/(trueKa+recoPi).Mag();
				ref_valPi[flag]=  (truePi-recoKa).Mag()/(truePi+recoKa).Mag();
			}
			pipiMATCH[flag]++;
		}
		}
        }
*/
/*
if(kapiMATCH[flag]>0&&valKa[flag]>-0.015&&valKa[flag]<0.015&&valPi[flag]>-0.015&&valPi[flag]<0.015)kapi[flag]=1;
if(kapiMATCH[flag]>0&&ref_valKa[flag]>-0.015&&ref_valKa[flag]<0.015&&ref_valPi[flag]>-0.015&&ref_valPi[flag]<0.015)pika[flag]=1;
if(pipiMATCH[flag]>0&&((valKa[flag]>-0.015&&valKa[flag]<0.015&&valPi[flag]>-0.015&&valPi[flag]<0.015)||(ref_valKa[flag]>-0.015&&ref_valKa[flag]<0.015&&ref_valPi[flag]>-0.015&&ref_valPi[flag]<0.015)))pipi[flag]=1;
if(kakaMATCH[flag]>0&&((valKa[flag]>-0.015&&valKa[flag]<0.015&&valPi[flag]>-0.015&&valPi[flag]<0.015)||(ref_valKa[flag]>-0.015&&ref_valKa[flag]<0.015&&ref_valPi[flag]>-0.015&&ref_valPi[flag]<0.015)))kaka[flag]=1;


/// Dzero matching !!! ///

TVector3 vD_true;
	vD_true.SetXYZ(1000,1000,1000);
Float_t min_dellta=100;

for(Int_t f=0;f<Fmck_nstor;f++)
	{
		Int_t number_K=0;
		Int_t number_Pi=0;
		Int_t number_X=0;
		
		if(Fmck_prt[f]==66||Fmck_prt[f]==67)
		{
			for(Int_t s=0;s<Fmck_nstor;s++)
			{
				if(Fmck_id[f]==Fmck_daug[s])
				{
					if((Fmck_prt[s]==54||Fmck_prt[s]==55)){number_Pi++;}
					else if((Fmck_prt[s]==58||Fmck_prt[s]==59)){number_K++;}
						else number_X++;
				}
			}
		if(number_X==0&&number_K==1&&number_Pi==1)
			{
				vD_true.SetXYZ(Fmck_px[f],Fmck_py[f],Fmck_pz[f]);
				dellta[flag]=((vD-vD_true).Mag())/((vD+vD_true).Mag());
				if(dellta[flag]<min_dellta)min_dellta=dellta[flag];
			}

		}
	dellta[flag]=min_dellta;
	}
*/
 /// KK
/*
min_dellta=100;

for(Int_t f=0;f<Fmck_nstor;f++)
	{
		Int_t number_K=0;
		Int_t number_Pi=0;
		Int_t number_X=0;
		
		if(Fmck_prt[f]==66||Fmck_prt[f]==67)
		{
			for(Int_t s=0;s<Fmck_nstor;s++)
			{
				if(Fmck_id[f]==Fmck_daug[s])
				{
					if((Fmck_prt[s]==54||Fmck_prt[s]==55)){number_Pi++;}
					else if((Fmck_prt[s]==58||Fmck_prt[s]==59)){number_K++;}
						else number_X++;
				}
			}
		if(number_X==0&&number_K==2&&number_Pi==0)
			{
				vD_true.SetXYZ(Fmck_px[f],Fmck_py[f],Fmck_pz[f]);
				dKk[flag]=((vD-vD_true).Mag())/((vD+vD_true).Mag());
				if(dKk[flag]<min_dellta)min_dellta=dKk[flag];
			}

		}
	dKk[flag]=min_dellta;
	}
*/
 /// PP
/*
min_dellta=100;

for(Int_t f=0;f<Fmck_nstor;f++)
	{
		Int_t number_K=0;
		Int_t number_Pi=0;
		Int_t number_X=0;
		
		if(Fmck_prt[f]==66||Fmck_prt[f]==67)
		{
			for(Int_t s=0;s<Fmck_nstor;s++)
			{
				if(Fmck_id[f]==Fmck_daug[s])
				{
					if((Fmck_prt[s]==54||Fmck_prt[s]==55)){number_Pi++;}
					else if((Fmck_prt[s]==58||Fmck_prt[s]==59)){number_K++;}
						else number_X++;
				}
			}
		if(number_X==0&&number_K==0&&number_Pi==2)
			{
				vD_true.SetXYZ(Fmck_px[f],Fmck_py[f],Fmck_pz[f]);
				dPp[flag]=((vD-vD_true).Mag())/((vD+vD_true).Mag());
				if(dPp[flag]<min_dellta)min_dellta=dPp[flag];
			}

		}
	dPp[flag]=min_dellta;
	}

*/
/// ... ///



 									flag++;
 									}

 				
				if(flag>0) {dzero->TTree::Fill();}
			}



TFile f(outfile,"RECREATE");
dzero->Write();
f.Close();

cout<<"nevents= "<< nevents<<endl;
cout << "Events left:" <<dzero->GetEntries()<< endl;

cout << "Finish!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
}


