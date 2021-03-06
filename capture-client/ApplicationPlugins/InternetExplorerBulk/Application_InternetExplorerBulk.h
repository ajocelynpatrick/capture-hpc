/*
 *	PROJECT: Capture
 *	FILE: Client_InternetExplorerBulk.h
 *	AUTHORS: Ramon Steenson (rsteenson@gmail.com) & Christian Seifert (christian.seifert@gmail.com)
 *
 *	Developed by Victoria University of Wellington and the New Zealand Honeynet Alliance
 *
 *	This file is part of Capture.
 *
 *	Capture is free software; you can redistribute it and/or modify
 *	it under the terms of the GNU General Public License as published by
 *	the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  Capture is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with Capture; if not, write to the Free Software
 *  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
 */
#pragma once
#include "..\..\ApplicationPlugin.h"
#include "..\..\CaptureGlobal.h"
#include <psapi.h>

#define MAX_WORKER_THREADS 60

/* Define the application plugin name and the application names it supports */
#define APPLICATION_PLUGIN_NAME		Application_InternetExplorerBulk
static wchar_t* supportedApplications[] = {L"iexplorebulk", NULL};
using namespace std;

class Application_InternetExplorerBulk : ApplicationPlugin
{
	
public:
	Application_InternetExplorerBulk(void);
	~Application_InternetExplorerBulk(void);
	
	void visitGroup(VisitEvent* visitEvent);
	wchar_t** getSupportedApplicationNames();
	unsigned int getPriority() { return 100; };
	DWORD closeAllInternetExplorers();

	std::wstring getAlgorithm() { return L"bulk"; }
private:
	static BOOL CALLBACK EnumWindowsProc(HWND hwnd,LPARAM lParam);
	static DWORD WINAPI InternetExplorerWorker(LPVOID data);
	int compareName(DWORD processID, std::wstring processName);
	static BOOL CALLBACK EnumWindowsCloseAppProc(HWND hwnd,LPARAM lParam);


};

/* DO NOT REMOVE OR MOVE THIS LINE ... ADDS EXPORTS (NEW/DELETE) TO THE PLUGIN */
/* Must be included after the actual plugin class definition */
#include "..\..\PluginExports.h"

