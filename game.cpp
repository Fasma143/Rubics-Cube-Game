#define is_down(b) input -> buttons[b].is_down
#define pressed(b) (input -> buttons[b].is_down && input -> buttons[b].changed)
#define released(b) (!input -> buttons[b].is_down && input -> buttons[b].changed)

internal void rotate(unsigned int& a, unsigned int& b, unsigned int& c, unsigned int& d) {
	unsigned int copy_a = a;
	unsigned int copy_c = c;
	a = d;
	c = b;
	b = copy_a;
	d = copy_c;
}

internal void Rrotate(unsigned int &a, unsigned int &b, unsigned int &c, unsigned int &d) {
	unsigned int copy_a = a;
	unsigned int copy_c = c;
	a = b;
	c = d;
	d = copy_a;
	b = copy_c;
}

internal void 
simulate_cube(Input* input) {
	clear_screen(0xFF111111);
	
	if (pressed(Button_1)) {
		rotate(f1, t1, b9, d7);
		rotate(f4, t4, b6, d4);
		rotate(f7, t7, b3, d1);
		//Lface
		rotate(l2, l4, l8, l6);
		rotate(l3, l1, l7, l9);
	}
	if (pressed(Button_11)) {
		Rrotate(f1, t1, b9, d7);
		Rrotate(f4, t4, b6, d4);
		Rrotate(f7, t7, b3, d1);
		//Lface
		Rrotate(l2, l4, l8, l6);
		Rrotate(l3, l1, l7, l9);
	}

	if (pressed(Button_2)) {
		rotate(f2, t2, b8, d8);
		rotate(f5, t5, b5, d5);
		rotate(f8, t8, b2, d2);
	}
	if (pressed(Button_12)) {
		Rrotate(f2, t2, b8, d8);
		Rrotate(f5, t5, b5, d5);
		Rrotate(f8, t8, b2, d2);
	}

	if (pressed(Button_3)) {
		rotate(f3, t3, b7, d9);
		rotate(f6, t6, b4, d6);
		rotate(f9, t9, b1, d3);
		//Rface
		rotate(r1, r3, r9, r7);
		rotate(r2, r6, r8, r4);
	}
	if (pressed(Button_13)) {
		Rrotate(f3, t3, b7, d9);
		Rrotate(f6, t6, b4, d6);
		Rrotate(f9, t9, b1, d3);
		//Rface
		Rrotate(r1, r3, r9, r7);
		Rrotate(r2, r6, r8, r4);
	}

	if (pressed(Button_4)) {
		rotate(r1, t7, l9, d9);
		rotate(r4, t8, l6, d8);
		rotate(r7, t9, l3, d7);
		//Fface
		rotate(f3, f1, f7, f9);
		rotate(f2, f4, f8, f6);
	}
	if (pressed(Button_14)) {
		Rrotate(r1, t7, l9, d9);
		Rrotate(r4, t8, l6, d8);
		Rrotate(r7, t9, l3, d7);
		//Fface
		Rrotate(f3, f1, f7, f9);
		Rrotate(f2, f4, f8, f6);
	}

	if (pressed(Button_5)) {
		rotate(r2, t4, l8, d6);
		rotate(r5, t5, l5, d5);
		rotate(r8, t6, l2, d4);
	}
	if (pressed(Button_15)) {
		Rrotate(r2, t4, l8, d6);
		Rrotate(r5, t5, l5, d5);
		Rrotate(r8, t6, l2, d4);
	}

	if (pressed(Button_6)) {
		rotate(r3, t1, l7, d3);
		rotate(r6, t2, l4, d2);
		rotate(r9, t3, l1, d1);
		//Bface
		rotate(b1, b3, b9, b7);
		rotate(b2, b6, b8, b4);
	}
	if (pressed(Button_16)) {
		Rrotate(r3, t1, l7, d3);
		Rrotate(r6, t2, l4, d2);
		Rrotate(r9, t3, l1, d1);
		//Bface
		Rrotate(b1, b3, b9, b7);
		Rrotate(b2, b6, b8, b4);
	}

	if (pressed(Button_7)) {
		rotate(r7, f7, l7, b7);
		rotate(r8, f8, l8, b8);
		rotate(r9, f9, l9, b9);
		//Dface
		rotate(d9, d7, d1, d3);
		rotate(d2, d6, d8, d4);
	}
	if (pressed(Button_17)) {
		Rrotate(r7, f7, l7, b7);
		Rrotate(r8, f8, l8, b8);
		Rrotate(r9, f9, l9, b9);
		//Dface
		Rrotate(d9, d7, d1, d3);
		Rrotate(d2, d6, d8, d4);
	}

	if (pressed(Button_8)) {
		rotate(r4, f4, l4, b4);
		rotate(r5, f5, l5, b5);
		rotate(r6, f6, l6, b6);
	}
	if (pressed(Button_18)) {
		Rrotate(r4, f4, l4, b4);
		Rrotate(r5, f5, l5, b5);
		Rrotate(r6, f6, l6, b6);
	}

	if (pressed(Button_9)) {
		rotate(r1, f1, l1, b1);
		rotate(r2, f2, l2, b2);
		rotate(r3, f3, l3, b3);
		//Dface
		rotate(t9, t7, t1, t3);
		rotate(t8, t4, t2, t6);
	}
	if (pressed(Button_19)) {
		Rrotate(r1, f1, l1, b1);
		Rrotate(r2, f2, l2, b2);
		Rrotate(r3, f3, l3, b3);
		//Dface
		Rrotate(t9, t7, t1, t3);
		Rrotate(t8, t4, t2, t6);
	}
	

	if (pressed(Button_Left)) {
		rotate(r7, f7, l7, b7);
		rotate(r8, f8, l8, b8);
		rotate(r9, f9, l9, b9);
		//Dface
		rotate(d9, d7, d1, d3);
		rotate(d2, d6, d8, d4);

		rotate(r4, f4, l4, b4);
		rotate(r5, f5, l5, b5);
		rotate(r6, f6, l6, b6);

		rotate(r1, f1, l1, b1);
		rotate(r2, f2, l2, b2);
		rotate(r3, f3, l3, b3);
		//Dface
		rotate(t9, t7, t1, t3);
		rotate(t8, t4, t2, t6);
	}
	if (pressed(Button_Right)) {
		Rrotate(r7, f7, l7, b7);
		Rrotate(r8, f8, l8, b8);
		Rrotate(r9, f9, l9, b9);
		//Dface
		Rrotate(d9, d7, d1, d3);
		Rrotate(d2, d6, d8, d4);

		Rrotate(r4, f4, l4, b4);
		Rrotate(r5, f5, l5, b5);
		Rrotate(r6, f6, l6, b6);

		Rrotate(r1, f1, l1, b1);
		Rrotate(r2, f2, l2, b2);
		Rrotate(r3, f3, l3, b3);
		//Dface
		Rrotate(t9, t7, t1, t3);
		Rrotate(t8, t4, t2, t6);
	}

	if (pressed(Button_Up)) {
		rotate(f1, t1, b9, d7);
		rotate(f4, t4, b6, d4);
		rotate(f7, t7, b3, d1);
		//Lface
		rotate(l2, l4, l8, l6);
		rotate(l3, l1, l7, l9);

		rotate(f2, t2, b8, d8);
		rotate(f5, t5, b5, d5);
		rotate(f8, t8, b2, d2);

		rotate(f3, t3, b7, d9);
		rotate(f6, t6, b4, d6);
		rotate(f9, t9, b1, d3);
		//Rface
		rotate(r1, r3, r9, r7);
		rotate(r2, r6, r8, r4);

	}

	if (pressed(Button_Restart)) {
		reset_colors();
	}


	show_cube();
}