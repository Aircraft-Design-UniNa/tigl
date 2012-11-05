/* 
* Copyright (C) 2007-2011 German Aerospace Center (DLR/SC)
*
* Created: 2010-08-13 Markus Litz <Markus.Litz@dlr.de>
* Changed: $Id$ 
*
* Version: $Revision$
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
*     http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*/
/**
* @file
* @brief Tests for testing behavior of the routines for segment handling/query.
*/

#include "test.h" // Brings in the GTest framework
#include "tigl.h"

#include "CCPACSConfigurationManager.h"
#include "CCPACSWing.h"
#include "CCPACSWingSegment.h"

/***************************************************************************************************/

class WingSegment : public ::testing::Test {
 protected:
  virtual void SetUp() {
        char* filename = "TestData/CPACS_21_D150.xml";
        ReturnCode tixiRet;
        TiglReturnCode tiglRet;

        tiglHandle = -1;
        tixiHandle = -1;
        
        tixiRet = tixiOpenDocument(filename, &tixiHandle);
        ASSERT_TRUE (tixiRet == SUCCESS);

        tiglRet = tiglOpenCPACSConfiguration(tixiHandle, "D150_VAMP", &tiglHandle);
        ASSERT_TRUE(tiglRet == TIGL_SUCCESS);
  }

  virtual void TearDown() {
        ASSERT_TRUE(tiglCloseCPACSConfiguration(tiglHandle) == SUCCESS);
        ASSERT_TRUE(tixiCloseDocument(tixiHandle) == SUCCESS);
        tiglHandle = -1;
        tixiHandle = -1;
  }

  TixiDocumentHandle           tixiHandle;
  TiglCPACSConfigurationHandle tiglHandle;
};

class WingSegmentSimple : public ::testing::Test {
 protected:
  virtual void SetUp() {
        char* filename = "TestData/simpletest.cpacs.xml";
        ReturnCode tixiRet;
        TiglReturnCode tiglRet;

        tiglHandle = -1;
        tixiHandle = -1;
        
        tixiRet = tixiOpenDocument(filename, &tixiHandle);
        ASSERT_TRUE (tixiRet == SUCCESS);

        tiglRet = tiglOpenCPACSConfiguration(tixiHandle, "Cpacs2Test", &tiglHandle);
        ASSERT_TRUE(tiglRet == TIGL_SUCCESS);
  }

  virtual void TearDown() {
        ASSERT_TRUE(tiglCloseCPACSConfiguration(tiglHandle) == SUCCESS);
        ASSERT_TRUE(tixiCloseDocument(tixiHandle) == SUCCESS);
        tiglHandle = -1;
        tixiHandle = -1;
  }

  TixiDocumentHandle           tixiHandle;
  TiglCPACSConfigurationHandle tiglHandle;
};

/***************************************************************************************************/

/**
* Tests tiglGetWingCount with invalid CPACS handle.
*/
TEST_F(WingSegment, tiglGetWingCount_invalidHandle)
{
    int wingCount;
    ASSERT_TRUE(tiglGetWingCount(-1, &wingCount) == TIGL_NOT_FOUND);
}

/**
* Tests tiglGetWingCount with null pointer argument.
*/
TEST_F(WingSegment, tiglGetWingCount_nullPointerArgument)
{
    ASSERT_TRUE(tiglGetWingCount(tiglHandle, NULL) == TIGL_NULL_POINTER);
}

/**
* Tests successfull call of tiglGetWingCount.
*/
TEST_F(WingSegment, tiglGetWingCount_success)
{
    int wingCount;
    ASSERT_TRUE(tiglGetWingCount(tiglHandle, &wingCount) == TIGL_SUCCESS);
    ASSERT_TRUE(wingCount == 3);
}

/***************************************************************************************************/

/**
* Tests tiglWingGetSegmentCount with invalid CPACS handle.
*/
TEST_F(WingSegment, tiglWingGetSegmentCount_invalidHandle)
{
    int segmentCount;
    ASSERT_TRUE(tiglWingGetSegmentCount(-1, 1, &segmentCount) == TIGL_NOT_FOUND);
}

