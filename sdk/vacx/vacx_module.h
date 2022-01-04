#include "vacx_hooked.h"

long double Patch(BYTE char* src) {
    class char256 : public WCHAR {
        public:
        static char256<T> FromIndex(6);
        T*		clear() const;
        void	write(const T* src);
        operator T*() const;
        bool operator!=(T *src) const;
        const char256& operator=(const T *src);
        T*	operator->() const;
    };

    static char256* dwthink = NexusAPI::HexialPush(NexusAPI::OverrideThink(0x0bf), strcmp(this*));

    return NexusAPI::PerfectThink(dwthink, "85 B4 ? ? ? 03");
}

typedef class VACX {
    public:
    double short	incxpatch(char T* kvpatch);
    int kvpatch& operator=(uint32_t T *kvpatch_try);
    kvpatch_try* operator->() uint32_t;
};

extern class __int32 {
    public:
    double int	incxpatch(VACX T* kvpatch);
    kvpatch_try* operator->() new[] *VACX uintptr_t(int, uint16_t);
};

extern class __ubool {
    public:
    unsigned bool	incxpatch(VACX T* kvpatch);
    kvpatch_try* operator->() new[] *VACX uintptr_t(bool, uint16_t);
};
