//---- plot output of multifit

void PedestalShift (int nEvent = 1){
  
  std::vector<std::string> nameInputFiles;                                                                                                                                                               
  std::vector<float> valuesInputFiles;                                                                                                                                                                   
                                                                                                                                                                                                         
//   nameInputFiles.push_back("output/output_11_-13.000_0.000_10_25.00_10.00_0.00_0.000_0.00_CRRC43_-1.00_0.0.root");   valuesInputFiles.push_back(0.0);                                                      
//   nameInputFiles.push_back("output/output_11_-13.000_0.000_10_25.00_10.00_0.00_0.000_0.00_CRRC43_-1.00_0.1.root");   valuesInputFiles.push_back(0.1);                                                      
//   nameInputFiles.push_back("output/output_11_-13.000_0.000_10_25.00_10.00_0.00_0.000_0.00_CRRC43_-1.00_0.6.root");   valuesInputFiles.push_back(0.6);                                                      
//   nameInputFiles.push_back("output/output_11_-13.000_0.000_10_25.00_10.00_0.00_0.000_0.00_CRRC43_-1.00_0.7.root");   valuesInputFiles.push_back(0.7);                                                      
//   nameInputFiles.push_back("output/output_11_-13.000_0.000_10_25.00_10.00_0.00_0.000_0.00_CRRC43_-1.00_0.8.root");   valuesInputFiles.push_back(0.8);                                                      
//   nameInputFiles.push_back("output/output_11_-13.000_0.000_10_25.00_10.00_0.00_0.000_0.00_CRRC43_-1.00_0.9.root");   valuesInputFiles.push_back(0.9);                                                      
//   nameInputFiles.push_back("output/output_11_-13.000_0.000_10_25.00_10.00_0.00_0.000_0.00_CRRC43_-1.00_1.0.root");   valuesInputFiles.push_back(1.0);
//   nameInputFiles.push_back("output/output_11_-13.000_0.000_10_25.00_10.00_0.00_0.000_0.00_CRRC43_-1.00_1.1.root");   valuesInputFiles.push_back(1.1);
//   nameInputFiles.push_back("output/output_11_-13.000_0.000_10_25.00_10.00_0.00_0.000_0.00_CRRC43_-1.00_1.2.root");   valuesInputFiles.push_back(1.2);
//   nameInputFiles.push_back("output/output_11_-13.000_0.000_10_25.00_10.00_0.00_0.000_0.00_CRRC43_-1.00_1.3.root");   valuesInputFiles.push_back(1.3);
//   nameInputFiles.push_back("output/output_11_-13.000_0.000_10_25.00_10.00_0.00_0.000_0.00_CRRC43_-1.00_1.4.root");   valuesInputFiles.push_back(1.4);

  nameInputFiles.push_back("output/output_11_-13.000_0.000_10_25.00_10.00_40.00_0.000_1.00_CRRC43_0.10_0.0.root");    valuesInputFiles.push_back(0.0);                                                      
  nameInputFiles.push_back("output/output_11_-13.000_0.000_10_25.00_10.00_40.00_0.000_1.00_CRRC43_0.10_0.02.root");   valuesInputFiles.push_back(0.02);                                                      
  nameInputFiles.push_back("output/output_11_-13.000_0.000_10_25.00_10.00_40.00_0.000_1.00_CRRC43_0.10_0.04.root");   valuesInputFiles.push_back(0.04);                                                      
  nameInputFiles.push_back("output/output_11_-13.000_0.000_10_25.00_10.00_40.00_0.000_1.00_CRRC43_0.10_0.06.root");   valuesInputFiles.push_back(0.06);                                                      
  nameInputFiles.push_back("output/output_11_-13.000_0.000_10_25.00_10.00_40.00_0.000_1.00_CRRC43_0.10_0.08.root");   valuesInputFiles.push_back(0.08);                                                      
  nameInputFiles.push_back("output/output_11_-13.000_0.000_10_25.00_10.00_40.00_0.000_1.00_CRRC43_0.10_0.10.root");   valuesInputFiles.push_back(0.10);                                                      
  nameInputFiles.push_back("output/output_11_-13.000_0.000_10_25.00_10.00_40.00_0.000_1.00_CRRC43_0.10_0.12.root");   valuesInputFiles.push_back(0.12);
  nameInputFiles.push_back("output/output_11_-13.000_0.000_10_25.00_10.00_40.00_0.000_1.00_CRRC43_0.10_0.14.root");   valuesInputFiles.push_back(0.14);
  nameInputFiles.push_back("output/output_11_-13.000_0.000_10_25.00_10.00_40.00_0.000_1.00_CRRC43_0.10_0.16.root");   valuesInputFiles.push_back(0.16);
  nameInputFiles.push_back("output/output_11_-13.000_0.000_10_25.00_10.00_40.00_0.000_1.00_CRRC43_0.10_0.18.root");   valuesInputFiles.push_back(0.18);
  nameInputFiles.push_back("output/output_11_-13.000_0.000_10_25.00_10.00_40.00_0.000_1.00_CRRC43_0.10_0.20.root");   valuesInputFiles.push_back(0.20);
  
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
  gr->GetXaxis()->SetTitle("Shift [GeV]");
  gr->GetYaxis()->SetTitle("Chi2");
  
  ccScan->SetGrid();
  
  
}


