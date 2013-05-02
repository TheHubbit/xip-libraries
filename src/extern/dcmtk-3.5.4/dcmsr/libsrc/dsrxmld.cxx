/*
 *
 *  Copyright (C) 2003-2005, OFFIS
 *
 *  This software and supporting documentation were developed by
 *
 *    Kuratorium OFFIS e.V.
 *    Healthcare Information and Communication Systems
 *    Escherweg 2
 *    D-26121 Oldenburg, Germany
 *
 *  THIS SOFTWARE IS MADE AVAILABLE,  AS IS,  AND OFFIS MAKES NO  WARRANTY
 *  REGARDING  THE  SOFTWARE,  ITS  PERFORMANCE,  ITS  MERCHANTABILITY  OR
 *  FITNESS FOR ANY PARTICULAR USE, FREEDOM FROM ANY COMPUTER DISEASES  OR
 *  ITS CONFORMITY TO ANY SPECIFICATION. THE ENTIRE RISK AS TO QUALITY AND
 *  PERFORMANCE OF THE SOFTWARE IS WITH THE USER.
 *
 *  Module:  dcmsr
 *
 *  Author:  Joerg Riesmeier
 *
 *  Purpose:
 *    classes: DSRXMLDocument
 *
 *  Last Update:      $Author: meichel $
 *  Update Date:      $Date: 2005/12/16 15:46:43 $
 *  CVS/RCS Revision: $Revision: 1.11 $
 *  Status:           $State: Exp $
 *
 *  CVS/RCS Log at end of file
 *
 */


#include "dcmtk/config/osconfig.h"    /* make sure OS specific configuration is included first */

#include "dcmtk/dcmsr/dsrxmld.h"

#define INCLUDE_CSTDARG
#include "dcmtk/ofstd/ofstdinc.h"

#ifdef WITH_LIBXML
#include <libxml/xmlschemas.h>

#ifdef LIBXML_SCHEMAS_ENABLED
#ifdef HAVE_VPRINTF
// function required to avoid issue with 'std' namespace
extern "C" void errorFunction(void *ctx, const char *msg, ...)
{
    va_list ap;
    va_start(ap, msg);
#ifdef HAVE_PROTOTYPE_STD__VFPRINTF
    std::vfprintf(OFstatic_cast(FILE *, ctx), msg, ap);
#else
    vfprintf(OFstatic_cast(FILE *, ctx), msg, ap);
#endif
    va_end(ap);
}
#endif
#endif /* LIBXML_SCHEMAS_ENABLED */

// 'libxml' shall be quiet in non-debug mode
extern "C" void noErrorFunction(void * /*ctx*/, const char * /*msg*/, ...)
{
    /* do nothing */
}

#endif /* WITH_LIBXML */


/* ------------------------ */


DSRXMLDocument::DSRXMLDocument()
  : Document(NULL),
    EncodingHandler(NULL),
    LogStream(NULL)
{
}


DSRXMLDocument::~DSRXMLDocument()
{
    clear();
}


void DSRXMLDocument::clear()
{
#ifdef WITH_LIBXML
    /* free allocated memory */
    xmlFreeDoc(Document);
#endif
    /* remove all references to libxml structures */
    Document = NULL;
    EncodingHandler = NULL;
}


OFBool DSRXMLDocument::valid() const
{
    return (Document != NULL);
}


OFConsole *DSRXMLDocument::getLogStream() const
{
    return LogStream;
}


void DSRXMLDocument::setLogStream(OFConsole *stream)
{
    LogStream = stream;
}


