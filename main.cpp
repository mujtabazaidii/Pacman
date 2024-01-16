#include <iostream>
#include "mygraphics.h"
using namespace std;
class Grid
{
public:
	Grid();
	~Grid();
	void showGrid(int w, int h);
	int DrawDots(int arr[][2], int w, int h);
	void REDrawDots(int arr[][2], int size);
};
Grid::Grid()
{

}
Grid::~Grid()
{

}
void Grid::showGrid(int w, int h)
{
	drawLine(10, 10, 10, 150, 0, 0, 255);
	drawLine(10, 150, 120, 150, 0, 0, 255);
	drawLine(120, 150, 120, 200, 0, 0, 255);
	drawLine(10, 200, 120, 200, 0, 0, 255);
	drawLine(10, 250, 120, 250, 0, 0, 255);
	drawLine(120, 250, 120, 300, 0, 0, 255);
	drawLine(10, 300, 120, 300, 0, 0, 255);
	drawLine(10, 300, 10, 450, 0, 0, 255);
	drawLine(10, 10, w - 10, 10, 0, 0, 255);
	drawLine(w - 10, 10, w - 10, 150, 0, 0, 255);
	drawLine(w - 120, 150, w - 10, 150, 0, 0, 255);
	drawLine(w - 120, 150, w - 120, 200, 0, 0, 255);
	drawLine(w - 120, 200, w - 10, 200, 0, 0, 255);
	drawLine(w - 120, 250, w - 10, 250, 0, 0, 255);
	drawLine(w - 120, 250, w - 120, 300, 0, 0, 255);
	drawLine(w - 120, 300, w - 10, 300, 0, 0, 255);
	drawLine(w - 10, 300, w - 10, 450, 0, 0, 255);
	drawLine(10, 450, w - 10, 450, 0, 0, 255);

	drawRectangle(w / 2 - 25, 10, w / 2 + 25, 100, 0, 0, 255);
	drawRectangle(50, 50, 200, 100, 0, 0, 255);
	drawRectangle(250, 50, 400, 100, 0, 0, 255);

	drawRectangle(w / 2 + 75, 50, w / 2 + 225, 100, 0, 0, 255);
	drawRectangle(w / 2 + 275, 50, w / 2 + 425, 100, 0, 0, 255);
	drawRectangle(200, 150, 250, 300, 0, 0, 255);
	drawRectangle(w - 250, 150, w - 200, 300, 0, 0, 255);
	drawRectangle(w / 2 - 150, 155, w / 2 + 150, 290, 0, 0, 255);
	drawRectangle(w / 2 - 150, 155, w / 2 + 150, 290, 0, 0, 255);
	drawRectangle(w - 250, 355, w - 80, 405, 0, 0, 255);
	drawRectangle(w / 2 - 20, 355, w / 2 + 130, 405, 0, 0, 255);
	drawRectangle(200, 355, 370, 405, 0, 0, 255);
}
int Grid::DrawDots(int arr[][2], int w, int h)
{
	int row = 0;
	for (int i = 130; i < h - 80; i = i + 20)
	{
		drawLine(160, i, 160, i, 255, 211, 0);
		arr[row][1] = i;
		arr[row][0] = 160;
		row++;
	}
	for (int i = 180; i < w / 2 + 180; i = i + 20)
	{
		drawLine(i, 130, i, 130, 255, 211, 0);
		arr[row][1] = 130;
		arr[row][0] = i;
		row++;
	}
	for (int i = 130; i < h - 140; i = i + 20)
	{
		drawLine(w / 2 + 180, i, w / 2 + 180, i, 255, 211, 0);
		arr[row][1] = i;
		arr[row][0] = w / 2 + 180;
		row++;
	}
	for (int i = 180; i < w / 2 + 200; i = i + 20)
	{
		drawLine(i, h - 150, i, h - 150, 255, 211, 0);
		arr[row][1] = h - 150;
		arr[row][0] = i;
		row++;
	}
	for (int i = 150; i < h - 160; i = i + 20)
	{
		drawLine(280, i, 280, i, 255, 211, 0);
		arr[row][1] = i;
		arr[row][0] = 280;
		row++;
	}

	return row;
}
void Grid::REDrawDots(int arr[][2], int row)
{
	for (int i = 0; i < row; i++)
	{
		drawLine(arr[i][0], arr[i][1], arr[i][0], arr[i][1], 255, 211, 0);
	}
}
class PlayerRecord
{
public:
	PlayerRecord();
	~PlayerRecord();
	int score;
	int lives;
};
PlayerRecord::PlayerRecord()
{
	score = 0;
	lives = 0;
}
PlayerRecord::~PlayerRecord()
{

}
class Energizer
{
public:
	Energizer();
	~Energizer();
	void draw_energizer(int x1, int y1, int x2, int y2);
};
Energizer::Energizer()
{

}
Energizer::~Energizer()
{

}
void Energizer::draw_energizer(int x1, int y1, int x2, int y2)
{
	drawEllipse(x1, y1, x2, y2, 255, 20, 147, 255, 20, 147);
}
int main() {

	bool check = true;
	bool check2 = true;
	bool check3 = false;
	bool check4 = false;
	bool check5 = false;
	bool checkEng = false;
	bool winCheck = false;
	int dpos[200][2] = {};
	int size = 0;
	int w = 0, h = 0;
	getWindowDimensions(w, h);
	cls();
	showConsoleCursor(false);
	Grid G;
	PlayerRecord PR;
	Energizer E;
	PR.lives = 3;
	int x1 = 210, x2 = 240, y1 = 60, y2 = 90;
	int e1x1 = 140, e1x2 = 180, e1y1 = 350, e1y2 = 390;
	int e2x1 = 650, e2x2 = 690, e2y1 = 310, e2y2 = 350;
	int engx1 = 20, engx2 = 40, engy1 = 350, engy2 = 370;
	int i = 4, j = 2;
	size = G.DrawDots(dpos, w, h);
	while (1)
	{
		gotoxy(4, 26);//col,row
		cout << "Score: " << PR.score << "					Lives: " << PR.lives;
		G.REDrawDots(dpos, size);
		G.showGrid(w, h);
		E.draw_energizer(engx1, engy1, engx2, engy2);
		drawEllipse(x1, y1, x2, y2, 255, 211, 0, 255, 211, 0);
		for (int k = 0; k < size; k++)
		{
			if ((dpos[k][1] >= y1 && dpos[k][1] <= y2) && (dpos[k][0] >= x1 && dpos[k][0] <= x2))
			{
				PR.score++;
				dpos[k][1] = -1;
				dpos[k][0] = -1;
			}
		}
		if ((engy1 >= y1 && engy1 <= y2) && (engx1 >= x1 && engx1 <= x2))
		{
			engx1 = -1;
			engx2 = -1;
			engy1 = -1;
			engy2 = -1;
			checkEng = true;

		}
		if (check == true)
		{
			G.showGrid(w, h);
			drawRectangle(e1x1, e1y1, e1x2, e1y2, 255, 20, 147, 255, 20, 147);
			delay(10);
			drawRectangle(e1x1, e1y1, e1x2, e1y2, 0, 0, 0, 0, 0, 0);
			e1y1 -= j;
			e1y2 -= j;
			if (e1y1 <= 104)
			{
				check = false;
			}
			if ((y2 == e1y1 || y1 == e1y2) && (x1 >= e1x1 && x1 <= e1x2) && (checkEng == false))
			{
				PR.lives--;
				cls();
				x1 = 210, x2 = 240, y1 = 60, y2 = 90;
				if (PR.lives == 0)
				{
					break;
				}
			}
			else if ((y2 == e1y1 || y1 == e1y2) && (x1 >= e1x1 && x1 <= e1x2) && (checkEng == true))
			{
				drawRectangle(e1x1, e1y1, e1x2, e1y2, 0, 0, 0, 0, 0, 0);
				e1x1 = -1;
				e1x2 = -1;
				e1y1 = -1;
				e1y2 = -1;
				checkEng = false;
				check = NULL;
				PR.score += 10;
			}
		}
		else if (check == false)
		{

			G.showGrid(w, h);
			drawRectangle(e1x1, e1y1, e1x2, e1y2, 255, 20, 147, 255, 20, 147);
			delay(10);
			drawRectangle(e1x1, e1y1, e1x2, e1y2, 0, 0, 0, 0, 0, 0);
			e1y1 += j;
			e1y2 += j;
			if (e1y2 >= h - 70)
			{
				check = true;
			}
			if ((y2 == e1y1 || y1 == e1y2) && (x1 >= e1x1 && x1 <= e1x2) && (checkEng == false))
			{
				PR.lives--;
				cls();
				x1 = 210, x2 = 240, y1 = 60, y2 = 90;
				if (PR.lives == 0)
				{
					break;
				}
			}
			else if ((y2 == e1y1 || y1 == e1y2) && (x1 >= e1x1 && x1 <= e1x2) && (checkEng == true))
			{
				drawRectangle(e1x1, e1y1, e1x2, e1y2, 0, 0, 0, 0, 0, 0);
				check = NULL;
				checkEng = false;
				e1x1 = -1;
				e1x2 = -1;
				e1y1 = -1;
				e1y2 = -1;
				PR.score += 10;
			}
		}

		if (check2 == true)
		{
			G.showGrid(w, h);
			drawRectangle(e2x1, e2y1, e2x2, e2y2, 255, 0, 0, 255, 0, 0);
			delay(10);
			drawRectangle(e2x1, e2y1, e2x2, e2y2, 0, 0, 0, 0, 0, 0);
			e2x1 -= j;
			e2x2 -= j;
			if (e2x1 <= 275)
			{
				check2 = false;
				check3 = true;
			}
			if ((y1 >= e2y1 && y2 <= e2y2) && (x1 == e2x2 || x2 == e2x1) && (checkEng == false))
			{
				PR.lives--;
				cls();
				x1 = 210, x2 = 240, y1 = 60, y2 = 90;
				if (PR.lives == 0)
				{
					break;
				}
			}
			else if ((y1 >= e2y1 && y2 <= e2y2) && (x1 == e2x2 || x2 == e2x1) && (checkEng == true))
			{
				drawRectangle(e2x1, e2y1, e2x2, e2y2, 0, 0, 0, 0, 0, 0);
				check2 = false;
				checkEng = false;
				PR.score += 10;
			}
		}
		else if (check3 == true)
		{
			G.showGrid(w, h);
			drawRectangle(e2x1, e2y1, e2x2, e2y2, 255, 0, 0, 255, 0, 0);
			delay(10);
			drawRectangle(e2x1, e2y1, e2x2, e2y2, 0, 0, 0, 0, 0, 0);
			e2y1 -= j;
			e2y2 -= j;
			if (e2y1 <= 104)
			{
				check3 = false;
				check4 = true;
			}
			if ((y2 == e2y1 || y1 == e2y2) && (x1 >= e2x1 && x1 <= e2x2) && (checkEng == false))
			{
				PR.lives--;
				cls();
				x1 = 210, x2 = 240, y1 = 60, y2 = 90;
				if (PR.lives == 0)
				{
					break;
				}
			}
			else if ((y1 >= e2y1 && y2 <= e2y2) && (x1 == e2x2 || x2 == e2x1) && (checkEng == true))
			{
				drawRectangle(e2x1, e2y1, e2x2, e2y2, 0, 0, 0, 0, 0, 0);
				check3 = false;
				checkEng = false;
				PR.score += 10;
			}
		}
		else if (check4 == true)
		{

			G.showGrid(w, h);
			drawRectangle(e2x1, e2y1, e2x2, e2y2, 255, 0, 0, 255, 0, 0);
			delay(10);
			drawRectangle(e2x1, e2y1, e2x2, e2y2, 0, 0, 0, 0, 0, 0);
			e2x1 += j;
			e2x2 += j;
			if (e2x2 >= 690)
			{
				check5 = true;
				check4 = false;
			}
			if ((y1 >= e2y1 && y2 <= e2y2) && (x1 == e2x2 || x2 == e2x1) && (checkEng == false))
			{
				PR.lives--;
				cls();
				x1 = 210, x2 = 240, y1 = 60, y2 = 90;
				if (PR.lives == 0)
				{
					break;
				}
			}
			else if ((y1 >= e2y1 && y2 <= e2y2) && (x1 == e2x2 || x2 == e2x1) && (checkEng == true))
			{
				drawRectangle(e2x1, e2y1, e2x2, e2y2, 0, 0, 0, 0, 0, 0);
				check4 = false;
				checkEng = false;
				PR.score += 10;
			}

		}
		else if (check5 == true)
		{
			G.showGrid(w, h);
			drawRectangle(e2x1, e2y1, e2x2, e2y2, 255, 0, 0, 255, 0, 0);
			delay(10);
			drawRectangle(e2x1, e2y1, e2x2, e2y2, 0, 0, 0, 0, 0, 0);
			e2y1 += j;
			e2y2 += j;
			if (e2y2 >= 350)
			{
				check2 = true;
				check5 = false;
			}
			if ((y2 == e2y1 || y1 == e2y2) && (x1 >= e2x1 && x1 <= e2x2) && (checkEng == false))
			{
				PR.lives--;
				cls();
				x1 = 210, x2 = 240, y1 = 60, y2 = 90;
				if (PR.lives == 0)
				{
					break;
				}
			}
			else if ((y1 >= e2y1 && y2 <= e2y2) && (x1 == e2x2 || x2 == e2x1) && (checkEng == true))
			{
				drawRectangle(e2x1, e2y1, e2x2, e2y2, 0, 0, 0, 0, 0, 0);
				check5 = false;
				checkEng = false;
				PR.score += 10;
			}
		}
		if (GetAsyncKeyState(0x49))
		{
			//gotoxy(10,2);//col,row
			cls();
			y1 -= i;
			y2 -= i;
			drawEllipse(x1, y1, x2, y2, 255, 211, 0, 255, 211, 0);

		}
		if (GetAsyncKeyState(0x4B))
		{
			cls();
			//drawEllipse(x1, y1, x2, y2, 0, 0, 0, 0, 0, 0);
			y1 += i;
			y2 += i;
			drawEllipse(x1, y1, x2, y2, 255, 211, 0, 255, 211, 0);
		}
		if (GetAsyncKeyState(0x4A))
		{
			cls();
			//drawEllipse(x1, y1, x2, y2, 0, 0, 0, 0, 0, 0);
			x1 -= i;
			x2 -= i;
			drawEllipse(x1, y1, x2, y2, 255, 211, 0, 255, 211, 0);
		}
		if (GetAsyncKeyState(0x4C))
		{
			cls();
			//drawEllipse(x1, y1, x2, y2, 0, 0, 0, 0, 0, 0);
			x1 += i;
			x2 += i;
			drawEllipse(x1, y1, x2, y2, 255, 211, 0, 255, 211, 0);
		}
		for (int k = 0; k < size; k++)
		{
			if (dpos[k][1] == -1 && dpos[k][0] == -1)
			{
				winCheck = true;
			}
			else
			{
				winCheck = false;
				break;
			}
		}
		if (winCheck == true)
		{
			break;
		}
	}
	showConsoleCursor(true);
	cls();
	gotoxy(0, 0);
	cout << "Score is: " << PR.score << endl;
	cout << "Game Over!" << endl;
	system("pause");
	return 0;
}