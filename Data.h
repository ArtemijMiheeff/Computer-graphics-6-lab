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
#include "Data.h"
#include "Mesh.h"
#include "Light.h"
#include "camera.h"

extern Camera camera;
extern Light light;

extern vector <GraphicObject> graphicObjects;

extern vector<std::shared_ptr<PhongMaterial>> materials;
extern int passabilityMap[21][21];
extern vector <std::shared_ptr<Mesh>> all_meshes;
extern GraphicObject plane;

extern std::shared_ptr<GameObject> map_object[21][21];

extern GraphicObject plane;
extern GraphicObject Box;
extern GraphicObject ChamferBox;
extern GraphicObject BorderBox;

void initData();