#ifdef WITH_LIBXML
OFCondition DSRXMLDocument::read(const OFString &filename,
                                 const size_t flags, const E_LoadXmlMode loadMode)
{
    OFCondition result = SR_EC_InvalidDocument;
    /* first remove any possibly existing document from memory */
    clear();
    /* substitute default entities (XML mnenonics) */
    xmlSubstituteEntitiesDefault(1);
    if (flags & XF_enableLibxmlErrorOutput)
    {
        /* add line number to debug messages */
        xmlLineNumbersDefault(1);
        /* enable libxml warnings and error messages */
        xmlGetWarningsDefaultValue = 1;
        initGenericErrorDefaultFunc(NULL);
    } else {
        /* disable libxml warnings and error messages */
        xmlGetWarningsDefaultValue = 0;
        xmlSetGenericErrorFunc(NULL, noErrorFunction);
    }
    xmlGenericError(xmlGenericErrorContext, "--- libxml parsing ------\n");
    /* build an XML tree from the given file */
	if (loadMode == DSRTypes::LXT_File)
		Document = xmlParseFile(filename.c_str());
	else
		Document = xmlParseDoc((xmlChar *)filename.c_str());
    if (Document != NULL)
    {
        OFBool isValid = OFTrue;
        /* validate Schema */
        if (flags & XF_validateSchema)
        {
            xmlGenericError(xmlGenericErrorContext, "--- libxml validating ---\n");
#ifdef LIBXML_SCHEMAS_ENABLED
#if 1
            /* create context for Schema validation */
            xmlSchemaParserCtxtPtr context = xmlSchemaNewParserCtxt(DCMSR_XML_XSD_FILE);
            if (flags & XF_enableLibxmlErrorOutput)
            {
#ifdef HAVE_VPRINTF
                xmlSchemaSetParserErrors(context, errorFunction, errorFunction, stderr);
#else
                xmlSchemaSetParserErrors(context, OFreinterpret_cast(xmlSchemaValidityErrorFunc, fprintf),
                                                  OFreinterpret_cast(xmlSchemaValidityWarningFunc, fprintf), stderr);
#endif
            } else
                xmlSchemaSetParserErrors(context, NULL, NULL, NULL);
            /* parse Schema file */
            xmlSchemaPtr schema = xmlSchemaParse(context);
            if (schema != NULL)
            {
                xmlSchemaValidCtxtPtr validCtx = xmlSchemaNewValidCtxt(schema);
                if (flags & XF_enableLibxmlErrorOutput)
                {
#ifdef HAVE_VPRINTF
                    xmlSchemaSetValidErrors(validCtx, errorFunction, errorFunction, stderr);
#else
                    xmlSchemaSetValidErrors(validCtx, OFreinterpret_cast(xmlSchemaValidityErrorFunc, fprintf),
                                                      OFreinterpret_cast(xmlSchemaValidityWarningFunc, fprintf), stderr);
#endif
                } else
                    xmlSchemaSetValidErrors(validCtx, NULL, NULL, NULL);
                /* validate the document */
                isValid = (xmlSchemaValidateDoc(validCtx, Document) == 0);
                xmlSchemaFreeValidCtxt(validCtx);
                xmlSchemaFree(schema);
            } else
                xmlGenericError(xmlGenericErrorContext, "error: failed to compile schema \"%s\"\n", DCMSR_XML_XSD_FILE);
            xmlSchemaFreeParserCtxt(context);
#else // 0
            /* ### the following code fragment is not yet working! ### */

            /* create context for Schema validation */
            xmlSchemaValidCtxtPtr context = xmlSchemaNewValidCtxt(NULL);
            if (flags & XF_enableLibxmlErrorOutput)
            {
#ifdef HAVE_VPRINTF
                xmlSchemaSetValidErrors(context, errorFunction, errorFunction, stderr);
#else
                xmlSchemaSetValidErrors(context, OFreinterpret_cast(xmlSchemaValidityErrorFunc, fprintf),
                                                 OFreinterpret_cast(xmlSchemaValidityWarningFunc, fprintf), stderr);
#endif
            } else
                xmlSchemaSetValidErrors(context, NULL, NULL, NULL);
            /* validate the document */
            isValid = (xmlSchemaValidateDoc(context, Document) == 0);
#endif
#else /* LIBXML_SCHEMAS_ENABLED */
            xmlGenericError(xmlGenericErrorContext, "no support for XML Schema\n");
#endif
        }
        xmlGenericError(xmlGenericErrorContext, "-------------------------\n");
        /* check whether the document is of the right kind */
        xmlNodePtr current = xmlDocGetRootElement(Document);
        if ((current != NULL) && isValid)
        {
            /* check namespace declaration (if required) */
            if (!(flags & XF_useDcmsrNamespace) ||
                (xmlSearchNsByHref(Document, current, OFreinterpret_cast(const xmlChar *, DCMSR_XML_NAMESPACE_URI)) != NULL))
            {
                result = EC_Normal;
            } else
                printErrorMessage(LogStream, "Document has wrong type, dcmsr namespace not found");
        } else {
            if (isValid)
                printErrorMessage(LogStream, "Document is empty");
            else
                printErrorMessage(LogStream, "Document does not validate");
        }
    } else {
        xmlGenericError(xmlGenericErrorContext, "-------------------------\n");
        printErrorMessage(LogStream, "Could not parse document");
    }
    return result;
}
#else /* WITH_LIBXML */
OFCondition DSRXMLDocument::read(const OFString &,
                                 const size_t, const E_LoadXmlMode loadMode)
{
    return EC_IllegalCall;
}
#endif


