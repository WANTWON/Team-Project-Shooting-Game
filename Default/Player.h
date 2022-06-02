#pragma once
#include "Obj.h"


class CPlayer :
	public CObj
{
public:
	CPlayer();
	virtual~CPlayer();
public:
	void Initialize(void)  override;
	int Update(void) override;
	void Late_Update(void) override;
	void Release(void) override;
	void Render(HDC hDC) override;

private:
	void Key_Input(void);
	void Bullet_Key_Input(void);
	CObj* Create_Bullet(DIRECTION eDir);
	CObj* Create_Shield(void);

private:
	float m_pShield_Angle;
	
	POINT m_pGUIDE;
};

