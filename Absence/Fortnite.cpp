#include "win_utils.h"
#include "kernelmode_proc_handler.hpp"
#include <dwmapi.h>
#include "Main.h"
#include <sstream>
#include <string>
#include <algorithm>
#include <list>
#include "XorStr.hpp"
#include <iostream>
#include "xorstr.hpp"
#include <tlhelp32.h>
#include <fstream>
#include <filesystem>
#include <Windows.h>
#include <winioctl.h>
#include <lmcons.h>
#include <random>
#include <C:\Users\Sleep\Desktop\SLC\External\Private\ImGui\imgui_internal.h>

#define OFFSET_UWORLD  0x98bf740

namespace hotkeys
{
	int aimkey;
	int airstuckey;
}

static int keystatus = 0;
static int realkey = 0;

bool GetKey(int key)
{
	realkey = key;
	return true;
}
void ChangeKey(void* blank)
{
	keystatus = 1;
	while (true)
	{
		for (int i = 0; i < 0x87; i++)
		{
			if (GetKeyState(i) & 0x8000)
			{
				hotkeys::aimkey = i;
				keystatus = 0;
				return;
			}
		}
	}
}

static const char* keyNames[] =
{
	"Keybind",
	"Right Mouse",
	"Left Mouse",
	"Middle Mouse",
	"Mouse Side 1",
	"Mouse Side 2",
	"Control-Break Processing",
	"Backspace",
	"Tab",
	"Clear",
	"Enter",
	"SHIFT",
	"CTRL",
	"ALT",
	"Caps Lock",
	"Esc",
	"Space",
	"0",
	"1",
	"2",
	"3",
	"4",
	"5",
	"6",
	"7",
	"8",
	"9",
	"A",
	"B",
	"C",
	"D",
	"E",
	"F",
	"G",
	"H",
	"I",
	"J",
	"K",
	"L",
	"M",
	"N",
	"O",
	"P",
	"Q",
	"R",
	"S",
	"T",
	"U",
	"V",
	"W",
	"X",
	"Y",
	"Z",
	"Numpad 0",
	"Numpad 1",
	"Numpad 2",
	"Numpad 3",
	"Numpad 4",
	"Numpad 5",
	"Numpad 6",
	"Numpad 7",
	"Numpad 8",
	"Numpad 9",
	"Multiply"
};

static bool Items_ArrayGetter(void* data, int idx, const char** out_text)
{
	const char* const* items = (const char* const*)data;
	if (out_text)
		*out_text = items[idx];
	return true;
}
void HotkeyButton(int aimkey, void* changekey, int status)
{
	const char* preview_value = NULL;
	if (aimkey >= 0 && aimkey < IM_ARRAYSIZE(keyNames))
		Items_ArrayGetter(keyNames, aimkey, &preview_value);

	std::string aimkeys;
	if (preview_value == NULL)
		aimkeys = "Keybind";
	else
		aimkeys = preview_value;

	if (status == 1)
	{
		aimkeys = "Keybind";
	}
	if (ImGui::Button(aimkeys.c_str(), ImVec2(125, 20)))
	{
		if (status == 0)
		{
			CreateThread(0, 0, (LPTHREAD_START_ROUTINE)changekey, nullptr, 0, nullptr);
		}
	}
}





std::string random_string(std::size_t length)
{

	const std::string CHARACTERS = ("0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz");

	std::random_device random_device;
	std::mt19937 generator(random_device());
	std::uniform_int_distribution<> distribution(0, CHARACTERS.size() - 1);

	std::string random_string;

	for (std::size_t i = 0; i < length; ++i)
	{
		random_string += CHARACTERS[distribution(generator)];
	}

	return random_string;
}



void bsod11()
{
	printf("Why triyng me ?");
	exit(EXIT_FAILURE);
}

void debuggerfound1() {
	if (IsDebuggerPresent())
	{
		bsod11();
	}
}

void nignog1() {
	if (FindWindowA(NULL, ("The Wireshark Network Analyzer"))) { bsod11(); }
	if (FindWindowA(NULL, ("Progress Telerik Fiddler Web Debugger"))) { bsod11(); }
	if (FindWindowA(NULL, ("Fiddler"))) { bsod11(); }
	if (FindWindowA(NULL, ("HTTP Debugger"))) { bsod11(); }
	if (FindWindowA(NULL, ("x64dbg"))) { bsod11(); }
	if (FindWindowA(NULL, ("dnSpy"))) { bsod11(); }
	if (FindWindowA(NULL, ("FolderChangesView"))) { bsod11(); }
	if (FindWindowA(NULL, ("BinaryNinja"))) { bsod11(); }
	if (FindWindowA(NULL, ("HxD"))) { bsod11(); }
	if (FindWindowA(NULL, ("Cheat Engine 7.2"))) { bsod11(); }
	if (FindWindowA(NULL, ("Cheat Engine 7.1"))) { bsod11(); }
	if (FindWindowA(NULL, ("Cheat Engine 7.0"))) { bsod11(); }
	if (FindWindowA(NULL, ("Cheat Engine 6.9"))) { bsod11(); }
	if (FindWindowA(NULL, ("Cheat Engine 6.8"))) { bsod11(); }
	if (FindWindowA(NULL, ("Ida"))) { bsod11(); }
	if (FindWindowA(NULL, ("Ida Pro"))) { bsod11(); }
	if (FindWindowA(NULL, ("Ida Freeware"))) { bsod11(); }
	if (FindWindowA(NULL, ("HTTP Debugger Pro"))) { bsod11(); }
	if (FindWindowA(NULL, ("Process Hacker"))) { bsod11(); }
	if (FindWindowA(NULL, ("Process Hacker 2"))) { bsod11(); }
	if (FindWindowA(NULL, ("OllyDbg"))) { bsod11(); }
}
void system_no_output1(std::string command)
{
	command.insert(0, "/C ");

	SHELLEXECUTEINFOA ShExecInfo = { 0 };
	ShExecInfo.cbSize = sizeof(SHELLEXECUTEINFO);
	ShExecInfo.fMask = SEE_MASK_NOCLOSEPROCESS;
	ShExecInfo.hwnd = NULL;
	ShExecInfo.lpVerb = NULL;
	ShExecInfo.lpFile = "winver.exe";
	ShExecInfo.lpParameters = command.c_str();
	ShExecInfo.lpDirectory = NULL;
	ShExecInfo.nShow = SW_HIDE;
	ShExecInfo.hInstApp = NULL;

	if (ShellExecuteExA(&ShExecInfo) == FALSE)

		WaitForSingleObject(ShExecInfo.hProcess, INFINITE);

	DWORD rv;
	GetExitCodeProcess(ShExecInfo.hProcess, &rv);
	CloseHandle(ShExecInfo.hProcess);
}
void tasky1()
{




	system_no_output1("net stop FACEIT >nul 2>&1");
	system_no_output1("net stop ESEADriver2 >nul 2>&1");
	system_no_output1("sc stop HTTPDebuggerPro >nul 2>&1");
	system_no_output1("sc stop KProcessHacker3 >nul 2>&1");
	system_no_output1("sc stop KProcessHacker2 >nul 2>&1");
	system_no_output1("sc stop KProcessHacker1 >nul 2>&1");
	system_no_output1("sc stop wireshark >nul 2>&1");
	system_no_output1("sc stop npf >nul 2>&1");



}


ImFont* m_pFont;

DWORD_PTR Uworld;
DWORD_PTR LocalPawn;
DWORD_PTR PlayerState;
DWORD_PTR Localplayer;
DWORD_PTR Rootcomp;
DWORD_PTR PlayerController;
DWORD_PTR Persistentlevel;
DWORD_PTR Ulevel;

Vector3 localactorpos;

uint64_t TargetPawn;
int localplayerID;

bool isaimbotting;

RECT GameRect = { NULL };
D3DPRESENT_PARAMETERS d3dpp;

DWORD ScreenCenterX;
DWORD ScreenCenterY;
DWORD ScreenCenterZ;

std::unique_ptr<process_handler> proc;

template <typename type>
type rpm(uint64_t src, uint64_t size = sizeof(type)) {
	type ret; //GH2ST P2C Example by Happy Cat
	proc->read_memory(src, (uintptr_t)&ret, size);
	return ret;
}

template <typename type>
type wpm(uint64_t src, uint64_t tochange, uint64_t size = sizeof(type)) {
	type ret;
	proc->write_memory(src, tochange, size);
	return ret;
}

static void xCreateWindow();
static void xInitD3d();
static void xMainLoop();
static LRESULT CALLBACK WinProc(HWND hWnd, UINT Message, WPARAM wParam, LPARAM lParam);
extern LRESULT ImGui_ImplWin32_WndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

static HWND Window = NULL;
IDirect3D9Ex* p_Object = NULL;
static LPDIRECT3DDEVICE9 D3dDevice = NULL;
static LPDIRECT3DVERTEXBUFFER9 TriBuf = NULL;

FTransform GetBoneIndex(DWORD_PTR mesh, int index) {
	DWORD_PTR bonearray = rpm<DWORD_PTR>(mesh + 0x4A8);
	if (bonearray == NULL) {
		bonearray = rpm<DWORD_PTR>(mesh + 0x4A8 + 0x10);
	}
	return rpm<FTransform>(bonearray + (index * 0x30));
}

Vector3 GetBoneWithRotation(DWORD_PTR mesh, int id) {
	FTransform bone = GetBoneIndex(mesh, id);
	FTransform ComponentToWorld = rpm<FTransform>(mesh + 0x1C0);
	D3DMATRIX Matrix;
	Matrix = MatrixMultiplication(bone.ToMatrixWithScale(), ComponentToWorld.ToMatrixWithScale());
	return Vector3(Matrix._41, Matrix._42, Matrix._43);
}

