#pragma once
#include "Function.h"
#include "Struct.h"
#include "Define.h"
#include "Enum.h"

class CObj
{
public:
	CObj();
	virtual ~CObj();

public:
	void Set_Pos(float _fX, float _fY) { m_tInfo.fX = _fX; m_tInfo.fY = _fY; }
	void Set_PosY(float _fY) { m_tInfo.fY += _fY; }
	void Set_PosX(float _fX) { m_tInfo.fX += _fX; }
	void Set_Angle(int angle) { m_fAngle = float(angle); }
	void Set_Rect(float _left, float _top, float _right, float _bottom) { m_tRect.left = int(_left); m_tRect.top = int(_top); m_tRect.right = int(_right); m_tRect.bottom = int(_bottom); }
	void Set_Dir(DIRECTION eDir) { m_eDir = eDir; }
	void Set_bDead(bool _dead) { bDead = _dead; }
	void Set_Target(CObj* temp) { m_pTarget = temp;; }
	const RECT& Return_Rect(void) const { return m_tRect; }
	const INFO& Get_Info(void) const { return m_tInfo; }
	const DIRECTION& Return_Dir(void) const { return m_eDir ;}

public:
	virtual		void	Initialize(void) PURE;
	virtual		int		Update(void)	PURE;
	virtual		void	Late_Update(void)	PURE;
	virtual		void	Render(HDC hDC) PURE;
	virtual		void	Release(void) PURE;

protected:
	void Update_Rect(void);
	
	

protected:
	INFO  m_tInfo; //x좌표, y좌표 등을 담은 구조체
	RECT  m_tRect; //m_tInfo를 기반으로 Rect의 left,top,right,bottom을 구함
	DIRECTION m_eDir;

	float m_fSpeed;
	float m_fRotSpeed;
	bool  bDead;

	float m_fAngle;
	float m_fDistance;
	CObj* m_pTarget;
};

