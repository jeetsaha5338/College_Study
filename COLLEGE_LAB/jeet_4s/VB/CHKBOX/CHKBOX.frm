VERSION 5.00
Begin VB.Form Form1 
   BackColor       =   &H80000016&
   Caption         =   "Form1"
   ClientHeight    =   6165
   ClientLeft      =   120
   ClientTop       =   450
   ClientWidth     =   12375
   BeginProperty Font 
      Name            =   "MS Sans Serif"
      Size            =   12
      Charset         =   0
      Weight          =   400
      Underline       =   0   'False
      Italic          =   0   'False
      Strikethrough   =   0   'False
   EndProperty
   LinkTopic       =   "Form1"
   ScaleHeight     =   6165
   ScaleWidth      =   12375
   StartUpPosition =   3  'Windows Default
   Begin VB.CommandButton Command3 
      Caption         =   " EXIT "
      BeginProperty Font 
         Name            =   "Palatino Linotype"
         Size            =   12
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   -1  'True
         Strikethrough   =   0   'False
      EndProperty
      Height          =   495
      Left            =   9120
      TabIndex        =   9
      Top             =   5400
      Width           =   1455
   End
   Begin VB.CommandButton Command2 
      Caption         =   " CLEAR "
      BeginProperty Font 
         Name            =   "Palatino Linotype"
         Size            =   12
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   -1  'True
         Strikethrough   =   0   'False
      EndProperty
      Height          =   495
      Left            =   7200
      TabIndex        =   8
      Top             =   5400
      Width           =   1455
   End
   Begin VB.CommandButton Command1 
      Caption         =   " SHOW "
      BeginProperty Font 
         Name            =   "Palatino Linotype"
         Size            =   12
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   -1  'True
         Strikethrough   =   0   'False
      EndProperty
      Height          =   495
      Left            =   5160
      TabIndex        =   7
      Top             =   5400
      Width           =   1575
   End
   Begin VB.Frame Frame3 
      Caption         =   "DISPLAY"
      Height          =   3015
      Left            =   4920
      TabIndex        =   6
      Top             =   2040
      Width           =   6975
      Begin VB.TextBox Text3 
         Height          =   2535
         Left            =   120
         TabIndex        =   10
         Top             =   360
         Width           =   6615
      End
   End
   Begin VB.Frame Frame2 
      Caption         =   "SELECT FONT"
      Height          =   1335
      Left            =   5400
      TabIndex        =   5
      Top             =   240
      Width           =   5775
      Begin VB.CheckBox Check9 
         Caption         =   "Underline"
         Height          =   735
         Left            =   4080
         TabIndex        =   19
         Top             =   360
         Width           =   1575
      End
      Begin VB.CheckBox Check8 
         Caption         =   "Italic"
         Height          =   495
         Left            =   2280
         TabIndex        =   18
         Top             =   480
         Width           =   1575
      End
      Begin VB.CheckBox Check7 
         Caption         =   "Bold"
         Height          =   495
         Left            =   480
         TabIndex        =   17
         Top             =   480
         Width           =   1695
      End
   End
   Begin VB.Frame Frame1 
      Caption         =   "HOBBIES"
      Height          =   3375
      Left            =   480
      TabIndex        =   4
      Top             =   2280
      Width           =   3855
      Begin VB.CheckBox Check6 
         Caption         =   "Chating"
         Height          =   615
         Left            =   2160
         TabIndex        =   16
         Top             =   2400
         Width           =   1335
      End
      Begin VB.CheckBox Check5 
         Caption         =   "Eating"
         Height          =   375
         Left            =   240
         TabIndex        =   15
         Top             =   2520
         Width           =   1335
      End
      Begin VB.CheckBox Check4 
         Caption         =   "Sleeping"
         Height          =   615
         Left            =   2160
         TabIndex        =   14
         Top             =   1440
         Width           =   1335
      End
      Begin VB.CheckBox Check3 
         Caption         =   "Travalling"
         Height          =   375
         Left            =   240
         TabIndex        =   13
         Top             =   1560
         Width           =   1335
      End
      Begin VB.CheckBox Check2 
         Caption         =   "Playing"
         Height          =   375
         Left            =   2160
         TabIndex        =   12
         Top             =   600
         Width           =   1455
      End
      Begin VB.CheckBox Check1 
         Caption         =   "Reading"
         Height          =   420
         Left            =   240
         TabIndex        =   11
         Top             =   600
         Width           =   1335
      End
   End
   Begin VB.TextBox Text2 
      Height          =   615
      Left            =   2520
      TabIndex        =   3
      Top             =   1200
      Width           =   2295
   End
   Begin VB.TextBox Text1 
      Height          =   615
      Left            =   2520
      TabIndex        =   2
      Top             =   240
      Width           =   2295
   End
   Begin VB.Label Label2 
      Caption         =   "    AGE       "
      BeginProperty Font 
         Name            =   "Perpetua Titling MT"
         Size            =   18
         Charset         =   0
         Weight          =   700
         Underline       =   -1  'True
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   615
      Left            =   240
      TabIndex        =   1
      Top             =   1200
      Width           =   1815
   End
   Begin VB.Label Label1 
      Caption         =   "   NAME     "
      BeginProperty Font 
         Name            =   "Perpetua Titling MT"
         Size            =   18
         Charset         =   0
         Weight          =   700
         Underline       =   -1  'True
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   615
      Left            =   240
      TabIndex        =   0
      Top             =   240
      Width           =   1815
   End
End
Attribute VB_Name = "Form1"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Dim s As String
Private Sub Check1_Click()
If Check1.Value = 1 Then
s = s & " " & Check1.Caption
End If
End Sub

Private Sub Check2_Click()
If Check2.Value = 1 Then
s = s & " " & Check2.Caption
End If

End Sub

Private Sub Check3_Click()
If Check3.Value = 1 Then
s = s & " " & Check3.Caption
End If

End Sub

Private Sub Check4_Click()
If Check4.Value = 1 Then
s = s & " " & Check4.Caption
End If

End Sub

Private Sub Check5_Click()
If Check5.Value = 1 Then
s = s & " " & Check5.Caption
End If

End Sub

Private Sub Check6_Click()
If Check6.Value = 1 Then
s = s & " " & Check6.Caption
End If

End Sub

Private Sub Check7_Click()
If Check7.Value = 1 Then
Text3.FontBold = True
Else
Text3.FontBold = False
End If
End Sub

Private Sub Check8_Click()
If Check8.Value = 1 Then
Text3.FontItalic = True
Else
Text3.FontItalic = False
End If
End Sub

Private Sub Check9_Click()
If Check9.Value = 1 Then
Text3.FontUnderline = True
Else
Text3.FontUnderline = False
End If
End Sub

Private Sub Command1_Click()
Text3.Text = Text1.Text & " " & Text2.Text & " " & s
End Sub

Private Sub Command2_Click()
Text1.Text = " "
Text2.Text = " "
Text3.Text = " "
Check1.Value = 0
Check2.Value = 0
Check3.Value = 0
Check4.Value = 0
Check5.Value = 0
Check6.Value = 0
Check7.Value = 0
Check8.Value = 0
Check9.Value = 0

End Sub

Private Sub Command3_Click()
End
End Sub

