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

# include "SoVtkPolyDataMapper.h"
# include "SoVtkUtils.h"

# include "vtkPlanes.h"
# include "vtkPolyData.h"
# include "vtkAlgorithmOutput.h"
# include "vtkScalarsToColors.h"


SO_ENGINE_SOURCE( SoVtkPolyDataMapper )

SoVtkPolyDataMapper::SoVtkPolyDataMapper()
{
	SO_ENGINE_CONSTRUCTOR(SoVtkPolyDataMapper);

	mObject = vtkPolyDataMapper::New();

	mObject->Register(0);mObject->SetGlobalWarningDisplay(0);

	mObject->GlobalWarningDisplayOff();

	vtkPolyDataMapper *aPolyDataMapper = vtkPolyDataMapper::New();
	double *x;
	int *y;

	SO_ENGINE_ADD_INPUT(ScalarRange, (0,0));

	x= aPolyDataMapper->GetScalarRange();
	ScalarRange.setValue(x[0],x[1]);

	SO_ENGINE_ADD_INPUT(ResolveCoincidentTopology, (0));
	ResolveCoincidentTopology.setValue(aPolyDataMapper->GetResolveCoincidentTopology());

	SO_ENGINE_ADD_INPUT(ImmediateModeRendering, (0));
	ImmediateModeRendering.setValue(aPolyDataMapper->GetImmediateModeRendering());

	SO_ENGINE_ADD_INPUT(ScalarMode, (0));
	ScalarMode.setValue(aPolyDataMapper->GetScalarMode());

	SO_ENGINE_ADD_INPUT(GlobalImmediateModeRendering, (0));
	GlobalImmediateModeRendering.setValue(aPolyDataMapper->GetGlobalImmediateModeRendering());

	SO_ENGINE_ADD_INPUT(ClippingPlanes, (0));

	SO_ENGINE_ADD_INPUT(ResolveCoincidentTopologyZShift, (0));
	ResolveCoincidentTopologyZShift.setValue(aPolyDataMapper->GetResolveCoincidentTopologyZShift());

	SO_ENGINE_ADD_INPUT(Input, (0));

	SO_ENGINE_ADD_INPUT(InputArrayToProcess, ());
	InputArrayToProcess.setFormat("int int int int char*");

	SO_ENGINE_ADD_INPUT(NumberOfSubPieces, (0));
	NumberOfSubPieces.setValue(aPolyDataMapper->GetNumberOfSubPieces());

	SO_ENGINE_ADD_INPUT(InputConnection, (0));

	SO_ENGINE_ADD_INPUT(GhostLevel, (0));
	GhostLevel.setValue(aPolyDataMapper->GetGhostLevel());

	SO_ENGINE_ADD_INPUT(UseLookupTableScalarRange, (0));
	UseLookupTableScalarRange.setValue(aPolyDataMapper->GetUseLookupTableScalarRange());

	SO_ENGINE_ADD_INPUT(ScalarMaterialMode, (0));
	ScalarMaterialMode.setValue(aPolyDataMapper->GetScalarMaterialMode());

	SO_ENGINE_ADD_INPUT(NumberOfPieces, (0));
	NumberOfPieces.setValue(aPolyDataMapper->GetNumberOfPieces());

	SO_ENGINE_ADD_INPUT(Piece, (0));
	Piece.setValue(aPolyDataMapper->GetPiece());

	SO_ENGINE_ADD_INPUT(LookupTable, (0));

	SO_ENGINE_ADD_INPUT(ScalarVisibility, (0));
	ScalarVisibility.setValue(aPolyDataMapper->GetScalarVisibility());

	SO_ENGINE_ADD_INPUT(InterpolateScalarsBeforeMapping, (0));
	InterpolateScalarsBeforeMapping.setValue(aPolyDataMapper->GetInterpolateScalarsBeforeMapping());

	SO_ENGINE_ADD_INPUT(Static, (0));
	Static.setValue(aPolyDataMapper->GetStatic());

	SO_ENGINE_ADD_INPUT(RenderTime, (0));
	RenderTime.setValue(aPolyDataMapper->GetRenderTime());

	SO_ENGINE_ADD_INPUT(ColorMode, (0));
	ColorMode.setValue(aPolyDataMapper->GetColorMode());

	aPolyDataMapper->Delete();


	SO_ENGINE_ADD_OUTPUT( OutputPort, SoSFVtkAlgorithmOutput );
	mOutputPort = 0;
	SO_ENGINE_ADD_OUTPUT(Output, SoSFVtkObject );
	mOutput = 0;

}

SoVtkPolyDataMapper::~SoVtkPolyDataMapper()
{
	// Deletion of the objects if they exist
	if ( mOutputPort )
	{
	
		mOutputPort->unref();
		mOutputPort = 0;
	}
	
	if ( mOutput )
	{
	
		mOutput->unref();
		mOutput = 0;
	}
	
	if ( mObject )
	{
		mObject->UnRegister(0);
		mObject->Delete();
		mObject = 0;
	}
	

}

void SoVtkPolyDataMapper::initClass()
{
	SO_ENGINE_INIT_CLASS( SoVtkPolyDataMapper, SoEngine, "Engine" );
}

