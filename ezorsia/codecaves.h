#pragma once
//tips:pushad and pushfd,  and, popad and popfd to push and pop all stack variables and flags to restore after

//my own load other wz file attempt //OMG working thanks to a check after CWvsApp::InitializeInput !!
const char* resmanLoadOrder[] = {  //suspecting resman load list is an array of const char* rather than a vector
"Character", //"Character"
"Mob", //"Mob"
"Skill", //"Skill"
"Reactor", //"Reactor"
"Npc", //"Npc"
"UI", //"UI"
"Quest", //"Quest"
"Item", //"Item"
"Effect", //"Effect"
"String", //"String"
"Etc", //"Etc"
"Morph", //"Morph"
"TamingMob", //"TamingMob"
"Sound", //"Sound"
"Map",  //Map"
"EzorsiaV2_UI"	//sneakily insert our wz file here and walk away
};
unsigned char resmanLoadAMNT = sizeof(resmanLoadOrder) / sizeof(resmanLoadOrder[0]) - 1;
__declspec(naked) void LoadUItwice() {
	__asm {
		mov     ebx, [eax * 4 + resmanLoadOrder]//mov     ebx, MainMain::resmanLoadOrder //mov     ebx, [ebp+eax*4+
		jmp dword ptr[dwLoadUItwiceRetn]
	}
}

//Expanded item

// Edit Foggy Set the isItemSlotIDover96 to ture if ID is over 96
DWORD getItemSlotRectNewRtn = 0x0081E2CD;
__declspec(naked) void getItemSlotRectNew()
{
	__asm {
		push ebp
		mov ebp, esp
		push ecx
		push ecx
		pushad
		pushfd
		mov eax, [ebp + 8]
		cmp eax, 60h
		setg byte ptr[isItemSlotIDover96]
		jle skip_sub
		sub eax, 60h
		mov[ebp + 8], eax
		skip_sub :
		popfd
			popad
			jmp getItemSlotRectNewRtn
	}
}
// Edit Foggy Drawing slots with ID over 96 with the same pos.x and higher pos.y as the slots with ID - 96
DWORD updateItemSlotRectValRtn = 0x0081E394;
DWORD updateItemSlotRectTemp = 0xFFFFFFFF;	// Temporary register
__declspec(naked) void updateItemSlotRectVal()
{
	__asm {
		mov dword ptr[updateItemSlotRectTemp], ebx
		mov bl, byte ptr[isItemSlotIDover96]
		test bl, bl
		jz sub_notOver1
		add edx, dword ptr[diffFullItemHeight]
		sub_notOver1 :
		push edx
			lea edx, dword ptr[ecx + 28h]
			push edx
			add eax, 32h
			test bl, bl
			jz sub_notOver2
			add eax, dword ptr[diffFullItemHeight]
			sub_notOver2 :
		push eax
			add ecx, 8
			push ecx
			mov ebx, dword ptr[updateItemSlotRectTemp]
			jmp updateItemSlotRectValRtn
	}
}
// Edit Foggy Drawing disabled icon on Item UI (unlocked slot)
DWORD itemSlotLimitExpandedARtn = 0x0081DF7A;
__declspec(naked) void itemSlotLimitExpandedA()
{
	__asm {
		cmp edx, 0xC0
		mov dword ptr[ebp + 8], edx
		jmp itemSlotLimitExpandedARtn
	}
}