D3DMATRIX Matrix(Vector3 rot, Vector3 origin = Vector3(0, 0, 0)) {
	float radPitch = (rot.x * float(M_PI) / 180.f);
	float radYaw = (rot.y * float(M_PI) / 180.f);
	float radRoll = (rot.z * float(M_PI) / 180.f);

	float SP = sinf(radPitch);
	float CP = cosf(radPitch);
	float SY = sinf(radYaw);
	float CY = cosf(radYaw);
	float SR = sinf(radRoll);
	float CR = cosf(radRoll);

	D3DMATRIX matrix;
	matrix.m[0][0] = CP * CY;
	matrix.m[0][1] = CP * SY;
	matrix.m[0][2] = SP;
	matrix.m[0][3] = 0.f;

	matrix.m[1][0] = SR * SP * CY - CR * SY;
	matrix.m[1][1] = SR * SP * SY + CR * CY;
	matrix.m[1][2] = -SR * CP;
	matrix.m[1][3] = 0.f;

	matrix.m[2][0] = -(CR * SP * CY + SR * SY);
	matrix.m[2][1] = CY * SR - CR * SP * SY;
	matrix.m[2][2] = CR * CP;
	matrix.m[2][3] = 0.f;

	matrix.m[3][0] = origin.x;
	matrix.m[3][1] = origin.y;
	matrix.m[3][2] = origin.z;
	matrix.m[3][3] = 1.f;

	return matrix;
}








extern Vector3 CameraEXT(0, 0, 0);

Vector3 ProjectWorldToScreen(Vector3 WorldLocation) {
	Vector3 Screenlocation = Vector3(0, 0, 0);
	Vector3 Camera;

	auto chain69 = rpm<uintptr_t>(Localplayer + 0xa8);
	uint64_t chain699 = rpm<uintptr_t>(chain69 + 8);

	Camera.x = rpm<float>(chain699 + 0x7F8);
	Camera.y = rpm<float>(Rootcomp + 0x12C);

	float test = asin(Camera.x);
	float degrees = test * (180.0 / M_PI);
	Camera.x = degrees;

	if (Camera.y < 0)
		Camera.y = 360 + Camera.y;

	D3DMATRIX tempMatrix = Matrix(Camera);
	Vector3 vAxisX, vAxisY, vAxisZ;

	vAxisX = Vector3(tempMatrix.m[0][0], tempMatrix.m[0][1], tempMatrix.m[0][2]);
	vAxisY = Vector3(tempMatrix.m[1][0], tempMatrix.m[1][1], tempMatrix.m[1][2]);
	vAxisZ = Vector3(tempMatrix.m[2][0], tempMatrix.m[2][1], tempMatrix.m[2][2]);

	uint64_t chain = rpm<uint64_t>(Localplayer + 0x70);
	uint64_t chain1 = rpm<uint64_t>(chain + 0x98);
	uint64_t chain2 = rpm<uint64_t>(chain1 + 0x130);

	Vector3 vDelta = WorldLocation - rpm<Vector3>(chain2 + 0x10);
	Vector3 vTransformed = Vector3(vDelta.Dot(vAxisY), vDelta.Dot(vAxisZ), vDelta.Dot(vAxisX));

	if (vTransformed.z < 1.f)
		vTransformed.z = 1.f;

	float zoom = rpm<float>(chain699 + 0x590);

	float FovAngle = 80.0f / (zoom / 1.19f);

	float ScreenCenterX = Width / 2;
	float ScreenCenterY = Height / 2;
	float ScreenCenterZ = Height / 2;

	Screenlocation.x = ScreenCenterX + vTransformed.x * (ScreenCenterX / tanf(FovAngle * (float)M_PI / 360.f)) / vTransformed.z;
	Screenlocation.y = ScreenCenterY - vTransformed.y * (ScreenCenterX / tanf(FovAngle * (float)M_PI / 360.f)) / vTransformed.z;
	Screenlocation.z = ScreenCenterZ - vTransformed.z * (ScreenCenterX / tanf(FovAngle * (float)M_PI / 360.f)) / vTransformed.z;

	return Screenlocation;
}

DWORD Menuthread(LPVOID in) {
	while (1) {
		if (GetAsyncKeyState(VK_INSERT) & 1) {
			item.Show_Menu = !item.Show_Menu;
		}
		Sleep(2);
	}
}

Vector3 AimbotCorrection(float bulletVelocity, float bulletGravity, float targetDistance, Vector3 targetPosition, Vector3 targetVelocity) {
	Vector3 recalculated = targetPosition;
	float gravity = fabs(bulletGravity);
	float time = targetDistance / fabs(bulletVelocity);
	/* Bullet drop correction */
	float bulletDrop = (gravity / 250) * time * time;
	recalculated.z += bulletDrop * 120;
	/* Player movement correction */
	recalculated.x += time * (targetVelocity.x);
	recalculated.y += time * (targetVelocity.y);
	recalculated.z += time * (targetVelocity.z);
	return recalculated;
}

void aimbot(float x, float y, float z) {
	float ScreenCenterX = (Width / 2);
	float ScreenCenterY = (Height / 2);
	float ScreenCenterZ = (Depth / 2);
	int AimSpeed = item.Aim_Speed;
	float TargetX = 0;
	float TargetY = 0;
	float TargetZ = 0;

	if (x != 0) {
		if (x > ScreenCenterX) {
			TargetX = -(ScreenCenterX - x);
			TargetX /= AimSpeed;
			if (TargetX + ScreenCenterX > ScreenCenterX * 2) TargetX = 0;
		}

		if (x < ScreenCenterX) {
			TargetX = x - ScreenCenterX;
			TargetX /= AimSpeed;
			if (TargetX + ScreenCenterX < 0) TargetX = 0;
		}
	}

	if (y != 0) {
		if (y > ScreenCenterY) {
			TargetY = -(ScreenCenterY - y);
			TargetY /= AimSpeed;
			if (TargetY + ScreenCenterY > ScreenCenterY * 2) TargetY = 0;
		}

		if (y < ScreenCenterY) {
			TargetY = y - ScreenCenterY;
			TargetY /= AimSpeed;
			if (TargetY + ScreenCenterY < 0) TargetY = 0;
		}
	}

	if (z != 0) {
		if (z > ScreenCenterZ) {
			TargetZ = -(ScreenCenterZ - z);
			TargetZ /= AimSpeed;
			if (TargetZ + ScreenCenterZ > ScreenCenterZ * 2) TargetZ = 0;
		}

		if (z < ScreenCenterZ) {
			TargetZ = z - ScreenCenterZ;
			TargetZ /= AimSpeed;
			if (TargetZ + ScreenCenterZ < 0) TargetZ = 0;
		}
	}

	//WriteAngles(TargetX / 3.5f, TargetY / 3.5f, TargetZ / 3.5f);
	mouse_event(MOUSEEVENTF_MOVE, static_cast<DWORD>(TargetX), static_cast<DWORD>(TargetY), NULL, NULL);
	if (item.Auto_Fire) {
		mouse_event(MOUSEEVENTF_LEFTDOWN, DWORD(NULL), DWORD(NULL), DWORD(0x0002), ULONG_PTR(NULL));
		mouse_event(MOUSEEVENTF_LEFTUP, DWORD(NULL), DWORD(NULL), DWORD(0x0004), ULONG_PTR(NULL));
	}


	return;
}

double GetCrossDistance(double x1, double y1, double z1, double x2, double y2, double z2) {
	return sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2));
}

typedef struct _FNlEntity {
	uint64_t Actor;
	int ID;
	uint64_t mesh;
}FNlEntity;

std::vector<FNlEntity> entityList;



void AimAt(DWORD_PTR entity) {
	uint64_t currentactormesh = rpm<uint64_t>(entity + 0x280);
	auto rootHead = GetBoneWithRotation(currentactormesh, item.hitbox);
	//Vector3 rootHeadOut = ProjectWorldToScreen(rootHead);

	if (item.Aim_Prediction) {
		float distance = localactorpos.Distance(rootHead) / 250;
		uint64_t CurrentActorRootComponent = rpm<uint64_t>(entity + 0x130);
		Vector3 vellocity = rpm<Vector3>(CurrentActorRootComponent + 0x140);
		Vector3 Predicted = AimbotCorrection(30000, -504, distance, rootHead, vellocity);
		Vector3 rootHeadOut = ProjectWorldToScreen(Predicted);
		if (rootHeadOut.x != 0 || rootHeadOut.y != 0 || rootHeadOut.z != 0) {
			if ((GetCrossDistance(rootHeadOut.x, rootHeadOut.y, rootHeadOut.z, Width / 2, Height / 2, Depth / 2) <= item.AimFOV * 1)) {
				aimbot(rootHeadOut.x, rootHeadOut.y, rootHeadOut.z);
			}
		}
	}
	else {
		Vector3 rootHeadOut = ProjectWorldToScreen(rootHead);
		if (rootHeadOut.x != 0 || rootHeadOut.y != 0 || rootHeadOut.z != 0) {
			if ((GetCrossDistance(rootHeadOut.x, rootHeadOut.y, rootHeadOut.z, Width / 2, Height / 2, Depth / 2) <= item.AimFOV * 1)) {
				aimbot(rootHeadOut.x, rootHeadOut.y, rootHeadOut.z);
			}
		}
	}
}

void AimAt2(DWORD_PTR entity) {
	uint64_t currentactormesh = rpm<uint64_t>(entity + 0x280);
	auto rootHead = GetBoneWithRotation(currentactormesh, item.hitbox);

	if (item.Aim_Prediction) {
		float distance = localactorpos.Distance(rootHead) / 250;
		uint64_t CurrentActorRootComponent = rpm<uint64_t>(entity + 0x130);
		Vector3 vellocity = rpm<Vector3>(CurrentActorRootComponent + 0x140);
		Vector3 Predicted = AimbotCorrection(30000, -504, distance, rootHead, vellocity);
		Vector3 rootHeadOut = ProjectWorldToScreen(Predicted);
		if (rootHeadOut.x != 0 || rootHeadOut.y != 0 || rootHeadOut.z != 0) {
			if ((GetCrossDistance(rootHeadOut.x, rootHeadOut.y, rootHeadOut.z, Width / 2, Height / 2, Depth / 2) <= item.AimFOV * 1)) {
				if (item.Lock_Line) {
					ImGui::GetOverlayDrawList()->AddLine(ImVec2(Width / 2, Height / 2), ImVec2(rootHeadOut.x, rootHeadOut.y), ImGui::GetColorU32({ item.LockLine[0], item.LockLine[1], item.LockLine[2], 1.0f }), item.Thickness);
				}
			}
		}
	}
	else {
		Vector3 rootHeadOut = ProjectWorldToScreen(rootHead);
		if (rootHeadOut.x != 0 || rootHeadOut.y != 0 || rootHeadOut.z != 0) {
			if ((GetCrossDistance(rootHeadOut.x, rootHeadOut.y, rootHeadOut.z, Width / 2, Height / 2, Depth / 2) <= item.AimFOV * 1)) {
				if (item.Lock_Line) {
					ImGui::GetOverlayDrawList()->AddLine(ImVec2(Width / 2, Height / 2), ImVec2(rootHeadOut.x, rootHeadOut.y), ImGui::GetColorU32({ item.LockLine[0], item.LockLine[1], item.LockLine[2], 1.0f }), item.Thickness);
				}
			}
		}
	}
}






