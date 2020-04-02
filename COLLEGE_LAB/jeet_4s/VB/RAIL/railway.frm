VERSION 5.00
Begin VB.Form Form1 
   BackColor       =   &H00000080&
   Caption         =   "Form1"
   ClientHeight    =   8370
   ClientLeft      =   120
   ClientTop       =   450
   ClientWidth     =   12105
   LinkTopic       =   "Form1"
   ScaleHeight     =   8370
   ScaleWidth      =   12105
   StartUpPosition =   3  'Windows Default
   Begin VB.CommandButton Command4 
      Caption         =   "PAY"
      Height          =   495
      Left            =   2760
      TabIndex        =   27
      Top             =   6960
      Width           =   1815
   End
   Begin VB.CommandButton Command3 
      Caption         =   "RESET"
      Height          =   495
      Left            =   600
      TabIndex        =   26
      Top             =   6960
      Width           =   1815
   End
   Begin VB.CommandButton Command2 
      Caption         =   "CALCULATE"
      Height          =   495
      Left            =   7680
      TabIndex        =   25
      Top             =   6960
      Width           =   1815
   End
   Begin VB.CommandButton Command1 
      Caption         =   "RESET"
      Height          =   495
      Left            =   5160
      TabIndex        =   24
      Top             =   6960
      Width           =   1815
   End
   Begin VB.TextBox Text8 
      Height          =   495
      Left            =   7680
      TabIndex        =   23
      Top             =   5760
      Width           =   1575
   End
   Begin VB.TextBox Text7 
      Height          =   495
      Left            =   7680
      TabIndex        =   21
      Top             =   4800
      Width           =   1575
   End
   Begin VB.TextBox Text6 
      Height          =   495
      Left            =   7680
      TabIndex        =   19
      Top             =   3720
      Width           =   1575
   End
   Begin VB.TextBox Text5 
      Height          =   495
      Left            =   7680
      TabIndex        =   17
      Top             =   2640
      Width           =   1575
   End
   Begin VB.TextBox Text4 
      Height          =   375
      Left            =   9360
      TabIndex        =   15
      Top             =   1560
      Width           =   855
   End
   Begin VB.TextBox Text3 
      Height          =   375
      Left            =   7680
      TabIndex        =   14
      Top             =   1560
      Width           =   855
   End
   Begin VB.ComboBox Combo3 
      Height          =   315
      Left            =   8160
      TabIndex        =   10
      Top             =   360
      Width           =   2415
   End
   Begin VB.Frame Frame1 
      Caption         =   "PAYMENT DETAILS"
      Height          =   4455
      Left            =   600
      TabIndex        =   0
      Top             =   1920
      Width           =   3735
      Begin VB.ComboBox Combo2 
         Height          =   315
         Left            =   120
         TabIndex        =   8
         Top             =   3600
         Width           =   3375
      End
      Begin VB.ComboBox Combo1 
         Height          =   315
         Left            =   1440
         TabIndex        =   6
         Top             =   2280
         Width           =   1935
      End
      Begin VB.TextBox Text2 
         Height          =   495
         Left            =   1440
         TabIndex        =   4
         Top             =   1200
         Width           =   1935
      End
      Begin VB.TextBox Text1 
         Height          =   495
         Left            =   1440
         TabIndex        =   2
         Top             =   360
         Width           =   1935
      End
      Begin VB.Label Label4 
         Caption         =   "PAYMENT MODE"
         Height          =   375
         Left            =   120
         TabIndex        =   7
         Top             =   3000
         Width           =   2415
      End
      Begin VB.Label Label3 
         Caption         =   "GENDER"
         Height          =   375
         Left            =   120
         TabIndex        =   5
         Top             =   2280
         Width           =   1215
      End
      Begin VB.Label Label2 
         Caption         =   "AGE"
         Height          =   375
         Left            =   120
         TabIndex        =   3
         Top             =   1200
         Width           =   735
      End
      Begin VB.Label Label1 
         Caption         =   "NAME"
         Height          =   375
         Left            =   120
         TabIndex        =   1
         Top             =   360
         Width           =   855
      End
   End
   Begin VB.Label Label13 
      Caption         =   "INDIAN RAILWAYS"
      BeginProperty Font 
         Name            =   "Papyrus"
         Size            =   15.75
         Charset         =   0
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   735
      Left            =   480
      TabIndex        =   28
      Top             =   360
      Width           =   3855
   End
   Begin VB.Label Label12 
      Caption         =   "TOTAL FARE"
      Height          =   495
      Left            =   5160
      TabIndex        =   22
      Top             =   5760
      Width           =   2055
   End
   Begin VB.Label Label11 
      Caption         =   "SERVICE TAX"
      Height          =   495
      Left            =   5160
      TabIndex        =   20
      Top             =   4920
      Width           =   2055
   End
   Begin VB.Label Label10 
      Caption         =   "RESERVATION CHARGE"
      Height          =   495
      Left            =   5160
      TabIndex        =   18
      Top             =   3720
      Width           =   2055
   End
   Begin VB.Label Label9 
      Caption         =   "BASE FARE "
      Height          =   495
      Left            =   5160
      TabIndex        =   16
      Top             =   2640
      Width           =   2055
   End
   Begin VB.Label Label8 
      Caption         =   "CHILDREN"
      Height          =   255
      Left            =   9240
      TabIndex        =   13
      Top             =   1080
      Width           =   1095
   End
   Begin VB.Label Label7 
      Caption         =   "ADULT"
      Height          =   255
      Left            =   7800
      TabIndex        =   12
      Top             =   1080
      Width           =   975
   End
   Begin VB.Label Label6 
      Caption         =   "ENTER NUMBER OF PASSENGERS"
      Height          =   495
      Left            =   5160
      TabIndex        =   11
      Top             =   1560
      Width           =   2055
   End
   Begin VB.Label Label5 
      Caption         =   "SELECT THE CLASS TYPE"
      Height          =   375
      Left            =   5160
      TabIndex        =   9
      Top             =   360
      Width           =   2535
   End
