#include "Data.h"


// используем пространство имен стандартной библиотеки
using namespace glm;
using namespace std;

Camera camera(vec3(0, 25, 40));

Light light(vec3(0, 5, 0));

// список графических объектов
vector <GraphicObject> graphicObjects;
vector <shared_ptr<Mesh>> all_meshes;

// используемые материалы
std::vector<std::shared_ptr<PhongMaterial>> materials;

// карта проходимости
int passabilityMap[21][21] = {
 3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,
 3,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,2,0,0,0,3,
 3,0,2,1,2,0,2,0,2,2,2,1,2,0,2,0,2,0,2,2,3,
 3,0,2,0,2,0,0,0,2,0,2,0,0,0,2,0,1,0,0,0,3,
 3,0,1,0,2,2,1,2,2,0,2,0,2,2,2,1,2,0,2,0,3,
 3,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,2,0,2,0,3,
 3,0,2,2,1,1,2,0,2,0,2,2,2,2,2,0,2,2,2,0,3,
 3,0,2,0,0,0,2,0,2,0,0,0,0,0,2,0,0,0,0,0,3,
 3,0,2,0,2,2,2,0,2,0,2,2,1,2,2,2,1,2,2,0,3,
 3,0,0,0,2,0,0,0,2,0,2,0,0,0,0,0,0,0,1,0,3,
 3,2,2,2,2,0,2,2,2,0,2,0,2,2,2,2,2,2,2,0,3,
 3,0,0,0,2,0,0,0,1,0,2,0,0,0,2,0,0,0,0,0,3,
 3,0,2,0,2,2,2,0,2,1,2,0,2,2,2,0,2,2,2,2,3,
 3,0,2,0,0,0,2,0,0,0,2,0,0,0,2,0,2,0,0,0,3,
 3,2,2,2,2,0,2,2,2,0,2,2,2,0,1,0,2,2,2,0,3,
 3,0,0,0,0,0,2,0,2,0,0,0,2,0,1,0,0,0,2,0,3,
 3,0,2,0,2,1,2,0,2,0,2,2,2,0,2,2,2,0,2,0,3,
 3,0,1,0,1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,3,
 3,0,2,1,2,0,2,2,2,2,2,0,2,0,2,0,2,2,2,2,3,
 3,0,0,0,0,0,0,0,0,0,0,0,2,0,2,0,0,0,0,0,3,
 3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3
};

//Mesh mesh_object;
//std::shared_ptr<Mesh> mesh_object;
std::shared_ptr<GameObject> map_object[21][21];

GraphicObject plane;
GraphicObject Box;
GraphicObject ChamferBox;
GraphicObject BorderBox;



void initData()
{
	light.setAmbient(vec4(1, 1, 1, 1));
	light.setDiffuse(vec4(1, 1, 1, 1));
	light.setSpecular(vec4(0.1, 0.1, 0.1, 1));




	


	// ИНИЦИАЛИЗАЦИЯ ДАННЫХ, НЕОБХОДИМЫХ ДЛЯ РАБОТЫ ПРОГРАММЫ:
	// инициализация графических объектов

	std::shared_ptr<PhongMaterial> material1 = make_shared<PhongMaterial>();
	materials.push_back(material1);
	std::shared_ptr<PhongMaterial> material2 = make_shared<PhongMaterial>();
	materials.push_back(material2);
	std::shared_ptr<PhongMaterial> material3 = make_shared<PhongMaterial>();
	materials.push_back(material3);
	std::shared_ptr<PhongMaterial> material4 = make_shared<PhongMaterial>();
	materials.push_back(material4);
	materials[0]->load("data/materials/material_1.txt");
	materials[1]->load("data/materials/material_2.txt");
	materials[2]->load("data/materials/material_3.txt");
	materials[3]->load("data/materials/material_4.txt");


	all_meshes.push_back(make_shared<Mesh>());
	all_meshes[0]->load("SimplePlane.obj");
	all_meshes.push_back(make_shared<Mesh>());
	all_meshes[1]->load("Box.obj");
	all_meshes.push_back(make_shared<Mesh>());
	all_meshes[2]->load("ChamferBox.obj");
	//Загрузка сферы для 7 лабы (ниже)
	//all_meshes.push_back(make_shared<Mesh>());
	//all_meshes[3]->load("Sphere.obj");

	plane.setPosition(vec3(0, 0, 0));
	plane.setMaterial(materials[0]);
	plane.setMesh(all_meshes[0]);

	Box.setMaterial(materials[2]);
	Box.setMesh(all_meshes[1]);

	ChamferBox.setMaterial(materials[1]);
	ChamferBox.setMesh(all_meshes[2]);

	BorderBox.setMaterial(materials[3]);
	BorderBox.setMesh(all_meshes[1]);

	//GraphicObject tempGraphicObject;
	//// 1 -----------------------------------------
	//tempGraphicObject.setPosition(vec3(5, 0, 0));
	//tempGraphicObject.setAngle(180);
	//tempGraphicObject.setСolor(vec3(1, 0, 0));
	//tempGraphicObject.setMaterial(materials[0]);
	//graphicObjects.push_back(tempGraphicObject);
	//// 2 -----------------------------------------
	//tempGraphicObject.setPosition(vec3(-5, 0, 0));
	//tempGraphicObject.setAngle(0);
	//tempGraphicObject.setСolor(vec3(0, 1, 0));
	//tempGraphicObject.setMaterial(materials[1]);
	//graphicObjects.push_back(tempGraphicObject);
	//// 3 -----------------------------------------
	//tempGraphicObject.setPosition(vec3(0, 0, 5));
	//tempGraphicObject.setAngle(90);
	//tempGraphicObject.setСolor(vec3(0, 0, 1));
	//tempGraphicObject.setMaterial(materials[2]);
	//graphicObjects.push_back(tempGraphicObject);
	//// 4 -----------------------------------------
	//tempGraphicObject.setPosition(vec3(0, 0, -5));
	//tempGraphicObject.setAngle(-90);
	//tempGraphicObject.setСolor(vec3(0, 1, 1));
	//tempGraphicObject.setMaterial(materials[3]);
	//graphicObjects.push_back(tempGraphicObject);

	for (int i=0; i<21;i++)
	{
		for (int j = 0; j < 21; j++)
		{
			switch (passabilityMap[i][j])
			{
			case 0:
			{
				map_object[i][j] = nullptr;
				break; 
			}
			case 1:
			{
				map_object[i][j] = make_shared<GameObject>();
				map_object[i][j]->setGraphicObject(ChamferBox);
				map_object[i][j]->setPosition(i - 10, j - 10);
				break;
			}
			case 2:
			{
				map_object[i][j] = make_shared<GameObject>();
				map_object[i][j]->setGraphicObject(Box);
				map_object[i][j]->setPosition(i - 10, j - 10);
				break;
			}
			case 3:
			{
				map_object[i][j] = make_shared<GameObject>();
				map_object[i][j]->setGraphicObject(BorderBox);
				map_object[i][j]->setPosition(i - 10, j - 10);
				break;
			}
			}
		}
	}


};