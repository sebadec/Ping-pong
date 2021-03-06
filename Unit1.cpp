//---------------------------------------------------------------------------



//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <dos.h>
#include <mmsystem.h>

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

double x = -3;
double y = -3;
int scoreLeft = 0, scoreRight = 0, bounces = 0;
AnsiString scoreLeftString, scoreRightString, bouncesString;
bool sounds = false;

void soundReflectedBall()
{
        if  (sounds == true)
        {
        sndPlaySound("snd/320549__debsound__pop-19.wav", SND_ASYNC);
        }
}

void WinSound()
{
        if  (sounds == true)
        {
        sndPlaySound("snd/249524__pearcewilsonking__badass-victory.wav", SND_ASYNC);
        }
}


//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
    : TForm(Owner)
{
    Timer_Ball->Enabled = false;
    GroupBox1->Visible = false;
    Label1->Visible = true;
    Label2->Visible = false;
    Button2->Visible = false;
    GroupBox1->Top = Background_Board->Height - Background_Board->Height/2 - GroupBox1->Height/2;
    GroupBox1->Left = Background_Board->Width/2-Label1->Width/2 + GroupBox1->Width/2;

}
//---------------------------------------------------------------------------

void __fastcall TForm1::Timer_BallTimer(TObject *Sender)
{

    Ball->Left += x;
    Ball->Top += y;

    // odbij od lewej sciany
    //if (Ball->Left-5 <= Tlo ->Left) x = -x;

    // odbij od gornej sciany
    if (Ball->Top-5 <= Background_Board ->Top)
    {
        y = -y;
    }

    // odbij od prawej sciany
    //if (Ball->Left+Ball->Width+50 >= Background_Board ->Width) x = -x;

    // odbij od dolnej sciany
    if (Ball->Top + Ball->Height+7 >= Background_Board->Height)
    {
    y = -y;
    }

    //skucha
    if ((Ball->Left <= Background_Board ->Left) ||
            (Ball->Left+Ball->Width+5 >= Background_Board ->Width))
    {
        WinSound();
        Timer_Ball->Enabled = false;
        Ball->Visible = false;
        if (Ball->Left <= Background_Board ->Left)
        {
            Label1->Caption = "> Punkt dla gracza prawego";
            scoreRight = scoreRight++;
            scoreRightString=IntToStr(scoreRight);
        }
        else if (Ball->Left+Ball->Width+5 >= Background_Board ->Width)
        {
            Label1->Caption = "< Punkt dla gracza lewego";
            scoreLeft = scoreLeft++;
            scoreLeftString=IntToStr(scoreLeft);
        }
        bouncesString=IntToStr(bounces);
        Label3->Caption = "Ilosc odbic: " + bouncesString;
        Label2->Caption = scoreLeftString + ":" + scoreRightString;
        Label1->Visible = true;
        Label2->Visible = true;
        Label3->Visible = true;
        Button1->Visible = true;
        Button2->Visible = true;
    }

    //odbicie przez lewa paletke
    if
    ( Ball->Left < Paddle_Left->Left + Paddle_Left->Width
            && Ball->Top + Ball->Height/2 < Paddle_Left->Top + Paddle_Left->Height
            && Ball->Top + Ball->Height/2 >= Paddle_Left->Top)
    {
    soundReflectedBall();
        if (x<0)
        {
            if //10000
            ( Ball->Left < Paddle_Left->Left + Paddle_Left->Width
                    && Ball->Top + Ball->Height/2 < Paddle_Left->Top + Paddle_Left->Height/5  //40
                    && Ball->Top + Ball->Height/2 >= Paddle_Left->Top + 0)   //0
            {
                x = - x;
                y = y*1.1;
                bounces = bounces++;
            }
            else if //01000
            ( Ball->Left < Paddle_Left->Left + Paddle_Left->Width
                    && Ball->Top + Ball->Height/2 < Paddle_Left->Top + (Paddle_Left->Height/5)*2   //80
                    && Ball->Top + Ball->Height/2 >= Paddle_Left->Top + Paddle_Left->Height/5)   //40
            {
                x = - x;
                bounces = bounces++;
            }
            else if //00100
            ( Ball->Left < Paddle_Left->Left + Paddle_Left->Width
                    && Ball->Top + Ball->Height/2 < Paddle_Left->Top + (Paddle_Left->Height/5)*3   //120
                    && Ball->Top + Ball->Height/2 >= Paddle_Left->Top + (Paddle_Left->Height/5)*2)   //80
            {
                x = x*-1.2;
                y = y*1.2;
                bounces = bounces++;
            }
            else if //00010
            ( Ball->Left < Paddle_Left->Left + Paddle_Left->Width
                    && Ball->Top + Ball->Height/2 < Paddle_Left->Top + (Paddle_Left->Height/5)*4   //160
                    && Ball->Top + Ball->Height/2 >= Paddle_Left->Top + (Paddle_Left->Height/5)*3)   //120
            {
                x = - x;
                bounces = bounces++;
            }
            else if //00001
            ( Ball->Left < Paddle_Left->Left + Paddle_Left->Width
                    && Ball->Top + Ball->Height/2 <= Paddle_Left->Top + (Paddle_Left->Height/5)*5   //200
                    && Ball->Top + Ball->Height/2 >= Paddle_Left->Top + (Paddle_Left->Height/5)*4)   //160
            {
                x = x*-1.1;
                y = y*1;
                bounces = bounces++;
            }
        }
    }

    //odbicie przez prawa paletke
    if //10000
    (Ball->Left + Ball->Width >= Paddle_Right->Left
            && Ball->Top + Ball->Height/2 < Paddle_Right->Top + Paddle_Right->Height
            && Ball->Top + Ball->Height/2 >= Paddle_Right->Top)
    {
    soundReflectedBall();
        if (x>0)
        {
            if //10000
            (Ball->Left + Ball->Width >= Paddle_Right->Left
                    && Ball->Top + Ball->Height/2 < Paddle_Right->Top + Paddle_Right->Height/5  //40
                    && Ball->Top + Ball->Height/2 >= Paddle_Right->Top + 0)   //0
            {
                x = x*-1;
                y = y*1.1;
                bounces = bounces++;
            }
            else if //01000
            (Ball->Left + Ball->Width >= Paddle_Right->Left
                    && Ball->Top + Ball->Height/2 < Paddle_Right->Top + (Paddle_Right->Height/5)*2   //80
                    && Ball->Top + Ball->Height/2 >= Paddle_Right->Top + Paddle_Right->Height/5)   //40
            {
                x = - x;
                bounces = bounces++;
            }
            else if //00100
            (Ball->Left + Ball->Width >= Paddle_Right->Left
                    && Ball->Top + Ball->Height/2 < Paddle_Right->Top + (Paddle_Right->Height/5)*3   //120
                    && Ball->Top + Ball->Height/2 >= Paddle_Right->Top + (Paddle_Right->Height/5)*2)   //80
            {
                x = x*-1.2;
                y = y*1.2;
                bounces = bounces++;
            }
            else if //00010
            (Ball->Left + Ball->Width >= Paddle_Right->Left
                    && Ball->Top + Ball->Height/2 < Paddle_Right->Top + (Paddle_Right->Height/5)*4   //160
                    && Ball->Top + Ball->Height/2 >= Paddle_Right->Top + (Paddle_Right->Height/5)*3)   //120
            {
                x = - x;
                bounces = bounces++;
            }
            else if //00001
            (Ball->Left + Ball->Width >= Paddle_Right->Left
                    && Ball->Top + Ball->Height/2 <= Paddle_Right->Top + (Paddle_Right->Height/5)*5   //200
                    && Ball->Top + Ball->Height/2 >= Paddle_Right->Top + (Paddle_Right->Height/5)*4)   //160
            {
                x = x*-1.1;
                y = y*1;
                bounces = bounces++;
            }
        }
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


    Label3->Top = Background_Board->Height - Background_Board->Height/2;
    Label2->Top = Label3->Top-45;
    Label1->Top = Label2->Top-80;
    Button2->Top = Label3->Top+60;
    Button1->Top = Button2->Top+60;
    Button3->Top = Button1->Top+60;

    Label1->Left = Background_Board->Width/2-Label1->Width/2;
    Label2->Left = Background_Board->Width/2-Label1->Width/2;
    Label3->Left = Background_Board->Width/2-Label1->Width/2;
    Button1->Left = Background_Board->Width/2-Button1->Width/2;
    Button2->Left = Background_Board->Width/2-Button1->Width/2;
    Button3->Left = Background_Board->Width/2-Button1->Width/2;


    Timer_Ball->Enabled = true;

    scoreLeft = 0;
    scoreRight = 0;
    scoreLeftString = "0";
    scoreRightString = "0";
    bounces = 0;
    bouncesString = "0";
    x = -3;
    y = -3;


    Ball->Visible = true;
    Label1->Visible = false;
    Label2->Visible = false;
    Label3->Visible = false;
    Button1->Visible = false;
    Button2->Visible = false;
    Button3->Visible = false;
    Timer_Ball->Enabled = true;
    GroupBox1->Visible = false;
    Paddle_Right->Visible = true;
    Paddle_Left->Visible = true;


}
//---------------------------------------------------------------------------


void __fastcall TForm1::Button2Click(TObject *Sender)
{
    Ball->Left = Background_Board->Width/2;
    Ball->Top = Background_Board->Height/2;

    Paddle_Left->Left = Background_Board->Width/20;
    Paddle_Left->Top = Background_Board->Height/2-100;

    Paddle_Right->Left = Background_Board->Width - Background_Board->Width/20;
    Paddle_Right->Top = Background_Board->Height/2-100;


    Label3->Top = Background_Board->Height - Background_Board->Height/2;
    Label2->Top = Label3->Top-45;
    Label1->Top = Label2->Top-80;
    Button2->Top = Label3->Top+60;
    Button1->Top = Button2->Top+60;
    Button3->Top = Button1->Top+60;

    Label1->Left = Background_Board->Width/2-Label1->Width/2;
    Label2->Left = Background_Board->Width/2-Label1->Width/2;
    Label3->Left = Background_Board->Width/2-Label1->Width/2;
    Button1->Left = Background_Board->Width/2-Button1->Width/2;
    Button2->Left = Background_Board->Width/2-Button1->Width/2;
    Button3->Left = Background_Board->Width/2-Button1->Width/2;


    Timer_Ball->Enabled = true;

    if (x>0) x = -3;
    else if (x<=0) x = 3;

    if (y>0) y = -3;
    else if (y<=0) y = 3;


    Ball->Visible = true;
    Label1->Visible = false;
    Label2->Visible = false;
    Label3->Visible = false;
    Button1->Visible = false;
    Button2->Visible = false;
    Button3->Visible = false;
    Timer_Ball->Enabled = true;


}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button3Click(TObject *Sender)
{

    GroupBox1->Visible = true;
    Ball->Visible = false;
    Label1->Visible = false;
    Label2->Visible = false;
    Label3->Visible = false;
    Button1->Visible = true;
    Button2->Visible = false;
    Button3->Visible = false;
    Timer_Ball->Enabled = false;
    Paddle_Left->Visible = false;
    Paddle_Right->Visible = false;




}
//---------------------------------------------------------------------------


void __fastcall TForm1::RadioButton1Click(TObject *Sender)
{
        sounds = true;
        sndPlaySound("snd/d2.wav", SND_ASYNC);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::RadioButton2Click(TObject *Sender)
{
        sounds = false;
}
//---------------------------------------------------------------------------

