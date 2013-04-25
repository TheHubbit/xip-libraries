/*
 *
 *  Copyright (C) 2004 MeVis gGmbH  All Rights Reserved.
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
 *  Contact information: MeVis, Center for Medical Diagnostic Systems and
 *  Visualization GmbH, Universitätsallee 29, D-28359 Bremen, GERMANY, or:
 *
 *  http://www.mevis.de
 *
 */

/*
 * Copyright (C) 2004   MeVis Research GmbH
 *
 _______________________________________________________________________
 _______________  M E V I S   R E S E A R C H   G M B H  _______________
 |
 |   $Revision$
 |
 |   Description:
 |   This include file contains a class to manage a buffer for a stack
 |   and a list of string pointers for tracing debug and release code.
 |
 |   Author(s)      : Wolf Spindler, Felix Ritter
 |
 _______________  M E V I S   R E S E A R C H   G M B H  _______________
 _______________________________________________________________________
 */

#ifndef  _SO_TRACE_
#define  _SO_TRACE_

#include <Inventor/system/SbSystem.h>
#include <Inventor/SbString.h>
#include <inttypes.h>


//////////////////////////////////////////////////////////////////////////////
//
//  This macro can/should be inserted at first position in user
//  implemented class methods and functions. It stores pointers
//  to a string in buffers for the most recently called function
//  and on a call stack. In error cases these buffers can be read
//  to analyse the crash/error position.
//
//////////////////////////////////////////////////////////////////////////////

#if !defined(DISABLE_ERRORTRACING)

# define SO_TRACE_IN(__classAndMethod___)  \
   static const char *const __SO_TRACE_IN_STRING_BUF = __FILE__ ":" __classAndMethod___; \
   SoTrace<uint16_t> __SoTraceObject(__SO_TRACE_IN_STRING_BUF, SoGlobalTraceBuffer);

#else

# define SO_TRACE_IN(__classAndMethod___)

#endif  // DISABLE_ERRORTRACING

// The type used in the SoGlobalTraceBuffer.
typedef uint16_t SoGlobalTraceBufferType;



//////////////////////////////////////////////////////////////////////////////
//
//  This class manages a list and a stack of pointers to permanent strings.
//  The constructor initializes the buffers to empty pointers.
//  It will be used by the Trace class called by SO_TRACE_IN macros on
//  function entries to track the call stack and call list.
//  Overflows especially of the list will occur and are included in class
//  design; so the buffers have exactly of a size identical with index
//  range of the stack pointer and the list pointer. Accepting overflows
//  limits the stack size and the number of list entries; however, so no
//  checks for overflow etc. are necessary which permits maximum tracing
//  performance.
//  INDEXTYPE specifies the data type and indirectly the size of the
//  stack and the list. Normally it should be uint16_t which then
//  will result in 65536 stack and list entries. Other types are
//  not supported.
//
//////////////////////////////////////////////////////////////////////////////

template <typename INDEXTYPE> class SoTraceBuffer
{
   public:

      // Initializing constructor. It resets the stack and
      // list buffer and also listEnd and stackTop indices.
      inline SoTraceBuffer() {
      	 _initClass();
      }

      // Add trace description. It appends the passed string reference
      // to the trace buffer and to the top of the trace stack. Then it
      // increases trace index and stack pointer.
      // traceInString may be NULL. If not NULL it must point to
      // any null-terminated permanent string.
      // VERY TIME CRITICAL!
      inline void    	add(const char *const traceInString) {
      	 // Push string address onto the stack. Be sure that
      	 // _stackTop is incremented after storing pointer to
      	 // make memory access and incrementation of index independent.
      	 // So the CPU can execute both statements parallel.
      	 // Also be sure to increment index NOT within "[" and "]"
      	 // to avoid that indexing works on 32bit integers which would
         // access areas outside buffers.
      	 _traceStack[_traceStackTop] = traceInString;
      	 ++_traceStackTop;

      	 // Append string address to end of trace list. For optimizing
      	 // performance also see _traceStack push above.
      	 _traceList[_traceListEnd] = traceInString;
      	 ++_traceListEnd;
      }

      // Destructor. It decreases stack pointer and resets last
      // stored string pointer to
      // VERY TIME CRITICAL!
      inline void    	remove() {
      	 // Decrement trace stack top. Be sure that integer index
      	 // is really limited to size of INDEXTYPE since passing
      	 // decremented _traceStackTop without masking it could
      	 // lead to usage of 32 bit index in index "[" "]" and
      	 // accesses outside buffers. Note that mask calculation
      	 // is constant and probably will be evaluated on compile
      	 // time.
      	 _traceStackTop = (INDEXTYPE)((_traceStackTop - 1) & _bufferIndexMask);

      	 // Reset stack entry. So unused entries do not use
      	 // invalid information.
      	 _traceStack[_traceStackTop] = NULL;
      }

      // Returns index into trace stack buffer. It addresses the entry to
      // be written on next push.
      inline INDEXTYPE	getTraceStackTop() const {
      	 return _traceStackTop;
      }

      // Returns index into trace list buffer. It addresses the entry to
      // be written on next append.
      inline INDEXTYPE	getTraceListEnd() const {
      	 return _traceListEnd;
      }

      // Returns the pointer to the first element of the trace stack.
      inline const char *const *getTraceStack() const {
      	 return _traceStack;
      }

      // Returns the pointer to the first element of the trace list.
      inline const char *const *getTraceList() const {
      	 return _traceList;
      }

      // Maximum number of trace list entries to be shown on fatal error outputs.
      inline SoGlobalTraceBufferType getMaxNumTraceListDumps() const {
      	 return _maxNumTraceListDumps;
      }

      // Sets the maximum number of trace list entries to be shown on fatal error outputs.
      inline void    	setMaxNumTraceListDumps(SoGlobalTraceBufferType num) {
      	 _maxNumTraceListDumps = num;
      }

      // Maximum number of trace stack entries to be shown on fatal error outputs.
      inline SoGlobalTraceBufferType getMaxNumTraceStackDumps() const {
      	 return _maxNumTraceStackDumps;
      }

      // Sets the maximum number of trace stack entries to be shown on fatal error outputs.
      inline void    	setMaxNumTraceStackDumps(SoGlobalTraceBufferType num) {
      	 _maxNumTraceStackDumps = num;
      }

      // Returns an SbString which returns a dump of trace list and trace dump
      // entries for debugging purposes.
      SbString       	getTraceDumpString() const;

   private:

      // Initializing constructor. It resets the stack and
      // list buffer and also listEnd and stackTop indices.
      inline void    	_initClass() {
      	 // Initialize both buffers with NULL pointers.
      	 memset(_traceStack, 0, _numBufBytes);
      	 memset(_traceList,  0, _numBufBytes);

      	 // Reset indices into stack and list.
      	 _traceStackTop = 0;
      	 _traceListEnd  = 0;
      }

      // Calculate the number of buffer entries, the byte size of the buffer
      // and a bit mask to limit an index to index only buffer elements.
      // We put it into an enum to define constants in the header usable
      // as array sizes without having the need to spend constant members for it.
      enum {
      	 _numBufEntries   = (1L << (sizeof(INDEXTYPE) << 3)) ,
         _numBufBytes     = _numBufEntries * sizeof(const char *),
         _bufferIndexMask = _numBufEntries - 1
      };

      // Index to the entry to be written on next push.
      INDEXTYPE         _traceStackTop;

      // Index to the entry to be written on next append.
      INDEXTYPE         _traceListEnd;

      // Buffer for the trace stack.
      const char       *_traceStack[_numBufEntries];

      // Buffer for the trace list.
      const char       *_traceList[_numBufEntries];

      // The number of trace list outputs dumped into an error message
      // in the case of a fatal error. Default is 16.
      SoGlobalTraceBufferType _maxNumTraceListDumps;

      // The number of trace stack outputs dumped into an error message
      // in the case of a fatal error. Default is 32.
      SoGlobalTraceBufferType _maxNumTraceStackDumps;
};



