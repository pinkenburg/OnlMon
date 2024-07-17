#ifndef BBC_BBCMONDRAW_H
#define BBC_BBCMONDRAW_H

#include "BbcMonDefs.h"

#include <onlmon/OnlMonDraw.h>

#include <string>
#include <fstream>

class OnlMonDB;
class TCanvas;
class TGraphErrors;
class TPad;
class TStyle;
class TPaveText;
class TText;
class TArc;
class TLine;
class TBox;
class TH1;
class TH2;
class TGraph;
class TArrow;
class TF1;
class TLatex;
class TSpectrum;

class BbcMonDraw : public OnlMonDraw
{
 public:
  explicit BbcMonDraw(const std::string &name);

  ~BbcMonDraw() override;

  int Init() override;
  int Draw(const std::string &what = "ALL") override;
  int MakeHtml(const std::string &what = "ALL") override;
  int SavePlot(const std::string &what = "ALL", const std::string &type = "png") override;

 protected:
  TStyle *bbcStyle {nullptr};

  int MakeCanvas(const std::string &name);
  int DrawFirst(const std::string &what = "ALL");
  int DrawSecond(const std::string &what = "ALL");

  int Warning(TPad *pad, const float x, const float y, const int r, const std::string &msg);
  int ClearWarning(void);

  // vtx to MCR variables
  int sendflag{0};      // 0 = don't send, 1 = send
  std::string sendflagfname;
  int GetSendFlag();
  int UpdateSendFlag(const int flag);

  // bad gl1 variables
  int gl1badflag{0};      // 0 = normal, 1 = gl1bad
  std::string gl1badflagfname;
  int GetGL1BadFlag();
  int UpdateGL1BadFlag(const int flag);

  TCanvas *TC[nCANVAS] {nullptr};
  TPad *transparent[nCANVAS] {nullptr};

  TPad *Pad[6] {nullptr};

  // for all Pages
  TPad *PadTop[nCANVAS] {nullptr};
  TPaveText *PaveTop {nullptr};
  TText *TextTop {nullptr};

  TPaveText *PaveWarning[BbcMonDefs::MAX_WARNING] {nullptr};
  TArc *ArcWarning[BbcMonDefs::MAX_WARNING] {nullptr};
  TPad *PadWarning[BbcMonDefs::MAX_WARNING] {nullptr};
  int nPadWarning[BbcMonDefs::MAX_WARNING] {0};
  int nWarning {0};

  TH1 *Trigs{nullptr};

  // for the 1st Page
  TPad *PadZVertex {nullptr};
  TPad *PadZVertexSummary {nullptr};
  TH2 *SouthHitMap {nullptr};
  TPad *PadSouthHitMap {nullptr};
  TH2 *NorthHitMap {nullptr};
  TPad *PadNorthHitMap {nullptr};

  // for 2nd Page
  TH1 *HitTime[nSIDE] {nullptr};
  TPad *PadHitTime[nSIDE] {nullptr};
  TLine *LineHitTime[nSIDE][2] {{nullptr}};
  TArrow *ArrowHitTime[nSIDE] {nullptr};
  TText *TextHitTime[nSIDE] {nullptr};
  TF1 *FitHitTime[nSIDE] {nullptr};

  TH1 *AvrHitTime {nullptr};
  TPad *PadAvrHitTime {nullptr};
  TLine *LineAvrHitTime[2] {nullptr};
  TArrow *ArrowAvrHitTime {nullptr};
  TText *TextAvrHitTime {nullptr};
  TF1 *FitAvrHitTime {nullptr};

  TH1 *SouthHitTime {nullptr};
  TPad *PadSouthHitTime {nullptr};
  TLine *LineSouthHitTime[2] {nullptr};
  TArrow *ArrowSouthHitTime {nullptr};
  TText *TextSouthHitTime {nullptr};
  TF1 *FitSouthHitTime {nullptr};

  TH1 *NorthHitTime {nullptr};
  TPad *PadNorthHitTime {nullptr};
  TLine *LineNorthHitTime[2] {nullptr};
  TArrow *ArrowNorthHitTime {nullptr};
  TText *TextNorthHitTime {nullptr};
  TF1 *FitNorthHitTime {nullptr};

  TH2 *TimeWave {nullptr};
  TPad *PadTimeWave {nullptr};

  TH2 *ChargeWave {nullptr};
  TPad *PadChargeWave {nullptr};

  TLine *LineTzeroZvtx[4] {nullptr};
  TText *TextTzeroZvtx {nullptr};

  TPad *PadBbcSummary {nullptr};
  // TText * TextBbcSummaryHitTime {nullptr};
  TText *TextBbcSummaryHitTime[2] {nullptr};
  TText *TextBbcSummaryGlobalOffset[2] {nullptr};
  TText *TextBbcSummaryZvertex {nullptr};
  // TText * TextBbcSummaryTrigRate {nullptr};
  TLatex *TextBbcSummaryTrigRate {nullptr};