// Edit Foggy Drawing disabled icon on Item UI (unlocked slot)
DWORD itemSlotLimitExpandedBRtn = 0x0081E025;
__declspec(naked) void itemSlotLimitExpandedB()
{
	__asm {
		inc dword ptr[ebp + 8]
		cmp dword ptr[ebp + 8], 0xC0
		jmp itemSlotLimitExpandedBRtn
	}
}
DWORD itemSlotLimitExpandedCRtn = 0x0081DBE6;
__declspec(naked) void itemSlotLimitExpandedC()
{
	__asm {
		push 0xC1
		pop ebx
		jmp itemSlotLimitExpandedCRtn
	}
}
DWORD itemSlotLimitExpandedD1Rtn = 0x004B1634;
__declspec(naked) void itemSlotLimitExpandedD1()
{
	__asm {
		cmp eax, 0xC0
		setle bl
		jmp itemSlotLimitExpandedD1Rtn
	}
}
DWORD itemSlotLimitExpandedD2Rtn = 0x004B165C;
__declspec(naked) void itemSlotLimitExpandedD2()
{
	__asm {
		cmp eax, 0xC0
		setle bl
		jmp itemSlotLimitExpandedD2Rtn
	}
}
DWORD itemSlotLimitExpandedD3Rtn = 0x004B1684;
__declspec(naked) void itemSlotLimitExpandedD3()
{
	__asm {
		cmp eax, 0xC0
		setle bl
		jmp itemSlotLimitExpandedD3Rtn
	}
}
DWORD itemSlotLimitExpandedD4Rtn = 0x004B16A9;
__declspec(naked) void itemSlotLimitExpandedD4()
{
	__asm {
		cmp esi, 0xC0
		setle dl
		jmp itemSlotLimitExpandedD4Rtn
	}
}
DWORD itemSlotLimitExpandedERtn = 0x0047AA74;
__declspec(naked) void itemSlotLimitExpandedE()
{
	__asm {
		cmp ebx, 0xC0
		jle skip_sub
		push eax
		mov eax, 0x0047AAD1
		mov dword ptr[itemSlotLimitExpandedERtn], eax
		pop eax
		skip_sub :
		jmp itemSlotLimitExpandedERtn
	}
}
DWORD itemSlotLimitExpandedFRtn = 0x00470917;
__declspec(naked) void itemSlotLimitExpandedF()
{
	__asm {
		add ecx, eax
		cmp ecx, 0xC0
		jmp itemSlotLimitExpandedFRtn
	}
}
DWORD itemSlotLimitExpandedGRtn = 0x0081D34B;
__declspec(naked) void itemSlotLimitExpandedG()
{
	__asm {
		cmp eax, 0xC0
		jge skip_sub
		push eax
		mov eax, 0x0081D35A
		mov dword ptr[itemSlotLimitExpandedGRtn], eax
		pop eax
		skip_sub :
		jmp itemSlotLimitExpandedGRtn
	}
}
DWORD itemSlotLimitExpandedHRtn = 0x00470917;
__declspec(naked) void itemSlotLimitExpandedH()
{
	__asm {
		add ecx, eax
		cmp ecx, 0xC0
		jmp itemSlotLimitExpandedHRtn
	}
}
DWORD itemSlotLimitExpandedIRtn = 0x0046C2E0;
__declspec(naked) void itemSlotLimitExpandedI()
{
	__asm {
		add eax, 3
		cmp eax, 0xC0
		jmp itemSlotLimitExpandedIRtn
	}
}
DWORD CUIItemCoinPosYRtn = 0x0081DD64;
__declspec(naked) void CUIItemCoinPosY()
{
	__asm {
		cmp dword ptr[ebx + 604h], 0
		jz skip_isSmallItem
		mov eax, dword ptr[diffFullItemHeight]
		add eax, 0x10A
		push eax
		mov eax, esp
		jmp skip_step
		skip_isSmallItem :
		push 0x10A
			skip_step :
			jmp CUIItemCoinPosYRtn
	}
}
DWORD CUIItemBtCoinPosYRtn = 0x0081CD6C;
__declspec(naked) void CUIItemBtCoinPosY()
{
	__asm {
		cmp dword ptr[esi + 604h], 0
		jz skip_isSmallItem
		mov ebx, dword ptr[diffFullItemHeight]
		add ebx, 0x10A
		push ebx
		xor ebx, ebx
		jmp skip_step
		skip_isSmallItem :
		push 0x10A
			skip_step :
			jmp CUIItemBtCoinPosYRtn
	}
}


// Double Jump Mechanics - Ezorsia V2

// Part 1: Evaluate Jump State
extern "C" int jumpCount = 0;
const void* dblJumpFalse = reinterpret_cast<void*>(0x009B2139);
const void* jumpReturnAddress = reinterpret_cast<void*>(0x009B204B);
const void* proceedDoubleJump = reinterpret_cast<void*>(0x009B2053);

__declspec(naked) void evaluateHasJumped() {
	__asm {
		pushfd
		pushad
		cmp[jumpCount], 1
		je goToEnd

		popad
		popfd
		jmp[proceedDoubleJump]
		goToEnd:
		popad
			popfd
			jmp[dblJumpFalse]
	}
}

// Part 2: Jump Physics
extern "C" const double jumpMult = 2.5;
const void* firstCall = reinterpret_cast<void*>(0x006724FC);
const void* continueAddress = reinterpret_cast<void*>(0x009B211C);
const void* fixed_call = reinterpret_cast<void*>(0x00BEBFA0);

__declspec(naked) void jumpPhysics() {
	__asm {
		mov eax, [esi + 424] // 1A8h
		lea ecx, [eax + 6Ch] // 84h
		call firstCall
		mov eax, [fixed_call]
		mov eax, dword ptr[eax]
		mov eax, [eax + 8]
		fmul qword ptr[eax + 72]
		fmul qword ptr[ebp - 32]
		fmul[jumpMult]
		inc dword ptr[jumpCount]
		jmp continueAddress
	}
}

// Part 3: Clear Jump Count
const int push_val = 2273;
const void* onGroundJumpProceed = reinterpret_cast<void*>(0x009B201D);

__declspec(naked) void clearJumps() {
	__asm {
		lea eax, [ebp - 18h]
		push[push_val]
		mov dword ptr[jumpCount], 0
		jmp[onGroundJumpProceed]
	}
}

int nStatusBarY = 0;
__declspec(naked) void AdjustStatusBar() {
	__asm {
		push nStatusBarY
		push ebx // horizontal position; 0
		mov ecx, esi
		jmp dword ptr[dwStatusBarPosRetn]
	}
}

// Disable Auto Assign Button
DWORD autoAssign_ret = 0x008C5926;
__declspec(naked) void autoAssignRemove()
{
	_asm {
		lea ecx, [eax + 4]
		mov eax, [ecx]
		push 0
		jmp autoAssign_ret
	}
}