//////////////////////////////////////////////////////////////////////////////
//
//  This class simply implements a constructor and a destructor.
//  The constructor calls the add method of a SoTraceBuffer and the destructor
//  calls the remove method of a SoTraceBuffer.
//  It will typically be called of SO_TRACE_IN macros on function entries
//  to track the string description of the function name in a call stack
//  and a call list in a SoTraceBuffer object.
//  INDEXTYPE specifies the data type and indirectly the size of the
//  stack and the list. Normally it should be uint8_t or uint16_t which then
//  will result in 256 or 65536 stack and list entries. Other types are
//  not supported.
//
//////////////////////////////////////////////////////////////////////////////

template <typename INDEXTYPE> class SoTrace
{
   public:

      // Constructor. It adds the passed string reference to the
      // trace buffer and to the top of the trace stack. Passed
      // string pointer also may be NULL. If not NULL it must
      // point to any null-terminated non changing permanent string.
      // To be used by SO_TRACE_IN macros.
      // traceInString is the string pointer to the permanent
      //        static string to be added to list and pushed to stack.
      // traceBuf is the TraceBuffer in which the string
      //        shall be appended and pushed.
      // VERY TIME CRITICAL!
      inline SoTrace(const char *const traceInString, SoTraceBuffer<INDEXTYPE> &traceBuf) : _traceBuf(traceBuf) {
      	 // Push string addres on stack and at end of trace list.
      	 traceBuf.add(traceInString);
      }

      // Destructor. It removes the last entry from the SoTraceBuffer.
      // That pops the last pushed string reference from the stack
      // and resets its entry to NULL.
      // Normally automatically called when leaving the scope where
      // the constructor is called.
      // VERY TIME CRITICAL!
      inline ~SoTrace() {
      	 _traceBuf.remove();
      }

   private:

      // Stores the reference to the TraceBuffer object during lifetime
      // of this TraceObject. The TraceBuffer is used for managing the
      // trace stack and the trace list.
      SoTraceBuffer<INDEXTYPE> &_traceBuf;

      // Implement copy constructor to avoid compiler warnings.
      // It is not intented to be used and so it is private.
      inline SoTrace(const SoTrace &trace) : _traceBuf(trace._traceBuf) {
      }

      // Implement assignment operator to avoid compiler warnings.
      // It is not intented to be used directly and so it is private.
      // References cannot be assigned/changed, so _traceBuf cannot be assigned.
      inline SoTrace<INDEXTYPE> &operator=(const SoTrace &trace) {
      	 return *this;
      }
};


//////////////////////////////////////////////////////////////////////////////
//
//  This is a global singleton of the SoTraceBuffer class. It is used
//  by all SO_TRACE_IN macros to trace function calls in inventor code.
//  In the case of catched error exceptions the most recently called
//  functions and function stack can be dumped.
//
//////////////////////////////////////////////////////////////////////////////

extern INVENTOR_API SoTraceBuffer<SoGlobalTraceBufferType> SoGlobalTraceBuffer;

#endif  // _SO_TYPE_
