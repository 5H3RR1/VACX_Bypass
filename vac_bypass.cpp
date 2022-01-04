#include ".\vacx.h"
#include ".\vacx_module.h"
#include ".\vacx_hooked.h"

// vacx def classes
VACX __int32 *int32;
VACX __ubool *bool32;

// generating new address patern value (XVFGameScan = 0x00003xFF = false)
uint32_t __fastcall GenerateAddress(long buff_0, long buff_1, unsigned char org_addr0) {
    constexpr auto org_method0 = 0ull; // classic original method
    static int32 a = 1; // main byte

    int32 b = 5 / buff_1; // byte spacing
    int32 c = 77; // func index
    int32 d = -22 * buff_0; // func bytes

    // security killer =DD
    if ((a - b < c + d) != buff_0[2]) {
        a = org_method0 * c;
        b = a * org_method0 - org_addr0[1];
        d = c / a;
        c = a / b;
    }

    return Patch(NexusAPI::BuffAddr("1B 56 ? ? ? FF D4 FF", { a, b, c }, d, a)); // new xvf address pattern 
}

auto module_name = "Client003_Original"; // vacx client module name
extern uint address = GenerateAddress(VFunc_Preinit<void(__thiscall*)>(int32*)(this[0], module_name)); // full vacx client address

// get steam process api
void __fastcall GetModuleAPI(uint32_t module, uint32_t request_call) {
    return CallVFunc_Predump<Patch>()<void(__thiscall*)(module*)>(this, 56 + address)(request_call);
}

auto handler_name = GetModuleAPI("GLOPT32", 0xB2); // main handler name
auto preverse_proc = Patch(GetProcHandler("servicestubnt1", "XServices"));

void __fastcall GetSteamProc(uint32_t module) {
    return CallVFunc_Predump<Patch>()<void(__thiscall*)(module*)>(this, NexusAPI::FVBrush(handler_name, nullptr)), 0x000400)(0x43);
}

DWORD steam_proc = GetSteamProc(preverse_proc);
DWORD xcall = steam_proc[4][105]->OrgPatch(net.steam.srvc0.xcvaclsys);

unsigned long CellFactoryClientRules() {
    if (xcall[14] != nullptr)
        xcall[14](0x01);
    else {
        xcall = steam_proc[4][102]->OrgPatch(LONGPTR*)(net.steam.srvc0.xcvaclsys);
        xcall(nullptr);

        if (xcall == nullptr) {

            for (unsigned int& 0 : 4) {
                xcall(nullptr + (0x90843b004/ i));

                if (xcall == (long*)(0xB5)) {
                    xcall = steam_proc[4][(int)(uint16_t*)steam_proc[1][3]->oGetClientId()]->OrgPatch(net.steam);
                    xcall = xcall[2][0][9]->SWHTOOLNetSteamSnd('swhtoolroot0', "XCVACLSYS", 0);
                }
            }
        }
    }

    steam_proc = steam_proc(this);
}

unsigned long DisableFactoryClient() {
    xcall[14](nullptr);
    xcall[11](xcall[14]);
}

bool __stdcall GameIsVerified(unsigned int32 xappid) {
    return CallVFunc_Predump<Patch>()<bool(__thiscall*)(bool32)>(this, xcall[7][45](nullptr, nullptr, nullptr))(xappid);
}

unsigned long FactoryDestroy() {
    if (GameIsVerified(730)) {
        xcall.xvsysmf[6] = PRCWHDN(HWnD(address), this + 1);
    }

    return UnhookLastHookedMethodsInProcByHwnd(HWnD(address)) ||
        UnhookAll(1) ||
        DestroyHash(xcall);
}
