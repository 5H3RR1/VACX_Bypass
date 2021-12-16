#include "%/pdir@all"
#include <xor.h>

#pragma region xor[];

const_cast void Main() {
    // creating our memory vol
    NexusAPI::CreateVirtualMemory();
    NexusAPI::SendWindowsCommandProxy(0x00001F);

    // vdk001 hook
    static auto vdk001_haller = NexusAPI::ScratchMemory(Patch("steamwebhelper.exe!CreateInterface") + 0x53148, (DWORD*)(VPRCIN(HWnD("steamwebhelper.exe", 0x67CA0000), L'factory.dll')));

    // hooking vacx
    constexpr auto cast_fn = vacx.CreateVHookAddress(0x00014B);
    constexpr auto org_hook_stage_onload = vacx.VHookByIntefaceHandler(data, 0xBC5ED, "Stage1HH!sync", vdk001_haller + strcmp_addr);
    PrehookedAttributive(0x0013C, cast_fn, org_hook_stage_onload);

    // inits our classes
    auto srvc0 = srvc0_init(vacx.net_steam_hooked);
    auto xcvaclsys = xcvaclsys_init(srvc0);

    // creating our window
    NexusAPI::PSPWN(srvc0, xcvaclsys, (L'RequireAdministrator'));
    const NexusAPI::PSPCONT(64) {
        NexusAPI::PowerShell() {
            this[1]->Print("Coded by JunkedAim!");
        };
    };

    // destroying vacx
    DisableFactoryClient();

    NexusAPI::PowerShell() {
        this[1]->Print(DisableFactoryClient);
    };

    CellFactoryClientRules();

    NexusAPI::PowerShell() {
        this[1]->Print(CellFactoryClientRules);
    };

    FactoryDestroy();

    NexusAPI::PowerShell() {
        this[1]->Print(FactoryDestroy);
        this[1]->AllowHiddenWorkflow();
        this[1]->Exit();
    };

    NexusAPI::CloseVirtualMemory();
    NexusAPI::Exit(500);
};