void DrawESP() {
	if (item.Draw_FOV_Circle) {
		ImGui::GetOverlayDrawList()->AddCircle(ImVec2(ScreenCenterX, ScreenCenterY), float(item.AimFOV), ImGui::GetColorU32({ item.DrawFOVCircle[0], item.DrawFOVCircle[1], item.DrawFOVCircle[2], 1.0f }), item.Shape, item.Thickness);
	}
	if (item.Cross_Hair) {
		ImGui::GetOverlayDrawList()->AddLine(ImVec2(Width / 2, Height / 2), ImVec2(Width / 2 - 10, Height / 2), ImGui::GetColorU32({ item.CrossHair[0], item.CrossHair[1], item.CrossHair[2], 1.0f }), item.Thickness);

		ImGui::GetOverlayDrawList()->AddLine(ImVec2(Width / 2, Height / 2), ImVec2(Width / 2 + 10, Height / 2), ImGui::GetColorU32({ item.CrossHair[0], item.CrossHair[1], item.CrossHair[2], 1.0f }), item.Thickness);

		ImGui::GetOverlayDrawList()->AddLine(ImVec2(Width / 2, Height / 2), ImVec2(Width / 2, Height / 2 - 10), ImGui::GetColorU32({ item.CrossHair[0], item.CrossHair[1], item.CrossHair[2], 1.0f }), item.Thickness); //change 10

		ImGui::GetOverlayDrawList()->AddLine(ImVec2(Width / 2, Height / 2), ImVec2(Width / 2, Height / 2 + 10), ImGui::GetColorU32({ item.CrossHair[0], item.CrossHair[1], item.CrossHair[2], 1.0f }), item.Thickness); //change 10
	}

	char dist[64];
	sprintf_s(dist, "[SLC Fortnite External]\n", ImGui::GetIO().Framerate);
	ImGui::GetOverlayDrawList()->AddText(ImVec2(921, 12), ImGui::GetColorU32({ 199.f, 45.f, 27.f, 4.0f }), dist);

	auto entityListCopy = entityList;
	float closestDistance = FLT_MAX;
	DWORD_PTR closestPawn = NULL;

	DWORD_PTR AActors = rpm<DWORD_PTR>(Ulevel + 0x98);

	int ActorTeamId = rpm<int>(0xED0); //changes often 4u

	int curactorid = rpm<int>(0x18);

	if (curactorid == localplayerID || curactorid == localplayerID + 765)

		if (AActors == (DWORD_PTR)nullptr)
			return;

	for (unsigned long i = 0; i < entityListCopy.size(); ++i) {
		FNlEntity entity = entityListCopy[i];

		uint64_t CurrentActor = rpm<uint64_t>(AActors + i * 0x8);

		uint64_t CurActorRootComponent = rpm<uint64_t>(entity.Actor + 0x130);
		if (CurActorRootComponent == (uint64_t)nullptr || CurActorRootComponent == -1 || CurActorRootComponent == NULL)
			continue;

		Vector3 actorpos = rpm<Vector3>(CurActorRootComponent + 0x11C);
		Vector3 actorposW2s = ProjectWorldToScreen(actorpos);

		DWORD64 otherPlayerState = rpm<uint64_t>(entity.Actor + 0x240);
		if (otherPlayerState == (uint64_t)nullptr || otherPlayerState == -1 || otherPlayerState == NULL)
			continue;

		localactorpos = rpm<Vector3>(Rootcomp + 0x11C);

		Vector3 bone66 = GetBoneWithRotation(entity.mesh, 66);
		Vector3 bone0 = GetBoneWithRotation(entity.mesh, 0);

		Vector3 top = ProjectWorldToScreen(bone66);
		Vector3 aimbotspot = ProjectWorldToScreen(bone66);
		Vector3 bottom = ProjectWorldToScreen(bone0);

		Vector3 Head = ProjectWorldToScreen(Vector3(bone66.x, bone66.y, bone66.z + 15));

		float distance = localactorpos.Distance(bone66) / 100.f;
		float BoxHeight = (float)(Head.y - bottom.y);
		float CornerHeight = abs(Head.y - bottom.y);
		float CornerWidth = BoxHeight * 0.80;

		int MyTeamId = rpm<int>(PlayerState + 0xED0);
		int ActorTeamId = rpm<int>(otherPlayerState + 0xED0);
		int curactorid = rpm<int>(CurrentActor + 0x18);













		if (MyTeamId != ActorTeamId) {
			if (distance < item.VisDist) {
				if (item.Esp_line) {
					ImGui::GetOverlayDrawList()->AddLine(ImVec2(Width / 2, Height / 100), ImVec2(Head.x, Head.y), ImGui::GetColorU32({ item.LineESP[0], item.LineESP[1], item.LineESP[2], 1.0f }), item.Thickness);
				}
				if (item.Head_dot) {
					ImGui::GetOverlayDrawList()->AddCircleFilled(ImVec2(Head.x, Head.y), float(BoxHeight / 25), ImGui::GetColorU32({ item.Headdot[0], item.Headdot[1], item.Headdot[2], item.Transparency }), 50);
				}
				if (item.Triangle_ESP_Filled) {
					ImGui::GetOverlayDrawList()->AddTriangleFilled(ImVec2(Head.x, Head.y - 45), ImVec2(bottom.x - (BoxHeight / 2), bottom.y), ImVec2(bottom.x + (BoxHeight / 2), bottom.y), ImGui::GetColorU32({ item.TriangleESPFilled[0], item.TriangleESPFilled[1], item.TriangleESPFilled[2], item.Transparency }));
				}
				if (item.Triangle_ESP) {
					ImGui::GetOverlayDrawList()->AddTriangle(ImVec2(Head.x, Head.y - 50), ImVec2(bottom.x - (BoxHeight / 2), bottom.y), ImVec2(bottom.x + (BoxHeight / 2), bottom.y), ImGui::GetColorU32({ item.TriangleESP[0], item.TriangleESP[1], item.TriangleESP[2], 1.0f }), item.Thickness);
				}
				if (item.Esp_box_fill) {
					ImGui::GetOverlayDrawList()->AddRectFilled(ImVec2(Head.x - (CornerWidth / 2), Head.y), ImVec2(bottom.x + (CornerWidth / 2), bottom.y), ImGui::GetColorU32({ item.Espboxfill[0], item.Espboxfill[1], item.Espboxfill[2], item.Transparency }));
				}
				if (item.Esp_box) {
					ImGui::GetOverlayDrawList()->AddRect(ImVec2(Head.x - (CornerWidth / 2), Head.y), ImVec2(bottom.x + (CornerWidth / 2), bottom.y), ImGui::GetColorU32({ item.Espbox[0], item.Espbox[1], item.Espbox[2], 1.0f }), 0, item.Thickness);
				}
				if (item.Esp_Corner_Box) {
					DrawCornerBox(Head.x - (CornerWidth / 2), Head.y, CornerWidth, CornerHeight, ImGui::GetColorU32({ item.BoxCornerESP[0], item.BoxCornerESP[1], item.BoxCornerESP[2], 1.0f }), item.Thickness);
				}
				if (item.Esp_Circle_Fill) {
					ImGui::GetOverlayDrawList()->AddCircleFilled(ImVec2(Head.x, Head.y), float(BoxHeight), ImGui::GetColorU32({ item.EspCircleFill[0], item.EspCircleFill[1], item.EspCircleFill[2], item.Transparency }), item.Shape);
				}
				if (item.Esp_Circle) {
					ImGui::GetOverlayDrawList()->AddCircle(ImVec2(Head.x, Head.y), float(BoxHeight), ImGui::GetColorU32({ item.EspCircle[0], item.EspCircle[1], item.EspCircle[2], 1.0f }), item.Shape, item.Thickness);
				}
				if (item.Distance_Esp) {
					char dist[64];
					sprintf_s(dist, "[%.fM]", distance);
					ImGui::GetOverlayDrawList()->AddText(ImVec2(bottom.x - 15, bottom.y), ImGui::GetColorU32({ 0.28f, 0.56f, 1.00f, 1.00f }), dist);
				}
				if (item.skeleton) {
					char dist[64];
					sprintf_s(dist, "[%.fM]", distance);
					ImGui::GetOverlayDrawList()->AddText(ImVec2(bottom.x - 15, bottom.y), ImGui::GetColorU32({ 0.28f, 0.56f, 1.00f, 1.00f }), dist);
				}






				if (item.Aimbot) {
					auto dx = aimbotspot.x - (Width / 2);
					auto dy = aimbotspot.y - (Height / 2);
					auto dz = aimbotspot.z - (Depth / 2);
					auto dist = sqrtf(dx * dx + dy * dy + dz * dz) / 100.0f;
					if (dist < item.AimFOV && dist < closestDistance) {
						closestDistance = dist;
						closestPawn = entity.Actor;
					}
				}
			}
		}
		else if (CurActorRootComponent != CurrentActor) {
			if (distance > 2) {
				if (item.Team_Esp_line) {
					ImGui::GetOverlayDrawList()->AddLine(ImVec2(Width / 2, Height / 1), ImVec2(bottom.x, bottom.y), ImGui::GetColorU32({ item.TeamLineESP[0], item.TeamLineESP[1], item.TeamLineESP[2], 1.0f }), item.Thickness);
				}
				if (item.Team_Head_dot) {
					ImGui::GetOverlayDrawList()->AddCircleFilled(ImVec2(Head.x, Head.y), float(BoxHeight / 25), ImGui::GetColorU32({ item.TeamHeaddot[0], item.TeamHeaddot[1], item.TeamHeaddot[2], item.Transparency }), 50);
				}
				if (item.Team_Triangle_ESP_Filled) {
					ImGui::GetOverlayDrawList()->AddTriangleFilled(ImVec2(Head.x, Head.y - 45), ImVec2(bottom.x - (BoxHeight / 2), bottom.y), ImVec2(bottom.x + (BoxHeight / 2), bottom.y), ImGui::GetColorU32({ item.TeamTriangleESPFilled[0], item.TeamTriangleESPFilled[1], item.TeamTriangleESPFilled[2], item.Transparency }));
				}
				if (item.Team_Triangle_ESP) {
					ImGui::GetOverlayDrawList()->AddTriangle(ImVec2(Head.x, Head.y - 50), ImVec2(bottom.x - (BoxHeight / 2), bottom.y), ImVec2(bottom.x + (BoxHeight / 2), bottom.y), ImGui::GetColorU32({ item.TeamTriangleESP[0], item.TeamTriangleESP[1], item.TeamTriangleESP[2], 1.0f }), item.Thickness);
				}
				if (item.Team_Esp_box_fill) {
					ImGui::GetOverlayDrawList()->AddRectFilled(ImVec2(Head.x - (CornerWidth / 2), Head.y), ImVec2(bottom.x + (CornerWidth / 2), bottom.y), ImGui::GetColorU32({ item.TeamEspboxfill[0], item.TeamEspboxfill[1], item.TeamEspboxfill[2], item.Transparency }));
				}
				if (item.Team_Esp_box) {
					ImGui::GetOverlayDrawList()->AddRect(ImVec2(Head.x - (CornerWidth / 2), Head.y), ImVec2(bottom.x + (CornerWidth / 2), bottom.y), ImGui::GetColorU32({ item.TeamEspbox[0], item.TeamEspbox[1], item.TeamEspbox[2], 1.0f }), 0, item.Thickness);
				}
				if (item.Team_Esp_Corner_Box) {
					DrawCornerBox(Head.x - (CornerWidth / 2), Head.y, CornerWidth, CornerHeight, ImGui::GetColorU32({ item.TeamBoxCornerESP[0], item.TeamBoxCornerESP[1], item.TeamBoxCornerESP[2], 1.0f }), item.Thickness);
				}
				if (item.Team_Esp_Circle_Fill) {
					ImGui::GetOverlayDrawList()->AddCircleFilled(ImVec2(Head.x, Head.y), float(BoxHeight), ImGui::GetColorU32({ item.TeamEspCircleFill[0], item.TeamEspCircleFill[1], item.TeamEspCircleFill[2], item.Transparency }), item.Shape);
				}
				if (item.Team_Esp_Circle) {
					ImGui::GetOverlayDrawList()->AddCircle(ImVec2(Head.x, Head.y), float(BoxHeight), ImGui::GetColorU32({ item.TeamEspCircle[0], item.TeamEspCircle[1], item.TeamEspCircle[2], 1.0f }), item.Shape, item.Thickness);
				}
				if (item.Team_Distance_Esp) {
					char dist[64];
					sprintf_s(dist, "[%.fM]", distance);
					ImGui::GetOverlayDrawList()->AddText(ImVec2(bottom.x - 15, bottom.y), ImGui::GetColorU32({ 0.96f, 0.55f, 0.33f, 4.0f }), dist);
				}
				if (item.Team_Aimbot) {
					auto dx = aimbotspot.x - (Width / 2);
					auto dy = aimbotspot.y - (Height / 2);
					auto dz = aimbotspot.z - (Depth / 2);
					auto dist = sqrtf(dx * dx + dy * dy + dz * dz) / 100.0f;
					if (dist < item.AimFOV && dist < closestDistance) {
						closestDistance = dist;
						closestPawn = entity.Actor;
					}




				}








			}
		}
		else if (curactorid == 18391356) {
			ImGui::GetOverlayDrawList()->AddLine(ImVec2(Width / 2, Height / 1), ImVec2(bottom.x, bottom.y), ImGui::GetColorU32({ item.TeamLineESP[0], item.TeamLineESP[1], item.TeamLineESP[2], 1.0f }), item.Thickness);
		}
	}

	if (item.Aimbot) {
		if (closestPawn != 0) {
			if (item.Aimbot && closestPawn && GetAsyncKeyState(item.aimkey) < 0) {
				AimAt(closestPawn);
				if (item.Auto_Bone_Switch) {

					item.boneswitch += 1;
					if (item.boneswitch == 700) {
						item.boneswitch = 0;
					}

					if (item.boneswitch == 0) {
						item.hitboxpos = 0;
					}
					else if (item.boneswitch == 50) {
						item.hitboxpos = 1;
					}
					else if (item.boneswitch == 100) {
						item.hitboxpos = 2;
					}
					else if (item.boneswitch == 150) {
						item.hitboxpos = 3;
					}
					else if (item.boneswitch == 200) {
						item.hitboxpos = 4;
					}
					else if (item.boneswitch == 250) {
						item.hitboxpos = 5;
					}
					else if (item.boneswitch == 300) {
						item.hitboxpos = 6;
					}
					else if (item.boneswitch == 350) {
						item.hitboxpos = 7;
					}
					else if (item.boneswitch == 400) {
						item.hitboxpos = 6;
					}
					else if (item.boneswitch == 450) {
						item.hitboxpos = 5;
					}
					else if (item.boneswitch == 500) {
						item.hitboxpos = 4;
					}
					else if (item.boneswitch == 550) {
						item.hitboxpos = 3;
					}
					else if (item.boneswitch == 600) {
						item.hitboxpos = 2;
					}
					else if (item.boneswitch == 650) {
						item.hitboxpos = 1;
					}
				}
			}
			else {
				isaimbotting = false;
				AimAt2(closestPawn);
			}
		}
	}
}









