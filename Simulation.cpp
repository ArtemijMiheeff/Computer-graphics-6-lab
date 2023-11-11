#include "Simulation.h"
#include "Data.h"


int counter = 1;
int counter1 = 0;

float r = 1;
float g = 0.5;
float b = 0.5;


vector<vec3> color{ vec3(0.0, 0.0, 0.0), vec3(0.0, 0.0, 1.0), vec3(1.0, 0.0, 0.0), vec3(1.0, 1.0, 0.0), vec3(0.5, 0.0, 1.0) };

void simulation()
{
	if (GetAsyncKeyState(VK_LEFT))
	{
		camera.rotateLeftRight(-0.1);
	};
	if (GetAsyncKeyState(VK_RIGHT))
	{
		camera.rotateLeftRight(0.1);
	};
	if (GetAsyncKeyState(VK_UP))
	{
		camera.rotateUpDown(0.1);
	};
	if (GetAsyncKeyState(VK_DOWN))
	{
		camera.rotateUpDown(-0.1);
	};
	if (GetAsyncKeyState(VK_SPACE))
	{
		camera.zoomInOut(0.1);
	};
	if (GetAsyncKeyState(VK_SHIFT))
	{
		camera.zoomInOut(-0.1);
	};


	counter1++;
	if (counter1 == 50) {
		switch (counter)
		{
		case 1:
			r = color[0][0];
			g = color[0][1];
			b = color[0][2];
			counter++;
			counter1 = 0;
			break;
		case 2:
			r = color[1][0];
			g = color[1][1];
			b = color[1][2];
			counter++;
			counter1 = 0;
			break;
		case 3:
			r = color[2][0];
			g = color[2][1];
			b = color[2][2];
			counter = 1;
			counter1 = 0;
			break;
		}
	}
	//counter1 = 0;
	// устанавливаем признак того, что окно нуждается в перерисовке
	glutPostRedisplay();
	// эта же функция будет вызвана еще раз через 20 мс
	//glutTimerFunc(20, simulation, 0);
};