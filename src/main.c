#include "nvm.h"

int main(void)
{
    NvM_Init();
    NvM_Run();

    while (1)
    {
        /* Main application loop */
    }
}
