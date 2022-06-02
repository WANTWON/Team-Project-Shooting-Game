#include "stdafx.h"
#include "Shield.h"


CShield::CShield() : Temp(GetTickCount())
{
}


CShield::~CShield()
{
}


void CShield::Initialize(void)
{
	m_tInfo.fCX = 5.f;
	m_tInfo.fCY = 5.f;
	m_fRotSpeed = 7.f;
	
}

int CShield::Update(void)
{
	m_fDistance = m_pTarget->Get_Info().fCX;


	if (bDead)
		return OBJ_DEAD;

	m_tInfo.fX = float(m_pTarget->Get_Info().fX) + float(cosf(RADIAN*m_fAngle)*m_fDistance);
	m_tInfo.fY = float(m_pTarget->Get_Info().fY) - float(sinf(RADIAN*m_fAngle)*m_fDistance);

	m_fAngle += m_fRotSpeed;
		

	Update_Rect();

	return OBJ_NOEVENT;
}
void CShield::Late_Update(void)
{
	if (Temp + 10000 < GetTickCount())
	{
		bDead = true;
	}
}
void CShield::Release(void)
{

}
void CShield::Render(HDC hDC)
{

	Ellipse(hDC, m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.bottom);

}