OFBool DSRXMLDocument::encodingHandlerValid() const
{
    return (EncodingHandler != NULL);
}


#ifdef WITH_LIBXML
OFCondition DSRXMLDocument::setEncodingHandler(const char *charset)
{
    OFCondition result = EC_IllegalParameter;
    if ((charset != NULL) && (strlen(charset) > 0))
    {
        /* find appropriate encoding handler */
        EncodingHandler = xmlFindCharEncodingHandler(charset);
        if (EncodingHandler != NULL)
            result = EC_Normal;
    }
    return result;
}
#else /* WITH_LIBXML */
OFCondition DSRXMLDocument::setEncodingHandler(const char *)
{
    return EC_IllegalCall;
}
#endif


DSRXMLCursor DSRXMLDocument::getRootNode() const
{
    DSRXMLCursor cursor;
#ifdef WITH_LIBXML
    /* set cursor to root node */
    cursor.Node = xmlDocGetRootElement(Document);
#endif
    return cursor;
}


#ifdef WITH_LIBXML
DSRXMLCursor DSRXMLDocument::getNamedNode(const DSRXMLCursor &cursor,
                                          const char *name,
                                          const OFBool required) const
{
    DSRXMLCursor result;
    /* check whether given name is valid */
    if ((name != NULL) && (strlen(name) > 0))
    {
        xmlNodePtr current = cursor.Node;
        /* iterate over all nodes */
        while (current != NULL)
        {
            /* ignore blank (empty or whitespace only) nodes */
            while ((current != NULL) && xmlIsBlankNode(current))
                current = current->next;
            if (current != NULL)
            {
                /* check whether node has expected name */
                if (xmlStrcmp(current->name, OFreinterpret_cast(const xmlChar *, name)) == 0)
                    break;
                /* proceed with next node */
                current = current->next;
            }
        }
        if (current == NULL)
        {
            /* report error message */
            if (required)
            {
                OFString tmpString;
                OFString message = "Document of the wrong type, '";
                message += name;
                message += "' expected at ";
                message += getFullNodePath(cursor, tmpString, OFFalse /*omitCurrent*/);
                DSRTypes::printErrorMessage(LogStream, message.c_str());
            }
        } else {
            /* return new node position */
            result.Node = current;
        }
    }
    return result;
}
#else /* WITH_LIBXML */
DSRXMLCursor DSRXMLDocument::getNamedNode(const DSRXMLCursor &,
                                          const char *,
                                          const OFBool) const
{
    DSRXMLCursor result;
    return result;
}
#endif


