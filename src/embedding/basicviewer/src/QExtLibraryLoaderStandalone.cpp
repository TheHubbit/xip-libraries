/****************************************************************************
Component: Extensions for Qt
Author: Philipp Horwath; SCR, Imaging Architecture
Date: May, 2007
Description: ...
Copyright (C) Siemens AG 2006 All Rights Reserved
****************************************************************************/

#include "QExtLibraryLoaderStandalone.h"

//#include "QTools.h"
#include <QtCore/QLibrary>
#include <QtCore/QStringList>
#include <QtCore/QFile>

//#include "QXipBuilderError.h"

QExtLibraryLoaderStandalone::QLibraryMap QExtLibraryLoaderStandalone::mLibraryMap;
QExtLibraryLoaderStandalone::QErrorMap QExtLibraryLoaderStandalone::mErrorMap;

bool QExtLibraryLoaderStandalone::loadDLL(const QString &file)
{
	// get the new library
	QLibrary* library = getQLibrary(file);

	// load the library
	bool success = false;

	try
	{
		success = library->load();
	}
	catch (...)
	{
	}

	// if loading is ok, check the difference
	if (!success)
	{
		// remove "QLibrary::load_sys: " heading form Qt error message
		QString error = library->errorString();
		setErrorMessage(file, error.right(error.length() - error.indexOf(' ') - 1));
	}
	else
	{
		setErrorMessage(file, "");
	}

	return success;
}

bool QExtLibraryLoaderStandalone::unloadDLL(const QString &file)
{
	QLibrary* library = getQLibrary(file);
	bool success = library->unload();

	if (!success)
	{
		// remove "QLibrary::load_sys: " heading form Qt error message
		QString error = library->errorString();
		setErrorMessage(file, error.right(error.length() - error.indexOf(' ') - 1));
	}
	else
		setErrorMessage(file, "");

	return success;
}

bool QExtLibraryLoaderStandalone::isLoaded(const QString &file)
{
	QLibrary* library = getQLibrary(file);
	return library->isLoaded();
}

bool QExtLibraryLoaderStandalone::exists(const QString &file)
{
	return QFile::exists(file);
}

QLibrary* QExtLibraryLoaderStandalone::getQLibrary(const QString &file)
{
	QLibrary* library = 0;

	// try to find the library
	if (mLibraryMap.find(file) != mLibraryMap.end())
	{
		// if it's found
		library = mLibraryMap[file];
	}
	else
	{
		// if it's not found, create a new one
		library = new QLibrary(file);
		// register the new one
		mLibraryMap[file] = library;
	}

	return library;
}

bool QExtLibraryLoaderStandalone::setErrorMessage(const QString &file, const QString &message)
{
	// safe the message
	mErrorMap[file] = message;
	return true;
}

QString QExtLibraryLoaderStandalone::getErrorMessage(const QString &file)
{
	QString error;

	// try to find an error
	if (mErrorMap.find(file) != mErrorMap.end())
		error = mErrorMap[file];

	return error;
}