//---- plot output of multifit

void TimeShift (int nEvent = 1){
  
  std::vector<std::string> nameInputFiles;
  std::vector<float> valuesInputFiles;
  
  nameInputFiles.push_back("output/output_11_-13.000_0.000_10_25.00_10.00_0.00_0.000_0.00_CRRC43_0.00_shift_-3.root");   valuesInputFiles.push_back(-3);
  nameInputFiles.push_back("output/output_11_-13.000_0.000_10_25.00_10.00_0.00_0.000_0.00_CRRC43_0.00_shift_-2.root");   valuesInputFiles.push_back(-2);
  nameInputFiles.push_back("output/output_11_-13.000_0.000_10_25.00_10.00_0.00_0.000_0.00_CRRC43_0.00_shift_-1.root");   valuesInputFiles.push_back(-1);

  nameInputFiles.push_back("output/output_11_-13.000_0.000_10_25.00_10.00_0.00_0.000_0.00_CRRC43_0.00_shift_-0.9.root");    valuesInputFiles.push_back(-0.9);
  nameInputFiles.push_back("output/output_11_-13.000_0.000_10_25.00_10.00_0.00_0.000_0.00_CRRC43_0.00_shift_-0.2.root");    valuesInputFiles.push_back(-0.8);
  nameInputFiles.push_back("output/output_11_-13.000_0.000_10_25.00_10.00_0.00_0.000_0.00_CRRC43_0.00_shift_-0.3.root");    valuesInputFiles.push_back(-0.7);
  nameInputFiles.push_back("output/output_11_-13.000_0.000_10_25.00_10.00_0.00_0.000_0.00_CRRC43_0.00_shift_-0.6.root");    valuesInputFiles.push_back(-0.6);
  nameInputFiles.push_back("output/output_11_-13.000_0.000_10_25.00_10.00_0.00_0.000_0.00_CRRC43_0.00_shift_-0.5.root");    valuesInputFiles.push_back(-0.5);
  nameInputFiles.push_back("output/output_11_-13.000_0.000_10_25.00_10.00_0.00_0.000_0.00_CRRC43_0.00_shift_-0.4.root");    valuesInputFiles.push_back(-0.4);
  nameInputFiles.push_back("output/output_11_-13.000_0.000_10_25.00_10.00_0.00_0.000_0.00_CRRC43_0.00_shift_-0.3.root");    valuesInputFiles.push_back(-0.3);
  nameInputFiles.push_back("output/output_11_-13.000_0.000_10_25.00_10.00_0.00_0.000_0.00_CRRC43_0.00_shift_-0.2.root");    valuesInputFiles.push_back(-0.2);
  nameInputFiles.push_back("output/output_11_-13.000_0.000_10_25.00_10.00_0.00_0.000_0.00_CRRC43_0.00_shift_-0.1.root");    valuesInputFiles.push_back(-0.1);

  nameInputFiles.push_back("output/output_11_-13.000_0.000_10_25.00_10.00_0.00_0.000_0.00_CRRC43_0.00_shift_0.root");    valuesInputFiles.push_back(0);

  nameInputFiles.push_back("output/output_11_-13.000_0.000_10_25.00_10.00_0.00_0.000_0.00_CRRC43_0.00_shift_0.1.root");    valuesInputFiles.push_back(0.1);
  nameInputFiles.push_back("output/output_11_-13.000_0.000_10_25.00_10.00_0.00_0.000_0.00_CRRC43_0.00_shift_0.2.root");    valuesInputFiles.push_back(0.2);
  nameInputFiles.push_back("output/output_11_-13.000_0.000_10_25.00_10.00_0.00_0.000_0.00_CRRC43_0.00_shift_0.3.root");    valuesInputFiles.push_back(0.3);
  nameInputFiles.push_back("output/output_11_-13.000_0.000_10_25.00_10.00_0.00_0.000_0.00_CRRC43_0.00_shift_0.4.root");    valuesInputFiles.push_back(0.4);
  nameInputFiles.push_back("output/output_11_-13.000_0.000_10_25.00_10.00_0.00_0.000_0.00_CRRC43_0.00_shift_0.5.root");    valuesInputFiles.push_back(0.5);
  nameInputFiles.push_back("output/output_11_-13.000_0.000_10_25.00_10.00_0.00_0.000_0.00_CRRC43_0.00_shift_0.6.root");    valuesInputFiles.push_back(0.6);
  nameInputFiles.push_back("output/output_11_-13.000_0.000_10_25.00_10.00_0.00_0.000_0.00_CRRC43_0.00_shift_0.7.root");    valuesInputFiles.push_back(0.7);
  nameInputFiles.push_back("output/output_11_-13.000_0.000_10_25.00_10.00_0.00_0.000_0.00_CRRC43_0.00_shift_0.8.root");    valuesInputFiles.push_back(0.8);
  nameInputFiles.push_back("output/output_11_-13.000_0.000_10_25.00_10.00_0.00_0.000_0.00_CRRC43_0.00_shift_0.9.root");    valuesInputFiles.push_back(0.9);
  
  nameInputFiles.push_back("output/output_11_-13.000_0.000_10_25.00_10.00_0.00_0.000_0.00_CRRC43_0.00_shift_1.root");    valuesInputFiles.push_back(1);
  nameInputFiles.push_back("output/output_11_-13.000_0.000_10_25.00_10.00_0.00_0.000_0.00_CRRC43_0.00_shift_2.root");    valuesInputFiles.push_back(2);
  nameInputFiles.push_back("output/output_11_-13.000_0.000_10_25.00_10.00_0.00_0.000_0.00_CRRC43_0.00_shift_3.root");    valuesInputFiles.push_back(3);
 
  
  
  TGraph *gr = new TGraph();
  
  TCanvas* ccScan = new TCanvas ("ccScan","",800,600);
  
  for (int iFile = 0; iFile < nameInputFiles.size(); iFile++) {
    std::string nameInputFile = nameInputFiles.at(iFile);
    
    TFile *file = new TFile(nameInputFile.c_str());
    
    TTree* tree = (TTree*) file->Get("RecoAndSim");
    
    float  chi2;
    tree->SetBranchAddress("chi2",      &chi2);
 
    tree->GetEntry(nEvent);

    gr->SetPoint(iFile, valuesInputFiles.at(iFile), chi2);
  } 
  
    
  gr->SetLineWidth(2);
  gr->SetMarkerSize(2);
  gr->SetMarkerStyle(22);
  gr->SetMarkerColor(kBlue);
  gr->SetLineColor(kBlue);
  
  gr->Draw("APL");
  gr->GetXaxis()->SetTitle("time [ns]");
  gr->GetYaxis()->SetTitle("Chi2");
  
  ccScan->SetGrid();
  
  
}