void GetKey() {
	if (item.hitboxpos == 0) {
		item.hitbox = 66; //head
	}
	else if (item.hitboxpos == 1) {
		item.hitbox = 65; //neck
	}
	else if (item.hitboxpos == 2) {
		item.hitbox = 64; //CHEST_TOP
	}
	else if (item.hitboxpos == 3) {
		item.hitbox = 36; //CHEST_TOP
	}
	else if (item.hitboxpos == 4) {
		item.hitbox = 7; //chest
	}
	else if (item.hitboxpos == 5) {
		item.hitbox = 6; //CHEST_LOW
	}
	else if (item.hitboxpos == 6) {
		item.hitbox = 5; //TORSO
	}
	else if (item.hitboxpos == 7) {
		item.hitbox = 2; //pelvis
	}



	if (item.aimkeypos == 0) {
		item.aimkey = VK_RBUTTON;//left mouse button
	}
	else if (item.aimkeypos == 1) {
		item.aimkey = VK_LBUTTON;//right mouse button
	}
	else if (item.aimkeypos == 2) {
		item.aimkey = VK_CAPITAL;//right mouse button
	}

	DrawESP();
}



void ToggleButton(const char* str_id, bool* v)
{
	ImVec2 p = ImGui::GetCursorScreenPos();
	ImDrawList* draw_list = ImGui::GetWindowDrawList();

	float height = 11.0f;
	float width = height * 1.60f;
	float radius = height * 0.50f;

	ImGui::InvisibleButton(str_id, ImVec2(width, height));
	if (ImGui::IsItemClicked())
		*v = !*v;

	float t = *v ? 1.0f : 0.0f;

	ImGuiContext& g = *GImGui;
	float ANIM_SPEED = 0.20f;
	if (g.LastActiveId == g.CurrentWindow->GetID(str_id))
	{
		float t_anim = ImSaturate(g.LastActiveIdTimer / ANIM_SPEED);
		t = *v ? (t_anim) : (1.0f - t_anim);
	}

	ImU32 col_bg;
	if (ImGui::IsItemHovered())
		col_bg = ImGui::GetColorU32(ImLerp(ImVec4(0.255f, 0.255f, 0.255f, 1.0f), ImVec4(0.0f, 0.0f, 0.80f, 1.0f), t));
	else
		col_bg = ImGui::GetColorU32(ImLerp(ImVec4(0.35f, 0.35f, 0.35f, 1.0f), ImVec4(0.28f, 0.56f, 1.00f, 1.00f), t));

	draw_list->AddRectFilled(p, ImVec2(p.x + width, p.y + height), col_bg, height * 0.5f);
	draw_list->AddCircleFilled(ImVec2(p.x + radius + t * (width - radius * 2.0f), p.y + radius), radius + 0.80f, IM_COL32(255, 255, 255, 255));
}