// World Map to middle of screen
int wordMapX, wordMapY;
DWORD wordMapUIccRtn = 0x009EB5A1;
__declspec(naked) void wordMapUIcc()
{
	__asm {
		push 20Ch
		push 29Ah
		push wordMapY
		push wordMapX
		jmp wordMapUIccRtn
	}
}

//Long skillbar
DWORD Array_aDefaultQKM_Address = (DWORD)&Array_aDefaultQKM;
DWORD Array_mystery_Address = (DWORD)&Array_Expanded;
DWORD Array_mystery_Address_plus = (DWORD)&Array_Expanded + 1;
DWORD cooldown_Array_Address = (DWORD)&cooldown_Array;

DWORD CompareValidate_Retn = 0x8DD8BD;
_declspec(naked) void CompareValidateFuncKeyMappedInfo_cave()
{
	_asm
	{
		push 0x138;
		push 0x0;
		push eax;
		pushad;
		popad;
		jmp CompareValidate_Retn
			//push 0x8DD8BD;
			//ret;
	}
}

DWORD sub_9FA0CB_cave_retn_1 = 0x9FA0E1;
_declspec(naked) void sub_9FA0CB_cave()
{
	_asm {
		test eax, eax;
		jne label;
		push 0xD4;
		pushad;
		popad;
		// -> ZAllocEx<ZAllocAnonSelector>::Alloc(ZAllocEx<ZAllocAnonSelector>::_s_alloc, 0x44u);
		//push 0x9FA0E1;
		//ret;
		jmp sub_9FA0CB_cave_retn_1
			label :
		push 0x138;
		push 0x0;
		push eax;
		pushad;
		popad;
		// -> memset(this + 0xD20, 0, 0x60u);
		//push 0x8DD8BD;
		//ret;
		jmp CompareValidate_Retn
	}
}
//DWORD sDefaultQuickslotKeyMap_cave_retn = 0x72B7C2;
_declspec(naked) void sDefaultQuickslotKeyMap_cave()
{
	_asm {
		push ebx;
		push esi;
		push edi;
		xor edx, edx;
		mov ebx, ecx;
		call label;
		nop;
		lea edi, dword ptr ds : [ebx + 0x4] ;
		mov ecx, 0x1A;
		mov esi, Array_aDefaultQKM_Address;
		rep movsd;
		lea edi, dword ptr ds : [ebx + 0x6C] ;
		mov ecx, 0x1A;
		mov esi, Array_aDefaultQKM_Address;
		rep movsd;
		pop edi;
		pop esi;
		pop ebx;
		ret;
		// 0xBF8EE8
	label:
		push esi;
		mov esi, ecx;
		lea eax, dword ptr ds : [esi + 0x4] ;
		// -> _DWORD *__fastcall sub_72B7BC(_DWORD *a1)
		push 0x72B7C2;
		ret;
		//jmp sDefaultQuickslotKeyMap_cave_retn
	}
}
_declspec(naked) void DefaultQuickslotKeyMap_cave()
{
	_asm {
		push esi;
		push edi;
		lea eax, dword ptr ds : [ecx + 0x4] ;
		mov esi, Array_aDefaultQKM_Address;
		mov ecx, 0x1A;
		mov edi, eax;
		rep movsd;
		pop edi;
		pop esi;
		ret;
	}
}

// LTRB Handling for Bullet Skills
DWORD dwFireArrow = 0x00955DA8;
DWORD dwFireArrowRet = 0x00955DAD;
DWORD dwFireSucc = 0x00956372;
__declspec(naked) void FireArrow() {
	__asm {

		cmp eax, 2101005 // Poison Breath
		je success
		cmp eax, 2301005 // Holy Ray
		je success
		cmp eax, 4101006 // Shuriken MAX
		je success
		cmp eax, 3201005 // Iron Arrow
		je success
		cmp eax, 0x0021E3CB
		jmp dwFireArrowRet
		success :
		jmp dwFireSucc
	}
}

// LTRB Handling for Bullet Skills
DWORD dwFireBulletAdd = 0x00956445;
DWORD dwFireBulletSucc = 0x0095645B;
DWORD dwFireBulletRet = 0x0095644E;
__declspec(naked) void FireArrowBullet() {
	__asm {
		cmp dword ptr[ebp - 0x14], 2101005 // Poison Breath
		je success
		cmp dword ptr[ebp - 0x14], 2301005 // Holy Ray
		je success
		cmp dword ptr[ebp - 0x14], 4101006 // Shuriken MAX
		je success
		cmp dword ptr[ebp - 0x14], 3201005 // Iron Arrow
		je success
		jmp dwFireBulletRet
		success :
		jmp dwFireBulletSucc
	}
}


// Reduced CD: Recoil Shot
DWORD dwRecoilShot = 0x00953646;
DWORD dwRecoilShotRet = 0x0095364D;
DWORD dwRecoilShotSucc = 0x00953669;
__declspec(naked) void RecoilShotLowerCD() {
	__asm {
		cmp eax, 5201006
		je success
		jmp dwRecoilShotRet
		success :
		mov eax, 100//700 //originally 2000ms
			jmp dwRecoilShotSucc
	}
}