/**
* Tests tiglWingGetSegmentCount with invalid wing index.
*/
TEST_F(WingSegment, tiglWingGetSegmentCount_invalidWing)
{
    int segmentCount;
    ASSERT_TRUE(tiglWingGetSegmentCount(tiglHandle, 0, &segmentCount) == TIGL_INDEX_ERROR);
}

/**
* Tests tiglWingGetSegmentCount with null pointer argument for segmentCountPtr.
*/
TEST_F(WingSegment, tiglWingGetSegmentCount_nullPointerArgument)
{
    ASSERT_TRUE(tiglWingGetSegmentCount(tiglHandle, 1, NULL) == TIGL_NULL_POINTER);
}

/**
* Tests successfull call of tiglWingGetSegmentCount.
*/
TEST_F(WingSegment, tiglWingGetSegmentCount_success)
{
    int segmentCount;
    ASSERT_TRUE(tiglWingGetSegmentCount(tiglHandle, 1, &segmentCount) == TIGL_SUCCESS);
    ASSERT_TRUE(segmentCount == 3);
}

/***************************************************************************************************/

/**
* Tests tiglWingGetInnerConnectedSegmentCount with invalid CPACS handle.
*/
TEST_F(WingSegment, tiglWingGetInnerConnectedSegmentCount_invalidHandle)
{
    int segmentCount;
    ASSERT_TRUE(tiglWingGetInnerConnectedSegmentCount(-1, 1, 1, &segmentCount) == TIGL_NOT_FOUND);
}

/**
* Tests tiglWingGetInnerConnectedSegmentCount with invalid wing index.
*/
TEST_F(WingSegment, tiglWingGetInnerConnectedSegmentCount_invalidWing)
{
    int segmentCount;
    ASSERT_TRUE(tiglWingGetInnerConnectedSegmentCount(tiglHandle, 0, 1, &segmentCount) == TIGL_INDEX_ERROR);
}

/**
* Tests tiglWingGetInnerConnectedSegmentCount with invalid segment index.
*/
TEST_F(WingSegment, tiglWingGetInnerConnectedSegmentCount_invalidSegment)
{
    int segmentCount;
    ASSERT_TRUE(tiglWingGetInnerConnectedSegmentCount(tiglHandle, 1, 0, &segmentCount) == TIGL_INDEX_ERROR);
}

/**
* Tests tiglWingGetInnerConnectedSegmentCount with null pointer argument.
*/
TEST_F(WingSegment, tiglWingGetInnerConnectedSegmentCount_nullPointerArgument)
{
    ASSERT_TRUE(tiglWingGetInnerConnectedSegmentCount(tiglHandle, 1, 1, NULL) == TIGL_NULL_POINTER);
}

/**
* Tests successfull call of tiglWingGetInnerConnectedSegmentCount.
*/
TEST_F(WingSegment, tiglWingGetInnerConnectedSegmentCount_success)
{
    int segmentCount;
    ASSERT_TRUE(tiglWingGetInnerConnectedSegmentCount(tiglHandle, 1, 1, &segmentCount) == TIGL_SUCCESS);
    ASSERT_TRUE(segmentCount == 0);
    ASSERT_TRUE(tiglWingGetInnerConnectedSegmentCount(tiglHandle, 1, 2, &segmentCount) == TIGL_SUCCESS);
    ASSERT_TRUE(segmentCount == 1);
}

/***************************************************************************************************/

/**
* Tests tiglWingGetOuterConnectedSegmentCount with invalid CPACS handle.
*/
TEST_F(WingSegment, tiglWingGetOuterConnectedSegmentCount_invalidHandle)
{
    int segmentCount;
    ASSERT_TRUE(tiglWingGetOuterConnectedSegmentCount(-1, 1, 1, &segmentCount) == TIGL_NOT_FOUND);
}

/**
* Tests tiglWingGetOuterConnectedSegmentCount with invalid wing index.
*/
TEST_F(WingSegment, tiglWingGetOuterConnectedSegmentCount_invalidWing)
{
    int segmentCount;
    ASSERT_TRUE(tiglWingGetOuterConnectedSegmentCount(tiglHandle, 0, 1, &segmentCount) == TIGL_INDEX_ERROR);
}

