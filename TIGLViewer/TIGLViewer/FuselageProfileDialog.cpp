/* 
* Copyright (C) 2007-2011 German Aerospace Center (DLR/SC)
*
* Created: 2010-08-13 Markus Litz <Markus.Litz@dlr.de>
* Changed: $Id: FuselageProfileDialog.cpp 4416 2011-02-08 21:03:40Z litz_ma $ 
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

#include "stdafx.h"
#include "TIGLViewer.h"
#include "FuselageProfileDialog.h"
#include "TIGLViewerDoc.h"
#include "CCPACSConfiguration.h"
#include "CCPACSFuselageProfile.h"


IMPLEMENT_DYNAMIC(CFuselageProfileDialog, CDialog)

BEGIN_MESSAGE_MAP(CFuselageProfileDialog, CDialog)
END_MESSAGE_MAP()

CFuselageProfileDialog::CFuselageProfileDialog(CTIGLViewerDoc& document)
	: CDialog(CFuselageProfileDialog::IDD, 0)
	, m_document(document)
{
}

CFuselageProfileDialog::~CFuselageProfileDialog()
{
}

int CFuselageProfileDialog::GetProfileIndex(void) const
{
    return m_profileIndex;
}

void CFuselageProfileDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_FUSELAGE_PROFILE_LIST, m_profileList);
}

BOOL CFuselageProfileDialog::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Initialize fuselage profile list
	tigl::CCPACSConfiguration& config = m_document.GetConfiguration();
	int profileCount = config.GetFuselageProfileCount();
	for (int i = 1; i <= profileCount; i++) 
	{
		tigl::CCPACSFuselageProfile& profile = config.GetFuselageProfile(i);
		std::string filename = profile.GetFileName();
		std::string name     = profile.GetName();
		if (name == "") name = "---";
		std::string entry    = filename + " (" + name + ")";
		m_profileList.InsertString(i - 1, _T(entry.c_str()));
	}
	return TRUE;  // return TRUE unless you set the focus to a control
}

void CFuselageProfileDialog::OnOK()
{
	UpdateData(TRUE);
	m_profileIndex = m_profileList.GetCurSel();
    CDialog::OnOK();
}
