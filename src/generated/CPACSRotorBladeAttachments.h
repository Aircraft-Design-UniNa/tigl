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

#pragma once

#include <string>
#include <tixi.h>
#include <vector>
#include "tigl_internal.h"
#include "UniquePtr.h"

namespace tigl
{
    class CCPACSRotorBladeAttachment;
    class CCPACSRotorHub;
    
    namespace generated
    {
        // This class is used in:
        // CPACSRotorHub
        
        // generated from /xsd:schema/xsd:complexType[738]
        class CPACSRotorBladeAttachments
        {
        public:
            TIGL_EXPORT CPACSRotorBladeAttachments(CCPACSRotorHub* parent);
            
            TIGL_EXPORT virtual ~CPACSRotorBladeAttachments();
            
            TIGL_EXPORT CCPACSRotorHub* GetParent() const;
            
            TIGL_EXPORT virtual void ReadCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath);
            TIGL_EXPORT virtual void WriteCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath) const;
            
            TIGL_EXPORT virtual const std::vector<unique_ptr<CCPACSRotorBladeAttachment> >& GetRotorBladeAttachments() const;
            TIGL_EXPORT virtual std::vector<unique_ptr<CCPACSRotorBladeAttachment> >& GetRotorBladeAttachments();
            
        protected:
            CCPACSRotorHub* m_parent;
            
            std::vector<unique_ptr<CCPACSRotorBladeAttachment> > m_rotorBladeAttachments;
            
        private:
            #ifdef HAVE_CPP11
            CPACSRotorBladeAttachments(const CPACSRotorBladeAttachments&) = delete;
            CPACSRotorBladeAttachments& operator=(const CPACSRotorBladeAttachments&) = delete;
            
            CPACSRotorBladeAttachments(CPACSRotorBladeAttachments&&) = delete;
            CPACSRotorBladeAttachments& operator=(CPACSRotorBladeAttachments&&) = delete;
            #else
            CPACSRotorBladeAttachments(const CPACSRotorBladeAttachments&);
            CPACSRotorBladeAttachments& operator=(const CPACSRotorBladeAttachments&);
            #endif
        };
    }
    
    // CPACSRotorBladeAttachments is customized, use type CCPACSRotorBladeAttachments directly
}
