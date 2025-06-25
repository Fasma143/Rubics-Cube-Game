internal void;

unsigned int r = 0xFFE10600;
unsigned int b = 0xFF0000FF;
unsigned int g = 0xFF00FF00;
unsigned int y = 0xFFFFFF00;
unsigned int w = 0xFFFFFFFF;
unsigned int o = 0xFFFFB500;

void reset_colors() {
	f1 = f2 = f3 = f4 = f5 = f6 = f7 = f8 = f9 = w;
	b1 = b2 = b3 = b4 = b5 = b6 = b7 = b8 = b9 = y;
	l1 = l2 = l3 = l4 = l5 = l6 = l7 = l8 = l9 = g;
	r1 = r2 = r3 = r4 = r5 = r6 = r7 = r8 = r9 = b;
	t1 = t2 = t3 = t4 = t5 = t6 = t7 = t8 = t9 = o;
	d1 = d2 = d3 = d4 = d5 = d6 = d7 = d8 = d9 = r;
}
void render_background() {
	unsigned int* pixel = (unsigned int*)render_state.memory;
	for (int y = 0; y < render_state.height; ++y) {
		for (int x = 0; x < render_state.width; ++x) {
			*pixel++ = 0xff5500;
		}
	}
}

void clear_screen(unsigned int color) {
	unsigned int* pixel = (unsigned int*)render_state.memory;
	for (int y = 0; y < render_state.height; ++y) {
		for (int x = 0; x < render_state.width; ++x) {
			*pixel++ = color;
		}
	}
}


void draw_rect(int x0, int y0, int x1, int y1, unsigned int color) {

	x0 = clamp(0, x0, render_state.width - 1);
	y0 = clamp(0, y0, render_state.height - 1);
	x1 = clamp(0, x1, render_state.width - 1);
	y1 = clamp(0, y1, render_state.height - 1);


	for (int y = y0; y < y1; ++y) {
		unsigned int* pixel = (unsigned int*)render_state.memory;
		pixel += y * render_state.width; 
		pixel += x0; 
		
		for (int x = x0; x < x1; ++x) {
			*pixel++ = color;
		}
	}
}
void draw_rhomb(int x0, int y0, int x1, int y1, unsigned int color) {
	for (int y = y0; y < y1; ++y) {
		unsigned int* pixel = (unsigned int*)render_state.memory;
		pixel += y * render_state.width;
		pixel += x0;
		for (int x = x0; x < x1; ++x) {
			pixel += render_state.width;
			
			*pixel++ = color;
		}
	}
}

void draw_rhomb2(int x0, int y0, int x1, int y1, unsigned int color) {
	for (int y = y0; y < y1; ++y) {
		unsigned int* pixel = (unsigned int*)render_state.memory;
		pixel += y * render_state.width;
		pixel += x0;

		for (int x = x0; x < x1; ++x) {
			*pixel++ = color;
		}
		x0++;
		x1++;
	}
}

void show_cube() {
	int center_x = render_state.width / 2 +25;
	int center_y = render_state.height / 2 +50;

	//left side
	draw_rhomb(center_x, center_y - 50, center_x + 25, center_y, r1);
	draw_rhomb(center_x, center_y - 100, center_x + 25, center_y - 50, r4);
	draw_rhomb(center_x, center_y - 150, center_x + 25, center_y - 100, r7);

	draw_rhomb(center_x + 25, center_y - 25, center_x + 50, center_y + 25, r2);
	draw_rhomb(center_x + 25, center_y - 75, center_x + 50, center_y - 25, r5);
	draw_rhomb(center_x + 25, center_y - 125, center_x + 50, center_y - 75, r8);

	draw_rhomb(center_x + 50, center_y, center_x + 75, center_y + 50, r3);
	draw_rhomb(center_x + 50, center_y - 50, center_x + 75, center_y, r6);
	draw_rhomb(center_x + 50, center_y - 100, center_x + 75, center_y - 50, r9);


	//front side
	draw_rect(center_x - 50, center_y - 50, center_x, center_y, f3);
	draw_rect(center_x - 50, center_y - 100, center_x, center_y - 50, f6);
	draw_rect(center_x - 50, center_y - 150, center_x, center_y - 100, f9);

	draw_rect(center_x - 100, center_y - 50, center_x - 50, center_y + 0, f2);
	draw_rect(center_x - 100, center_y - 100, center_x - 50, center_y - 50, f5);
	draw_rect(center_x - 100, center_y - 150, center_x - 50, center_y - 100, f8);

	draw_rect(center_x - 150, center_y - 50, center_x - 100, center_y + 0, f1);
	draw_rect(center_x - 150, center_y - 100, center_x - 100, center_y - 50, f4);
	draw_rect(center_x - 150, center_y - 150, center_x - 100, center_y - 100, f7);


	//top side
	draw_rhomb2(center_x - 50, center_y, center_x, center_y + 25, t9);
	draw_rhomb2(center_x - 25, center_y + 25, center_x + 25, center_y + 50, t6);
	draw_rhomb2(center_x, center_y + 50, center_x + 50, center_y + 75, t3);

	draw_rhomb2(center_x - 100, center_y, center_x - 50, center_y + 25, t8);
	draw_rhomb2(center_x - 75, center_y + 25, center_x - 25, center_y + 50, t5);
	draw_rhomb2(center_x - 50, center_y + 50, center_x, center_y + 75, t2);

	draw_rhomb2(center_x - 150, center_y, center_x - 100, center_y + 25, t7);
	draw_rhomb2(center_x - 125, center_y + 25, center_x - 75, center_y + 50, t4);
	draw_rhomb2(center_x - 100, center_y + 50, center_x - 50, center_y + 75, t1);



	//Invisible cube

	//left side
	draw_rhomb(0, 0, 15, 30, l9);
	draw_rhomb(0, 30, 15, 60, l6);
	draw_rhomb(0, 60, 15, 90, l3);

	draw_rhomb(15, 15, 30, 45, l8);
	draw_rhomb(15, 45, 30, 75, l5);
	draw_rhomb(15, 75, 30, 105, l2);

	draw_rhomb(30, 30, 45, 60, l7);
	draw_rhomb(30, 60, 45, 90, l4);
	draw_rhomb(30, 90, 45, 120, l1);


	//back side
	draw_rect(45, 45, 75, 75, b9);
	draw_rect(45, 75, 75, 105, b6);
	draw_rect(45, 105, 75, 135, b3);

	draw_rect(75, 45, 105, 75, b8);
	draw_rect(75, 75, 105, 105, b5);
	draw_rect(75, 105, 105, 135, b2);

	draw_rect(105, 45, 135, 75, b7);
	draw_rect(105, 75, 135, 105, b4);
	draw_rect(105, 105, 135, 135, b1);


	//down side
	draw_rhomb2(0, 0, 30, 15, d7);
	draw_rhomb2(30, 0, 60, 15, d8);
	draw_rhomb2(60, 0, 90, 15, d9);

	draw_rhomb2(15, 15, 45, 30, d4);
	draw_rhomb2(45, 15, 75, 30, d5);
	draw_rhomb2(75, 15, 105, 30, d6);

	draw_rhomb2(30, 30, 60, 45, d1);
	draw_rhomb2(60, 30, 90, 45, d2);
	draw_rhomb2(90, 30, 120, 45, d3);
}