void SoVtkPolyDataMapper::evaluate()
{
	try
	{
		// Deletion of the objects if they exist
		if ( mOutputPort )
		{
		
			mOutputPort->unref();
			mOutputPort = 0;
		}
		
		if ( mOutput )
		{
		
			mOutput->unref();
			mOutput = 0;
		}
		
		// Get the input type(s)
		SoVtkObject *inputPtr = Input.getValue();
		
		if (inputPtr && inputPtr->getPointer()->IsA("vtkPolyData"))
			mObject->SetInput(vtkPolyData::SafeDownCast(inputPtr->getPointer()));

		SoVtkAlgorithmOutput *inputPortPtr = InputConnection.getValue();
		if (inputPortPtr)
			mObject->SetInputConnection(inputPortPtr->getPointer());

		mOutput = new SoVtkObject();
		mOutput->ref();
		mOutput->setPointer( mObject );

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
	SO_ENGINE_OUTPUT( OutputPort, SoSFVtkAlgorithmOutput, setValue( mOutputPort ) );
	SO_ENGINE_OUTPUT( Output, SoSFVtkObject, setValue( mOutput ) );
}


void SoVtkPolyDataMapper::inputChanged(SoField * f)
{
	// Get the ScalarRange value
	if ( f == &ScalarRange )
		SO_VTK_SET_FIELD_VEC2F( mObject, ScalarRange);

	// Get the ResolveCoincidentTopology value
	if ( f == &ResolveCoincidentTopology )
		SO_VTK_SET_FIELD_VALUE( mObject, ResolveCoincidentTopology);

	// Get the ImmediateModeRendering value
	if ( f == &ImmediateModeRendering )
		SO_VTK_SET_FIELD_VALUE( mObject, ImmediateModeRendering);

	// Get the ScalarMode value
	if ( f == &ScalarMode )
		SO_VTK_SET_FIELD_VALUE( mObject, ScalarMode);

	// Get the GlobalImmediateModeRendering value
	if ( f == &GlobalImmediateModeRendering )
		SO_VTK_SET_FIELD_VALUE( mObject, GlobalImmediateModeRendering);

	// Get the ClippingPlanes value
	if ( f == &ClippingPlanes )
		SO_VTK_SET_FIELD_DATA( mObject, ClippingPlanes, vtkPlanes);

	// Get the ResolveCoincidentTopologyZShift value
	if ( f == &ResolveCoincidentTopologyZShift )
		SO_VTK_SET_FIELD_VALUE( mObject, ResolveCoincidentTopologyZShift);

	// Get the InputArrayToProcess value
	if ( f == &InputArrayToProcess )
	{
		SbVariant vInputArrayToProcess = (SbVariant)InputArrayToProcess.getValue();
		SoInput input;
		int val0;
		int val1;
		int val2;
		int val3;
		SbString val4;
	
		input.setBuffer((void *)vInputArrayToProcess.getField().getString(),256);
		input.read(val0);
		input.read(val1);
		input.read(val2);
		input.read(val3);
		input.read(val4);
		mObject->SetInputArrayToProcess( 
			(int) val0,
			(int) val1,
			(int) val2,
			(int) val3,
			val4.getString()
		);
	}
	// Get the NumberOfSubPieces value
	if ( f == &NumberOfSubPieces )
		SO_VTK_SET_FIELD_VALUE( mObject, NumberOfSubPieces);

	// Get the GhostLevel value
	if ( f == &GhostLevel )
		SO_VTK_SET_FIELD_VALUE( mObject, GhostLevel);

	// Get the UseLookupTableScalarRange value
	if ( f == &UseLookupTableScalarRange )
		SO_VTK_SET_FIELD_VALUE( mObject, UseLookupTableScalarRange);

	// Get the ScalarMaterialMode value
	if ( f == &ScalarMaterialMode )
		SO_VTK_SET_FIELD_VALUE( mObject, ScalarMaterialMode);

	// Get the NumberOfPieces value
	if ( f == &NumberOfPieces )
		SO_VTK_SET_FIELD_VALUE( mObject, NumberOfPieces);

	// Get the Piece value
	if ( f == &Piece )
		SO_VTK_SET_FIELD_VALUE( mObject, Piece);

	// Get the LookupTable value
	if ( f == &LookupTable )
		SO_VTK_SET_FIELD_DATA( mObject, LookupTable, vtkScalarsToColors);

	// Get the ScalarVisibility value
	if ( f == &ScalarVisibility )
		SO_VTK_SET_FIELD_VALUE( mObject, ScalarVisibility);

	// Get the InterpolateScalarsBeforeMapping value
	if ( f == &InterpolateScalarsBeforeMapping )
		SO_VTK_SET_FIELD_VALUE( mObject, InterpolateScalarsBeforeMapping);

	// Get the Static value
	if ( f == &Static )
		SO_VTK_SET_FIELD_VALUE( mObject, Static);

	// Get the RenderTime value
	if ( f == &RenderTime )
		SO_VTK_SET_FIELD_VALUE( mObject, RenderTime);

	// Get the ColorMode value
	if ( f == &ColorMode )
		SO_VTK_SET_FIELD_VALUE( mObject, ColorMode);

	//mObject->Update();
	
}
