//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Graphics.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
        TShape *Background_Board;
        TImage *Ball;
        TTimer *Timer_Ball;
        TImage *Paddle_Left;
        TTimer *Paddle_Left_Up;
        TTimer *Paddle_Left_Down;
        TImage *Paddle_Right;
        TTimer *Paddle_Right_Up;
        TTimer *Paddle_Right_Down;
        TLabel *Label1;
        TButton *Button1;
        void __fastcall Timer_BallTimer(TObject *Sender);
        void __fastcall Paddle_Left_UpTimer(TObject *Sender);
        void __fastcall FormKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall Paddle_Left_DownTimer(TObject *Sender);
        void __fastcall FormKeyUp(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall Paddle_Right_UpTimer(TObject *Sender);
        void __fastcall Paddle_Right_DownTimer(TObject *Sender);
        void __fastcall Button1Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif