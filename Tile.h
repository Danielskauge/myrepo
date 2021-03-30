#pragma once
#include "GUI.h"

using namespace Graph_lib;

//De forskjellige tilstandene en Tile kan vaere i
enum class Cell { closed, open, flagged };

class Tile : public Button
{
	bool isMine = false;
	Cell state = Cell::closed;
	Point pos;

public:
	void set_label(string s) { label = s; redraw(); }
	void set_label_color(Color c) { pw->labelcolor(c.as_int()); redraw();}
	Tile(Point pos, int size, Graph_lib::Callback cb)
		:Button{pos, size, size, "", cb},
		pos{pos}
		{};

	
	Cell getState() const {return state; };
	void setState(Cell newState) { state = newState; };

	bool getIsMine(){return isMine;}
	void setIsMine(bool isMine){this->isMine = isMine;}

	Point getPos(){return pos;};

	void setAdjMines(int n);
	void open();
	void flag();
};
