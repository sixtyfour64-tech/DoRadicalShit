#include "includes.h"

VOID
WINAPI
GdiPayload1(VOID)
{
	HDC hdc = GetDC(NULL);
	CONST INT w = GetSystemMetrics(SM_CXSCREEN);
	CONST INT h = GetSystemMetrics(SM_CYSCREEN);

	INT poseX = w / 2;
	INT poseY = h / 2;

	INT dx = 4, dy = 3;
	INT nCircleRadius = 30;

	DOUBLE dAngle = 0.0;
	DOUBLE dRadius = 0.0;
	CONST DOUBLE dAngleStep = 0.15;
	CONST DOUBLE dRadiusStep = 0.5;

	for (;;)
	{
		hdc = GetDC(NULL);
		dAngle += dAngleStep;
		dRadius += dRadiusStep;

		INT nSpiralX = (INT)(dRadius * cos(dAngle));
		INT nSpiralY = (INT)(dRadius * sin(dAngle));

		poseX += dx + nSpiralX / 20;
		poseY += dy + nSpiralY / 20;

		if (poseX - nCircleRadius < 0 || poseX + nCircleRadius > w)
		{
			dx = -dx;
		}

		if (poseY - nCircleRadius < 0 || poseY + nCircleRadius > h)
		{
			dy = -dy;
		}

		HBRUSH hColor = CreateSolidBrush(RGB(Xorshift32() % 255, Xorshift32() % 255, Xorshift32() % 255));
		HBRUSH hOldColor = (HBRUSH)SelectObject(hdc, hColor);

		Ellipse(hdc, poseX - nCircleRadius, poseY - nCircleRadius, poseX + nCircleRadius, poseY + nCircleRadius);
		SelectObject(hdc, hOldColor);
		DeleteObject(hColor);

		ReleaseDC(NULL, hdc);
		Sleep(10);
	}
}