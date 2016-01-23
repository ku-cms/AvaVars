// -*- C++ -*-
//
// Package:    UserCode/AnaVars
// Class:      AnaVars
// 
/**\class AnaVars AnaVars.cc UserCode/AnaVars/plugins/AnaVars.cc

 Description: [one line class summary]

 Implementation:
     [Notes on implementation]
*/
//
// Original Author:  Robert Stringer
//         Created:  Fri, 18 Sep 2015 19:10:16 GMT
//
//


// system include files
#include <memory>

// user include files
#include "FWCore/Framework/interface/Frameworkfwd.h"
#include "FWCore/Framework/interface/EDProducer.h"

#include "FWCore/Framework/interface/Event.h"
#include "FWCore/Framework/interface/MakerMacros.h"

#include "FWCore/ParameterSet/interface/ParameterSet.h"

#include "DataFormats/Math/interface/deltaR.h"
#include "Analysis/VLQAna/interface/JetSelector.h"
#include <TLorentzVector.h>


//
// class declaration
//

class AnaVars : public edm::EDProducer {
   public:
      explicit AnaVars(const edm::ParameterSet&);
      ~AnaVars();

      static void fillDescriptions(edm::ConfigurationDescriptions& descriptions);

   private:
      virtual void beginJob() override;
      virtual void produce(edm::Event&, const edm::EventSetup&) override;
      virtual void endJob() override;
      
      //virtual void beginRun(edm::Run const&, edm::EventSetup const&) override;
      //virtual void endRun(edm::Run const&, edm::EventSetup const&) override;
      //virtual void beginLuminosityBlock(edm::LuminosityBlock const&, edm::EventSetup const&) override;
      //virtual void endLuminosityBlock(edm::LuminosityBlock const&, edm::EventSetup const&) override;

      // ----------member data ---------------------------

//      edm::ParameterSet TJetSelParamssub_             ;
//      edm::ParameterSet TJetSelParamssub2_             ;
//      edm::ParameterSet TJetSelParams_             ;
      edm::ParameterSet TJetSelParams03_           ;
      edm::ParameterSet TJetSelParams03SB0_           ;
/*
      edm::ParameterSet TJetSelParams10_           ;
      edm::ParameterSet TJetSelParams30_           ;
      edm::ParameterSet TJetSelParams0_           ;
      edm::ParameterSet TJetSelParams1_           ;
      edm::ParameterSet TJetSelParams2_           ;
      edm::ParameterSet TJetSelParams3_           ;
*/ 
      edm::ParameterSet HJetSelParams_             ;
      edm::ParameterSet HJetSelParamsSB0_             ;
      edm::ParameterSet HJetSelParamsSB1_             ;
      edm::ParameterSet WJetSelParams_             ;


};

//
// constants, enums and typedefs
//


//
// static data member definitions
//

//
// constructors and destructor
//
AnaVars::AnaVars(const edm::ParameterSet& iConfig) :  
//  TJetSelParamssub_          (iConfig.getParameter<edm::ParameterSet>  ("TJetSelParamssub")),
//  TJetSelParamssub2_          (iConfig.getParameter<edm::ParameterSet>  ("TJetSelParamssub2")),
//  TJetSelParams_          (iConfig.getParameter<edm::ParameterSet>  ("TJetSelParams")),
  TJetSelParams03_          (iConfig.getParameter<edm::ParameterSet>  ("TJetSelParams03")),
  TJetSelParams03SB0_          (iConfig.getParameter<edm::ParameterSet>  ("TJetSelParams03SB0")),
//  TJetSelParams03sub_          (iConfig.getParameter<edm::ParameterSet>  ("TJetSelParams03sub")),
//  TJetSelParams10_          (iConfig.getParameter<edm::ParameterSet>  ("TJetSelParams10")),
//  TJetSelParams30_          (iConfig.getParameter<edm::ParameterSet>  ("TJetSelParams30")),
//  TJetSelParams0_          (iConfig.getParameter<edm::ParameterSet>  ("TJetSelParams0")),
//  TJetSelParams1_          (iConfig.getParameter<edm::ParameterSet>  ("TJetSelParams1")),
//  TJetSelParams2_          (iConfig.getParameter<edm::ParameterSet>  ("TJetSelParams2")),
//  TJetSelParams3_          (iConfig.getParameter<edm::ParameterSet>  ("TJetSelParams3")),
  HJetSelParams_          (iConfig.getParameter<edm::ParameterSet>  ("HJetSelParams")),
  HJetSelParamsSB0_          (iConfig.getParameter<edm::ParameterSet>  ("HJetSelParamsSB0")),
  HJetSelParamsSB1_          (iConfig.getParameter<edm::ParameterSet>  ("HJetSelParamsSB1")),
  WJetSelParams_          (iConfig.getParameter<edm::ParameterSet>  ("WJetSelParams"))

