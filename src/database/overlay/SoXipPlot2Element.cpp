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
*	@file	SoXipPlot2Element.cpp
*	@brief	Implementation of the SoXipPlot2Element class
*	@author	Julien Gein
**/

#include <xip/inventor/overlay/SoXipPlot2Element.h>
#include <xip/inventor/overlay/SbXipPlot2LegendInfo.h>
#include <Inventor/elements/SoLinePatternElement.h>
#include <Inventor/elements/SoLineWidthElement.h>
#include <Inventor/elements/SoPointSizeElement.h>
#include <Inventor/elements/SoLazyElement.h>

SO_ELEMENT_SOURCE( SoXipPlot2Element );

void 
SoXipPlot2Element::initClass()
{
	SO_ELEMENT_INIT_CLASS( SoXipPlot2Element, SoAccumulatedElement );
}

SoXipPlot2Element::~SoXipPlot2Element()
{

}

void
SoXipPlot2Element::init( SoState* )
{
	mPlotInfoList.truncate(0);
	mStartIndex = 0;
}

void 
SoXipPlot2Element::add( SoState* state, SoNode* node, const SbString& label,
	float lineWidth, unsigned short linePattern, const SbColor& lineColor,
	int markerType, float markerSize, const SbColor& markerColor )
{
	SoXipPlot2Element* elt = (SoXipPlot2Element *) getElement(state, classStackIndex);

	if (elt) 
	{
		SbXipPlot2LegendInfo* newPlotInfo = new SbXipPlot2LegendInfo;
		if (newPlotInfo)
		{
			newPlotInfo->label = label;
			newPlotInfo->lineWidth = lineWidth;;
			newPlotInfo->linePattern = linePattern;
			newPlotInfo->lineColor = lineColor;
			newPlotInfo->markerType = markerType;
			newPlotInfo->markerSize = markerSize;
			newPlotInfo->markerColor = markerColor;
			newPlotInfo->isArea = FALSE;
			newPlotInfo->isLine = TRUE;

			elt->mPlotInfoList.append(newPlotInfo);
		}

		// Update node id list in element
		elt->addNodeId(node);
	}
}

void
SoXipPlot2Element::add( SoState* state, SoNode* node, const SbString& label, int markerType, const SbColor& markerColor )
{
	SoXipPlot2Element* elt = (SoXipPlot2Element *) getElement(state, classStackIndex);
	
	if (elt) 
	{
		SbXipPlot2LegendInfo* newPlotInfo = new SbXipPlot2LegendInfo;
		if (newPlotInfo)
		{
			newPlotInfo->label = label;
			newPlotInfo->markerType = markerType;
			newPlotInfo->markerSize = SoPointSizeElement::get(state);
			newPlotInfo->markerColor = markerColor;
			newPlotInfo->isArea = FALSE;
			newPlotInfo->isLine = FALSE;

			elt->mPlotInfoList.append(newPlotInfo);
		}

		// Update node id list in element
		elt->addNodeId(node);
	}
}

void 
SoXipPlot2Element::add( SoState* state, SoNode* node, const SbString& label, const SbColor& lineColor, const SbColor& areaColor )
{
	SoXipPlot2Element* elt = (SoXipPlot2Element *) getElement(state, classStackIndex);

	if (elt) 
	{
		SbXipPlot2LegendInfo* newPlotInfo = new SbXipPlot2LegendInfo;
		if (newPlotInfo)
		{
			newPlotInfo->label = label;
			newPlotInfo->isArea = TRUE;
			newPlotInfo->isLine = FALSE;
			newPlotInfo->lineColor = lineColor;
			newPlotInfo->areaColor = areaColor;

			elt->mPlotInfoList.append(newPlotInfo);
		}

		// Update node id list in element
		elt->addNodeId(node);
	}
}

void 
SoXipPlot2Element::push( SoState* state )
{
	const SoXipPlot2Element* elt = (const SoXipPlot2Element *) getNextInStack();

	mPlotInfoList = elt->mPlotInfoList;
	mStartIndex = mPlotInfoList.getLength();
	nodeIds = elt->nodeIds;
}

void 
SoXipPlot2Element::pop( SoState*, const SoElement* prevTopElement )
{
	const SoXipPlot2Element *prevElt = (const SoXipPlot2Element *) prevTopElement;

	// Free up any plane structures that were created by prevElt
	for (int i = prevElt->mStartIndex; i < prevElt->mPlotInfoList.getLength(); i++)
	{
		delete (SbXipPlot2LegendInfo *) prevElt->mPlotInfoList[i];
	}
}


SoXipPlot2Element*
SoXipPlot2Element::getInstance( SoState* state )
{
	return (SoXipPlot2Element *) getConstElement( state, classStackIndex );
}

int 
SoXipPlot2Element::getNum() const
{
	return (int) mPlotInfoList.getLength();
}

const 
SbXipPlot2LegendInfo& SoXipPlot2Element::getInfo( int index ) const
{
#ifdef DEBUG
	if( index < 0 || index >= mPlotInfoList.getLength() )
		SoDebugError::post("SoXipPlot2Element::getInfo",
		"Index (%d) is out of range 0 - %d",
		index, mPlotInfoList.getLength() - 1);
#endif

	SbXipPlot2LegendInfo* plotInfo = (SbXipPlot2LegendInfo *) mPlotInfoList[index];
	return *plotInfo;
}