End
Attribute VB_Name = "Form1"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False

Private Sub Combo3_Click()
Text1.Enabled = True
Text2.Enabled = True
Text3.Enabled = True
Text4.Enabled = True
Text5.Enabled = True
Text6.Enabled = True
Text7.Enabled = True
Text8.Enabled = True
End Sub

Private Sub Command1_Click()
Text1.Text = ""
Text2.Text = ""
Text3.Text = ""
Text4.Text = ""
Text5.Text = ""
Text6.Text = ""
Text7.Text = ""
Text8.Text = ""
Combo3.Text = ""
Combo1.Text = ""
Combo2.Text = ""
Command1.Enabled = False
Command2.Enabled = False
Command3.Enabled = False
Command4.Enabled = False

End Sub

Private Sub Command2_Click()
Dim S As String
Dim I As Integer
Dim PASS, base, rc, sc, pass1 As Integer
S = Combo3.Text
Select Case S
Case "AC FIRST CLASS"
I = 800
Case "AC SECOND CLASS"
I = 600
Case "AC THIRD CLASS"
I = 400
Case "SLEEPER"
I = 200
Case "GENERAL"
I = 100
End Select
PASS = Text3.Text
pass1 = Text4.Text
base = I * PASS + ((I / 2) * pass1)
Text5.Text = base
rc = (Text5.Text * 2) / 100
Text6.Text = rc
sc = (Text5.Text * 15) / 100
Text7.Text = sc
Text8.Text = base + sc + rc
End Sub

Private Sub Command3_Click()
Text1.Text = ""
Text2.Text = ""
Combo1.Text = ""
Combo2.Text = ""
End Sub

Private Sub Command4_Click()
Select Case Combo2.Text
Case "CREDIT CARD"
InputBox "enter credit card number"
MsgBox "please confirm payment by pressing enter"
MsgBox "PAYMENT SUCCESS"
Case "DEBIT CARD"
InputBox "enter credit card number"
MsgBox "please confirm payment by pressing enter"
MsgBox "PAYMENT SUCCESS"
Case "PAY-TM"
InputBox "enter PAYTM number"
MsgBox "please confirm payment by pressing enter"
MsgBox "PAYMENT SUCCESS"
End Select
Text1.Enabled = False
Text2.Enabled = False
Text3.Enabled = False
Text4.Enabled = False
Text5.Enabled = False
Text6.Enabled = False
Text7.Enabled = False
Text8.Enabled = False
End Sub

Private Sub Form_Load()
Command1.Enabled = False
Command2.Enabled = False
Command3.Enabled = False
Command4.Enabled = False
Combo3.AddItem "AC FIRST CLASS"
Combo3.AddItem "AC SECOND CLASS"
Combo3.AddItem "AC THIRD CLASS"
Combo3.AddItem "SLEEPER CLASS"
Combo3.AddItem "GENERAL"
Combo2.AddItem "CREDIT CARD"
Combo2.AddItem "DEBIT CARD"
Combo2.AddItem "PAY-TM"
Combo1.AddItem "MALE"
Combo1.AddItem "FEMALE"
Combo1.AddItem "OTHER"
Text1.Enabled = False
Text2.Enabled = False
Text3.Enabled = False
Text4.Enabled = False
Text5.Enabled = False
Text6.Enabled = False
Text7.Enabled = False
Text8.Enabled = False
End Sub

Private Sub Text1_Change()
Command3.Enabled = True
Command4.Enabled = True
End Sub

Private Sub Text3_Change()
Command1.Enabled = True
Command2.Enabled = True

End Sub
