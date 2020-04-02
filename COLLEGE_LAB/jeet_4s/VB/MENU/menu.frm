VERSION 5.00
Begin VB.Form Form1 
   Caption         =   "Form1"
   ClientHeight    =   5925
   ClientLeft      =   225
   ClientTop       =   855
   ClientWidth     =   7185
   LinkTopic       =   "Form1"
   ScaleHeight     =   5925
   ScaleWidth      =   7185
   StartUpPosition =   3  'Windows Default
   Begin VB.TextBox Text1 
      BeginProperty Font 
         Name            =   "Palatino Linotype"
         Size            =   14.25
         Charset         =   0
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   3855
      Left            =   960
      TabIndex        =   0
      Text            =   "hello world......"
      Top             =   480
      Width           =   5055
   End
   Begin VB.Menu menu 
      Caption         =   "menu"
      Begin VB.Menu bold 
         Caption         =   "&bold"
         Shortcut        =   ^B
      End
      Begin VB.Menu italic 
         Caption         =   "&italic"
         Shortcut        =   ^I
      End
      Begin VB.Menu underline 
         Caption         =   "&underline"
         Shortcut        =   ^U
      End
   End
   Begin VB.Menu colour 
      Caption         =   "colour"
      Begin VB.Menu red 
         Caption         =   "&red"
         Shortcut        =   ^R
      End
      Begin VB.Menu green 
         Caption         =   "&green"
         Shortcut        =   ^G
      End
   End
   Begin VB.Menu edit 
      Caption         =   "edit"
      Begin VB.Menu copy 
         Caption         =   "&copy"
         Shortcut        =   ^C
      End
      Begin VB.Menu paste 
         Caption         =   "&paste"
         Shortcut        =   ^V
      End
      Begin VB.Menu cut 
         Caption         =   "&cut"
         Shortcut        =   ^X
      End
   End
End
Attribute VB_Name = "Form1"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Private Sub bold_Click()
Text1.FontBold = True
End Sub

Private Sub copy_Click()
Clipboard.Clear
Clipboard.SetText Text1.SelText
End Sub

Private Sub cut_Click()
Clipboard.Clear
Clipboard.SetText Text1.SelText
Text1.SelText = " "
End Sub

Private Sub green_Click()
Text1.ForeColor = vbGreen

End Sub

Private Sub italic_Click()
Text1.FontItalic = True

End Sub

Private Sub paste_Click()
Text1.SelText = Clipboard.GetText
End Sub

Private Sub red_Click()
Text1.ForeColor = vbRed

End Sub



Private Sub underline_Click()
Text1.FontUnderline = True

End Sub
