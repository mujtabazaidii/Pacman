#include"graphics.h"
#include<iostream>
using namespace std;
class pacman
{
	int cc, kl, ll, g, w, s, gg[10000], kk[10000], k, h, r, xx[30], zz, score, life, fin[2];
public:
	pacman() {
		g = 330;
		w = 40;
		h = 0;
		r = 18;
		for (int i = 0; i < 30; i++)
			xx[i] = 0;
		for (int i = 0; i < 2; i++)
			fin[i] = 0;
		zz = 0;
		cc = 2;
		score = 0;
		life = 3;
	}
	bool pmovement(int& x, int& y)
	{
		s = 10;
		if (GetAsyncKeyState(VK_RIGHT)) {
			x = x + s;
			g = 330;
			w = 40;
			return true;
		}
		else if (GetAsyncKeyState(VK_LEFT)) {
			x = x - s;
			g = 140;
			w = 210;
			return true;
		}
		else if (GetAsyncKeyState(VK_UP)) {
			y = y - s;
			g = 60;
			w = 130;
			return true;
		}
		else if (GetAsyncKeyState(VK_DOWN)) {
			y = y + s;
			g = 240;
			w = 310;
			return true;
		}
		else
			return false;
		kl = x; ll = y;
	}
	void show(int k, int v) {
		setcolor(YELLOW);
		setfillstyle(SOLID_FILL, YELLOW);
		circle(k, v, r);
		floodfill(k, v, YELLOW);
		if (cc % 2 == 0) {
			setcolor(BLACK);
			setfillstyle(SOLID_FILL, BLACK);
			pieslice(k, v, g, w, 22);
		}
		delay(15);
		cc = cc + 1;
	}
	int rget() {
		return r;
	}
	int llget() {
		return ll;
	}
	void normal() {
		if (r == 22)
			r = r - 4;
	}
	void fruitC(int q, int ww, int u) {
		int m;
		m = 520;
		if (m == 520 && u < 980) {
			if (q + 18 >= u - 5 && ww >= m - 20 && ww <= m + 20 && q <= u + 20) {
				gg[h] = u; kk[h] = m;
				if (xx[22] < 21) {
					score = score + 10;
					xx[22] = xx[22] + 1;
				}
				h = h + 1;
			}
		}
		m = 440;
		if (m == 440 && u < 980) {
			if (q + 18 >= u - 5 && ww >= m - 20 && ww <= m + 20 && q <= u + 20) {
				gg[h] = u; kk[h] = m;
				if (xx[20] < 21) {
					score = score + 10;
					xx[20] = xx[20] + 1;
				}
				h = h + 1;
			}
		}
		m = 400;
		if (m == 400 && u < 980) {
			if (q + 18 >= u - 5 && ww >= m - 20 && ww <= m + 20 && q <= u + 20) {
				gg[h] = u; kk[h] = m;
				if (xx[23] < 21) {
					score = score + 10;
					xx[23] = xx[23] + 1;
				}
				h = h + 1;
			}
		}
		m = 170;
		if (m == 170) {
			if (q + 18 >= u - 5 && ww >= m - 20 && ww <= m + 20 && q <= u + 20) {
				gg[h] = u; kk[h] = m;
				if (xx[24] <= 21) {
					score = score + 10;
					xx[24] = xx[24] + 1;
				}
				h = h + 1;
			}
		}
		m = 90;
		if (m == 90 && u < 570 && u < 980) {
			if (q + 18 >= u - 5 && ww >= m - 20 && ww <= m + 20 && q <= u + 20) {
				gg[h] = u; kk[h] = m;
				if (xx[25] < 7) {
					score = score + 10;
					xx[25] = xx[25] + 1;
				}
				h = h + 1;
			}
		}
		m = 90;
		if (m == 90 && u > 680 && u < 930 && u < 980) {
			if (q + 18 >= u - 5 && ww >= m - 20 && ww <= m + 20 && q <= u + 20) {
				gg[h] = u; kk[h] = m;
				if (xx[26] < 7) {
					score = score + 10;
					xx[26] = xx[26] + 1;
				}
				h = h + 1;
			}
		}


	}
	void energeizer(int q, int ww, int u) {
		int m;
		m = 240;
		if (m == 240 && u == 550 + 10) {

			if (q + 18 >= u - 5 && ww >= m - 20 && ww <= m + 20 && q <= u + 20) {
				gg[h] = u; kk[h] = m;
				h = h + 1;
				if (xx[27] == 0) {
					score = score + 100;
					life = life + 1;
					xx[27] = xx[27] + 1;
				}
			}
		}
		m = 40;
		if (u == 350 && m == 40) {
			if (q + 18 >= u - 5 && ww >= m - 20 && ww <= m + 20 && q <= u + 20) {
				gg[h] = u; kk[h] = m;
				h = h + 1;
				if (xx[28] == 0) {
					s = s + 7;
					r = r + 4;
					score = score + 60;
					xx[28] = xx[28] + 1;
				}
			}
		}


	}
	void fruit(int x, int y) {
		int jk = 0;
		bool b = true;
		int m = 30;
		int u = 350;
		while (u < 980) {
			if (u < 980) {
				m = 520;
				for (int z = 0; z < h; z++) {
					if (u == gg[z] && m == kk[z]) {
						b = false;
						break;
					}
					else {
						b = true;
					}
				}
				if (b == true) {
					jk = jk + 1;
					setcolor(3);
					setfillstyle(SOLID_FILL, 3);
					circle(u, m, 5);
					floodfill(u, m, 3);
				}
			}
			b = true;
			if (u < 980) {
				m = 440;
				for (int z = 0; z < h; z++) {
					if (u == gg[z] && m == kk[z]) {
						b = false;
						break;
					}
					else {
						b = true;
					}
				}
				if (b == true) {
					jk = jk + 1;
					setcolor(3);
					setfillstyle(SOLID_FILL, 3);
					circle(u, m, 5);
					floodfill(u, m, 3);
				}
			}
			b = true;
			if (u < 980) {
				m = 400;
				for (int z = 0; z < h; z++) {
					if (u == gg[z] && m == kk[z]) {
						b = false;
						break;
					}
					else {
						b = true;
					}
				}
				if (b == true) {
					jk = jk + 1;
					setcolor(3);
					setfillstyle(SOLID_FILL, 3);
					circle(u, m, 5);
					floodfill(u, m, 3);
				}
			}
			b = true;
			if (u < 980) {
				m = 170;
				for (int z = 0; z < h; z++) {
					if (u == gg[z] && m == kk[z]) {
						b = false;
						break;
					}
					else {
						b = true;
					}
				}
				if (b == true) {
					jk = jk + 1;
					setcolor(3);
					setfillstyle(SOLID_FILL, 3);
					circle(u, m, 5);
					floodfill(u, m, 3);
				}
			}
			b = true;
			if (u < 570 && u < 980) {
				m = 90;
				for (int z = 0; z < h; z++) {
					if (u == gg[z] && m == kk[z]) {
						b = false;
						break;
					}
					else {
						b = true;
					}
				}
				if (b == true) {
					jk = jk + 1;
					setcolor(3);
					setfillstyle(SOLID_FILL, 3);
					circle(u, m, 5);
					floodfill(u, m, 3);
				}
			}
			b = true;
			if (u > 680 && u < 930) {
				m = 90;
				for (int z = 0; z < h; z++) {
					if (u == gg[z] && m == kk[z]) {
						b = false;
						break;
					}
					else {
						b = true;
					}
				}
				if (b == true) {
					jk = jk + 1;
					setcolor(3);
					setfillstyle(SOLID_FILL, 3);
					circle(u, m, 5);
					floodfill(u, m, 3);
				}
			}
			b = true;
			if (u == 550 + 10) {
				m = 240;
				for (int z = 0; z < h; z++) {
					if (u == gg[z] && m == kk[z]) {
						b = false;
						break;
					}
					else {
						b = true;
					}
				}
				if (b == true) {
					jk = jk + 1;
					setcolor(4);
					setfillstyle(SOLID_FILL, 4);
					circle(u, m, 7);
					floodfill(u, m, 4);
				}
			}
			b = true;
			if (u == 350) {
				m = 40;
				for (int z = 0; z < h; z++) {
					if (u == gg[z] && m == kk[z]) {
						b = false;
						break;
					}
					else {
						b = true;
					}
				}
				if (b == true) {
					jk = jk + 1;
					setcolor(5);
					setfillstyle(SOLID_FILL, 5);
					circle(u, m, 7);
					floodfill(u, m, 5);
				}
			}
			u = u + 30;
		}
		if (jk == 0) {
			fin[0] = 1;
		}
	}
	void checkl(int l) {
		if (l == 0) {
			fin[1] = 1;
		}
	}
	void update(int l) {
		life = l;
	}
	int Clife() {
		return life;
	}
	bool gfinish(int l) {
		checkl(l);
		if (fin[0] == 1) {
			cout << "\nCongratulation you win the game : YOUR SCORE IS : " << score << endl;
			return true;
		}
		else if (fin[1] == 1) {
			cout << "\nTRY AGAIN :\n Your score is : " << score << endl;
			return true;
		}
		else
			return false;
	}
};
class enemy : virtual public pacman {
	int o, p, k, c, zx, lifel;
public:
	enemy() {
		k = -4;
		c = 0;
		zx = 7;
	}
	void  eshape(int g, int gg, int oo)
	{
		o = g; p = gg;
		setcolor(oo);
		setfillstyle(SOLID_FILL, oo);
		arc(o, p, 0, 180, 20);
		line(o - 19, p, o - 19, p + 20);
		line(o + 18, p, o + 18, p + 20);
		int temp, y = p + 20, c = p + 16, k = o - 19, i = p;
		for (int i = p - 19; i <= p + 13; i = i + 4) {
			line(k, y, k + 4, c);
			temp = y;
			y = c;
			c = temp;
			k = k + 4;
		}
		floodfill(o, p, oo);
		setcolor(WHITE);
		setfillstyle(SOLID_FILL, WHITE);
		circle(o - 10, p, 5);
		circle(o + 9, p, 5);
		floodfill(o - 10, p, WHITE);
		floodfill(o + 9, p, WHITE);
		setcolor(BLACK);
		circle(o - 10, p, 2);
		circle(o + 9, p, 2);
		circle(o - 10, p, 1);
		circle(o + 9, p, 1);
	}