#ifdef WITH_LIBXML
OFBool DSRXMLDocument::matchNode(const DSRXMLCursor &cursor,
                                 const char *name) const
{
    OFBool result = OFFalse;
    if (cursor.Node != NULL)
    {
        /* check whether node name matches */
        if ((name != NULL) && (strlen(name) > 0))
            result = (xmlStrcmp(cursor.Node->name, OFreinterpret_cast(const xmlChar *, name)) == 0);
    }
    return result;
}
#else /* WITH_LIBXML */
OFBool DSRXMLDocument::matchNode(const DSRXMLCursor &,
                                 const char *) const
{
    return OFFalse;
}
#endif


#ifdef WITH_LIBXML
OFCondition DSRXMLDocument::checkNode(const DSRXMLCursor &cursor,
                                      const char *name) const
{
    OFCondition result = EC_IllegalParameter;
    /* check whether parameters are valid */
    if ((name != NULL) && (strlen(name) > 0))
    {
        /* check whether node is valid at all */
        if (cursor.Node != NULL)
        {
            /* check whether node has expected name */
            if (xmlStrcmp(cursor.Node->name, OFreinterpret_cast(const xmlChar *, name)) != 0)
            {
                OFString message = "Document of the wrong type, was '";
                message += OFreinterpret_cast(const char *, cursor.Node->name);
                message += "', '";
                message += name;
                message += "' expected";
                DSRTypes::printErrorMessage(LogStream, message.c_str());
                result = SR_EC_InvalidDocument;
            } else
                result = EC_Normal;
        } else {
            OFString message = "Document of the wrong type, '";
            message += name;
            message += "' expected";
            DSRTypes::printErrorMessage(LogStream, message.c_str());
            result = EC_IllegalParameter;
        }
    }
    return result;
}
#else /* WITH_LIBXML */
OFCondition DSRXMLDocument::checkNode(const DSRXMLCursor &,
                                      const char *) const
{
    return EC_IllegalCall;
}
#endif


#ifdef WITH_LIBXML
OFBool DSRXMLDocument::convertUtf8ToCharset(const xmlChar *fromString,
                                            OFString &toString) const
{
    OFBool result = OFFalse;
    if (EncodingHandler != NULL)
    {
        /* prepare input/output buffers */
        xmlBufferPtr fromBuffer = xmlBufferCreate();
        xmlBufferPtr toBuffer = xmlBufferCreate();
        xmlBufferCat(fromBuffer, fromString);
        /* convert character encoding of given string */
        result = (xmlCharEncOutFunc(EncodingHandler, toBuffer, fromBuffer) >= 0);
        if (result)
            toString = OFreinterpret_cast(const char *, xmlBufferContent(toBuffer));
        /* free allocated memory */
        xmlBufferFree(toBuffer);
        xmlBufferFree(fromBuffer);
    }
    return result;
}
#else /* WITH_LIBXML */
OFBool DSRXMLDocument::convertUtf8ToCharset(const xmlChar *,
                                            OFString &) const
{
    return OFFalse;
}
#endif


#ifdef WITH_LIBXML
OFBool DSRXMLDocument::hasAttribute(const DSRXMLCursor &cursor,
                                    const char *name) const
{
    OFBool result = OFFalse;
    if (cursor.Node != NULL)
    {
        /* check whether attribute exists */
        if ((name != NULL) && (strlen(name) > 0))
            result = (xmlHasProp(cursor.Node, OFreinterpret_cast(const xmlChar *, name)) != NULL);
    }
    return result;
}
#else /* WITH_LIBXML */
OFBool DSRXMLDocument::hasAttribute(const DSRXMLCursor &,
                                    const char *) const
{
    return OFFalse;
}
#endif


