#pragma once
#include "Bullet.h"

class ScrewBullet : public CBullet
{
public:
	ScrewBullet();
	~ScrewBullet();

public:
	 void Initialize(void);
	 int Update(void);
	 void Late_Update(void);
	 void Render(HDC hDC);
	 void Release(void);

public:
	void Set_Center(int _fX, int _fY) { m_tCenter.x = _fX; m_tCenter.y = _fY; }
	

private:
	POINT m_tCenter;
	bool	m_bStart;
	float m_fRotAngle;

};

