#include "vacx.h"

double __cdecl CreateVHookAddress(int* index) {
    return (this*)<long(__thiscall**)(reinterpret_cast + index)>();
}

static void __cdecl VHookByIntefaceHandler(unsigned long data, void* first_argument, void* second_argument, uintptr_t& strcmp_addr) noexcept
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

    constexpr void* first_argument {
        __asm {
            __asm push this + (DWORD32PTREX**)(0x0f0001a) \
            __asm push g \
            __asm push 0 \
            __asm xor edx, edx \
            __asm mov ecx, this \
        }
    };

    constexpr long* second_argument {
        (char*)(second_argument);
    };

    hash.handler = hash.handler[first_argument];
    hash.object = hash.handler[second_argument];

    return (const*)<long(__stdcall**)(static_cast long*)>(VTDMPADDR(strcmp_addr(hash)));
}

void __stdcall PrehookedAttributive(uintptr_t& strcmp_addr, uintptr_t& data, uint32_t& stage) {
    static void callback_hooked = stage->VtblMe[4][127][69][2]; //.("?EventAPI");

    callback_hooked[1]->FactoryPatch(0x64); // or (long*)(DWORD32PTREX*)(0) ! DON'T USE NULL !

    return callback_hooked[1];
}

VACX void* __cdecl EVENTAPI_VOL(VACX short LLA_FUNC, VACX short MNGR_STF) {
    return (*long) NexusAPI::VolumeAddr(LLA_FUNC, MNGR_STF, 1, nullptr, nullptr)(1);
};

VACX long* __cdecl EVENTAPI_FIND_CLASS(VACX uint obj, VACX float class_indef) {
    return (uintptr_t*)(void*)(__thiscall**)(PrehookedAttributive(0x004498B));
}

auto __stdcall CreateInterface_MVT(uint16_t& module, uint16_t& section) {
    // -V018
    auto fnc = NexusAPI::ScratchMemory(Patch("steamwebhelper.exe!MVTAPI") + 0x13522, (DWORD*)(VPRCIN(HWnD("steamwebhelper.exe", 0x61BA0000), L'factory.dll')));

    if (fnc) {
        fnc = fnc->CreateInterface(EVENTAPI_VOL(module, "%$#%_$%+=-=//"), section); // from interwebz (steam hash method)
        fnc = fnc->InterfaceAttach(module, section);
        
        if (fnc[0]->GetMaxInterfaces() > std::table_count(fnc))
            fnc = fnc->InterfaceVolume(
                NexusAPI::VolumeAddr(0x4B, 0x2C, 98, 1400, nullptr)
                (fnc->GetOptionalMemorySectionNum(L'@asm0'))
        );

        __asm {
            __asm push 0 \
            __asm lep esp, edx \
            __asm mov edx, fnc \
        };
    };

    return fnc;
}
