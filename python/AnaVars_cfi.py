import FWCore.ParameterSet.Config as cms

from Analysis.VLQAna.JetSelector_cfi import *


anavars = cms.EDProducer('AnaVars',
    HJetSelParams              = defaultHJetSelectionParameters.clone(
	jettau2Bytau1Max    = cms.double(0.6) ,
	subjetbMin	    = cms.double(2),
	subjetbMax	    = cms.double(2) 
	),

    HJetSelParamsSB0              = defaultHJetSelectionParameters.clone(
	jettau2Bytau1Max    = cms.double(0.6) ,
        jetnSubJetsMin      = cms.double(0),
        jetnSubJetsMax      = cms.double(2),
	subjetbMin	    = cms.double(0),
	subjetbMax	    = cms.double(0) ),

    HJetSelParamsSB1              = defaultHJetSelectionParameters.clone(
	jettau2Bytau1Max    = cms.double(0.6) ,
        jetnSubJetsMin      = cms.double(0) ,
        jetnSubJetsMax      = cms.double(2) ,
	subjetbMin	    = cms.double(1),
	subjetbMax	    = cms.double(1) ),

   TJetSelParamssub              = defaultTJetSelectionParameters.clone(
        subjetCSVMin        = cms.double(-100000),
        jetMassMin          = cms.double(0) ,
        jetMassMax          = cms.double(10000) ,
        jetPrunedMassMin          = cms.double(140) ,
        jetPrunedMassMax          = cms.double(250) ,
        JetSubstrParams         = defaultJetSubstructureParameters.clone(),
        SubjetParams            = defaultTopTaggedSubjetParameters.clone(),
        subjetbMin          = cms.double(1),
        subjetbMax          = cms.double(3),
        jetnSubJetsMin      = cms.double(0),
        jetnSubJetsMax      = cms.double(99),

         ),

   TJetSelParamssub2              = defaultTJetSelectionParameters.clone(
        subjetCSVMin        = cms.double(-100000),
        jetMassMin          = cms.double(0) ,
        jetMassMax          = cms.double(10000) ,
        jetPrunedMassMin          = cms.double(140) ,
        jetPrunedMassMax          = cms.double(250) ,
        JetSubstrParams         = defaultJetSubstructureParameters.clone(),
        SubjetParams            = defaultTopTaggedSubjetParameters.clone(),
        subjetbMin          = cms.double(1),
        subjetbMax          = cms.double(3),
        jetnSubJetsMin      = cms.double(2),
        jetnSubJetsMax      = cms.double(2),
         ),


    TJetSelParams              = defaultTJetSelectionParameters.clone(
	subjetCSVMin        = cms.double(-100000),
        jetMassMin          = cms.double(0) ,
        jetMassMax          = cms.double(10000) ,
        jetPrunedMassMin          = cms.double(140) ,
        jetPrunedMassMax          = cms.double(250) ,
        JetSubstrParams		= defaultJetSubstructureParameters.clone(),
	SubjetParams		= defaultTopTaggedSubjetParameters.clone(),
	subjetbMin	    = cms.double(1),
	subjetbMax	    = cms.double(3),
	 ),

    TJetSelParams03              = defaultTJetSelectionParameters.clone(
        jettau3Bytau2Min    = cms.double(0.00) ,
        jettau3Bytau2Max    = cms.double(0.61) ,
        jetMassMin          = cms.double(0) ,
        jetMassMax          = cms.double(10000) ,
        jetSoftDropMassMin          = cms.double(110) ,
        jetSoftDropMassMax          = cms.double(210) ,
        JetSubstrParams		= defaultJetSubstructureParameters.clone(),
	SubjetParams		= defaultTopTaggedSubjetParameters.clone(),
	subjetbMin	    = cms.double(1),
	subjetbMax	    = cms.double(3),
	subjetCSVMin	    = cms.double(0.76)) ,

    TJetSelParams03SB0              = defaultTJetSelectionParameters.clone(
        jettau3Bytau2Min    = cms.double(0.00) ,
        jettau3Bytau2Max    = cms.double(0.61) ,
        jetMassMin          = cms.double(0) ,
        jetMassMax          = cms.double(10000) ,
        jetSoftDropMassMin          = cms.double(110) ,
        jetSoftDropMassMax          = cms.double(210) ,
        JetSubstrParams         = defaultJetSubstructureParameters.clone(),
        SubjetParams            = defaultTopTaggedSubjetParameters.clone(),
        subjetbMin          = cms.double(0),
        subjetbMax          = cms.double(0),
	subjetCSVMin        = cms.double(0.76)) ,


    TJetSelParams10              = defaultTJetSelectionParameters.clone(
        jettau3Bytau2Min    = cms.double(0.00) ,
        jettau3Bytau2Max    = cms.double(0.69) ,
        jetMassMin          = cms.double(0) ,
        jetMassMax          = cms.double(10000) ,
        jetSoftDropMassMin          = cms.double(110) ,
        jetSoftDropMassMax          = cms.double(210) ,
        JetSubstrParams		= defaultJetSubstructureParameters.clone(),
	SubjetParams		= defaultTopTaggedSubjetParameters.clone(),
	subjetbMin	    = cms.double(1),
	subjetbMax	    = cms.double(3),
	subjetCSVMin	    = cms.double(0.66)) ,
 
    TJetSelParams30              = defaultTJetSelectionParameters.clone(
        jettau3Bytau2Min    = cms.double(0.00) ,
        jettau3Bytau2Max    = cms.double(0.75) ,
        jetMassMin          = cms.double(0) ,
        jetMassMax          = cms.double(10000) ,
        jetSoftDropMassMin          = cms.double(110) ,
        jetSoftDropMassMax          = cms.double(210) ,
        JetSubstrParams		= defaultJetSubstructureParameters.clone(),
	SubjetParams		= defaultTopTaggedSubjetParameters.clone(),
	subjetbMin	    = cms.double(1),
	subjetbMax	    = cms.double(3),
	subjetCSVMin	    = cms.double(0.39)),

    TJetSelParams0              = defaultTJetSelectionParameters.clone(
        jetMassMin          = cms.double(0) ,
        jetMassMax          = cms.double(10000) ,
        jetPrunedMassMin          = cms.double(140) ,
        jetPrunedMassMax          = cms.double(250) ,
        JetSubstrParams         = defaultJetSubstructureParameters.clone(),
        SubjetParams            = defaultTopTaggedSubjetParameters.clone(),
	subjetbMin	    = cms.double(0),
	subjetbMax	    = cms.double(0),
        subjetCSVMin        = cms.double(0.605)),

    TJetSelParams1              = defaultTJetSelectionParameters.clone(
        jetMassMin          = cms.double(0) ,
        jetMassMax          = cms.double(10000) ,
        jetPrunedMassMin          = cms.double(140) ,
        jetPrunedMassMax          = cms.double(250) ,
        JetSubstrParams         = defaultJetSubstructureParameters.clone(),
        SubjetParams            = defaultTopTaggedSubjetParameters.clone(),
        subjetbMin          = cms.double(0),
        subjetbMax          = cms.double(0),
        subjetCSVMin        = cms.double(0.605)),


    TJetSelParams2              = defaultTJetSelectionParameters.clone(
        jetMassMin          = cms.double(0) ,
        jetMassMax          = cms.double(10000) ,
        jetPrunedMassMin          = cms.double(140) ,
        jetPrunedMassMax          = cms.double(250) ,
        JetSubstrParams         = defaultJetSubstructureParameters.clone(),
        SubjetParams            = defaultTopTaggedSubjetParameters.clone(),
        subjetbMin          = cms.double(2),
        subjetbMax          = cms.double(2),
        subjetCSVMin        = cms.double(0.605)),

    TJetSelParams3              = defaultTJetSelectionParameters.clone(
        jetMassMin          = cms.double(0) ,
        jetMassMax          = cms.double(10000) ,
        jetPrunedMassMin          = cms.double(140) ,
        jetPrunedMassMax          = cms.double(250) ,
        JetSubstrParams         = defaultJetSubstructureParameters.clone(),
        SubjetParams            = defaultTopTaggedSubjetParameters.clone(),
        subjetbMin          = cms.double(3),
        subjetbMax          = cms.double(3),
        subjetCSVMin        = cms.double(0.605)),
	
    WJetSelParams 		= defaultAK8JetSelectionParameters.clone(),

    
)

 

