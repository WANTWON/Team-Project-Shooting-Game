#include "stdafx.h"
#include "Wall.h"


CWall::CWall()
{
}


CWall::~CWall()
{
	Release();
}

void CWall::Initialize(void)
{

}
int CWall::Update(void)
{

	return OBJ_NOEVENT;
}
void CWall::Late_Update(void)
{

}
void CWall::Release(void)
{

}
void CWall::Render(HDC hDC)
{
	Rectangle(hDC, m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.bottom );
}
