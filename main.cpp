#include "main.h"

#include <wx/wx.h>

#include <cmath>
#include <limits>
#include <tuple>
#include <vector>

#include "Camera.h"
#include "Geometry.h"
#include "RayTracingUtils.h"
#include "Vector3d.h"

MyFrame::MyFrame(const wxChar* title, int xpos, int ypos, int width, int height)
    : wxFrame((wxFrame*)NULL, -1, title, wxPoint(xpos, ypos),
              wxSize(width, height)) {
  Connect(wxEVT_PAINT, wxPaintEventHandler(MyFrame::OnPaint));
}

// MyFrame::MyFrame(const wxString& title, const wxPoint& pos, const wxSize&
// size)
//     : wxFrame(NULL, wxID_ANY, title, pos, size, wxCAPTION | wxCLOSE_BOX) {
//   Connect(wxEVT_PAINT, wxPaintEventHandler(MyFrame::OnPaint));
// }

void MyFrame::OnPaint(wxPaintEvent& event) {
  wxPaintDC dc(this);
  auto [width, height] = GetSize();
  std::vector<std::vector<wxColour>> imageColors(width,
                                                 std::vector<wxColour>(height));
  RayTracingUtils::raytrace(width, height, imageColors);
  wxImage image(width, height);
  for (int y = 0; y < height; y++) {
    for (int x = 0; x < width; x++) {
      // Задаем цвет пикселя
      image.SetRGB(x, y, imageColors[x][y].Red() % 256,
                   imageColors[x][y].Green() % 256,
                   imageColors[x][y].Blue() % 256);
    }
  }

  // Отображаем изображение
  wxBitmap bitmap(image);
  dc.DrawBitmap(bitmap, 0, 0);
}

MyFrame::~MyFrame() {}

bool MyApp::OnInit() {
  MyFrame* frame = new MyFrame(wxT("Simple Text Editor"), 50, 50, 800, 600);
  frame->Show(true);
  return true;
}

wxIMPLEMENT_APP(MyApp);
