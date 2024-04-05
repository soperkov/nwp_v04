#include <windows.h>
#include <string>

namespace vsite::nwp {

class application
{
public:
	int run();
};

class window
{
	HWND hw{ 0 };

protected:
	virtual std::string class_name();
	bool register_class(const std::string& name);
	std::string generate_class_name();

public:
	bool create(HWND parent, DWORD style, LPCTSTR caption = 0, int IdOrMenu = 0,
		int x = CW_USEDEFAULT, int y = CW_USEDEFAULT, int width = CW_USEDEFAULT, int height = CW_USEDEFAULT);

	operator HWND();
	static LRESULT CALLBACK proc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam/*, UINT_PTR tid*/);

//	messages
protected:
	virtual int on_create(CREATESTRUCT*) { return 0; }
	virtual void on_command(int) { }
	virtual void on_destroy() { }
	//virtual void on_timer(HWND hw, UINT_PTR id) { }

	virtual void on_key_down(int key) { }
	virtual void on_key_up(int key) { }
	virtual void on_left_button_down(POINT p) { }
};

} // namespace
