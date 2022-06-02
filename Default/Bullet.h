#pragma once
#include "Obj.h"
class CBullet :
	public CObj
{
public:
	CBullet();
	virtual ~CBullet();

public:
	void Initialize(void)  override;
	int Update(void) override;
	void Late_Update(void) override;
	void Release(void) override;
	void Render(HDC hDC) override;

public:
	RECT Return_Rect(void) { return m_tRect; }
	void Get_Direction(int x, int y) { Move_Point.x = x; Move_Point.y = y; }


	
protected:
	void Direction(void);
	
	POINT  Move_Point;


	


};

