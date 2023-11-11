#include "Mesh.h"
Mesh::Mesh() {

}
void Mesh::load(string filename) {
	// вектор для хранения геометрических координат
	vector<vec3> v;
	// вектор для хранения нормалей
	vector<vec3> n;
	// вектор для хранения текстурных координат
	vector<vec2> t;
	// вектор для хранения индексов атрибутов, для построения вершин
	vector<ivec3> fPoints;
	fstream File;
	File.open(filename);
	if (!File) {
		cout << "Error mesh file\n";
	}
	else {
		cout << "Mesh file open\n";
	}
	string line;
	while (!File.eof()) {
		getline(File, line);
		int choice = -1;
		string label = line.substr(0, 2);
		if (label == "v ") { choice = 0;}
		if (label == "vn") {choice = 1; }
		if (label == "vt") {choice = 2; }
		if (label == "f ") { choice = 3; }
		//cout << '"' << label << "' " << choice << endl;
		switch (choice)
		{
		case 0: {
			v.push_back(getVec3(line));
			break;
		}
		case 1: {
			n.push_back(getVec3(line));
			break;
		}
		case 2: {
			t.push_back(getVec3(line));
			break;
		}
		case 3: {
			ivec3* a = getPolygon(line);
			for (int i = 0; i < 3; i++) {
				fPoints.push_back(a[i]);
			}
			delete[] a;
			break;
		}
		default:
			break;
		}
	}
	for (auto point : fPoints) {
		Vertex vert;
		for (int i = 0; i < 3; i++) {
			vert.coord[i] = v[point[0]][i];
		}
		for (int i = 0; i < 2; i++) {
			vert.texCoord[i] = t[point[1]][i];
		}
		for (int i = 0; i < 3; i++) {
			vert.normal[i] = n[point[2]][i];
		}
		vertices.push_back(vert);
	}
	File.close();
}
vec3 Mesh::getVec3(string inLine) {
	string line = inLine.substr(3);
	int length = line.size();
	vec3 vec = vec3(0, 0, 0);
	float number = 0.0;
	size_t a = 0;
	size_t current_pos = 0;
	int space = line.find(' ');
	int iter = 0;
	//cout << '"' << line << '"' << endl;
	while (current_pos < length) {
		string new_line = line.substr(current_pos, space - current_pos);
		//cout << "New line: " << new_line << endl;
		vec[iter] = stof(new_line, &a);
		current_pos += a;
		//cout << vec[iter] << " " << current_pos << endl;
		iter++;
		space = line.find(' ', current_pos + 1);
		//cout << "Space: " << space << endl;
	}
	return vec;
}
ivec3* Mesh::getPolygon(string inLine) {
	string line = inLine.substr(2);
	int length = line.size();
	ivec3* vec = new ivec3[3];
	int numbers[9];
	//cout << line << endl;
	int current_pos = 0;
	int iter = 0;
	while (current_pos < length) {
		int number = 0;
		size_t a = 0;
		string new_line = line.substr(current_pos);
		number = stoi(new_line, &a);
		numbers[iter] = number - 1;
		current_pos += a + 1;
		//cout << numbers[iter] << " ";
		iter++;
	}
	for (int i = 0; i < 3; i++) {
		vec[i].x = numbers[i * 3];
		vec[i].y = numbers[i * 3 + 1];
		vec[i].z = numbers[i * 3 + 2];
	}
	//cout << endl;
	return vec;
}
void Mesh::draw() {

	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_NORMAL_ARRAY);
	glEnableClientState(GL_TEXTURE_COORD_ARRAY);

	glVertexPointer(3, GL_FLOAT, sizeof(Vertex), vertices[0].coord);
	glNormalPointer(GL_FLOAT, sizeof(Vertex), vertices[0].normal);
	glTexCoordPointer(2, GL_FLOAT, sizeof(Vertex), vertices[0].texCoord);

	glDrawArrays(GL_TRIANGLES, 0, vertices.size());

	glDisableClientState(GL_VERTEX_ARRAY);
	glDisableClientState(GL_NORMAL_ARRAY);
	glDisableClientState(GL_TEXTURE_COORD_ARRAY);
}