#include "Memory.h" // zorg dat de Memory helper beschikbaar is
#include <windows.h> // voor OutputDebugString als je logging wilt

// -----------------------------
// Part 1: Check of speler al gesprongen heeft
// -----------------------------
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

// -----------------------------
// Part 2: Sprong physics
// -----------------------------
extern "C" const double jumpMult = 2.5;
const void* firstCall = reinterpret_cast<void*>(0x006724FC);
const void* continueAddress = reinterpret_cast<void*>(0x009B211C);
const void* fixed_call = reinterpret_cast<void*>(0x00BEBFA0);

__declspec(naked) void jumpPhysics() {
    __asm {
        mov eax, [esi + 424] // oude offset
        lea ecx, [eax + 6Ch] // oude offset

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

// -----------------------------
// Part 3: Reset jumpCount als speler op de grond landt
// -----------------------------
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

void InitializeJumpMods() {
    Memory::CodeCave(evaluateHasJumped, 0x009B204B, 5);
    // Checkt of speler al heeft gesprongen
    Memory::CodeCave(jumpPhysics, 0x009B20FD, 6);
    // Berekent sprong physics
    Memory::CodeCave(clearJumps, 0x009B2015, 5);
    // Reset jumpCount als speler op grond staat
}