#ifdef WITH_LIBXML
OFString &DSRXMLDocument::getStringFromAttribute(const DSRXMLCursor &cursor,
                                                 OFString &stringValue,
                                                 const char *name,
                                                 const OFBool encoding,
                                                 const OFBool required) const
{
    /* always clear result string */
    stringValue.clear();
    /* check whether parameters are valid */
    if ((cursor.Node != NULL) && (name != NULL) && (strlen(name) > 0))
    {
        /* get the XML attribute value */
        xmlChar *attrVal = xmlGetProp(cursor.Node, OFreinterpret_cast(const xmlChar *, name));
        if ((attrVal != NULL) && (xmlStrlen(attrVal) > 0))
        {
            /* put value to the result variable */
            if (!encoding || !convertUtf8ToCharset(attrVal, stringValue))
                stringValue = OFreinterpret_cast(const char *, attrVal);
        } else if (required)
            printMissingAttributeError(cursor, name);
        /* free allocated memory */
        xmlFree(attrVal);
    }
    return stringValue;
}
#else /* WITH_LIBXML */
OFString &DSRXMLDocument::getStringFromAttribute(const DSRXMLCursor &,
                                                 OFString &stringValue,
                                                 const char *,
                                                 const OFBool,
                                                 const OFBool) const
{
    stringValue.clear();
    return stringValue;
}
#endif


#ifdef WITH_LIBXML
OFCondition DSRXMLDocument::getElementFromAttribute(const DSRXMLCursor &cursor,
                                                    DcmElement &delem,
                                                    const char *name,
                                                    const OFBool encoding,
                                                    const OFBool required) const
{
    OFCondition result = SR_EC_InvalidDocument;
    /* check whether parameters are valid */
    if ((cursor.Node != NULL) && (name != NULL) && (strlen(name) > 0))
    {
        /* get the XML attribute value */
        xmlChar *attrVal = xmlGetProp(cursor.Node, OFreinterpret_cast(const xmlChar *, name));
        if ((attrVal != NULL) && (xmlStrlen(attrVal) > 0))
        {
            OFString attrStr;
            /* put value to DICOM element */
            if (encoding && convertUtf8ToCharset(attrVal, attrStr))
                result = delem.putString(attrStr.c_str());
            else
                result = delem.putString(OFreinterpret_cast(const char *, attrVal));
        } else if (required)
            printMissingAttributeError(cursor, name);
        /* free allocated memory */
        xmlFree(attrVal);
    }
    return result;
}
#else /* WITH_LIBXML */
OFCondition DSRXMLDocument::getElementFromAttribute(const DSRXMLCursor &,
                                                    DcmElement &,
                                                    const char *,
                                                    const OFBool,
                                                    const OFBool) const
{
    return EC_IllegalCall;
}
#endif


#ifdef WITH_LIBXML
OFString &DSRXMLDocument::getStringFromNodeContent(const DSRXMLCursor &cursor,
                                                   OFString &stringValue,
                                                   const char *name,
                                                   const OFBool encoding,
                                                   const OFBool clearString) const
{
    if (clearString)
        stringValue.clear();
    if (cursor.Node != NULL)
    {
        /* compare element name if required */
        if ((name == NULL) || (xmlStrcmp(cursor.Node->name, OFreinterpret_cast(const xmlChar *, name)) == 0))
        {

            /* get the XML node content */
            xmlChar *elemVal = xmlNodeGetContent(cursor.Node);
            /* put value to the result variable */
            if (!encoding || !convertUtf8ToCharset(elemVal, stringValue))
                stringValue = OFreinterpret_cast(const char *, elemVal);
            /* free allocated memory */
            xmlFree(elemVal);
        }
    }
    return stringValue;
}
#else /* WITH_LIBXML */
OFString &DSRXMLDocument::getStringFromNodeContent(const DSRXMLCursor &,
                                                   OFString &stringValue,
                                                   const char *,
                                                   const OFBool,
                                                   const OFBool) const
{
    stringValue.clear();
    return stringValue;
}
#endif


