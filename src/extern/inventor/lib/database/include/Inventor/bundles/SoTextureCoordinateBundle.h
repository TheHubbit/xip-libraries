/*
 *
 *  Copyright (C) 2000 Silicon Graphics, Inc.  All Rights Reserved. 
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
 *  Contact information: Silicon Graphics, Inc., 1600 Amphitheatre Pkwy,
 *  Mountain View, CA  94043, or:
 * 
 *  http://www.sgi.com 
 * 
 *  For further information regarding this notice, see: 
 * 
 *  http://oss.sgi.com/projects/GenInfo/NoticeExplan/
 *
 */

//  -*- C++ -*-

/*
 * Copyright (C) 1990,91   Silicon Graphics, Inc.
 *
 _______________________________________________________________________
 ______________  S I L I C O N   G R A P H I C S   I N C .  ____________
 |
 |   $Revision: 1.1.1.1 $
 |
 |   Description:
 |	This file defines the SoTextureCoordinateBundle class.
 |
 |   Author(s)		: Paul S. Strauss
 |
 ______________  S I L I C O N   G R A P H I C S   I N C .  ____________
 _______________________________________________________________________
 */

#ifndef  _SO_TEXTURE_COORDINATE_BUNDLE
#define  _SO_TEXTURE_COORDINATE_BUNDLE

#include <Inventor/bundles/SoBundle.h>
#include <Inventor/elements/SoGLTextureCoordinateElement.h>
#include <Inventor/misc/SoState.h>

//////////////////////////////////////////////////////////////////////////////
//
//  Class: SoTextureCoordinateBundle
//
//  Bundle that allows shapes to deal with texture coordinates more
//  easily. This class provides a fairly simple interface to texture
//  coordinate handling, including default texture coordinate
//  generation. This can be used during either rendering or primitive
//  generation.
//
//  This class can be used during either rendering or primitive
//  generation. For primitive generation, there are two cases,
//  distinguished by the flag returned by isFunction(). If this
//  flag is TRUE, the texture coordinates are to be generated using
//  the get(point, normal) method, which uses a software texture
//  coordinate function. (This process is also used for texture
//  coordinates that are generated by default when necessary - in this
//  case, the function does a linear map across two sides of the
//  bounding box of the shape.) If the isFunction() flag is FALSE, the
//  coordinates are accessed directly from the element using the
//  get(index) method.
//
//  For GL rendering, there is an additional case. If
//  needCoordinates() returns FALSE, no texture coordinates need to be
//  sent at all, and the bundle does not have to be used for anything
//  else. Otherwise, send(index) should be used.
//
//////////////////////////////////////////////////////////////////////////////

SoEXTENDER class INVENTOR_API SoTextureCoordinateBundle : public SoBundle {

  public:
    // Constructor - takes the action the bundle is used for and a
    // flag to indicate whether the bundle is being used for
    // rendering. If this is TRUE, the bundle can be used to send
    // texture coordinates to GL. If it is FALSE, the setUpDefault
    // flag (default TRUE) indicates whether to set up a texture
    // coordinate function if the binding is DEFAULT. Shapes can pass
    // FALSE here if they are picking and want to delay computation of
    // the texture coordinates until an intersection is found.
    SoTextureCoordinateBundle(SoAction *action, SbBool forRendering,
			      SbBool setUpDefault = TRUE);

    // Destructor
    ~SoTextureCoordinateBundle();

    // Returns TRUE if texture coordinates are needed at all
    SbBool		needCoordinates() const	{ return needCoords; }

    // return value to determine which get() to use.
    SbBool		isFunction() const	{ return isFunc; }

    // Returns texture coordinate computed by function during
    // primitive generation or rendering
    SbVec4f 		get(const SbVec3f &point, const SbVec3f &normal) const
	{ return texCoordElt->get(point, normal); }

    // Returns indexed texture coordinate during primitive generation
    // or rendering
    SbVec4f	 	get(int index) const
	{ if (tCoords) return(SbVec4f(tCoords[index][0],tCoords[index][1],
			0.0, 1.0)); 
		else return texCoordElt->get4(index); }

    // Sends indexed texture coordinate to GL during rendering
    void		send(int index) const	{ GLTexCoordElt->send(index); }

  private:
    // TextureCoordinate elements:
    const SoTextureCoordinateElement	*texCoordElt;
    const SoGLTextureCoordinateElement	*GLTexCoordElt;

    SbBool		needCoords;	// Texture coordinates are needed
    SbBool		isFunc;		// Coordinates generated by function
    SbBool		isRendering;	// Bundle being used for rendering
    SbBool		setFunction;	// We set default coord func in state

    // These indicate the dimensions used for S and T for default
    // texture coordinate generation
    int			coordS, coordT;
    // These hold the vectors used for default texture coordinate generation
    SbVec4f		sVector, tVector;
    // This holds the texture coords from a vertexProperty node:
    const SbVec2f *	tCoords;

    // Sets up bundle for primitive generation or rendering
    void		setUpForPrimGen(SoAction *action,
					SbBool setUpDefault);
    void		setUpForGLRender(SoAction *action);

    // Sets up for default texture coordinate generation
    void		setUpDefaultCoordSpace(SoAction *action);

    // Callback registered with SoTextureCoordinateElement for
    // computing texture coordinate from point and normal - used for
    // default coordinate generation. The userData arg will be "this".
    static const SbVec4f &generateCoord(void *userData,
					const SbVec3f &point,
					const SbVec3f &normal);
    
    // Callback registered with SoGLTextureCoordinateElement for
    // setting up GL texture generation for default coordinates. The
    // userData arg will be "this".
    static void		setUpTexGen(void *userData);
};

#endif /* _SO_TEXTURE_COORDINATE_BUNDLE */
