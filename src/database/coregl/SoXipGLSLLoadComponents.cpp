/*
 *  COPYRIGHT NOTICE.  Copyright (C) 2005 Siemens Corporate Research, 
 *  Inc. ("caBIG(tm) Participant"). eXtensible Imaging Platform (XIP)
 *  was created with NCI funding and is part of the caBIG(tm) 
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
#include <xip/system/standard.h>
#include <xip/system/GL/gl.h>
#include <xip/inventor/coregl/SoXipShaderProgramElement.h>
#include <xip/inventor/coregl/SoXipGLSLShaderProgramElement.h>
#include <xip/inventor/coregl/ShaderComponentLibrary.h>
#include <xip/inventor/coregl/ShaderProgramManager.h>
#include <xip/inventor/coregl/ShaderSourceComponent.h>

#include "SoXipGLSLLoadComponents.h"

#include <Inventor/actions/SoGLRenderAction.h>
// Used for insertion of defines in shader source
#include <string>
#include <vector>
#include <fstream>
// Used for timestamp lookup on shader source
#include <sys/stat.h>
#include <time.h>


SO_NODE_SOURCE(SoXipGLSLLoadComponents);


SoXipGLSLLoadComponents::SoXipGLSLLoadComponents()
{
	SO_NODE_CONSTRUCTOR(SoXipGLSLLoadComponents);

	SO_NODE_ADD_FIELD(vpFilenames, (""));
    SO_NODE_ADD_FIELD(gpFilenames, (""));
    SO_NODE_ADD_FIELD(fpFilenames, (""));
	
	SO_NODE_ADD_FIELD(vpComponents, (""));
	SO_NODE_ADD_FIELD(gpComponents, (""));
	SO_NODE_ADD_FIELD(fpComponents, (""));
	
	mVpSensor = new SoFieldSensor(fieldChangeCB, this);
	mVpSensor->attach(&this->vpFilenames);
	mGpSensor = new SoFieldSensor(fieldChangeCB, this);
	mGpSensor->attach(&this->gpFilenames);
	mFpSensor = new SoFieldSensor(fieldChangeCB, this);
	mFpSensor->attach(&this->fpFilenames);
	
	mVpComponentsSensor = new SoFieldSensor(fieldChangeCB, this);
	mVpComponentsSensor->attach(&this->vpComponents);
	mGpComponentsSensor = new SoFieldSensor(fieldChangeCB, this);
	mGpComponentsSensor->attach(&this->gpComponents);
	mFpComponentsSensor = new SoFieldSensor(fieldChangeCB, this);
	mFpComponentsSensor->attach(&this->fpComponents);

  	SO_NODE_ADD_FIELD(update, ());

    mUpdateFieldSensor = new SoFieldSensor(updateSensorCB, this);
	mUpdateFieldSensor->attach(&this->update);
	mAutoUpdateTimerSensor = new SoTimerSensor(autoUpdateCB, this);
	mAutoUpdateTimerSensor->setInterval(1.0/3.0);

    SO_NODE_ADD_FIELD(autoUpdate, (false));

    mAutoUpdateCheckboxSensor = new SoFieldSensor(toggleAutoCB, this);
	mAutoUpdateCheckboxSensor->attach(&this->autoUpdate);

    SO_NODE_ADD_FIELD(testCompilation, (false));



	SO_NODE_ADD_FIELD(geometryInputType,  (IN_TRIANGLES));
	SO_NODE_ADD_FIELD(geometryOutputType, (OUT_TRIANGLE_STRIP));
	SO_NODE_ADD_FIELD(maxEmittedVertices, (1));

	SO_NODE_DEFINE_ENUM_VALUE(InGeometry, IN_POINTS);
	SO_NODE_DEFINE_ENUM_VALUE(InGeometry, IN_LINES);
	SO_NODE_DEFINE_ENUM_VALUE(InGeometry, IN_LINES_ADJACENCY_EXT);
	SO_NODE_DEFINE_ENUM_VALUE(InGeometry, IN_TRIANGLES);
	SO_NODE_DEFINE_ENUM_VALUE(InGeometry, IN_TRIANGLES_ADJACENCY_EXT);
	SO_NODE_SET_SF_ENUM_TYPE(geometryInputType, InGeometry);

	SO_NODE_DEFINE_ENUM_VALUE(OutGeometry, OUT_POINTS);
	SO_NODE_DEFINE_ENUM_VALUE(OutGeometry, OUT_LINE_STRIP);
	SO_NODE_DEFINE_ENUM_VALUE(OutGeometry, OUT_TRIANGLE_STRIP);
	SO_NODE_DEFINE_ENUM_VALUE(OutGeometry, OUT_TRIANGLES);
    SO_NODE_SET_SF_ENUM_TYPE(geometryOutputType, OutGeometry);

    mVpComponents.clear();
    mGpComponents.clear();
    mFpComponents.clear();

    mFieldBitmask = 0;
    mTimedUpdate = false;
    mIsAutoOn = false;
}

/**
 *	Destructor
 */	
