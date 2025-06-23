#include <windows.h>
#include "utilis.cpp"

global_variable bool running = true;

struct RenderState {
	int width;
	int height;
	void* memory;
	BITMAPINFO bitmap_info;
};
RenderState render_state;

unsigned int f1, f2, f3, f4, f5, f6, f7, f8, f9;
unsigned int b1, b2, b3, b4, b5, b6, b7, b8, b9;
unsigned int l1, l2, l3, l4, l5, l6, l7, l8, l9;
unsigned int r1, r2, r3, r4, r5, r6, r7, r8, r9;
unsigned int t1, t2, t3, t4, t5, t6, t7, t8, t9;
unsigned int d1, d2, d3, d4, d5, d6, d7, d8, d9;

#include "renderer.cpp"
#include "platform_common.cpp"
#include "game.cpp"

LRESULT CALLBACK window_callback(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
	LRESULT result = 0;
	switch (uMsg) {
		case WM_CLOSE:{
			if (MessageBox(hwnd, 
				L"Are you really giving up? \nIf you are a pussy click OK \nOhterwise a real one, will press that cancel button ",
				L"Rubics Cube Game", MB_OKCANCEL) == IDOK) 
			{
				DestroyWindow(hwnd);
			}
		}

		case WM_DESTROY: {
			PostQuitMessage(0);
			running = false;
		} break;

		case WM_PAINT: {
		}

		case WM_SIZE: {
			RECT rect;
			GetClientRect(hwnd, &rect);
			// Get the width and height of the client area
			render_state.width = rect.right - rect.left;
			render_state.height = rect.bottom - rect.top;

			int size = render_state.width * render_state.height * (sizeof(unsigned int));

			if (render_state.memory)  VirtualFree(render_state.memory, 0, MEM_RELEASE);

			render_state.memory = VirtualAlloc(0, size, MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE);

			render_state.bitmap_info.bmiHeader.biSize = sizeof(render_state.bitmap_info.bmiHeader);

			render_state.bitmap_info.bmiHeader.biWidth = render_state.width;
			render_state.bitmap_info.bmiHeader.biHeight = render_state.height;
			render_state.bitmap_info.bmiHeader.biPlanes = 1;
			render_state.bitmap_info.bmiHeader.biBitCount = 32; // 32 bits per pixel
			render_state.bitmap_info.bmiHeader.biCompression = BI_RGB; // no compression

		}

		default: {
			result = DefWindowProc(hwnd, uMsg, wParam, lParam);
		}
		   return result;
	}
	return 0;
}

int WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd) {
	WNDCLASS window_class = {};
	window_class.style = CS_HREDRAW | CS_VREDRAW;
	window_class.hInstance = hInstance;
	window_class.lpszClassName = L"Game Window Class";
	window_class.lpfnWndProc = window_callback;

	RegisterClass(&window_class);

	HWND window = CreateWindow(window_class.lpszClassName, L"RUBIKS CUBE GAME!",
		WS_OVERLAPPEDWINDOW | WS_VISIBLE | WS_SYSMENU ,
		CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, 0, 0, hInstance, 0);
	HDC hdc = GetDC(window);

	Input input = {};

	reset_colors();

	while (running) {
		//input
		MSG message;

		for (int i = 0; i < Button_Count; i++) {
			input.buttons[i].changed = false;
		}

		while (PeekMessage(&message, window, 0, 0, PM_REMOVE)) {
			switch (message.message) {
				case WM_KEYUP:
				case WM_KEYDOWN: {
					u32 vk_code = (u32)message.wParam;
					bool is_down = ((message.lParam & (1 << 31)) == 0);

#define process_button(b, vk)\
case vk: {\
input.buttons[b].is_down = is_down;\
input.buttons[b].changed = true;\
} break;


					switch (vk_code) {
						process_button(Button_Up, VK_UP);
						process_button(Button_1, '1');
						process_button(Button_2, '2');
						process_button(Button_3, '3');
						process_button(Button_4, '4');
						process_button(Button_5, '5');
						process_button(Button_6, '6');
						process_button(Button_7, '7');
						process_button(Button_8, '8');
						process_button(Button_9, '9');

						process_button(Button_11, 'Q');
						process_button(Button_12, 'W');
						process_button(Button_13, 'E');
						process_button(Button_14, 'R');
						process_button(Button_15, 'T');
						process_button(Button_16, 'Y');
						process_button(Button_17, 'U');
						process_button(Button_18, 'I');
						process_button(Button_19, 'O');

						process_button(Button_Restart, 'C');
						process_button(Button_Left, VK_LEFT)
						process_button(Button_Right, VK_RIGHT)


					}
				} break;

				default: {
					TranslateMessage(&message);
					DispatchMessage(&message);
				}
			}
		}

		//simulate
		simulate_cube(&input);
		

		//render
		StretchDIBits(hdc, 0, 0,render_state.width, render_state.height, 0, 0, render_state.width, render_state.height, render_state.memory, &render_state.bitmap_info, DIB_RGB_COLORS, SRCCOPY);
	}
	return 0;
}