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

#include "SoXipWindowLevelManip.h"
#include <Inventor/events/SoLocation2Event.h>
#include <Inventor/events/SoKeyboardEvent.h>
#include <Inventor/actions/SoHandleEventAction.h>
#include <Inventor/actions/SoActions.h>
#include <Inventor/actions/SoGLRenderAction.h>
#include <Inventor/elements/SoComplexityElement.h>
#include <xip/inventor/core/SoXipWindowLevelElement.h>

const unsigned int MAX_SCREENRESOLUTION = 1024;
const unsigned int STEP = 5;
const float DBCLICK_TIME = .3f;

SO_NODE_SOURCE(SoXipWindowLevelManip);


SoXipWindowLevelManip::SoXipWindowLevelManip()
{
	mComplexity = SoComplexityElement::getDefault();

	mLastEventTime = SbTime::zero();

	SO_NODE_CONSTRUCTOR(SoXipWindowLevelManip);

	SO_NODE_ADD_FIELD(window, (1.f));
	SO_NODE_ADD_FIELD(level, (0.5f));

	SO_NODE_DEFINE_ENUM_VALUE(mouseButtonType, BUTTON1);
	SO_NODE_DEFINE_ENUM_VALUE(mouseButtonType, BUTTON2);
	SO_NODE_DEFINE_ENUM_VALUE(mouseButtonType, BUTTON3);
	SO_NODE_SET_SF_ENUM_TYPE(mouse, mouseButtonType);
	SO_NODE_ADD_FIELD(mouse, (BUTTON2));

	SO_NODE_ADD_FIELD(handleComplexity, (FALSE));

	mDefaultWindow = window.getValue();
	mDefaultLevel = level.getValue();
}


void SoXipWindowLevelManip::initClass()
{
	SO_NODE_INIT_CLASS(SoXipWindowLevelManip, SoNode, "Node");

	SO_ENABLE(SoGLRenderAction, SoComplexityElement);

	SO_ENABLE( SoGLRenderAction,	SoXipWindowLevelElement );
	SO_ENABLE(SoPickAction,     SoXipWindowLevelElement);
	SO_ENABLE(SoCallbackAction, SoXipWindowLevelElement);
}


SoXipWindowLevelManip::~SoXipWindowLevelManip()
{
}


void SoXipWindowLevelManip::handleEvent(SoHandleEventAction *action)
{
	const SoEvent *e = action->getEvent();
	SbBool handled = FALSE;

	if (SO_KEY_PRESS_EVENT(e, PAD_MULTIPLY))
	{
		float w = - (float)STEP / MAX_SCREENRESOLUTION;
		w += window.getValue();
		if (w < 0.f) w = 0.f;
		if (window.getValue() != w)
			window.setValue(w);

		handled = TRUE;
	}
	else if (SO_KEY_PRESS_EVENT(e, PAD_SUBTRACT))
	{
		float w = (float)STEP / MAX_SCREENRESOLUTION;
		w += window.getValue();
		if (w > 1.f) w = 1.f;
		if (window.getValue() != w)
			window.setValue(w);

		handled = TRUE;
	}
	else if (SO_KEY_PRESS_EVENT(e, NUM_LOCK))
	{
		float l = - (float)STEP / MAX_SCREENRESOLUTION;
		l += level.getValue();
		if (l < 0.f) l = 0.f;
		if (level.getValue() != l)
			level.setValue(l);

		handled = TRUE;
	}
	else if (SO_KEY_PRESS_EVENT(e, PAD_DIVIDE))
	{
		float l = (float)STEP / MAX_SCREENRESOLUTION;
		l += level.getValue();
		if (l > 1.f) l = 1.f;
		if (level.getValue() != l)
			level.setValue(l);

		handled = TRUE;
	}
	else if ( SoMouseButtonEvent::isButtonPressEvent( e, (SoMouseButtonEvent::Button)mouse.getValue() ) )
	{
		if ( !action->getGrabber() && !e->wasShiftDown() && !e->wasCtrlDown() && !e->wasAltDown() )
		{
			action->setGrabber(this);
			handled = TRUE;

			mLastMousePosition = e->getPosition();

			mComplexity = (SoComplexityElement::getDefault() - 0.01f) / 2.f;

			if ( (e->getTime() - mLastEventTime).getValue() < DBCLICK_TIME )
				autoWindowing.touch();

			mLastEventTime = e->getTime();
		}
	}
	else if (e->isOfType(SoLocation2Event::getClassTypeId()))
	{
		if (action->getGrabber() == this)
		{
			handled = TRUE;

			SbVec2s diff = e->getPosition() - mLastMousePosition;
			mLastMousePosition = e->getPosition();

			float w = (float)diff[0] / ( 2 * MAX_SCREENRESOLUTION );
			float l = (float)diff[1] / ( 2 * MAX_SCREENRESOLUTION );

			l += level.getValue();
			w += window.getValue();

			if (l > 1.f) l = 1.f;
			if (l < 0.f) l = 0.f;
			if (w > 1.f) w = 1.f;
			if (w < 0.f) w = 0.f;

			if (level.getValue() != l)
				level.setValue(l);
			if (window.getValue() != w)
				window.setValue(w);
		}
	}
	else if (SoMouseButtonEvent::isButtonReleaseEvent(e, (SoMouseButtonEvent::Button) mouse.getValue()) && (action->getGrabber() == this)) 
	{
		action->releaseGrabber();
		handled = TRUE;

		// trigger last update with full complexity
		if (handleComplexity.getValue()) level.touch();

		mComplexity = SoComplexityElement::getDefault();
	}

	if (handled)
	{
		action->setHandled();
	}
}


void SoXipWindowLevelManip::GLRender(SoGLRenderAction *action)
{
	if (handleComplexity.getValue() && (mComplexity < SoComplexityElement::getDefault()))
	{
		float complexity = SoComplexityElement::get(action->getState());
		SoComplexityElement::set(action->getState(), std::min(mComplexity, complexity));
	}

	if (window.getValue() != mDefaultWindow)
	{
		SoXipWindowLevelElement::setWindow( action->getState(), this,window.getValue() );
	}

	if (level.getValue() != mDefaultLevel)
	{
		SoXipWindowLevelElement::setLevel( action->getState(), this,level.getValue() );
	}

	SoNode::GLRender(action);
}