SoXipGLSLLoadComponents::~SoXipGLSLLoadComponents()
{
    for (unsigned int i = 0; i < mVpComponents.size(); i++)
        if (!mVpComponents[i].isNameEmpty())
            this->removeLibraryEntry(&mVpComponents[i]);

    for (unsigned int i = 0; i < mGpComponents.size(); i++)
        if (!mGpComponents[i].isNameEmpty())
            this->removeLibraryEntry(&mGpComponents[i]);

    for (unsigned int i = 0; i < mFpComponents.size(); i++)
        if (!mFpComponents[i].isNameEmpty())
            this->removeLibraryEntry(&mFpComponents[i]);

    // Delete self
	delete mVpSensor;
	delete mFpSensor;
	delete mGpSensor;
	delete mGpComponentsSensor;
	delete mVpComponentsSensor;
	delete mFpComponentsSensor;

	delete mUpdateFieldSensor;
	delete mAutoUpdateTimerSensor;
	delete mAutoUpdateCheckboxSensor;
}

void SoXipGLSLLoadComponents::fieldChangeCB(void * data, SoSensor * sensor)
{
    // Accumulate bitmask of manipulated fields
    SoXipGLSLLoadComponents * obj = reinterpret_cast<SoXipGLSLLoadComponents *>(data);
    if      (sensor == obj->mVpSensor)
        obj->mFieldBitmask |= VP_FILENAMES;
    else if (sensor == obj->mGpSensor)
        obj->mFieldBitmask |= GP_FILENAMES;
    else if (sensor == obj->mFpSensor)
        obj->mFieldBitmask |= FP_FILENAMES;
    else if (sensor == obj->mVpComponentsSensor)
        obj->mFieldBitmask |= VP_COMPONENTS;
    else if (sensor == obj->mGpComponentsSensor)
        obj->mFieldBitmask |= GP_COMPONENTS;
    else if (sensor == obj->mFpComponentsSensor)
        obj->mFieldBitmask |= FP_COMPONENTS;
}

/**	
 *	Initializes the class
 */
void SoXipGLSLLoadComponents::initClass()
{
	SO_NODE_INIT_CLASS(SoXipGLSLLoadComponents, SoNode, "SoNode");
	SO_ENABLE(SoGLRenderAction, SoXipGLOWElement);
	SO_ENABLE(SoGLRenderAction, SoXipShaderProgramElement);
	SO_ENABLE(SoGLRenderAction, SoXipGLSLShaderProgramElement);
}

/**
 *  One of two main update functions.
 *  Gets triggered by user interaction.
 *  Can be called both from GLRender or from any other scope.
 */
void SoXipGLSLLoadComponents::UpdateAction()
{
    if (vpFilenames.getNum() && !(vpFilenames.getNum() == 1 && vpFilenames[0] == ""))
        this->UpdateComponents(mVpComponents, vpComponents, vpFilenames, GL_VERTEX_SHADER);
    if (gpFilenames.getNum() && !(gpFilenames.getNum() == 1 && gpFilenames[0] == ""))
        this->UpdateComponents(mGpComponents, gpComponents, gpFilenames, GL_GEOMETRY_SHADER_EXT);
    if (fpFilenames.getNum() && !(fpFilenames.getNum() == 1 && fpFilenames[0] == ""))
        this->UpdateComponents(mFpComponents, fpComponents, fpFilenames, GL_FRAGMENT_SHADER);

    mFieldBitmask = 0;
	mTimedUpdate = false;
}

void SoXipGLSLLoadComponents::UpdateComponents(std::vector<ShaderSourceComponent> & compVec, const SoMFString & compMF, const SoMFString & fileMF, GLenum shaderType)
{
    int numC = compMF.getNum();
    int numF = fileMF.getNum();

    if (numC != numF)
    {
        SoDebugError::postWarning("SoXipGLSLLoadComponents", "Number of component names must match number of filenames!");
        return;
    }

    int vecSize = compVec.size();
    if (vecSize != numC)
    {
        if (vecSize > numC)
            compVec.erase(compVec.begin() + numC, compVec.end());
        else
            compVec.insert(compVec.end(), numC-vecSize, ShaderSourceComponent());

        if (compVec.size() != numC)
            return;
    }

    for (int i = 0; i < numC; i++)
    {
        evaluateShaderComponent(&compVec[i], compMF[i], fileMF[i], shaderType);
    }
}