// Remove Charge: Big Bang Bishop
DWORD dwBB = 0x00967ECC;
DWORD dwBBReturn = 0x00967ED2;
DWORD dwBBS = 0x0096928B;
__declspec(naked) void BigBang() {
	__asm
	{
		je BBS
		jmp dword ptr[dwBBReturn]
		BBS:
		jmp dword ptr[dwBBS]
	}
}


// Remove Charge: Big Bang IL
DWORD dwBB2 = 0x00967DEE;
DWORD dwBB2Return = 0x00967DF4;
DWORD dwBBS2 = 0x0096928B;
__declspec(naked) void BigBang2() {
	__asm
	{
		je BBS2
		jmp dword ptr[dwBB2Return]
		BBS2:
		jmp dword ptr[dwBBS2]
	}
}

// Remove Charge: Big Bang FP
DWORD dwBB3 = 0x00967D10;
DWORD dwBB3Return = 0x00967D16;
DWORD dwBBS3 = 0x0096928B;
__declspec(naked) void BigBang3() {
	__asm
	{
		je BBS3
		jmp dword ptr[dwBB3Return]
		BBS3:
		jmp dword ptr[dwBBS3]
	}
}

// Remove Charge: Piercing Arrow
DWORD dwPA = 0x00968048;
DWORD dwPAReturn = 0x00967B8B;
DWORD dwPAS = 0x009690E9;
__declspec(naked) void PA() {
	__asm {
		je PAS
		jmp dword ptr[dwPAReturn]
		PAS:
		jmp dword ptr[dwPAS]
	}
}

// Remove Charge: Corkscrew Blow
DWORD dwCB = 0x00968278;
DWORD dwCBReturn = 0x00967B8B;
DWORD dwCBS = 0x009690AE;
__declspec(naked) void CorkscrewBlow() {
	__asm {
		je CBS
		jmp dword ptr[dwCBReturn]
		CBS:
		jmp dword ptr[dwCBS]
	}
}

// Fix Mouse Scroll Issue
DWORD fixMouseWheelAddr = 0x009E8090;
DWORD fixMouseWheelRetJmpAddr = 0x009E809F;
DWORD SetCursorVectorPos = 0x0059A0CB;
__declspec(naked) void fixMouseWheelHook() {
	__asm {
		// is mouse wheel
		cmp eax, 522
		je[halo3]
		mov eax, dword ptr[edi]
		shr eax, 0x10
		push eax
		movzx eax, word ptr[edi]
		push eax
		call SetCursorVectorPos
		halo3 :
		jmp[fixMouseWheelRetJmpAddr]
	}
}

// Align Chat Box Text
DWORD chat_Y_offset_retn = 0x008DD6BE;
DWORD call_func_chat_cave = 0x00403382;
__declspec(naked) void chat_Y_offset_cave()
{
	_asm {
		call call_func_chat_cave
		push eax
		mov eax, [ebp - 28h]
		dec eax
		mov[ebp - 28h], eax
		pop eax
		jmp chat_Y_offset_retn
	}
}

// Align Monster Book Text
DWORD pos1Rtn = 0x0086437D;
DWORD pos2Rtn = 0x0086449A;
DWORD pos3Rtn = 0x008645B9;
__declspec(naked) void pos1()
{
	__asm {
		push 146
		sub eax, edi
		push eax
		jmp pos1Rtn
	}
}
__declspec(naked) void pos2()
{
	__asm {
		push 180
		sub eax, edi
		push eax
		jmp pos2Rtn
	}
}
__declspec(naked) void pos3()
{
	__asm {
		push 200
		sub eax, edi
		push eax
		jmp pos3Rtn
	}
}



__declspec(naked) void AdjustStatusBarBG() {
	__asm {
		push nStatusBarY
		movsd
		push 0
		jmp dword ptr[dwStatusBarBackgroundPosRetn]
	}
}

__declspec(naked) void AdjustStatusBarInput() {
	__asm {
		push nStatusBarY
		push edi
		lea ecx, [esi + 0x0CD0]
		jmp dword ptr[dwStatusBarInputPosRetn]
	}
}

__declspec(naked) void PositionLoginDlg() {
	__asm {
		push 0x000000B4
		push 400
		push - 48	// y
		push - 185	// x
		jmp dword ptr[dwLoginCreateDlgRtn]
	}
}
__declspec(naked) void PositionLoginUsername() {
	__asm {
		push 0x0F
		push 0x00000084
		push 127	// y
		push 0		// x
		jmp dword ptr[dwLoginUsernameRtn]
	}
}