	void e1movement(int& gg, int& g) {
		if (g == 55) {
			for (int h = 0; h < 8; h++) {
				if (gg > 640) {
					gg--;
				}
			}
			if (gg == 640)
				g--;
		}
		else if (gg == 640) {
			for (int h = 0; h < 8; h++) {
				if (g <= 180) {
					g++;
				}
			}
			if (g == 181)
				gg++;
		}
		else if (g == 181) {
			for (int h = 0; h < 8; h++) {
				if (gg <= 950) {
					gg++;
				}
			}
			if (gg == 951)
				g++;
		}
		else if (gg == 951) {
			for (int h = 0; h < 8; h++) {
				if (g < 386) {
					g++;
				}
			}
			if (g == 386)
				gg--;
		}
		else if (g == 386) {
			for (int h = 0; h < 8; h++) {
				if (gg >= 710) {
					gg--;
				}
			}
			if (gg == 709)
				g--;
		}
		else  if (gg == 709) {
			for (int h = 0; h < 8; h++) {
				if (g >= 200) {
					g--;
				}
			}
			if (g == 199) {
				gg++;
			}
		}
		else if (gg == 710) {
			for (int h = 0; h < 8; h++) {
				if (g <= 445) {
					g++;
				}
			}
			if (g == 446)
				gg++;
		}
		else if (g == 446) {
			for (int h = 0; h < 8; h++) {
				if (gg >= 305) {
					gg--;
				}
			}
			if (gg == 304)
				g--;
		}
		else if (gg == 304) {
			for (int h = 0; h < 8; h++) {
				if (g >= 150) {
					g--;
				}
			}
			if (g == 149)
				gg++;
		}
		else if (g == 149) {
			for (int h = 0; h < 8; h++) {
				if (gg <= 645) {
					gg++;
				}
			}
			if (gg == 646)
				g--;
		}
		else if (gg == 646) {
			for (int h = 0; h < 8; h++) {
				if (g >= 53) {
					g--;
				}
			}
			if (g == 52)
				gg--;
		}
		else if (g == 52) {
			for (int h = 0; h < 8; h++) {
				if (gg <= 964) {
					g++;
				}
			}
			if (gg == 965)
				g++;
		}
		else if (gg == 965) {
			if (g <= 54)
				g++;
		}

	}
	int oget() {
		return o;
	}
	void e2movement(int& gg, int& g, int u[20][20000], int dd, int& as) {
		if (gg == 310 && k == -4) {
			for (int h = 0; h < 8; h++) {
				if (g < 530) {
					g++;
				}
			}
			if (g == 530)
				k = k + 4;
		}
		if (k >= 0) {
			if (as == 12) {
				gg = u[k][c]; g = u[k][c + 1];
				c = c + 2;
			}
			else if (c >= 0) {
				gg = u[k][c]; g = u[k][c + 1];
				c = c - 2;
				if (c == 0) {
					k = k + 1;
					as = 12;
				}
			}
		}

	}
	bool cpe(int& h, int& y, int& u, int& v, int r, int ss, int& aa) {
		lifel = Clife();
		bool z = false;
		if (r == 18) {
			if (h + 18 >= u - 20 && y >= v - 20 && y <= v + 20 && h <= u + 20 || h + 18 >= u - 20 && y + 20 >= v - 20 && y - 20 <= v + 20 && h <= u + 20) {
				h = 310;
				y = 530;
				aa = 0;
				lifel = lifel - 1;
				z = true;
				return true;
			}
		}
		else if (r != 18) {
			if (h + 18 >= u - 20 && y >= v - 20 && y <= v + 20 && h - 18 <= u + 20 || h + 18 >= u - 20 && y + 20 >= v - 20 && y - 20 <= v + 20 && h - 18 <= u + 20) {
				if (ss == 5) {
					u = 310;
					v = 55;
					c = 0;
					k = -4;
					r = 18;
					return false;
				}
				else {
					u = 965;
					v = 55;
					r = 18;
					return false;
				}
			}
		}
		if (z == false) {
			return false;
		}
	}
	int getlife() {
		return lifel;
	}
};
class grid :virtual public pacman, virtual public enemy
{
	int x, y, g, h, mm, nn, aa, qq[20][20000], as, dd, ttime;
	bool tt, uu, kk, jdd;
public:
	grid() {
		x = 310;
		ttime = 0;
		y = 530;
		g = 965;
		h = 55;
		mm = 310;
		nn = 55;
		aa = 0;
		dd = 0;
		as = 12;
		tt = false;
		kk = false;
		uu = false;
		jdd = false;
	}
	void mgrid()
	{
		initwindow(1300, 600);
		int j = 0;
		int page = 0;
		for (int i = 0; j < 300; i++)
		{
			setactivepage(page);
			setvisualpage(1 - page);
			cleardevice();
			e2movement(mm, nn, qq, aa, as);
			kk = cpe(x, y, mm, nn, rget(), 5, aa);
			int l = getlife();
			update(l);
			jdd = gfinish(l);
			if (jdd == true)
				j = 300;
			eshape(mm, nn, 1);
			e1movement(g, h);
			uu = cpe(x, y, g, h, rget(), 10, aa);
			l = getlife();
			update(l);
			jdd = gfinish(l);
			if (jdd == true)
				j = 300;
			if (uu == true) {
				as = 86;
				dd = dd + 1;
				uu = false;
			}
			if (kk == true) {
				as = 86;
				dd = dd + 1;
				kk = false;
			}
			eshape(g, h, 4);
			cgrid(x, y, rget());
			if (tt == true) {
				qq[dd][aa] = x; qq[dd][aa + 1] = y;
				aa = aa + 2;
				tt = false;
			}
			show(x, y);
			fruit(x, y);
			tt = pmovement(x, y);
			int u = 350;
			while (u < 980) {
				fruitC(x, y, u);
				energeizer(x, y, u);
				u = u + 30;
			}
			setfillstyle(SOLID_FILL, BLUE);
			setcolor(BLUE);
			rectangle(280, 30, 990, 560);
			rectangle(265, 15, 1005, 575);
			floodfill(266, 16, BLUE);
			setfillstyle(SOLID_FILL, LIGHTGRAY);
			floodfill(260, 16, BLUE);
			line(620, 30, 620, 130);
			line(600, 30, 600, 130);
			line(600, 130, 620, 130);
			rectangle(350, 100, 550, 120);
			rectangle(690, 100, 910, 120);
			rectangle(580, 200, 680, 378);
			rectangle(590, 215, 670, 363);
			rectangle(350, 230, 520, 280);
			rectangle(740, 230, 910, 280);
			rectangle(350, 260, 520, 350);
			rectangle(740, 260, 910, 350);
			rectangle(350, 410, 520, 420);
			rectangle(740, 410, 910, 420);
			rectangle(450, 478, 820, 498);
			setfillstyle(SOLID_FILL, WHITE);
			floodfill(351, 261, BLUE);
			floodfill(741, 261, BLUE);
			setfillstyle(SOLID_FILL, BLUE);
			floodfill(581, 201, BLUE);
			delay(40);
			page = 1 - page;
		}

	}
	void cgrid(int& f, int& b, int rr) {
		if (x - rr <= 280) {
			while (x - rr < 281) {
				x++;
			}
		}
		if (b - rr <= 30) {
			while (b - rr < 31)
				b++;
		}
		if (f + rr >= 990) {
			while (f + rr > 989)
				f--;
		}
		if (b + rr >= 560) {
			while (b + rr > 559)
				b--;
		}

		if (f - rr <= 620 && f - rr >= 610) {
			if (b - rr >= 30 && b - rr <= 130) {
				while (f - rr < 621)
					f++;
			}
		}
		if (f + rr >= 600 && f + rr <= 609) {
			if (b + rr >= 30 && b - rr <= 130) {
				while (f + rr > 599)
					f--;
			}
		}
		if (y - rr <= 130 && y - rr >= 120) {
			if (x + rr >= 600 && x - rr <= 620) {
				while (y - rr < 131)
					y++;
			}
		}
		if (x - rr <= 550 && x - rr >= 540) {
			if (y + rr >= 100 && y - rr <= 120) {
				while (x - rr < 551)
					x++;
			}
		}
		else if (b - rr <= 120 && b - rr >= 111) {
			if (x + rr >= 350 && x - rr <= 550) {
				while (b - rr < 121)
					b++;
			}
		}
		else if (b + rr >= 100 && b + rr <= 110) {
			if (f + rr >= 350 && f - rr <= 550) {
				while (b + rr > 99)
					b--;
			}
		}
		else if (x + rr >= 350 && x + rr <= 370) {
			if (y + rr >= 100 && y - rr <= 120) {
				while (x + rr > 351)
					x--;
			}
		}
		if (x - rr <= 910 && x - rr >= 890) {
			if (y + rr >= 100 && y - rr <= 120) {
				while (x - rr < 909)
					x++;
			}
		}
		else if (b - rr <= 120 && b - rr >= 111) {
			if (x + rr >= 690 && x - rr <= 910) {
				while (b - rr < 121)
					b++;
			}
		}
		else if (b + rr >= 100 && b + rr <= 110) {
			if (f + rr >= 690 && f - rr <= 910) {
				while (b + rr > 99)
					b--;
			}
		}
		else if (x + rr >= 690 && x + rr <= 700) {
			if (y + rr >= 100 && y - rr <= 120) {
				while (x + rr > 689)
					x--;
			}
		}
		if (x - rr <= 680 && x - rr >= 670) {
			if (y + rr >= 200 && y - rr <= 378) {
				while (x - rr < 681)
					x++;
			}
		}
		else if (b - rr <= 378 && b - rr >= 360) {
			if (x + rr >= 580 && x - rr <= 680) {
				while (b - rr < 379)
					b++;
			}
		}
		else if (b + rr >= 200 && b + rr <= 220) {
			if (f + rr >= 580 && f - rr <= 680) {
				while (b + rr > 201)
					b--;
			}
		}
		else if (x + rr >= 580 && x + rr <= 590) {
			if (y + rr >= 200 && y - rr <= 378) {
				while (x + rr > 579)
					x--;
			}
		}
		if (x - rr <= 520 && x - rr >= 510) {
			if (y + rr >= 230 && y - rr <= 350) {
				while (x - rr < 521)
					x++;
			}
		}
		else if (b - rr <= 350 && b - rr >= 340) {
			if (x + rr >= 350 && x - rr <= 520) {
				while (b - rr < 351)
					b++;
			}
		}
		else if (b + rr >= 230 && b + rr <= 240) {
			if (f + rr >= 350 && f - rr <= 520) {
				while (b + rr > 229)
					b--;
			}
		}
		else if (x + rr >= 350 && x + rr <= 360) {
			if (y + rr >= 230 && y - rr <= 350) {
				while (x + rr > 349)
					x--;
			}
		}
		if (x - rr <= 910 && x - rr >= 900) {
			if (y + rr >= 230 && y - rr <= 350) {
				while (x - rr < 911)
					x++;
			}
		}
		else if (b - rr <= 350 && b - rr >= 340) {
			if (x + rr >= 740 && x - rr <= 910) {
				while (b - rr < 351)
					b++;
			}
		}
		else if (b + rr >= 230 && b + rr <= 240) {
			if (f + rr >= 740 && f - rr <= 910) {
				while (b + rr > 229)
					b--;
			}
		}
		else if (x + rr >= 740 && x + rr <= 910) {
			if (y + rr >= 230 && y - rr <= 350) {
				while (x + rr > 739)
					x--;
			}
		}
		if (x - rr <= 520 && x - rr >= 510) {
			if (y + rr >= 410 && y - rr <= 420) {
				while (x - rr < 521)
					x++;
			}
		}
		else if (b - rr <= 427 && b - rr >= 414) {
			if (x + rr >= 350 && x - rr <= 520) {
				while (b - rr < 427)
					b++;
			}
		}
		else if (b + rr >= 410 && b + rr <= 420) {
			if (f + rr >= 350 && f - rr <= 520) {
				while (b + rr > 409)
					b--;
			}
		}
		else if (x + rr >= 350 && x + rr <= 360) {
			if (y + rr >= 410 && y - rr <= 420) {
				while (x + rr > 349)
					x--;
			}
		}
		if (x - rr <= 910 && x - rr >= 900) {
			if (y + rr >= 410 && y - rr <= 420) {
				while (x - rr < 911)
					x++;
			}
		}
		else if (b - rr <= 425 && b - rr >= 414) {
			if (x + rr >= 740 && x - rr <= 910) {
				while (b - rr < 427)
					b++;
			}
		}
		else if (b + rr >= 410 && b + rr <= 420) {
			if (f + rr >= 740 && f - rr <= 910) {
				while (b + rr > 409)
					b--;
			}
		}
		else if (x + rr >= 740 && x + rr <= 750) {
			if (y + rr >= 410 && y - rr <= 420) {
				while (x + rr > 739)
					x--;
			}
		}
		if (x - rr <= 820 && x - rr >= 810) {
			if (y + rr >= 478 && y - rr <= 498) {
				while (x - rr < 821)
					x++;
			}
		}
		else if (b - rr <= 498 && b - rr >= 488) {
			if (x + rr >= 450 && x - rr <= 820) {
				while (b - rr < 499)
					b++;
			}
		}
		else if (b + rr >= 478 && b + rr <= 487) {
			if (f + rr >= 450 && f - rr <= 820) {
				while (b + rr > 477)
					b--;
			}
		}
		else if (x + rr >= 450 && x + rr <= 460) {
			if (y + rr >= 478 && y - rr <= 498) {
				while (x + rr > 449)
					x--;
			}
		}

	}
};
int main()
{
	grid b;
	b.mgrid();
	Sleep(-1);
	return 0;
}