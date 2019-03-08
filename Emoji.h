#pragma once

// Include Graph_lib library files that holds declarations needed for Window,
// and Shape derivatives.
#include "Graph.h"
#include "GUI.h"


using namespace Graph_lib;

// An abstract class. Concrete classes derived from this base class
// has to implement the member function attach_to().
class Emoji {
public:
	// Disable copying. Disable slicing, etc.
	Emoji(const Emoji&) = delete;
	Emoji& operator=(const Emoji&) = delete;

	// Deleting the copy constructor also deletes the default constructor.
	// Emoji needs a default constructor.
	Emoji() {}
	// Emoji() = default; // is an alternative way of achieving the same.

	// The pure virtual function that has to be overriden for a deriving class
	// to be instantiable. Every class deriving from Emoji is supposed to
	// attach all its Shapes to a window. This makes the class abstract.
	virtual void attach_to(Graph_lib::Window&) = 0;

	// Relevant because Vector_ref can own Emojis and automatically cleans up.
	// Subject will be visited later in the course.
	virtual ~Emoji() {}
};

class Face : public Emoji {
	Circle O;
public:
	Face(Point c, int r);
	virtual void attach_to(Graph_lib::Window& win) override = 0;	// Pure virtual
};

class EmptyFace : public Face {
	Circle leftEye, rightEye;
public:
	EmptyFace(Point c, int r, Point leftPoint, Point rightPoint, Color leftColor, Color rightColor, int leftRadius, int rightRadius);
	void attach_to(Graph_lib::Window& win) override;
};

class SmilingFace : public EmptyFace {
	Arc mouth;
public:
	SmilingFace(Point c, int r, Point mouth, int mouthWidth, int mouthHeight, int start_degree, int end_degree, Point leftEyePoint, Point rightEyePoint);
	void attach_to(Graph_lib::Window& win) override;
};

class poutingFace : public EmptyFace {
	Arc mouth;
public:
	poutingFace(Point c, int r, Point mouth, int mouthWidth, int mouthHeight, int start_degree, int end_degree, Point leftEyePoint, Point rightEyePoint);
	void attach_to(Graph_lib::Window& win) override;
};

class ColorFace : public EmptyFace {
	Arc mouth;
public:
	ColorFace(Point c, int r, Point mouth, int mouthWidth, int mouthHeight, int start_degree, int end_degree, Point leftEyePoint, Point rightEyePoint, Color leftCol, Color rightCol);
	void attach_to(Graph_lib::Window& win) override;
};

class NeutralFace : public EmptyFace {
	Line mouth;
public:
	NeutralFace(Point c, int r, Point leftEye, Point rightEye, int eyeRadius, Point mouthStart, Point mouthEnd);
	void attach_to(Graph_lib::Window& win);
};

class AngryFace : public NeutralFace {
	Line leftEyeBrow;
	Line rightEyeBrow;
public:
	AngryFace(Point c, int r, Point leftEye, Point rightEye, int eyeRadius, Point mouthStart, Point mouthEnd, Point leftStartEB, Point leftEndEB, Point rightStartEB, Point rightEndEB);
	void attach_to(Graph_lib::Window& win);
};