_declspec(naked) void ExceptionList_BackButton_CodeCave()
{
	_asm {
		push 1
		push 5 //Y (from top)
		push 162 //X

		push 0x008FC6DC
		retn
	}
}
_declspec(naked) void ExceptionList_MesoButton_CodeCave()
{
	_asm {
		push 1
		push 179 //Y
		push 100 //X (from 10)

		push 0x008FC75C
		retn
	}
}
_declspec(naked) void ExceptionList_RegisterButton_CodeCave()
{
	_asm {
		push 1
		push 179 //Y
		push 133 //X (from 80)

		push 0x008FC7DC
		retn
	}
}
_declspec(naked) void ExceptionList_DeleteButton_CodeCave()
{
	_asm {
		push 1
		push 179 //Y
		push 10 //X (from 124)

		push 0x008FC85F
		retn
	}
}
_declspec(naked) void ExceptionList_Scrollbar_CodeCave()
{
	_asm {
		push 148 //vertical length
		push 25
		push 161
		push 3
		push 1

		push 0x008FC8AF
		retn
	}
}

__declspec(naked) void PositionLoginPassword() {
	__asm {
		push 0x0F
		push 0x78
		push 127	// y
		push 272	// x
		jmp dword ptr[dwLoginPasswordRtn]
	}
}
__declspec(naked) void PositionBossBarY() {
	__asm {	//finally working!, originally posted by Angxl
		//push 22	//modification
		push edi	//part of original memory
		push dword ptr ss : [ebp - 68]	//part of original memory
		lea eax, dword ptr ss : [ebp - 32]	//part of original memory
		jmp dword ptr[dwBossBarRetn]
	}
}
__declspec(naked) void PositionBossBarY1() {
	__asm {	//finally working!, originally posted by Angxl
		push 22	//modification
		//push edi	//part of original memory
		push dword ptr ss : [ebp - 68]	//part of original memory
		lea eax, dword ptr ss : [ebp - 32]	//part of original memory
		jmp dword ptr[dwBossBarRetn]
	}
}

int serverMessageExists;
__declspec(naked) void PositionBossBarY2() {
	__asm {
		mov esi, eax
		and dword ptr ss : [ebp - 4] , 0
		mov serverMessageExists, esi
		jmp dword ptr[dwBossBarRetn2]
	}
}

int myHeight = -(Client::m_nGameHeight - 600) / 2;
int myWidth = -(Client::m_nGameWidth - 800) / 2;

__declspec(naked) void CashShopFix() {
	__asm {
		push    eax //vCanvas //originally posted by shavitash		//fixed
		push    ebx //nZ
		push    ebx //uHeight
		push    ebx //uWidth
		push	myHeight//84//myHeight //nTop - do the math yourself, this wont compile obviously
		push	myWidth//283//myWidth //nLeft - same as above
		jmp dword ptr[dwCashFixRtm]
	}
}

int nHeightOfsetted1 = 0; int nWidthOfsetted1 = 0; int nTopOfsetted1 = 0; int nLeftOfsetted1 = 0;
int nHeightOfsetted2 = 0; int nWidthOfsetted2 = 0; int nTopOfsetted2 = 0; int nLeftOfsetted2 = 0;
int nHeightOfsetted3 = 0; int nWidthOfsetted3 = 0; int nTopOfsetted3 = 0; int nLeftOfsetted3 = 0;
int nHeightOfsetted4 = 0; int nWidthOfsetted4 = 0; int nTopOfsetted4 = 0; int nLeftOfsetted4 = 0;
int nHeightOfsetted5 = 0; int nWidthOfsetted5 = 0; int nTopOfsetted5 = 0; int nLeftOfsetted5 = 0;
int nHeightOfsetted6 = 0; int nWidthOfsetted6 = 0; int nTopOfsetted6 = 0;
int nHeightOfsetted7 = 0; int nWidthOfsetted7 = 0; int nTopOfsetted7 = 0; int nLeftOfsetted7 = 0;
int nHeightOfsetted8 = 0; int nWidthOfsetted8 = 0; int nTopOfsetted8 = 0; int nLeftOfsetted8 = 0;

__declspec(naked) void CashShopFix1() {
	__asm {
		push	nHeightOfsetted1
		push	nWidthOfsetted1
		push	nTopOfsetted1
		push	nLeftOfsetted1
		jmp dword ptr[dwCashFix1Rtm]
	}
}

__declspec(naked) void CashShopFix2() {
	__asm {
		push	nHeightOfsetted2
		push	nWidthOfsetted2
		push	nTopOfsetted2
		push	nLeftOfsetted2
		jmp dword ptr[dwCashFix2Rtm]
	}
}

__declspec(naked) void CashShopFix3() {
	__asm {
		push	nHeightOfsetted3
		push	nWidthOfsetted3
		push	nTopOfsetted3
		push	nLeftOfsetted3
		jmp dword ptr[dwCashFix3Rtm]
	}
}

__declspec(naked) void CashShopFix4() {
	__asm {
		push	nHeightOfsetted4
		push	nWidthOfsetted4
		push	nTopOfsetted4
		push	nLeftOfsetted4
		jmp dword ptr[dwCashFix4Rtm]
	}
}

__declspec(naked) void CashShopFix5() {
	__asm {
		push	nHeightOfsetted5
		push	nWidthOfsetted5
		push	nTopOfsetted5
		push	nLeftOfsetted5
		jmp dword ptr[dwCashFix5Rtm]
	}
}

__declspec(naked) void CashShopFix6() {
	__asm {
		push	nHeightOfsetted6
		push	nWidthOfsetted6
		push	nTopOfsetted6
		jmp dword ptr[dwCashFix6Rtm]
	}
}

