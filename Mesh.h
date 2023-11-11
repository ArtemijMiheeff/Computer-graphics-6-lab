#pragma once

#include <windows.h>
#include <iostream>
#include <memory>
#include <fstream>
#include <string>
#include <GL/gl.h>
#include <GL/glu.h>
#include "GL/freeglut.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp> 
#include <vector>
#include <sstream>  

// ���������� ������������ ���� ����������� ����������
using namespace glm;
using namespace std;

// ����� ��� ������ C �����
class Mesh
{
public:
	// �����������
	Mesh();
	// �������� ���� �� ����� � ��������� ������
	void load(std::string filename);
	// ����� ���� (�������� ���� ������ � OpenGL)
	void draw();
private:
	struct Vertex
	{
		// �������������� ����������
		GLfloat coord[3];
		// ������ �������
		GLfloat normal[3];
		// ���������� ���������� �������� ����������� ����� 
		GLfloat texCoord[2];
	};

	// ������ ������ ������������� �����
	vector<Vertex> vertices;
	vec3 getVec3(string);
	ivec3* getPolygon(string);
};

// ���������, ����������� ���� ������� ������������� ����� 
// ������ ������� ����� �������������� ����������, 
// ������ ������� � ���������� ����������
