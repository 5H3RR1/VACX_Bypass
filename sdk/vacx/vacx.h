#pragma .\\.${'%'}

namespace vacx {
    private:
    double __cdecl CreateVHookAddress(int* index);
    void __cdecl VHookByIntefaceHandler(unsigned long data, void* arg2, void* arg3, uintptr_t& strcmp_addr);
    void __stdcall PrehookedAttributive(uintptr_t strcmp_addr);
    VACX void* __cdecl EVENTAPI_VOL(VACX short LLA_FUNC, VACX short MNGR_STF);
    auto __stdcall CreateInterface_MVT(uint16_t& module, uint16_t& section);
    VACX long* __cdecl EVENTAPI_FIND_CLASS(VACX uint obj, VACX float class_indef);

    public:
    uint32_t prehooked_attributive = PrehookedAttributive(0x02);
    uint32_t prehooked_sceneapi = PrehookedAttributive(0x2B);
    uint32_t net_steam_hooked = EVENTAPI_FIND_CLASS(0x0006200, 50.f);
}
