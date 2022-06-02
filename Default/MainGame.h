#pragma once
#include "Define.h"
#include "Player.h"
#include "Bullet.h"
#include "Monster.h"
#include "Mouse.h"
#include "Wall.h"

class CMainGame
{
public:
	CMainGame();
	~CMainGame();

public:
	void Initialize(void);
	void Update(void);
	void Late_Update(void);
	void Release(void);
	void Render(void);

private:
	HDC m_hDc;
	
	
	
	DWORD  m_dwTime;
	int  m_iFPS;
	TCHAR m_tszFPS[32];

	int m_iScore;

};