const 
SbString& SoXipPlot2Element::getLabel( int index ) const
{
#ifdef DEBUG
	if( index < 0 || index >= mPlotInfoList.getLength() )
		SoDebugError::post("SoXipPlot2Element::getLabel",
		"Index (%d) is out of range 0 - %d",
		index, mPlotInfoList.getLength() - 1);
#endif

	SbXipPlot2LegendInfo* plotInfo = (SbXipPlot2LegendInfo *) mPlotInfoList[index];
	return plotInfo->label;
}

float 
SoXipPlot2Element::getLineWidth( int index ) const
{
#ifdef DEBUG
	if( index < 0 || index >= mPlotInfoList.getLength() )
		SoDebugError::post("SoXipPlot2Element::getLineWidth",
		"Index (%d) is out of range 0 - %d",
		index, mPlotInfoList.getLength() - 1);
#endif

	SbXipPlot2LegendInfo* plotInfo = (SbXipPlot2LegendInfo *) mPlotInfoList[index];
	return plotInfo->lineWidth;
}

unsigned short 
SoXipPlot2Element::getLinePattern( int index ) const
{
#ifdef DEBUG
	if( index < 0 || index >= mPlotInfoList.getLength() )
		SoDebugError::post("SoXipPlot2Element::getLinePattern",
		"Index (%d) is out of range 0 - %d",
		index, mPlotInfoList.getLength() - 1);
#endif

	SbXipPlot2LegendInfo* plotInfo = (SbXipPlot2LegendInfo *) mPlotInfoList[index];
	return plotInfo->linePattern;
}

SbColor 
SoXipPlot2Element::getLineColor( int index ) const
{
#ifdef DEBUG
	if( index < 0 || index >= mPlotInfoList.getLength() )
		SoDebugError::post("SoXipPlot2Element::getLineColor",
		"Index (%d) is out of range 0 - %d",
		index, mPlotInfoList.getLength() - 1);
#endif

	SbXipPlot2LegendInfo* plotInfo = (SbXipPlot2LegendInfo *) mPlotInfoList[index];
	return plotInfo->lineColor;
} 

int
SoXipPlot2Element::getMarkerType( int index ) const
{
#ifdef DEBUG
	if( index < 0 || index >= mPlotInfoList.getLength() )
		SoDebugError::post("SoXipPlot2Element::getMarkerType",
		"Index (%d) is out of range 0 - %d",
		index, mPlotInfoList.getLength() - 1);
#endif

	SbXipPlot2LegendInfo* plotInfo = (SbXipPlot2LegendInfo *) mPlotInfoList[index];
	return plotInfo->markerType;
}

float
SoXipPlot2Element::getMarkerSize( int index ) const
{
#ifdef DEBUG
	if( index < 0 || index >= mPlotInfoList.getLength() )
		SoDebugError::post("SoXipPlot2Element::getMarkerSize",
		"Index (%d) is out of range 0 - %d",
		index, mPlotInfoList.getLength() - 1);
#endif

	SbXipPlot2LegendInfo* plotInfo = (SbXipPlot2LegendInfo *) mPlotInfoList[index];
	return plotInfo->markerSize;
}

SbColor
SoXipPlot2Element::getMarkerColor( int index ) const
{
#ifdef DEBUG
	if( index < 0 || index >= mPlotInfoList.getLength() )
		SoDebugError::post("SoXipPlot2Element::getMarkerColor",
		"Index (%d) is out of range 0 - %d",
		index, mPlotInfoList.getLength() - 1);
#endif

	SbXipPlot2LegendInfo* plotInfo = (SbXipPlot2LegendInfo *) mPlotInfoList[index];
	return plotInfo->markerColor;
} 

SbBool 
SoXipPlot2Element::isLine( int index ) const
{
#ifdef DEBUG
	if( index < 0 || index >= mPlotInfoList.getLength() )
		SoDebugError::post("SoXipPlot2Element::isLine",
		"Index (%d) is out of range 0 - %d",
		index, mPlotInfoList.getLength() - 1);
#endif

	SbXipPlot2LegendInfo* plotInfo = (SbXipPlot2LegendInfo *) mPlotInfoList[index];
	return plotInfo->isLine;
} 

SbBool 
SoXipPlot2Element::isArea( int index ) const
{
#ifdef DEBUG
	if( index < 0 || index >= mPlotInfoList.getLength() )
		SoDebugError::post("SoXipPlot2Element::isArea",
		"Index (%d) is out of range 0 - %d",
		index, mPlotInfoList.getLength() - 1);
#endif

	SbXipPlot2LegendInfo* plotInfo = (SbXipPlot2LegendInfo *) mPlotInfoList[index];
	return plotInfo->isArea;
} 

SbColor 
SoXipPlot2Element::getAreaColor( int index ) const
{
#ifdef DEBUG
	if( index < 0 || index >= mPlotInfoList.getLength() )
		SoDebugError::post("SoXipPlot2Element::getAreaColor",
		"Index (%d) is out of range 0 - %d",
		index, mPlotInfoList.getLength() - 1);
#endif

	SbXipPlot2LegendInfo* plotInfo = (SbXipPlot2LegendInfo *) mPlotInfoList[index];
	return plotInfo->areaColor;
}