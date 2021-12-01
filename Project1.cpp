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

                 Lewy gracz steruje wciskaj¹c klawisze W oraz S.
                 Prawy gracz steruje wciskaj¹c strze³ki do góry i w dó³.

                 Dla urozmaicenia zabawy:
                 Kiedy odbijesz pi³kê na srodku paletki, pi³ka perzyspieszy,
                 Liedy odbijesz pi³kê na krawêdziach paletki, pi³ka zmieni k¹t odbicia.);
                 Mo¿esz dowolnie zmieniac pole gry.

                 Mi³ej zabawy!
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