{
   //register your products
/* Examples
   produces<ExampleData2>();

   //if do put with a label
   produces<ExampleData2>("label");
 
   //if you want to put into the Run
   produces<ExampleData2,InRun>();
*/
   //now do what ever other initialization is needed



//   produces<std::vector<unsigned> >("ak4UnmatchedIdx");  
   produces<std::vector<unsigned> >("ak4UnmatchedIdx03");  
//   produces<std::vector<unsigned> >("ak4UnmatchedIdx10");  
//   produces<std::vector<unsigned> >("ak4UnmatchedIdx30");  
//   produces<std::vector<unsigned> >("tjetsIdx");
//   produces<std::vector<unsigned> >("tjetsIdxsub");
//   produces<std::vector<unsigned> >("tjetsIdxsub2");
   produces<std::vector<unsigned> >("tjetsIdx03");
   produces<std::vector<unsigned> >("tjetsIdx03sb0");
//   produces<std::vector<unsigned> >("tjetsIdx03sub");
//   produces<std::vector<unsigned> >("tjetsIdx10");
//   produces<std::vector<unsigned> >("tjetsIdx30");
//   produces<std::vector<unsigned> >("tjetsIdx0");
//   produces<std::vector<unsigned> >("tjetsIdx1");
//   produces<std::vector<unsigned> >("tjetsIdx2");
//   produces<std::vector<unsigned> >("tjetsIdx3");
   produces<std::vector<unsigned> >("hjetsIdx");
   produces<std::vector<unsigned> >("hjetsIdxSB0");
   produces<std::vector<unsigned> >("hjetsIdxSB1");
   produces<std::vector<unsigned> >("wjetsIdx");

}


AnaVars::~AnaVars()
{
 
   // do anything here that needs to be done at desctruction time
   // (e.g. close files, deallocate resources etc.)

}


//
// member functions
//

