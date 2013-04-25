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
 |   $Revision: 1.1.1.1 $
 |
 |   Classes:
 |	SoMFLong
 |
 |   Author(s)		: Paul S. Strauss
 |
 ______________  S I L I C O N   G R A P H I C S   I N C .  ____________
 _______________________________________________________________________
 */

#include <Inventor/fields/SoMFLong.h>

//////////////////////////////////////////////////////////////////////////////
//
// SoMFLong class
//
//////////////////////////////////////////////////////////////////////////////

// Use standard definitions of all basic methods
#if WIN32
SO_MFIELD_SOURCE_MALLOC(SoMFLong, long, long);
#else
  //#define SoMFLong SoMFInt32
	SO_MFIELD_REQUIRED_SOURCE(SoMFLong);
	SO_MFIELD_CONSTRUCTOR_SOURCE(SoMFLong);
	SO_MFIELD_VALUE_SOURCE(SoMFLong, int32_t, int32_t);
	SO_MFIELD_MALLOC_SOURCE(SoMFLong, int32_t);
#endif

////////////////////////////////////////////////////////////////////////
//
// Description:
//    Reads one (indexed) value from file. Returns FALSE on error.
//
// Use: private

SbBool
SoMFLong::read1Value(SoInput *in, int index)
//
////////////////////////////////////////////////////////////////////////
{
    return in->read(values[index]);
}

////////////////////////////////////////////////////////////////////////
//
// Description:
//    Writes one (indexed) value to file.
//
// Use: private

void
SoMFLong::write1Value(SoOutput *out, int index) const
//
////////////////////////////////////////////////////////////////////////
{
    out->write(values[index]);
}


////////////////////////////////////////////////////////////////////////
//
// Description:
//    Returns number of ASCII values to write per output line.
//
// Use: private

int
SoMFLong::getNumValuesPerLine() const
//
////////////////////////////////////////////////////////////////////////
{
    return 8;
}


////////////////////////////////////////////////////////////////////////
//
// Description:
//    Writes array of binary values to file as one chunk.
//
// Use: private

void
SoMFLong::writeBinaryValues(SoOutput *out) const // Defines writing action

//
////////////////////////////////////////////////////////////////////////
{
    out->writeBinaryArray(values, num);
}


////////////////////////////////////////////////////////////////////////
//
// Description:
//    Reads array of binary values from file as one chunk.
//
// Use: private

SbBool
SoMFLong::readBinaryValues(SoInput *in,    // Reading specification
                          int numToRead)   // Number of values to read
//
////////////////////////////////////////////////////////////////////////
{
    return (in->readBinaryArray(values, numToRead));
}

