VERSION 5.00
Begin VB.Form Form1 
   BackColor       =   &H00808000&
   Caption         =   "Form1"
   ClientHeight    =   3030
   ClientLeft      =   120
   ClientTop       =   450
   ClientWidth     =   4560
   LinkTopic       =   "Form1"
   ScaleHeight     =   10950
   ScaleWidth      =   20250
   StartUpPosition =   3  'Windows Default
   Begin VB.CommandButton Command2 
      Caption         =   "Exit"
      Height          =   1215
      Left            =   7920
      TabIndex        =   3
      Top             =   3240
      Width           =   1575
   End
   Begin VB.CommandButton Command1 
      Caption         =   "CLEAR"
      Height          =   1095
      Left            =   7920
      TabIndex        =   2
      Top             =   1320
      Width           =   1695
   End
   Begin VB.TextBox Text1 
      BackColor       =   &H00008080&
      ForeColor       =   &H8000000B&
      Height          =   3735
      Left            =   1920
      MultiLine       =   -1  'True
      TabIndex        =   1
      Text            =   "C to F.frx":0000
      Top             =   840
      Width           =   5055
   End
   Begin VB.VScrollBar VScroll1 
      Height          =   3735
      Left            =   720
      Max             =   200
      TabIndex        =   0
      Top             =   840
      Width           =   855
   End
End
Attribute VB_Name = "Form1"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Private Sub Command1_Click()
Text1.Text = " "
End Sub

Private Sub Command2_Click()
End
End Sub

Private Sub Form_Load()
Text1.Text = " "
End Sub



Private Sub VScroll1_Change()
Dim f As Integer
Dim c As Double
f = VScroll1.Value
c = ((f - 32) * 5) / 9
Text1.Text = "  TEMPARATURE IN FARENHITE  " & f & vbCrLf & "  CELCIOUS VALUE  " & c

End Sub