// ------------ method called to produce the data  ------------
void
AnaVars::produce(edm::Event& iEvent, const edm::EventSetup& iSetup)
{
   using namespace edm;
/* This is an event example
   //Read 'ExampleData' from the Event
   Handle<ExampleData> pIn;
   iEvent.getByLabel("example",pIn);

   //Use the ExampleData to create an ExampleData2 which 
   // is put into the Event
   std::unique_ptr<ExampleData2> pOut(new ExampleData2(*pIn));
   iEvent.put(std::move(pOut));
*/

/* this is an EventSetup example
   //Read SetupData from the SetupRecord in the EventSetup
   ESHandle<SetupData> pSetup;
   iSetup.get<SetupRecord>().get(pSetup);
*/


//	cout << "AnaVars" << endl;

//      edm::Handle<std::vector<float> > mh_jetAK4Pt;
//      edm::Handle<std::vector<float> > mh_jetAK4GenPartonPt;
      edm::Handle<std::vector<float> > mh_jetAK4Eta;
//      edm::Handle<std::vector<float> > mh_jetAK4GenPartonY;
      edm::Handle<std::vector<float> > mh_jetAK4Phi;
//      edm::Handle<std::vector<float> > mh_jetAK4E;
//      edm::Handle<std::vector<float> > mh_jetAK4HadronFlavour;
//      edm::Handle<std::vector<float> > mh_jetAK4CSV;
//      edm::Handle<std::vector<float> > mh_jetAK4Mass;
      edm::Handle<std::vector<unsigned> > mh_jetAK4Good;
//      edm::Handle<double> mh_htak4jets;
//      edm::Handle<double> mh_htak4trigjets;
//      edm::Handle<double> mh_htak8jets;

//      edm::Handle<std::vector<float> > mh_jetAK8Pt;
      edm::Handle<std::vector<float> > mh_jetAK8Eta;
      edm::Handle<std::vector<float> > mh_jetAK8Phi;
//      edm::Handle<std::vector<float> > mh_jetAK8E;
//      edm::Handle<std::vector<float> > mh_jetAK8Mass;
//      edm::Handle<std::vector<float> > mh_jetAK8subjetIndex0;
//      edm::Handle<std::vector<float> > mh_jetAK8subjetIndex1;
//     edm::Handle<std::vector<float> > mh_jetAK8HadronFlavour;
//      edm::Handle<std::vector<float> > mh_jetAK8tau1;
//      edm::Handle<std::vector<float> > mh_jetAK8tau2;
//      edm::Handle<std::vector<float> > mh_jetAK8tau3;
      edm::Handle<std::vector<unsigned> > mh_jetAK8Good;
      edm::Handle<std::vector<float> > mh_jetAK8nSubjets;

//      edm::Handle<std::vector<float> >  mh_jetAK8FilteredMass;
//      edm::Handle<std::vector<float> >  mh_jetAK8TrimmedMass    ;
//     edm::Handle<std::vector<float> >  mh_jetAK8PrunedMass     ;
//      edm::Handle<std::vector<float> >  mh_jetAK8SoftDropMass   ;


//      iEvent.getByLabel("jetsAK4", "jetAK4Pt", mh_jetAK4Pt);
//      iEvent.getByLabel("jetsAK4", "jetAK4GenPartonPt", mh_jetAK4GenPartonPt);
      iEvent.getByLabel("jetsAK4", "jetAK4Eta", mh_jetAK4Eta);
//      iEvent.getByLabel("jetsAK4", "jetAK4GenPartonY", mh_jetAK4GenPartonY);
      iEvent.getByLabel("jetsAK4", "jetAK4Phi", mh_jetAK4Phi);
//      iEvent.getByLabel("jetsAK4", "jetAK4E", mh_jetAK4E);
//      iEvent.getByLabel("jetsAK4", "jetAK4HadronFlavour", mh_jetAK4HadronFlavour);
//      iEvent.getByLabel("jetsAK4", "jetAK4CSV", mh_jetAK4CSV);
//      iEvent.getByLabel("jetsAK4", "jetAK4Mass", mh_jetAK4Mass);

      iEvent.getByLabel("presel","ak4goodjets", mh_jetAK4Good);
//      iEvent.getByLabel("presel", "htak4jets", mh_htak4jets);
//      iEvent.getByLabel("presel", "htak8jets", mh_htak8jets);
//      iEvent.getByLabel("presel", "htak4trigjets", mh_htak4trigjets);

//      iEvent.getByLabel("presel","ngoodAK4Jets", mh_ngoodAK4Jets);
//      iEvent.getByLabel("presel","ngoodAK8Jets", mh_ngoodAK8Jets);


//      iEvent.getByLabel("jetsAK8", "jetAK8Pt", mh_jetAK8Pt);
      iEvent.getByLabel("jetsAK8", "jetAK8Eta", mh_jetAK8Eta);
      iEvent.getByLabel("jetsAK8", "jetAK8Phi", mh_jetAK8Phi);
//      iEvent.getByLabel("jetsAK8", "jetAK8E", mh_jetAK8E);
//      iEvent.getByLabel("jetsAK8", "jetAK8Mass", mh_jetAK8Mass);
//      iEvent.getByLabel("jetsAK8", "jetAK8subjetIndex0", mh_jetAK8subjetIndex0);
//      iEvent.getByLabel("jetsAK8", "jetAK8subjetIndex1", mh_jetAK8subjetIndex1);
//      iEvent.getByLabel("jetsAK8", "jetAK8HadronFlavour", mh_jetAK8HadronFlavour);
      iEvent.getByLabel("jetsAK8", "jetAK8nSubJets", mh_jetAK8nSubjets );

//      iEvent.getByLabel("jetsAK8", "jetAK8filteredMass"    , mh_jetAK8FilteredMass   );
//      iEvent.getByLabel("jetsAK8", "jetAK8trimmedMass"    , mh_jetAK8TrimmedMass   );
//      iEvent.getByLabel("jetsAK8", "jetAK8prunedMass"    , mh_jetAK8PrunedMass   );
//      iEvent.getByLabel("jetsAK8", "jetAK8softDropMass"    , mh_jetAK8SoftDropMass   );

//      iEvent.getByLabel("jetsAK8", "jetAK8tau1", mh_jetAK8tau1);
//      iEvent.getByLabel("jetsAK8", "jetAK8tau2", mh_jetAK8tau2);
//      iEvent.getByLabel("jetsAK8", "jetAK8tau3", mh_jetAK8tau3);
      iEvent.getByLabel("presel", "ak8goodjets", mh_jetAK8Good);
//      iEvent.getByLabel("presel", "htak8jets", mh_htak8jets);

//      const double * htak4jets = mh_htak4jets.product();
//      const double * htak4trigjets = mh_htak4trigjets.product();
//      const double * htak8jets = mh_htak8jets.product();

//      const unsigned * ngoodAK4Jets = mh_ngoodAK4Jets.product();
//      const unsigned * ngoodAK8Jets = mh_ngoodAK8Jets.product();

//      const std::vector<float> * jetcsv = mh_jetAK4CSV.product();
//      const std::vector<float> * jetpt = mh_jetAK4Pt.product();
      const std::vector<float> * jeteta = mh_jetAK4Eta.product();
      const std::vector<float> * jetphi = mh_jetAK4Phi.product();
//      const std::vector<float> * jetM = mh_jetAK4Mass.product();
//      const std::vector<float> * jetflavor = mh_jetAK4HadronFlavour.product();
      const std::vector<unsigned> * jetgood = mh_jetAK4Good.product();

//      const std::vector<float> * jet8pt = mh_jetAK8Pt.product();
      //const std::vector<float> * jet8nSubjets = mh_jetAK8nSubjets.product();
      const std::vector<float> * jet8eta = mh_jetAK8Eta.product();
      const std::vector<float> * jet8phi = mh_jetAK8Phi.product();
//      const std::vector<float> * jet8M = mh_jetAK8Mass.product();
      const std::vector<unsigned> * jet8good = mh_jetAK8Good.product();



      // Make W, top and H jets 
      std::vector<unsigned> seltjets03, seltjets03sb0, selhjets,selhjetssb0,selhjetssb1, selwjets;
 try {
      for ( unsigned  ijet : (*jet8good) ) {
  //vlq::JetCollection tjets, hjets, wjets ;
/*
          JetSelector tjetselsub(TJetSelParamssub_) ;
          JetSelector tjetselsub2(TJetSelParamssub2_) ;
          JetSelector tjetsel(TJetSelParams_) ;
          JetSelector tjetsel03sub(TJetSelParams03sub_) ;
*/
          JetSelector tjetsel03(TJetSelParams03_) ;
          JetSelector tjetsel03sb0(TJetSelParams03SB0_) ;
/*
          JetSelector tjetsel10(TJetSelParams10_) ;
          JetSelector tjetsel30(TJetSelParams30_) ;
          JetSelector tjetsel0(TJetSelParams0_) ;
          JetSelector tjetsel1(TJetSelParams1_) ;
          JetSelector tjetsel2(TJetSelParams2_) ;
          JetSelector tjetsel3(TJetSelParams3_) ;
*/
          JetSelector hjetsel(HJetSelParams_) ;
          JetSelector hjetselsb0(HJetSelParamsSB0_) ;
          JetSelector hjetselsb1(HJetSelParamsSB1_) ;
          JetSelector wjetsel(WJetSelParams_) ;
          bool rettjetsel = false ;
          bool rethjetsel = false ;
          bool retwjetsel = false ;
	  //   cout << "Jet: "<< ijet << " t subjets: " << endl;
/*
          if (tjetselsub(iEvent, ijet,rettjetsel) == true ) {
             seltjetssub.push_back(ijet) ;
          0
          if (tjetselsub2(iEvent, ijet,rettjetsel) == true ) {
             seltjetssub2.push_back(ijet) ;
          }
          if (tjetsel(iEvent, ijet,rettjetsel) == true ) {
             seltjets.push_back(ijet) ;
          }
          if (tjetsel03sub(iEvent, ijet,rettjetsel) == true ) {
             seltjets03sub.push_back(ijet) ;
          }
*/
          if (tjetsel03(iEvent, ijet,rettjetsel) == true ) {
             seltjets03.push_back(ijet) ;
          }
          if (tjetsel03sb0(iEvent, ijet,rettjetsel) == true ) {
             seltjets03sb0.push_back(ijet) ;
          }
/*
          if (tjetsel10(iEvent, ijet,rettjetsel) == true ) {
             seltjets10.push_back(ijet) ;
          }
          if (tjetsel30(iEvent, ijet,rettjetsel) == true ) {
             seltjets30.push_back(ijet) ;
          }
          if (tjetsel0(iEvent, ijet,rettjetsel) == true ) {
             seltjets0.push_back(ijet) ;
          }
          if (tjetsel1(iEvent, ijet,rettjetsel) == true ) {
             seltjets1.push_back(ijet) ;
          }
          if (tjetsel2(iEvent, ijet,rettjetsel) == true ) {
             seltjets2.push_back(ijet) ;
          }
          if (tjetsel3(iEvent, ijet,rettjetsel) == true ) {
             seltjets3.push_back(ijet) ;
          }
*/
          //rethjetsel = false ;
          if (hjetsel(iEvent, ijet,rethjetsel) == true ) {
             selhjets.push_back(ijet) ;
          }
          if (hjetselsb0(iEvent, ijet,rethjetsel) == true ) {
             selhjetssb0.push_back(ijet) ;
          }
          if (hjetselsb1(iEvent, ijet,rethjetsel) == true ) {
             selhjetssb1.push_back(ijet) ;
          }
          if (wjetsel(iEvent, ijet,retwjetsel) == true ) {
             selwjets.push_back(ijet) ;
          }
     }
} catch (...) {std::cout << "exception.." << std::endl;}
	
//cout << "n t: " << seltjets.size() << endl;
//cout << "n t03: " <<seltjets03.size() << endl;
//cout << "n t10: " <<seltjets10.size() << endl;
//cout << "n t30: " <<seltjets30.size() << endl;

//cout << "n hsb0: "<< selhjetssb0.size() << endl;
//cout << "n hsb1: "<< selhjetssb1.size() << endl;

//	std::cout << " Select cands" << std::endl;

     //Select T, H cands.
     //unsigned HIdx, TIdx, HIdx03, TIdx03, HIdx10, TIdx10, HIdx30, TIdx30;
     unsigned HIdx03, TIdx03;
/*
     HIdx = 0;
     TIdx = 0;

     if(seltjets.size()>0 && selhjets.size()>0)
	if(seltjets[0] == selhjets[0]) {
	   if (seltjets.size()>1)
		TIdx = 1;
	   else
	   if (selhjets.size()>1)
		HIdx = 1;
	}
*/
     HIdx03 = 0;
     TIdx03 = 0;

     if(seltjets03.size()>0 && selhjets.size()>0)
        if(seltjets03[0] == selhjets[0]) {
           if (seltjets03.size()>1)
                TIdx03 = 1;
           else
           if (selhjets.size()>1)
                HIdx03 = 1;
      }
/*
     HIdx10 = 0;
     TIdx10 = 0;

     if(seltjets10.size()>0 && selhjets.size()>0)
        if(seltjets10[0] == selhjets[0]) {
           if (seltjets10.size()>1)
                TIdx10 = 1;
           else
           if (selhjets.size()>1)
                HIdx10 = 1;
        }
     HIdx30 = 0;
     TIdx30 = 0;


     if(seltjets30.size()>0 && selhjets.size()>0)
        if(seltjets30[0] == selhjets[0]) {
           if (seltjets30.size()>1)
                TIdx30 = 1;
           else
           if (selhjets.size()>1)
                HIdx30 = 1;
        }
*/	
//     std::vector<unsigned> jetUnmatchedIdx;
     std::vector<unsigned> jetUnmatchedIdx03;
//     std::vector<unsigned> jetUnmatchedIdx10;
//     std::vector<unsigned> jetUnmatchedIdx30;

     for (unsigned i = 0 ; i < jetgood->size() ; i++) {
//          bool bMatch = false;
          bool bMatch03 = false;
//          bool bMatch10 = false;
//          bool bMatch30 = false;

          //Match AK4 to H,T cand

          if(selhjets.size()>0) {
/*
             if(deltaR((*jeteta)[(*jetgood)[i]],(*jetphi)[(*jetgood)[i]],(*jet8eta)[selhjets[HIdx]],(*jet8phi)[selhjets[HIdx]]) < 0.5) {
          	bMatch = true;
             }
*/
             if(deltaR((*jeteta)[(*jetgood)[i]],(*jetphi)[(*jetgood)[i]],(*jet8eta)[selhjets[HIdx03]],(*jet8phi)[selhjets[HIdx03]]) < 0.5) {
          	bMatch03 = true;
             }
/*
             if(deltaR((*jeteta)[(*jetgood)[i]],(*jetphi)[(*jetgood)[i]],(*jet8eta)[selhjets[HIdx10]],(*jet8phi)[selhjets[HIdx10]]) < 0.5) {
          	bMatch10 = true;
             }
             if(deltaR((*jeteta)[(*jetgood)[i]],(*jetphi)[(*jetgood)[i]],(*jet8eta)[selhjets[HIdx30]],(*jet8phi)[selhjets[HIdx30]]) < 0.5) {
          	bMatch30 = true;
             }
*/
	  }
/*
	  if(seltjets.size() > 0 ) 
             if(deltaR((*jeteta)[(*jetgood)[i]],(*jetphi)[(*jetgood)[i]],(*jet8eta)[seltjets[TIdx]],(*jet8phi)[seltjets[TIdx]]) < 0.5) {
          	bMatch = true;
             }
*/
	  if(seltjets03.size() > 0 )
             if(deltaR((*jeteta)[(*jetgood)[i]],(*jetphi)[(*jetgood)[i]],(*jet8eta)[seltjets03[TIdx03]],(*jet8phi)[seltjets03[TIdx03]]) < 0.5) {
          	bMatch03 = true;
             }
/*
	  if(seltjets10.size() > 0 )
             if(deltaR((*jeteta)[(*jetgood)[i]],(*jetphi)[(*jetgood)[i]],(*jet8eta)[seltjets10[TIdx10]],(*jet8phi)[seltjets10[TIdx10]]) < 0.5) {
          	bMatch10 = true;
             }
	  if(seltjets30.size() > 0 )
             if(deltaR((*jeteta)[(*jetgood)[i]],(*jetphi)[(*jetgood)[i]],(*jet8eta)[seltjets30[TIdx30]],(*jet8phi)[seltjets30[TIdx30]]) < 0.5) {
          	bMatch30 = true;
             }
*/
          //Add unmatched good AK4 jet index

//          if(!bMatch)
//                jetUnmatchedIdx.push_back((*jetgood)[i]);
          if(!bMatch03)
                jetUnmatchedIdx03.push_back((*jetgood)[i]);
//          if(!bMatch10)
//                jetUnmatchedIdx10.push_back((*jetgood)[i]);
//          if(!bMatch30)
//                jetUnmatchedIdx30.push_back((*jetgood)[i]);

     }

/*	
        std::auto_ptr<std::vector<unsigned> > ptjetsel ( new std::vector<unsigned>(seltjets));
        std::auto_ptr<std::vector<unsigned> > ptjetselsub ( new std::vector<unsigned>(seltjetssub));
        std::auto_ptr<std::vector<unsigned> > ptjetselsub2 ( new std::vector<unsigned>(seltjetssub2));
        std::auto_ptr<std::vector<unsigned> > ptjetsel03sub ( new std::vector<unsigned>(seltjets03sub));
*/
        std::auto_ptr<std::vector<unsigned> > ptjetsel03 ( new std::vector<unsigned>(seltjets03));
        std::auto_ptr<std::vector<unsigned> > ptjetsel03sb0 ( new std::vector<unsigned>(seltjets03sb0));
/*
        std::auto_ptr<std::vector<unsigned> > ptjetsel10 ( new std::vector<unsigned>(seltjets10));
        std::auto_ptr<std::vector<unsigned> > ptjetsel30 ( new std::vector<unsigned>(seltjets30));
        std::auto_ptr<std::vector<unsigned> > ptjetsel0 ( new std::vector<unsigned>(seltjets0));
        std::auto_ptr<std::vector<unsigned> > ptjetsel1 ( new std::vector<unsigned>(seltjets1));
        std::auto_ptr<std::vector<unsigned> > ptjetsel2 ( new std::vector<unsigned>(seltjets2));
        std::auto_ptr<std::vector<unsigned> > ptjetsel3 ( new std::vector<unsigned>(seltjets3));
*/
        std::auto_ptr<std::vector<unsigned> > phjetselsb0 ( new std::vector<unsigned>(selhjetssb0));
        std::auto_ptr<std::vector<unsigned> > phjetselsb1 ( new std::vector<unsigned>(selhjetssb1));
        std::auto_ptr<std::vector<unsigned> > phjetsel ( new std::vector<unsigned>(selhjets));
        std::auto_ptr<std::vector<unsigned> > pwjetsel ( new std::vector<unsigned>(selwjets));


//      std::auto_ptr<std::vector<unsigned> > pUnmatched ( new std::vector<unsigned>(jetUnmatchedIdx));
      std::auto_ptr<std::vector<unsigned> > pUnmatched03 ( new std::vector<unsigned>(jetUnmatchedIdx03));
//      std::auto_ptr<std::vector<unsigned> > pUnmatched10 ( new std::vector<unsigned>(jetUnmatchedIdx10));
//      std::auto_ptr<std::vector<unsigned> > pUnmatched30 ( new std::vector<unsigned>(jetUnmatchedIdx30));


//      iEvent.put( pUnmatched, "ak4UnmatchedIdx");
      iEvent.put( pUnmatched03, "ak4UnmatchedIdx03");
//      iEvent.put( pUnmatched10, "ak4UnmatchedIdx10");
//      iEvent.put( pUnmatched30, "ak4UnmatchedIdx30");

/*
      iEvent.put( ptjetsel, "tjetsIdx");
      iEvent.put( ptjetselsub, "tjetsIdxsub");
      iEvent.put( ptjetselsub2, "tjetsIdxsub2");
      iEvent.put( ptjetsel03sub, "tjetsIdx03sub");
*/
      iEvent.put( ptjetsel03, "tjetsIdx03");
      iEvent.put( ptjetsel03sb0, "tjetsIdx03sb0");
/*
      iEvent.put( ptjetsel10, "tjetsIdx10");
      iEvent.put( ptjetsel30, "tjetsIdx30");
      iEvent.put( ptjetsel0, "tjetsIdx0");
      iEvent.put( ptjetsel1, "tjetsIdx1");
      iEvent.put( ptjetsel2, "tjetsIdx2");
      iEvent.put( ptjetsel3, "tjetsIdx3");
*/
      iEvent.put( phjetsel, "hjetsIdx");
      iEvent.put( phjetselsb0, "hjetsIdxSB0");
      iEvent.put( phjetselsb1, "hjetsIdxSB1");
      iEvent.put( pwjetsel, "wjetsIdx");
}

