cmake_minimum_required ( VERSION 2.6)

option(TIGL_BINDINGS_JAVA_INTERNAL "Builds the Java interface to the internal API" ON)
mark_as_advanced(TIGL_BINDINGS_JAVA_INTERNAL)

if (TIGL_BINDINGS_JAVA_INTERNAL)

  #-----------------------------------------------------------------------------------
  # setup the c++ wrapper code for OCCT
  #-----------------------------------------------------------------------------------

  set( CMAKE_CONFIGURATION_TYPES Debug;Release;Protected CACHE INTERNAL "" FORCE)

  set( CMAKE_SHARED_LINKER_FLAGS_PROTECTED ${CMAKE_SHARED_LINKER_FLAGS_RELEASE} CACHE STRING "" FORCE )

  set( CMAKE_BUILD_TYPE $ENV{BUILD_TYPE} CACHE INTERNAL "Build type of wrapper" FORCE )

  set( PROJECT OCCwrapJava )

  project( ${PROJECT} )

  set(BUILD_SHARED_LIBS ON)

  # change default locations of binaries (dlls)
  set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE   ../bin)
  set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG     ../bind)
  set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_PROTECTED ../binp)

  # change default locations of libraries (lib)
  set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_RELEASE   ../lib)
  set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_DEBUG     ../libd)
  set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_PROTECTED ../libp)

  if(WIN32)
    if (MSVC)              
      add_definitions(/bigobj)
    endif()
  else()
    add_definitions(/DGL_GLEXT_LEGACY)
  endif()

  # increase compiler warnings level (-W4 for MSVC, -Wall for GCC)
  if(MSVC)
    if(CMAKE_CXX_FLAGS MATCHES "/W[0-4]")
      string(REGEX REPLACE "/W[0-4]" "/W4" CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")
    else()
      set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /W4")
    endif()
  elseif(CMAKE_COMPILER_IS_GNUCC OR CMAKE_COMPILER_IS_GNUCXX)
   set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -fno-strict-aliasing")
  endif()

  if (DEFINED CMAKE_COMPILER_IS_GNUCXX OR "x${CMAKE_CXX_COMPILER_ID}" STREQUAL "xClang")
    set (CMAKE_CXX_FLAGS "-std=gnu++11 ${CMAKE_CXX_FLAGS}")
  endif()

  set(CMAKE_CXX_FLAGS_PROTECTED "${CMAKE_CXX_FLAGS_PROTECTED} /DUSE_OCC_LICENSE")

  # add headers 
  include_directories (${OpenCASCADE_INCLUDE_DIR} $ENV{JAVA_HOME}/include $ENV{JAVA_HOME}/include/win32 $ENV{JAVA_HOME}/include/linux)

  # add libraries
  link_directories (${OpenCASCADE_LINK_DIRECTORY} $ENV{JAVA_HOME}/jre/lib/amd64 $ENV{JAVA_HOME}/lib)

  # lib to include:
  list( APPEND LINK_LIBRARIES TKernel )
  list( APPEND LINK_LIBRARIES TKMath )
  list( APPEND LINK_LIBRARIES TKG2d )
  list( APPEND LINK_LIBRARIES TKG3d ) 
  list( APPEND LINK_LIBRARIES TKGeomBase ) 
  list( APPEND LINK_LIBRARIES TKBRep )
  list( APPEND LINK_LIBRARIES TKGeomAlgo )
  list( APPEND LINK_LIBRARIES TKHLR )
  list( APPEND LINK_LIBRARIES TKTopAlgo )
  list( APPEND LINK_LIBRARIES TKPrim )
  list( APPEND LINK_LIBRARIES TKBO )
  list( APPEND LINK_LIBRARIES TKBool )
  list( APPEND LINK_LIBRARIES TKShHealing )
  list( APPEND LINK_LIBRARIES TKOffset )
  list( APPEND LINK_LIBRARIES TKFillet )
  list( APPEND LINK_LIBRARIES TKService )
  list( APPEND LINK_LIBRARIES TKV3d ) 
  list( APPEND LINK_LIBRARIES TKOpenGl )
  list( APPEND LINK_LIBRARIES TKCDF )
  list( APPEND LINK_LIBRARIES TKLCAF ) 
  list( APPEND LINK_LIBRARIES TKCAF ) 
  list( APPEND LINK_LIBRARIES TKXSBase )
  list( APPEND LINK_LIBRARIES TKIGES ) 
  list( APPEND LINK_LIBRARIES TKSTEPBase ) 
  list( APPEND LINK_LIBRARIES TKSTEP ) 
  list( APPEND LINK_LIBRARIES TKSTL )
  list( APPEND LINK_LIBRARIES TKVRML )
  list( APPEND LINK_LIBRARIES TKFeat )
  list( APPEND LINK_LIBRARIES jawt )         

  set (SOURCES occjava_wrap.cxx)

  add_library (${PROJECT} SHARED ${HEADERS} ${SOURCES})

  target_link_libraries( ${PROJECT} ${LINK_LIBRARIES} )

  #-----------------------------------------------------------------------------------
  # setup the java wrapper classes and jar archive
  #-----------------------------------------------------------------------------------

  set(TIGLJAVAINTERNAL_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/OCCJava/src)
  configure_file(${CMAKE_CURRENT_SOURCE_DIR}/OCCJava/build.gradle.in ${CMAKE_CURRENT_BINARY_DIR}/build.gradle)
	configure_file(${CMAKE_CURRENT_SOURCE_DIR}/OCCJava/gradle.properties ${CMAKE_CURRENT_BINARY_DIR}/gradle.properties COPYONLY )
  file(GLOB_RECURSE TIGL_JAVAINTERNAL_SRC "*.java")
  SET(TIGL_INTERNAL_JAR "${PROJECT_BINARY_DIR}/${CMAKE_INSTALL_LIBDIR}/tigl-occjava-${TIGL_VERSION}.jar")

  add_custom_command(
		OUTPUT ${TIGL_INTERNAL_JAR}
		DEPENDS ${TIGL_JAVAINTERNAL_SRC}
		WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
		COMMAND ${Java_JAVA_EXECUTABLE} -classpath ${CMAKE_CURRENT_SOURCE_DIR}/OCCJava/gradle/wrapper/gradle-wrapper.jar org.gradle.wrapper.GradleWrapperMain assemble
	)
	
	ADD_CUSTOM_TARGET(
		tigl-java-internal ALL 
		DEPENDS ${TIGL_INTERNAL_JAR}
	)
	
	install(FILES ${TIGL_INTERNAL_JAR} DESTINATION share/tigl3/java)

endif(TIGL_BINDINGS_JAVA_INTERNAL)