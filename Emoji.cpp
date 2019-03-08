#include "Emoji.h"


Face::Face(Point c, int r) : O(c,r)	{	//Yellow circle
	O.set_fill_color(Color::yellow);
}

void Face::attach_to(Graph_lib::Window& win) {
	win.attach(O);
}

EmptyFace::EmptyFace(Point c, int r, Point leftPoint = { 85, 92 }, Point rightPoint = { 115, 92 }, Color leftColor = Color::black, Color rightColor = Color::black,  int leftRadius = 7, int rightRadius = 7)
	: Face( c,r ), leftEye(leftPoint, leftRadius), rightEye(rightPoint, rightRadius) {
	leftEye.set_fill_color(leftColor);
	rightEye.set_fill_color(rightColor);
}

void EmptyFace::attach_to(Graph_lib::Window& win) {
	Face::attach_to(win);
	win.attach(leftEye);
	win.attach(rightEye);
}

SmilingFace::SmilingFace(Point c = { 100,100 }, int r = 60, Point mouth = { 100, 100 }, int mouthWidth = 50, int mouthHeight = 65, int start_degree = 210, int end_degree = 330, Point leftEyePoint = { 79, 85 }, Point rightEyePoint = { 123, 85 })
	: EmptyFace(c, r, leftEyePoint, rightEyePoint), mouth(mouth, mouthWidth, mouthHeight, start_degree, end_degree) {};

void SmilingFace::attach_to(Graph_lib::Window& win) {
	EmptyFace::attach_to(win);
	win.attach(mouth);
};

poutingFace::poutingFace(Point c = { 100,100 }, int r = 60, Point mouth = { 100, 100 }, int mouthWidth = 50, int mouthHeight = 65, int start_degree = 200, int end_degree = 340, Point leftEyePoint = { 75, 85 }, Point rightEyePoint = { 125, 85 })
	: EmptyFace(c, r, leftEyePoint, rightEyePoint, Color::black, Color::black, 8,8), mouth(mouth, mouthWidth, mouthHeight, start_degree, end_degree) {};

void poutingFace::attach_to(Graph_lib::Window& win) {
	EmptyFace::attach_to(win);
	win.attach(mouth);
};

ColorFace::ColorFace(Point c = { 100,100 }, int r = 60, Point mouth = { 100, 100 }, int mouthWidth = 50, int mouthHeight = 65, int start_degree = 210, int end_degree = 330, Point leftEyePoint = { 79, 85 }, Point rightEyePoint = { 123, 85 }, Color leftCol = Color::red, Color rightCol = Color::green)
	: EmptyFace(c, r, leftEyePoint, rightEyePoint, leftCol, rightCol, 8, 8), mouth(mouth, mouthWidth, mouthHeight, start_degree, end_degree) {};

void ColorFace::attach_to(Graph_lib::Window& win) {
	EmptyFace::attach_to(win);
	win.attach(mouth);
};

NeutralFace::NeutralFace(Point c, int r, Point leftEye, Point rightEye, int eyeRadius, Point mouthStart, Point mouthEnd)
	: EmptyFace(c, r, leftEye, rightEye, eyeRadius), mouth(mouthStart, mouthEnd) {};

void NeutralFace::attach_to(Graph_lib::Window& win) {
	EmptyFace::attach_to(win);
	win.attach(mouth);
};

AngryFace::AngryFace(Point c, int r, Point leftEye, Point rightEye, int eyeRadius, Point mouthStart, Point mouthEnd, Point leftStartEB, Point leftEndEB, Point rightStartEB, Point rightEndEB) 
	: NeutralFace(c, r, leftEye, rightEye, eyeRadius, mouthStart, mouthEnd), leftEyeBrow(leftStartEB, leftEndEB), rightEyeBrow(rightStartEB, rightEndEB) {};

void AngryFace::attach_to(Graph_lib::Window& win) {
	NeutralFace::attach_to(win);
	win.attach(leftEyeBrow);
	win.attach(rightEyeBrow);
}