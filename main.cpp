#include <wx/wx.h>

class MyFrame : public wxFrame {
 public:
  MyFrame(const wxString& title, const wxPoint& pos, const wxSize& size)
      : wxFrame(NULL, wxID_ANY, title, pos, size) {
    Connect(wxEVT_PAINT, wxPaintEventHandler(MyFrame::OnPaint));
  }

  void OnPaint(const wxPaintEvent& event) {
    wxPaintDC dc(this);  // Создаем контекст устройства для рисования
    dc.SetBackground(
        wxBrush(wxColour(255, 255, 255)));  // Устанавливаем белый фон
    dc.Clear();  // Заполняем окно белым цветом

    wxPen pen(*wxBLACK);
    dc.SetPen(pen);

    // Рисуем точку
    dc.DrawPoint(50, 50);
  }
};

class MyApp : public wxApp {
 public:
  virtual bool OnInit() {
    MyFrame* frame =
        new MyFrame("Larger Point Example", wxPoint(50, 50), wxSize(800, 600));
    frame->Show(true);
    return true;
  }
};

wxIMPLEMENT_APP(MyApp);
