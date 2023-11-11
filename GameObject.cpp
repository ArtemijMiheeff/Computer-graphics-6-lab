#include "GameObject.h"

GameObject::GameObject()
{
	position = ivec2(0.0, 0.0);
	graphicObject = GraphicObject();
}
void GameObject::setGraphicObject(const GraphicObject& graphicObject)
{
	this->graphicObject = graphicObject;
};
// установка логических координат (два перегруженных метода для удобства)
void GameObject::setPosition(int x, int y)
{
	position.x = x;
	position.y = y;
	graphicObject.setPosition(vec3(x, 0.5, y));
};
void GameObject::setPosition(ivec2 position)
{
	this->position = position;
};
// получение текущих логических координат
ivec2 GameObject::getPosition()
{
	return position;
};
// вывод игрового объекта на экран
void GameObject::draw(void)
{
	graphicObject.draw();
};