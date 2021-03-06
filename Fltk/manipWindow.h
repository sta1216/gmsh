// Gmsh - Copyright (C) 1997-2018 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues

#ifndef _MANIP_WINDOW_H_
#define _MANIP_WINDOW_H_

#include <FL/Fl_Window.H>
#include <FL/Fl_Value_Input.H>

class manipWindow {
public:
  Fl_Window *win;
  Fl_Value_Input *value[9];

public:
  manipWindow(int deltaFontSize);
  void update(bool force = false);
  void show();
};

void manip_cb(Fl_Widget *w, void *data);

#endif