/**
* Tests tiglWingGetOuterConnectedSegmentCount with invalid segment index.
*/
TEST_F(WingSegment, tiglWingGetOuterConnectedSegmentCount_invalidSegment)
{
    int segmentCount;
    ASSERT_TRUE(tiglWingGetOuterConnectedSegmentCount(tiglHandle, 1, 0, &segmentCount) == TIGL_INDEX_ERROR);
}

/**
* Tests tiglWingGetOuterConnectedSegmentCount with null pointer argument.
*/
TEST_F(WingSegment, tiglWingGetOuterConnectedSegmentCount_nullPointerArgument)
{
    ASSERT_TRUE(tiglWingGetOuterConnectedSegmentCount(tiglHandle, 1, 1, NULL) == TIGL_NULL_POINTER);
}

/**
* Tests successfull call of tiglWingGetOuterConnectedSegmentCount.
*/
TEST_F(WingSegment, tiglWingGetOuterConnectedSegmentCount_success)
{
    int segmentCount;
    ASSERT_TRUE(tiglWingGetOuterConnectedSegmentCount(tiglHandle, 1, 1, &segmentCount) == TIGL_SUCCESS);
    ASSERT_TRUE(segmentCount == 1);
    ASSERT_TRUE(tiglWingGetOuterConnectedSegmentCount(tiglHandle, 1, 3, &segmentCount) == TIGL_SUCCESS);
    ASSERT_TRUE(segmentCount == 0);
}

/***************************************************************************************************/

/**
* Tests tiglWingGetInnerConnectedSegmentIndex with invalid CPACS handle.
*/
TEST_F(WingSegment, tiglWingGetInnerConnectedSegmentIndex_invalidHandle)
{
    int connectedSegment;
    ASSERT_TRUE(tiglWingGetInnerConnectedSegmentIndex(-1, 1, 2, 1, &connectedSegment) == TIGL_NOT_FOUND);
}

/**
* Tests tiglWingGetInnerConnectedSegmentIndex with invalid wing index.
*/
TEST_F(WingSegment, tiglWingGetInnerConnectedSegmentIndex_invalidWing)
{
    int connectedSegment;
    ASSERT_TRUE(tiglWingGetInnerConnectedSegmentIndex(tiglHandle, 0, 2, 1, &connectedSegment) == TIGL_INDEX_ERROR);
}

/**
* Tests tiglWingGetInnerConnectedSegmentIndex with invalid segment index.
*/
TEST_F(WingSegment, tiglWingGetInnerConnectedSegmentIndex_invalidSegment)
{
    int connectedSegment;
    ASSERT_TRUE(tiglWingGetInnerConnectedSegmentIndex(tiglHandle, 1, 0, 1, &connectedSegment) == TIGL_INDEX_ERROR);
}

/**
* Tests tiglWingGetInnerConnectedSegmentIndex with invalid segment n-parameter.
*/
TEST_F(WingSegment, tiglWingGetInnerConnectedSegmentIndex_invalidN)
{
    int connectedSegment;
    ASSERT_TRUE(tiglWingGetInnerConnectedSegmentIndex(tiglHandle, 1, 1, 1, &connectedSegment) == TIGL_INDEX_ERROR);
    ASSERT_TRUE(tiglWingGetInnerConnectedSegmentIndex(tiglHandle, 1, 1, 0, &connectedSegment) == TIGL_INDEX_ERROR);
    ASSERT_TRUE(tiglWingGetInnerConnectedSegmentIndex(tiglHandle, 1, 2, 2, &connectedSegment) == TIGL_INDEX_ERROR);
}

/**
* Tests tiglWingGetInnerConnectedSegmentIndex with null pointer argument.
*/
TEST_F(WingSegment, tiglWingGetInnerConnectedSegmentIndex_nullPointerArgument)
{
    ASSERT_TRUE(tiglWingGetInnerConnectedSegmentIndex(tiglHandle, 1, 2, 1, NULL) == TIGL_NULL_POINTER);
}

