#pragma once

#include <windows.h>
#include <iostream>
#include <memory>
#include <vector>

#include <GL/gl.h>
#include <GL/glu.h>
#include "GL/freeglut.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp> 

#include "GraphicObject.h"
#include "GameObject.h"
#include "Simulation.h"
#include "PhongMaterial.h"
#include "Display.h"

#include "Mesh.h"
#include "Light.h"
#include "camera.h"

// ����� ��� ������������� �������� �������
class GameObject
{
public:
	// �����������
	GameObject();
	// ��������� ������������� ������������ �������
	// ���������� ����������� ����������� ������� ��� ������������ �������������
	void setGraphicObject(const GraphicObject& graphicObject);
	// ��������� ���������� ��������� (��� ������������� ������ ��� ��������)
	void setPosition(int x, int y);
	void setPosition(ivec2 position);
	// ��������� ������� ���������� ���������
	ivec2 getPosition();
	// ����� �������� ������� �� �����
	void draw(void);
private:
	// ���������� ���������� �������� �������
	ivec2 position;
	// ����������� ������ (��� ������ �� �����)
	GraphicObject graphicObject;
	
};