#include "stdafx.h"
#include "GuideBullet.h"


CGuideBullet::CGuideBullet() : m_pDistance(1000)
{
}


CGuideBullet::~CGuideBullet()
{
}


void CGuideBullet::Initialize(void)
{
	m_tInfo.fCX = 10.f;
	m_tInfo.fCY = 10.f;

	m_fSpeed = 5.f;
}
int  CGuideBullet::Update(void)
{
	if (bDead)
		return OBJ_DEAD;

	Compare_distance();
	Bullet_Move();
	Update_Rect();

	return OBJ_NOEVENT;
}
void CGuideBullet::Late_Update(void)
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

void CGuideBullet::Release(void)
{
}
	
void CGuideBullet::Render(HDC hDC)
{
	Ellipse(hDC, m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.bottom);
}

void CGuideBullet::Bullet_Move(void)
 {
	if (m_pTarget)
	{
		m_tInfo.fX += (m_pTarget->Get_Info().fX - m_tInfo.fX)*m_fSpeed*0.01;
		m_tInfo.fY += (m_pTarget->Get_Info().fY - m_tInfo.fY)*m_fSpeed*0.01;
	}
	else
	{
		m_tInfo.fX += float(Move_Point.x*0.2);
		m_tInfo.fY += float(Move_Point.y*0.2);
	}
	
}

void CGuideBullet::Compare_distance()
{
	CObj* Temp = nullptr;
	for (auto& iter = m_pMonster_List->begin(); iter != m_pMonster_List->end(); ++iter)
	{
		if (m_pDistance >= sqrt(pow(2, ((*iter)->Get_Info().fX - m_tInfo.fX)) + pow(2, ((*iter)->Get_Info().fY - m_tInfo.fY))))
		{
			Set_Target(*iter);
			m_pDistance = sqrt(pow(2, ((*iter)->Get_Info().fX - m_tInfo.fX)) + pow(2, ((*iter)->Get_Info().fY - m_tInfo.fY)));
			
		}

	}

}