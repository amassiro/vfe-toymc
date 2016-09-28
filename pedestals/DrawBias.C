
{
  TGraph graph("../reconstruction/results.txt");
  graph.SetName("bias");
  graph.SetTitle("Energy shift vs pedestal shift");
  graph.SetMarkerSize(2);
  graph.SetMarkerStyle(20);
  graph.SetMarkerColor(kRed);
  graph.SetLineColor(kRed);
  
 
  TCanvas cc("cc", "absolute", 800, 600);
  graph.Draw("APL");
  graph.GetXaxis()->SetTitle("pedestal shift [GeV]");
  graph.GetYaxis()->SetTitle("Energy [GeV]");
  graph.GetYaxis()->SetTitleOffset(1.2);
  gPad->SetGrid();
  
  
  
  TGraph graph_relative;
  for (int i=0; i<graph.GetN(); i++) {
    graph_relative.SetPoint(i, graph.GetX()[i], graph.GetY()[i]/10. - 1);
  }
  graph_relative.SetMarkerSize(2);
  graph_relative.SetMarkerStyle(21);
  graph_relative.SetMarkerColor(kBlue);
  graph_relative.SetLineColor(kBlue);
  
  graph_relative.GetXaxis()->SetTitle("pedestal shift [GeV]");
  graph_relative.GetYaxis()->SetTitle("Energy shift / Energy");
  graph_relative.GetYaxis()->SetTitleOffset(1.2);
  
  TCanvas cc_relative("cc_relative", "relative", 800, 600);
  graph_relative.Draw("APL");
  
  gPad->SetGrid();
  
  
  
  TGraph graph_relative_both;
  for (int i=0; i<graph.GetN(); i++) {
    graph_relative_both.SetPoint(i, graph.GetX()[i] / 10., graph.GetY()[i]/10. - 1);
  }
  graph_relative_both.SetMarkerSize(2);
  graph_relative_both.SetMarkerStyle(22);
  graph_relative_both.SetMarkerColor(kMagenta);
  graph_relative_both.SetLineColor(kMagenta);
  
  graph_relative_both.GetXaxis()->SetTitle("pedestal shift / Energy");
  graph_relative_both.GetYaxis()->SetTitle("Energy shift / Energy");
  graph_relative_both.GetYaxis()->SetTitleOffset(1.4);
  
  TCanvas cc_relative_both("cc_relative_both", "relative_both", 800, 600);
  graph_relative_both.Draw("APL");
  
  gPad->SetGrid();
  
  
  
  
  
  
  TGraph graph_adc;
  for (int i=0; i<graph.GetN(); i++) {
    graph_adc.SetPoint(i, graph.GetX()[i] / 0.04, graph.GetY()[i]);
  }
  graph_adc.SetMarkerSize(1);
  graph_adc.SetMarkerStyle(24);
  graph_adc.SetMarkerColor(kRed);
  graph_adc.SetLineColor(kRed);
  
  graph_adc.GetXaxis()->SetTitle("pedestal shift [ADC counts]");
  graph_adc.GetYaxis()->SetTitle("Energy [GeV]");
  graph_adc.GetYaxis()->SetTitleOffset(1.4);
 
  
  TCanvas cc_ADC("cc_ADC", "ADC", 800, 600);
  graph_adc.Draw("APL");
  
  gPad->SetGrid();
  
  
  
}


