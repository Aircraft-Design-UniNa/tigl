/* 
* Copyright (C) 2007-2011 German Aerospace Center (DLR/SC)
*
* Created: 2010-08-13 Markus Litz <Markus.Litz@dlr.de>
* Changed: $Id: WingUIDDialog.h 4416 2011-02-08 21:03:40Z litz_ma $ 
*
* Version: $Revision: 4416 $
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
#pragma once

#include "afxwin.h"

class CTIGLViewerDoc;
namespace tigl { class CCPACSConfiguration; }

// CWingDialog-Dialogfeld
class CWingUIDDialog : public CDialog
{
public:

    CWingUIDDialog(CTIGLViewerDoc& document);
	virtual ~CWingUIDDialog();
	virtual BOOL OnInitDialog();
    int GetWingIndex(void) const;
	std::string GetWingUID(void) const;

	enum { IDD = IDD_WING_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV-Unterst�tzung
	virtual void OnOK();

private:
	CTIGLViewerDoc& m_document;
	CListBox        m_wingList;
    int             index;
	std::string		wingUID;		

	DECLARE_DYNAMIC(CWingUIDDialog)
	DECLARE_MESSAGE_MAP()
};
