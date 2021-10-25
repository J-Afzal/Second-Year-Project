# This CMakeList file can, depending upon which booleans are set, create the Model
# and Model_Viewer libararies; create the Model library test code and CTests; create the
# Observer executable; and create the installer
cmake_minimum_required( VERSION 3.9.2 )

# The name of the project and its curent version
project( Observer VERSION 1.2.1)

# Boolean to adjust want you want to build
set( BUILD_MODEL_TEST_CODE  TRUE)
set( BUILD_OBSERVER         TRUE)
set( BUILD_INSTALLERS       TRUE)

#These two lines set the path for QT and VTK dll files transfered below. Might need changed based on personal settings
set(VTK_DIR "C:\\dev\\vtk\\build")
set(Qt5Widgets_DIR "C:\\dev\\qt\\5.15.0\\msvc2019_64\\lib\\cmake\\Qt5Widgets")

# All booleans require the model library
if ( ${BUILD_MODEL_TEST_CODE} )
    add_subdirectory ( model )

endif()

# Observer and installer require the model_viewer library and Observer executable
if ( ${BUILD_OBSERVER} OR ${BUILD_INSTALLERS} )
    add_subdirectory ( model_viewer )
endif()

# Installer code
if( ${BUILD_INSTALLERS} )
    if( WIN32 )
        set( CPACK_GENERATOR NSIS )
    else()
        set(CPACK_GENERATOR ZIP)
    endif()

    install(TARGETS Observer
        RUNTIME
        DESTINATION bin
        COMPONENT applications
        )

    install(FILES model_viewer/images/Observer.stl
        model_viewer/images/ObserverLogo.stl
        DESTINATION example_models
        COMPONENT applications
        )

    install(FILES LICENSE.txt
        installers/README.txt
        DESTINATION docs
        COMPONENT documentation
        )

    install(FILES example_models/a-10-thunderbolt-mk2.stl
        example_models/airbus_a400m.stl
        example_models/bawar_plane.stl
        example_models/cube.stl
        example_models/he111.stl
        example_models/sphere.stl
        example_models/ExampleModel1.mod
        example_models/ExampleModel2.mod
        example_models/ExampleModel3.mod
        example_models/Model_One.txt
        example_models/Model_Two.txt
        DESTINATION example_models
        COMPONENT example_models
        )

    install(TARGETS Observer_Model_Library
        ARCHIVE
        DESTINATION lib
        COMPONENT libraries
        )

    install(FILES	${CMAKE_DIR}/bin/Qt5Cored.dll
        ${CMAKE_DIR}/bin/Qt5Guid.dll
        ${CMAKE_DIR}/bin/Qt5Widgetsd.dll
        ${VTK_DIR}/bin/Debug/vtkRenderingGL2PSOpenGL2-8.2.dll
        ${VTK_DIR}/bin/Debug/QVTKWidgetPlugin.dll
        ${VTK_DIR}/bin/Debug/vtkCommonColor-8.2.dll
        ${VTK_DIR}/bin/Debug/vtkCommonComputationalGeometry-8.2.dll
        ${VTK_DIR}/bin/Debug/vtkCommonCore-8.2.dll
        ${VTK_DIR}/bin/Debug/vtkCommonDataModel-8.2.dll
        ${VTK_DIR}/bin/Debug/vtkCommonExecutionModel-8.2.dll
        ${VTK_DIR}/bin/Debug/vtkCommonMath-8.2.dll
        ${VTK_DIR}/bin/Debug/vtkCommonMisc-8.2.dll
        ${VTK_DIR}/bin/Debug/vtkCommonSystem-8.2.dll
        ${VTK_DIR}/bin/Debug/vtkCommonTransforms-8.2.dll
        ${VTK_DIR}/bin/Debug/vtkDICOMParser-8.2.dll
        ${VTK_DIR}/bin/Debug/vtkdoubleconversion-8.2.dll
        ${VTK_DIR}/bin/Debug/vtkFiltersCore-8.2.dll
        ${VTK_DIR}/bin/Debug/vtkFiltersExtraction-8.2.dll
        ${VTK_DIR}/bin/Debug/vtkFiltersGeneral-8.2.dll
        ${VTK_DIR}/bin/Debug/vtkFiltersGeometry-8.2.dll
        ${VTK_DIR}/bin/Debug/vtkFiltersHybrid-8.2.dll
        ${VTK_DIR}/bin/Debug/vtkFiltersModeling-8.2.dll
        ${VTK_DIR}/bin/Debug/vtkFiltersSources-8.2.dll
        ${VTK_DIR}/bin/Debug/vtkFiltersStatistics-8.2.dll
        ${VTK_DIR}/bin/Debug/vtkfreetype-8.2.dll
        ${VTK_DIR}/bin/Debug/vtkgl2ps-8.2.dll
        ${VTK_DIR}/bin/Debug/vtkglew-8.2.dll
        ${VTK_DIR}/bin/Debug/vtkGUISupportQt-8.2.dll
        ${VTK_DIR}/bin/Debug/vtkImagingColor-8.2.dll
        ${VTK_DIR}/bin/Debug/vtkImagingCore-8.2.dll
        ${VTK_DIR}/bin/Debug/vtkImagingFourier-8.2.dll
        ${VTK_DIR}/bin/Debug/vtkImagingGeneral-8.2.dll
        ${VTK_DIR}/bin/Debug/vtkImagingHybrid-8.2.dll
        ${VTK_DIR}/bin/Debug/vtkImagingSources-8.2.dll
        ${VTK_DIR}/bin/Debug/vtkInteractionStyle-8.2.dll
        ${VTK_DIR}/bin/Debug/vtkInteractionWidgets-8.2.dll
        ${VTK_DIR}/bin/Debug/vtkIOCore-8.2.dll
        ${VTK_DIR}/bin/Debug/vtkIOGeometry-8.2.dll
        ${VTK_DIR}/bin/Debug/vtkIOImage-8.2.dll
        ${VTK_DIR}/bin/Debug/vtkjpeg-8.2.dll
        ${VTK_DIR}/bin/Debug/vtklz4-8.2.dll
        ${VTK_DIR}/bin/Debug/vtklzma-8.2.dll
        ${VTK_DIR}/bin/Debug/vtkmetaio-8.2.dll
        ${VTK_DIR}/bin/Debug/vtkpng-8.2.dll
        ${VTK_DIR}/bin/Debug/vtkRenderingAnnotation-8.2.dll
        ${VTK_DIR}/bin/Debug/vtkRenderingCore-8.2.dll
        ${VTK_DIR}/bin/Debug/vtkRenderingFreeType-8.2.dll
        ${VTK_DIR}/bin/Debug/vtkRenderingGL2PSOpenGL2-8.2.dll
        ${VTK_DIR}/bin/Debug/vtkRenderingOpenGL2-8.2.dll
        ${VTK_DIR}/bin/Debug/vtksys-8.2.dll
        ${VTK_DIR}/bin/Debug/vtktiff-8.2.dll
        ${VTK_DIR}/bin/Debug/vtkzlib-8.2.dll
        DESTINATION bin
        COMPONENT libraries
        )

    install(FILES model/include/Model.hpp;
        model/include/Cell.hpp;
        model/include/Matrix.hpp;
        model/include/Vectors.h;
        model/include/Material.h;
        model_viewer/include/mainwindow.h;
        model_viewer/include/edit_light.h;
        model_viewer/include/filters.h;
        model_viewer/include/vtklight_withname.h
        DESTINATION include
        COMPONENT headers
        )

    # CPACK macros below here
    set(CPACK_PACKAGE_NAME "Observer")
    set(CPACK_PACKAGE_VERSION "${PROJECT_VERSION}")
    set(CPACK_PACKAGE_VENDOR "The Space Explorers")
    set(CPACK_NSIS_MUI_ICON ${CMAKE_CURRENT_SOURCE_DIR}/model_viewer/images/ObserverLogo.ico)
    set(CPACK_NSIS_MUI_UNIICON ${CMAKE_CURRENT_SOURCE_DIR}/model_viewer/images/ObserverLogo.ico)
    set(CPACK_NSIS_INSTALLED_ICON_NAME ${CMAKE_CURRENT_SOURCE_DIR}/model_viewer/images/ObserverLogo.ico)

    set(CPACK_PACKAGE_INSTALL_DIRECTORY "Observer")
    set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "Observer by The Space Explorers")
    set(CPACK_RESOURCE_FILE_LICENSE ${CMAKE_CURRENT_SOURCE_DIR}/LICENSE.txt)

    # Start menu and desktop shortcuts
    set(CPACK_PACKAGE_EXECUTABLES Observer;Observer Observer;Observer)
    set(CPACK_CREATE_DESKTOP_LINKS Observer Observer)
    set(CPACK_NSIS_MODIFY_PATH "ON")

    # Define components and their display names
    set(CPACK_COMPONENTS_ALL applications documentation example_models libraries headers)
    set(CPACK_COMPONENT_APPLICATIONS_DISPLAY_NAME "Applications")
    set(CPACK_COMPONENT_DOCUMENTATION_DISPLAY_NAME "Documentation")
    set(CPACK_COMPONENT_EXAMPLE_MODELS_DISPLAY_NAME "Example Models")
    set(CPACK_COMPONENT_LIBRARIES_DISPLAY_NAME "Libraries")
    set(CPACK_COMPONENT_HEADERS_DISPLAY_NAME "Header Files")

    # Define dependencies between components
    set(CPACK_COMPONENT_APPLICATIONS_DEPENDS libraries)
    set(CPACK_COMPONENT_HEADERS_DEPENDS libraries)

    # Define groups
    set(CPACK_COMPONENT_APPLICATIONS_GROUP "Runtime")
    set(CPACK_COMPONENT_DOCUMENTATION_GROUP "Runtime")
    set(CPACK_COMPONENT_EXAMPLE_MODELS_GROUP "Runtime")
    set(CPACK_COMPONENT_LIBRARIES_GROUP "Runtime")
    set(CPACK_COMPONENT_HEADERS_GROUP "Development")

    # Define NSIS installation types
    set(CPACK_ALL_INSTALL_TYPES Everything "Applications With Libraries" Developer)
    set(CPACK_COMPONENT_APPLICATIONS_INSTALL_TYPES Everything "Applications With Libraries")
    set(CPACK_COMPONENT_DOCUMENTATION_INSTALL_TYPES Everything "Applications With Libraries" Developer)
    set(CPACK_COMPONENT_EXAMPLE_MODELS_INSTALL_TYPES Everything)
    set(CPACK_COMPONENT_LIBRARIES_INSTALL_TYPES Everything "Applications With Libraries" Developer)
    set(CPACK_COMPONENT_HEADERS_INSTALL_TYPES Everything Developer)

    # Must be after the last CPACK macros
    include(CPack)

endif()