// ------------ method called once each job just before starting event loop  ------------
void 
AnaVars::beginJob()
{

	

}

// ------------ method called once each job just after ending the event loop  ------------
void 
AnaVars::endJob() {
}

// ------------ method called when starting to processes a run  ------------
/*
void
AnaVars::beginRun(edm::Run const&, edm::EventSetup const&)
{
}
*/
 
// ------------ method called when ending the processing of a run  ------------
/*
void
AnaVars::endRun(edm::Run const&, edm::EventSetup const&)
{
}
*/
 
// ------------ method called when starting to processes a luminosity block  ------------
/*
void
AnaVars::beginLuminosityBlock(edm::LuminosityBlock const&, edm::EventSetup const&)
{
}
*/
 
// ------------ method called when ending the processing of a luminosity block  ------------
/*
void
AnaVars::endLuminosityBlock(edm::LuminosityBlock const&, edm::EventSetup const&)
{
}
*/
 
// ------------ method fills 'descriptions' with the allowed parameters for the module  ------------
void
AnaVars::fillDescriptions(edm::ConfigurationDescriptions& descriptions) {
  //The following says we do not know what parameters are allowed so do no validation
  // Please change this to state exactly what you do use, even if it is no parameters
  edm::ParameterSetDescription desc;
  desc.setUnknown();
  descriptions.addDefault(desc);
}

//define this as a plug-in
DEFINE_FWK_MODULE(AnaVars);
