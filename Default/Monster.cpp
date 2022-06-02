#include "stdafx.h"
#include "Monster.h"


CMonster::CMonster()
{

}


CMonster::~CMonster()
{
	Release();
}

void CMonster::Initialize(void)
{
	m_tInfo = { 125.f,125.f, 30.f, 30.f };
	m_fSpeed = 0.f;
}
int  CMonster::Update(void)
{
	if (bDead)
		return OBJ_DEAD;

	Move();
	Update_Rect();

	return OBJ_NOEVENT;
}

void CMonster::Late_Update(void)
{
	if (m_tRect.right > WINCX - 50 || m_tRect.left < 50)
	{
		m_fSpeed *= -1.f;
		//m_eDir = DIR_RIGHT;
	}

	if (m_tRect.bottom > WINCY - 50 || m_tRect.top < 50)
	{
		m_fSpeed *= -1.f;
		//m_eDir = DIR_UP;
	}

	/*if (m_tRect.top == m_pTarget->Return_Rect().bottom
		&& fabs(m_tInfo.fX - m_pTarget->Return_Info().fX) <= fabs((m_tInfo.fCX - m_pTarget->Return_Info().fCX)*0.5f))
		bDead = true;

	else if (m_tRect.bottom == m_pTarget->Return_Rect().top
		&& fabs(m_tInfo.fX - m_pTarget->Return_Info().fX) <= fabs((m_tInfo.fCX - m_pTarget->Return_Info().fCX)*0.5f))
		bDead = true;

	else if (m_tRect.left == m_pTarget->Return_Rect().right
		&& fabs(m_tInfo.fY - m_pTarget->Return_Info().fY) <= fabs((m_tInfo.fCY - m_pTarget->Return_Info().fCY)*0.5f))
		bDead = true;

	else if (m_tRect.right == m_pTarget->Return_Rect().left
		&& fabs(m_tInfo.fY - m_pTarget->Return_Info().fY) <= fabs((m_tInfo.fCY - m_pTarget->Return_Info().fCY)*0.5f))
		bDead = true;
	else
		bDead = false;*/

	/*if( m_tRect.left < m_pTarget->Return_Rect().right &&  m_tRect.top < m_pTarget->Return_Rect().bottom 
		&& fabs(m_tInfo.fX - m_pTarget->Return_Info().fX) <= fabs((m_tInfo.fCX - m_pTarget->Return_Info().fCX)*0.5f))
		bDead = true;
	if (m_tRect.left < m_pTarget->Return_Rect().right &&  m_tRect.bottom > m_pTarget->Return_Rect().top
		&& fabs(m_tInfo.fX - m_pTarget->Return_Info().fX) <= fabs((m_tInfo.fCX - m_pTarget->Return_Info().fCX)*0.5f))
		bDead = true;
	if (m_tRect.right > m_pTarget->Return_Rect().left &&  m_tRect.top < m_pTarget->Return_Rect().bottom
		&& fabs(m_tInfo.fX - m_pTarget->Return_Info().fX) <= fabs((m_tInfo.fCX - m_pTarget->Return_Info().fCX)*0.5f))
		bDead = true;
	if (m_tRect.right > m_pTarget->Return_Rect().left &&  m_tRect.bottom > m_pTarget->Return_Rect().top
		&& fabs(m_tInfo.fX - m_pTarget->Return_Info().fX) <= fabs((m_tInfo.fCX - m_pTarget->Return_Info().fCX)*0.5f))
		bDead = true;
	else
		bDead = false;*/


}

void CMonster::Release(void)
{

}

void CMonster::Render(HDC hDC)
{
	Rectangle(hDC, m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.bottom);
}



void CMonster::Move(void)
{

	if (m_pTarget)
	{
		float Width = (m_pTarget->Get_Info().fX - m_tInfo.fX);
		float Height = (m_pTarget->Get_Info().fY - m_tInfo.fY);

		float Diagonol = sqrtf(Width*Width + Height*Height);

		m_fAngle = acosf(Width / Diagonol);


		if (m_pTarget->Get_Info().fY >= m_tInfo.fY)
			m_fAngle *= -1;

		m_tInfo.fX += cos(m_fAngle)*m_fSpeed;
		m_tInfo.fY -= sin(m_fAngle)*m_fSpeed;

		/*m_tInfo.fX += (m_pTarget->Return_Info().fX - m_tInfo.fX)*m_fSpeed;
		m_tInfo.fY += (m_pTarget->Return_Info().fY - m_tInfo.fY) *m_fSpeed;*/
	}
	else if (m_eDir == DIR_LEFT)
		m_tInfo.fX += m_fSpeed;
	else if (m_eDir == DIR_UP)
		m_tInfo.fY += m_fSpeed;

}