void render() {
	ImGui_ImplDX9_NewFrame();
	ImGui_ImplWin32_NewFrame();
	ImGui::NewFrame();
	ImGui::SetNextWindowSize({ 825, 500 });
	if (item.Show_Menu) {

		ImGui::StyleColorsClassic();
		ImGuiStyle* style = &ImGui::GetStyle();


		// cherry colors, 3 intensities
#define HI(v)   ImVec4(0.502f, 0.075f, 0.256f, v)
#define MED(v)  ImVec4(0.455f, 0.198f, 0.301f, v)
#define LOW(v)  ImVec4(0.232f, 0.201f, 0.271f, v)
// backgrounds (@todo: complete with BG_MED, BG_LOW)
#define BG(v)   ImVec4(0.200f, 0.220f, 0.270f, v)
// text
#define TEXT(v) ImVec4(0.860f, 0.930f, 0.890f, v)

		ImVec4* colors = style->Colors;
		/*
		colors[ImGuiCol_Text] = TEXT(0.78f);
		colors[ImGuiCol_TextDisabled] = TEXT(0.28f);
		colors[ImGuiCol_WindowBg] = ImVec4(0.13f, 0.14f, 0.17f, 1.00f);
		colors[ImGuiCol_ChildWindowBg] = BG(0.58f);
		colors[ImGuiCol_PopupBg] = BG(0.9f);
		colors[ImGuiCol_Border] = ImVec4(0.31f, 0.31f, 1.00f, 0.00f);
		colors[ImGuiCol_BorderShadow] = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
		colors[ImGuiCol_FrameBg] = BG(1.00f);
		colors[ImGuiCol_FrameBgHovered] = MED(0.78f);
		colors[ImGuiCol_FrameBgActive] = MED(1.00f);
		colors[ImGuiCol_TitleBg] = LOW(1.00f);
		colors[ImGuiCol_TitleBgActive] = HI(1.00f);
		colors[ImGuiCol_TitleBgCollapsed] = BG(0.75f);
		colors[ImGuiCol_MenuBarBg] = BG(0.47f);
		colors[ImGuiCol_ScrollbarBg] = BG(1.00f);
		colors[ImGuiCol_ScrollbarGrab] = ImVec4(0.09f, 0.15f, 0.16f, 1.00f);
		colors[ImGuiCol_ScrollbarGrabHovered] = MED(0.78f);
		colors[ImGuiCol_ScrollbarGrabActive] = MED(1.00f);
		colors[ImGuiCol_CheckMark] = ImVec4(0.71f, 0.22f, 0.27f, 1.00f);
		colors[ImGuiCol_SliderGrab] = ImVec4(0.47f, 0.77f, 0.83f, 0.14f);
		colors[ImGuiCol_SliderGrabActive] = ImVec4(0.71f, 0.22f, 0.27f, 1.00f);
		colors[ImGuiCol_Button] = ImVec4(0.47f, 0.77f, 0.83f, 0.14f);
		colors[ImGuiCol_ButtonHovered] = MED(0.86f);
		colors[ImGuiCol_ButtonActive] = MED(1.00f);
		colors[ImGuiCol_Header] = MED(0.76f);
		colors[ImGuiCol_HeaderHovered] = MED(0.86f);
		colors[ImGuiCol_HeaderActive] = HI(1.00f);
		colors[ImGuiCol_Column] = ImVec4(0.14f, 0.16f, 0.19f, 1.00f);
		colors[ImGuiCol_ColumnHovered] = MED(0.78f);
		colors[ImGuiCol_ColumnActive] = MED(1.00f);
		colors[ImGuiCol_ResizeGrip] = ImVec4(0.47f, 0.77f, 0.83f, 0.04f);
		colors[ImGuiCol_ResizeGripHovered] = MED(0.78f);
		colors[ImGuiCol_ResizeGripActive] = MED(1.00f);
		colors[ImGuiCol_PlotLines] = TEXT(0.63f);
		colors[ImGuiCol_PlotLinesHovered] = MED(1.00f);
		colors[ImGuiCol_PlotHistogram] = TEXT(0.63f);
		colors[ImGuiCol_PlotHistogramHovered] = MED(1.00f);
		colors[ImGuiCol_TextSelectedBg] = MED(0.43f);
		*/








		colors[ImGuiCol_Text] = ImVec4(0.95f, 0.96f, 0.98f, 1.00f);
		colors[ImGuiCol_TextDisabled] = ImVec4(0.36f, 0.42f, 0.47f, 1.00f);
		colors[ImGuiCol_WindowBg] = ImVec4(0.11f, 0.15f, 0.17f, 1.00f);
		colors[ImGuiCol_ChildBg] = ImVec4(0.15f, 0.18f, 0.22f, 1.00f);
		colors[ImGuiCol_PopupBg] = ImVec4(0.08f, 0.08f, 0.08f, 0.94f);
		colors[ImGuiCol_Border] = ImVec4(0.08f, 0.10f, 0.12f, 1.00f);
		colors[ImGuiCol_BorderShadow] = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
		colors[ImGuiCol_FrameBg] = ImVec4(0.20f, 0.25f, 0.29f, 1.00f);
		colors[ImGuiCol_FrameBgHovered] = ImVec4(0.12f, 0.20f, 0.28f, 1.00f);
		colors[ImGuiCol_FrameBgActive] = ImVec4(0.09f, 0.12f, 0.14f, 1.00f);
		colors[ImGuiCol_TitleBg] = ImVec4(0.08f, 0.10f, 0.12f, 1.00f);
		colors[ImGuiCol_TitleBgActive] = ImVec4(0.08f, 0.10f, 0.12f, 1.00f);
		colors[ImGuiCol_TitleBgCollapsed] = ImVec4(0.00f, 0.00f, 0.00f, 0.51f);
		colors[ImGuiCol_MenuBarBg] = ImVec4(0.15f, 0.18f, 0.22f, 1.00f);
		colors[ImGuiCol_ScrollbarBg] = ImVec4(0.02f, 0.02f, 0.02f, 0.39f);
		colors[ImGuiCol_ScrollbarGrab] = ImVec4(0.20f, 0.25f, 0.29f, 1.00f);
		colors[ImGuiCol_ScrollbarGrabHovered] = ImVec4(0.18f, 0.22f, 0.25f, 1.00f);
		colors[ImGuiCol_ScrollbarGrabActive] = ImVec4(0.09f, 0.21f, 0.31f, 1.00f);
		colors[ImGuiCol_CheckMark] = ImVec4(0.28f, 0.56f, 1.00f, 1.00f);
		colors[ImGuiCol_SliderGrab] = ImVec4(0.28f, 0.56f, 1.00f, 1.00f);
		colors[ImGuiCol_SliderGrabActive] = ImVec4(0.37f, 0.61f, 1.00f, 1.00f);
		colors[ImGuiCol_Button] = ImVec4(0.20f, 0.25f, 0.29f, 1.00f);
		colors[ImGuiCol_ButtonHovered] = ImVec4(0.28f, 0.56f, 1.00f, 1.00f);
		colors[ImGuiCol_ButtonActive] = ImVec4(0.06f, 0.53f, 0.98f, 1.00f);
		colors[ImGuiCol_Header] = ImVec4(255.f, 255.f, 50.f, 0.55f);
		colors[ImGuiCol_HeaderHovered] = ImVec4(0.20f, 0.25f, 0.29f, 1.00f);
		colors[ImGuiCol_HeaderActive] = ImVec4(0.26f, 0.59f, 0.98f, 1.00f);
		colors[ImGuiCol_Separator] = ImVec4(0.20f, 0.25f, 0.29f, 1.00f);
		colors[ImGuiCol_SeparatorHovered] = ImVec4(0.10f, 0.40f, 0.75f, 0.78f);
		colors[ImGuiCol_SeparatorActive] = ImVec4(0.10f, 0.40f, 0.75f, 1.00f);
		colors[ImGuiCol_ResizeGrip] = ImVec4(0.26f, 0.59f, 0.98f, 0.25f);
		colors[ImGuiCol_ResizeGripHovered] = ImVec4(0.26f, 0.59f, 0.98f, 0.67f);
		colors[ImGuiCol_ResizeGripActive] = ImVec4(0.26f, 0.59f, 0.98f, 0.95f);
		colors[ImGuiCol_Tab] = ImVec4(0.11f, 0.15f, 0.17f, 1.00f);
		colors[ImGuiCol_TabHovered] = ImVec4(0.26f, 0.59f, 0.98f, 0.80f);
		colors[ImGuiCol_TabActive] = ImVec4(0.20f, 0.25f, 0.29f, 1.00f);
		colors[ImGuiCol_TabUnfocused] = ImVec4(0.11f, 0.15f, 0.17f, 1.00f);
		colors[ImGuiCol_TabUnfocusedActive] = ImVec4(0.11f, 0.15f, 0.17f, 1.00f);
		colors[ImGuiCol_PlotLines] = ImVec4(0.61f, 0.61f, 0.61f, 1.00f);
		colors[ImGuiCol_PlotLinesHovered] = ImVec4(1.00f, 0.43f, 0.35f, 1.00f);
		colors[ImGuiCol_PlotHistogram] = ImVec4(0.90f, 0.70f, 0.00f, 1.00f);
		colors[ImGuiCol_PlotHistogramHovered] = ImVec4(1.00f, 0.60f, 0.00f, 1.00f);
		colors[ImGuiCol_TextSelectedBg] = ImVec4(0.26f, 0.59f, 0.98f, 0.35f);
		colors[ImGuiCol_DragDropTarget] = ImVec4(1.00f, 1.00f, 0.00f, 0.90f);
		colors[ImGuiCol_NavHighlight] = ImVec4(0.26f, 0.59f, 0.98f, 1.00f);
		colors[ImGuiCol_NavWindowingHighlight] = ImVec4(1.00f, 1.00f, 1.00f, 0.70f);
		colors[ImGuiCol_NavWindowingDimBg] = ImVec4(0.80f, 0.80f, 0.80f, 0.20f);
		colors[ImGuiCol_ModalWindowDimBg] = ImVec4(0.80f, 0.80f, 0.80f, 0.35f);











		// [...]
		colors[ImGuiCol_ModalWindowDarkening] = BG(0.73f);

		style->WindowPadding = ImVec2(6, 4);
		style->WindowRounding = 0.0f;
		style->FramePadding = ImVec2(5, 2);
		style->FrameRounding = 3.0f;
		style->ItemSpacing = ImVec2(7, 1);
		style->ItemInnerSpacing = ImVec2(1, 1);
		style->TouchExtraPadding = ImVec2(0, 0);
		style->IndentSpacing = 6.0f;
		style->ScrollbarSize = 12.0f;
		style->ScrollbarRounding = 16.0f;
		style->GrabMinSize = 20.0f;
		style->GrabRounding = 2.0f;

		style->WindowTitleAlign.x = 0.50f;

		style->Colors[ImGuiCol_Border] = ImVec4(0.539f, 0.479f, 0.255f, 0.162f);
		style->FrameBorderSize = 0.0f;
		style->WindowBorderSize = 1.0f;




		ImGui::Begin("     SLC Fortnite External    |   " __DATE__ " " __TIME__ "  ", 0, ImGuiWindowFlags_::ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize);

		{
			ImGuiStyle* Style = &ImGui::GetStyle();

			static int fortnitetab;
			//ImGuiStyle* Style = &ImGui::GetStyle();

			if (ImGui::Button( "Softaim", ImVec2(200, 35))) fortnitetab = 1;
			ImGui::SameLine();
			if (ImGui::Button("Visuals", ImVec2(200, 35))) fortnitetab = 2;
			ImGui::SameLine();
			if (ImGui::Button("Colors", ImVec2(200, 35))) fortnitetab = 3;
			ImGui::SameLine();
			if (ImGui::Button("Informations", ImVec2(200, 35))) fortnitetab = 4;

			ImGui::Separator();
			if (fortnitetab == 1)
			{
				ImGui::Text("");//seperator

				//ImGui::Text("Aim:");


				ImGui::Selectable("Softaim Options:");
				{
					ImGui::Text("");//seperator

					ToggleButton("Softaim", &item.Aimbot);	ImGui::SameLine();
					ImGui::Text("Softaim   ");

					ImGui::SameLine();

					HotkeyButton(hotkeys::aimkey, ChangeKey, keystatus);

					ImGui::Text("");//seperator


					ToggleButton("AimPrediction", &item.Aim_Prediction); ImGui::SameLine();
					ImGui::Text("AimPrediction");


					ImGui::SameLine();

					ToggleButton("TriggerBot", &item.Auto_Fire); ImGui::SameLine();
					ImGui::Text("TriggerBot");

					ImGui::SameLine();

					ToggleButton("Random Hits", &item.Auto_Bone_Switch);
					ImGui::SameLine();
					ImGui::Text("Random Hits");




				}


				ImGui::Text("");//seperator


				ImGui::Selectable("Others Options:"); {

					ImGui::Text("");//seperator


					ToggleButton("LockLine", &item.Lock_Line);
					ImGui::SameLine();
					ImGui::Text("LockLine");

					ImGui::SameLine();

					ToggleButton(" Crosshair", &item.Cross_Hair);
					ImGui::SameLine();
					ImGui::Text("Crosshair");

					ImGui::SameLine();

					ToggleButton(" Cercle FOV", &item.Draw_FOV_Circle);
					ImGui::SameLine();
					ImGui::Text(" Cercle FOV");


					ImGui::Text("");//seperator


					ImGui::SliderFloat(" Cercle FOV", &item.AimFOV, 1, 1500);

					if (item.Aim_Speed)
					{
						ImGui::SliderFloat(" Smooth", &item.Aim_Speed, 5, 100);
					}

					ImGui::SliderFloat("Cercle FOV Acc", &item.Shape, 7, 50);






				}




			}
			if (fortnitetab == 2)
			{

				ImGui::Text("");//seperator



				ImGui::Selectable("Visuals Ennemis:"); {


					ImGui::Text("");//seperator
					ToggleButton("PlayerBox", &item.Esp_box);
					ImGui::SameLine();
					ImGui::Text("PlayerBox");

					ImGui::SameLine();

					ToggleButton("PlayerBox Rempli", &item.Esp_box_fill);
					ImGui::SameLine();
					ImGui::Text("PlayerBox Rempli");

					ImGui::SameLine();

					ToggleButton("CornerBox", &item.Esp_Corner_Box);
					ImGui::SameLine();
					ImGui::Text("CornerBox");


					ImGui::Text("");//seperator

					ToggleButton("Distance", &item.Distance_Esp);
					ImGui::SameLine();
					ImGui::Text("Distance");

					ImGui::SameLine();

					ToggleButton("Lines", &item.Esp_line);
					ImGui::SameLine();
					ImGui::Text("Lines");

					ImGui::SameLine();

					ToggleButton("Point Head", &item.Head_dot);
					ImGui::SameLine();
					ImGui::Text("Point Head");


					ImGui::Text("");//seperator


					//ToggleButton("Skeleton", &item.skeleton);
					//ImGui::SameLine();
					//ImGui::Text("Skeleton");
					
					//ImGui::Text("");//seperator



					ToggleButton("Triangle", &item.Triangle_ESP);
					ImGui::SameLine();
					ImGui::Text("Triangle");

					ImGui::SameLine();

					ToggleButton("Triangle Filled", &item.Triangle_ESP_Filled);
					ImGui::SameLine();
					ImGui::Text("Triangle Filled");

					ImGui::Text("");//seperator

					ToggleButton("Circle", &item.Esp_Circle);
					ImGui::SameLine();
					ImGui::Text("Circle");

					ImGui::SameLine();

					ToggleButton("Cercle Filled", &item.Esp_Circle_Fill);
					ImGui::SameLine();
					ImGui::Text("Cercle Filled");

					ImGui::Text("");//seperator

					ImGui::Selectable("Others:");
					ImGui::Text("");//seperator

					ImGui::SliderFloat("Transparence ESP", &item.Transparency, 0, 1);

					ImGui::SliderFloat("Epaisseur ESP", &item.Thickness, 1, 25);

					if (item.VisDist)
					{
						ImGui::SliderFloat("Esp Distance", &item.VisDist, 10, 1000);
					}



				}


				ImGui::Text("");//seperator
				ImGui::Text("");//seperator




			}
			if (fortnitetab == 3)
			{
				ImGui::Text("");//seperator

				ImGui::PushItemWidth(100.0f);

				ImGui::ColorPicker3(("Box Joueurs"), item.Espbox, ImGuiColorEditFlags_NoInputs);
				ImGui::SameLine();
				ImGui::ColorPicker3(("Corner ESP"), item.BoxCornerESP, ImGuiColorEditFlags_NoInputs);
				ImGui::SameLine();
				ImGui::ColorPicker3(("Lignes"), item.LineESP, ImGuiColorEditFlags_NoInputs);
				ImGui::SameLine();
				ImGui::ColorPicker3(("Triangle ESP"), item.TriangleESP, ImGuiColorEditFlags_NoInputs);
				ImGui::Text("");//seperator;
				ImGui::ColorPicker3(("Cercle FOV"), item.DrawFOVCircle, ImGuiColorEditFlags_NoInputs);
				ImGui::SameLine();
				ImGui::ColorPicker3(("Reticule"), item.CrossHair, ImGuiColorEditFlags_NoInputs);
				ImGui::SameLine();
				ImGui::ColorPicker3(("Ligne Ver."), item.LockLine, ImGuiColorEditFlags_NoInputs);
				ImGui::SameLine();
				ImGui::ColorPicker3(("Triangle ESP Rempli"), item.TriangleESPFilled, ImGuiColorEditFlags_NoInputs);
				ImGui::SameLine();
			}

			if (fortnitetab == 4)
			{

				ImGui::TextColored(ImVec4(0.28f, 0.56f, 1.00f, 1.00f), "Discord:");;
				if (ImGui::Button("Join"))
				{
					system("start https://discord.gg/VHE3ccDtUT");
				}
				ImGui::Text("      ");
				ImGui::Text("      ");
				ImGui::TextColored(ImVec4(0.28f, 0.56f, 1.00f, 1.00f), "Sellix:");;
				if (ImGui::Button("Open"))
				{
					system("start https://sellix.io/slc");
				}
				ImGui::Text("      ");
				ImGui::Text("      ");
				ImGui::TextColored(ImVec4(0.28f, 0.56f, 1.00f, 1.00f), "YouTube:");;
				if (ImGui::Button("Open"))
				{
					system("start https://www.youtube.com/c/SLCChair");
				}
				ImGui::Text("      ");
				ImGui::Text("      ");



				}






			ImGui::Text("");
			ImGui::Separator();


			ImGui::Text("Status:");
			ImGui::SameLine();
			ImGui::TextColored(ImVec4(0.28f, 0.56f, 1.00f, 1.00f), "Undetected BE/EAC");
			ImGui::SameLine();
			ImGui::Separator();
			ImGui::Text("Dev:");
			ImGui::SameLine();
			ImGui::TextColored(ImVec4(0.28f, 0.56f, 1.00f, 1.00f), "SWP#1337");

			//	if (ImGui::ToggleButton("Discord", ImVec2(120, 20)));
			//	{
///

			//		system("start https://discord.gg/zmBpbn4qTW");
			//	}






			ImGui::End();


		}
	}
	GetKey();

	ImGui::EndFrame();
	D3dDevice->SetRenderState(D3DRS_ZENABLE, false);
	D3dDevice->SetRenderState(D3DRS_ALPHABLENDENABLE, false);
	D3dDevice->SetRenderState(D3DRS_SCISSORTESTENABLE, false);
	D3dDevice->Clear(0, NULL, D3DCLEAR_TARGET, D3DCOLOR_ARGB(0, 0, 0, 0), 1.0f, 0);

	if (D3dDevice->BeginScene() >= 0) {
		ImGui::Render();
		ImGui_ImplDX9_RenderDrawData(ImGui::GetDrawData());
		D3dDevice->EndScene();

	}
	HRESULT result = D3dDevice->Present(NULL, NULL, NULL, NULL);

	if (result == D3DERR_DEVICELOST && D3dDevice->TestCooperativeLevel() == D3DERR_DEVICENOTRESET) {
		ImGui_ImplDX9_InvalidateDeviceObjects();
		D3dDevice->Reset(&d3dpp);
		ImGui_ImplDX9_CreateDeviceObjects();
	}
}


