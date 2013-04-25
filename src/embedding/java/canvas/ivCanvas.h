/* DO NOT EDIT THIS FILE - it is machine generated */
#include <jni.h>
/* Header for class ivCanvas */

#ifndef _Included_ivCanvas
#define _Included_ivCanvas
#ifdef __cplusplus
extern "C" {
#endif
#undef ivCanvas_FOCUS_TRAVERSABLE_UNKNOWN
#define ivCanvas_FOCUS_TRAVERSABLE_UNKNOWN 0L
#undef ivCanvas_FOCUS_TRAVERSABLE_DEFAULT
#define ivCanvas_FOCUS_TRAVERSABLE_DEFAULT 1L
#undef ivCanvas_FOCUS_TRAVERSABLE_SET
#define ivCanvas_FOCUS_TRAVERSABLE_SET 2L
#undef ivCanvas_TOP_ALIGNMENT
#define ivCanvas_TOP_ALIGNMENT 0.0f
#undef ivCanvas_CENTER_ALIGNMENT
#define ivCanvas_CENTER_ALIGNMENT 0.5f
#undef ivCanvas_BOTTOM_ALIGNMENT
#define ivCanvas_BOTTOM_ALIGNMENT 1.0f
#undef ivCanvas_LEFT_ALIGNMENT
#define ivCanvas_LEFT_ALIGNMENT 0.0f
#undef ivCanvas_RIGHT_ALIGNMENT
#define ivCanvas_RIGHT_ALIGNMENT 1.0f
#undef ivCanvas_serialVersionUID
#define ivCanvas_serialVersionUID -7644114512714619750i64
#undef ivCanvas_serialVersionUID
#define ivCanvas_serialVersionUID -2284879212465893870i64
#undef ivCanvas_BACKSPACE
#define ivCanvas_BACKSPACE 10001L
#undef ivCanvas_DELETE
#define ivCanvas_DELETE 10002L
#undef ivCanvas_HOME
#define ivCanvas_HOME 10003L
#undef ivCanvas_END
#define ivCanvas_END 10004L
#undef ivCanvas_PAGE_UP
#define ivCanvas_PAGE_UP 10005L
#undef ivCanvas_PAGE_DOWN
#define ivCanvas_PAGE_DOWN 10006L
#undef ivCanvas_LEFT_ARROW
#define ivCanvas_LEFT_ARROW 10007L
#undef ivCanvas_RIGHT_ARROW
#define ivCanvas_RIGHT_ARROW 10008L
#undef ivCanvas_UP_ARROW
#define ivCanvas_UP_ARROW 10009L
#undef ivCanvas_DOWN_ARROW
#define ivCanvas_DOWN_ARROW 10010L
/*
 * Class:     ivCanvas
 * Method:    loadLibraries
 * Signature: (Ljava/lang/String;)Z
 */
JNIEXPORT jboolean JNICALL Java_ivCanvas_loadLibraries
  (JNIEnv *, jobject, jstring);

/*
 * Class:     ivCanvas
 * Method:    initializeOpenGL
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_ivCanvas_initializeOpenGL
  (JNIEnv *, jobject);

/*
 * Class:     ivCanvas
 * Method:    paintOpenGL
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_ivCanvas_paintOpenGL
  (JNIEnv *, jobject);

/*
 * Class:     ivCanvas
 * Method:    cleanupOpenGL
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_ivCanvas_cleanupOpenGL
  (JNIEnv *, jobject);

/*
 * Class:     ivCanvas
 * Method:    initialSetup
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_ivCanvas_initialSetup
  (JNIEnv *, jobject);

/*
 * Class:     ivCanvas
 * Method:    processQueue
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_ivCanvas_processQueue
  (JNIEnv *, jobject);

/*
 * Class:     ivCanvas
 * Method:    keyPressedEvent
 * Signature: (Ljava/lang/String;)V
 */
JNIEXPORT void JNICALL Java_ivCanvas_keyPressedEvent
  (JNIEnv *, jobject, jstring);

/*
 * Class:     ivCanvas
 * Method:    keyReleasedEvent
 * Signature: (Ljava/lang/String;)V
 */
JNIEXPORT void JNICALL Java_ivCanvas_keyReleasedEvent
  (JNIEnv *, jobject, jstring);

/*
 * Class:     ivCanvas
 * Method:    mouseEventHandler
 * Signature: (Ljava/lang/String;)V
 */
JNIEXPORT void JNICALL Java_ivCanvas_mouseEventHandler
  (JNIEnv *, jobject, jstring);

/*
 * Class:     ivCanvas
 * Method:    loadGraphOpenGL
 * Signature: (Ljava/lang/String;)V
 */
JNIEXPORT void JNICALL Java_ivCanvas_loadGraphOpenGL
  (JNIEnv *, jobject, jstring);

/*
 * Class:     ivCanvas
 * Method:    setBackgroundColor
 * Signature: (III)V
 */
JNIEXPORT void JNICALL Java_ivCanvas_setBackgroundColor
  (JNIEnv *, jobject, jint, jint, jint);

/*
 * Class:     ivCanvas
 * Method:    setViewportRegion
 * Signature: (II)V
 */
JNIEXPORT void JNICALL Java_ivCanvas_setViewportRegion
  (JNIEnv *, jobject, jint, jint);

/*
 * Class:     ivCanvas
 * Method:    get
 * Signature: (Ljava/lang/String;)Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_ivCanvas_get
  (JNIEnv *, jobject, jstring);

/*
 * Class:     ivCanvas
 * Method:    set
 * Signature: (Ljava/lang/String;Ljava/lang/String;)Z
 */
JNIEXPORT jboolean JNICALL Java_ivCanvas_set
  (JNIEnv *, jobject, jstring, jstring);

#ifdef __cplusplus
}
#endif
#endif
