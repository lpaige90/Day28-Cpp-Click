#ifndef CLICK_H
#define CLICK_H
#include "D:/GLFW/include/GLFW/glfw3.h"

extern double mouseX, mouseY;

class Circle {
	GLfloat radius;
	GLfloat red, green, blue;
	GLfloat horiz, vert;

	void setColor();

	public:
		Circle(GLfloat rad, GLfloat r, GLfloat g, GLfloat b);

		void drawCircle(GLfloat x, GLfloat y);
		void moveCircle(double x, double y);
};

#endif
