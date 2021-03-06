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
/*
 * \brief
 * \author Sylvain Jaume, Francois Huguet
 */
 
 
 
# include "SoVtkAppendFilter.h"
# include "SoVtkUtils.h"

# include "vtkAlgorithmOutput.h"
# include "vtkUnstructuredGrid.h"
# include "vtkDataSetCollection.h"


SO_ENGINE_SOURCE( SoVtkAppendFilter )

SoVtkAppendFilter::SoVtkAppendFilter()
{
	SO_ENGINE_CONSTRUCTOR(SoVtkAppendFilter);

	mObject = vtkAppendFilter::New();
	mObject->Register(0);
	mObject->SetGlobalWarningDisplay(0);

	vtkAppendFilter *aAppendFilter = vtkAppendFilter::New();

	SO_ENGINE_ADD_INPUT(InputConnection, (0));

	aAppendFilter->Delete();

	SO_ENGINE_ADD_OUTPUT( Output, SoSFVtkObject );
	mOutput = 0;

	SO_ENGINE_ADD_OUTPUT( OutputPort, SoSFVtkAlgorithmOutput );
	mOutputPort = 0;

	SO_ENGINE_ADD_OUTPUT( oInputList, SoSFVtkObject );
	mInputList = 0;

	addCalled = 0;
}

SoVtkAppendFilter::~SoVtkAppendFilter()
{
	// Deletion of the objects if they exist
	if ( mOutput )
	{
	
		mOutput->unref();
		mOutput = 0;
	}
	
	if ( mOutputPort )
	{
	
		mOutputPort->unref();
		mOutputPort = 0;
	}
	
	if ( mInputList )
	{
	
		mInputList->unref();
		mInputList = 0;
	}
	
	if ( mObject )
	{
		mObject->UnRegister(0);
		mObject->Delete();
		mObject = 0;
	}
	

}

void SoVtkAppendFilter::initClass()
{
	SO_ENGINE_INIT_CLASS( SoVtkAppendFilter, SoEngine, "Engine" );
}

void SoVtkAppendFilter::evaluate()
{
	try
	{
		// Get the input type(s)
		SoVtkAlgorithmOutput *inputPortPtr = InputConnection.getValue();
		
		if (inputPortPtr)
			mObject->SetInputConnection(inputPortPtr->getPointer());

		// Deletion of the objects if they exist
		if ( mOutput )
		{
		
			mOutput->unref();
			mOutput = 0;
		}
		
		if ( mOutputPort )
		{
		
			mOutputPort->unref();
			mOutputPort = 0;
		}
		
		if ( mInputList )
		{
		
			mInputList->unref();
			mInputList = 0;
		}
		
		if ( addCalled )
		{
			reset();
			addCalled = 0;
		}

		mObject->GetOutput()->Register(0);
		mOutput = new SoVtkObject();
		mOutput->ref();
		mOutput->setPointer( mObject->GetOutput() );

		if ( mObject->GetNumberOfOutputPorts() > 0 )
		{
			mObject->GetOutputPort()->Register(0);
			mOutputPort = new SoVtkAlgorithmOutput();
			mOutputPort->ref();
			mOutputPort->setPointer( mObject->GetOutputPort() );
		}

		mObject->GetInputList();
		mInputList = new SoVtkObject();
		mInputList->ref();
		mInputList->setPointer( mObject->GetInputList() );

	}
	catch(...)
	{
		SoDebugError::post( __FILE__, "Unknown Exception" );
		return;
	}
	SO_ENGINE_OUTPUT( Output, SoSFVtkObject, setValue( mOutput ) );
	SO_ENGINE_OUTPUT( OutputPort, SoSFVtkAlgorithmOutput, setValue( mOutputPort ) );
	SO_ENGINE_OUTPUT( oInputList, SoSFVtkObject, setValue( mInputList ) );
}


void SoVtkAppendFilter::inputChanged(SoField * f)
{
	mObject->Update();
}

void SoVtkAppendFilter::reset()
{
	mObject->UnRegister(0);
	mObject->Delete();
	mObject = 0;
	mObject = vtkAppendFilter::New();
	mObject->Register(0);
	mObject->SetGlobalWarningDisplay(0);
	// Get the input type(s)
	SoVtkAlgorithmOutput *inputPortPtr = InputConnection.getValue();
	
	if (inputPortPtr)
		mObject->SetInputConnection(inputPortPtr->getPointer());

	mObject->Update();
}

