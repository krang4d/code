// WinApp.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "WinApp.h"

#define MAX_LOADSTRING 100
#define TIMER_01 101
#define TIMER_02 202

// Global Variables:
HINSTANCE hInst;								// current instance
TCHAR szTitle[MAX_LOADSTRING];					// The title bar text
TCHAR szWindowClass[MAX_LOADSTRING];			// the main window class name
TCHAR szCurrentTime[40];						// массив для формирования строки - текущие дата и время

// Forward declarations of functions included in this code module:
ATOM				MyRegisterClass(HINSTANCE hInstance);
BOOL				InitInstance(HINSTANCE, int);
LRESULT CALLBACK	WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK	About(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK	LineProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK	CircleProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK	SquerProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK	LoginProc(HWND, UINT, WPARAM, LPARAM);
/*
Прототип функции получения текущего 
времени и преобразование его в символы
*/
void				OutTimeDate(HWND);


int APIENTRY _tWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPTSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);

 	// TODO: Place code here.
	MSG msg;
	HACCEL hAccelTable;

	// Initialize global strings
	LoadString(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
	LoadString(hInstance, IDC_WINAPP, szWindowClass, MAX_LOADSTRING);
	MyRegisterClass(hInstance);

	// Perform application initialization:
	if (!InitInstance (hInstance, nCmdShow))
	{
		return FALSE;
	}

	hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_WINAPP));

	// Main message loop:
	while (GetMessage(&msg, NULL, 0, 0))
	{
		if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}

	return (int) msg.wParam;
}
//
//  FUNCTION: MyRegisterClass()
//
//  PURPOSE: Registers the window class.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
	WNDCLASSEX wcex;

	wcex.cbSize = sizeof(WNDCLASSEX);

	wcex.style			= CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc	= WndProc;
	wcex.cbClsExtra		= 0;
	wcex.cbWndExtra		= 0;
	wcex.hInstance		= hInstance;
	wcex.hIcon			= LoadIcon(hInstance, MAKEINTRESOURCE(IDI_WINAPP));
	wcex.hCursor		= LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground	= (HBRUSH)(COLOR_WINDOW+1);
	wcex.lpszMenuName	= MAKEINTRESOURCE(IDC_WINAPP);
	wcex.lpszClassName	= szWindowClass;
	wcex.hIconSm		= LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

	return RegisterClassEx(&wcex);
}
//
//   FUNCTION: InitInstance(HINSTANCE, int)
//
//   PURPOSE: Saves instance handle and creates main window
//
//   COMMENTS:
//
//        In this function, we save the instance handle in a global variable and
//        create and display the main program window.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   HWND hWnd;

   hInst = hInstance; // Store instance handle in our global variable

   hWnd = CreateWindow(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, NULL, NULL, hInstance, NULL);

   if (!hWnd)
   {
      return FALSE;
   }

	
	DialogBox(hInst, MAKEINTRESOURCE(IDD_LOGIN), hWnd, LoginProc);
	//wsprintf((LPWSTR)szAsm, _T("CS=%X,DS=%X\nES=%X,SS=%X\nWinMain = %X\nszWindowClass = %X"), regCS, regDS, regES, regSS);
	//MessageBox(NULL, _T(""), _T("Регистры"), MB_ICONINFORMATION);
	// Ввод исходных данных

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}
//
//  FUNCTION: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  PURPOSE:  Processes messages for the main window.
//
//  WM_COMMAND	- process the application menu
//  WM_PAINT	- Paint the main window
//  WM_DESTROY	- post a quit message and return
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	int wmId, wmEvent;
	PAINTSTRUCT ps;
	HDC hdc;
	TCHAR szTimerID[20];

	switch (message)
	{
	case WM_CREATE:
		OutTimeDate(hWnd);									//Первый вывод текущего времени
		SetTimer(hWnd, TIMER_01, 1000, (TIMERPROC)NULL);	//функция создает системный таймер c периодом 1с
		SetTimer(hWnd, TIMER_02, 5000, (TIMERPROC)NULL);
		return TRUE;
	case WM_TIMER:
		switch (wParam)
		{
		case TIMER_01:
			OutTimeDate(hWnd);
			//MessageBox(NULL, _T("Первый таймер"), _T("wParam"), MB_ICONINFORMATION);
			break;
		case TIMER_02:
			//MessageBox(NULL, _T("Второй таймер"), _T("wParam"), MB_ICONINFORMATION);
			break;
		default:
			wsprintf((LPWSTR)szTimerID, _T("Неизвестный сигнал таймера %X"), wParam);
			MessageBox(NULL, (LPTSTR)szTimerID, _T("wParam"), MB_ICONINFORMATION);
			break;
		}
		/*
		wsprintf((LPWSTR)szTimerID, _T("%X"), wParam);
		MessageBox(NULL, (LPTSTR)szTimerID, _T("wParam"), MB_ICONINFORMATION);
		*/
		break;
	case WM_COMMAND:
		wmId    = LOWORD(wParam);
		wmEvent = HIWORD(wParam);
		// Parse the menu selections:
		switch (wmId)
		{
		case IDM_LINE:
			DialogBox(hInst, MAKEINTRESOURCE(IDD_LINE), hWnd, LineProc);
			break;
		case IDM_CIRCLE:
			DialogBox(hInst, MAKEINTRESOURCE(IDD_CIRCLE), hWnd, CircleProc);
			break;
		case IDM_SQUER:
			DialogBox(hInst, MAKEINTRESOURCE(IDD_SQUER), hWnd, SquerProc);
			break;
		case IDM_ABOUT:
			DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
			break;
		case IDM_EXIT:
			DestroyWindow(hWnd);
			break;
		default:
			return DefWindowProc(hWnd, message, wParam, lParam);
		}
		break;
	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);
		{
			// TODO: Add any drawing code here...
			//использование функций GDI
			//перо

			HPEN hNewPen = CreatePen(PS_SOLID, 3, RGB(255, 0, 0));
			HPEN hOldPen = (HPEN)SelectObject(hdc, hNewPen);

			HBRUSH hOldBrush = (HBRUSH)SelectObject(hdc, GetStockObject(GRAY_BRUSH));
		

			Circle c(Point(250, 250), 150);
			c.Draw(hdc);

			HBRUSH hNewBrush = CreateSolidBrush(RGB(255, 255, 0));
			SelectObject(hdc, hNewBrush);
			Circle c2(Point(400, 200), 50);
			c2.Draw(hdc);

			HBRUSH hNewBrush2 = CreateHatchBrush(HS_DIAGCROSS, RGB(0, 255, 0));
			SelectObject(hdc, hNewBrush2);
			Circle c3(Point(500, 150), 100);
			c3.Draw(hdc);

			Line ab(Point(100, 100), Point(200, 200));
			ab.Draw(hdc);
		
			Squer ac(Point(250, 250), Point(300, 300));
			ac.Draw(hdc);

			RECT rect = {0, 0, 200, 50};
			//LPRECT lpRect = &rect;
			//GetClientRect(hWnd, lpRect);
			SetTextColor(hdc, RGB(0, 250, 0));
			//SetBkColor(hdc, RGB(250, 0, 0));
			DrawText(hdc, szCurrentTime, -1, &rect, (DT_SINGLELINE | DT_CENTER | DT_VCENTER));
			
			SelectObject(hdc, hOldBrush);
			SelectObject(hdc, hOldPen);
			DeleteObject(hNewBrush);
			DeleteObject(hNewBrush2);
			DeleteObject(hNewPen);
		}
		EndPaint(hWnd, &ps);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}

