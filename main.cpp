#include "Simple_window.h"
#include "Emoji.h"

// Size of window and emoji radius
constexpr int xmax = 1000;
constexpr int ymax = 600;
constexpr int emojiRadius = 50;

int main()
{
	using namespace Graph_lib;

	const Point tl{ 100, 100 };
	const string win_label{ "Emoji factory" };
	Simple_window win{ tl, xmax, ymax, win_label };
	Point c = { 100	, 100 }; Point mouth = { 100,100 }; Point leftEye = { 75, 85 }; Point rightEye = { 125, 85 }; int eyeRadius = 6;

	/*
	SmilingFace smiling(c, emojiRadius, mouth, 50, 65, 215, 325, leftEye, rightEye);
	poutingFace pouting(c, emojiRadius, { 115, 90 }, 140, 65, 270, 280, Point{ 92, 80 }, Point{ 132, 80 });
	*/
	ColorFace color(c, emojiRadius, mouth, 50, 65, 200, 340, leftEye, rightEye, Color::dark_red, Color::red);
	NeutralFace neutral(c, emojiRadius, leftEye, rightEye, eyeRadius, Point{ 80, 120 }, Point{ 120, 120 });
	AngryFace angry(c, emojiRadius, leftEye, rightEye, eyeRadius, Point{ 80, 120 }, Point{ 120, 120 }, Point{ 72,65 }, Point{ 92,75 }, Point{ 108, 75 }, Point{ 128,65 });
	SmilingFace smiling(c, emojiRadius, mouth, 50, 65, 215, 325, leftEye, rightEye);
	poutingFace pouting(Point{ 240,100 }, emojiRadius, { 235, 110 }, 140, 65, 270, 280, Point{ 212, 100 }, Point{ 252, 100 });
	poutingFace pouting2(Point{ 360,100 }, emojiRadius, { 355, 90 }, 140, 65, 270, 280, Point{ 332, 80 }, Point{ 372, 80 });
	/*
	smiling.attach_to(win);
	pouting.attach_to(win);
	pouting2.attach_to(win);*/

	//color.attach_to(win);
	//neutral.attach_to(win);
	angry.attach_to(win);


	win.wait_for_button();
}