/**
 *  Second out of two main update functions.
 *  Gets triggered by a timer for automatics recompilations.
 *  Can be called both from GLRender or from any other scope.
 */
void SoXipGLSLLoadComponents::AutoUpdateAction()
{
    bool dirty = false;

    if (vpComponents.getNum() == vpFilenames.getNum() && vpComponents.getNum() == mVpComponents.size())
        for (int i = 0; i < vpComponents.getNum(); i++)
            dirty |= checkTimeStamp(&mVpComponents[i], vpFilenames[i]);

    if (gpComponents.getNum() == gpFilenames.getNum() && gpComponents.getNum() == mGpComponents.size())
        for (int i = 0; i < gpComponents.getNum(); i++)
            dirty |= checkTimeStamp(&mGpComponents[i], gpFilenames[i]);

    if (fpComponents.getNum() == fpFilenames.getNum() && fpComponents.getNum() == mFpComponents.size())
        for (int i = 0; i < fpComponents.getNum(); i++)
            dirty |= checkTimeStamp(&mFpComponents[i], fpFilenames[i]);

    if (dirty)
    {
        mTimedUpdate = true;
        startNotify();
    }
}



/**
 *	Concatenates all componets into batch->vSource/gSource/fSource.
 */	
bool SoXipGLSLLoadComponents::updateSingleSource(ShaderSourceComponent * comp, const SbString& compName, const SbString& fileName, GLenum shaderType, std::string& errstr)
{
    if (!comp)
        return false;

    comp->clearContent(); //Saves name and type
    comp->readSourceFile(fileName.getString(), errstr);
    comp->setTimeStamp(time(NULL));

    if (shaderType == GL_GEOMETRY_SHADER_EXT)
    {
        comp->setParameter(GL_GEOMETRY_VERTICES_OUT_EXT, maxEmittedVertices.getValue());
		comp->setParameter(GL_GEOMETRY_INPUT_TYPE_EXT, geometryInputType.getValue());
	    comp->setParameter(GL_GEOMETRY_OUTPUT_TYPE_EXT, geometryOutputType.getValue());
    }

    return true;
}

bool SoXipGLSLLoadComponents::checkTimeStamp(ShaderSourceComponent * comp, const SbString& fileName)
{
    if (!comp)
        return false;

    bool dirty = false;
    if (!comp->isNameEmpty() && fileName != "")
    {
        int tod = ShaderEngine::getSourceFileTimeStamp(fileName.getString());
        int cts = comp->getSourceTimeStamp();
        if (tod > cts /*&& cts*/)
            dirty = true;

        ShaderComponentLibrary * lib = ShaderComponentLibrary::getInstance();
        const ShaderSourceComponent * entry = 0;
        if (lib)
            entry = lib->getEntry(comp->getName());
        if (!entry)
            dirty = true;
        else
            if (entry->getTimeStamp() != comp->getTimeStamp())
                dirty = true;
    }
    return dirty;
}

void SoXipGLSLLoadComponents::setTimeStamp(ShaderSourceComponent * comp, const SbString& fileName)
{
    if (!comp)
        return;

    if (fileName != "")
    {
        int tod = ShaderEngine::getSourceFileTimeStamp(fileName.getString());
        comp->setSourceTimeStamp(tod);
    }
}

/**
 *	Update existing shader batch by per field comparison.
 */
bool SoXipGLSLLoadComponents::updateShaderComponent(ShaderSourceComponent * comp, const SbString& compName, const SbString& fileName, GLenum shaderType, std::string& errstr)
{
    bool dirty = false;

    if (mTimedUpdate)
        dirty |= checkTimeStamp(comp, fileName.getString());

    if (mFieldBitmask)
    {
        switch (shaderType)
        {
        case GL_VERTEX_SHADER :
            dirty |= (mFieldBitmask & (VP_FILENAMES | VP_COMPONENTS)) ? true : false;
            break;
        case GL_GEOMETRY_SHADER_EXT :
            dirty |= (mFieldBitmask & (GP_FILENAMES | GP_COMPONENTS)) ? true : false;
            break;
        case GL_FRAGMENT_SHADER :
            dirty |= (mFieldBitmask & (FP_FILENAMES | FP_COMPONENTS)) ? true : false;
            break;
        default :
            return false;
        }
    }

    if (dirty)
    {
        this->setTimeStamp(comp, fileName);

        this->updateSingleSource(comp, compName, fileName, shaderType, errstr);

        if (!errstr.empty())
            return false;

        if (testCompilation.getValue())
        {
            GLuint dummy = ShaderEngine::compileShader(comp->getFullComponent(), shaderType, errstr);
            ShaderEngine::deleteShader(dummy);
            if (!errstr.empty())
                return false;
        }
    
        comp->setDirty(true);
    }

    return true;
}





