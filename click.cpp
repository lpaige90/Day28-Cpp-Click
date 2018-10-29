#include "click.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <iostream>

double mouseX;
double mouseY;

Circle::Circle(GLfloat rad, GLfloat r, GLfloat g, GLfloat b) {
	radius = rad;
	red = r;
	green = g;
	blue = b;
	horiz = 0.0f;
	vert = 0.0f;
}

void Circle::setColor() {
	glColor3f(red, green, blue);
}

void Circle::drawCircle(GLfloat x, GLfloat y) {
	glBegin(GL_POLYGON);
	this->setColor();
	for (int i = 0; i < 360; ++i) {
		float degToRad = i * (3.14159 / 180.0);
		glVertex2f(cos(degToRad) * this->radius + x, sin(degToRad) * this->radius + y);
	}
	glEnd();
}

void Circle::moveCircle(double x, double y) {
	horiz = (GLfloat)x;
	vert = (GLfloat)y;
	this->drawCircle(horiz, vert);
}