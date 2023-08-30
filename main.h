#pragma once

#include <wx/wx.h>

class MyFrame : public wxFrame {
 public:
  MyFrame(const wxChar* title, int xpos, int ypos, int width, int height);
  bool OnInit();
  void OnPaint(wxPaintEvent& event);

  ~MyFrame();
};

class MyApp : public wxApp {
 public:
  /** Initialize the application */
  virtual bool OnInit();
};

DECLARE_APP(MyApp)
