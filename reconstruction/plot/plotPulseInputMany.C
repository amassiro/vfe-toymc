//---- plot output of multifit

void plotPulseInputMany (int nEvent = 1){
  
  std::vector<std::string> nameInputFiles;
  
  nameInputFiles.push_back("input/mysample_11_5.000_0.000_10_25.00_10.00_0.00_0.000_0.00_CRRC43_0.00.root");
  nameInputFiles.push_back("input/mysample_11_4.000_0.000_10_25.00_10.00_0.00_0.000_0.00_CRRC43_0.00.root");
  nameInputFiles.push_back("input/mysample_11_3.000_0.000_10_25.00_10.00_0.00_0.000_0.00_CRRC43_0.00.root");
  nameInputFiles.push_back("input/mysample_11_2.000_0.000_10_25.00_10.00_0.00_0.000_0.00_CRRC43_0.00.root");
  nameInputFiles.push_back("input/mysample_11_1.000_0.000_10_25.00_10.00_0.00_0.000_0.00_CRRC43_0.00.root");
  nameInputFiles.push_back("input/mysample_11_0.000_0.000_10_25.00_10.00_0.00_0.000_0.00_CRRC43_0.00.root");
  nameInputFiles.push_back("input/mysample_11_-1.000_0.000_10_25.00_10.00_0.00_0.000_0.00_CRRC43_0.00.root");
  nameInputFiles.push_back("input/mysample_11_-2.000_0.000_10_25.00_10.00_0.00_0.000_0.00_CRRC43_0.00.root");
  nameInputFiles.push_back("input/mysample_11_-3.000_0.000_10_25.00_10.00_0.00_0.000_0.00_CRRC43_0.00.root");
  nameInputFiles.push_back("input/mysample_11_-4.000_0.000_10_25.00_10.00_0.00_0.000_0.00_CRRC43_0.00.root");
  nameInputFiles.push_back("input/mysample_11_-5.000_0.000_10_25.00_10.00_0.00_0.000_0.00_CRRC43_0.00.root");
  nameInputFiles.push_back("input/mysample_11_-6.000_0.000_10_25.00_10.00_0.00_0.000_0.00_CRRC43_0.00.root");
  nameInputFiles.push_back("input/mysample_11_-7.000_0.000_10_25.00_10.00_0.00_0.000_0.00_CRRC43_0.00.root");
  nameInputFiles.push_back("input/mysample_11_-8.000_0.000_10_25.00_10.00_0.00_0.000_0.00_CRRC43_0.00.root");
  nameInputFiles.push_back("input/mysample_11_-9.000_0.000_10_25.00_10.00_0.00_0.000_0.00_CRRC43_0.00.root");
  nameInputFiles.push_back("input/mysample_11_-10.000_0.000_10_25.00_10.00_0.00_0.000_0.00_CRRC43_0.00.root");
  
  TGraph *gr[20];
  TGraph *grPulse[20];
  
  TCanvas* ccpulse_signal = new TCanvas ("ccpulse_signal","",800,600);
  TCanvas* ccPulse = new TCanvas ("ccPulse","",800,600);
  
  for (int iFile = 0; iFile < nameInputFiles.size(); iFile++) {
    std::string nameInputFile = nameInputFiles.at(iFile);
      
    TFile *file = new TFile(nameInputFile.c_str());
    
    TTree* tree = (TTree*) file->Get("Samples");
    
    int    nWF;
    std::vector<double>* pulse_signal = new std::vector<double>;
    std::vector<double>* samples = new std::vector<double>;
    
    tree->SetBranchAddress("nWF",      &nWF);
    tree->SetBranchAddress("pulse_signal", &pulse_signal);
    tree->SetBranchAddress("samples", &samples);
    
    tree->GetEntry(nEvent);
    
    ccpulse_signal->cd();
    gr[iFile] = new TGraph();
    for(int i=0; i<nWF; i++){
      gr[iFile]->SetPoint(i, i, pulse_signal->at(i));
    }
    if (iFile == 0) {
      gr[iFile]->Draw("AL");
    }
    else {
      gr[iFile]->Draw("LP");
    }
    gr[iFile]->SetLineColor(kMagenta+iFile);
    gr[iFile]->SetLineWidth(2);
    gr[iFile]->GetXaxis()->SetTitle("time [ns]");
    
    ccPulse->cd();
    grPulse[iFile] = new TGraph();
    for(int i=0; i<samples->size(); i++){
      grPulse[iFile]->SetPoint(i, i, samples->at(i));
    }
    grPulse[iFile]->SetMarkerSize(2);
    grPulse[iFile]->SetMarkerStyle(21);
    grPulse[iFile]->SetMarkerColor(kRed-6-5+iFile);
    grPulse[iFile]->SetLineColor(kRed-6-5+iFile);
    if (iFile == 0) {
      grPulse[iFile]->Draw("ALP");
      grPulse[iFile]->GetXaxis()->SetTitle("BX");
    }
    else {
      grPulse[iFile]->Draw("LP");
    }
    
  } 
  
  
  
}


