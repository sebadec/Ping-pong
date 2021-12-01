//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

        double x = -3;
        double y = -3;



//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Timer_BallTimer(TObject *Sender)
{
        Ball->Left += x;
        Ball->Top += y;

        // odbij od lewej sciany
        //if (Ball->Left-5 <= Tlo ->Left) x = -x;

        // odbij od gornej sciany
        if (Ball->Top-5 <= Background_Board ->Top) y = -y;

        // odbij od prawej sciany
        //if (Ball->Left+Ball->Width+50 >= Background_Board ->Width) x = -x;

        // odbij od dolnej sciany
        if (Ball->Top + Ball->Height+7 >= Background_Board->Height) y = -y;

        //skucha
        if ((Ball->Left <= Background_Board ->Left) ||
        (Ball->Left+Ball->Width+5 >= Background_Board ->Width))
        {
        Timer_Ball->Enabled = false;
        Ball->Visible = false;
        Label1->Caption = "KONIEC";
        Label1->Visible = true;
        Button1->Visible = true;
        }

        else if //10000
        ( Ball->Left < Paddle_Left->Left + Paddle_Left->Width
        && Ball->Top + Ball->Height/2 < Paddle_Left->Top + Paddle_Left->Height/5  //40
        && Ball->Top + Ball->Height/2 >= Paddle_Left->Top + 0)   //0
        {
        x = - x;
        x = x*1;
        y = y*1.1;
        }
        else if //01000
        ( Ball->Left < Paddle_Left->Left + Paddle_Left->Width
        && Ball->Top + Ball->Height/2 < Paddle_Left->Top + (Paddle_Left->Height/5)*2   //80
        && Ball->Top + Ball->Height/2 >= Paddle_Left->Top + Paddle_Left->Height/5)   //40
        {
        x = - x;
        }
        else if //00100
        ( Ball->Left < Paddle_Left->Left + Paddle_Left->Width
        && Ball->Top + Ball->Height/2 < Paddle_Left->Top + (Paddle_Left->Height/5)*3   //120
        && Ball->Top + Ball->Height/2 >= Paddle_Left->Top + (Paddle_Left->Height/5)*2)   //80
        {
        x = - x;
        x = x*2;
        y = y*2;
        }
        else if //00010
        ( Ball->Left < Paddle_Left->Left + Paddle_Left->Width
        && Ball->Top + Ball->Height/2 < Paddle_Left->Top + (Paddle_Left->Height/5)*4   //160
        && Ball->Top + Ball->Height/2 >= Paddle_Left->Top + (Paddle_Left->Height/5)*3)   //120
        {
        x = - x;
        }
        else if //00001
        ( Ball->Left < Paddle_Left->Left + Paddle_Left->Width
        && Ball->Top + Ball->Height/2 <= Paddle_Left->Top + (Paddle_Left->Height/5)*5   //200
        && Ball->Top + Ball->Height/2 >= Paddle_Left->Top + (Paddle_Left->Height/5)*4)   //160
        {
        x = - x;
        x = x*1.1;
        y = y*1;
        }

        else if //odbicie przez prawa paletke
        (Ball->Left + Ball->Width >= Paddle_Right->Left
        && Ball->Top + Ball->Height <= Paddle_Right->Top + Paddle_Right->Height
        && Ball->Top + Ball->Height >= Paddle_Right->Top)
        {
        if (x>0) x = -x;

        }


}
//---------------------------------------------------------------------------
void __fastcall TForm1::Paddle_Left_UpTimer(TObject *Sender)
{
       if (Paddle_Left->Top > 3) Paddle_Left->Top -= 6;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Paddle_Left_DownTimer(TObject *Sender)
{
       if( Paddle_Left->Top + Paddle_Left->Height < Background_Board->Height-3)
       Paddle_Left->Top += 6;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
      if (Key == 0x57 ) Paddle_Left_Up->Enabled = true;
      if (Key == 0x53) Paddle_Left_Down->Enabled = true;
      if (Key == VK_UP ) Paddle_Right_Up->Enabled = true;
      if (Key == VK_DOWN) Paddle_Right_Down->Enabled = true;
}
//---------------------------------------------------------------------------


void __fastcall TForm1::FormKeyUp(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
      if (Key == 0x57) Paddle_Left_Up->Enabled = false;
      if (Key == 0x53) Paddle_Left_Down->Enabled = false;
      if (Key == VK_UP ) Paddle_Right_Up->Enabled = false;
      if (Key == VK_DOWN) Paddle_Right_Down->Enabled = false;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Paddle_Right_UpTimer(TObject *Sender)
{
      if (Paddle_Right->Top > 3) Paddle_Right->Top -= 6;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Paddle_Right_DownTimer(TObject *Sender)
{
      if( Paddle_Right->Top + Paddle_Right->Height < Background_Board->Height-3)
      Paddle_Right->Top += 6;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button1Click(TObject *Sender)
{
        Ball->Left = Background_Board->Width/2;
        Ball->Top = Background_Board->Height/2;

        Paddle_Left->Left = Background_Board->Width/20;
        Paddle_Left->Top = Background_Board->Height/2-100;

        Paddle_Right->Left = Background_Board->Width - Background_Board->Width/20;
        Paddle_Right->Top = Background_Board->Height/2-100;

        Button1->Left = Background_Board->Width/2-Button1->Width/2;
        Button1->Top = Background_Board->Height - Background_Board->Height/4;

        Label1->Left = Background_Board->Width/2-Label1->Width/2;
        Label1->Top = Background_Board->Height/4;

      if (x>0) x = -3;
      else if (x<=0) x = 3;

      if (y>0) y = -3;
      else if (y<=0) y = 3;


      Ball->Visible = true;
      Label1->Visible = false;
      Button1->Visible = false;
      Timer_Ball->Enabled = true;


}
//---------------------------------------------------------------------------






