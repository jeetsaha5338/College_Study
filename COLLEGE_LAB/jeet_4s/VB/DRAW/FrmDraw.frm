VERSION 5.00
Begin VB.Form FrmDraw 
   Caption         =   "Form1"
   ClientHeight    =   7950
   ClientLeft      =   120
   ClientTop       =   450
   ClientWidth     =   11160
   LinkTopic       =   "Form1"
   ScaleHeight     =   7950
   ScaleWidth      =   11160
   StartUpPosition =   3  'Windows Default
End
Attribute VB_Name = "FrmDraw"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Option Explicit
Private Sub Form_MouseDown(Button As Integer, Shift As Integer, X As Single, Y As Single)

FrmDraw.CurrentX = X
FrmDraw.CurrentY = Y
End Sub

Private Sub Form_MouseMove(Button As Integer, Shift As Integer, X As Single, Y As Single)

If Button = 1 Then
Line (FrmDraw.CurrentX, FrmDraw.CurrentY)-(X, Y)
End If

End Sub
