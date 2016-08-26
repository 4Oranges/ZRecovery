// ZRecovery.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "ZRecovery.h"
#include "UI.h"
#include "WIM.h"
#include "debug.h"
#include "load_resource.h"

// Global Variables:
HINSTANCE hInst;                                // current instance

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

	hInst = hInstance;

	auto wnd = SolidWindow(load_resource<std::wstring>(hInstance, IDC_ZRECOVERY), load_resource<std::wstring>(hInstance, IDS_APP_TITLE), RECT{0, 0, 800, 600});
	wnd.create();
	
	Tab tab(wnd.getHandler());
	tab.create();

	tab.insert(L"button");
	Button btn(tab[0].getHandler(), L"Button", RECT{ 50, 50, 150, 80 });
	btn.onClick = [](auto, auto) {
		Alert("Button clicked!");
	};
	btn.create();

	tab.insert(L"textbox");
	TextBox tbx(tab[1].getHandler(), RECT{ 50, 50, 250, 70 }, L"TextBox");
	tbx.create();
	Button btn_tbx(tab[1].getHandler(), L"Test", RECT{ 50, 90, 150, 120 });
	btn_tbx.onClick = [&tbx](auto s, auto) {
		//auto tbx = dynamic_cast<TextBox*>(s);
		auto txt = tbx.getText();
		Alert(std::wstring(L"TextBox content is: [") + txt  + L"]\n Add mark...");
		tbx.setText(std::wstring(L"Mark: [") + txt + L"]");
	};
	btn_tbx.create();

	tab.insert(L"label");
	Label lab(tab[2].getHandler(), L"Label", RECT{ 50, 50, 150, 80 });
	lab.create();
	//lab.setFont(Font(30).Create());

	wnd.show(nCmdShow);

	

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_ZRECOVERY));
    MSG msg;
    while (GetMessage(&msg, nullptr, 0, 0))
    {
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }
    return (int) msg.wParam;
}
