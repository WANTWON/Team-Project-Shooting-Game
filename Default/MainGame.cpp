#include "stdafx.h"
#include "MainGame.h"
#include "AbstractFactory.h"
#include "CollisionMgr.h"
#include <time.h>
#include "ObjMgr.h"


CMainGame::CMainGame() : m_dwTime(GetTickCount()),m_iFPS(0), m_iScore(0) //: m_pPlayer(nullptr), m_pMonster(nullptr)
{
	ZeroMemory(m_tszFPS, sizeof(m_tszFPS));
}


CMainGame::~CMainGame()                          
{
	Release();
}

void CMainGame::Initialize(void)
{
	m_hDc = GetDC(g_hWnd);

	
	CObjMgr::Get_Instance()->Add_Object(OBJ_PLAYER, CAbstractFactory<CPlayer>::Create());
	
	

	for (int i = 0; i < 6; ++i)
	{
		CObjMgr::Get_Instance()->Add_Object(OBJ_MONSTER, CAbstractFactory<CMonster>::Create(rand() % (WINCX- 100) + 100, rand() % ( WINCY- 100) + 100));
	}


	CObjMgr::Get_Instance()->Add_Object(OBJ_WALL, CAbstractFactory<CWall>::Create(0, 0, WINCX, 50, DIR_UP));
	CObjMgr::Get_Instance()->Add_Object(OBJ_WALL, CAbstractFactory<CWall>::Create(0, WINCY - 50, WINCX, WINCY, DIR_DOWN));
	CObjMgr::Get_Instance()->Add_Object(OBJ_WALL, CAbstractFactory<CWall>::Create(WINCX - 50, 0, WINCX, WINCY, DIR_RIGHT));
	CObjMgr::Get_Instance()->Add_Object(OBJ_WALL, CAbstractFactory<CWall>::Create(0, 0, 50, WINCY, DIR_LEFT));
	
}

void CMainGame::Update(void)
{
	CObjMgr::Get_Instance()->Update();
	
}

void CMainGame::Late_Update(void)
{
	

	CObjMgr::Get_Instance()->Late_Update();

	
}

void CMainGame::Render(void)
{
	m_iFPS++; //render할 때마다 프레임수 증가
	Rectangle(m_hDc, 0, 0, WINCX, WINCY);
	CObjMgr::Get_Instance()->Render(m_hDc);

}

void CMainGame::Release(void)
{

	CObjMgr::Get_Instance()->Release();

	ReleaseDC(g_hWnd, m_hDc);

}