  TH1 *Zvtx{nullptr};
  TH1 *Zvtx_alltrigger{nullptr};
  TH1 *Zvtx_ns{nullptr};
  TH1 *Zvtx_10{nullptr};
  TH1 *Zvtx_30{nullptr};
  TH1 *Zvtx_60{nullptr};
  TH1 *Zvtx_10_chk{nullptr};
  TH1 *Zvtx_30_chk{nullptr};
  TH1 *Zvtx_60_chk{nullptr};
  TH1 *Zvtx_zdcns{nullptr};
  TH1 *Zvtx_emcal{nullptr};
  TH1 *Zvtx_hcal{nullptr};
  TH1 *Zvtx_emcalmbd{nullptr};
  TH1 *Zvtx_hcalmbd{nullptr};
  TF1 *FitZvtx {nullptr};
  TLine *LineZvtx[2] {nullptr};
  TArrow *ArrowZvtx {nullptr};
  TText *TextZvtx {nullptr};
  TText *TextZvtxNorth {nullptr};
  TText *TextZvtxSouth {nullptr};

  TH2 *ArmHit {nullptr};
  TPad *PadArmHit {nullptr};
  TText *TextArmHit {nullptr};
  TArc *ArcArmHit {nullptr};

  // for 3rd Page
  // Triggered Monitor
  TH1 *South_Nhit{ nullptr };
  TH1 *North_Nhit{ nullptr };
  TH1 *Nhit_emcal[2]{ nullptr };
  TH1 *Nhit_hcal[2]{ nullptr};
  TH1 *Nhit_emcalmbd[2]{ nullptr};
  TH1 *Nhit_hcalmbd[2]{ nullptr};
  TPad *PadNhits{ nullptr };
  TPad *PadNhitsHCAL{ nullptr };
  TPad *PadNhitsEMCAL{ nullptr };
  TPad *PadZvtx{ nullptr };
  TPad *PadZvtxHCAL{ nullptr };
  TPad *PadZvtxEMCAL{ nullptr };

  TH1 *SouthChargeSum {nullptr};
  TH1 *NorthChargeSum {nullptr};
  TPad *PadChargeSum {nullptr};
  TText *TextSouthChargeSum {nullptr};
  TText *TextNorthChargeSum {nullptr};

  TPad *PadButton {nullptr};
  TPad *PadMultiView {nullptr};
  TH1 *MultiView1F {nullptr};
  TH2 *MultiView2F {nullptr};
  TPad *PadWarnings {nullptr};
  TPaveText *PaveWarnings {nullptr};

  TPad *PadAdc {nullptr};
  TH2 *Adc {nullptr};

  // for 4th Page
  // It is for Only Expert
  TPad *PadTzeroZVertex {nullptr};
  TText *TextZVertexExpress {nullptr};
  TText *TextZVertexNotice {nullptr};
  TGraphErrors *TdcOver[nSIDE] {nullptr};
  TPad *PadTdcOver[nSIDE] {nullptr};
  TLine *LineTdcOver[nSIDE][2] {{nullptr}};
  TBox *BoxTdcOver[nSIDE] {nullptr};
  TH1 *FrameTdcOver[nSIDE] {nullptr};

  TGraph *nHit[nTRIGGER][nSIDE] {{nullptr}};
  TPad *PadnHit[nSIDE] {nullptr};
  TLine *LinenHit[nTRIGGER][nSIDE][2] {{nullptr}};
  TBox *BoxnHit[nTRIGGER][nSIDE] {nullptr};
  TPad *PadnHitStatus {nullptr};
  TText *TextnHitStatus {nullptr};
  TH1 *FramenHit[nSIDE] {nullptr};


  //  TText * TextZVertex[3] = {};
  // TText * TextZVertex_scale[3] = {};
  // TText * TextZVertex[4] = {};
  // TText * TextZVertex_scale[4] = {};
  // TText * TextZVertex_mean[4] = {};
  TText *TextZVertex[5] {nullptr};        // RUN11 pp
  TText *TextZVertex_scale[5] {nullptr};  // RUN11 pp
  TText *TextZVertex_mean[5] {nullptr};   // RUN11 pp

  TLatex *TextZvtxStatus[3] {nullptr};

  TH2 *TzeroZvtx {nullptr};

  // Scale down factor
  TH1 *Prescale_hist {nullptr};
  TSpectrum *tspec {nullptr};

 private:
  int DrawDeadServer(TPad *transparent_pad) override;
};

#endif /* BBC_BBCMONDRAW_H */
