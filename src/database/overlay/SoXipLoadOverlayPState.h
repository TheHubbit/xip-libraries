/*
Copyright (c) 2011, Siemens Corporate Research a Division of Siemens Corporation 
All rights reserved.

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

  http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
*/
/**
*	@file    SoXipLoadOverlayPState.h
*	@brief   Declaration of the SoXipLoadOverlayPState class
*	@author  Babu Samuel
**/

#ifndef SOXIPLOADOVERLAYPSTATE_H
#define SOXIPLOADOVERLAYPSTATE_H

#include <Inventor/engines/SoSubEngine.h>
#include <xip/inventor/dicom/SoXipSFPState.h>

class SoXipPState;
class SoXipShape;
class SoXipShapeList;


class SoXipLoadOverlayPState : public SoEngine
{
	SO_ENGINE_HEADER(SoXipLoadOverlayPState);

public:
	SoXipLoadOverlayPState();
	static void initClass();

protected:
	virtual ~SoXipLoadOverlayPState();

public:
	SoXipSFPState		presentationstate;;		// Input

	SoEngineOutput		overlays;				// Output (SoMFNode)

protected:
	/// Engines evaluate method
	virtual void evaluate();

	SoXipShapeList* mShapeList;

private:
	// creates new shape 
	SoXipShape* createNewShape(const SbString classname);
};


#endif // SOXIPLOADOVERLAYPSTATE_H
