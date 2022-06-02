#pragma once
#include "Obj.h"
class CWall :
	public CObj
{
public:
	CWall();
	virtual ~CWall();

public:
	void Initialize(void)  override;
	int Update(void) override;
	void Late_Update(void) override;
	void Release(void) override;
	void Render(HDC hDC) override;
};