__declspec(naked) void CashShopFix7() {
	__asm {
		push	nHeightOfsetted7
		push	nWidthOfsetted7
		push	nTopOfsetted7
		push	nLeftOfsetted7
		jmp dword ptr[dwCashFix7Rtm]
	}
}

__declspec(naked) void CashShopFix8() {
	__asm {
		push	nHeightOfsetted8
		push	nWidthOfsetted8
		push	nTopOfsetted8
		push	nLeftOfsetted8
		jmp dword ptr[dwCashFix8Rtm]
	}
}

__declspec(naked) void CashShopFixOnOff() {	//could be improved upon because idk if it's the right way to do it or if it might cause issues
	__asm {
		pop	ebx
		push ecx
		mov ecx, dword ptr[dwCashFixOnOffCall]
		call ecx
		add esp, 4
		leave
		retn    4
	}
}

int nHeightOfsettedPrev = 0; int nWidthOfsettedPrev = 0; int nTopOfsettedPrev = 0; int nLeftOfsettedPrev = 0;

__declspec(naked) void CashShopFixPrev() {
	__asm {
		push	nHeightOfsettedPrev
		push	nWidthOfsettedPrev
		push	nTopOfsettedPrev
		push	nLeftOfsettedPrev
		jmp dword ptr[dwCashFixPrevRtm]
	}
}

int nTopOfsettedVerFix = 0; int nLeftOfsettedVerFix = 0;

__declspec(naked) void VersionNumberFix() {
	__asm {
		mov    eax, nLeftOfsettedVerFix
		sub    eax, DWORD PTR[ebp - 0x1c]
		push	nTopOfsettedVerFix
		jmp dword ptr[dwVersionNumberFixRtm]
	}
}

int myAlwaysViewRestoreFixOffset = 0;

__declspec(naked) void AlwaysViewRestoreFix() {
	__asm {
		test	eax, eax
		jnz C_Dest
		mov ecx, myAlwaysViewRestoreFixOffset
		push myAlwaysViewRestoreFixOffset
		jmp dword ptr[dwAlwaysViewRestorerFixRtm]
		C_Dest:
		mov ecx, DWORD PTR[eax]
		push eax
		jmp dword ptr[dwAlwaysViewRestorerFixRtm]
	}
}

//int nHeightOfsettedloginFrameFix = 0; int nWidthOfsettedloginFrameFix = 0;
//int nTopOfsettedloginFrameFix = 0; int nLeftOfsettedloginFrameFix = 0;

//__declspec(naked) void loginFrameFix() {
//	__asm {
//		pop ebx
////		push 1
//		push 0
//		push 1
//		push	nHeightOfsettedloginFrameFix
//		push	nWidthOfsettedloginFrameFix
//		push	nTopOfsettedloginFrameFix
//		push	nLeftOfsettedloginFrameFix
//		push esi
//		call dword ptr[dwloginFrameFixCall]
//		add esp, 4
//		leave
//		retn 4
//	}
//}

int nHeightOfsettedLoginBackCanvasFix = 0; int nWidthOfsettedLoginBackCanvasFix = 0;
int nTopOfsettedLoginBackCanvasFix = 0; int nLeftOfsettedLoginBackCanvasFix = 0;

__declspec(naked) void ccLoginBackCanvasFix() {
	__asm {
		push	nHeightOfsettedLoginBackCanvasFix
		push	nWidthOfsettedLoginBackCanvasFix
		push	nTopOfsettedLoginBackCanvasFix
		push	nLeftOfsettedLoginBackCanvasFix
		jmp dword ptr[dwLoginBackCanvasFixRetn]
	}
}

int nHeightOfsettedLoginViewRecFix = 0; int nWidthOfsettedLoginViewRecFix = 0;
int nTopOfsettedLoginViewRecFix = 0; int nLeftOfsettedLoginViewRecFix = 0;

__declspec(naked) void ccLoginViewRecFix() {
	__asm {
		push	nHeightOfsettedLoginViewRecFix
		push	nWidthOfsettedLoginViewRecFix
		push	nTopOfsettedLoginViewRecFix
		push	nLeftOfsettedLoginViewRecFix
		jmp dword ptr[dwLoginViewRecFixRetn]
	}
}

int yOffsetOfLoginBackBtnFix = 0; int xOffsetOfLoginBackBtnFix = 0;

__declspec(naked) void ccLoginBackBtnFix() {	//un used
	__asm {
		mov    esi, yOffsetOfLoginBackBtnFix
		push	esi
		mov    edi, xOffsetOfLoginBackBtnFix
		push	edi
		push   0x3e8
		jmp dword ptr[dwLoginBackBtnFixRetn]
	}
}

int a1x = 0; int a2x = 0; int a2y = 0; int a3 = 0; int a1y = 0; 

