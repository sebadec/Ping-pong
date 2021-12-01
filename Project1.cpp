//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
//---------------------------------------------------------------------------
USEFORM("Unit1.cpp", Form1);
//---------------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
        try
        {
                 Application->Initialize();
                 /*
                 Witaj w grze PingPong.

                 Lewy gracz steruje wciskaj�c klawisze W oraz S.
                 Prawy gracz steruje wciskaj�c strze�ki do g�ry i w d�.

                 Dla urozmaicenia zabawy:
                 Kiedy odbijesz pi�k� na srodku paletki, pi�ka perzyspieszy,
                 Liedy odbijesz pi�k� na kraw�dziach paletki, pi�ka zmieni k�t odbicia.);
                 Mo�esz dowolnie zmieniac pole gry.

                 Mi�ej zabawy!
                 */
                 Application->CreateForm(__classid(TForm1), &Form1);
                 Application->Run();
        }
        catch (Exception &exception)
        {
                 Application->ShowException(&exception);
        }
        catch (...)
        {
                 try
                 {
                         throw Exception("");
                 }
                 catch (Exception &exception)
                 {
                         Application->ShowException(&exception);
                 }
        }
        return 0;
}
//---------------------------------------------------------------------------
