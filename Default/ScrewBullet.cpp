#include "stdafx.h"
#include "ScrewBullet.h"


ScrewBullet::ScrewBullet() : m_bStart(false), m_fRotAngle(0)
{
}


ScrewBullet::~ScrewBullet()
{
}

void ScrewBullet::Initialize(void)
{
	m_tInfo.fCX = 10.f;
	m_tInfo.fCY = 10.f;
	m_fRotSpeed = 30.f;
	m_fRotAngle = 0;
	m_fSpeed = 5.f;
	m_fDistance = 30.f;
}

int ScrewBullet::Update(void)
{
	if (bDead)
		return OBJ_DEAD;


	if (!m_bStart)
	{
		m_tInfo.fX = (m_tCenter.x);
		m_tInfo.fY = (m_tCenter.y);
		m_bStart = true;
	}

	m_tCenter.x += float(cosf(RADIAN* m_fAngle) * m_fSpeed);
	m_tCenter.y += float(sinf(RADIAN* m_fAngle) * m_fSpeed);

	m_fRotAngle += m_fRotSpeed;

	m_tInfo.fX = m_tCenter.x + cosf(RADIAN* m_fRotAngle)*m_fDistance;
	m_tInfo.fY = m_tCenter.y - sinf(RADIAN* m_fRotAngle)*m_fDistance;

	Update_Rect();

	return OBJ_NOEVENT;
 }
void ScrewBullet::Late_Update(void)
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
void ScrewBullet::Render(HDC hDC)
{
	Ellipse(hDC, m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.bottom);
 }
void ScrewBullet::Release(void)
{

 }
