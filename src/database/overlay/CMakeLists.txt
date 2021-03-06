# Copyright Siemens Corporate Research Inc. 2007
# Author Sylvain Jaume <sylvain.jaume@siemens.com>

project(overlay)

#--------------------------------------------------------------------
# Find the Freetype library
#
if(WIN32)
  set(FREETYPE_LIBRARIES freetype2)
else(WIN32)
  find_package(Freetype)
endif(WIN32)

#--------------------------------------------------------------------
# Build FTGL project
#
add_subdirectory(ftgl)

#--------------------------------------------------------------------
# Define the header files
#
set(HEADERS
  SbXipSearchTree.h
  SoXipAngle.h
  SoXipAnnotation.h
  SoXipBSpline.h
  SoXipBox.h
  SoXipContour.h
  SoXipDisplayImageText.h
  SoXipDropShadowElement.h
  SoXipDropShadowStyle.h
  #SoXipEllipse.h
  SoXipFontAutoScale.h
  SoXipFontType.h
  ../../../include/xip/inventor/overlay/SoXipHandlerShape.h
  SoXipHermiteSpline.h
  SoXipIcon.h
  SoXipIconsResource.h
  SoXipImageOverlayAdd.h
  SoXipImageOverlayClear.h
  SoXipImageOverlayManager.h
  SoXipDicomOverlayManager.h
  SoXipImageOverlaySearch.h
  SoXipImageTextColor.h
  SoXipLine.h
  SoXipLineMeasurement.h
  SoXipLoadOverlay.h
  SoXipLoadOverlayPState.h
  SoXipLutColorBar.h
  SoXipMarkerSet.h
  SoXipMeasDistance.h
  SoXipMeasPixelLens.h
  SoXipMenu.h
  SoXipMenuBase.h
  SoXipMenuItem.h
  SoXipMenuItemBase.h
  SoXipMenuItemSeparator.h
  SoXipMenuStyle.h
  SoXipMenuStyleElement.h
  SoXipOverlayActions.h
  #SoXipOverlayColor.h
  SoXipOverlayColorElement.h
  SoXipOverlayDrawStyle.h
  SoXipOverlayDrawStyleElement.h
  SoXipOverlayExtractContour.h
  SoXipOverlayFilter.h
  SoXipOverlayFilterElement.h
  SoXipOverlayHandlerManip.h
  SoXipOverlayManager.h
  SoXipOverlayManips.h
  #SoXipOverlayManipulatedElement.h
  SoXipOverlayProperties.h
  SoXipOverlaySearch.h
  SoXipOverlaySearchContour.h
  SoXipOverlaySelectionFrame.h
  SoXipOverlaySelectionManip.h
  SoXipOverlaySettings.h
  SoXipOverlayTransformBoxManip.h
  SoXipOverlayTranslationManip.h
  SoXipPlot2Area.h
  SoXipPlot2Columns.h
  SoXipPlot2Curve.h
  SoXipPlot2Extent.h
  SoXipPlot2Grid.h
  SoXipPlot2Histogram.h
  SoXipPlot2Legend.h
  SoXipPlot2Ruler.h
  SoXipPlot2Samples.h
  SoXipPoint.h
  SoXipPolyLine.h
  SoXipPolygon.h
  SoXipPolygonArea.h
  SoXipRectangle.h
  SoXipSaveOverlay.h
  SoXipSaveOverlayPState.h
  SoXipScaleBar.h
  SoXipShapeGroup.h
  SoXipShapeList.h
  SoXipWidgetCamera.h
  XipBSpline.h
  XipHermiteSpline.h
  fontutils.h
  geomutils.h)

