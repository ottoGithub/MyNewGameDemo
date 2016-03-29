#ifndef _PROCESS_INFO_WIN32_H_
#define _PROCESS_INFO_WIN32_H_

struct ProcessInfoWin32
{
	HINSTANCE m_hInst;
	HINSTANCE m_hPrevInst;
	LPSTR     m_lpCmdLine;
	int	      m_nCmdShow;
};

#endif