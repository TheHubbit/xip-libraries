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
 *	Node class for texture handling
 */
#ifndef SO_XIP_BLEND_FUNC_ELEMENT_H
#define SO_XIP_BLEND_FUNC_ELEMENT_H
#include <xip/inventor/coregl/xipivcoregl.h>
#include <Inventor/elements/SoSubElement.h>

#include <xip/inventor/coregl/SoXipGlowElement.h>

//XIPIVCOREGL_API
class SoXipBlendFuncElement : public SoElement
{
	SO_ELEMENT_HEADER(SoXipBlendFuncElement);

public:
	static void initClass();

	virtual void init(SoState *state);

    virtual void push(SoState *state);
    virtual void pop(SoState *state, const SoElement *prevTopElement);

	virtual SbBool matches(const SoElement *elt) const;
    virtual SoElement *copyMatchInfo() const;

	static void setEnabled(SoState *state, GLboolean enabled);
	static void setBlendFunc(SoState *state, GLenum srcFunc, GLenum dstFunc);

//	static const void* get(SoState *state);

private:
	~SoXipBlendFuncElement();

	void setEnabledElt(GLboolean enabled);
	void setEnabledGL();
	void setBlendFuncElt(GLenum srcFunc, GLenum dstFunc);
	void setBlendFuncGL();

	GLboolean blendEnabled;
	GLint srcBlendFunction;
	GLint dstBlendFunction;
};

#endif // SO_RAD_DEPTH_TEST_ELEMENT_H