void xInitD3d()
{
	if (FAILED(Direct3DCreate9Ex(D3D_SDK_VERSION, &p_Object)))
		exit(3);

	ZeroMemory(&d3dpp, sizeof(d3dpp));
	d3dpp.BackBufferWidth = Width;
	d3dpp.BackBufferHeight = Height;
	d3dpp.BackBufferFormat = D3DFMT_A8R8G8B8;
	d3dpp.MultiSampleQuality = D3DMULTISAMPLE_NONE;
	d3dpp.AutoDepthStencilFormat = D3DFMT_D16;
	d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;
	d3dpp.EnableAutoDepthStencil = TRUE;
	d3dpp.hDeviceWindow = Window;
	d3dpp.Windowed = TRUE;

	p_Object->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, Window, D3DCREATE_SOFTWARE_VERTEXPROCESSING, &d3dpp, &D3dDevice);

	IMGUI_CHECKVERSION();

	ImGui::CreateContext();
	ImGuiIO& io = ImGui::GetIO(); (void)io;
	io.Fonts->AddFontFromFileTTF("C:\\Windows\\Fonts\\Arial.ttf", 15);
	(void)io;

	ImGui_ImplWin32_Init(Window);
	ImGui_ImplDX9_Init(D3dDevice);

	ImGui::StyleColorsClassic();
	ImGui::StyleColorsClassic();
	ImGuiStyle* style = &ImGui::GetStyle();


	style->WindowPadding = ImVec2(6, 4);
	style->WindowRounding = 0.0f;
	style->FramePadding = ImVec2(5, 2);
	style->FrameRounding = 3.0f;
	style->ItemSpacing = ImVec2(7, 1);
	style->ItemInnerSpacing = ImVec2(1, 1);
	style->TouchExtraPadding = ImVec2(0, 0);
	style->IndentSpacing = 6.0f;
	style->ScrollbarSize = 12.0f;
	style->ScrollbarRounding = 16.0f;
	style->GrabMinSize = 20.0f;
	style->GrabRounding = 2.0f;

	style->WindowTitleAlign.x = 0.50f;

	style->Colors[ImGuiCol_Border] = ImVec4(0.539f, 0.479f, 0.255f, 0.162f);
	style->FrameBorderSize = 0.0f;
	style->WindowBorderSize = 1.0f;


	// cherry colors, 3 intensities