/**
* Tests successfull call of tiglWingGetInnerConnectedSegmentIndex.
*/
TEST_F(WingSegment, tiglWingGetInnerConnectedSegmentIndex_success)
{
    int connectedSegment;
    ASSERT_TRUE(tiglWingGetInnerConnectedSegmentIndex(tiglHandle, 1, 2, 1, &connectedSegment) == TIGL_SUCCESS);
    ASSERT_TRUE(connectedSegment == 1);
    ASSERT_TRUE(tiglWingGetInnerConnectedSegmentIndex(tiglHandle, 1, 3, 1, &connectedSegment) == TIGL_SUCCESS);
    ASSERT_TRUE(connectedSegment == 2);
}

/***************************************************************************************************/

/**
* Tests tiglWingGetOuterConnectedSegmentIndex with invalid CPACS handle.
*/
TEST_F(WingSegment, tiglWingGetOuterConnectedSegmentIndex_invalidHandle)
{
    int connectedSegment;
    ASSERT_TRUE(tiglWingGetOuterConnectedSegmentIndex(-1, 1, 1, 1, &connectedSegment) == TIGL_NOT_FOUND);
}

/**
* Tests tiglWingGetOuterConnectedSegmentIndex with invalid wing index.
*/
TEST_F(WingSegment, tiglWingGetOuterConnectedSegmentIndex_invalidWing)
{
    int connectedSegment;
    ASSERT_TRUE(tiglWingGetOuterConnectedSegmentIndex(tiglHandle, 0, 1, 1, &connectedSegment) == TIGL_INDEX_ERROR);
}

/**
* Tests tiglWingGetOuterConnectedSegmentIndex with invalid segment index.
*/
TEST_F(WingSegment, tiglWingGetOuterConnectedSegmentIndex_invalidSegment)
{
    int connectedSegment;
    ASSERT_TRUE(tiglWingGetOuterConnectedSegmentIndex(tiglHandle, 1, 0, 1, &connectedSegment) == TIGL_INDEX_ERROR);
}

/**
* Tests tiglWingGetOuterConnectedSegmentIndex with invalid segment n-parameter.
*/
TEST_F(WingSegment, tiglWingGetOuterConnectedSegmentIndex_invalidN)
{
    int connectedSegment;
    ASSERT_TRUE(tiglWingGetOuterConnectedSegmentIndex(tiglHandle, 1, 1, 2, &connectedSegment) == TIGL_INDEX_ERROR);
    ASSERT_TRUE(tiglWingGetOuterConnectedSegmentIndex(tiglHandle, 1, 1, 0, &connectedSegment) == TIGL_INDEX_ERROR);
    ASSERT_TRUE(tiglWingGetOuterConnectedSegmentIndex(tiglHandle, 1, 3, 1, &connectedSegment) == TIGL_INDEX_ERROR);
}

/**
* Tests tiglWingGetOuterConnectedSegmentIndex with null pointer argument.
*/
TEST_F(WingSegment, tiglWingGetOuterConnectedSegmentIndex_nullPointerArgument)
{
    ASSERT_TRUE(tiglWingGetOuterConnectedSegmentIndex(tiglHandle, 1, 1, 1, NULL) == TIGL_NULL_POINTER);
}

/**
* Tests successfull call of tiglWingGetOuterConnectedSegmentIndex.
*/
TEST_F(WingSegment, tiglWingGetOuterConnectedSegmentIndex_success)
{
    int connectedSegment;
    ASSERT_TRUE(tiglWingGetOuterConnectedSegmentIndex(tiglHandle, 1, 1, 1, &connectedSegment) == TIGL_SUCCESS);
    ASSERT_TRUE(connectedSegment == 2);
    ASSERT_TRUE(tiglWingGetOuterConnectedSegmentIndex(tiglHandle, 1, 2, 1, &connectedSegment) == TIGL_SUCCESS);
    ASSERT_TRUE(connectedSegment == 3);
}

/***************************************************************************************************/