#ifdef WITH_LIBXML
OFCondition DSRXMLDocument::getElementFromNodeContent(const DSRXMLCursor &cursor,
                                                      DcmElement &delem,
                                                      const char *name,
                                                      const OFBool encoding) const
{
    OFCondition result = SR_EC_InvalidDocument;
    if (cursor.Node != NULL)
    {
        /* compare element name if required */
        if ((name == NULL) || (xmlStrcmp(cursor.Node->name, OFreinterpret_cast(const xmlChar *, name)) == 0))
        {
            OFString elemStr;
            /* get the XML node content */
            xmlChar *elemVal = xmlNodeGetContent(cursor.Node);
            /* put value to DICOM element */
            if (encoding && convertUtf8ToCharset(elemVal, elemStr))
                result = delem.putString(elemStr.c_str());
            else
                result = delem.putString(OFreinterpret_cast(const char *, elemVal));
            /* free allocated memory */
            xmlFree(elemVal);
        }
    }
    return result;
}
#else /* WITH_LIBXML */
OFCondition DSRXMLDocument::getElementFromNodeContent(const DSRXMLCursor &,
                                                      DcmElement &,
                                                      const char *,
                                                      const OFBool) const
{
    return EC_IllegalCall;
}
#endif


#ifdef WITH_LIBXML
OFString &DSRXMLDocument::getFullNodePath(const DSRXMLCursor &cursor,
                                          OFString &stringValue,
                                          const OFBool omitCurrent)
{
    stringValue.clear();
    if (cursor.Node != NULL)
    {
        OFString tmpString;
        xmlNodePtr current = cursor.Node;
        if (!omitCurrent)
            stringValue = OFreinterpret_cast(const char *, current->name);
        /* follow path to parent nodes */
        while (current->parent != NULL)
        {
            current = current->parent;
            tmpString = stringValue;
            stringValue = OFreinterpret_cast(const char *, current->name);
            if (!tmpString.empty())
            {
                stringValue += '/';
                stringValue += tmpString;
            }
        }
        /* avoid empty return value */
        if (stringValue.empty() && omitCurrent)
            stringValue = '.';
    } else
        stringValue = "<invalid>";
    return stringValue;
}
#else /* WITH_LIBXML */
OFString &DSRXMLDocument::getFullNodePath(const DSRXMLCursor &,
                                          OFString &stringValue,
                                          const OFBool)
{
    stringValue.clear();
    return stringValue;
}
#endif


#ifdef WITH_LIBXML
DSRTypes::E_ValueType DSRXMLDocument::getValueTypeFromNode(const DSRXMLCursor &cursor) const
{
    E_ValueType valueType = VT_invalid;
    if (cursor.valid())
    {
        if (xmlStrcmp(cursor.Node->name, OFreinterpret_cast(const xmlChar *, "item")) == 0)
        {
            /* check for "ref" attribute */
            if (xmlHasProp(cursor.Node, OFreinterpret_cast(const xmlChar *, "ref")))
                valueType = DSRTypes::VT_byReference;
            else {
                /* get the XML attribute value */
                xmlChar *attrVal = xmlGetProp(cursor.Node, OFreinterpret_cast(const xmlChar *, "valType"));
                /* try to convert attribute value to SR value type */
                valueType = definedTermToValueType(OFreinterpret_cast(const char *, attrVal));
                /* free allocated memory */
                xmlFree(attrVal);
            }
        } else {
            /* try to convert tag name to SR value type */
            valueType = xmlTagNameToValueType(OFreinterpret_cast(const char *, cursor.Node->name));
        }
    }
    return valueType;
}
#else /* WITH_LIBXML */
DSRTypes::E_ValueType DSRXMLDocument::getValueTypeFromNode(const DSRXMLCursor &) const
{
    return VT_invalid;
}
#endif


