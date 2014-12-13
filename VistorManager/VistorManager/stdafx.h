// stdafx.h : 标准系统包含文件的包含文件，
// 或是经常使用但不常更改的
// 特定于项目的包含文件
//

#pragma once

#include "targetver.h"

#define WIN32_LEAN_AND_MEAN             //  从 Windows 头文件中排除极少使用的信息
// Windows 头文件:
#include <windows.h>

// C 运行时头文件
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>

#include <objbase.h>
#include <zmouse.h>
#include "../DuiLib/DuiLib/UIlib.h"
using namespace DuiLib;

#ifdef _DEBUG
#   ifdef _UNICODE
#       pragma comment(lib, "../DuiLib/lib/DuiLib_ud.lib")
#   else
#       pragma comment(lib, "../DuiLib/lib/DuiLib_ud.lib")
#   endif
#else
#   ifdef _UNICODE
#       pragma comment(lib, "../DuiLib/lib/DuiLib_u.lib")
#   else
#       pragma comment(lib, "../DuiLib/lib/DuiLib_u.lib")
#   endif
#endif
// TODO: 在此处引用程序需要的其他头文件
