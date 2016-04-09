#if !defined(AFX_STDAFX_H__B36C365D_F0EA_4545_B3BC_1E0EAB3B5E43__INCLUDED_)
#define AFX_STDAFX_H__B36C365D_F0EA_4545_B3BC_1E0EAB3B5E43__INCLUDED_

//#include "GlobalValue.h"
//#include "CommonDef.h"

#include <stdio.h>
#include <assert.h>
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#define WIN32_LEAN_AND_MEAN		// Exclude rarely-used stuff from Windows headers

// Windows Header Files:
#include <windows.h>

#include "System/SystemGlobalEnvironment.h"

#define SAFE_DELETE(p) if(p){delete p; p = NULL;}

#include <assert.h>


#endif