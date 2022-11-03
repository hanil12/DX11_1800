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
#include <memory>
#include <tchar.h>
#include <math.h>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

// Type
#include "Types.h"
#include "Math/Vector2.h"

// Collider
#include "Collider/Line.h"
#include "Collider/Collider.h"
#include "Collider/CircleCollider.h"
#include "Collider/RectCollider.h"

// Object
// Bagic

// Game
#include "Object/GameObject/Bullet.h"
#include "Object/GameObject/Barrel.h"
#include "Object/GameObject/Cannon.h"

// Game.Arknoid
#include "Object/GameObject/Arkanoid/Block.h"
#include "Object/GameObject/Arkanoid/Ball.h"
#include "Object/GameObject/Arkanoid/Map.h"

// Game.Maze
#include "Object/GameObject/Maze/MazeBlock.h"
#include "Object/GameObject/Maze/MazePlayer.h"
#include "Object/GameObject/Maze/Maze.h"

// Scene
#include "Scene/Scene.h"

// Program
#include "Program/Program.h"

extern Vector2 mousePos;
extern HWND hWnd;
