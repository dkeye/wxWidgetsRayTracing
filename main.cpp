#include "main.h"

#include <format>
#include <iostream>

#include "RayTracingUtils.h"
#include "wx/glcanvas.h"
#include "wx/sizer.h"
#include "wx/wx.h"

// include OpenGL
#ifdef __WXMAC__
#include "OpenGL/gl.h"
#include "OpenGL/glu.h"
#else
#include <GL/gl.h>
#include <GL/glu.h>
#endif

class MyApp : public wxApp {
  virtual bool OnInit();

  wxFrame* frame;
  BasicGLPane* glPane;

 public:
};

IMPLEMENT_APP(MyApp)

bool MyApp::OnInit() {
  wxBoxSizer* sizer = new wxBoxSizer(wxHORIZONTAL);
  frame = new wxFrame((wxFrame*)NULL, -1, wxT("Hello GL World"),
                      wxPoint(50, 50), wxSize(400, 200));

  int args[] = {WX_GL_RGBA, WX_GL_DOUBLEBUFFER, WX_GL_DEPTH_SIZE, 16, 0};

  glPane = new BasicGLPane((wxFrame*)frame, args);
  sizer->Add(glPane, 1, wxEXPAND);

  frame->SetSizer(sizer);
  frame->SetAutoLayout(true);

  frame->Show();
  return true;
}

BEGIN_EVENT_TABLE(BasicGLPane, wxGLCanvas)
EVT_MOTION(BasicGLPane::mouseMoved)
EVT_LEFT_DOWN(BasicGLPane::mouseDown)
EVT_LEFT_UP(BasicGLPane::mouseReleased)
EVT_RIGHT_DOWN(BasicGLPane::rightClick)
EVT_LEAVE_WINDOW(BasicGLPane::mouseLeftWindow)
EVT_SIZE(BasicGLPane::resized)
EVT_KEY_DOWN(BasicGLPane::keyPressed)
EVT_KEY_UP(BasicGLPane::keyReleased)
EVT_MOUSEWHEEL(BasicGLPane::mouseWheelMoved)
EVT_PAINT(BasicGLPane::render)
END_EVENT_TABLE()

// some useful events to use
void BasicGLPane::mouseMoved(wxMouseEvent& event) {}
void BasicGLPane::mouseDown(wxMouseEvent& event) {}
void BasicGLPane::mouseWheelMoved(wxMouseEvent& event) {}
void BasicGLPane::mouseReleased(wxMouseEvent& event) {}
void BasicGLPane::rightClick(wxMouseEvent& event) {}
void BasicGLPane::mouseLeftWindow(wxMouseEvent& event) {}
void BasicGLPane::keyPressed(wxKeyEvent& event) {}
void BasicGLPane::keyReleased(wxKeyEvent& event) {}

BasicGLPane::BasicGLPane(wxFrame* parent, int* args)
    : wxGLCanvas(parent, wxID_ANY, args, wxDefaultPosition, wxDefaultSize,
                 wxFULL_REPAINT_ON_RESIZE) {
  m_context = new wxGLContext(this);
  // To avoid flashing on MSW
  SetBackgroundStyle(wxBG_STYLE_CUSTOM);
}

BasicGLPane::~BasicGLPane() { delete m_context; }

void BasicGLPane::resized(wxSizeEvent& evt) {
  //	wxGLCanvas::OnSize(evt);

  Refresh();
}

/** Inits the OpenGL viewport for drawing in 2D. */
void BasicGLPane::prepare2DViewport(int topleft_x, int topleft_y,
                                    int bottomrigth_x, int bottomrigth_y) {
  glClearColor(0.0f, 0.0f, 0.0f, 1.0f);  // Black Background
  // glEnable(GL_TEXTURE_2D);               // textures
  // glEnable(GL_COLOR_MATERIAL);
  // glEnable(GL_BLEND);
  glDisable(GL_DEPTH_TEST);
  glPointSize(1.0f);
  glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

  glViewport(topleft_x, topleft_y, bottomrigth_x - topleft_x,
             bottomrigth_y - topleft_y);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();

  gluOrtho2D(topleft_x, bottomrigth_x, bottomrigth_y, topleft_y);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
}

int BasicGLPane::getWidth() { return GetSize().x; }

int BasicGLPane::getHeight() { return GetSize().y; }

void BasicGLPane::render(wxPaintEvent& evt) {
  if (!IsShown()) return;

  wxGLCanvas::SetCurrent(*m_context);
  wxPaintDC(this);  // only to be used in paint events. use wxClientDC to paint
                    // outside the paint event

  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  // ------------- draw some 2D ----------------
  int width = getWidth();
  int height = getHeight();
  prepare2DViewport(0, 0, width, height);
  glLoadIdentity();

  std::vector<std::vector<wxColour>> imageColors(width,
                                                 std::vector<wxColour>(height));
  RayTracingUtils::raytrace(width, height, imageColors);
  glBegin(GL_POINTS);
  for (int x = 0; x < width; x++) {
    for (int y = 0; y < height; y++) {
      wxColour color = imageColors[x][y];
      if (color && color != *wxBLACK) {
        glColor4f(color.Red(), color.Green(), color.Blue(), 1);
        // std::cout << std::format("Color: ({},{},{}) Coord: {}:{}", color.Red(),
        //                          color.Green(), color.Blue(), x, y) << std::endl;
        glVertex2f(x, y);
      }
    }
  }
  glEnd();

  glFlush();
  SwapBuffers();
}