/**
* Tests tiglWingGetInnerSectionAndElementIndex with invalid CPACS handle.
*/
TEST_F(WingSegment, tiglWingGetInnerSectionAndElementIndex_invalidHandle)
{
    int sectionIndex;
    int elementIndex;
    ASSERT_TRUE(tiglWingGetInnerSectionAndElementIndex(-1, 1, 1, &sectionIndex, &elementIndex) == TIGL_NOT_FOUND);
}

/**
* Tests tiglWingGetInnerSectionAndElementIndex with invalid wing index.
*/
TEST_F(WingSegment, tiglWingGetInnerSectionAndElementIndex_invalidWing)
{
    int sectionIndex;
    int elementIndex;
    ASSERT_TRUE(tiglWingGetInnerSectionAndElementIndex(tiglHandle, 0, 1, &sectionIndex, &elementIndex) == TIGL_INDEX_ERROR);
}

/**
* Tests tiglWingGetInnerSectionAndElementIndex with invalid segment index.
*/
TEST_F(WingSegment, tiglWingGetInnerSectionAndElementIndex_invalidSegment)
{
    int sectionIndex;
    int elementIndex;
    ASSERT_TRUE(tiglWingGetInnerSectionAndElementIndex(tiglHandle, 1, 0, &sectionIndex, &elementIndex) == TIGL_INDEX_ERROR);
}

/**
* Tests tiglWingGetInnerSectionAndElementIndex with null pointer argument.
*/
TEST_F(WingSegment, tiglWingGetInnerSectionAndElementIndex_nullPointerArgument)
{
    int sectionIndex;
    int elementIndex;
    ASSERT_TRUE(tiglWingGetInnerSectionAndElementIndex(tiglHandle, 1, 1, NULL, &elementIndex) == TIGL_NULL_POINTER);
    ASSERT_TRUE(tiglWingGetInnerSectionAndElementIndex(tiglHandle, 1, 1, &sectionIndex, NULL) == TIGL_NULL_POINTER);
    ASSERT_TRUE(tiglWingGetInnerSectionAndElementIndex(tiglHandle, 1, 1, NULL, NULL)          == TIGL_NULL_POINTER);
}

/**
* Tests successfull call of tiglWingGetInnerSectionAndElementIndex.
*/
TEST_F(WingSegment, tiglWingGetInnerSectionAndElementIndex_success)
{
    int sectionIndex;
    int elementIndex;
    ASSERT_TRUE(tiglWingGetInnerSectionAndElementIndex(tiglHandle, 1, 1, &sectionIndex, &elementIndex) == TIGL_SUCCESS);
    ASSERT_TRUE(sectionIndex == 1);
    ASSERT_TRUE(elementIndex == 1);
    ASSERT_TRUE(tiglWingGetInnerSectionAndElementIndex(tiglHandle, 1, 2, &sectionIndex, &elementIndex) == TIGL_SUCCESS);
    ASSERT_TRUE(sectionIndex == 2);
    ASSERT_TRUE(elementIndex == 1);
    ASSERT_TRUE(tiglWingGetInnerSectionAndElementIndex(tiglHandle, 1, 3, &sectionIndex, &elementIndex) == TIGL_SUCCESS);
    ASSERT_TRUE(sectionIndex == 3);
    ASSERT_TRUE(elementIndex == 1);
}

/***************************************************************************************************/

/**
* Tests tiglWingGetOuterSectionAndElementIndex with invalid CPACS handle.
*/
TEST_F(WingSegment, tiglWingGetOuterSectionAndElementIndex_invalidHandle)
{
    int sectionIndex;
    int elementIndex;
    ASSERT_TRUE(tiglWingGetOuterSectionAndElementIndex(-1, 1, 1, &sectionIndex, &elementIndex) == TIGL_NOT_FOUND);
}

/**
* Tests tiglWingGetOuterSectionAndElementIndex with invalid wing index.
*/
TEST_F(WingSegment, tiglWingGetOuterSectionAndElementIndex_invalidWing)
{
    int sectionIndex;
    int elementIndex;
    ASSERT_TRUE(tiglWingGetOuterSectionAndElementIndex(tiglHandle, 0, 1, &sectionIndex, &elementIndex) == TIGL_INDEX_ERROR);
}

/**
* Tests tiglWingGetOuterSectionAndElementIndex with invalid segment index.
*/
TEST_F(WingSegment, tiglWingGetOuterSectionAndElementIndex_invalidSegment)
{
    int sectionIndex;
    int elementIndex;
    ASSERT_TRUE(tiglWingGetOuterSectionAndElementIndex(tiglHandle, 1, 0, &sectionIndex, &elementIndex) == TIGL_INDEX_ERROR);
}

/**
* Tests tiglWingGetOuterSectionAndElementIndex with null pointer argument.
*/
TEST_F(WingSegment, tiglWingGetOuterSectionAndElementIndex_nullPointerArgument)
{
    int sectionIndex;
    int elementIndex;
    ASSERT_TRUE(tiglWingGetOuterSectionAndElementIndex(tiglHandle, 1, 1, NULL, &elementIndex) == TIGL_NULL_POINTER);
    ASSERT_TRUE(tiglWingGetOuterSectionAndElementIndex(tiglHandle, 1, 1, &sectionIndex, NULL) == TIGL_NULL_POINTER);
    ASSERT_TRUE(tiglWingGetOuterSectionAndElementIndex(tiglHandle, 1, 1, NULL, NULL)          == TIGL_NULL_POINTER);
}

/**
* Tests successfull call of tiglWingGetOuterSectionAndElementIndex.
*/
TEST_F(WingSegment, tiglWingGetOuterSectionAndElementIndex_success)
{
    int sectionIndex;
    int elementIndex;
    ASSERT_TRUE(tiglWingGetOuterSectionAndElementIndex(tiglHandle, 1, 1, &sectionIndex, &elementIndex) == TIGL_SUCCESS);
    ASSERT_TRUE(sectionIndex == 2);
    ASSERT_TRUE(elementIndex == 1);
    ASSERT_TRUE(tiglWingGetOuterSectionAndElementIndex(tiglHandle, 1, 2, &sectionIndex, &elementIndex) == TIGL_SUCCESS);
    ASSERT_TRUE(sectionIndex == 3);
    ASSERT_TRUE(elementIndex == 1);
    ASSERT_TRUE(tiglWingGetOuterSectionAndElementIndex(tiglHandle, 1, 3, &sectionIndex, &elementIndex) == TIGL_SUCCESS);
    ASSERT_TRUE(sectionIndex == 4);
    ASSERT_TRUE(elementIndex == 1);
}



/***************************************************************************************************/
/*       Test of tiglWingGet[Inner|Outer]SectionAndElementUID-Functions      */ 
/***************************************************************************************************/

/**
* Tests tiglWingGetInnerSectionAndElementUID with invalid CPACS handle.
*/
TEST_F(WingSegment, tiglWingGetInnerSectionAndElementUID_invalidHandle)
{
    char* sectionUID;
    char* elementUID;
    ASSERT_TRUE(tiglWingGetInnerSectionAndElementUID(-1, 1, 1, &sectionUID, &elementUID) == TIGL_NOT_FOUND);
}

/**
* Tests tiglWingGetInnerSectionAndElementUID with invalid wing index.
*/
TEST_F(WingSegment, tiglWingGetInnerSectionAndElementUID_invalidWing)
{
    char* sectionUID;
    char* elementUID;
    ASSERT_TRUE(tiglWingGetInnerSectionAndElementUID(tiglHandle, 0, 1, &sectionUID, &elementUID) == TIGL_INDEX_ERROR);
}

/**
* Tests tiglWingGetInnerSectionAndElementUID with invalid segment index.
*/
TEST_F(WingSegment, tiglWingGetInnerSectionAndElementUID_invalidSegment)
{
    char* sectionUID;
    char* elementUID;
    ASSERT_TRUE(tiglWingGetInnerSectionAndElementUID(tiglHandle, 1, 0, &sectionUID, &elementUID) == TIGL_INDEX_ERROR);
}


/**
* Tests successfull call of tiglWingGetInnerSectionAndElementUID.
*/
TEST_F(WingSegment, tiglWingGetInnerSectionAndElementUID_success)
{
    char* sectionUID;
    char* elementUID;

    ASSERT_TRUE(tiglWingGetInnerSectionAndElementUID(tiglHandle, 1, 1, &sectionUID, &elementUID) == TIGL_SUCCESS);
    ASSERT_TRUE(strcmp(sectionUID, "D150_VAMP_W1_Sec1") == 0);
    ASSERT_TRUE(strcmp(elementUID, "D150_VAMP_W1_Sec1_Elem1") == 0);
	free(sectionUID);
	free(elementUID);
    
	ASSERT_TRUE(tiglWingGetInnerSectionAndElementUID(tiglHandle, 1, 2, &sectionUID, &elementUID) == TIGL_SUCCESS);
    ASSERT_TRUE(strcmp(sectionUID, "D150_VAMP_W1_Sec2") == 0);
    ASSERT_TRUE(strcmp(elementUID, "D150_VAMP_W1_Sec2_Elem1") == 0);
	free(sectionUID);
	free(elementUID);

    ASSERT_TRUE(tiglWingGetInnerSectionAndElementUID(tiglHandle, 1, 3, &sectionUID, &elementUID) == TIGL_SUCCESS);
    ASSERT_TRUE(strcmp(sectionUID, "D150_VAMP_W1_Sec3") == 0);
    ASSERT_TRUE(strcmp(elementUID, "D150_VAMP_W1_Sec3_Elem1") == 0);
    free(sectionUID);
	free(elementUID);
}

/***************************************************************************************************/

/**
* Tests tiglWingGetOuterSectionAndElementUID with invalid CPACS handle.
*/
TEST_F(WingSegment, tiglWingGetOuterSectionAndElementUID_invalidHandle)
{
    char* sectionUID;
    char* elementUID;
    ASSERT_TRUE(tiglWingGetOuterSectionAndElementUID(-1, 1, 1, &sectionUID, &elementUID) == TIGL_NOT_FOUND);
}

/**
* Tests tiglWingGetOuterSectionAndElementUID with invalid wing index.
*/
TEST_F(WingSegment, tiglWingGetOuterSectionAndElementUID_invalidWing)
{
    char* sectionUID;
    char* elementUID;
    ASSERT_TRUE(tiglWingGetOuterSectionAndElementUID(tiglHandle, 0, 1, &sectionUID, &elementUID) == TIGL_INDEX_ERROR);
}

/**
* Tests tiglWingGetOuterSectionAndElementUID with invalid segment index.
*/
TEST_F(WingSegment, tiglWingGetOuterSectionAndElementUID_invalidSegment)
{
    char* sectionUID;
    char* elementUID;
    ASSERT_TRUE(tiglWingGetOuterSectionAndElementUID(tiglHandle, 1, 0, &sectionUID, &elementUID) == TIGL_INDEX_ERROR);
}

/**
* Tests successfull call of tiglWingGetOuterSectionAndElementUID.
*/
TEST_F(WingSegment, tiglWingGetOuterSectionAndElementUID_success)
{
	char* sectionUID;
    char* elementUID;
    ASSERT_TRUE(tiglWingGetOuterSectionAndElementUID(tiglHandle, 1, 1, &sectionUID, &elementUID) == TIGL_SUCCESS);
    ASSERT_TRUE(strcmp(sectionUID, "D150_VAMP_W1_Sec2") == 0);
    ASSERT_TRUE(strcmp(elementUID, "D150_VAMP_W1_Sec2_Elem1") == 0);
	free(sectionUID);
	free(elementUID);

    ASSERT_TRUE(tiglWingGetOuterSectionAndElementUID(tiglHandle, 1, 2, &sectionUID, &elementUID) == TIGL_SUCCESS);
    ASSERT_TRUE(strcmp(sectionUID, "D150_VAMP_W1_Sec3") == 0);
    ASSERT_TRUE(strcmp(elementUID, "D150_VAMP_W1_Sec3_Elem1") == 0);
    free(sectionUID);
	free(elementUID);
	
	ASSERT_TRUE(tiglWingGetOuterSectionAndElementUID(tiglHandle, 1, 3, &sectionUID, &elementUID) == TIGL_SUCCESS);
    ASSERT_TRUE(strcmp(sectionUID, "D150_VAMP_W1_Sec4") == 0);
    ASSERT_TRUE(strcmp(elementUID, "D150_VAMP_W1_Sec4_Elem1") == 0);
	free(sectionUID);
	free(elementUID);
}

