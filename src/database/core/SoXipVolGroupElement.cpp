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
#include <xip/inventor/core/SoXipVolGroupElement.h>
#include <Inventor/errors/SoDebugError.h>

SO_ELEMENT_SOURCE(SoXipVolGroupElement);


/*! \struct So_VolGroup
 * \brief This structure contains a simple node pointer
 *
 * Pointers to instances of this structure are stored in the
 * "mVolGroups" SbPList.
 */
struct So_VolGroup 
{
	SoNode *node;
};


/*! \fn SoXipVolGroupElement::~SoXipVolGroupElement()
* Destructor, cleans up internal data
* \return None
*/
SoXipVolGroupElement::~SoXipVolGroupElement()
{
}

/*! \fn SoXipVolGroupElement::initClass()
* Initializes this class. Called on dll initialization.
* \return void
*/
void SoXipVolGroupElement::initClass()
{
	SO_ELEMENT_INIT_CLASS(SoXipVolGroupElement, SoAccumulatedElement);
}



/*! \fn SoXipVolGroupElement::init(SoState *state)
* Initializes the element
* \param state - the current state pointer, unused
* \return void
*/
void SoXipVolGroupElement::init(SoState *state)
{
	mVolGroups.truncate(0);
	mStartIndex = 0;
}


/*! \fn SoXipVolGroupElement::add(SoState *state, SoNode *node, So_IvtRenderParam *renderParam)
 * Adds the a node to the current state
 * \param state - the current state pointer
 * \param node - the current node
 * \return void
 */
void SoXipVolGroupElement::add(SoState *state, SoNode *node)
{
	SoXipVolGroupElement* elt = (SoXipVolGroupElement *) getElement(state, classStackIndex);

	if (elt) 
	{
		elt->addToElt(node);

		// Update node id list in element
		elt->addNodeId(node);
	}
}


/*! \fn SoXipVolGroupElement::push(SoState *state)
 * Override push to copy the existing rendering parameter from the previous
 * \param state - the current state pointer
 * \return void
 */
void SoXipVolGroupElement::push(SoState *state)
{
	const SoXipVolGroupElement *elt = (const SoXipVolGroupElement *) getNextInStack();

	// Use SbPList::operator = to copy the pointers to the existing
	// planes. Since the previous element can't be destroyed before
	// this one is, there is no problem with using pointers to
	// existing plane structures. However, any new ones we add have to
	// be freed up when this instance goes away, so we save the
	// starting index to allow us to fix this in pop().
	mVolGroups = elt->mVolGroups;
	mStartIndex = mVolGroups.getLength();
	nodeIds = elt->nodeIds;
}


/*! \fn SoXipVolGroupElement::pop(SoState *state, const SoElement *prevTopElement)
 * Override pop to free up render parameter that were created in the instance that was removed from the state.
 * \param state - the current state pointer
 * \param prevTopElement - the previous top element
 * \return void
 */
void SoXipVolGroupElement::pop(SoState *, const SoElement *prevTopElement)
{
	const SoXipVolGroupElement *prevElt = (const SoXipVolGroupElement *) prevTopElement;

	// Free up any plane structures that were created by prevElt
	for (int i = prevElt->mStartIndex; i < prevElt->mVolGroups.getLength(); i++)
	{
		delete (So_VolGroup*) prevElt->mVolGroups[i];
	}
}


/*! \fn SoXipVolGroupElement::getInstance(SoState *state)
 * Returns the first (top) instance of the element in the state.
 * \param state - the current state pointer
 * \return pointer to element instance
 */
SoXipVolGroupElement* SoXipVolGroupElement::getInstance(SoState *state)
{
	return (SoXipVolGroupElement *) getConstElement(state, classStackIndex);
}



/*! \fn SoXipVolGroupElement::getNum() const
 * Returns the number of nodes in the element
 * \return number of nodes in the accumulated state
 */
int SoXipVolGroupElement::getNum() const
{
	return mVolGroups.getLength();
}


// Returns the nth plane matrix stored in an instance.

/*! \fn SoIvtRenderParamElement::getSceneObject(int index) const
 * Returns the generic parameter with the given index
 * \param index - the index to get
 * \return pointer to generic parameter structure
 */
const SoNode* SoXipVolGroupElement::getNode(int index) const
{
    if (index < 0 || index >= mVolGroups.getLength())
    {
        SoError::post("SoXipVolGroupElement::get",
            "Index (%d) is out of range 0 - %d",
            index, mVolGroups.getLength() - 1);
        return (NULL);
    }

	So_VolGroup *volGroup = (So_VolGroup *) mVolGroups[index];

	return volGroup->node;
}


/*! \fn SoXipVolGroupElement::addToElt(ivtSceneObj *sceneObj)
 * Adds a node to the element
 * \param node - the node pointer
 * \return void
 */
void SoXipVolGroupElement::addToElt(SoNode *node)
{
	So_VolGroup *newPlane = new So_VolGroup;

	newPlane->node = node;

	mVolGroups.append(newPlane);
}
