// ModernCppLibraries.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <Windows.h>
#include <crtdbg.h>

#define ASSERT _ASSERTE

#ifdef _DEBUG
#define VERIFY ASSERT
#else
#define VERIFY(expresison) (expression)
#endif

struct LastException
{
	DWORD result;

	LastException() : result{ GetLastError() } {}
};

struct ManualResetEvent
{
	HANDLE m_handle;

	ManualResetEvent() {
		m_handle = CreateEvent(nullptr,
			true,
			false,
			nullptr);

		if (!m_handle) {
			throw LastException();
		}
	}

	~ManualResetEvent() {
		VERIFY(CloseHandle(m_handle));
	}
};

static_assert(sizeof(float) == 4, "can't serialize floats!");

int main()
{
	auto e = ManualResetEvent{};
	auto e2 = e;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