/**
 * Update batch entry in ShaderProgramManager singleton.
 * @param batch The shader batch we want to update.
 * @see removeManagerEntry()
 */
void SoXipGLSLLoadComponents::updateLibraryEntry(ShaderSourceComponent * comp)
{
    if (comp)
    {
        if (comp->getName() != "")
        {
            ShaderComponentLibrary * lib = ShaderComponentLibrary::getInstance();
            if (lib)
            {
                lib->insertEntry(*comp);
                SoDebugError::postInfo("Shader Component Library",
                    "Component entry \"%s\" updated",
                    comp->getName());
            }
        }
    }
}

/**
 *  Remove entry in ShaderProgramManager singleton.
 *  @param batch The shader batch we want to update.
 *  @see updateManagerEntry()
 */
void SoXipGLSLLoadComponents::removeLibraryEntry(ShaderSourceComponent * comp)
{
    if (comp)
    {
        ShaderComponentLibrary * lib = ShaderComponentLibrary::getInstance();
        if (lib)
            lib->removeEntry(comp->getName());
    }
}


/**
 *	Compare timestamps in internal list and update if necessary.
 *  Function only executes if no fields have been touched, this way we
 *  avoid costly validation of filenames. No cleaning and synchronizing
 *  need to be done since fields and values are intact.
 */
void SoXipGLSLLoadComponents::evaluateShaderComponent(ShaderSourceComponent * comp, const SbString& compName, const SbString& fileName, GLenum shaderType)
{
    // Reflect component name change in library
    if (comp->getName() != compName.getString())
    {
        if (!comp->isNameEmpty())
            this->removeLibraryEntry(comp);
        comp->clear();
        comp->setName(compName.getString());
        comp->setType(shaderType);
        comp->setDirty(true);
    }

    if (!comp->isOriginEmpty())
        if (std::string(comp->getOrigin()) != std::string(fileName.getString()))
            comp->setDirty(true);

    std::string errstr = "";

    if (compName != "" && fileName != "")
    {
        this->updateShaderComponent(comp, compName, fileName, shaderType, errstr);

        if (!errstr.empty())
        {
            SoDebugError::post("GLSL Load Components", "\"%s\": \"%s\"", comp->getName(), errstr.c_str());
            this->removeLibraryEntry(comp);
        }
    }
    else
        comp->clear();


    if (comp->isDirty())
    {
	    this->updateLibraryEntry(comp);
        comp->setDirty(false);
    }
}


/**
 *	GLRender.
 *  Binds program 0 after update since we have no idea which shader
 *  the user wants anyway.
 */
void SoXipGLSLLoadComponents::GLRender(SoGLRenderAction *action)
{
	if (mTimedUpdate || mFieldBitmask)
	{
        int prevShader = SoXipGLSLShaderProgramElement::get(action->getState());
        UpdateAction();
        SoXipGLSLShaderProgramElement::set(action->getState(), prevShader);
    }
}


void SoXipGLSLLoadComponents::updateSensorCB(void *data, SoSensor *sensor)
{
	// cast editor object
	SoXipGLSLLoadComponents *thisObj = (SoXipGLSLLoadComponents*)data;

    if (sensor == thisObj->mUpdateFieldSensor)
    {
        thisObj->vpComponents.touch();
        thisObj->gpComponents.touch();
        thisObj->fpComponents.touch();
    }
}

void SoXipGLSLLoadComponents::autoUpdateCB(void *data, SoSensor *sensor)
{
	// cast editor object
	SoXipGLSLLoadComponents *thisObj = (SoXipGLSLLoadComponents*)data;
    thisObj->AutoUpdateAction();
}

void SoXipGLSLLoadComponents::toggleAutoCB(void *data, SoSensor *sensor)
{
	// cast editor object
	SoXipGLSLLoadComponents *thisObj = (SoXipGLSLLoadComponents*)data;

    if ((thisObj->mIsAutoOn && !thisObj->autoUpdate.getValue()) ||
        (!thisObj->mIsAutoOn && thisObj->autoUpdate.getValue()))
    {
        thisObj->mIsAutoOn = (thisObj->autoUpdate.getValue()) ? true : false;
        (thisObj->mIsAutoOn) ? thisObj->mAutoUpdateTimerSensor->schedule()
                             : thisObj->mAutoUpdateTimerSensor->unschedule();
    }
}


