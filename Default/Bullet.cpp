#include "stdafx.h"
#include "Bullet.h"


CBullet::CBullet() 
{
	//ZeroMemory(&Move_Point, sizeof(POINT));
}


CBullet::~CBullet()
{
}

void CBullet::Initialize(void)
{
	m_tInfo.fCX = 10.f;
	m_tInfo.fCY = 10.f;

	m_fSpeed = 10.f;
}
int CBullet::Update(void)
{
	if (bDead)
		return OBJ_DEAD;
	Direction();
	Update_Rect();

	return OBJ_NOEVENT;
}
void CBullet::Late_Update(void)
{
	if (m_tRect.top <= 50
		|| m_tRect.bottom >= WINCY - 50
		|| m_tRect.left <= 50
		|| m_tRect.right >= WINCX - 50)
	{
		bDead = true;
	}
	else
		bDead = false;
}


void CBullet::Release(void)
{

}
void CBullet::Render(HDC hDC)
{
	Ellipse(hDC, m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.bottom);
}


void  CBullet::Direction(void)
{
	
	m_tInfo.fX += m_fSpeed * cos(m_fAngle*RADIAN);
	m_tInfo.fY += m_fSpeed * sin(m_fAngle*RADIAN);

	
}