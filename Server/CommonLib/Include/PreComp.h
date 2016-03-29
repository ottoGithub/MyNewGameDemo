#ifndef _COMMONLIB_PRE_COMP_H_
#define _COMMONLIB_PRE_COMP_H_

#ifdef _WIN32
#define WIN32_LEAN_AND_MEAN
/*
 ͷ�ļ�Winsock2.h���ڲ�������Windows.h�ĺ���Ԫ�أ�
 �����WinsockӦ�ó�����ͨ��������ͷ�ļ�Windows.h��
 �����Ҫһ��#include��������Windows.h����ô����Ҫ
 ��ǰ�����#define WIN32_LEAN_AND_MEAN �ꡣ������
 ʷԭ��ͷ�ļ�Windows.hĬ�ϵذ���Windows Sockets 
 1.1���ͷ�ļ�Winsock.h����ͷ�ļ�Winsock.h�е�����
 ���Windows Socket2��Ҫ��ͷ�ļ�Winsock2.h�е�����
 ��ͻ��WIN32_LEAN_AND_MEAN���ֹWindows.h����Winso
 ck.h��
 */
#endif

#ifdef _WIN32
#include <WinSock2.h>
#endif

#include "Types.h"

#define SAFE_DELETE(p) { if(p){ delete p; p = NULL;} }

#endif