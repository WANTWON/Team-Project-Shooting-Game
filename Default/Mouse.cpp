#include "stdafx.h"
#include "Mouse.h"


CMouse::CMouse()
{
}


CMouse::~CMouse()
{
	Release();
}


void CMouse::Initialize(void)
{
	m_tInfo.fCX = 30.f;
	m_tInfo.fCY = 30.f;
}
int CMouse::Update(void)
{
	POINT pt = {}; //���콺 Ŀ���� ��ġ�� �޾ƿ� x��ǥ, y��ǥ

	GetCursorPos(&pt); //���콺 Ŀ���� ��ġ�� �˾ƿ��� �Լ�
					   //���� �� ���´� Window ����� â�� �������� ��ǥ�� ��ȯ�ϱ� ������ ������ â�� �������� ��ǥ�� ��ȯ�ϰ� �ؾ���

	ScreenToClient(g_hWnd, &pt); //������ ��ũ�� â�� �������� ��ǥ�� ��ȯ��.

	m_tInfo.fX = (float)pt.x;
	m_tInfo.fY = (float)pt.y;

	Update_Rect();

	ShowCursor(FALSE); //���콺 Ŀ�� ���̰� �ϱ� ����
	return OBJ_NOEVENT;
}
void CMouse::Late_Update(void)
{

}
void CMouse::Release(void)
{

}
void CMouse::Render(HDC hDC)
{
	
	Rectangle(hDC, m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.bottom);

}