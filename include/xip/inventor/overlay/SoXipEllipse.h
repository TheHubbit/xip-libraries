/*
 *  COPYRIGHT NOTICE.  Copyright (C) 2007 Siemens Corporate Research, 
 *  Inc. ("caBIG(tm) Participant"). The eXtensible Imaging Platform
 *  (XIP) was created with NCI funding and is part of the caBIG(tm) 
 *  initiative. The software subject to this notice and license 
 *  includes both human readable source code form and machine 
 *  readable, binary, object code form (the "caBIG(tm) Software").
 *  
 *  This caBIG(tm) Software License (the "License") is between 
 *  caBIG(tm) Participant and You.  "You (or "Your") shall mean a 
 *  person or an entity, and all other entities that control, are 
 *  controlled by, or are under common control with the entity.  
 *  "Control" for purposes of this definition means (i) the direct or 
 *  indirect power to cause the direction or management of such 
 *  entity, whether by contract or otherwise, or (ii) ownership of 
 *  fifty percent (50%) or more of the outstanding shares, or (iii) 
 *  beneficial ownership of such entity.
 *  
 *  LICENSE.  Provided that You agree to the conditions described 
 *  below, caBIG(tm) Participant grants You a non-exclusive, 
 *  worldwide, perpetual, fully-paid-up, no-charge, irrevocable, 
 *  transferable and royalty-free right and license in its rights in 
 *  the caBIG(tm) Software, including any copyright or patent rights 
 *  therein that may be infringed by the making, using, selling, 
 *  offering for sale, or importing of caBIG(tm) Software, to (i) 
 *  use, install, access, operate, execute, reproduce, copy, modify, 
 *  translate, market, publicly display, publicly perform, and 
 *  prepare derivative works of the caBIG(tm) Software; (ii) make, 
 *  have made, use, practice, sell, and offer for sale, and/or 
 *  otherwise dispose of caBIG(tm) Software (or portions thereof); 
 *  (iii) distribute and have distributed to and by third parties the 
 *  caBIG(tm) Software and any modifications and derivative works 
 *  thereof; and (iv) sublicense the foregoing rights set out in (i), 
 *  (ii) and (iii) to third parties, including the right to license 
 *  such rights to further third parties.  For sake of clarity, and 
 *  not by way of limitation, caBIG(tm) Participant shall have no 
 *  right of accounting or right of payment from You or Your 
 *  sublicensees for the rights granted under this License.  This 
 *  License is granted at no charge to You.  Your downloading, 
 *  copying, modifying, displaying, distributing or use of caBIG(tm) 
 *  Software constitutes acceptance of all of the terms and 
 *  conditions of this Agreement.  If you do not agree to such terms 
 *  and conditions, you have no right to download, copy, modify, 
 *  display, distribute or use the caBIG(tm) Software.
 *  
 *  1.	Your redistributions of the source code for the caBIG(tm) 
 *      Software must retain the above copyright notice, this list 
 *      of conditions and the disclaimer and limitation of 
 *      liability of Article 6 below.  Your redistributions in 
 *      object code form must reproduce the above copyright notice, 
 *      this list of conditions and the disclaimer of Article 6 in 
 *      the documentation and/or other materials provided with the 
 *      distribution, if any.
 *  2.	Your end-user documentation included with the 
 *      redistribution, if any, must include the following 
 *      acknowledgment: "This product includes software developed 
 *      by Siemens Corporate Research Inc."  If You do not include 
 *      such end-user documentation, You shall include this 
 *      acknowledgment in the caBIG(tm) Software itself, wherever 
 *      such third-party acknowledgments normally appear.
 *  3.	You may not use the names "Siemens Corporate Research, 
 *      Inc.", "The National Cancer Institute", "NCI", "Cancer 
 *      Bioinformatics Grid" or "caBIG(tm)" to endorse or promote 
 *      products derived from this caBIG(tm) Software.  This 
 *      License does not authorize You to use any trademarks, 
 *  	service marks, trade names, logos or product names of 
 *      either caBIG(tm) Participant, NCI or caBIG(tm), except as 
 *      required to comply with the terms of this License.
 *  4.	For sake of clarity, and not by way of limitation, You may 
 *      incorporate this caBIG(tm) Software into Your proprietary 
 *      programs and into any third party proprietary programs.  
 *      However, if You incorporate the caBIG(tm) Software into 
 *      third party proprietary programs, You agree that You are 
 *      solely responsible for obtaining any permission from such 
 *      third parties required to incorporate the caBIG(tm) 
 *      Software into such third party proprietary programs and for 
 *      informing Your sublicensees, including without limitation 
 *      Your end-users, of their obligation to secure any required 
 *      permissions from such third parties before incorporating 
 *      the caBIG(tm) Software into such third party proprietary 
 *      software programs.  In the event that You fail to obtain 
 *      such permissions, You agree to indemnify caBIG(tm) 
 *      Participant for any claims against caBIG(tm) Participant by 
 *      such third parties, except to the extent prohibited by law, 
 *      resulting from Your failure to obtain such permissions.
 *  5.	For sake of clarity, and not by way of limitation, You may 
 *      add Your own copyright statement to Your modifications and 
 *      to the derivative works, and You may provide additional or 
 *      different license terms and conditions in Your sublicenses 
 *      of modifications of the caBIG(tm) Software, or any 
 *      derivative works of the caBIG(tm) Software as a whole, 
 *      provided Your use, reproduction, and distribution of the 
 *      Work otherwise complies with the conditions stated in this 
 *      License.
 *  6.	THIS caBIG(tm) SOFTWARE IS PROVIDED "AS IS" AND ANY 
 *      EXPRESSED OR IMPLIED WARRANTIES (INCLUDING, BUT NOT LIMITED 
 *      TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY, NON-
 *      INFRINGEMENT AND FITNESS FOR A PARTICULAR PURPOSE) ARE 
 *      DISCLAIMED.  IN NO EVENT SHALL SIEMENS CORPORATE RESEARCH 
 *      INC. OR ITS AFFILIATES BE LIABLE FOR ANY DIRECT, INDIRECT, 
 *      INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES 
 *      (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE 
 *      GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR 
 *      BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF 
 *      LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT 
 *      (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT 
 *      OF THE USE OF THIS caBIG(tm) SOFTWARE, EVEN IF ADVISED OF 
 *      THE POSSIBILITY OF SUCH DAMAGE.
 *  
 */

