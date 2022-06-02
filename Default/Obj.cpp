#include "stdafx.h"
#include "Obj.h"


CObj::CObj() : m_eDir(DIR_END), bDead(0), m_fAngle(0), m_fDistance(0), m_fRotSpeed(0), m_pTarget(nullptr)
{
	ZeroMemory(&m_tInfo, sizeof(INFO));
	ZeroMemory(&m_tRect, sizeof(RECT));
}


CObj::~CObj()
{
}

void CObj::Update_Rect(void)
{
	m_tRect.left = int(m_tInfo.fX - (m_tInfo.fCX * 0.5f));
	m_tRect.right = int(m_tInfo.fX + (m_tInfo.fCX * 0.5f));
	m_tRect.top = int(m_tInfo.fY - (m_tInfo.fCY * 0.5f));
	m_tRect.bottom = int(m_tInfo.fY + (m_tInfo.fCY * 0.5f));
}