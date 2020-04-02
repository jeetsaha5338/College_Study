VERSION 5.00
Begin VB.Form Form1 
   Caption         =   "Form1"
   ClientHeight    =   3030
   ClientLeft      =   120
   ClientTop       =   450
   ClientWidth     =   4560
   LinkTopic       =   "Form1"
   ScaleHeight     =   3030
   ScaleWidth      =   4560
   StartUpPosition =   3  'Windows Default
   Begin VB.CommandButton Command1 
      Caption         =   "Enter number to check odd or even"
      Height          =   735
      Left            =   1320
      TabIndex        =   0
      Top             =   1080
      Width           =   1335
   End
End
Attribute VB_Name = "Form1"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Private Sub Command1_Click()
num = InputBox("Enter a number")
If num < 0 Then
    MsgBox "Negative number!", vbOKOnly, "ERROR"
ElseIf num Mod 2 = 0 Then
    MsgBox "Even!", vbOKOnly, "RESULT"
Else
    MsgBox "Odd!", vbOKOnly, "RESULT"
End If

End Sub