/* Tests on simple geometry__________________________ */
TEST_F(WingSegmentSimple, getPoint_accuracy)
{
    double x = 0., y = 0., z = 0.;
    ASSERT_TRUE(tiglWingGetUpperPoint(tiglHandle, 1, 1, 0.5, 0.5, &x, &y, &z) == TIGL_SUCCESS);
    ASSERT_NEAR(y, 0.5, 1e-7);
    ASSERT_NEAR(x, 0.5, 1e-7);
    //z value read from profile data
    ASSERT_NEAR(z, 0.0529402520006, 1e-7);

    ASSERT_TRUE(tiglWingGetUpperPoint(tiglHandle, 1, 2, 0.5, 0.5, &x, &y, &z) == TIGL_SUCCESS);
    ASSERT_NEAR(y, 1.5, 1e-7);
    ASSERT_NEAR(x, 0.625, 1e-7);
}

TEST_F(WingSegmentSimple, getChordPointInternal_accuracy)
{
    // now we have do use the internal interface as we currently have no public api for this
    tigl::CCPACSConfigurationManager & manager = tigl::CCPACSConfigurationManager::GetInstance();
    tigl::CCPACSConfiguration & config = manager.GetConfiguration(tiglHandle);
    tigl::CCPACSWing& wing = config.GetWing(1);

    tigl::CCPACSWingSegment& segment  = (tigl::CCPACSWingSegment&) wing.GetSegment(1);
    tigl::CCPACSWingSegment& segment2 = (tigl::CCPACSWingSegment&) wing.GetSegment(2);
    gp_Pnt point = segment.GetChordPoint(0,0.5);
    ASSERT_NEAR(point.X(), 0.5,1e-7);
    ASSERT_NEAR(point.Y(), 0., 1e-7);
    ASSERT_NEAR(point.Z(), 0., 1e-7);

    point = segment.GetChordPoint(1,0.5);
    ASSERT_NEAR(point.X(), 0.5,1e-7);
    ASSERT_NEAR(point.Y(), 1., 1e-7);
    ASSERT_NEAR(point.Z(), 0., 1e-7);

    point = segment2.GetChordPoint(0.5,0.5);
    ASSERT_NEAR(point.X(), 0.625 ,1e-7);
    ASSERT_NEAR(point.Y(), 1.5, 1e-7);
    ASSERT_NEAR(point.Z(), 0., 1e-7);

    point = segment2.GetChordPoint(1,0.5);
    ASSERT_NEAR(point.X(), 0.75 ,1e-7);
    ASSERT_NEAR(point.Y(), 2., 1e-7);
    ASSERT_NEAR(point.Z(), 0., 1e-7);
}

TEST_F(WingSegmentSimple, trafo_Consistency){
    // we transform eta, xsi to x,y,z and perform the back transform
    // we check if we get the the same eta xsi as before
    int segIndex = 1;
    double eta_start = 0.5;
    double xsi_start = 0.5;
    double x = 0., y = 0., z = 0.;
    ASSERT_TRUE(tiglWingGetUpperPoint(tiglHandle, 1, segIndex, eta_start, xsi_start, &x, &y, &z) == TIGL_SUCCESS);

    // now we have do use the internal interface as we currently have no public api for this
    tigl::CCPACSConfigurationManager & manager = tigl::CCPACSConfigurationManager::GetInstance();
    tigl::CCPACSConfiguration & config = manager.GetConfiguration(tiglHandle);
    tigl::CCPACSWing& wing = config.GetWing(1);
    tigl::CCPACSWingSegment& segment = (tigl::CCPACSWingSegment&) wing.GetSegment(segIndex);

    gp_Pnt point(x,y,z);
    double xsi_end = segment.GetXsi(point, true);
    double eta_end = segment.GetEta(point, true);

    ASSERT_NEAR(eta_end, eta_start, 1e-7);
    ASSERT_NEAR(xsi_end, xsi_start, 1e-7);
}
