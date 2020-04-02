VERSION 5.00
Begin VB.Form Form1 
   Caption         =   "Form1"
   ClientHeight    =   3795
   ClientLeft      =   120
   ClientTop       =   450
   ClientWidth     =   6255
   LinkTopic       =   "Form1"
   ScaleHeight     =   3795
   ScaleWidth      =   6255
   StartUpPosition =   3  'Windows Default
   Begin VB.CommandButton Command2 
      Caption         =   "Stop!"
      Height          =   315
      Left            =   3000
      TabIndex        =   1
      Top             =   3120
      Width           =   1215
   End
   Begin VB.CommandButton Command1 
      Caption         =   "Start!"
      Height          =   315
      Left            =   1560
      TabIndex        =   0
      Top             =   3120
      Width           =   1215
   End
   Begin VB.Timer Timer1 
      Interval        =   1000
      Left            =   2520
      Top             =   2520
   End
End
Attribute VB_Name = "Form1"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Dim red, blue, green As Integer

Private Sub Command1_Click()
Timer1.Enabled = True
Command1.Enabled = False
Command2.Enabled = True
End Sub

Private Sub Command2_Click()
Timer1.Enabled = False
Command1.Enabled = True
Command2.Enabled = False
End Sub

Private Sub Form_Load()
Timer1.Enabled = False
Command2.Enabled = False
End Sub

Private Sub Timer1_Timer()
red = CInt(Int((255 * Rnd()) + 0))
green = CInt(Int((255 * Rnd()) + 0))
blue = CInt(Int((255 * Rnd()) + 0))
Form1.BackColor = RGB(red, blue, green)
End Sub
