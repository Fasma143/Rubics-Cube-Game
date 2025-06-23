struct Button_State {
	bool is_down;
	bool changed;

};
enum Button {
	Button_Up,
	Button_Down,
	Button_Left,
	Button_Right,
	Button_Restart,
	Button_1,
	Button_2,
	Button_3,
	Button_4,
	Button_5,
	Button_6,
	Button_7,
	Button_8,
	Button_9,

	Button_11,
	Button_12,
	Button_13,
	Button_14,
	Button_15,
	Button_16,
	Button_17,
	Button_18,
	Button_19,
	// Add more buttons as needed
	Button_Count,
};


struct Input {
	Button_State buttons[Button_Count];
};