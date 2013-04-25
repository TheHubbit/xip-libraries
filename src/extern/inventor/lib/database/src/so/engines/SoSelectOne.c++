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

/*
 * Copyright (C) 1990,91   Silicon Graphics, Inc.
 *
 _______________________________________________________________________
 ______________  S I L I C O N   G R A P H I C S   I N C .  ____________
 |
 |   $Revision: 1.2 $
 |
 |   Classes:
 |      SelectOne class
 |
 |   Author(s)          : Gavin Bell
 |
 ______________  S I L I C O N   G R A P H I C S   I N C .  ____________
 _______________________________________________________________________
 */

#include <Inventor/engines/SoSelectOne.h>
#include <Inventor/errors/SoDebugError.h>
#include <Inventor/errors/SoReadError.h>
#include <Inventor/fields/SoFields.h>

// Constants for all of the multi-value fields; SelectOne's input can be
// any of the SoMF types, and its output will be the corresponding
// SoSF type.

enum TypeConst {
    BitMask,
    Bool,
    Color,
    Enum,
    Float,
    Int32,
    Matrix,
    Name,
    Node,
    Path,
    Plane,
    Rotation,
    Short,
    String,
    Time,
    UInt32,
    UShort,
    Vec2f,
    Vec3f,
    Vec4f,
    BAD_TYPE
};    

//
// Can't use regular SO_ENGINE_SOURCE macro because of the funky
// handling of getFieldData/getEngineOutputData:
//
SO__ENGINE_VARS(SoSelectOne);

////////////////////////////////////////////////////////////////////////
//
// Description:
//    Constructor; takes the type of SoSelectOne desired:
//
// Use: public
//
SoSelectOne::SoSelectOne(SoType inputType)
//
////////////////////////////////////////////////////////////////////////
{
    SO_ENGINE_CONSTRUCTOR(SoSelectOne);
    SO_ENGINE_ADD_INPUT(index, (-1));

    myInputData = new SoFieldData(inputData);
    myOutputData = new SoEngineOutputData(outputData);
    input = NULL;
    
    setup(inputType);			// Create input, output
    typeField.setValue(inputType.getName());

    isBuiltIn = TRUE;
}

////////////////////////////////////////////////////////////////////////
//
// Description:
//    Constructor, used only when reading from file:
//
// Use: private
//
SoSelectOne::SoSelectOne()
//
////////////////////////////////////////////////////////////////////////
{
    SO_ENGINE_CONSTRUCTOR(SoSelectOne);
    SO_ENGINE_ADD_INPUT(index, (0));

    myInputData = new SoFieldData(inputData);
    myOutputData = new SoEngineOutputData(outputData);
    input = NULL;

    isBuiltIn = TRUE;
}

////////////////////////////////////////////////////////////////////////
//
// Description:
//    Destructor
//
// Use: private
//
SoSelectOne::~SoSelectOne()
//
////////////////////////////////////////////////////////////////////////
{
    delete myInputData;
    delete myOutputData;
    if (input != NULL) {
	delete input;
	delete output;
    }
}

////////////////////////////////////////////////////////////////////////
//
// Description:
//    Creates input and output fields and input/output data
//
// Use: private
//

void
SoSelectOne::setup(SoType inputType)
//
////////////////////////////////////////////////////////////////////////
{
#ifdef DEBUG
    if (input != NULL) {
	SoDebugError::post("SoSelectOne::setup",
			   "Already initialized!");
    }
#endif

    if (inputType.isDerivedFrom(SoMField::getClassTypeId())) {
	input = (SoMField *)inputType.createInstance();
    } else {
	input = NULL;
    }
    if (input == NULL) {
#ifdef DEBUG
	SoDebugError::post("SoSelectOne::setup",
		   "Couldn't create field of type %s",
			   inputType.getName().getString());
#endif
	conversionCase = BAD_TYPE;
    } else {

	input->setContainer(this);

	// Pass in the static field data as the parent field data for
	// the per-instance field data:
	myInputData->addField(this, "input", input);
    
	output = new SoEngineOutput;
	output->setContainer(this);

	static const char *outputName = "output";
	
// This handy macro sets up conversionCase, which is used to quickly
// decide what types we're converting between at evaluate() time, and
// sets up the type of our output:

#define DECIDE(class) \
	(inputType == SO__CONCAT(SoMF,class)::getClassTypeId()) { \
	     conversionCase = class; \
	     myOutputData->addOutput(this, outputName, output, \
		     SO__CONCAT(SoSF,class)::getClassTypeId()); \
	}			     

	// Set up for which switch to use in evaluate() routine:
	if DECIDE(BitMask)
	else if DECIDE(Bool)
	else if DECIDE(Color)
	else if DECIDE(Enum)
	else if DECIDE(Float)
	else if DECIDE(Int32)
	else if DECIDE(Matrix)
	else if DECIDE(Name)
	else if DECIDE(Node)
	else if DECIDE(Path)
	else if DECIDE(Plane)
	else if DECIDE(Rotation)
	else if DECIDE(Short)
	else if DECIDE(String)
	else if DECIDE(Time)
	else if DECIDE(UInt32)
	else if DECIDE(UShort)
	else if DECIDE(Vec2f)
	else if DECIDE(Vec3f)
	else if DECIDE(Vec4f)
#undef DECIDE
	else {
#ifdef DEBUG
	    SoDebugError::post("SoSelectOne::setup",
			"Can't select field of type %s",
			inputType.getName().getString());
#endif
	    conversionCase = BAD_TYPE;
	}
    }
}    

