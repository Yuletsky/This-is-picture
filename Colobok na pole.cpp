#include "TXLib.h"

int main()
{
    txCreateWindow (800, 600);

    HDC pole = txLoadImage ("Pole1.bmp");
    HDC colobok = txLoadImage ("Colobok.bmp");
    int x = 243, y = 210;

    while (!txGetAsyncKeyState (VK_SPACE))
    {
        txBitBlt         (txDC (), 0, 0, 0, 0, pole);
        txTransparentBlt (txDC (), x, y, 0, 0, colobok, 0, 0, RGB (255, 0, 255));
        //txAlphaBlend (txDC(), x, y, 0, 0, colobok, 0, 0, 0);

        if (GetAsyncKeyState (VK_LEFT)) x--;
        if (GetAsyncKeyState (VK_RIGHT)) x++;

        txSleep ();
    }
    txDeleteDC (pole);
    txDeleteDC (colobok);
}
