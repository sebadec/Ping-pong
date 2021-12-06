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
		 Application->MessageBox(
                 "Witaj w grze PingPong."
                 " \n"
                 "Lewy gracz steruje wciskajac klawisze W oraz S.\n"
                 "Prawy gracz steruje wciskajac strzalki do gory i w dol. \n"
                 "Dla urozmaicenia zabawy: \n"
                 "Kiedy odbijesz pilke na srodku paletki, pilka perzyspieszy,\n"
                 "Kiedy odbijesz pilke na krawedziach paletki, pilka zmieni kat odbicia. \n"
                 "Mozesz dowolnie zmieniac pole gry -> gra sie dostosuje.\n"
                 " \n"
                 "Milej zabawy!\n"
                 " \n"
                 , "Game made by Sebastian Dec", MB_OK);

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