// Message handler for about box.
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	UNREFERENCED_PARAMETER(lParam);
	switch (message)
	{
	case WM_INITDIALOG:
		return (INT_PTR)TRUE;

	case WM_COMMAND:
		if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
		{
			EndDialog(hDlg, LOWORD(wParam));
			return (INT_PTR)TRUE;
		}
		break;
	}
	return (INT_PTR)FALSE;
}

INT_PTR CALLBACK LineProc(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	int wmId, wmEvent;

	UNREFERENCED_PARAMETER(lParam);
	switch (message)
	{
	case WM_INITDIALOG:
		return (INT_PTR)TRUE;

	case WM_COMMAND:
		wmId = LOWORD(wParam);
		wmEvent = HIWORD(wParam);
		// Parse the menu selections:
		switch (wmId)
		{
		case IDOK:
			{
					 int x1 = GetDlgItemInt(hDlg, IDC_X1, 0, 0);
					 int y1 = GetDlgItemInt(hDlg, IDC_Y1, 0, 0);
					 //GetDlgItemText();
					 int x2 = GetDlgItemInt(hDlg, IDC_X2, 0, 0);
					 int y2 = GetDlgItemInt(hDlg, IDC_Y2, 0, 0);
					 Line a(Point(x1, y1), Point(x2, y2));
			}

		case IDCANCEL:
			EndDialog(hDlg, wmId);
			return (INT_PTR)TRUE;
		}
		break;
	}
	return (INT_PTR)FALSE;
}

INT_PTR CALLBACK CircleProc(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	int wmId, wmEvent;

	UNREFERENCED_PARAMETER(lParam);
	switch (message)
	{
	case WM_INITDIALOG:
		return (INT_PTR)TRUE;

	case WM_COMMAND:
		wmId = LOWORD(wParam);
		wmEvent = HIWORD(wParam);
		// Parse the menu selections:
		switch (wmId)
		{
		case IDOK:
		{
					 int x = GetDlgItemInt(hDlg, IDC_X, 0, 0);
					 int y = GetDlgItemInt(hDlg, IDC_Y, 0, 0);
					 int r = GetDlgItemInt(hDlg, IDC_RADIUS, 0, 0);
					 Circle c(Point(x,y), r);
		}
		case IDCANCEL:
			EndDialog(hDlg, wmId);
			return (INT_PTR)TRUE;
		}
		break;
	}
	return (INT_PTR)FALSE;
}