__declspec(naked) void ccLoginDescriptorFix() {
	__asm {
		and	edx, 0x3f
		add    edx, 0x21
		add    edx, a2y
		cmp     ecx, edi
		setl   bl
		mov     ecx, esi
		mov    DWORD PTR[esi + 0x4], 0xaf7084
		mov    DWORD PTR[esi + 0x8], 0xaf7080
		neg     ebx
		sbb     ebx, ebx
		and ebx, a3	//and ebx, 0x64
		add     ebx, eax
		push    ebx
		push    edx
		xor eax, eax
		add eax, a1x //a1x
		push    eax
		push    edx
		push    eax
		push    edx
		mov    eax, a2x	//mov    eax, 0xffffff6b
		push    eax
		push	edi
		jmp dword ptr[dwLoginDescriptorFixRetn]
	}
}

int MoreGainMsgsOffset = 6;

__declspec(naked) void ccMoreGainMsgs() {
	__asm {
		mov    eax, DWORD PTR[edi + 0x10]
		cmp    eax, MoreGainMsgsOffset
		jmp dword ptr[dwMoreGainMsgsRetn]
	}
}

int MoreGainMsgsFadeOffset = 0;

__declspec(naked) void ccMoreGainMsgsFade() {
	__asm {
		add eax,MoreGainMsgsFadeOffset
		push 3
		jmp dword ptr[dwMoreGainMsgsFadeRetn]
	}
}

int MoreGainMsgsFade1Offset = 0;

__declspec(naked) void ccMoreGainMsgsFade1() {
	__asm {
		push MoreGainMsgsFade1Offset
		jmp dword ptr[dwMoreGainMsgsFade1Retn]
	}
}

int yOffsetOfMuruengraidPlayer = 50; int xOffsetOfMuruengraidPlayer = 169;

__declspec(naked) void ccMuruengraidPlayer() {
	__asm {
		push yOffsetOfMuruengraidPlayer
		push xOffsetOfMuruengraidPlayer
		push ecx
		jmp dword ptr[dwMuruengraidPlayerRetn]
	}
}

int yOffsetOfMuruengraidClock = 26; int xOffsetOfMuruengraidClock = 400;

__declspec(naked) void ccMuruengraidClock() {
	__asm {
		push yOffsetOfMuruengraidClock
		push xOffsetOfMuruengraidClock
		push ecx
		jmp dword ptr[dwMuruengraidClockRetn]
	}
}

int yOffsetOfMuruengraidMonster = 50; int xOffsetOfMuruengraidMonster = 631;

__declspec(naked) void ccMuruengraidMonster() {
	__asm {
		push yOffsetOfMuruengraidMonster
		push xOffsetOfMuruengraidMonster
		push ecx
		jmp dword ptr[dwMuruengraidMonsterRetn]
	}
}

int yOffsetOfMuruengraidMonster1 = 32; int xOffsetOfMuruengraidMonster1 = 317;

__declspec(naked) void ccMuruengraidMonster1() {	
	__asm {
		push yOffsetOfMuruengraidMonster1
		push xOffsetOfMuruengraidMonster1
		jmp dword ptr[dwMuruengraidMonster1Retn]
	}
}

int yOffsetOfMuruengraidMonster2 = 32; int xOffsetOfMuruengraidMonster2 = 482;

__declspec(naked) void ccMuruengraidMonster2() {
	__asm {
		push yOffsetOfMuruengraidMonster2
		push xOffsetOfMuruengraidMonster2
		jmp dword ptr[dwMuruengraidMonster2Retn]
	}
}

int yOffsetOfMuruengraidEngBar = 86; int xOffsetOfMuruengraidEngBar = 17;

__declspec(naked) void ccMuruengraidEngBar() {
	__asm {
		push yOffsetOfMuruengraidEngBar
		push xOffsetOfMuruengraidEngBar
		push ecx
		jmp dword ptr[dwMuruengraidEngBarRetn]
	}
}

int yOffsetOfMuruengraidEngBar1 = 130; int xOffsetOfMuruengraidEngBar1 = 20;

__declspec(naked) void ccMuruengraidEngBar1() {
	__asm {
		push yOffsetOfMuruengraidEngBar1
		push xOffsetOfMuruengraidEngBar1
		push ecx
		jmp dword ptr[dwMuruengraidEngBar1Retn]
	}
}

int yOffsetOfMuruengraidEngBar2 = 80; int xOffsetOfMuruengraidEngBar2 = 9;

__declspec(naked) void ccMuruengraidEngBar2() {
	__asm {
		push yOffsetOfMuruengraidEngBar2
		push xOffsetOfMuruengraidEngBar2
		push ecx
		jmp dword ptr[dwMuruengraidEngBar2Retn]
	}
}

int yOffsetOfMuruengraidClearRoundUI = 260; int xOffsetOfMuruengraidClearRoundUI = 400;

__declspec(naked) void ccMuruengraidClearRoundUI() {
	__asm {
		mov ecx, esi
		push yOffsetOfMuruengraidClearRoundUI
		push xOffsetOfMuruengraidClearRoundUI
		jmp dword ptr[dwMuruengraidClearRoundUIRetn]
	}
}

int yOffsetOfMuruengraidTimerCanvas = 28; int xOffsetOfMuruengraidTimerCanvas = 112;

