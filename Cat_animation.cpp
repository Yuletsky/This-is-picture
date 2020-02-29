#include "TXLib.h"

void Animation (HDC hero, int framesX, int framesY, int x, int y, int clavisha);

int main()
{
    txCreateWindow (800, 600);
    txSetFillColor (TX_WHITE);
    txClear ();

    HDC cat = txLoadImage ("Cats1.bmp");
    const int framesX = 6, framesY = 3;
    int x = 600, y = 300;

    Animation (cat, framesX1, framesY1, x, y, VK_SPACE);

    txDeleteDC (cat);
}

void Animation (HDC hero, int framesX, int framesY, int x, int y, int clavisha)
{
    int anima = 0;

    int frameSizeX = txGetExtentX (hero) / framesX;
    int frameSizeY = txGetExtentY (hero) / framesY;

    for (int i = 0; !GetAsyncKeyState (clavisha); i++)
    {
        txBitBlt (txDC (), x, y, frameSizeX, frameSizeY, hero, (i % framesX) * frameSizeX,
                  anima * frameSizeY);

        if (GetAsyncKeyState ('1')) { anima = 0; }
        if (GetAsyncKeyState ('2')) { anima = 1; }
        if (GetAsyncKeyState ('3')) { anima = 2; }

        txSleep (50);
    }
    anima++;
}