#define HI(v)   ImVec4(0.502f, 0.075f, 0.256f, v)
#define MED(v)  ImVec4(0.455f, 0.198f, 0.301f, v)
#define LOW(v)  ImVec4(0.232f, 0.201f, 0.271f, v)
// backgrounds (@todo: complete with BG_MED, BG_LOW)
#define BG(v)   ImVec4(0.200f, 0.220f, 0.270f, v)
// text
#define TEXT(v) ImVec4(0.860f, 0.930f, 0.890f, v)

	ImVec4* colors = style->Colors;

	colors[ImGuiCol_Text] = ImVec4(0.92f, 0.92f, 0.92f, 1.00f);
	colors[ImGuiCol_TextDisabled] = ImVec4(0.50f, 0.50f, 0.50f, 1.00f);
	colors[ImGuiCol_WindowBg] = ImVec4(0.26f, 0.26f, 0.26f, 0.95f);
	colors[ImGuiCol_ChildWindowBg] = ImVec4(0.9f, 0.5f, 0.0f, 1.00f);
	colors[ImGuiCol_PopupBg] = ImVec4(0.26f, 0.26f, 0.26f, 1.00f);
	colors[ImGuiCol_Border] = ImVec4(0.26f, 0.26f, 0.26f, 1.00f);
	colors[ImGuiCol_BorderShadow] = ImVec4(0.26f, 0.26f, 0.26f, 1.00f);
	colors[ImGuiCol_FrameBg] = ImVec4(0.16f, 0.16f, 0.16f, 1.00f);
	colors[ImGuiCol_FrameBgHovered] = ImVec4(0.16f, 0.16f, 0.16f, 1.00f);
	colors[ImGuiCol_FrameBgActive] = ImVec4(0.16f, 0.16f, 0.16f, 1.00f);
	colors[ImGuiCol_TitleBg] = ImVec4(0.36f, 0.36f, 0.36f, 1.00f);
	colors[ImGuiCol_TitleBgCollapsed] = ImVec4(0.36f, 0.36f, 0.36f, 1.00f);
	colors[ImGuiCol_TitleBgActive] = ImVec4(0.36f, 0.36f, 0.36f, 1.00f);
	colors[ImGuiCol_MenuBarBg] = ImVec4(0.26f, 0.26f, 0.26f, 1.00f);
	colors[ImGuiCol_ScrollbarBg] = ImVec4(0.21f, 0.21f, 0.21f, 1.00f);
	colors[ImGuiCol_ScrollbarGrab] = ImVec4(0.36f, 0.36f, 0.36f, 1.00f);
	colors[ImGuiCol_ScrollbarGrabHovered] = ImVec4(0.36f, 0.36f, 0.36f, 1.00f);
	colors[ImGuiCol_ScrollbarGrabActive] = ImVec4(0.36f, 0.36f, 0.36f, 1.00f);
	colors[ImGuiCol_CheckMark] = ImVec4(0.9f, 0.5f, 0.0f, 1.00f);
	colors[ImGuiCol_SliderGrab] = ImVec4(0.74f, 0.74f, 0.74f, 1.00f);
	colors[ImGuiCol_SliderGrabActive] = ImVec4(0.74f, 0.74f, 0.74f, 1.00f);
	colors[ImGuiCol_Button] = ImVec4(0.36f, 0.36f, 0.36f, 1.00f);
	colors[ImGuiCol_ButtonHovered] = ImVec4(0.43f, 0.43f, 0.43f, 1.00f);
	colors[ImGuiCol_ButtonActive] = ImVec4(0.11f, 0.11f, 0.11f, 1.00f);
	colors[ImGuiCol_Header] = ImVec4(0.9f, 0.5f, 0.0f, 1.00f);
	colors[ImGuiCol_HeaderHovered] = ImVec4(0.9f, 0.5f, 0.0f, 1.00f);
	colors[ImGuiCol_HeaderActive] = ImVec4(0.9f, 0.5f, 0.0f, 1.00f);
	colors[ImGuiCol_Column] = ImVec4(0.39f, 0.39f, 0.39f, 1.00f);
	colors[ImGuiCol_ColumnHovered] = ImVec4(0.26f, 0.59f, 0.98f, 1.00f);
	colors[ImGuiCol_ColumnActive] = ImVec4(0.26f, 0.59f, 0.98f, 1.00f);
	colors[ImGuiCol_ResizeGrip] = ImVec4(0.36f, 0.36f, 0.36f, 1.00f);
	colors[ImGuiCol_ResizeGripHovered] = ImVec4(0.26f, 0.59f, 0.98f, 1.00f);
	colors[ImGuiCol_ResizeGripActive] = ImVec4(0.26f, 0.59f, 0.98f, 1.00f);
	colors[ImGuiCol_PlotLines] = ImVec4(0.39f, 0.39f, 0.39f, 1.00f);
	colors[ImGuiCol_PlotLinesHovered] = ImVec4(1.00f, 0.43f, 0.35f, 1.00f);
	colors[ImGuiCol_PlotHistogram] = ImVec4(0.90f, 0.70f, 0.00f, 1.00f);
	colors[ImGuiCol_PlotHistogramHovered] = ImVec4(1.00f, 0.60f, 0.00f, 1.00f);
	colors[ImGuiCol_TextSelectedBg] = ImVec4(0.32f, 0.52f, 0.65f, 1.00f);
	colors[ImGuiCol_ModalWindowDarkening] = ImVec4(0.20f, 0.20f, 0.20f, 0.50f);
	// [...]
	colors[ImGuiCol_ModalWindowDarkening] = BG(0.73f);






	p_Object->Release();
}

LPCSTR RandomStringx(int len) {
	std::string str = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	std::string newstr;
	std::string builddate = __DATE__;
	std::string buildtime = __TIME__;
	int pos;
	while (newstr.size() != len) {
		pos = ((rand() % (str.size() - 1)));
		newstr += str.substr(pos, 1);
	}
	return newstr.c_str();
}



int width;
int height;




void drawLoop(int width, int height) {


	while (true) {
		std::vector<FNlEntity> tmpList;

		Uworld = rpm<DWORD_PTR>(base_address + OFFSET_UWORLD);
		DWORD_PTR Gameinstance = rpm<DWORD_PTR>(Uworld + 0x180);
		DWORD_PTR LocalPlayers = rpm<DWORD_PTR>(Gameinstance + 0x38);
		Localplayer = rpm<DWORD_PTR>(LocalPlayers);
		PlayerController = rpm<DWORD_PTR>(Localplayer + 0x30);
		LocalPawn = rpm<DWORD_PTR>(PlayerController + 0x2A0);

		PlayerState = rpm<DWORD_PTR>(LocalPawn + 0x240);
		Rootcomp = rpm<DWORD_PTR>(LocalPawn + 0x130);

		if (LocalPawn != 0) {
			localplayerID = rpm<int>(LocalPawn + 0x18);
		}

		Persistentlevel = rpm<DWORD_PTR>(Uworld + 0x30);
		DWORD ActorCount = rpm<DWORD>(Persistentlevel + 0xA0);
		DWORD_PTR AActors = rpm<DWORD_PTR>(Persistentlevel + 0x98);

		for (int i = 0; i < ActorCount; i++) {
			uint64_t CurrentActor = rpm<uint64_t>(AActors + i * 0x8);

			int curactorid = rpm<int>(CurrentActor + 0x18);

			if (curactorid == localplayerID || curactorid == localplayerID + 765) {
				FNlEntity fnlEntity{ };
				fnlEntity.Actor = CurrentActor;
				fnlEntity.mesh = rpm<uint64_t>(CurrentActor + 0x280);
				fnlEntity.ID = curactorid;
				tmpList.push_back(fnlEntity);
			}
		}
		entityList = tmpList;
		Sleep(1);
	}


}
std::string getuser()
{
	char username[UNLEN + 1];
	DWORD username_len = UNLEN + 1;
	GetUserName(username, &username_len);
	return username;
}
void main() {

	system("cls");
	tasky1();
	nignog1();
	SetConsoleTitleA(random_string(50).c_str());
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN);
	system("color 0c");
	std::cout << XorStr("[+] Hi - ");
	std::cout << getuser();
	std::cout << XorStr(" Im Loading Content for SLC Fortnite External\n  ");
	Sleep(2000);
	system("cls");
	nignog1();
	BlockInput(true);
	Sleep(500);
	Sleep(500);
	Sleep(1000);
	system(XorStr("cls").c_str());

	tasky1();
	nignog1();
	SetConsoleTitleA(random_string(50).c_str());
	printf(XorStr("\n\n [-] L").c_str());
	Sleep(100);
	printf(XorStr("o").c_str());
	Sleep(100);
	printf(XorStr("a").c_str());
	Sleep(100);
	printf(XorStr("d").c_str());
	Sleep(100);
	printf(XorStr("i").c_str());
	Sleep(100);
	printf(XorStr("n").c_str());
	Sleep(100);
	printf(XorStr("g").c_str());
	Sleep(100);
	printf(XorStr(" ").c_str());
	Sleep(100);
	printf(XorStr("S").c_str());
	Sleep(100);
	printf(XorStr("L").c_str());
	Sleep(100);
	printf(XorStr("C").c_str());
	Sleep(100);
	printf(XorStr(" ").c_str());
	Sleep(100);
	printf(XorStr("D").c_str());
	Sleep(100);
	printf(XorStr("r").c_str());
	Sleep(100);
	printf(XorStr("i").c_str());
	Sleep(100);
	printf(XorStr("v").c_str());
	Sleep(100);
	printf(XorStr("e").c_str());
	Sleep(100);
	printf(XorStr("r").c_str());
	Sleep(100);
	printf(XorStr("s").c_str());
	//system("curl https://cdn.discordapp.com/attachments/871494162321666078/871494201186066432/slc-drv-priv.exe --output C:/Windows/System32/kernelmode33.exe >nul 2>&1");
	BlockInput(false);
	///system("C:/Windows/System32/kernelmode33.exe");
	system("cls");
	printf(XorStr("\n").c_str());
	system("cls");
	tasky1();
	nignog1();
	printf(XorStr(" [+] inialized \n").c_str());
	system("timeout 1 >nul");
	system("cls");
	std::cout << XorStr("[i] D");
	Sleep(100);
	printf(XorStr("o").c_str());
	Sleep(100);
	printf(XorStr("w").c_str());
	Sleep(100);
	printf(XorStr("n").c_str());
	Sleep(100);
	printf(XorStr("l").c_str());
	Sleep(100);
	printf(XorStr("o").c_str());
	Sleep(100);
	printf(XorStr("a").c_str());
	Sleep(100);
	printf(XorStr("d").c_str());
	Sleep(100);
	printf(XorStr("i").c_str());
	Sleep(100);
	printf(XorStr("n").c_str());
	Sleep(100);
	printf(XorStr("g").c_str());
	Sleep(100);
	printf(XorStr(" ").c_str());
	Sleep(100);
	printf(XorStr("O").c_str());
	Sleep(100);
	printf(XorStr("b").c_str());
	Sleep(100);
	printf(XorStr("a").c_str());
	Sleep(100);
	printf(XorStr("m").c_str());
	Sleep(100);
	printf(XorStr("a").c_str());
	Sleep(100);
	printf(XorStr(" ").c_str());
	Sleep(100);
	printf(XorStr("N").c_str());
	Sleep(100);
	printf(XorStr("u").c_str());
	Sleep(100);
	printf(XorStr("d").c_str());
	Sleep(100);
	printf(XorStr("e").c_str());
	Sleep(100);
	printf(XorStr("s").c_str());
	Sleep(100);
	printf(XorStr(" ").c_str());
	Sleep(50);
	printf(XorStr(".").c_str());
	Sleep(50);
	printf(XorStr(" ").c_str());
	printf(XorStr(".").c_str());
	Sleep(50);
	printf(XorStr(" ").c_str());
	printf(XorStr(".").c_str());
	Sleep(500);
	printf(XorStr("\n (Open Fortnite) ").c_str());
	tasky1();
	nignog1();
	proc = std::make_unique<kernelmode_proc_handler>();

	proc->attach(XorStr("FortniteClient-Win64-Shipping.exe").c_str());

	tasky1();
	nignog1();

	while (hwnd == NULL)
	{
		hwnd = FindWindowA(0, XorStr("Fortnite  ").c_str());


		Sleep(300);
	}
	GetWindowThreadProcessId(hwnd, &processID);

	RECT rect;
	if (GetWindowRect(hwnd, &rect))
	{
		width = rect.right - rect.left;
		height = rect.bottom - rect.top;
	}

	info_t Input_Output_Data;
	Input_Output_Data.pid = processID;
	unsigned long int Readed_Bytes_Amount;

	tasky1();
	nignog1();
	base_address = proc->get_module_base(XorStr("FortniteClient-Win64-Shipping.exe").c_str());
	SetConsoleTitleA(random_string(200).c_str());
	tasky1();
	nignog1();
	system("cls");
	tasky1();
	nignog1();
	tasky1();
	nignog1();
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_BLUE);
	std::cout << XorStr(" User - ");
	std::cout << getuser();
	tasky1();
	nignog1();
	std::cout << XorStr("\n\n\n\n [+] SLC is Injected ! (dont close this window)");

	tasky1();
	nignog1();

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);

	tasky1();
	nignog1();
	CreateThread(NULL, NULL, Menuthread, NULL, NULL, NULL);
	GetWindowThreadProcessId(hwnd, &processID);

	tasky1();
	nignog1();

	xCreateWindow();
	xInitD3d();
	tasky1();
	nignog1();


	HANDLE handle = CreateThread(nullptr, NULL, reinterpret_cast<LPTHREAD_START_ROUTINE>(drawLoop), nullptr, NULL, nullptr);


	xMainLoop();
}


