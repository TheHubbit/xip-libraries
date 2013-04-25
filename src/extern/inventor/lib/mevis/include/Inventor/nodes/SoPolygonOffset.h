/*
 *
 *  Copyright (C) 2004 MeVis gGmbH  All Rights Reserved.
 *
 *  This library is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU Lesser General Public
 *  License as published by the Free Software Foundation; either
 *  version 2.1 of the License, or (at your option) any later version.
 *
 *  This library is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 *  Lesser General Public License for more details.
 *
 *  Further, this software is distributed without any warranty that it is
 *  free of the rightful claim of any third person regarding infringement
 *  or the like.  Any license provided herein, whether implied or
 *  otherwise, applies only to this software file.  Patent licenses, if
 *  any, provided herein do not apply to combinations of this program with
 *  other software, or any other product whatsoever.
 *
 *  You should have received a copy of the GNU Lesser General Public
 *  License along with this library; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *
 *  Contact information: MeVis, Center for Medical Diagnostic Systems and
 *  Visualization GmbH, Universitätsallee 29, D-28359 Bremen, GERMANY, or:
 *
 *  http://www.mevis.de
 *
 */

/*
 * Copyright (C) 2004   MeVis Research GmbH
 *
 _______________________________________________________________________
 _______________  M E V I S   R E S E A R C H   G M B H  _______________
 |
 |   $Revision$
 |
 |   Description:
 |   ...
 |
 |   Author(s)      : Felix Ritter
 |
 _______________  M E V I S   R E S E A R C H   G M B H  _______________
 _______________________________________________________________________
 */

#ifndef  _SO_POLYGON_OFFSET_
#define  _SO_POLYGON_OFFSET_

#include <Inventor/system/SbSystem.h>
#include <Inventor/elements/SoPolygonOffsetElement.h>
#include <Inventor/nodes/SoSubNode.h>
#include <Inventor/fields/SoSFBitMask.h>
#include <Inventor/fields/SoSFBool.h>
#include <Inventor/fields/SoSFFloat.h>

class SoAction;
class SoCallbackAction;
class SoGLRenderAction;

class INVENTOR_API SoPolygonOffset : public SoNode
{
   SO_NODE_HEADER(SoPolygonOffset);
   
   typedef SoNode inherited;

   protected:

      virtual ~SoPolygonOffset();

   public:

      enum Style {
         FILLED = SoPolygonOffsetElement::FILLED,
         LINES  = SoPolygonOffsetElement::LINES, 
         POINTS = SoPolygonOffsetElement::POINTS,
         ALL    = SoPolygonOffsetElement::ALL
      };
      
      SoSFFloat    factor;
      SoSFFloat    units;
      SoSFBitMask  styles;
      SoSFBool     on;
      
      SoPolygonOffset();

   SoEXTENDER public:

      virtual void doAction(SoAction *action);
      virtual void callback(SoCallbackAction *action);
      virtual void GLRender(SoGLRenderAction *action);

   SoINTERNAL public:

      static void initClass() ;
};

#endif  // _SO_POLYGON_OFFSET_