__declspec(naked) void ccMuruengraidTimerCanvas() {
	__asm {
		push yOffsetOfMuruengraidTimerCanvas
		movsd
		push xOffsetOfMuruengraidTimerCanvas
		jmp dword ptr[dwMuruengraidTimerCanvasRetn]
	}
}

int yOffsetOfMuruengraidTimerMinutes = 0; int xOffsetOfMuruengraidTimerMinutes = 0;

__declspec(naked) void ccMuruengraidTimerMinutes() {
	__asm {
		mov    DWORD PTR[esi + 0x848], edi
		push eax
		push yOffsetOfMuruengraidTimerMinutes
		push xOffsetOfMuruengraidTimerMinutes
		jmp dword ptr[dwMuruengraidTimerMinutesRetn]
	}
}

int yOffsetOfMuruengraidTimerSeconds = 0; int xOffsetOfMuruengraidTimerSeconds = 68;

__declspec(naked) void ccMuruengraidTimerSeconds() {
	__asm {
		mov ecx, esi
		push edx
		push yOffsetOfMuruengraidTimerSeconds
		push xOffsetOfMuruengraidTimerSeconds
		jmp dword ptr[dwMuruengraidTimerSecondsRetn]
	}
}

int yOffsetOfMuruengraidTimerBar = 16; int xOffsetOfMuruengraidTimerBar = 345;

__declspec(naked) void ccMuruengraidTimerBar() {
	__asm {
		push yOffsetOfMuruengraidTimerBar
		push xOffsetOfMuruengraidTimerBar
		jmp dword ptr[dwMuruengraidTimerBarRetn]
	}
}

int xOffsetOfMuruengraidMonster1_2 = 318;

__declspec(naked) void ccMuruengraidMonster1_2() {
	__asm {
		mov    edx,xOffsetOfMuruengraidMonster1_2
		jmp dword ptr[dwMuruengraidMonster1_2Retn]
	}
}

__declspec(naked) void ccStatsSubMov() {
	__asm {
		mov     ecx, esi
		add   DWORD PTR[ebp + 0x8], 84 //260-176
		push   DWORD PTR[ebp + 0x8]
		jmp dword ptr[dwStatsSubMovRetn]
	}
}
//beginning of packed client run caves
__declspec(naked) void ccCLoginSendCheckPasswordPacket() {
	__asm {
		jmp dword ptr[dwCLoginSendCheckPasswordPacketRetn]
	}
}

__declspec(naked) void cc0x00A63FF3() {
	__asm {
		push   ebp
		mov    ebp, esp
		push   0xffffffff
		push   0xb412e0
		push   0xa62478
		mov    eax, fs:0x0
		push   eax
		mov    DWORD PTR fs : 0x0, esp
		sub    esp, 0x58
		push   ebx
		push   esi
		push   edi
		mov    DWORD PTR[ebp - 0x18], esp
		call   DWORD PTR ds : 0xaf0074
		xor edx, edx
		jmp dword ptr[dw0x00A63FF3Retn]
	}
}
//end of packed client run caves

//char CUIStatusBarChatLogAddBypassLimit = 0xFF;
__declspec(naked) void ccCUIStatusBarChatLogAddBypass() {
	__asm {
		cmp    DWORD PTR[eax - 0x4], 0xFF
		jbe CUIStatusBarChatLogAddBypass_Dest
		jmp dword ptr[dwCUIStatusBarChatLogAddBypassRetn]
		CUIStatusBarChatLogAddBypass_Dest:
		jmp dword ptr[dwCUIStatusBarChatLogAddBypass2Retn]
	}
}

const char myWzFile[] = "TamingMob";
const char* ptrmyWzFile = myWzFile;

int MINT = 51+1;
const DWORD dwTesting = 0x009F753C;
const DWORD dwTestingRetn = 0x009F7543;
const int TestingNOPs = dwTestingRetn - dwTesting;
__declspec(naked) void testingCodeCave() {
	__asm {
		mov     ebx, [eax * 4 + resmanLoadOrder]//mov     ebx, MainMain::resmanLoadOrder //mov     ebx, [ebp+eax*4+
		jmp dword ptr[dwTestingRetn]
	}
}

const DWORD dwTesting2 = 0x005549F8;
const DWORD dwTesting2Retn = 0x005549FD;
const int Testing2NOPs = 5;
__declspec(naked) void testingCodeCave2() {
	__asm {
		//call dword ptr[custom_sub_4289B7]
		jmp dword ptr[dwTesting2Retn]
	}
}

const DWORD dwTesting3 = 0x005556CC;
const DWORD dwTesting3Retn = 0x005556D5;
const int Testing3NOPs = 9;
__declspec(naked) void testingCodeCave3() {
	__asm {
		mov    DWORD PTR[esi + 0x848], edi
		push eax
		push 80//0
		push 250//0
		jmp dword ptr[dwTesting3Retn]
	}
}

const DWORD dwTesting4 = 0x005556E6;
const DWORD dwTesting4Retn = 0x005556EC;
const int Testing4NOPs = 6;
__declspec(naked) void testingCodeCave4() {
	__asm {
		mov ecx,esi
		push edx
		push 80//0
		push 318//68
		jmp dword ptr[dwTesting4Retn]
	}
}

