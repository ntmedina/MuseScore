//=============================================================================
//  MuseScore
//  Music Composition & Notation
//
//  Copyright (C) 2017 Werner Schweer and others
//
//  This program is free software; you can redistribute it and/or modify
//  it under the terms of the GNU General Public License version 2
//  as published by the Free Software Foundation and appearing in
//  the file LICENSE.GPL
//=============================================================================

#include "inspector.h"
#include "libmscore/element.h"
#include "inspectorElementBase.h"

namespace Ms {

//---------------------------------------------------------
//   InspectorElementBase
//---------------------------------------------------------

InspectorElementBase::InspectorElementBase(QWidget* parent)
   : InspectorBase(parent)
      {
      e.setupUi(addWidget());
      iList = {
            { P_ID::VISIBLE,   0, 0, e.visible,    e.resetVisible   },
            { P_ID::Z,         0, 0, e.z,          e.resetZ         },
            { P_ID::COLOR,     0, 0, e.color,      e.resetColor     },
            { P_ID::USER_OFF,  0, 0, e.offsetX,    e.resetX         },
            { P_ID::USER_OFF,  1, 0, e.offsetY,    e.resetY         },
            { P_ID::AUTOPLACE, 0, 0, e.autoplace,  e.resetAutoplace },
            };
      pList = { { e.title, e.panel } };
      connect(e.resetAutoplace, SIGNAL(clicked()), SLOT(resetAutoplace()));
      connect(e.autoplace, SIGNAL(toggled(bool)),  SLOT(autoplaceChanged(bool)));
      }

//---------------------------------------------------------
//   setElement
//---------------------------------------------------------

void InspectorElementBase::setElement()
      {
      InspectorBase::setElement();
      autoplaceChanged(inspector->element()->autoplace());
      }

//---------------------------------------------------------
//   autoplaceChanged
//---------------------------------------------------------

void InspectorElementBase::autoplaceChanged(bool val)
      {
      for (auto i : std::vector<QWidget*>
         { e.xLabel, e.yLabel, e.offsetX, e.offsetY, e.resetX, e.resetY, e.hRaster, e.vRaster }
         ) {
            i->setVisible(!val);
            }
      }

//---------------------------------------------------------
//   resetAutoplace
//---------------------------------------------------------

void InspectorElementBase::resetAutoplace()
      {
      autoplaceChanged(true);
      }

} // namespace Ms


