#pragma once
#include "Bullet.h"
class CGuideBullet :
	public CBullet
{
public:
	CGuideBullet();
	~CGuideBullet();

public:
	void Initialize(void);
	int Update(void);
	void Late_Update(void);
	void Release(void);
	void Render(HDC hDC);

	void Bullet_Move(void);

	void Set_Center(int _fX, int _fY) { m_tCenter.x = _fX; m_tCenter.y = _fY; }
	void  Set_Monster_list(list<CObj*>*  &Temp) { m_pMonster_List = Temp; }
	void Compare_distance();
	

private:
	POINT m_tCenter;
	list<CObj*>*  m_pMonster_List;


	int m_pDistance;

	
};

