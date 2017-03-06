// Copyright (c) 2016 RISC Software GmbH
//
// This file was generated by CPACSGen from CPACS XML Schema (c) German Aerospace Center (DLR/SC).
// Do not edit, all changes are lost when files are re-generated.
//
// Licensed under the Apache License, Version 2.0 (the "License")
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include <CCPACSExternalObject.h>
#include <cassert>
#include "CCPACSAircraftModel.h"
#include "TixiHelper.h"
#include "CTiglLogging.h"
#include "CTiglError.h"
#include "CPACSGenericGeometryComponents.h"

namespace tigl
{
    namespace generated
    {
        CPACSGenericGeometryComponents::CPACSGenericGeometryComponents(CCPACSAircraftModel* parent)
        {
            //assert(parent != NULL);
            m_parent = parent;
        }
        
        CPACSGenericGeometryComponents::~CPACSGenericGeometryComponents() {}
        
        CCPACSAircraftModel* CPACSGenericGeometryComponents::GetParent() const
        {
            return m_parent;
        }
        
        void CPACSGenericGeometryComponents::ReadCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath)
        {
            // read element genericGeometryComponent
            if (tixihelper::TixiCheckElement(tixiHandle, xpath + "/genericGeometryComponent")) {
                tixihelper::TixiReadElements(tixiHandle, xpath + "/genericGeometryComponent", m_genericGeometryComponent, reinterpret_cast<CCPACSExternalObjects*>(this));
            }
            
        }
        
        void CPACSGenericGeometryComponents::WriteCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath) const
        {
            // write element genericGeometryComponent
            tixihelper::TixiSaveElements(tixiHandle, xpath + "/genericGeometryComponent", m_genericGeometryComponent);
            
        }
        
        const std::vector<unique_ptr<CCPACSExternalObject>>& CPACSGenericGeometryComponents::GetGenericGeometryComponent() const
        {
            return m_genericGeometryComponent;
        }
        
        std::vector<unique_ptr<CCPACSExternalObject>>& CPACSGenericGeometryComponents::GetGenericGeometryComponent()
        {
            return m_genericGeometryComponent;
        }
        
    }
}