/**
*  @file	SoXipEllipse.h
*  @brief	Declaration of the SoXipEllipse overlay class
*  @author	Julien Gein
**/

#ifndef SOXIPELLIPSE_H
#define SOXIPELLIPSE_H

#include <Inventor/fields/SoSFVec3f.h>
#include <Inventor/fields/SoSFShort.h>
#include <xip/inventor/overlay/SoXipSubShape.h>


/**
*	@class SoXipEllipse
*
* This node is used to draw an ellipse in the current view.
* It is a permanent overlay. User may use multiple instances of this node
* to perform multiple measures, or use this class as a parameter of the
* overlay manager (cf. SoXipOverlayManager)
*
* This overlay can be used as a base class for measurements.
*
*	@see SoXipOverlayManager
*
**/
class XIPIVOVERLAY_API SoXipEllipse : public SoXipManipulableShape
{
	SO_NODE_HEADER( SoXipEllipse );

    /// Center
	SO_XIP_SHAPE_FIELD( center, SoSFVec3f );
    /// Horizontal radius vector
	SO_XIP_SHAPE_FIELD( a, SoSFVec3f );
    /// Vertical radius vector
	SO_XIP_SHAPE_FIELD( b, SoSFVec3f );
    /// Precision: how many points per circle quarter
	SO_XIP_SHAPE_FIELD( precision, SoSFShort );

public:
    /// Constructor
	SoXipEllipse();

    /// Open Inventor class initialization
	static void initClass();

    /**
    *   @brief  Returns wheter the shape is closed or not. Always true for an
    * ellipse.
    *
    *   @return true if the shape is closed, false otherwise
    **/
	virtual SbBool isClosed() const;

    /**
    *   @brief  Apply the given transformation
    *
    * The transformation is applied to the ellipse's center and the scale and
    * rotation extracted from the matrix are applied to the radius vectors.
    *
    *   @param  matrix  transformation matrix
    **/
    virtual void transform( const SbMatrix& matrix );
    
    /**
    *   @brief  Translate the shape by the given offset
    *
    *   @param pos  projection of the mouse position in the view
    **/    
	virtual void translate( const SbVec3f& offset );

    /**
    *   @brief  Callback function called before the shape creation
    *
    **/
	virtual void beforeCreation();

    /**
    *   @brief  Extract shape geometries
    *
    * This method is called by the base class to retrieve the points and segments
    * defining the ellipse. 
    *
    *   @param point		output array of points
    *   @param coordIndex	output array of point indices
    *   @param closed		is the shape closed?
	*
    **/
	virtual void extractGeometries( SoMFVec3f& point, SoMFInt32& coordIndex, SbBool& closed );
	
protected:
    /// Destructor
	~SoXipEllipse();

    /**
    *   @brief  Send a Mouse Down event to the ellipse
    *
    *   @param pos  projection of the mouse position in the view
    **/
	virtual void mouseDown( const SbVec3f& pos );

    /**
    *   @brief  Send a Mouse Move event to the ellipse
    *
    *   @param pos  projection of the mouse position in the view
    **/
	virtual void mouseMove( const SbVec3f& pos );

    /**
    *   @brief  Send a Mouse Move event to the ellipse
    *
    *   @param pos  projection of the mouse position in the view
    **/    
    virtual void   mouseUp( const SbVec3f& pos );

    /// First point defined by the user, used to compute the ellipse's center
    /// and radius
	SbVec3f			mFirstPoint;
    /// Tell wheter the first point has been defined or not
	bool			mHasFirstPoint;

};

#endif // SOXIPELLIPSE_H