#--------------------------------------------------------------------
# Define the source files
#
set(SOURCES
  SbXipMarkerShapes.cpp
  SbXipPlot2LegendInfo.cpp
  SoXipAngle.cpp
  SoXipAnnotation.cpp
  SoXipBSpline.cpp
  SoXipBox.cpp
  SoXipContour.cpp
  SoXipDropShadowElement.cpp
  SoXipDropShadowStyle.cpp
  SoXipDisplayImageText.cpp
  SoXipEditText2.cpp
  SoXipEditableShape.cpp
  SoXipEllipse.cpp
  SoXipFontAutoScale.cpp
  SoXipHandlerShape.cpp
  SoXipHermiteSpline.cpp
  SoXipIcon.cpp
  SoXipImageOverlayManager.cpp
  SoXipDicomOverlayManager.cpp
  SoXipImageOverlayAdd.cpp
  SoXipImageOverlayClear.cpp
  SoXipImageOverlaySearch.cpp
  SoXipImageTextColor.cpp
  SoXipImageTextColorElement.cpp
  SoXipLine.cpp
  SoXipLineMeasurement.cpp
  SoXipLutColorBar.cpp
  SoXipLoadOverlay.cpp
  SoXipManipulableShape.cpp
  SoXipMarkerSet.cpp
  SoXipMeasDistance.cpp
  SoXipMeasPixelLens.cpp
  SoXipMenu.cpp
  SoXipMenuBase.cpp
  SoXipMenuItem.cpp
  SoXipMenuItemBase.cpp
  SoXipMenuItemSeparator.cpp
  SoXipMenuStyle.cpp
  SoXipMenuStyleElement.cpp
  SoXipOverlayActions.cpp
  SoXipOverlayColor.cpp
  SoXipOverlayColorElement.cpp
  SoXipOverlayDrawStyle.cpp
  SoXipOverlayDrawStyleElement.cpp
  SoXipOverlayElement.cpp
  SoXipOverlayExtractContour.cpp
  SoXipOverlayFilter.cpp
  SoXipOverlayFilterElement.cpp
  SoXipOverlayHandlerManip.cpp
  SoXipOverlayManager.cpp
  SoXipOverlayManipBase.cpp
  SoXipOverlayManips.cpp
  SoXipOverlayManipulatedElement.cpp
  SoXipOverlayProperties.cpp
  SoXipOverlaySearch.cpp
  SoXipOverlaySearchContour.cpp
  SoXipOverlaySelectionFrame.cpp
  SoXipOverlaySelectionManip.cpp
  SoXipOverlaySettings.cpp
  SoXipOverlayTransformBoxManip.cpp
  SoXipOverlayTranslationManip.cpp
  SoXipSegmentationOverlayManager.cpp
  SoXipPlot2Area.cpp
  SoXipPlot2AreaElement.cpp
  SoXipPlot2Columns.cpp
  SoXipPlot2Curve.cpp
  SoXipPlot2Element.cpp
  SoXipPlot2Extent.cpp
  SoXipPlot2Grid.cpp
  SoXipPlot2Histogram.cpp
  SoXipPlot2Legend.cpp
  SoXipPlot2Ruler.cpp
  SoXipPlot2Samples.cpp
  SoXipPoint.cpp
  SoXipPolyLine.cpp
  SoXipPolygon.cpp
  SoXipPolygonArea.cpp
  SoXipRectangle.cpp
  SoXipSaveOverlay.cpp
  SoXipScaleBar.cpp
  SoXipShape.cpp
  SoXipShapeGroup.cpp
  SoXipShapeList.cpp
  SoXipText2.cpp
  SoXipFontType.cpp
  SoXipFontTypeElement.cpp
  SoXipWidgetCamera.cpp
  SoXipSaveOverlayPState.cpp
  SoXipLoadOverlayPState.cpp
  XipBSpline.cpp
  XipHermiteSpline.cpp
  XipOverlayUtils.cpp
  XipPrimitiveDraw.cpp
  fontutils.cpp
  geomutils.cpp
  init.cpp)

#--------------------------------------------------------------------
# Define the compiler flags
#
if(WIN32)
  add_definitions(-DXIPIVOVERLAY_EXPORTS -DFTGL_LIBRARY_STATIC)
else(WIN32)
  add_definitions(-DHAVE_CONFIG_H)
endif(WIN32)

#--------------------------------------------------------------------
# Define the include directories
#
include_directories(
  ftgl/include)

if(WIN32)
  include_directories(
    ../../../include
    ../../extern/freetype-2.2.1/include)
else(WIN32)
  include_directories(
    ${CMAKE_CURRENT_BINARY_DIR} # for generated config.h
    ${FREETYPE_INCLUDE_DIRS}
    ${DCMTK_DIR}/include
    .)
endif(WIN32)

#--------------------------------------------------------------------
# Define the link directories
#
if(WIN32)
  link_directories(
    ${XIPEXT}/freetype2/lib)
else(WIN32)
  link_directories(
    ${src_BINARY_DIR}/database/core
    ${Xip_BINARY_DIR}/database/dicom
    ${xipivoverlay_BINARY_DIR}/ftgl
    ${DCMTK_DIR}/lib)
endif(WIN32)

#--------------------------------------------------------------------
# Compile the library
#
if(BUILD_SHARED_LIBS)
  add_library(xipivoverlay SHARED ${HEADERS} ${SOURCES})
else(BUILD_SHARED_LIBS)
  add_library(xipivoverlay STATIC ${HEADERS} ${SOURCES})
endif(BUILD_SHARED_LIBS)

set_target_properties(xipivoverlay
  PROPERTIES VERSION ${XIP_VERSION_STRING}
  SOVERSION ${XIP_VERSION_STRING})

#--------------------------------------------------------------------
# Link the library
#
target_link_libraries(xipivoverlay
  ${XIP_DICOM_LIBRARY}
  ${FREETYPE_LIBRARIES}
  ftgl)

add_dependencies(xipivoverlay xipivdicom)

#--------------------------------------------------------------------
# Install the library
#
install(TARGETS xipivoverlay
  RUNTIME DESTINATION bin/release CONFIGURATIONS Release
  ARCHIVE DESTINATION lib/release CONFIGURATIONS Release
  LIBRARY DESTINATION lib/release CONFIGURATIONS Release
  BUNDLE  DESTINATION lib/release CONFIGURATIONS Release)

install(TARGETS xipivoverlay
  RUNTIME DESTINATION bin/debug   CONFIGURATIONS Debug
  ARCHIVE DESTINATION lib/debug   CONFIGURATIONS Debug
  LIBRARY DESTINATION lib/debug   CONFIGURATIONS Debug
  BUNDLE  DESTINATION lib/debug   CONFIGURATIONS Debug)

if(WIN32)
  install(FILES ${LIBRARY_OUTPUT_PATH}/debug/xipivoverlay${CMAKE_DEBUG_POSTFIX}.pdb
    DESTINATION bin/debug CONFIGURATIONS Debug)
endif(WIN32)