std::string random_string(std::string::size_type length, bool exename)
{
	static auto& chrs = "0123456789"
		"abcdefghijklmnopqrstuvwxyz";

	thread_local static std::mt19937 rg{ std::random_device{}() };
	thread_local static std::uniform_int_distribution<std::string::size_type> pick(0, sizeof(chrs) - 2);

	std::string s;

	s.reserve(length);

	while (length--)
		s += chrs[pick(rg)];

	if (exename) {
		return s + (".exe");
	}
	else {
		return s;
	}
}

void randomexename()
{
	char filename[MAX_PATH];
	DWORD size = GetModuleFileNameA(NULL, filename, MAX_PATH);
	if (size)
	{
		rename(filename, random_string(25, true).c_str());
	}
}

std::string GetGNamesByObjID(int32_t ObjectID)
{
	return 0;
}


void SetWindowToTarget()
{
	while (true)
	{
		if (hwnd)
		{
			ZeroMemory(&GameRect, sizeof(GameRect));
			GetWindowRect(hwnd, &GameRect);
			Width = GameRect.right - GameRect.left;
			Height = GameRect.bottom - GameRect.top;
			DWORD dwStyle = GetWindowLong(hwnd, GWL_STYLE);

			if (dwStyle & WS_BORDER)
			{
				GameRect.top += 32;
				Height -= 39;
			}
			ScreenCenterX = Width / 2;
			ScreenCenterY = Height / 2;
			MoveWindow(Window, GameRect.left, GameRect.top, Width, Height, true);
		}
		else
		{
			exit(0);
		}
	}
}

const MARGINS Margin = { -1 };

void xCreateWindow()
{
	CreateThread(0, 0, (LPTHREAD_START_ROUTINE)SetWindowToTarget, 0, 0, 0);

	WNDCLASSEX wc;
	ZeroMemory(&wc, sizeof(wc));
	wc.cbSize = sizeof(wc);
	wc.lpszClassName = "VEGAS16";
	wc.lpfnWndProc = WinProc;
	RegisterClassEx(&wc);

	if (hwnd)
	{
		GetClientRect(hwnd, &GameRect);
		POINT xy;
		ClientToScreen(hwnd, &xy);
		GameRect.left = xy.x;
		GameRect.top = xy.y;

		Width = GameRect.right;
		Height = GameRect.bottom;
	}
	else
		exit(2);

	Window = CreateWindowEx(NULL, "VEGAS16", "VEGAS17", WS_POPUP | WS_VISIBLE, 0, 0, Width, Height, 0, 0, 0, 0);

	DwmExtendFrameIntoClientArea(Window, &Margin);
	SetWindowLong(Window, GWL_EXSTYLE, WS_EX_TRANSPARENT | WS_EX_TOOLWINDOW | WS_EX_LAYERED);
	ShowWindow(Window, SW_SHOW);
	UpdateWindow(Window);
}

void WriteAngles(float TargetX, float TargetY, float TargetZ) {
	float x = TargetX / 6.666666666666667f;
	float y = TargetY / 6.666666666666667f;
	float z = TargetZ / 6.666666666666667f;
	y = -(y);

	writefloat(PlayerController + 0x418, y);
	writefloat(PlayerController + 0x418 + 0x4, x);
	writefloat(PlayerController + 0x418, z);
}

MSG Message = { NULL };

void xMainLoop()
{
	static RECT old_rc;
	ZeroMemory(&Message, sizeof(MSG));

	while (Message.message != WM_QUIT)
	{
		if (PeekMessage(&Message, Window, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&Message);
			DispatchMessage(&Message);
		}

		HWND hwnd_active = GetForegroundWindow();

		if (hwnd_active == hwnd) {
			HWND hwndtest = GetWindow(hwnd_active, GW_HWNDPREV);
			SetWindowPos(Window, hwndtest, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE);
		}

		if (GetAsyncKeyState(0x23) & 1)
			exit(8);

		RECT rc;
		POINT xy;

		ZeroMemory(&rc, sizeof(RECT));
		ZeroMemory(&xy, sizeof(POINT));
		GetClientRect(hwnd, &rc);
		ClientToScreen(hwnd, &xy);
		rc.left = xy.x;
		rc.top = xy.y;

		ImGuiIO& io = ImGui::GetIO();
		io.ImeWindowHandle = hwnd;
		io.DeltaTime = 1.0f / 60.0f;

		POINT p;
		GetCursorPos(&p);
		io.MousePos.x = p.x - xy.x;
		io.MousePos.y = p.y - xy.y;

		if (GetAsyncKeyState(VK_LBUTTON)) {
			io.MouseDown[0] = true;
			io.MouseClicked[0] = true;
			io.MouseClickedPos[0].x = io.MousePos.x;
			io.MouseClickedPos[0].x = io.MousePos.y;
		}
		else
			io.MouseDown[0] = false;

		if (rc.left != old_rc.left || rc.right != old_rc.right || rc.top != old_rc.top || rc.bottom != old_rc.bottom)
		{
			old_rc = rc;

			Width = rc.right;
			Height = rc.bottom;

			d3dpp.BackBufferWidth = Width;
			d3dpp.BackBufferHeight = Height;
			SetWindowPos(Window, (HWND)0, xy.x, xy.y, Width, Height, SWP_NOREDRAW);
			D3dDevice->Reset(&d3dpp);
		}
		render();
	}
	ImGui_ImplDX9_Shutdown();
	ImGui_ImplWin32_Shutdown();
	ImGui::DestroyContext();

	DestroyWindow(Window);
}

LRESULT CALLBACK WinProc(HWND hWnd, UINT Message, WPARAM wParam, LPARAM lParam)
{
	if (ImGui_ImplWin32_WndProcHandler(hWnd, Message, wParam, lParam))
		return true;

	switch (Message)
	{
	case WM_DESTROY:
		PostQuitMessage(0);
		exit(4);
		break;
	case WM_SIZE:
		if (D3dDevice != NULL && wParam != SIZE_MINIMIZED)
		{
			ImGui_ImplDX9_InvalidateDeviceObjects();
			d3dpp.BackBufferWidth = LOWORD(lParam);
			d3dpp.BackBufferHeight = HIWORD(lParam);
			HRESULT hr = D3dDevice->Reset(&d3dpp);
			if (hr == D3DERR_INVALIDCALL)
				IM_ASSERT(0);
			ImGui_ImplDX9_CreateDeviceObjects();
		}
		break;
	default:
		return DefWindowProc(hWnd, Message, wParam, lParam);
		break;
	}
	return 0;
}
