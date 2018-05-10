#include "Vector3D.h"
#include<iostream>
#include<string>
using namespace std;
Vector3D::Vector3D():
	x(0),
	y(0),
	z(0)
{
}
void Vector3D::SetValueOfX(int newValue)
{
	x = newValue;
}

void Vector3D::SetValueOfY(int newValue)
{
	y = newValue;
}

void Vector3D::SetValueOfZ(int newValue)
{
	z = newValue;
}

Vector3D::Vector3D(double x, double y, double z):
	x(x),
	y(y),
	z(z)
{
}
Vector3D::~Vector3D()
{
}

double Vector3D::getX() const
{
	return x;
}

double Vector3D::getY() const
{
	return y;
}

double Vector3D::getZ() const
{
	return z;
}

Vector3D Vector3D::operator+(const Vector3D & secondVector) const
{
	Vector3D vector;
	vector.x = x + secondVector.x;
	vector.y = y + secondVector.y;
	vector.z = z + secondVector.z;
	return vector;
}

Vector3D Vector3D::operator-(const Vector3D & secondVector) const
{
	Vector3D vector;
	vector.x = x - secondVector.x;
	vector.y = y - secondVector.y;
	vector.z = z - secondVector.z;
	return vector;
}

Vector3D Vector3D::operator-() const
{
	Vector3D vector;
	vector.x = -x;
	vector.y = -y;
	vector.z = -z;
	return vector;
}

Vector3D Vector3D::operator*(double number) const
{
	Vector3D vector;
	vector.x = number * x;
	vector.y = number * y;
	vector.z = number * z;
	return vector;
}
void Vector3D::addingVectors()
{
	int num_vectors;
	cin >> num_vectors;
	Vector3D* vectors_to_enter = new Vector3D[num_vectors];

	for (int i = 0; i < num_vectors; i++) {
		cin >> vectors_to_enter[i];
	}

	Vector3D res;
	for (int i = 0; i < num_vectors; i++) {
		res = res + vectors_to_enter[i];
	}

	cout << res << endl;
	delete[] vectors_to_enter;
}
void Vector3D::subtractingVectors()
{
	int num_vectors;
	cin >> num_vectors;
	Vector3D* vectors_to_enter = new Vector3D[num_vectors];

	for (int i = 0; i < num_vectors; i++) {
		cin >> vectors_to_enter[i];
	}
	Vector3D res = vectors_to_enter[0];
	for (int i = 1; i < num_vectors; i++) {
		res = res - vectors_to_enter[i];
	}
	cout << res << endl;
	delete[] vectors_to_enter;
}
void Vector3D::negatingVectors()
{
	int num_vectors;
	cin >> num_vectors;
	Vector3D* vectors_to_enter = new Vector3D[num_vectors];

	for (int i = 0; i < num_vectors; i++) {
		cin >> vectors_to_enter[i];
	}
	for (int i = 0; i < num_vectors; i++) {
		//vectors_to_enter[i] = -vectors_to_enter[i];
		if (vectors_to_enter[i].getX() != 0) {

			vectors_to_enter[i].SetValueOfX(-vectors_to_enter[i].getX());
		}
		if (vectors_to_enter[i].getY() != 0) {
			vectors_to_enter[i].SetValueOfY(-vectors_to_enter[i].getY());
		}
		if (vectors_to_enter[i].getZ() != 0) {
			vectors_to_enter[i].SetValueOfZ(-vectors_to_enter[i].getZ());
		}

	}
	for (int i = 0; i < num_vectors; i++) {
		cout << vectors_to_enter[i] << " ";
	}
	cout << endl;
}
void Vector3D::multiplicatingNumberWithVector( string op)
{
	string number = op.substr(1, op.size());
	int to_mult = stoi(number);

	int num_vectors;
	cin >> num_vectors;
	Vector3D* vectors_to_enter = new Vector3D[num_vectors];

	for (int i = 0; i < num_vectors; i++) {
		cin >> vectors_to_enter[i];
	}
	for (int i = 0; i < num_vectors; i++) {
		vectors_to_enter[i] = to_mult*vectors_to_enter[i];
	}
	for (int i = 0; i < num_vectors; i++) {
		cout << vectors_to_enter[i] << " ";
	}
	cout << endl;

	delete[] vectors_to_enter;
}
void Vector3D::multiplicatingVectorWithNumber(string op)
{
	string number = op.substr(0, op.size() - 1);
	int to_mult = stoi(number);

	int num_vectors;
	cin >> num_vectors;
	Vector3D* vectors_to_enter = new Vector3D[num_vectors];

	for (int i = 0; i < num_vectors; i++) {
		cin >> vectors_to_enter[i];
	}
	for (int i = 0; i < num_vectors; i++) {
		vectors_to_enter[i] = vectors_to_enter[i] * to_mult;
	}
	for (int i = 0; i < num_vectors; i++) {
		cout << vectors_to_enter[i] << " ";
	}
	cout << endl;

	delete[] vectors_to_enter;
}
Vector3D operator*(double number, const Vector3D & vector)
{
	Vector3D vector2;
	vector2.x = number * vector.x;
	vector2.y = number * vector.y;
	vector2.z = number * vector.z;
	return vector2;
}

std::istream & operator >> (std::istream & iStream, Vector3D & vector)
{
	char bracket1, delimeter1, delimeter2, bracket2;
	iStream >> bracket1 >> vector.x >> delimeter1 >> vector.y >> delimeter2 >> vector.z >> bracket2;
	//proverka za pravilno podavane na vektora
	if (bracket1 == '(' && bracket2 == ')' && delimeter1 == ',' && delimeter2 == ',') {
		return iStream;
	}
}

std::ostream & operator<<(std::ostream & oStream, const Vector3D & vector)
{
		oStream << "(" << vector.x << "," << vector.y << "," << vector.z << ")";
		return oStream;
}

void test()
{
	string op;
	cin >> op;
	Vector3D vec;

	if (op == "+") {
		vec.addingVectors();
	}
	else if (op == "-") {
		vec.subtractingVectors();
		
	}
	else if (op == "NEG") {
		vec.negatingVectors();
	}
	else if (op[0] == '*') {
		vec.multiplicatingNumberWithVector(op);
		
	}
	else if (op[op.size() - 1] == '*') {
		vec.multiplicatingVectorWithNumber(op);
	}
}

int main()
{
	test();
	return 0;
}