DSRTypes::E_RelationshipType DSRXMLDocument::getRelationshipTypeFromNode(const DSRXMLCursor &cursor) const
{
    E_RelationshipType relationshipType = RT_invalid;
    if (cursor.valid())
    {
        OFString tmpString;
        /* get the XML attribute value (if present) */
        if (hasAttribute(cursor, "relType"))
        {
            /* try to convert attribute value to SR relationship type */
            relationshipType = definedTermToRelationshipType(getStringFromAttribute(cursor, tmpString, "relType"));
        } else {
            const DSRXMLCursor childCursor = getNamedNode(cursor.getChild(), "relationship");
            /* try to convert content of "relationship" tag to SR relationship type */
            if (childCursor.valid())
                relationshipType = definedTermToRelationshipType(getStringFromNodeContent(childCursor, tmpString));
        }
    }
    return relationshipType;
}


void DSRXMLDocument::printUnexpectedNodeWarning(const DSRXMLCursor &cursor) const
{
    OFString tmpString;
    /* create message string */
    OFString message = "Unexpected node '";
    message += getFullNodePath(cursor, tmpString);
    message += "', skipping";
    /* print warning message */
    printWarningMessage(LogStream, message.c_str());
}


void DSRXMLDocument::printMissingAttributeError(const DSRXMLCursor &cursor,
                                                const char *name) const
{
    /* report error message */
    if (name != NULL)
    {
        OFString tmpString;
        OFString message = "XML attribute '";
        message += name;
        message += "' missing/empty in ";
        message += getFullNodePath(cursor, tmpString);
        printErrorMessage(LogStream, message.c_str());
    }
}


void DSRXMLDocument::printGeneralNodeError(const DSRXMLCursor &cursor,
                                           const OFCondition &result) const
{
    /* report error message */
    if (result.bad())
    {
        OFString tmpString;
        OFString message = "Parsing node ";
        message += getFullNodePath(cursor, tmpString);
        message += " (";
        message += result.text();
        message += ")";
        printErrorMessage(LogStream, message.c_str());
    }
}


/*
 *  CVS/RCS Log:
 *  $Log: dsrxmld.cc,v $
 *  Revision 1.11  2005/12/16 15:46:43  meichel
 *  Declared libxml2 callback functions as extern "C"
 *
 *  Revision 1.10  2005/12/08 15:48:25  meichel
 *  Changed include path schema for all DCMTK header files
 *
 *  Revision 1.9  2004/09/03 08:50:48  joergr
 *  Replaced tabs by spaces.
 *
 *  Revision 1.8  2004/08/04 12:12:18  joergr
 *  Disabled support for XML Schema if not compiled into libxml2 library.
 *
 *  Revision 1.7  2004/04/07 12:04:48  joergr
 *  Adapted code to avoid warnings reported by gcc when compiling without libxml
 *  support.
 *
 *  Revision 1.6  2004/03/25 17:32:41  joergr
 *  Solved issue with function pointer to std::fprintf or fprintf, respectively.
 *
 *  Revision 1.5  2004/01/21 11:56:20  meichel
 *  Using std::fprintf instead of fprintf as function pointer if configure
 *    symbol HAVE_PROTOTYPE_STD__FPRINTF is defined, needed on Borland Builder.
 *
 *  Revision 1.4  2004/01/05 14:37:00  joergr
 *  Renamed XML attribute "ref_id" to "ref".
 *
 *  Revision 1.3  2003/12/01 15:47:28  joergr
 *  Changed XML encoding of by-reference relationships if flag
 *  XF_valueTypeAsAttribute is set.
 *
 *  Revision 1.2  2003/08/07 15:21:53  joergr
 *  Added brackets around "bitwise and" operator/operands to avoid warnings
 *  reported by MSVC5.
 *
 *  Revision 1.1  2003/08/07 14:49:36  joergr
 *  Added interface classes hiding the access to libxml (document and cursor
 *  class).
 *
 *
 */
