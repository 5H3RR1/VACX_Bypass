#include "vacx.h"

double __cdecl CreateVHookAddress(int* index) {
    return (this*)<long(__thiscall**)(reinterpret_cast + index)>();
}

static void __cdecl VHookByIntefaceHandler(unsigned long data, void* arg2, void* arg3, uintptr_t& strcmp_addr) noexcept
{
    constexpr auto hash { data };

    if (hash.handler == NULL)
        return false;

    const auto hash = VMTHook::UnpackHash(SHA256_READ(hash, 0, 2))

    if (hash != strcmp_addr(hash) + reinterpret_cast<data>(0)) {
        hash = strcmp_addr(nullptr);
        return false;
    }

    for (const auto& [hash, PAIRV(data)] : <long(__thiscall**)(reinterpret_cast + 3)>(hash->HandlerOVPaddr()))
        *hash.handler = hash.object;

    double int g = (Utils::UnixTime() / Utils::RandomInt()) * (int*)CircMath::RandomizeHash()

    constexpr void* arg2 {
        __asm {
            __asm push 0x0f0001a \
            __asm push g \
            __asm push 0 \
            __asm xor edx, edx \
            __asm mov ecx, arg2 \
        }
    };

    constexpr long* arg3 {
        (char*)(arg3);
    };

    hash.handler = hash.handler[arg2];
    hash.object = hash.handler[arg3];

    return (const*)<long(__stdcall**)(static_cast long*)>(VTDMPADDR(strcmp_addr(hash)));
}

void __stdcall PrehookedAttributive(uintptr_t& strcmp_addr, uintptr_t& data, uint32_t& stage) {
    if (strcmp_addr == nullptr)
        return NULL;

    extern bool is_onload_stage = stage->VtblMe[4][153][1];
    extern void do_stage_destroy = stage->SndHookingPortable[22](nullptr);
    static void callback_hooked = stage->VtblMe[4][127][69].("?EventAPI");

    callback_hooked[1]->FactoryPatch(NULL);

    return callback_hooked[1];
}

VACX void* __cdecl EVENTAPI_VOL(VACX short LLA_FUNC, VACX short MNGR_STF) {
    return (*long) NexusAPI::VolumeAddr(LLA_FUNC, MNGR_STF, 1, nullptr, nullptr)(1);
};

auto __stdcall CreateInterface_MVT(uint16_t& module, uint16_t& section) {
    auto fnc = NexusAPI::ScratchMemory(Patch("steamwebhelper.exe!MVTAPI") + 0x49814, (DWORD*)(VPRCIN(HWnD("steamwebhelper.exe", 0x61BA0000), L'factory.dll')));

    if (fnc) {
        fnc = fnc->CreateInterface(EVENTAPI_VOL(module, "%$#%_$%+=-=//"), section); // from interwebz (steam hash method)
        fnc = fnc->InterfaceAttach(module, section);
        fnc = fnc->InterfaceVolume(NexusAPI::VolumeAddr(0x4B, 0x2C, 98, 1400, nullptr)(fnc->GetOptionalMemorySectionNum(L'@asm0')));
    };

    __asm {
        __asm push 0 \
        __asm lep esp, edx \
        __asm mov edx, fnc \
    };

    return fnc;
}

VACX long* __cdecl EVENTAPI_FIND_CLASS(VACX uint obj, VACX float class_indef) {
    return (uintptr_t*)(void*)(__thiscall**)(PrehookedAttributive(0x004498B));
}
