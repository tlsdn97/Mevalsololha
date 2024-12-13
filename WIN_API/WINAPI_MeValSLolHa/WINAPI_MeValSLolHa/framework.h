﻿// header.h: 표준 시스템 포함 파일
// 또는 프로젝트 특정 포함 파일이 들어 있는 포함 파일입니다.
//

#pragma once

#include "targetver.h"
#define WIN32_LEAN_AND_MEAN             // 거의 사용되지 않는 내용을 Windows 헤더에서 제외합니다.
// Windows 헤더 파일
#include <windows.h>
// C 런타임 헤더 파일입니다.
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>
#include <vector>
#include <unordered_map>
#include <memory>
#include <algorithm>
#include <string>

using namespace std;

// Math
#include "Math/Vector2.h"

using Vector2D = Vector2<float>;

#define LERP(start, end, ratio)  start + (end - start) * ratio
#define BLACK		 RGB(0,0,0)
#define WHITE		 RGB(255,255,255)
#define RED			 RGB(255,0,0)
#define GREEN		 RGB(0,255,0)

// Objects
#include "Objects/Line.h"
#include "Objects/Collider.h"
#include "Objects/CircleCollider.h"
#include "Objects/RectCollider.h"

#include "Scenes/Scene.h"

#include "Program.h"

extern Vector2D mousePos;