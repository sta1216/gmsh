// Gmsh - Copyright (C) 1997-2018 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues

#ifndef _PVIEW_AS_SIMPLEFUNCTION_H
#define _PVIEW_AS_SIMPLEFUNCTION_H

#include "simpleFunction.h"

class PView;

class PViewEvaluator : public simpleFunction<double> {
  PView *_pv;
  int _step;

public:
  PViewEvaluator(PView *pv) : _pv(pv), _step(0) {}
  double operator()(double x, double y, double z) const;
  void setStep(int s) { _step = s; }
};

#endif