INT_PTR CALLBACK SquerProc(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	int wmId, wmEvent;
	TCHAR szText[80];

	wsprintf(szText, _T("HELLO WORLD!"));
	UNREFERENCED_PARAMETER(lParam);
	switch (message)
	{
	case WM_INITDIALOG:
		return (INT_PTR)TRUE;

	case WM_COMMAND:
		wmId = LOWORD(wParam);
		wmEvent = HIWORD(wParam);
		// Parse the menu selections:
		switch (wmId)
		{
		case IDOK:
		{
					 int x1 = GetDlgItemInt(hDlg, IDC_X1, 0, 0);
					 int y1 = GetDlgItemInt(hDlg, IDC_Y1, 0, 0);
					 int x2 = GetDlgItemInt(hDlg, IDC_X2, 0, 0);
					 int y2 = GetDlgItemInt(hDlg, IDC_Y2, 0, 0);
					 Squer ac(Point(x1, y1), Point(x2, y2));
		}
		case IDCANCEL:
			EndDialog(hDlg, wmId);
			return (INT_PTR)TRUE;
		}
		break;
	}
	return (INT_PTR)FALSE;
}

INT_PTR CALLBACK LoginProc(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	int wmId, wmEvent;

	UNREFERENCED_PARAMETER(lParam);
	switch (message)
	{
	case WM_INITDIALOG:
		return (INT_PTR)TRUE;

	case WM_COMMAND:
		wmId = LOWORD(wParam);
		wmEvent = HIWORD(wParam);
		// Parse the menu selections:
		switch (wmId)
		{
		case IDOK:
		{
		
		}
		case IDCANCEL:
			EndDialog(hDlg, wmId);
			return (INT_PTR)TRUE;
		}
		break;
	}
	return (INT_PTR)FALSE;
}

void OutTimeDate(HWND hWnd)
{
	LPTSTR szDay[] = { _T("Вск."), _T("Пнд."), _T("Втр."),
		_T("Ср."), _T("Чтв."),
		_T("Птн."), _T("Суб.")
	};
	LPTSTR szMonth[] = { _T(""), _T("Янв."), _T("Февр."),
		_T("Март"), _T("Апр."),
		_T("Май"), _T("Июнь"),
		_T("Июль"), _T("Авг."),
		_T("Сент."), _T("Окт."),
		_T("Нояб."), _T("Дек.")
	};
	TCHAR szT[20];
	SYSTEMTIME SystemTime;
	/*
	Функция GetLocalTime осуществляет выборку местного време-
	ни, на которое настроен компьютер, т.е. функция
	заполняет структуру типа SYSTEMTIME в числовом виде.
	*/
	GetLocalTime(&SystemTime);
	/*День недели*/
	lstrcpy(szCurrentTime,
		szDay[SystemTime.wDayOfWeek]);
	/*Разделяющий пробел*/
	lstrcat((LPTSTR)szCurrentTime, _T(" "));
	/*Месяц*/
	lstrcat((LPTSTR)szCurrentTime,
		szMonth[SystemTime.wMonth]);
	/*Разделяющий пробел*/
	lstrcat((LPTSTR)szCurrentTime, _T(" "));
	/*Дату переводим в символы*/
	wsprintf((LPTSTR)szT, _T("%d"),
		SystemTime.wDay);
	lstrcat((LPTSTR)szCurrentTime, (LPTSTR)szT);
	/*Разделяющий пробел*/
	lstrcat((LPTSTR)szCurrentTime, _T(" "));
	/*Год переводим в символы*/
	wsprintf((LPTSTR)szT, _T("%d"),
		SystemTime.wYear);
	lstrcat((LPTSTR)szCurrentTime, (LPTSTR)szT);
	lstrcat((LPTSTR)szCurrentTime, _T("---"));
	/**Часы переводим в символы*/
	wsprintf((LPTSTR)szT, _T("%d"),
		SystemTime.wHour);
	lstrcat((LPTSTR)szCurrentTime, (LPTSTR)szT);
	/*Разделяющее двоеточие*/
	lstrcat((LPTSTR)szCurrentTime, _T(":"));
	/*Минуты переводим в символы*/
	wsprintf((LPTSTR)szT, _T("%d"),
		SystemTime.wMinute);
	lstrcat((LPTSTR)szCurrentTime, (LPTSTR)szT);
	/*Разделяющее двоеточие*/
	lstrcat((LPTSTR)szCurrentTime, _T(":"));
	/*Сеуцнды переводим в символы*/
	wsprintf((LPTSTR)szT, _T("%d"),
		SystemTime.wSecond);
	lstrcat((LPTSTR)szCurrentTime, (LPTSTR)szT);
	/*Перерисовка окна*/
	InvalidateRect(hWnd, NULL, TRUE);
}