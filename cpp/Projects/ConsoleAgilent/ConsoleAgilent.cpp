// ConsoleAgilent.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
//#define _CRT_SECURE_NO_WARNINGS
using namespace std;
//void WriteToFile(const char*);

int _tmain(int argc, _TCHAR* argv[])
{
	HRESULT hr = ::CoInitialize(NULL);
	if (FAILED(hr)) exit(1);
	{
		IIviDmmPtr dmm(__uuidof(Agilent34410));
		try
		{
			vector<int>reading;
			dmm->Initialize("USB0::0x0957::0x0607::MY53008991::0::INSTR", false, true, "");
			dmm->Configure(IviDmmFunction2WireRes, 1.5, 0.001);
			dmm->Trigger->Delay = 0.01;
			for (size_t i = 0; i < 10; ++i)
			{
				reading[i] = dmm->Measurement->Read(1000);
				//wprintf(L"Reading: %g\n", reading[i]);
				// sprintf_s(str, buf, "%g\n", reading[i]);
			}
		}
		catch (_com_error e)
		{
			wprintf(L"Error: %s", e.ErrorMessage());
		}
		dmm->Close();
	}
	
	::CoUninitialize();

	printf("\nDone - Press any key to exit");
	getchar();
	return 0;
}

/*void WriteToFile(char *str)
{
	FILE* fp;
	char* fname = "ConsoleAgilent.txt";
	fopen_s(&fp, fname, "w");
	fprintf(fp, str);
	fclose(fp);
}*/