////////////////////////////////////////////////////////////////////////
//
// Description:
//    Redefines this to create an instance of the correct type.
//
// Use: internal, virtual

SoFieldContainer *
SoSelectOne::copyThroughConnection() const
//
////////////////////////////////////////////////////////////////////////
{
    // See SoEngine::copyThroughConnection() for details of this...
    SoFieldContainer *copy = findCopy(this, TRUE);
    if (copy != NULL)
	return copy;
    if (shouldCopy()) {
	// Create and add a new instance to the dictionary
	SoType inputType = SoType::fromName(typeField.getValue());
	SoEngine *newEngine = new SoSelectOne(inputType);
	newEngine->ref();
	addCopy(this, newEngine);		// Adds a ref()
	newEngine->unrefNoDelete();

	// Find the copy and return it; this has the side effect of
	// copying the contents and letting the dictionary know it has
	// been copied once.
	return findCopy(this, TRUE);
    }

    // Otherwise, just return this
    return (SoFieldContainer *) this;
}

////////////////////////////////////////////////////////////////////////
//
// Description:
//    Select the appropriate value and write it to output.
//
// Use: private
//

void
SoSelectOne::evaluate() 
//
////////////////////////////////////////////////////////////////////////
{
    // For efficiency and to reduce bloat, we don't use the standard
    // SO_ENGINE_OUTPUT macro:

    if (!output->isEnabled()) return;

    int whichIndex = (int) index.getValue();			 
    if (whichIndex < 0) return;

    if (whichIndex >= input->getNum()) {
	SoDebugError::post("SoSelectOne::evaluate",
			   "Index (%d) out of range (0-%d)",
			   whichIndex, input->getNum() - 1);
	return;
    }

    for (int i = 0; i < output->getNumConnections(); i++) {
	SoField *outField = (*output)[i];
	if (outField->isReadOnly()) continue;
	
// Handy macro for doing a type-correct operator[] and setValue():
#define CASE(class) \
  case class: ((SO__CONCAT(SoSF,class) *)outField)->setValue( \
    (*((SO__CONCAT(SoMF,class) *)input))[whichIndex]); \
    break
				 
	switch(conversionCase) {
	    CASE(BitMask);
	    CASE(Bool);
	    CASE(Color);
	    CASE(Enum);
	    CASE(Float);
	    CASE(Int32);
	    CASE(Matrix);
	    CASE(Name);
	    CASE(Node);
	    CASE(Path);
	    CASE(Plane);
	    CASE(Rotation);
	    CASE(Short);
	    CASE(String);
	    CASE(Time);
	    CASE(UInt32);
	    CASE(UShort);
	    CASE(Vec2f);
	    CASE(Vec3f);
	    CASE(Vec4f);
#undef CASE
	  case BAD_TYPE:
	    ; // Do nothing, already complained
	    break;
	  default:
	    // Something is seriously wrong:
#ifdef DEBUG
	    SoDebugError::post("SoSelectOne::evaluate",
			   "conversionCase is %d!", conversionCase);
#endif
	    break;
	}
    }
}

////////////////////////////////////////////////////////////////////////
//
// Description:
//    Returns type id.
//
// Use: public
//
SoType
SoSelectOne::getTypeId() const
//
////////////////////////////////////////////////////////////////////////
{
    return classTypeId;
}

////////////////////////////////////////////////////////////////////////
//
// Description:
//    Returns field data
//
// Use: internal
//
const SoFieldData *
SoSelectOne::getFieldData() const 
//
////////////////////////////////////////////////////////////////////////
{
    return myInputData;
}


////////////////////////////////////////////////////////////////////////
//
// Description:
//    Returns output date
//
// Use: internal
//
const SoEngineOutputData *
SoSelectOne::getOutputData() const
//
////////////////////////////////////////////////////////////////////////
{
    return myOutputData;
}

////////////////////////////////////////////////////////////////////////
//
// Description:
//    Create an instance of the class, using private constructor.
//    Used only by database when reading in from file.
//
// Use: internal
//
void *
SoSelectOne::createInstance()
//
////////////////////////////////////////////////////////////////////////
{
    return new SoSelectOne;
}

////////////////////////////////////////////////////////////////////////
//
// Description:
//    Special read code needed to read in type of SelectOne engine.
//
// Use: private

SbBool
SoSelectOne::readInstance(SoInput *in, unsigned short flags)
//
////////////////////////////////////////////////////////////////////////
{
    SbName typeName;
    if (!in->read(typeName, TRUE) ||
		typeName != "type" || !typeField.read(in, "type")) {

	SoReadError::post(in, "SoSelectOne is missing type field");
	return FALSE;
    }

    SoType inputType = SoType::fromName(typeField.getValue());
    if (! inputType.isDerivedFrom(SoMField::getClassTypeId())) {
	SoReadError::post(in, "\"%s\" is not a type of MField",
			  typeField.getValue().getString());
	return FALSE;
    }
    
    setup(inputType);

    return SoEngine::readInstance(in, flags);
}

////////////////////////////////////////////////////////////////////////
//
// Description:
//    Special write code to write out type info
//
// Use: private

void
SoSelectOne::writeInstance(SoOutput *out)
//
////////////////////////////////////////////////////////////////////////
{
    if (! writeHeader(out, FALSE, TRUE)) {

	// Write type info
	typeField.write(out, "type");

	const SoFieldData *fieldData = getFieldData();

	if (fieldData != NULL)
	    fieldData->write(out, this);

	writeFooter(out);
    }
}    
