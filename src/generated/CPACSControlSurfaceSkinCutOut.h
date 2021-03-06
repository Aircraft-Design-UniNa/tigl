// Copyright (c) 2018 RISC Software GmbH
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

#include <boost/optional.hpp>
#include <boost/utility/in_place_factory.hpp>
#include <string>
#include <tixi.h>
#include "tigl_internal.h"

namespace tigl
{
namespace generated
{
    class CPACSControlSurfaceWingCutOut;

    // This class is used in:
    // CPACSControlSurfaceWingCutOut

    // generated from /xsd:schema/xsd:complexType[186]
    /// @brief Cut out of the parents upper/lower skin due to a
    /// control surface.
    /// 
    /// Optional. Definition of the skin cut out due to a
    /// control surface. The cut out of the skin can either be defined
    /// by referencing to a spar uID or by defining the relative chord
    /// values (xsi) of the cut at the inner and outer border of the
    /// control surface. The xsi value is based on the parents chord.
    /// For leading edge devices additional parameters can be defined.
    /// An example for wing cut outs can be found in the
    /// picture below:
    /// @see wingCutOut
    /// 
    class CPACSControlSurfaceSkinCutOut
    {
    public:
        TIGL_EXPORT CPACSControlSurfaceSkinCutOut(CPACSControlSurfaceWingCutOut* parent);

        TIGL_EXPORT virtual ~CPACSControlSurfaceSkinCutOut();

        TIGL_EXPORT CPACSControlSurfaceWingCutOut* GetParent();

        TIGL_EXPORT const CPACSControlSurfaceWingCutOut* GetParent() const;

        TIGL_EXPORT virtual void ReadCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath);
        TIGL_EXPORT virtual void WriteCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath) const;

        TIGL_EXPORT bool ValidateChoices() const;

        TIGL_EXPORT virtual const boost::optional<std::string>& GetSparUID_choice1() const;
        TIGL_EXPORT virtual void SetSparUID_choice1(const boost::optional<std::string>& value);

        TIGL_EXPORT virtual const boost::optional<double>& GetXsiInnerBorder_choice2() const;
        TIGL_EXPORT virtual void SetXsiInnerBorder_choice2(const boost::optional<double>& value);

        TIGL_EXPORT virtual const boost::optional<double>& GetXsiOuterBorder_choice2() const;
        TIGL_EXPORT virtual void SetXsiOuterBorder_choice2(const boost::optional<double>& value);

    protected:
        CPACSControlSurfaceWingCutOut* m_parent;

        /// Reference to a spar, defining the skin cut
        /// out.
        boost::optional<std::string> m_sparUID_choice1;

        /// Xsi value of the inner border, where the cut
        /// out begins.
        boost::optional<double>      m_xsiInnerBorder_choice2;

        /// Xsi value of the outer border, where the cut
        /// out begins.
        boost::optional<double>      m_xsiOuterBorder_choice2;

    private:
#ifdef HAVE_CPP11
        CPACSControlSurfaceSkinCutOut(const CPACSControlSurfaceSkinCutOut&) = delete;
        CPACSControlSurfaceSkinCutOut& operator=(const CPACSControlSurfaceSkinCutOut&) = delete;

        CPACSControlSurfaceSkinCutOut(CPACSControlSurfaceSkinCutOut&&) = delete;
        CPACSControlSurfaceSkinCutOut& operator=(CPACSControlSurfaceSkinCutOut&&) = delete;
#else
        CPACSControlSurfaceSkinCutOut(const CPACSControlSurfaceSkinCutOut&);
        CPACSControlSurfaceSkinCutOut& operator=(const CPACSControlSurfaceSkinCutOut&);
#endif
    };
} // namespace generated

// CPACSControlSurfaceSkinCutOut is customized, use type CCPACSControlSurfaceSkinCutout directly

// Aliases in tigl namespace
#ifdef HAVE_CPP11
using CCPACSControlSurfaceWingCutOut = generated::CPACSControlSurfaceWingCutOut;
#else
typedef generated::CPACSControlSurfaceWingCutOut CCPACSControlSurfaceWingCutOut;
#endif
} // namespace tigl
