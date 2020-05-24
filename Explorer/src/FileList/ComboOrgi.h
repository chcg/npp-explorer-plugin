/*
This file is part of Explorer Plugin for Notepad++
Copyright (C)2006 Jens Lorenz <jens.plugin.npp@gmx.de>

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License
as published by the Free Software Foundation; either version 2
of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
*/


#ifndef COMBOORGI_DEFINE_H
#define COMBOORGI_DEFINE_H

#include <tchar.h>
#include <vector>
using namespace std;

class ComboOrgi
{
public :
	ComboOrgi();
    ~ComboOrgi ();
	virtual void init(HWND hCombo);
	virtual void destroy() {
	};

	void addText(LPTSTR pszText);
	void setText(LPTSTR pszText, UINT size = MAX_PATH);
	void getText(LPTSTR pszText, UINT size = MAX_PATH);
	bool getSelText(LPTSTR pszText);

	void setComboList(vector<wstring> vStrList);
	void getComboList(vector<wstring> & vStrList);

	void clearComboList(void)
	{
		_comboItems.clear();
	};

private:
	void selectComboText(LPTSTR pszText);

private :
	HWND					_hCombo;
    WNDPROC					_hDefaultComboProc;

	wstring					_currData;
	vector<wstring>			_comboItems;

	LRESULT runProc(HWND hwnd, UINT Message, WPARAM wParam, LPARAM lParam);
	static LRESULT CALLBACK wndDefaultProc(HWND hwnd, UINT Message, WPARAM wParam, LPARAM lParam) {
		return (((ComboOrgi *)(::GetWindowLongPtr(hwnd, GWLP_USERDATA)))->runProc(hwnd, Message, wParam, lParam));
	};
};

#endif // COMBOORGI_DEFINE_H
