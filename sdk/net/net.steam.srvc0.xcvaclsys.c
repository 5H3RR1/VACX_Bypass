#include "vacx_hooked.h"

static float ADDR_ASP = 1030.f;
static float ADDR_FNX = 1084.f;

unsigned void srvc0_init(uint32_t net_steam_hooked) {
    return vacx.prehooked_sceneapi(net_steam_hooked, ADDR_ASP);
};

unsigned void xcvaclsys_init(uint32_t net_steam_hooked_srvc0) {
    return vacx.prehooked_sceneapi(net_steam_hooked_srvc0, ADDR_FNX);
};
