#include "stdafx.h"
#include "Player.h"
#include "Bullet.h"
#include "Shield.h"
#include "AbstractFactory.h"
#include "ScrewBullet.h"
#include "GuideBullet.h"
#include "ObjMgr.h"


CPlayer::CPlayer() : m_pShield_Angle(0)
{
	ZeroMemory(&m_pGUIDE, sizeof(POINT));
}


CPlayer::~CPlayer()
{
	Release();
}

void CPlayer::Initialize(void)
{
	//플레이어 네모의 크기를 정하는 것
	m_tInfo = { 400.f, 300.f, 50.f, 50.f }; //x좌표, y좌표, 가로길이, 세로길이
	m_fSpeed = 0.1f;
	
}

int CPlayer::Update(void)
{
	if (bDead)
		return OBJ_DEAD;

	Key_Input();
	Bullet_Key_Input();


	m_fDistance = m_tInfo.fCX;

	
	if (m_fAngle <= 0)
		m_fAngle += 360;
	
	Update_Rect();

	m_pGUIDE.x = long(cos(RADIAN*m_fAngle)*m_fDistance);
	m_pGUIDE.y = long( sin(RADIAN*m_fAngle)*m_fDistance);

	return OBJ_NOEVENT;
}
void  CPlayer::Late_Update(void)
{
	                                                                                                                                                                                                                                                                                                           
}

void CPlayer::Release(void)
{
	
}
void CPlayer::Render(HDC hDC)
{

	Rectangle(hDC, m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.bottom);
	MoveToEx(hDC, (int)m_tInfo.fX, (int)m_tInfo.fY, nullptr);
	LineTo(hDC, int(m_tInfo.fX + m_pGUIDE.x), int(m_tInfo.fY + m_pGUIDE.y));
	
}

void CPlayer::Key_Input(void)
{

	if (GetAsyncKeyState(VK_RIGHT))
		m_fAngle += 4;

	else if (GetAsyncKeyState(VK_LEFT))
		m_fAngle -= 4;


	if (GetAsyncKeyState(VK_UP))
	{
		m_tInfo.fX += m_pGUIDE.x*m_fSpeed;
		m_tInfo.fY += m_pGUIDE.y*m_fSpeed;
	}
	else if (GetAsyncKeyState(VK_DOWN))
	{
		m_tInfo.fX -= m_pGUIDE.x*m_fSpeed;
		m_tInfo.fY -= m_pGUIDE.y*m_fSpeed;
	}

}

void CPlayer::Bullet_Key_Input(void)
{

	if (GetAsyncKeyState(VK_SPACE))
		CObjMgr::Get_Instance()->Add_Object(OBJ_BULLET, CAbstractFactory<CBullet>::Create(float(m_tInfo.fX + m_pGUIDE.x), float(m_tInfo.fY + m_pGUIDE.y), m_fAngle));

	if (GetAsyncKeyState('D'))
		CObjMgr::Get_Instance()->Add_Object(OBJ_BULLET, Create_Shield());

}

CObj* CPlayer::Create_Bullet(DIRECTION eDir)
{
	if (eDir == DIR_SCREW)
	{
		CObj* pBullet = new ScrewBullet;
		pBullet->Set_Pos(float(m_tInfo.fX + m_pGUIDE.x), float(m_tInfo.fY + m_pGUIDE.y));
		dynamic_cast<ScrewBullet*>(pBullet)->Set_Center(int(m_tInfo.fX + m_pGUIDE.x), int(m_tInfo.fY + m_pGUIDE.y));
		dynamic_cast<ScrewBullet*>(pBullet)->Set_Angle((int)m_fAngle);
		pBullet->Initialize();
		return pBullet;

	}

	else if (eDir == DIR_TEMP)
	{
		CObj* pBullet = new CBullet;

		pBullet->Set_Pos(float(m_tInfo.fX + m_pGUIDE.x), float(m_tInfo.fY + m_pGUIDE.y));
		dynamic_cast<CBullet*>(pBullet)->Set_Angle((int)m_fAngle);
		pBullet->Set_Dir(eDir);
		dynamic_cast<CBullet*>(pBullet)->Get_Direction(int(m_pGUIDE.x), int(m_pGUIDE.y));
		pBullet->Initialize();
		return pBullet;
	}

	else if (eDir == DIR_GUIDE)
	{
	
		
	}
	
}

CObj*  CPlayer::Create_Shield(void)
{
	CObj*	pSheild = CAbstractFactory<CShield>::Create();
	pSheild->Set_Target(this);
	return pSheild;
}