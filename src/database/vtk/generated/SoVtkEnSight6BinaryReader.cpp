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

#include "SoVtkEnSight6BinaryReader.h"
#include "SoVtkUtils.h"

#include "vtkAlgorithmOutput.h"
#include "vtkDataSet.h"
#include "vtkMultiBlockDataSet.h"

SO_ENGINE_SOURCE( SoVtkEnSight6BinaryReader )

SoVtkEnSight6BinaryReader::SoVtkEnSight6BinaryReader()
{
	SO_ENGINE_CONSTRUCTOR(SoVtkEnSight6BinaryReader);

	mObject = vtkEnSight6BinaryReader::New();
	mObject->Register(0);
	mObject->SetGlobalWarningDisplay(0);

	vtkEnSight6BinaryReader *aEnSight6BinaryReader = vtkEnSight6BinaryReader::New();
	double *x = 0;
	int *y = 0;
	float *z = 0;

	SO_ENGINE_ADD_INPUT(ByteOrder, (0));
	ByteOrder.setValue(aEnSight6BinaryReader->GetByteOrder());

	SO_ENGINE_ADD_INPUT(TimeValue, (0));
	SO_ENGINE_ADD_INPUT(FilePath, (""));

	SO_ENGINE_ADD_INPUT(NumberOfInputConnections, ());
	NumberOfInputConnections.setFormat("int int");

	SO_ENGINE_ADD_INPUT(CaseFileName, (""));

	SO_ENGINE_ADD_INPUT(InputConnection, (0));

	SO_ENGINE_ADD_INPUT(ReadAllVariables, (0));
	ReadAllVariables.setValue(aEnSight6BinaryReader->GetReadAllVariables());

	aEnSight6BinaryReader->Delete();


	SO_ENGINE_ADD_OUTPUT( Output, SoSFVtkObject );
	mOutput = 0;
	SO_ENGINE_ADD_OUTPUT( OutputPort, SoSFVtkAlgorithmOutput );
	mOutputPort = 0;


	addCalled = 0;
}

SoVtkEnSight6BinaryReader::~SoVtkEnSight6BinaryReader()
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
	
	if ( mObject )
	{
		mObject->UnRegister(0);
		mObject->Delete();
		mObject = 0;
	}
	

}

void SoVtkEnSight6BinaryReader::initClass()
{
	SO_ENGINE_INIT_CLASS( SoVtkEnSight6BinaryReader, SoEngine, "Engine" );
}

void SoVtkEnSight6BinaryReader::evaluate()
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

	}
	catch(...)
	{
		SoDebugError::post( __FILE__, "Unknown Exception" );
		return;
	}
	SO_ENGINE_OUTPUT( Output, SoSFVtkObject, setValue( mOutput ) );
	SO_ENGINE_OUTPUT( OutputPort, SoSFVtkAlgorithmOutput, setValue( mOutputPort ) );
}


void SoVtkEnSight6BinaryReader::inputChanged(SoField * f)
{
	// Get the ByteOrder value
	if ( f == &ByteOrder )
		SO_VTK_SET_FIELD_VALUE( mObject, ByteOrder);

	// Get the TimeValue value
	if ( f == &TimeValue )
		SO_VTK_SET_FIELD_VALUE( mObject, TimeValue);

	// Get the FilePath value
	if ( f == &FilePath )
		SO_VTK_SET_FIELD_MFSTRING( mObject, FilePath);

	// Get the NumberOfInputConnections value
	if ( f == &NumberOfInputConnections )
	{
		SbVariant *vNumberOfInputConnections = (SbVariant *)NumberOfInputConnections.getValues(0);
		SoInput input;
		int nb_fields = NumberOfInputConnections.getNum();

		int val0;
		int val1;
		for (int i=0; i < nb_fields; i++)
		{
			input.setBuffer((void *)vNumberOfInputConnections[i].getField().getString(),256);
			input.read(val0);
			input.read(val1);
			//mObject->SetNumberOfInputConnections( (int) val0, (int) val1 );
		}
	}

	// Get the CaseFileName value
	if ( f == &CaseFileName )
		SO_VTK_SET_FIELD_MFSTRING( mObject, CaseFileName);

	// Get the ReadAllVariables value
	if ( f == &ReadAllVariables )
		SO_VTK_SET_FIELD_VALUE( mObject, ReadAllVariables);

	mObject->Update();
}

void SoVtkEnSight6BinaryReader::reset()
{
	mObject->UnRegister(0);
	mObject->Delete();
	mObject = 0;
	mObject = vtkEnSight6BinaryReader::New();
	mObject->Register(0);
	mObject->SetGlobalWarningDisplay(0);
	// Get the input type(s)
	SoVtkAlgorithmOutput *inputPortPtr = InputConnection.getValue();
	
	if (inputPortPtr)
		mObject->SetInputConnection(inputPortPtr->getPointer());

	// Get the ByteOrder value
	
		SO_VTK_SET_FIELD_VALUE( mObject, ByteOrder);

	// Get the TimeValue value
	
		SO_VTK_SET_FIELD_VALUE( mObject, TimeValue);

	// Get the FilePath value
	
		SO_VTK_SET_FIELD_MFSTRING( mObject, FilePath);

	// Get the NumberOfInputConnections value
	if (addCalled == 1)
	{
		SbVariant *vNumberOfInputConnections = (SbVariant *)NumberOfInputConnections.getValues(0);
		SoInput input;
		int nb_fields = NumberOfInputConnections.getNum();

		int val0;
		int val1;
		for (int i=0; i < nb_fields; i++)
		{
			input.setBuffer((void *)vNumberOfInputConnections[i].getField().getString(),256);
			input.read(val0);
			input.read(val1);
			//mObject->SetNumberOfInputConnections( (int) val0, (int) val1 );
		}
	}

	// Get the CaseFileName value
	
		SO_VTK_SET_FIELD_MFSTRING( mObject, CaseFileName);

	// Get the ReadAllVariables value
	
		SO_VTK_SET_FIELD_VALUE( mObject, ReadAllVariables);

	mObject->Update();
}

